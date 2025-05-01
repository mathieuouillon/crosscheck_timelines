#ifdef __CLING__
#pragma cling optimize(0)
#endif
void beam_spin_asymmetry_slope_piminus()
{
//=========Macro generated from canvas: c1_n4/
//=========  (Fri Mar 21 11:35:46 2025) by ROOT version 6.30/04
   TCanvas *c1_n4 = new TCanvas("c1_n4", "",0,0,800,600);
   gStyle->SetOptFit(1);
   c1_n4->SetHighLightColor(2);
   c1_n4->Range(18207.92,-0.05263158,18901.08,0.05263158);
   c1_n4->SetFillColor(0);
   c1_n4->SetBorderMode(0);
   c1_n4->SetBorderSize(2);
   c1_n4->SetTickx(1);
   c1_n4->SetTicky(1);
   c1_n4->SetLeftMargin(0.12);
   c1_n4->SetRightMargin(0.12);
   c1_n4->SetTopMargin(0.12);
   c1_n4->SetBottomMargin(0.12);
   c1_n4->SetFrameBorderMode(0);
   c1_n4->SetFrameBorderMode(0);
   
   Double_t Graph_fx1003[3] = { 18335, 18774, 18535 };
   Double_t Graph_fy1003[3] = { -0.009583456, 0.01187533, -0.004144007 };
   Double_t Graph_fex1003[3] = { 0, 0, 0 };
   Double_t Graph_fey1003[3] = { 0.01506118, 0.008072902, 0.007630226 };
   TGraphErrors *gre = new TGraphErrors(3,Graph_fx1003,Graph_fy1003,Graph_fex1003,Graph_fey1003);
   gre->SetName("");
   gre->SetTitle("");
   gre->SetFillStyle(1000);
   
   TH1F *Graph_Graph1003 = new TH1F("Graph_Graph1003","",100,18291.1,18817.9);
   Graph_Graph1003->SetMinimum(-0.04);
   Graph_Graph1003->SetMaximum(0.04);
   Graph_Graph1003->SetDirectory(nullptr);
   Graph_Graph1003->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph1003->SetLineColor(ci);
   Graph_Graph1003->GetXaxis()->SetTitle("Run Number");
   Graph_Graph1003->GetXaxis()->SetNdivisions(505);
   Graph_Graph1003->GetXaxis()->SetLabelFont(42);
   Graph_Graph1003->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1003->GetXaxis()->SetTitleFont(42);
   Graph_Graph1003->GetYaxis()->SetTitle("Beam Spin Asymmetry slope");
   Graph_Graph1003->GetYaxis()->SetLabelFont(42);
   Graph_Graph1003->GetYaxis()->SetTitleFont(42);
   Graph_Graph1003->GetZaxis()->SetLabelFont(42);
   Graph_Graph1003->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1003->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1003);
   
   gre->Draw("ap");
   c1_n4->Modified();
   c1_n4->SetSelected(c1_n4);
}
