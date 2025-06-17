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
#include <TH1D.h>
#include <TLine.h>
#include <TROOT.h>
#include <TStyle.h>

// Project headers
#include <Core/Constantes.hpp>
#include <Core/Helpers.hpp>
#include <electron_normalized_FD_yields/Drawing.hpp>
#include <electron_normalized_FD_yields/Histograms.hpp>
#include <electron_normalized_FD_yields/Reader.hpp>
#include <thread_pool/multi_thread.hpp>

int main() {
    ROOT::EnableThreadSafety();  // To stop random errors in multithread mode

    auto start_time = std::chrono::high_resolution_clock::now();

    const toml::table run_files = toml::parse_file("../run_numbers_with_charge.toml");

    
    // std::vector<std::string> runs_LD2 = Core::read_folders_in_directory("/volatile/clas12/rg-d/production/pass0v11/LD2/mon/recon/");
    // std::vector<std::string> runs_CxC = Core::read_folders_in_directory("/volatile/clas12/rg-d/production/pass0v11/CxC/mon/recon/");
    // std::vector<std::string> runs_CuSn = Core::read_folders_in_directory("/volatile/clas12/rg-d/production/pass0v11/CuSn/mon/recon/");
    // std::vector<std::string> runs_ShortEmpRand = Core::read_folders_in_directory("/volatile/clas12/rg-d/production/pass0v11/ShortEmpRand/mon/recon/");

    std::vector<std::string> runs_LD2 = Core::read_recursive_file_in_directory("/cache/hallb/scratch/rg-d/production/skim_pass0v11/LD2/");
    std::vector<std::string> runs_CxC = Core::read_recursive_file_in_directory("/cache/hallb/scratch/rg-d/production/skim_pass0v11/CxC/");
    std::vector<std::string> runs_CuSn = Core::read_recursive_file_in_directory("/cache/hallb/scratch/rg-d/production/skim_pass0v11/CuSn/");
    std::vector<std::string> runs_ShortEmpRand = Core::read_recursive_file_in_directory("/cache/hallb/scratch/rg-d/production/skim_pass0v11/ShortEmpRand/");


    // Concatenate all runs
    std::vector<std::string> runs;
    runs.insert(runs.end(), runs_LD2.begin(), runs_LD2.end());
    runs.insert(runs.end(), runs_CxC.begin(), runs_CxC.end());
    runs.insert(runs.end(), runs_CuSn.begin(), runs_CuSn.end());
    runs.insert(runs.end(), runs_ShortEmpRand.begin(), runs_ShortEmpRand.end());

   // runs.resize(static_cast<int>(1.f / 100 * runs.size()));
    fmt::print("Number of runs: {}\n", runs.size());    

    electron_normalized_FD_yields::Histograms histograms;
    electron_normalized_FD_yields::Reader reader(histograms, run_files);
    multithread_reader(reader, runs, 40);

    electron_normalized_FD_yields::Drawing drawing(histograms);
    drawing.draw_timelines();

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);

    fmt::println("Time take: {} seconds", duration.count());

    return EXIT_SUCCESS;
}
