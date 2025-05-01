#ifdef __CLING__
#pragma cling optimize(0)
#endif
void beam_spin_asymmetry_piplus_18587()
{
//=========Macro generated from canvas: c1/
//=========  (Wed Feb 19 18:47:38 2025) by ROOT version 6.30/04
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
   
   Double_t Graph_fx1034[8] = { -0.875, -0.625, -0.375, -0.125, 0.125, 0.375, 0.625, 0.875 };
   Double_t Graph_fy1034[8] = { 0.0003117207, -0.02800659, 0.01536936, 0.02318393, -0.02647059, 0.02973523, 0.03003413, -0.01958403 };
   Double_t Graph_fex1034[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t Graph_fey1034[8] = { 0.0124844, 0.02029437, 0.02226625, 0.02269798, 0.02214037, 0.02018247, 0.01847422, 0.01232129 };
   TGraphErrors *gre = new TGraphErrors(8,Graph_fx1034,Graph_fy1034,Graph_fex1034,Graph_fey1034);
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
   
   TH1F *Graph_Graph1034 = new TH1F("Graph_Graph1034","",100,-1.05,1.05);
   Graph_Graph1034->SetMinimum(-0.06);
   Graph_Graph1034->SetMaximum(0.06);
   Graph_Graph1034->SetDirectory(nullptr);
   Graph_Graph1034->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1034->SetLineColor(ci);
   Graph_Graph1034->GetXaxis()->SetTitle("sin(#phi_{h})");
   Graph_Graph1034->GetXaxis()->SetNdivisions(505);
   Graph_Graph1034->GetXaxis()->SetLabelFont(42);
   Graph_Graph1034->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1034->GetXaxis()->SetTitleFont(42);
   Graph_Graph1034->GetYaxis()->SetTitle("Beam Spin Asymmetry");
   Graph_Graph1034->GetYaxis()->SetLabelFont(42);
   Graph_Graph1034->GetYaxis()->SetTitleFont(42);
   Graph_Graph1034->GetZaxis()->SetLabelFont(42);
   Graph_Graph1034->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1034->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1034);
   
   
   TF1 *f1035 = new TF1("f","pol1",-1.05,1.05, TF1::EAddToList::kNo);
   f1035->SetFillColor(19);
   f1035->SetFillStyle(0);
   f1035->SetLineColor(2);
   f1035->SetLineWidth(1);
   f1035->SetChisquare(12.17461);
   f1035->SetNDF(6);
   f1035->GetXaxis()->SetNdivisions(505);
   f1035->GetXaxis()->SetLabelFont(42);
   f1035->GetXaxis()->SetTitleOffset(1);
   f1035->GetXaxis()->SetTitleFont(42);
   f1035->GetYaxis()->SetLabelFont(42);
   f1035->GetYaxis()->SetTitleFont(42);
   f1035->SetParameter(0,-0.0004222723);
   f1035->SetParError(0,0.006110542);
   f1035->SetParLimits(0,0,0);
   f1035->SetParameter(1,-0.001058109);
   f1035->SetParError(1,0.008865125);
   f1035->SetParLimits(1,0,0);
   f1035->SetParent(gre);
   gre->GetListOfFunctions()->Add(f1035);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.735,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 12.17 / 6");
   ptstats_LaTex = ptstats->AddText("Prob  = 0.05818");
   ptstats_LaTex = ptstats->AddText("p0       = -0.0004223 #pm 0.006111 ");
   ptstats_LaTex = ptstats->AddText("p1       = -0.001058 #pm 0.008865 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ape1");
   c1->Modified();
   c1->SetSelected(c1);
}
