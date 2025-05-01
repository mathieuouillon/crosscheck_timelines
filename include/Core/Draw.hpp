#pragma once

// std includes
#include <memory>
#include <string>

// ROOT includes
#include <TCanvas.h>
#include <TColor.h>
#include <TF1.h>
#include <TH1D.h>
#include <TH2D.h>
#include <THStack.h>
#include <TLegend.h>
#include <TLine.h>
#include <TMath.h>
#include <TPaveStats.h>
#include <TStyle.h>
#include <TFile.h>

// Project headers
#include <Plotting/Colors.hpp>

namespace Core {

/**
 * @brief Generates a linearly spaced vector of values.
 * 
 * This function creates a vector containing `num` evenly spaced values 
 * starting from `start` and ending at `end`.
 * 
 * @tparam T The type of the start and end values.
 * @param start The starting value of the sequence.
 * @param end The ending value of the sequence.
 * @param num The number of values to generate.
 * @return std::vector<T> A vector containing the linearly spaced values.
 * 
 * @note If `num` is 0, an empty vector is returned. If `num` is 1, a vector 
 * containing only the `start` value is returned.
 */
template <typename T>
auto linspace(T start, T end, const int num) -> std::vector<T> {
    std::vector<T> v;
    if (num == 0) {
        return v;
    }
    if (num == 1) {
        v.push_back(start);
        return v;
    }

    double delta = static_cast<double>(end - start) / (num - 1);

    for (int i = 0; i < num - 1; ++i) {
        v.push_back(start + delta * i);
    }
    v.push_back(end);
    return v;
}

struct Figsize {
    const uint32_t width;
    const uint32_t height;
};

/**
 * @brief Creates a shared pointer to a TCanvas object with specified dimensions.
 * 
 * @param figsize The dimensions of the canvas, specified as a Figsize object. 
 *                Default is {800, 600}.
 * @return std::shared_ptr<TCanvas> A shared pointer to the created TCanvas object.
 */
inline auto make_canvas(const Figsize figsize = {800, 600}) -> std::shared_ptr<TCanvas> {
    auto canvas = std::make_shared<TCanvas>("", "", figsize.width, figsize.height);
    canvas->SetLeftMargin(0.12f);
    canvas->SetRightMargin(0.12f);
    canvas->SetTopMargin(0.12f);
    canvas->SetBottomMargin(0.12f);

    return canvas;
}

/**
 * @brief Saves the given canvas in multiple formats.
 *
 * This function saves the provided TCanvas object in PDF, C, TeX, and ROOT file formats.
 * The files are saved in respective subdirectories under the specified path.
 *
 * @param canvas A shared pointer to the TCanvas object to be saved.
 * @param path The directory path where the files will be saved. The function assumes
 *             that subdirectories "pdf", "C", "tex", and "root" exist under this path.
 * @param file_name The base name for the saved files. The function appends the appropriate
 *                 file extension for each format.
 */
inline auto save_canvas(const std::shared_ptr<TCanvas>& canvas, const std::string& path, const std::string& file_name) -> void {
    canvas->SaveAs((path + file_name + ".pdf").c_str());
    canvas->SaveAs((path + file_name + ".C").c_str());
    // canvas->SaveAs((path + "tex/" + file_name + ".tex").c_str());
// 
    // std::unique_ptr<TFile> outputFile(TFile::Open((path + "root/" + file_name + ".root").c_str(), "RECREATE"));
    // auto list = canvas->GetListOfPrimitives();
    // for (int i = 1; i < list->GetSize(); ++i) {
    //     outputFile->WriteObject(list->At(i), list->At(i)->GetName());
    // }
    // outputFile->Close();
}

struct Position {
    const double x1;
    const double y1;
    const double x2;
    const double y2;
};

/**
     * @brief Move the statistics boxes to fill a tile.
     *
     * This function updates the position of the statistics boxes to fill a tile with the size of it giving by the parameters.
     *
     * @param boxes A unique pointer to TObjArray that contains the stats boxes.
     * @param numColumns The number of columns in the tile.
     * @param numRows The number of rows in the tile.
     *
     * @return None.
     */
inline auto update_tile_stats(const TObjArray& boxes, bool haveFitPars, int numColumns = 0, int numRows = 0) -> void {
    std::vector<Position> positions;
    for (int i = 0; i < boxes.GetEntries(); i++) {
        auto stat_box = static_cast<TPaveStats*>(boxes.At(i));

        positions.emplace_back(stat_box->GetX1NDC(), stat_box->GetY1NDC(), stat_box->GetX2NDC(), stat_box->GetY2NDC());

        if (!stat_box) {
            return;
        }
        if (positions.size() == 1) {
            stat_box->SetX1NDC(positions[i].x1);
            stat_box->SetY1NDC(positions[i].y1);
            stat_box->SetX2NDC(positions[i].x2);
            stat_box->SetY2NDC(positions[i].y2);
        } else {
            stat_box->SetX1NDC(positions[i].x1);
            stat_box->SetY1NDC(positions[i].y1 - (positions[i - 1].y2 - positions[i - 1].y1));
            stat_box->SetX2NDC(positions[i].x2);
            stat_box->SetY2NDC(positions[i].y2 - (positions[i - 1].y2 - positions[i - 1].y1));
        }
    }
}

template <typename... Args>
inline auto set_stat_boxes(const std::shared_ptr<TCanvas>& canvas, bool haveFitPars, Args&&... args) -> void {
    canvas->Update();
    TObjArray boxes;
    for (const auto& h : {args...}) {
        auto st = dynamic_cast<TPaveStats*>(h->GetListOfFunctions()->FindObject("stats"));
        st->SetTextColor(h->GetLineColor());
        st->Draw();
        boxes.Add(st);
    }
    update_tile_stats(boxes, haveFitPars);
    canvas->Modified();
}

struct ArgsForDrawHist1D {
    const std::string& file_name = "";

    // colors
    const short color1 = Color::kBlue;
    const short color2 = Color::kBlack;

    const float alpha_color1 = 0.15;
    const float alpha_color2 = 0.15;

    // options
    const bool scaled = false;
    const bool set_stats = true;
    const std::string draw_option = "histo";
    const std::string opt_stat = "";

    // Cuts
    const std::vector<double> cuts = {};

    // Range
    const std::pair<double, double> x_range = {};
    const std::pair<double, double> y_range = {};

    // Legend
    const std::string legend = "";
    const std::string fLegend2;

    const std::string title = "";

    // Log scale
    const bool fLogX = false;
    const bool fLogY = false;

    // label
    const std::string label = "";
    const float fLabelOffset = 1.0f;
    const float fLabelSize = 0.05f;
};

inline auto draw_hist1D(const std::shared_ptr<TH1>& h, const std::string& path, const ArgsForDrawHist1D& args = {}) -> void {

    std::shared_ptr<TCanvas> canvas = make_canvas();
    std::string fileName = args.file_name.empty() ? h->GetName() : args.file_name;

    gStyle->SetOptStat(0);

    h->Draw(args.draw_option.c_str());
    h->SetStats(args.set_stats);
    h->SetTitle(args.title.data());

    h->SetLineColor(args.color1);

    h->GetXaxis()->SetTitle(args.label.data());
    h->GetXaxis()->SetTitleOffset(args.fLabelOffset);
    h->GetXaxis()->SetTitleSize(args.fLabelSize);

    if (args.fLogX)
        canvas->SetLogx();
    if (args.fLogY)
        canvas->SetLogy();

    // if (!args.opt_stat.empty()) set_stat_boxes(canvas, false, h);
    save_canvas(canvas, path, fileName);
}

inline auto draw_hist1D(const std::shared_ptr<TH1>& hNoCut, const std::shared_ptr<TH1>& hWithCut, const std::string& path, const ArgsForDrawHist1D& args = {}) -> void {
    std::shared_ptr<TCanvas> canvas = make_canvas();
    std::string fileName = hNoCut->GetName();
    const auto hStack = std::make_shared<THStack>("hs", "");

    gStyle->SetOptStat(0);

    hWithCut->SetLineColor(args.color1);
    hWithCut->SetFillColorAlpha(args.color1, args.alpha_color1);
    hNoCut->SetLineColor(args.color2);

    auto scale = static_cast<int>(0.66 * hNoCut->GetMaximum() / hWithCut->GetMaximum());
    if (args.scaled && scale > 5)
        hWithCut->Scale(scale);

    hStack->Add(hNoCut.get(), "sames histo");
    hStack->Add(hWithCut.get(), "sames histo");
    hStack->Draw("hist nostack");

    hStack->GetXaxis()->SetTitle(args.label.data());
    hStack->GetXaxis()->SetTitleOffset(args.fLabelOffset);
    hStack->GetXaxis()->SetTitleSize(args.fLabelSize);

    if (args.fLogX)
        canvas->SetLogx();
    if (args.fLogY)
        canvas->SetLogy();

    for (double cut : args.cuts) {
        TLine line;
        line.SetLineColor(Color::kRed);
        line.SetLineWidth(2);
        line.DrawLine(cut, 0, cut, 0.8 * std::max({hWithCut->GetMaximum(), hNoCut->GetMaximum()}));
    }

    if (args.scaled && scale > 5) {
        const auto text = std::make_unique<TText>();
        text->SetNDC();
        text->SetTextColor(Color::kBlue);
        text->SetTextSize(0.04f);
        text->DrawText(0.15, 0.04, ("Light blue is scaled by " + std::to_string(scale)).c_str());
    }

    if (!args.opt_stat.empty()) set_stat_boxes(canvas, false, hWithCut, hNoCut);
    save_canvas(canvas, path, fileName);
}

struct ArgsHist2D {
    const std::string& fFileName = "";

    // cuts
    const std::vector<double> fCuts = {};
    const double fX1 = 0;
    const double fY1 = 0;
    const double fX2 = 0;
    const double fY2 = 0;

    // Log scale
    const bool fLogX = false;
    const bool fLogY = false;
    const bool fLogZ = false;

    // option
    const bool fSetStats = false;

    // label
    const std::string fLabelX;
    const float fLabelXOffset = 0.8f;
    const float fLabelXSize = 0.05f;
    const std::string fLabelY;
    const float fLabelYOffset = 1.0f;
    const float fLabelYSize = 0.05f;
};

inline auto draw_hist2D(const std::shared_ptr<TH2D>& h, const std::string& path, const ArgsHist2D& args = {}) -> void {
    const auto canvas = make_canvas();
    const auto myFileName = args.fFileName.empty() ? h->GetName() : args.fFileName;

    h->Draw("COLZ");

    h->GetXaxis()->SetTitle(args.fLabelX.data());
    h->GetXaxis()->SetTitleOffset(args.fLabelXOffset);
    h->GetXaxis()->SetTitleSize(args.fLabelXSize);

    h->GetYaxis()->SetTitle(args.fLabelY.data());
    h->GetYaxis()->SetTitleOffset(args.fLabelYOffset);
    h->GetYaxis()->SetTitleSize(args.fLabelYSize);

    if (args.fLogX)
        canvas->SetLogx();
    if (args.fLogY)
        canvas->SetLogy();
    if (args.fLogZ)
        canvas->SetLogz();

    save_canvas(canvas, path, myFileName);
}

struct OptionTH1 {
    const std::string file_name = "";

    const int16_t color1 = Color::kBlue;
    const float alpha_color1 = 0.0;

    const std::string draw_option = "histo";
    const std::string opt_stat = "emr";

    const std::pair<double, double> x_range = {};

    const std::string legend = "";

    const std::string title = "";

    const bool log_x = false;
    const bool log_y = false;

    // label
    const std::string label = "";
    const float label_offset = 0.8f;
    const float label_size = 0.05f;
};

inline auto test_draw_hist1D(const std::shared_ptr<TH1D>& h, const std::string& path, const OptionTH1& args = {}) -> void {

    std::shared_ptr<TCanvas> canvas = make_canvas();
    std::string fileName = args.file_name.empty() ? h->GetName() : args.file_name;

    // gStyle->SetOptStat(args.opt_stat.data());

    h->Draw(args.draw_option.data());
    h->SetLineColor(args.color1);

    h->GetXaxis()->SetTitle(args.label.data());
    h->GetXaxis()->SetTitleOffset(args.label_offset);
    h->GetXaxis()->SetTitleSize(args.label_size);

    if (!args.title.empty()) {
        h->SetTitle(args.title.data());
    }

    if (args.alpha_color1 != 0.0) {
        h->SetFillColorAlpha(args.color1, args.alpha_color1);
    }

    if (args.log_x) {
        canvas->SetLogx();
    }
    if (args.log_y) {
        canvas->SetLogy();
    }

    set_stat_boxes(canvas, false, h);
    save_canvas(canvas, path, fileName);
}

inline auto draw_sectors(const std::shared_ptr<TH1D>& h1, const std::shared_ptr<TH1D>& h2, const std::shared_ptr<TH1D>& h3, const std::shared_ptr<TH1D>& h4, const std::shared_ptr<TH1D>& h5, const std::shared_ptr<TH1D>& h6, const std::shared_ptr<TH1D>& hTot, const std::string& path, const OptionTH1& args = {}) -> void {

    std::shared_ptr<TCanvas> canvas = make_canvas();
    std::string fileName = args.file_name.empty() ? h1->GetName() : args.file_name;
    const auto h_stack = std::make_shared<THStack>("hs", "");

    // canvas->SetLogy();

    // gStyle->SetOptStat(0);

    h1->SetLineColor(Color::kBlue);
    h2->SetLineColor(Color::kRed);
    h3->SetLineColor(Color::kViolet);
    h4->SetLineColor(Color::kGreen);
    h5->SetLineColor(Color::kOrange);
    h6->SetLineColor(Color::kGrey);
    hTot->SetLineColor(Color::kBlack);

    double factor = 1.;
    h1->Scale(factor / h1->Integral());
    h2->Scale(factor / h2->Integral());
    h3->Scale(factor / h3->Integral());
    h4->Scale(factor / h4->Integral());
    h5->Scale(factor / h5->Integral());
    h6->Scale(factor / h6->Integral());
    hTot->Scale(factor / hTot->Integral());

    h_stack->Add(h1.get(), "sames histo");
    h_stack->Add(h2.get(), "sames histo");
    h_stack->Add(h3.get(), "sames histo");
    h_stack->Add(h4.get(), "sames histo");
    h_stack->Add(h5.get(), "sames histo");
    h_stack->Add(h6.get(), "sames histo");
    h_stack->Add(hTot.get(), "sames histo");

    h_stack->Draw("hist nostack");

    h_stack->GetXaxis()->SetTitle(args.label.data());
    h_stack->GetXaxis()->SetTitleOffset(args.label_offset);
    h_stack->GetXaxis()->SetTitleSize(args.label_size);

    auto legend = new TLegend(0.7, 0.5, 0.9, 0.9);
    legend->AddEntry(h1.get(), "Sector 1", "l");
    legend->AddEntry(h2.get(), "Sector 2", "l");
    legend->AddEntry(h3.get(), "Sector 3", "l");
    legend->AddEntry(h4.get(), "Sector 4", "l");
    legend->AddEntry(h5.get(), "Sector 5", "l");
    legend->AddEntry(h6.get(), "Sector 6", "l");
    legend->AddEntry(hTot.get(), "All sector", "l");
    legend->Draw();

    save_canvas(canvas, path, fileName);
}


inline auto draw_sectors(const std::shared_ptr<TH1D>& h0, const std::shared_ptr<TH1D>& h1, const std::shared_ptr<TH1D>& h2, const std::shared_ptr<TH1D>& h3, const std::shared_ptr<TH1D>& h4, const std::shared_ptr<TH1D>& h5, const std::shared_ptr<TH1D>& h6, const std::shared_ptr<TH1D>& hTot, const std::string& path, const OptionTH1& args = {}) -> void {

    std::shared_ptr<TCanvas> canvas = make_canvas();
    std::string fileName = args.file_name.empty() ? h1->GetName() : args.file_name;
    const auto h_stack = std::make_shared<THStack>("hs", "");

    // canvas->SetLogy();

    // gStyle->SetOptStat(0);

    h0->SetLineColor(Color::kPink);
    h1->SetLineColor(Color::kBlue);
    h2->SetLineColor(Color::kRed);
    h3->SetLineColor(Color::kViolet);
    h4->SetLineColor(Color::kGreen);
    h5->SetLineColor(Color::kOrange);
    h6->SetLineColor(Color::kGrey);
    hTot->SetLineColor(Color::kBlack);

    double factor = 1.;
    h0->Scale(factor / h0->Integral("width"));
    h1->Scale(factor / h1->Integral("width"));
    h2->Scale(factor / h2->Integral("width"));
    h3->Scale(factor / h3->Integral("width"));
    h4->Scale(factor / h4->Integral("width"));
    h5->Scale(factor / h5->Integral("width"));
    h6->Scale(factor / h6->Integral("width"));
    hTot->Scale(factor / hTot->Integral("width"));

    h_stack->Add(h0.get(), "sames histo");
    h_stack->Add(h1.get(), "sames histo");
    h_stack->Add(h2.get(), "sames histo");
    h_stack->Add(h3.get(), "sames histo");
    h_stack->Add(h4.get(), "sames histo");
    h_stack->Add(h5.get(), "sames histo");
    h_stack->Add(h6.get(), "sames histo");
    h_stack->Add(hTot.get(), "sames histo");

    h_stack->Draw("hist nostack");

    h_stack->GetXaxis()->SetTitle(args.label.data());
    h_stack->GetXaxis()->SetTitleOffset(args.label_offset);
    h_stack->GetXaxis()->SetTitleSize(args.label_size);

    auto legend = new TLegend(0.7, 0.5, 0.9, 0.9);
    legend->AddEntry(h0.get(), "Central", "l");
    legend->AddEntry(h1.get(), "Sector 1", "l");
    legend->AddEntry(h2.get(), "Sector 2", "l");
    legend->AddEntry(h3.get(), "Sector 3", "l");
    legend->AddEntry(h4.get(), "Sector 4", "l");
    legend->AddEntry(h5.get(), "Sector 5", "l");
    legend->AddEntry(h6.get(), "Sector 6", "l");
    legend->AddEntry(hTot.get(), "All sector", "l");
    legend->Draw();

    save_canvas(canvas, path, fileName);
}

inline auto draw_sectors_and_cutted_parts(const std::shared_ptr<TH1D>& h1, const std::shared_ptr<TH1D>& h2, const std::shared_ptr<TH1D>& h3, const std::shared_ptr<TH1D>& h4, const std::shared_ptr<TH1D>& h5, const std::shared_ptr<TH1D>& h6, const std::shared_ptr<TH1D>& hTot, const std::string& path, double cut_min, double cut_max, const OptionTH1& args = {}) -> void {

    std::shared_ptr<TCanvas> canvas = make_canvas();
    std::string fileName = args.file_name.empty() ? h1->GetName() : args.file_name;
    const auto h_stack = std::make_shared<THStack>("hs", "");

    // gStyle->SetOptStat(0);

    h1->SetLineColor(Color::kBlue);
    h2->SetLineColor(Color::kRed);
    h3->SetLineColor(Color::kViolet);
    h4->SetLineColor(Color::kGreen);
    h5->SetLineColor(Color::kOrange);
    h6->SetLineColor(Color::kGrey);
    hTot->SetLineColor(Color::kBlack);

    double factor = 1.;
    h1->Scale(factor / h1->Integral("width"));
    h2->Scale(factor / h2->Integral("width"));
    h3->Scale(factor / h3->Integral("width"));
    h4->Scale(factor / h4->Integral("width"));
    h5->Scale(factor / h5->Integral("width"));
    h6->Scale(factor / h6->Integral("width"));
    hTot->Scale(factor / hTot->Integral("width"));

    h_stack->Add(h1.get(), "sames histo");
    h_stack->Add(h2.get(), "sames histo");
    h_stack->Add(h3.get(), "sames histo");
    h_stack->Add(h4.get(), "sames histo");
    h_stack->Add(h5.get(), "sames histo");
    h_stack->Add(h6.get(), "sames histo");
    h_stack->Add(hTot.get(), "sames histo");

    h_stack->Draw("hist nostack");

    h_stack->GetXaxis()->SetTitle(args.label.data());
    h_stack->GetXaxis()->SetTitleOffset(args.label_offset);
    h_stack->GetXaxis()->SetTitleSize(args.label_size);

    auto legend = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend->AddEntry(h1.get(), "Sector 1", "f");
    legend->AddEntry(h2.get(), "Sector 2", "f");
    legend->AddEntry(h3.get(), "Sector 3", "f");
    legend->AddEntry(h4.get(), "Sector 4", "f");
    legend->AddEntry(h5.get(), "Sector 5", "f");
    legend->AddEntry(h6.get(), "Sector 6", "f");
    legend->AddEntry(hTot.get(), "All sector", "f");
    legend->Draw();

    save_canvas(canvas, path, fileName);
}

}  // namespace Core