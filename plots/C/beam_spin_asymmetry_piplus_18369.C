#ifdef __CLING__
#pragma cling optimize(0)
#endif
void beam_spin_asymmetry_piplus_18369()
{
//=========Macro generated from canvas: c1/
//=========  (Wed Feb 19 18:45:57 2025) by ROOT version 6.30/04
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
   
   Double_t Graph_fx1001[8] = { -0.875, -0.625, -0.375, -0.125, 0.125, 0.375, 0.625, 0.875 };
   Double_t Graph_fy1001[8] = { 0.001571092, -0.05882353, -0.02864939, 0.02402402, 0.03733333, 0, 0.01535974, 0.04092173 };
   Double_t Graph_fex1001[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t Graph_fey1001[8] = { 0.0198185, 0.03080206, 0.03693584, 0.03874921, 0.03651484, 0.03227486, 0.02843251, 0.01993234 };
   TGraphErrors *gre = new TGraphErrors(8,Graph_fx1001,Graph_fy1001,Graph_fex1001,Graph_fey1001);
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
   
   TH1F *Graph_Graph1001 = new TH1F("Graph_Graph1001","",100,-1.05,1.05);
   Graph_Graph1001->SetMinimum(-0.06);
   Graph_Graph1001->SetMaximum(0.06);
   Graph_Graph1001->SetDirectory(nullptr);
   Graph_Graph1001->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1001->SetLineColor(ci);
   Graph_Graph1001->GetXaxis()->SetTitle("sin(#phi_{h})");
   Graph_Graph1001->GetXaxis()->SetNdivisions(505);
   Graph_Graph1001->GetXaxis()->SetLabelFont(42);
   Graph_Graph1001->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1001->GetXaxis()->SetTitleFont(42);
   Graph_Graph1001->GetYaxis()->SetTitle("Beam Spin Asymmetry");
   Graph_Graph1001->GetYaxis()->SetLabelFont(42);
   Graph_Graph1001->GetYaxis()->SetTitleFont(42);
   Graph_Graph1001->GetZaxis()->SetLabelFont(42);
   Graph_Graph1001->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1001->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1001);
   
   
   TF1 *f1002 = new TF1("f","pol1",-1.05,1.05, TF1::EAddToList::kNo);
   f1002->SetFillColor(19);
   f1002->SetFillStyle(0);
   f1002->SetLineColor(2);
   f1002->SetLineWidth(1);
   f1002->SetChisquare(5.281487);
   f1002->SetNDF(6);
   f1002->GetXaxis()->SetNdivisions(505);
   f1002->GetXaxis()->SetLabelFont(42);
   f1002->GetXaxis()->SetTitleOffset(1);
   f1002->GetXaxis()->SetTitleFont(42);
   f1002->GetYaxis()->SetLabelFont(42);
   f1002->GetYaxis()->SetTitleFont(42);
   f1002->SetParameter(0,0.007805852);
   f1002->SetParError(0,0.009779407);
   f1002->SetParLimits(0,0,0);
   f1002->SetParameter(1,0.02885507);
   f1002->SetParError(1,0.01410239);
   f1002->SetParLimits(1,0,0);
   f1002->SetParent(gre);
   gre->GetListOfFunctions()->Add(f1002);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.735,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 5.281 / 6");
   ptstats_LaTex = ptstats->AddText("Prob  = 0.5082");
   ptstats_LaTex = ptstats->AddText("p0       = 0.007806 #pm 0.009779 ");
   ptstats_LaTex = ptstats->AddText("p1       = 0.02886 #pm 0.0141 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ape1");
   c1->Modified();
   c1->SetSelected(c1);
}
