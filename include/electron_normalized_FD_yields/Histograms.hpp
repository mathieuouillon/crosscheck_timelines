#pragma once

#include <TGraph.h>
#include <TGraphErrors.h>
#include <ROOT/TThreadedObject.hxx>

using TTO_TGraph = ROOT::TThreadedObject<TGraph>;
using TTO_TGraphErrors = ROOT::TThreadedObject<TGraphErrors>;

namespace electron_normalized_FD_yields {

struct Histograms {
    std::unique_ptr<TTO_TGraphErrors> graph_normalized_electron_yield_s1 = std::make_unique<TTO_TGraphErrors>();
    std::unique_ptr<TTO_TGraphErrors> graph_electron_yield_s1 = std::make_unique<TTO_TGraphErrors>();
    std::unique_ptr<TTO_TGraphErrors> graph_normalized_charge_s1 = std::make_unique<TTO_TGraphErrors>();

    std::unique_ptr<TTO_TGraphErrors> graph_normalized_electron_yield_s2 = std::make_unique<TTO_TGraphErrors>();
    std::unique_ptr<TTO_TGraphErrors> graph_electron_yield_s2 = std::make_unique<TTO_TGraphErrors>();
    std::unique_ptr<TTO_TGraphErrors> graph_normalized_charge_s2 = std::make_unique<TTO_TGraphErrors>();

    std::unique_ptr<TTO_TGraphErrors> graph_normalized_electron_yield_s3 = std::make_unique<TTO_TGraphErrors>();
    std::unique_ptr<TTO_TGraphErrors> graph_electron_yield_s3 = std::make_unique<TTO_TGraphErrors>();
    std::unique_ptr<TTO_TGraphErrors> graph_normalized_charge_s3 = std::make_unique<TTO_TGraphErrors>();

    std::unique_ptr<TTO_TGraphErrors> graph_normalized_electron_yield_s4 = std::make_unique<TTO_TGraphErrors>();
    std::unique_ptr<TTO_TGraphErrors> graph_electron_yield_s4 = std::make_unique<TTO_TGraphErrors>();
    std::unique_ptr<TTO_TGraphErrors> graph_normalized_charge_s4 = std::make_unique<TTO_TGraphErrors>();

    std::unique_ptr<TTO_TGraphErrors> graph_normalized_electron_yield_s5 = std::make_unique<TTO_TGraphErrors>();
    std::unique_ptr<TTO_TGraphErrors> graph_electron_yield_s5 = std::make_unique<TTO_TGraphErrors>();
    std::unique_ptr<TTO_TGraphErrors> graph_normalized_charge_s5 = std::make_unique<TTO_TGraphErrors>();

    std::unique_ptr<TTO_TGraphErrors> graph_normalized_electron_yield_s6 = std::make_unique<TTO_TGraphErrors>();
    std::unique_ptr<TTO_TGraphErrors> graph_electron_yield_s6 = std::make_unique<TTO_TGraphErrors>();
    std::unique_ptr<TTO_TGraphErrors> graph_normalized_charge_s6 = std::make_unique<TTO_TGraphErrors>();

    std::unique_ptr<TTO_TGraphErrors> graph_normalized_electron_yield_all = std::make_unique<TTO_TGraphErrors>();
    std::unique_ptr<TTO_TGraphErrors> graph_electron_yield_all = std::make_unique<TTO_TGraphErrors>();
    std::unique_ptr<TTO_TGraphErrors> graph_normalized_charge_all = std::make_unique<TTO_TGraphErrors>();

    std::unique_ptr<TTO_TGraphErrors> graph_normalized_pip_yield_all = std::make_unique<TTO_TGraphErrors>();
    std::unique_ptr<TTO_TGraphErrors> graph_pip_yield_all = std::make_unique<TTO_TGraphErrors>();

    std::unique_ptr<TTO_TGraphErrors> graph_normalized_pim_yield_all = std::make_unique<TTO_TGraphErrors>();
    std::unique_ptr<TTO_TGraphErrors> graph_pim_yield_all = std::make_unique<TTO_TGraphErrors>();

    std::unique_ptr<TTO_TGraphErrors> graph_normalized_pi0_yield_all = std::make_unique<TTO_TGraphErrors>();
    std::unique_ptr<TTO_TGraphErrors> graph_pi0_yield_all = std::make_unique<TTO_TGraphErrors>();

    std::unique_ptr<TTO_TGraphErrors> graph_normalized_rho0_yield_all = std::make_unique<TTO_TGraphErrors>();
    std::unique_ptr<TTO_TGraphErrors> graph_rho0_yield_all = std::make_unique<TTO_TGraphErrors>();
};

}  // namespace electron_normalized_FD_yields