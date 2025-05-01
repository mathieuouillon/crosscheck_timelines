#ifdef __CLING__
#pragma cling optimize(0)
#endif
void beam_spin_asymmetry_piplus_18532()
{
//=========Macro generated from canvas: c1_n3/
//=========  (Mon Feb 24 13:51:23 2025) by ROOT version 6.30/04
   TCanvas *c1_n3 = new TCanvas("c1_n3", "",0,0,800,600);
   gStyle->SetOptFit(1);
   c1_n3->SetHighLightColor(2);
   c1_n3->Range(-1.381579,-0.07894737,1.381579,0.07894737);
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
   
   Double_t Graph_fx1001[8] = { -0.875, -0.625, -0.375, -0.125, 0.125, 0.375, 0.625, 0.875 };
   Double_t Graph_fy1001[8] = { -0.008615738, 0.003312255, 0.007117438, 0.003476246, 0.03455964, 0.04411765, -0.00621118, 0.01256614 };
   Double_t Graph_fex1001[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t Graph_fey1001[8] = { 0.01071805, 0.01735264, 0.01886457, 0.01965323, 0.01927716, 0.0175035, 0.01576221, 0.01049901 };
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
   f1002->SetChisquare(7.562422);
   f1002->SetNDF(6);
   f1002->GetXaxis()->SetNdivisions(505);
   f1002->GetXaxis()->SetLabelFont(42);
   f1002->GetXaxis()->SetTitleOffset(1);
   f1002->GetXaxis()->SetTitleFont(42);
   f1002->GetYaxis()->SetLabelFont(42);
   f1002->GetYaxis()->SetTitleFont(42);
   f1002->SetParameter(0,0.007691389);
   f1002->SetParError(0,0.005239566);
   f1002->SetParLimits(0,0,0);
   f1002->SetParameter(1,0.01105912);
   f1002->SetParError(1,0.007582666);
   f1002->SetParLimits(1,0,0);
   f1002->SetParent(gre);
   gre->GetListOfFunctions()->Add(f1002);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.735,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 7.562 / 6");
   ptstats_LaTex = ptstats->AddText("Prob  = 0.2719");
   ptstats_LaTex = ptstats->AddText("p0       = 0.007691 #pm 0.00524 ");
   ptstats_LaTex = ptstats->AddText("p1       = 0.01106 #pm 0.007583 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ape1");
   c1_n3->Modified();
   c1_n3->SetSelected(c1_n3);
}
