#include <electron_normalized_FD_yields/Reader.hpp>
#include <vector>

namespace normalized_yields {

Reader::Reader(Histograms& histograms, const toml::parse_result& run_files)
    : m_histograms(histograms), m_run_files(run_files) {}

Reader::~Reader() = default;

auto Reader::operator()(const std::string& run) -> void {
    namespace fs = std::filesystem;

    fs::path path = run;
    int run_number = std::stoi(path.filename().string().substr(9, 6));
    const std::string run_str = std::to_string(run_number);
    auto contains_run = [&run_str](const auto& container) {
        return std::ranges::find(container, run_str) != container.end();
    };
    double vz_min = -30.0, vz_max = 30.0;
    if (contains_run(inbending_runs_CuSn) || contains_run(inbending_runs_CxC))
        vz_min = -9.6, vz_max = 5.0;
    if (contains_run(outbending_runs_CuSn) || contains_run(outbending_runs_CxC))
        vz_min = -10.0, vz_max = 5.0;
    if (contains_run(inbending_runs_LD2) || contains_run(outbending_runs_LD2))
        vz_min = -15.0, vz_max = 5.0;

    const toml::array& array = *m_run_files["run_numbers"][run_str].as_array();
    const int tot_nb_of_files = array.at(0).value_or(-1);
    const double total_charge = array.at(1).value_or(-1.0) * 1E6;

    if (tot_nb_of_files == -1 || total_charge < 0) {
        fmt::print("Error: run number {} not found in the toml file\n", run_number);
        return;
    }

    int nb_electron_triggers = 0;
    int nb_pips = 0;
    int nb_pims = 0;
    int nb_pi0s = 0;
    int nb_rho0s = 0;

    hipo::hipoeventfile events(run);

    for (auto event : events) {

        hipo::bank REC_Particle = event.get_bank("REC::Particle");
        hipo::bank REC_Calorimeter = event.get_bank("REC::Calorimeter");
        hipo::bank REC_Event = event.get_bank("REC::Event");
        hipo::bank RUN_config = event.get_bank("RUN::config");

        if (REC_Particle.getRows() == 0 || RUN_config.getRows() == 0 || REC_Event.getRows() == 0 || REC_Calorimeter.getRows() == 0) continue;

        std::vector<Core::Particle> electrons = get_electrons(REC_Particle, REC_Calorimeter, vz_min, vz_max);
        if (electrons.empty()) continue;

        nb_electron_triggers += electrons.size();

        std::vector<Core::Particle> pips = get_pi_plus(REC_Particle, REC_Calorimeter, vz_min, vz_max);
        std::vector<Core::Particle> pims = get_pi_minus(REC_Particle, REC_Calorimeter, vz_min, vz_max);

        nb_pips += pips.size();
        nb_pims += pims.size();

        std::vector<Core::Particle> photons = get_photons(REC_Particle, REC_Calorimeter);
        std::vector<std::pair<ROOT::Math::PxPyPzEVector, ROOT::Math::PxPyPzEVector>> pairs;
        for (size_t i = 0; i < photons.size(); i++) {
            for (size_t j = i + 1; j < photons.size(); j++) {
                pairs.emplace_back(photons[i].PxPyPzEVector(), photons[j].PxPyPzEVector());
            }
        }

        for (const auto& [p1, p2] : pairs) {
            double invariant_mass = ROOT::Math::VectorUtil::InvariantMass(p1, p2);
            if (invariant_mass > 0.07 && invariant_mass < 0.2) nb_pi0s++;
        }

        std::vector<std::pair<ROOT::Math::PxPyPzEVector, ROOT::Math::PxPyPzEVector>> pairs_pip_pim;
        for (size_t i = 0; i < pips.size(); i++) {
            for (size_t j = 0; j < pims.size(); j++) {
                pairs_pip_pim.emplace_back(pips[i].PxPyPzEVector(), pims[j].PxPyPzEVector());
            }
        }

        for (const auto& [pip, pim] : pairs_pip_pim) {

            ROOT::Math::PxPyPzEVector k1 = {0, 0, 10.56, 10.56};
            ROOT::Math::PxPyPzEVector k2 = electrons[0].PxPyPzEVector();
            ROOT::Math::PxPyPzEVector q1 = k1 - k2;
            ROOT::Math::PxPyPzEVector p1 = {0, 0, 0, Core::Constantes::ProtonMass};

            ROOT::Math::PxPyPzEVector p_rho = pip + pim;

            const double Q2 = -q1.M2();
            const double W = (p1 + q1).mag();
            const double nu = k1.E() - k2.E();
            const double t = (q1 - p_rho).M2();
            const double zh = p_rho.E() / nu;

            const bool cut_w = W > 2;
            const bool cut_zh = zh > 0.8;
            const bool cut_t = 0.1 < -t && -t < 0.5;
            const bool cut_Q2 = Q2 > 1;

            if (cut_w && cut_zh && cut_t && cut_Q2) nb_rho0s++;
        }
    }

    double normalized_charge = -999.0;
    if (tot_nb_of_files < 40) normalized_charge = total_charge;
    else
        normalized_charge = total_charge * 40.0 / tot_nb_of_files;

    m_histograms.graph_normalized_electron_yield_all->Get()->SetPoint(m_histograms.graph_normalized_electron_yield_all->Get()->GetN(), run_number, nb_electron_triggers / normalized_charge);
    m_histograms.graph_electron_yield_all->Get()->SetPoint(m_histograms.graph_electron_yield_all->Get()->GetN(), run_number, nb_electron_triggers);
    m_histograms.graph_normalized_charge_all->Get()->SetPoint(m_histograms.graph_normalized_charge_all->Get()->GetN(), run_number, normalized_charge);

    // Pions plus and minus
    m_histograms.graph_normalized_pip_yield_all->Get()->SetPoint(m_histograms.graph_normalized_pip_yield_all->Get()->GetN(), run_number, (nb_pips) / normalized_charge);
    m_histograms.graph_pip_yield_all->Get()->SetPoint(m_histograms.graph_pip_yield_all->Get()->GetN(), run_number, (nb_pips));

    m_histograms.graph_normalized_pim_yield_all->Get()->SetPoint(m_histograms.graph_normalized_pim_yield_all->Get()->GetN(), run_number, (nb_pims) / normalized_charge);
    m_histograms.graph_pim_yield_all->Get()->SetPoint(m_histograms.graph_pim_yield_all->Get()->GetN(), run_number, (nb_pims));

    // Pi0
    m_histograms.graph_normalized_pi0_yield_all->Get()->SetPoint(m_histograms.graph_normalized_pi0_yield_all->Get()->GetN(), run_number, nb_pi0s / normalized_charge);
    m_histograms.graph_pi0_yield_all->Get()->SetPoint(m_histograms.graph_pi0_yield_all->Get()->GetN(), run_number, nb_pi0s);

    // Rho0
    m_histograms.graph_normalized_rho0_yield_all->Get()->SetPoint(m_histograms.graph_normalized_rho0_yield_all->Get()->GetN(), run_number, nb_rho0s / normalized_charge);
    m_histograms.graph_rho0_yield_all->Get()->SetPoint(m_histograms.graph_rho0_yield_all->Get()->GetN(), run_number, nb_rho0s);
}

auto Reader::check_sector(Core::CalorimeterBank& calorimeterBank) -> bool {
    if ((1 <= calorimeterBank.pcal.sector && calorimeterBank.pcal.sector <= 6) ||
        (1 <= calorimeterBank.inner.sector && calorimeterBank.inner.sector <= 6) ||
        (1 <= calorimeterBank.outer.sector && calorimeterBank.outer.sector <= 6))
        return true;
    return false;
}

auto Reader::get_electrons(const hipo::bank& REC_Particle, const hipo::bank& REC_Calorimeter, const double vz_min, const double vz_max) -> std::vector<Core::Particle> {
    std::vector<Core::Particle> electrons;

    for (int row = 0; row < REC_Particle.getRows(); row++) {
        int pid = REC_Particle.get<int>("pid", row);
        int status = REC_Particle.get<int>("status", row);
        float chi2pid = REC_Particle.get<float>("chi2pid", row);
        double vz = REC_Particle.get<double>("vz", row);

        if (pid == 11 && status < 0 && (std::abs(status / 1000) & 0x2 || std::abs(status / 1000) & 0x4) && std::abs(chi2pid) < 5 && vz_min < vz && vz < vz_max) {

            Core::CalorimeterBank calorimeterBank = Core::read_Calorimeter_bank(REC_Calorimeter, row);
            if (check_sector(calorimeterBank)) {

                double px = REC_Particle.get<double>("px", row);
                double py = REC_Particle.get<double>("py", row);
                double pz = REC_Particle.get<double>("pz", row);
                double vx = REC_Particle.get<double>("vx", row);
                double vy = REC_Particle.get<double>("vy", row);
                double vt = REC_Particle.get<double>("vt", row);
                double beta = REC_Particle.get<double>("beta", row);
                double E = Core::compute_energy(px, py, pz, pid);

                electrons.emplace_back(pid, status, row, -1, Core::Constantes::ElectronMass, px, py, pz, E, vx, vy, vz, vt, beta, chi2pid, calorimeterBank.pcal.sector);
            }
        }
    }

    return electrons;
}

auto Reader::get_pi_plus(const hipo::bank& REC_Particle, const hipo::bank& REC_Calorimeter, const double vz_min, const double vz_max) -> std::vector<Core::Particle> {
    std::vector<Core::Particle> pips;

    for (int row = 0; row < REC_Particle.getRows(); row++) {
        int pid = REC_Particle.get<int>("pid", row);
        int status = REC_Particle.get<int>("status", row);
        float chi2pid = REC_Particle.get<float>("chi2pid", row);
        double vz = REC_Particle.get<double>("vz", row);

        if (pid == 211 && (std::abs(status / 1000) & 0x2 || std::abs(status / 1000) & 0x4) && std::abs(chi2pid) < 10 && vz_min < vz && vz < vz_max) {
            Core::CalorimeterBank calorimeterBank = Core::read_Calorimeter_bank(REC_Calorimeter, row);
            if (check_sector(calorimeterBank)) {

                double px = REC_Particle.get<double>("px", row);
                double py = REC_Particle.get<double>("py", row);
                double pz = REC_Particle.get<double>("pz", row);
                double vx = REC_Particle.get<double>("vx", row);
                double vy = REC_Particle.get<double>("vy", row);
                double vz = REC_Particle.get<double>("vz", row);
                double vt = REC_Particle.get<double>("vt", row);
                double beta = REC_Particle.get<double>("beta", row);
                double E = Core::compute_energy(px, py, pz, pid);

                pips.emplace_back(pid, status, row, -1, Core::Constantes::ElectronMass, px, py, pz, E, vx, vy, vz, vt, beta, chi2pid, calorimeterBank.pcal.sector);
            }
        }
    }

    return pips;
}

auto Reader::get_pi_minus(const hipo::bank& REC_Particle, const hipo::bank& REC_Calorimeter, const double vz_min, const double vz_max) -> std::vector<Core::Particle> {
    std::vector<Core::Particle> pips;

    for (int row = 0; row < REC_Particle.getRows(); row++) {
        int pid = REC_Particle.get<int>("pid", row);
        int status = REC_Particle.get<int>("status", row);
        float chi2pid = REC_Particle.get<float>("chi2pid", row);
        double vz = REC_Particle.get<double>("vz", row);

        if (pid == -211 && (std::abs(status / 1000) & 0x2 || std::abs(status / 1000) & 0x4) && std::abs(chi2pid) < 10 && vz_min < vz && vz < vz_max) {
            Core::CalorimeterBank calorimeterBank = Core::read_Calorimeter_bank(REC_Calorimeter, row);
            if (check_sector(calorimeterBank)) {

                double px = REC_Particle.get<double>("px", row);
                double py = REC_Particle.get<double>("py", row);
                double pz = REC_Particle.get<double>("pz", row);
                double vx = REC_Particle.get<double>("vx", row);
                double vy = REC_Particle.get<double>("vy", row);
                double vz = REC_Particle.get<double>("vz", row);
                double vt = REC_Particle.get<double>("vt", row);
                double beta = REC_Particle.get<double>("beta", row);
                double E = Core::compute_energy(px, py, pz, pid);

                pips.emplace_back(pid, status, row, -1, Core::Constantes::ElectronMass, px, py, pz, E, vx, vy, vz, vt, beta, chi2pid, calorimeterBank.pcal.sector);
            }
        }
    }

    return pips;
}

auto Reader::get_photons(const hipo::bank& REC_Particle, const hipo::bank& REC_Calorimeter) -> std::vector<Core::Particle> {
    std::vector<Core::Particle> photons;

    for (int row = 0; row < REC_Particle.getRows(); row++) {
        int pid = REC_Particle.get<int>("pid", row);
        int status = REC_Particle.get<int>("status", row);
        float chi2pid = REC_Particle.get<float>("chi2pid", row);

        if (pid == 22 && (std::abs(status / 1000) & 0x2 || std::abs(status / 1000) & 0x4)) {

            double px = REC_Particle.get<double>("px", row);
            double py = REC_Particle.get<double>("py", row);
            double pz = REC_Particle.get<double>("pz", row);
            double vx = REC_Particle.get<double>("vx", row);
            double vy = REC_Particle.get<double>("vy", row);
            double vz = REC_Particle.get<double>("vz", row);
            double vt = REC_Particle.get<double>("vt", row);
            double beta = REC_Particle.get<double>("beta", row);
            double E = Core::compute_energy(px, py, pz, pid);

            photons.emplace_back(pid, status, row, 0, 0, px, py, pz, E, vx, vy, vz, vt, beta, chi2pid, 0);
        }
    }

    return photons;
}
}  // namespace normalized_yields