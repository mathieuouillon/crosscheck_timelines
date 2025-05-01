#include <beam_charge_asymmetry/Reader.hpp>

namespace beam_charge_asymmetry {

Reader::Reader(Histograms& histograms, const toml::table& run_files)
    : m_histograms(histograms), m_run_files(run_files) {}

Reader::~Reader() = default;

auto Reader::operator()(const std::string& run) -> void {

    namespace fs = std::filesystem;

    std::vector<std::string> files = Core::read_recursive_file_in_directory(run);

    fs::path path = run;
    int run_number = std::stoi(path.parent_path().filename().string());

    const toml::array& array = *m_run_files["run_numbers"][std::to_string(run_number)].as_array();
    const int tot_nb_of_files = array.at(0).value_or(-1);
    const double total_charge = array.at(1).value_or(-1.0) * 1E6;
    fmt::print("Reading run: {}, number of files: {}, total number of files in that run: {}, total charge: {}\n", run_number, files.size(), tot_nb_of_files, total_charge);

    if (tot_nb_of_files == -1 || total_charge < 0) {
        fmt::print("Error: run number {} not found in the toml file\n", run_number);
        return;
    }

    TriggerElectron trigger_electron_counter;

    for (const auto& file : files) {

        auto dict = hipo::dictionary();
        auto reader = hipo::reader(file, dict);
        auto hipo_event = hipo::event();

        auto REC_Event = hipo::bank(dict.getSchema("REC::Event"));
        auto REC_Particle = hipo::bank(dict.getSchema("REC::Particle"));
        auto REC_Calorimeter = hipo::bank(dict.getSchema("REC::Calorimeter"));
        auto HEL_scaler = hipo::bank(dict.getSchema("HEL::scaler"));
        auto RUN_config = hipo::bank(dict.getSchema("RUN::config"));
        auto RUN_scaler = hipo::bank(dict.getSchema("RUN::scaler"));

        while (reader.next(hipo_event, REC_Event, HEL_scaler, REC_Particle, REC_Calorimeter, RUN_config, RUN_scaler)) {
            if (RUN_config.getRows() > 0 && REC_Event.getRows() > 0 && REC_Particle.getRows() > 0 && REC_Calorimeter.getRows() > 0) {
                std::vector<Core::Particle2> electrons;
                for (int row = 0; row < REC_Particle.getRows(); row++) {
                    int pid = REC_Particle.get<int>("pid", row);
                    int status = REC_Particle.get<int>("status", row);
                    float chi2pid = REC_Particle.get<float>("chi2pid", row);

                    if (pid == 11 && status < 0 && (std::abs(status / 1000) & 0x2 || std::abs(status / 1000) & 0x4) && std::abs(chi2pid) < 3) {
                        Core::CalorimeterBank calorimeterBank = Core::read_Calorimeter_bank(REC_Calorimeter, row);
                        if ((1 <= calorimeterBank.pcal.sector && calorimeterBank.pcal.sector <= 6) ||
                            (1 <= calorimeterBank.inner.sector && calorimeterBank.inner.sector <= 6) ||
                            (1 <= calorimeterBank.outer.sector && calorimeterBank.outer.sector <= 6)) {
                            // fmt::print("sector: {}\n", calorimeterBank.inner.sector);

                            double px = REC_Particle.get<double>("px", row);
                            double py = REC_Particle.get<double>("py", row);
                            double pz = REC_Particle.get<double>("pz", row);
                            double vx = REC_Particle.get<double>("vx", row);
                            double vy = REC_Particle.get<double>("vy", row);
                            double vz = REC_Particle.get<double>("vz", row);
                            double vt = REC_Particle.get<double>("vt", row);
                            double beta = REC_Particle.get<double>("beta", row);
                            double E = Core::compute_energy(px, py, pz, pid);

                            Core::Particle2 electron(pid, status, row, -1, Core::Constantes::ElectronMass, px, py, pz, E, vx, vy, vz, vt, beta, chi2pid);
                            if ((1 <= calorimeterBank.pcal.sector && calorimeterBank.pcal.sector <= 6)) electron.sector(calorimeterBank.pcal.sector);
                            if ((1 <= calorimeterBank.inner.sector && calorimeterBank.inner.sector <= 6)) electron.sector(calorimeterBank.inner.sector);
                            if ((1 <= calorimeterBank.outer.sector && calorimeterBank.outer.sector <= 6)) electron.sector(calorimeterBank.outer.sector);
                            electrons.push_back(electron);
                        }
                    }
                }

                if (electrons.empty()) continue;
                Core::Particle2 electron = electrons[0];
                for (const auto& e : electrons) {
                    if (electron.E() < e.E()) {
                        electron = e;
                    }
                }

                switch (electron.sector()) {
                    case 1:
                        trigger_electron_counter.sector1++;
                        break;
                    case 2:
                        trigger_electron_counter.sector2++;
                        break;
                    case 3:
                        trigger_electron_counter.sector3++;
                        break;
                    case 4:
                        trigger_electron_counter.sector4++;
                        break;
                    case 5:
                        trigger_electron_counter.sector5++;
                        break;
                    case 6:
                        trigger_electron_counter.sector6++;
                        break;
                    default:
                        fmt::print("Sector not found: {}\n", electron.sector());
                        break;
                }
            }
        }
    }

    double normalized_charge = total_charge * files.size() / tot_nb_of_files;
    
    fmt::print("run: {}, sector 1: {}, total_charge: {}, normalized charge: {}\n", run_number, trigger_electron_counter.sector1, total_charge, normalized_charge);
    fmt::print("sector 1/normalized charge: {}\n", trigger_electron_counter.sector1/(normalized_charge));

    m_histograms.graph_normalized_electron_yield->Get()->SetPoint(m_histograms.graph_normalized_electron_yield->Get()->GetN(), run_number, trigger_electron_counter.sector1/normalized_charge);

}
}  // namespace beam_charge_asymmetry
