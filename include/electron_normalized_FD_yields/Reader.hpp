#pragma once

// C++ headers
#include <string>
#include <vector>

// <fmt> headers
#include <fmt/core.h>

// toml++ headers
#include <toml++/toml.h>

// ROOT headers
#include <Math/Vector4D.h>
#include <Math/VectorUtil.h>

// Project headers
#include <hipo4/hipoeventiterator.h>
#include <hipo4/reader.h>
#include <Core/Constantes.hpp>
#include <Core/Helpers.hpp>
#include <Core/Particle.hpp>
#include <Core/ReadBank.hpp>
#include <electron_normalized_FD_yields/Histograms.hpp>
#include "bank.h"


namespace normalized_yields {

class Reader {
   private:
    struct Topology {
        std::vector<Core::Particle> electrons;
    };

    // ****** private variables
    Histograms& m_histograms;
    const toml::parse_result& m_run_files;

    // ****** private constants
    static constexpr double NaN = std::numeric_limits<double>::quiet_NaN();

    // ****** private methods
    auto check_sector(Core::CalorimeterBank& calorimeterBank) -> bool;
    auto get_electrons(const hipo::bank& REC_Particle,const hipo::bank&REC_Calorimeter, const double vz_min, const double vz_max) -> std::vector<Core::Particle>;
    auto get_pi_plus(const hipo::bank& REC_Particle, const hipo::bank& REC_Calorimeter, const double vz_min, const double vz_max) -> std::vector<Core::Particle>;
    auto get_pi_minus(const hipo::bank& REC_Particle, const hipo::bank& REC_Calorimeter, const double vz_min, const double vz_max) -> std::vector<Core::Particle>;
    auto get_photons(const hipo::bank& REC_Particle, const hipo::bank& REC_Calorimeter) -> std::vector<Core::Particle>;

   public:
    // ****** constructors and destructor
    explicit Reader(Histograms& histograms, const toml::parse_result& config);
    ~Reader();

    // ****** public methods
    auto operator()(const std::string& run) -> void;
};

}  // namespace electron_normalized_FD_yields