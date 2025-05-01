#ifdef __CLING__
#pragma cling optimize(0)
#endif
void beam_spin_asymmetry_offset_piplus()
{
//=========Macro generated from canvas: c1_n3/
//=========  (Mon Mar 24 11:11:26 2025) by ROOT version 6.30/04
   TCanvas *c1_n3 = new TCanvas("c1_n3", "",0,0,800,600);
   gStyle->SetOptFit(1);
   c1_n3->SetHighLightColor(2);
   c1_n3->Range(18277.11,-0.05263158,18592.89,0.05263158);
   c1_n3->SetFillColor(0);
   c1_n3->SetBorderMode(0);
   c1_n3->SetBorderSize(2);
   c1_n3->SetTickx(1);
   c1_n3->SetTicky(1);
   c1_n3->SetLeftMargin(0.12);
   c1_n3->SetRightMargin(0.12);
   c1_n3->SetTopMargin(0.12);
   c1_n3->SetBottomMargin(0.12);
   c1_n3->SetFrameBorderMode(0);
   c1_n3->SetFrameBorderMode(0);
   
   Double_t Graph_fx1002[2] = { 18335, 18535 };
   Double_t Graph_fy1002[2] = { -0.001286907, 0.008180682 };
   Double_t Graph_fex1002[2] = { 0, 0 };
   Double_t Graph_fey1002[2] = { 0.006556596, 0.005226268 };
   TGraphErrors *gre = new TGraphErrors(2,Graph_fx1002,Graph_fy1002,Graph_fex1002,Graph_fey1002);
   gre->SetName("");
   gre->SetTitle("");
   gre->SetFillStyle(1000);
   
   TH1F *Graph_Graph1002 = new TH1F("Graph_Graph1002","",100,18315,18555);
   Graph_Graph1002->SetMinimum(-0.04);
   Graph_Graph1002->SetMaximum(0.04);
   Graph_Graph1002->SetDirectory(nullptr);
   Graph_Graph1002->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph1002->SetLineColor(ci);
   Graph_Graph1002->GetXaxis()->SetTitle("Run Number");
   Graph_Graph1002->GetXaxis()->SetNdivisions(505);
   Graph_Graph1002->GetXaxis()->SetLabelFont(42);
   Graph_Graph1002->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1002->GetXaxis()->SetTitleFont(42);
   Graph_Graph1002->GetYaxis()->SetTitle("Beam Spin Asymmetry slope");
   Graph_Graph1002->GetYaxis()->SetLabelFont(42);
   Graph_Graph1002->GetYaxis()->SetTitleFont(42);
   Graph_Graph1002->GetZaxis()->SetLabelFont(42);
   Graph_Graph1002->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1002->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1002);
   
   gre->Draw("ap");
   c1_n3->Modified();
   c1_n3->SetSelected(c1_n3);
}
