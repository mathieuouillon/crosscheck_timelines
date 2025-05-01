#ifdef __CLING__
#pragma cling optimize(0)
#endif
void beam_spin_asymmetry_piplus_18814()
{
//=========Macro generated from canvas: c1/
//=========  (Wed Feb 19 18:47:44 2025) by ROOT version 6.30/04
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
   
   Double_t Graph_fx1037[8] = { -0.875, -0.625, -0.375, -0.125, 0.125, 0.375, 0.625, 0.875 };
   Double_t Graph_fy1037[8] = { -0.006312467, 0.005555556, -0.01584722, -0.04299702, 0.009716941, -0.009921314, 0.02655889, 0.01226994 };
   Double_t Graph_fex1037[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t Graph_fey1037[8] = { 0.01146777, 0.0186339, 0.02015785, 0.02063282, 0.02055421, 0.01849633, 0.01699069, 0.01130539 };
   TGraphErrors *gre = new TGraphErrors(8,Graph_fx1037,Graph_fy1037,Graph_fex1037,Graph_fey1037);
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
   
   TH1F *Graph_Graph1037 = new TH1F("Graph_Graph1037","",100,-1.05,1.05);
   Graph_Graph1037->SetMinimum(-0.06);
   Graph_Graph1037->SetMaximum(0.06);
   Graph_Graph1037->SetDirectory(nullptr);
   Graph_Graph1037->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1037->SetLineColor(ci);
   Graph_Graph1037->GetXaxis()->SetTitle("sin(#phi_{h})");
   Graph_Graph1037->GetXaxis()->SetNdivisions(505);
   Graph_Graph1037->GetXaxis()->SetLabelFont(42);
   Graph_Graph1037->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1037->GetXaxis()->SetTitleFont(42);
   Graph_Graph1037->GetYaxis()->SetTitle("Beam Spin Asymmetry");
   Graph_Graph1037->GetYaxis()->SetLabelFont(42);
   Graph_Graph1037->GetYaxis()->SetTitleFont(42);
   Graph_Graph1037->GetZaxis()->SetLabelFont(42);
   Graph_Graph1037->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1037->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1037);
   
   
   TF1 *f1038 = new TF1("f","pol1",-1.05,1.05, TF1::EAddToList::kNo);
   f1038->SetFillColor(19);
   f1038->SetFillStyle(0);
   f1038->SetLineColor(2);
   f1038->SetLineWidth(1);
   f1038->SetChisquare(7.028137);
   f1038->SetNDF(6);
   f1038->GetXaxis()->SetNdivisions(505);
   f1038->GetXaxis()->SetLabelFont(42);
   f1038->GetXaxis()->SetTitleOffset(1);
   f1038->GetXaxis()->SetTitleFont(42);
   f1038->GetYaxis()->SetLabelFont(42);
   f1038->GetYaxis()->SetTitleFont(42);
   f1038->SetParameter(0,2.061543e-05);
   f1038->SetParError(0,0.005604509);
   f1038->SetParLimits(0,0,0);
   f1038->SetParameter(1,0.01274617);
   f1038->SetParError(1,0.008136769);
   f1038->SetParLimits(1,0,0);
   f1038->SetParent(gre);
   gre->GetListOfFunctions()->Add(f1038);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.735,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 7.028 / 6");
   ptstats_LaTex = ptstats->AddText("Prob  = 0.3183");
   ptstats_LaTex = ptstats->AddText("p0       = 2.062e-05 #pm 0.005605 ");
   ptstats_LaTex = ptstats->AddText("p1       = 0.01275 #pm 0.008137 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ape1");
   c1->Modified();
   c1->SetSelected(c1);
}
