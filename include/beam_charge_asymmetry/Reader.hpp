#pragma once

// C++ headers
#include <algorithm>
#include <cmath>
#include <filesystem>
#include <ranges>
#include <string>
#include <vector>

// <fmt> headers
#include <fmt/core.h>

// toml++ headers
#include <toml++/toml.h>

// ROOT headers
#include <Math/Vector4D.h>
#include <Math/VectorUtil.h>
#include <TGraphErrors.h>
#include <TH1.h>

// Project headers
#include <hipo4/reader.h>
#include <Core/Draw.hpp>
#include <Core/Helpers.hpp>
#include <Core/Particle2.hpp>
#include <Core/ReadBank.hpp>
#include <beam_charge_asymmetry/Histograms.hpp>
#include <fplus.hpp>

namespace beam_charge_asymmetry {

class Reader {

    struct HistoBins {
        std::shared_ptr<TH1F> hist1_pi_plus_p;
        std::shared_ptr<TH1F> hist1_pi_plus_pt;
        std::shared_ptr<TH1F> hist1_pi_plus_z;
        std::shared_ptr<TH1F> hist1_pi_plus_theta;
        std::shared_ptr<TH1F> hist1_pi_plus_phih;

        std::shared_ptr<TH1F> hist1_pi_minus_p;
        std::shared_ptr<TH1F> hist1_pi_minus_pt;
        std::shared_ptr<TH1F> hist1_pi_minus_z;
        std::shared_ptr<TH1F> hist1_pi_minus_theta;
        std::shared_ptr<TH1F> hist1_pi_minus_phih;

        std::shared_ptr<TH1F> hist1_Q2;
        std::shared_ptr<TH1F> hist1_W;
        std::shared_ptr<TH1F> hist1_x;
        std::shared_ptr<TH1F> hist1_y;

        HistoBins(int run_number, int bin_number) {
            hist1_pi_plus_p = std::make_shared<TH1F>((std::string("p_pi_plus") + std::to_string(run_number) + "_" + std::to_string(bin_number)).c_str(), "", 50, 0, 10);
            hist1_pi_plus_pt = std::make_shared<TH1F>((std::string("pt_pi_plus") + std::to_string(run_number) + "_" + std::to_string(bin_number)).c_str(), "", 50, 0, 4);
            hist1_pi_plus_z = std::make_shared<TH1F>((std::string("z_pi_plus") + std::to_string(run_number) + "_" + std::to_string(bin_number)).c_str(), "", 50, 0, 1);
            hist1_pi_plus_theta = std::make_shared<TH1F>((std::string("theta_pi_plus") + std::to_string(run_number) + "_" + std::to_string(bin_number)).c_str(), "", 50, 0, 1.570796);
            hist1_pi_plus_phih = std::make_shared<TH1F>((std::string("phih_pi_plus") + std::to_string(run_number) + "_" + std::to_string(bin_number)).c_str(), "", 50, -3.15, 3.15);

            hist1_pi_minus_p = std::make_shared<TH1F>((std::string("p_pi_minus") + std::to_string(run_number) + "_" + std::to_string(bin_number)).c_str(), "", 50, 0, 10);
            hist1_pi_minus_pt = std::make_shared<TH1F>((std::string("pt_pi_minus") + std::to_string(run_number) + "_" + std::to_string(bin_number)).c_str(), "", 50, 0, 4);
            hist1_pi_minus_z = std::make_shared<TH1F>((std::string("z_pi_minus") + std::to_string(run_number) + "_" + std::to_string(bin_number)).c_str(), "", 50, 0, 1);
            hist1_pi_minus_theta = std::make_shared<TH1F>((std::string("theta_pi_minus") + std::to_string(run_number) + "_" + std::to_string(bin_number)).c_str(), "", 50, 0, 1.570796);
            hist1_pi_minus_phih = std::make_shared<TH1F>((std::string("phih_pi_minus") + std::to_string(run_number) + "_" + std::to_string(bin_number)).c_str(), "", 50, -3.15, 3.15);
       
            hist1_Q2 = std::make_shared<TH1F>((std::string("Q2") + std::to_string(run_number) + "_" + std::to_string(bin_number)).c_str(), "", 100, 0, 12);
            hist1_W = std::make_shared<TH1F>((std::string("W") + std::to_string(run_number) + "_" + std::to_string(bin_number)).c_str(), "", 100, 0, 6);
            hist1_x = std::make_shared<TH1F>((std::string("x") + std::to_string(run_number) + "_" + std::to_string(bin_number)).c_str(), "", 100, 0, 1);
            hist1_y = std::make_shared<TH1F>((std::string("y") + std::to_string(run_number) + "_" + std::to_string(bin_number)).c_str(), "", 100, 0, 1);
       
        }
    };

    struct tag1info {
        int event;
        long timestamp;

        std::strong_ordering operator<=> (const tag1info& rhs) const {
            return event <=> rhs.event;
        }
    };

    struct TriggerElectron {
        int sector1;
        int sector2;
        int sector3;
        int sector4;
        int sector5;
        int sector6;
    };

    struct Topology {
        std::vector<Core::Particle2> electrons;
        std::vector<Core::Particle2> pions_plus;
        std::vector<Core::Particle2> pions_minus;
    };

   private:
    // ****** private members
    Histograms& m_histograms;
    const toml::parse_result& m_run_files;

    const double NaN = std::numeric_limits<double>::quiet_NaN();

    // ****** private methods

   public:
    // ****** constructors and destructor
    explicit Reader(Histograms& histograms, const toml::table& run_files);
    ~Reader();

    // ****** public methods
    auto operator()(const std::string& run) -> void;
};

}  // namespace beam_charge_asymmetry
