// C++ headers
#include <algorithm>
#include <chrono>
#include <filesystem>
#include <iostream>
#include <ranges>
#include <vector>

// fmt headers
#include <fmt/core.h>
#include <fmt/ranges.h>

#include <toml++/toml.hpp>

// ROOT headers
#include <TCanvas.h>
#include <TError.h>
#include <TH1D.h>
#include <TLine.h>
#include <TROOT.h>
#include <TStyle.h>

// Project headers
#include <Core/Draw.hpp>
#include <beam_charge_asymmetry/Histograms.hpp>
#include <beam_charge_asymmetry/Reader.hpp>
#include <thread_pool/multi_thread.hpp>

auto SetROOTOption() -> void {
    ROOT::EnableThreadSafety();
    ROOT::EnableImplicitMT();
    TH1::SetDefaultSumw2(kTRUE);

    gErrorIgnoreLevel = kPrint;  // setting it to kPrint will print all messages again. kError, kFatal

    // gStyle->SetOptStat(0);
    gStyle->SetOptFit(1111);
    gStyle->SetNumberContours(255);
    gStyle->SetImageScaling(3.);

    gStyle->SetLineWidth(1);
    gStyle->SetFrameLineWidth(1);
    gStyle->SetHistLineWidth(1);
    gStyle->SetFuncWidth(1);
    gStyle->SetGridWidth(1);
    // gStyle->SetLineStyleString(1, "[12 12]");  // postscript dashes

    // put tick marks on top and RHS of plots
    gStyle->SetPadTickX(1);
    gStyle->SetPadTickY(1);
    gStyle->SetNdivisions(505, "x");
    gStyle->SetNdivisions(510, "y");

    gStyle->SetTextFont(42);
}

auto main(int argc, char* argv[]) -> int {
    namespace fs = std::filesystem;

    ROOT::EnableThreadSafety();  // To stop random errors in multithread mode
    SetROOTOption();

    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<std::string> runs;

    runs = {
        "/volatile/clas12/rg-d/production/pass0v11/LD2/mon/recon/018439/",
        "/volatile/clas12/rg-d/production/pass0v11/LD2/mon/recon/018535/",
        "/volatile/clas12/rg-d/production/pass0v11/LD2/mon/recon/018774/",
        "/volatile/clas12/rg-d/production/pass0v11/LD2/mon/recon/018852/",
        "/volatile/clas12/rg-d/production/pass0v11/LD2/mon/recon/019040/",
        "/volatile/clas12/rg-d/production/pass0v11/CxC/mon/recon/018369/",
        "/volatile/clas12/rg-d/production/pass0v11/CxC/mon/recon/018480/",
        "/volatile/clas12/rg-d/production/pass0v11/CxC/mon/recon/018756/",
        "/volatile/clas12/rg-d/production/pass0v11/CxC/mon/recon/018814/",
        "/volatile/clas12/rg-d/production/pass0v11/CxC/mon/recon/018846/",
        "/volatile/clas12/rg-d/production/pass0v11/CuSn/mon/recon/018379/",
        "/volatile/clas12/rg-d/production/pass0v11/CuSn/mon/recon/018587/",
        "/volatile/clas12/rg-d/production/pass0v11/CuSn/mon/recon/018703/",
        "/volatile/clas12/rg-d/production/pass0v11/CuSn/mon/recon/018906/",
        "/volatile/clas12/rg-d/production/pass0v11/CuSn/mon/recon/019083/"
    };

    const toml::table run_files = toml::parse_file("../run_numbers_with_charge.toml");

    beam_charge_asymmetry::Histograms histograms;
    beam_charge_asymmetry::Reader reader(histograms, run_files);
    multithread_reader(reader, runs, 20);

    {
        auto canvas1 = Core::make_canvas();
        auto graph_normalized_electron_yield = histograms.graph_normalized_electron_yield->Merge();
        graph_normalized_electron_yield->Draw("AP");
        graph_normalized_electron_yield->GetXaxis()->SetTitle("Run Number");
        graph_normalized_electron_yield->GetYaxis()->SetTitle("Yields");
        Core::save_canvas(canvas1, "../plots/", "graph_normalized_electron_yield");
    }


    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);

    fmt::println("Time take: {} seconds", duration.count());

    return EXIT_SUCCESS;
}
