#ifdef __CLING__
#pragma cling optimize(0)
#endif
void beam_spin_asymmetry_piplus_18906()
{
//=========Macro generated from canvas: c1/
//=========  (Wed Feb 19 18:47:46 2025) by ROOT version 6.30/04
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
   
   Double_t Graph_fx1040[8] = { -0.875, -0.625, -0.375, -0.125, 0.125, 0.375, 0.625, 0.875 };
   Double_t Graph_fy1040[8] = { -0.02108844, 0.02292769, 0.01069519, 0.01516919, 0.003275109, 0.009575923, -0.007440476, 0.00620285 };
   Double_t Graph_fex1040[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t Graph_fey1040[8] = { 0.01304101, 0.02099803, 0.02312486, 0.02415431, 0.02336347, 0.02135407, 0.01928792, 0.01294776 };
   TGraphErrors *gre = new TGraphErrors(8,Graph_fx1040,Graph_fy1040,Graph_fex1040,Graph_fey1040);
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
   
   TH1F *Graph_Graph1040 = new TH1F("Graph_Graph1040","",100,-1.05,1.05);
   Graph_Graph1040->SetMinimum(-0.06);
   Graph_Graph1040->SetMaximum(0.06);
   Graph_Graph1040->SetDirectory(nullptr);
   Graph_Graph1040->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1040->SetLineColor(ci);
   Graph_Graph1040->GetXaxis()->SetTitle("sin(#phi_{h})");
   Graph_Graph1040->GetXaxis()->SetNdivisions(505);
   Graph_Graph1040->GetXaxis()->SetLabelFont(42);
   Graph_Graph1040->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1040->GetXaxis()->SetTitleFont(42);
   Graph_Graph1040->GetYaxis()->SetTitle("Beam Spin Asymmetry");
   Graph_Graph1040->GetYaxis()->SetLabelFont(42);
   Graph_Graph1040->GetYaxis()->SetTitleFont(42);
   Graph_Graph1040->GetZaxis()->SetLabelFont(42);
   Graph_Graph1040->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1040->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1040);
   
   
   TF1 *f1041 = new TF1("f","pol1",-1.05,1.05, TF1::EAddToList::kNo);
   f1041->SetFillColor(19);
   f1041->SetFillStyle(0);
   f1041->SetLineColor(2);
   f1041->SetLineWidth(1);
   f1041->SetChisquare(4.25069);
   f1041->SetNDF(6);
   f1041->GetXaxis()->SetNdivisions(505);
   f1041->GetXaxis()->SetLabelFont(42);
   f1041->GetXaxis()->SetTitleOffset(1);
   f1041->GetXaxis()->SetTitleFont(42);
   f1041->GetYaxis()->SetLabelFont(42);
   f1041->GetYaxis()->SetTitleFont(42);
   f1041->SetParameter(0,0.0005817624);
   f1041->SetParError(0,0.006403053);
   f1041->SetParLimits(0,0,0);
   f1041->SetParameter(1,0.008036343);
   f1041->SetParError(1,0.009275825);
   f1041->SetParLimits(1,0,0);
   f1041->SetParent(gre);
   gre->GetListOfFunctions()->Add(f1041);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.735,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 4.251 / 6");
   ptstats_LaTex = ptstats->AddText("Prob  = 0.6428");
   ptstats_LaTex = ptstats->AddText("p0       = 0.0005818 #pm 0.006403 ");
   ptstats_LaTex = ptstats->AddText("p1       = 0.008036 #pm 0.009276 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ape1");
   c1->Modified();
   c1->SetSelected(c1);
}
