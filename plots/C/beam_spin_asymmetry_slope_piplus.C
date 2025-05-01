#ifdef __CLING__
#pragma cling optimize(0)
#endif
void beam_spin_asymmetry_slope_piplus()
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
   
   Double_t Graph_fx1001[3] = { 18335, 18774, 18535 };
   Double_t Graph_fy1001[3] = { 0.02290539, 0.01365628, 0.01551095 };
   Double_t Graph_fex1001[3] = { 0, 0, 0 };
   Double_t Graph_fey1001[3] = { 0.009453557, 0.008004338, 0.007542701 };
   TGraphErrors *gre = new TGraphErrors(3,Graph_fx1001,Graph_fy1001,Graph_fex1001,Graph_fey1001);
   gre->SetName("");
   gre->SetTitle("");
   gre->SetFillStyle(1000);
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","",100,18291.1,18817.9);
   Graph_Graph1001->SetMinimum(-0.04);
   Graph_Graph1001->SetMaximum(0.04);
   Graph_Graph1001->SetDirectory(nullptr);
   Graph_Graph1001->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph1001->SetLineColor(ci);
   Graph_Graph1001->GetXaxis()->SetTitle("Run Number");
   Graph_Graph1001->GetXaxis()->SetNdivisions(505);
   Graph_Graph1001->GetXaxis()->SetLabelFont(42);
   Graph_Graph1001->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1001->GetXaxis()->SetTitleFont(42);
   Graph_Graph1001->GetYaxis()->SetTitle("Beam Spin Asymmetry slope");
   Graph_Graph1001->GetYaxis()->SetLabelFont(42);
   Graph_Graph1001->GetYaxis()->SetTitleFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelFont(42);
   Graph_Graph1001->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1001);
   
   gre->Draw("ap");
   c1_n4->Modified();
   c1_n4->SetSelected(c1_n4);
}
