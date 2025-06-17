#include <electron_normalized_FD_yields/Drawing.hpp>

namespace electron_normalized_FD_yields {

Drawing::Drawing(Histograms& histograms)
    : m_histograms(histograms) {
}

auto Drawing::draw_timelines() -> void {

    auto canvas1 = Plotting::make_canvas();
    auto graph_normalized_electron_yield_s1 = m_histograms.graph_normalized_electron_yield_s1->Merge();
    graph_normalized_electron_yield_s1->Draw("AP");
    graph_normalized_electron_yield_s1->GetXaxis()->SetTitle("Run Number");
    graph_normalized_electron_yield_s1->GetYaxis()->SetTitle("Yields");
    Plotting::save_canvas(canvas1, "../plots/", "graph_normalized_electron_yield_s1");

    auto canvas1_yield = Plotting::make_canvas();
    auto graph_electron_yield_s1 = m_histograms.graph_electron_yield_s1->Merge();
    graph_electron_yield_s1->Draw("AP");
    graph_electron_yield_s1->GetXaxis()->SetTitle("Run Number");
    graph_electron_yield_s1->GetYaxis()->SetTitle("Yields");
    Plotting::save_canvas(canvas1_yield, "../plots/", "graph_electron_yield_s1");

    auto canvas1_charge = Plotting::make_canvas();
    auto graph_normalized_charge_s1 = m_histograms.graph_normalized_charge_s1->Merge();
    graph_normalized_charge_s1->Draw("AP");
    graph_normalized_charge_s1->GetXaxis()->SetTitle("Run Number");
    graph_normalized_charge_s1->GetYaxis()->SetTitle("Charge");
    Plotting::save_canvas(canvas1_charge, "../plots/", "graph_normalized_charge_s1");

    auto canvas2 = Plotting::make_canvas();
    auto graph_normalized_electron_yield_s2 = m_histograms.graph_normalized_electron_yield_s2->Merge();
    graph_normalized_electron_yield_s2->Draw("AP");
    graph_normalized_electron_yield_s2->GetXaxis()->SetTitle("Run Number");
    graph_normalized_electron_yield_s2->GetYaxis()->SetTitle("Yields");
    Plotting::save_canvas(canvas2, "../plots/", "graph_normalized_electron_yield_s2");

    auto canvas2_yield = Plotting::make_canvas();
    auto graph_electron_yield_s2 = m_histograms.graph_electron_yield_s2->Merge();
    graph_electron_yield_s2->Draw("AP");
    graph_electron_yield_s2->GetXaxis()->SetTitle("Run Number");
    graph_electron_yield_s2->GetYaxis()->SetTitle("Yields");
    Plotting::save_canvas(canvas2_yield, "../plots/", "graph_electron_yield_s2");
    auto canvas2_charge = Plotting::make_canvas();
    auto graph_normalized_charge_s2 = m_histograms.graph_normalized_charge_s2->Merge();
    graph_normalized_charge_s2->Draw("AP");
    graph_normalized_charge_s2->GetXaxis()->SetTitle("Run Number");
    graph_normalized_charge_s2->GetYaxis()->SetTitle("Charge");
    Plotting::save_canvas(canvas2_charge, "../plots/", "graph_normalized_charge_s2");
    auto canvas3 = Plotting::make_canvas();
    auto graph_normalized_electron_yield_s3 = m_histograms.graph_normalized_electron_yield_s3->Merge();
    graph_normalized_electron_yield_s3->Draw("AP");
    graph_normalized_electron_yield_s3->GetXaxis()->SetTitle("Run Number");
    graph_normalized_electron_yield_s3->GetYaxis()->SetTitle("Yields");
    Plotting::save_canvas(canvas3, "../plots/", "graph_normalized_electron_yield_s3");
    auto canvas3_yield = Plotting::make_canvas();
    auto graph_electron_yield_s3 = m_histograms.graph_electron_yield_s3->Merge();
    graph_electron_yield_s3->Draw("AP");
    graph_electron_yield_s3->GetXaxis()->SetTitle("Run Number");
    graph_electron_yield_s3->GetYaxis()->SetTitle("Yields");
    Plotting::save_canvas(canvas3_yield, "../plots/", "graph_electron_yield_s3");
    auto canvas3_charge = Plotting::make_canvas();
    auto graph_normalized_charge_s3 = m_histograms.graph_normalized_charge_s3->Merge();
    graph_normalized_charge_s3->Draw("AP");
    graph_normalized_charge_s3->GetXaxis()->SetTitle("Run Number");
    graph_normalized_charge_s3->GetYaxis()->SetTitle("Charge");
    Plotting::save_canvas(canvas3_charge, "../plots/", "graph_normalized_charge_s3");
    auto canvas4 = Plotting::make_canvas();
    auto graph_normalized_electron_yield_s4 = m_histograms.graph_normalized_electron_yield_s4->Merge();
    graph_normalized_electron_yield_s4->Draw("AP");
    graph_normalized_electron_yield_s4->GetXaxis()->SetTitle("Run Number");
    graph_normalized_electron_yield_s4->GetYaxis()->SetTitle("Yields");
    Plotting::save_canvas(canvas4, "../plots/", "graph_normalized_electron_yield_s4");
    auto canvas4_yield = Plotting::make_canvas();
    auto graph_electron_yield_s4 = m_histograms.graph_electron_yield_s4->Merge();
    graph_electron_yield_s4->Draw("AP");
    graph_electron_yield_s4->GetXaxis()->SetTitle("Run Number");
    graph_electron_yield_s4->GetYaxis()->SetTitle("Yields");
    Plotting::save_canvas(canvas4_yield, "../plots/", "graph_electron_yield_s4");
    auto canvas4_charge = Plotting::make_canvas();
    auto graph_normalized_charge_s4 = m_histograms.graph_normalized_charge_s4->Merge();
    graph_normalized_charge_s4->Draw("AP"); 
    graph_normalized_charge_s4->GetXaxis()->SetTitle("Run Number");
    graph_normalized_charge_s4->GetYaxis()->SetTitle("Charge");
    Plotting::save_canvas(canvas4_charge, "../plots/", "graph_normalized_charge_s4");
    auto canvas5 = Plotting::make_canvas();
    auto graph_normalized_electron_yield_s5 = m_histograms.graph_normalized_electron_yield_s5->Merge();
    graph_normalized_electron_yield_s5->Draw("AP");
    graph_normalized_electron_yield_s5->GetXaxis()->SetTitle("Run Number");
    graph_normalized_electron_yield_s5->GetYaxis()->SetTitle("Yields");
    Plotting::save_canvas(canvas5, "../plots/", "graph_normalized_electron_yield_s5");
    auto canvas5_yield = Plotting::make_canvas();
    auto graph_electron_yield_s5 = m_histograms.graph_electron_yield_s5->Merge();
    graph_electron_yield_s5->Draw("AP");
    graph_electron_yield_s5->GetXaxis()->SetTitle("Run Number");
    graph_electron_yield_s5->GetYaxis()->SetTitle("Yields");
    Plotting::save_canvas(canvas5_yield, "../plots/", "graph_electron_yield_s5");
    auto canvas5_charge = Plotting::make_canvas();
    auto graph_normalized_charge_s5 = m_histograms.graph_normalized_charge_s5->Merge();
    graph_normalized_charge_s5->Draw("AP");
    graph_normalized_charge_s5->GetXaxis()->SetTitle("Run Number");
    graph_normalized_charge_s5->GetYaxis()->SetTitle("Charge");
    Plotting::save_canvas(canvas5_charge, "../plots/", "graph_normalized_charge_s5");
    auto canvas6 = Plotting::make_canvas();
    auto graph_normalized_electron_yield_s6 = m_histograms.graph_normalized_electron_yield_s6->Merge();
    graph_normalized_electron_yield_s6->Draw("AP");
    graph_normalized_electron_yield_s6->GetXaxis()->SetTitle("Run Number");
    graph_normalized_electron_yield_s6->GetYaxis()->SetTitle("Yields");
    Plotting::save_canvas(canvas6, "../plots/", "graph_normalized_electron_yield_s6");  
    auto canvas6_yield = Plotting::make_canvas();
    auto graph_electron_yield_s6 = m_histograms.graph_electron_yield_s6->Merge();
    graph_electron_yield_s6->Draw("AP");
    graph_electron_yield_s6->GetXaxis()->SetTitle("Run Number");
    graph_electron_yield_s6->GetYaxis()->SetTitle("Yields");
    Plotting::save_canvas(canvas6_yield, "../plots/", "graph_electron_yield_s6");
    auto canvas6_charge = Plotting::make_canvas();
    auto graph_normalized_charge_s6 = m_histograms.graph_normalized_charge_s6->Merge();
    graph_normalized_charge_s6->Draw("AP");
    graph_normalized_charge_s6->GetXaxis()->SetTitle("Run Number");
    graph_normalized_charge_s6->GetYaxis()->SetTitle("Charge");
    Plotting::save_canvas(canvas6_charge, "../plots/", "graph_normalized_charge_s6");

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