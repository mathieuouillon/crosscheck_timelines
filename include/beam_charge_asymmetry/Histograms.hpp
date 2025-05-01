#pragma once

#include <TGraph.h>
#include <TH1.h>
#include <TH2.h>
#include <ROOT/TThreadedObject.hxx>
#include <TGraphErrors.h>


using TTO_TH1D = ROOT::TThreadedObject<TH1D>;
using TTO_TH2D = ROOT::TThreadedObject<TH2D>;
using TTO_TGraph = ROOT::TThreadedObject<TGraph>;
using TTO_TGraphErrors = ROOT::TThreadedObject<TGraphErrors>;

namespace beam_charge_asymmetry {

struct Histograms {
    std::unique_ptr<TTO_TGraph> graph_beam_charge_asymmetry = std::make_unique<TTO_TGraph>();

    std::unique_ptr<TTO_TGraphErrors> graph_beam_spin_asymmetry_slope_piplus = std::make_unique<TTO_TGraphErrors>();
    std::unique_ptr<TTO_TGraphErrors> graph_beam_spin_asymmetry_offset_piplus = std::make_unique<TTO_TGraphErrors>();
    std::unique_ptr<TTO_TGraphErrors> graph_beam_spin_asymmetry_slope_piminus = std::make_unique<TTO_TGraphErrors>();
    std::unique_ptr<TTO_TGraphErrors> graph_beam_spin_asymmetry_offset_piminus = std::make_unique<TTO_TGraphErrors>();
    
    std::unique_ptr<TTO_TGraphErrors> graph_normalized_electron_yield = std::make_unique<TTO_TGraphErrors>();

};

}  // namespace beam_charge_asymmetry