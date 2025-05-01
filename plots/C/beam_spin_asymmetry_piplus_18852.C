#ifdef __CLING__
#pragma cling optimize(0)
#endif
void beam_spin_asymmetry_piplus_18852()
{
//=========Macro generated from canvas: c1/
//=========  (Wed Feb 19 18:47:19 2025) by ROOT version 6.30/04
   TCanvas *c1 = new TCanvas("c1", "",0,0,800,600);
   gStyle->SetOptFit(1);
   c1->SetHighLightColor(2);
   c1->Range(-1.381579,-0.07894737,1.381579,0.07894737);
   c1->SetFillColor(0);
   c1->SetBorderMode(0);
   c1->SetBorderSize(2);
   c1->SetTickx(1);
   c1->SetTicky(1);
   c1->SetLeftMargin(0.12);
   c1->SetRightMargin(0.12);
   c1->SetTopMargin(0.12);
   c1->SetBottomMargin(0.12);
   c1->SetFrameBorderMode(0);
   c1->SetFrameBorderMode(0);
   
   Double_t Graph_fx1016[8] = { -0.875, -0.625, -0.375, -0.125, 0.125, 0.375, 0.625, 0.875 };
   Double_t Graph_fy1016[8] = { -0.03178162, -0.003015075, -0.02756892, 0.0250957, 0, -0.002743484, 0.02492299, -0.008656379 };
   Double_t Graph_fex1016[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t Graph_fey1016[8] = { 0.01148364, 0.01830323, 0.02043798, 0.02062404, 0.02039543, 0.01851852, 0.0167342, 0.01120066 };
   TGraphErrors *gre = new TGraphErrors(8,Graph_fx1016,Graph_fy1016,Graph_fex1016,Graph_fey1016);
   gre->SetName("");
   gre->SetTitle("");
   gre->SetFillStyle(1000);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0c5da5");
   gre->SetLineColor(ci);

   ci = TColor::GetColor("#0c5da5");
   gre->SetMarkerColor(ci);
   gre->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1016 = new TH1F("Graph_Graph1016","",100,-1.05,1.05);
   Graph_Graph1016->SetMinimum(-0.06);
   Graph_Graph1016->SetMaximum(0.06);
   Graph_Graph1016->SetDirectory(nullptr);
   Graph_Graph1016->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1016->SetLineColor(ci);
   Graph_Graph1016->GetXaxis()->SetTitle("sin(#phi_{h})");
   Graph_Graph1016->GetXaxis()->SetNdivisions(505);
   Graph_Graph1016->GetXaxis()->SetLabelFont(42);
   Graph_Graph1016->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1016->GetXaxis()->SetTitleFont(42);
   Graph_Graph1016->GetYaxis()->SetTitle("Beam Spin Asymmetry");
   Graph_Graph1016->GetYaxis()->SetLabelFont(42);
   Graph_Graph1016->GetYaxis()->SetTitleFont(42);
   Graph_Graph1016->GetZaxis()->SetLabelFont(42);
   Graph_Graph1016->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1016->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1016);
   
   
   TF1 *f1017 = new TF1("f","pol1",-1.05,1.05, TF1::EAddToList::kNo);
   f1017->SetFillColor(19);
   f1017->SetFillStyle(0);
   f1017->SetLineColor(2);
   f1017->SetLineWidth(1);
   f1017->SetChisquare(8.400814);
   f1017->SetNDF(6);
   f1017->GetXaxis()->SetNdivisions(505);
   f1017->GetXaxis()->SetLabelFont(42);
   f1017->GetXaxis()->SetTitleOffset(1);
   f1017->GetXaxis()->SetTitleFont(42);
   f1017->GetYaxis()->SetLabelFont(42);
   f1017->GetYaxis()->SetTitleFont(42);
   f1017->SetParameter(0,-0.008045496);
   f1017->SetParError(0,0.005579625);
   f1017->SetParLimits(0,0,0);
   f1017->SetParameter(1,0.01526644);
   f1017->SetParError(1,0.008093823);
   f1017->SetParLimits(1,0,0);
   f1017->SetParent(gre);
   gre->GetListOfFunctions()->Add(f1017);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.735,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 8.401 / 6");
   ptstats_LaTex = ptstats->AddText("Prob  = 0.2102");
   ptstats_LaTex = ptstats->AddText("p0       = -0.008045 #pm 0.00558 ");
   ptstats_LaTex = ptstats->AddText("p1       = 0.01527 #pm 0.008094 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ape1");
   c1->Modified();
   c1->SetSelected(c1);
}
