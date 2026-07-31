#include <electron_normalized_FD_yields/Drawing.hpp>

namespace normalized_yields {

Drawing::Drawing(Histograms& histograms)
    : m_histograms(histograms) {
}

auto Drawing::draw_timelines() -> void {

    

    auto canvas_all = Plotting::make_canvas();
    auto graph_normalized_electron_yield_all = m_histograms.graph_normalized_electron_yield_all->Merge();
    graph_normalized_electron_yield_all->Draw("AP");
    graph_normalized_electron_yield_all->GetXaxis()->SetTitle("Run Number");
    graph_normalized_electron_yield_all->GetYaxis()->SetTitle("Yields");
    Plotting::save_canvas(canvas_all, "../plots/", "graph_normalized_electron_yield_all");
    auto canvas_all_yield = Plotting::make_canvas();
    auto graph_electron_yield_all = m_histograms.graph_electron_yield_all->Merge();
    graph_electron_yield_all->Draw("AP");
    graph_electron_yield_all->GetXaxis()->SetTitle("Run Number");
    graph_electron_yield_all->GetYaxis()->SetTitle("Yields");
    Plotting::save_canvas(canvas_all_yield, "../plots/", "graph_electron_yield_all");
    auto canvas_all_charge = Plotting::make_canvas();
    auto graph_normalized_charge_all = m_histograms.graph_normalized_charge_all->Merge();
    graph_normalized_charge_all->Draw("AP");
    graph_normalized_charge_all->GetXaxis()->SetTitle("Run Number");
    graph_normalized_charge_all->GetYaxis()->SetTitle("Charge");
    Plotting::save_canvas(canvas_all_charge, "../plots/", "graph_normalized_charge_all");
    auto canvas_all_charge_ratio = Plotting::make_canvas();
    auto graph_normalized_charge_all_ratio = m_histograms.graph_normalized_charge_all->Merge();
    graph_normalized_charge_all_ratio->Draw("AP");
    graph_normalized_charge_all_ratio->GetXaxis()->SetTitle("Run Number");
    graph_normalized_charge_all_ratio->GetYaxis()->SetTitle("Charge Ratio");
    Plotting::save_canvas(canvas_all_charge_ratio, "../plots/", "graph_normalized_charge_all_ratio");



    // Pions plus and minus
    auto canvas_pip_yield_all = Plotting::make_canvas();
    auto graph_pip_yield_all = m_histograms.graph_pip_yield_all->Merge();
    graph_pip_yield_all->Draw("AP");
    graph_pip_yield_all->GetXaxis()->SetTitle("Run Number");
    graph_pip_yield_all->GetYaxis()->SetTitle("Yields");
    Plotting::save_canvas(canvas_pip_yield_all, "../plots/", "graph_pip_yield_all");
    auto canvas_pip_yield_all_charge = Plotting::make_canvas();
    auto graph_normalized_pip_yield_all = m_histograms.graph_normalized_pip_yield_all->Merge();
    graph_normalized_pip_yield_all->Draw("AP");
    graph_normalized_pip_yield_all->GetXaxis()->SetTitle("Run Number");
    graph_normalized_pip_yield_all->GetYaxis()->SetTitle("Charge");
    Plotting::save_canvas(canvas_pip_yield_all_charge, "../plots/", "graph_normalized_pip_yield_all");
    auto canvas_pim_yield_all = Plotting::make_canvas();
    auto graph_pim_yield_all = m_histograms.graph_pim_yield_all->Merge();
    graph_pim_yield_all->Draw("AP");
    graph_pim_yield_all->GetXaxis()->SetTitle("Run Number");
    graph_pim_yield_all->GetYaxis()->SetTitle("Yields");
    Plotting::save_canvas(canvas_pim_yield_all, "../plots/", "graph_pim_yield_all");
    auto canvas_pim_yield_all_charge = Plotting::make_canvas();
    auto graph_normalized_pim_yield_all = m_histograms.graph_normalized_pim_yield_all->Merge();
    graph_normalized_pim_yield_all->Draw("AP");
    graph_normalized_pim_yield_all->GetXaxis()->SetTitle("Run Number");
    graph_normalized_pim_yield_all->GetYaxis()->SetTitle("Charge");
    Plotting::save_canvas(canvas_pim_yield_all_charge, "../plots/", "graph_normalized_pim_yield_all");

    // Pi0
    auto canvas_pi0_yield_all = Plotting::make_canvas();
    auto graph_pi0_yield_all = m_histograms.graph_pi0_yield_all->Merge();
    graph_pi0_yield_all->Draw("AP");
    graph_pi0_yield_all->GetXaxis()->SetTitle("Run Number");
    graph_pi0_yield_all->GetYaxis()->SetTitle("Yields");
    Plotting::save_canvas(canvas_pi0_yield_all, "../plots/", "graph_pi0_yield_all");
    auto canvas_pi0_yield_all_charge = Plotting::make_canvas();
    auto graph_normalized_pi0_yield_all = m_histograms.graph_normalized_pi0_yield_all->Merge();
    graph_normalized_pi0_yield_all->Draw("AP");
    graph_normalized_pi0_yield_all->GetXaxis()->SetTitle("Run Number");
    graph_normalized_pi0_yield_all->GetYaxis()->SetTitle("Charge");
    Plotting::save_canvas(canvas_pi0_yield_all_charge, "../plots/", "graph_normalized_pi0_yield_all");




    // Rho0
    auto canvas_rho0_yield_all = Plotting::make_canvas();
    auto graph_rho0_yield_all = m_histograms.graph_rho0_yield_all->Merge();
    graph_rho0_yield_all->Draw("AP");
    graph_rho0_yield_all->GetXaxis()->SetTitle("Run Number");
    graph_rho0_yield_all->GetYaxis()->SetTitle("Yields");
    Plotting::save_canvas(canvas_rho0_yield_all, "../plots/", "graph_rho0_yield_all");
    auto canvas_rho0_yield_all_charge = Plotting::make_canvas();
    auto graph_normalized_rho0_yield_all = m_histograms.graph_normalized_rho0_yield_all->Merge();
    graph_normalized_rho0_yield_all->Draw("AP");    
    graph_normalized_rho0_yield_all->GetXaxis()->SetTitle("Run Number");
    graph_normalized_rho0_yield_all->GetYaxis()->SetTitle("Charge");
    Plotting::save_canvas(canvas_rho0_yield_all_charge, "../plots/", "graph_normalized_rho0_yield_all");

}

}  // namespace electron_normalized_FD_yields