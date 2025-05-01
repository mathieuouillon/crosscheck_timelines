#ifdef __CLING__
#pragma cling optimize(0)
#endif
void beam_spin_asymmetry_piplus_18756()
{
//=========Macro generated from canvas: c1/
//=========  (Wed Feb 19 18:47:26 2025) by ROOT version 6.30/04
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
   
   Double_t Graph_fx1019[8] = { -0.875, -0.625, -0.375, -0.125, 0.125, 0.375, 0.625, 0.875 };
   Double_t Graph_fy1019[8] = { -0.01356319, 0.01208865, -0.05591572, 0.01142615, 0.002493766, -0.01791146, 0.005761317, 0.02041327 };
   Double_t Graph_fex1019[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t Graph_fey1019[8] = { 0.01125872, 0.01832473, 0.02012924, 0.0205716, 0.02038695, 0.01838347, 0.01656347, 0.01119084 };
   TGraphErrors *gre = new TGraphErrors(8,Graph_fx1019,Graph_fy1019,Graph_fex1019,Graph_fey1019);
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
   
   TH1F *Graph_Graph1019 = new TH1F("Graph_Graph1019","",100,-1.05,1.05);
   Graph_Graph1019->SetMinimum(-0.06);
   Graph_Graph1019->SetMaximum(0.06);
   Graph_Graph1019->SetDirectory(nullptr);
   Graph_Graph1019->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1019->SetLineColor(ci);
   Graph_Graph1019->GetXaxis()->SetTitle("sin(#phi_{h})");
   Graph_Graph1019->GetXaxis()->SetNdivisions(505);
   Graph_Graph1019->GetXaxis()->SetLabelFont(42);
   Graph_Graph1019->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1019->GetXaxis()->SetTitleFont(42);
   Graph_Graph1019->GetYaxis()->SetTitle("Beam Spin Asymmetry");
   Graph_Graph1019->GetYaxis()->SetLabelFont(42);
   Graph_Graph1019->GetYaxis()->SetTitleFont(42);
   Graph_Graph1019->GetZaxis()->SetLabelFont(42);
   Graph_Graph1019->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1019->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1019);
   
   
   TF1 *f1020 = new TF1("f","pol1",-1.05,1.05, TF1::EAddToList::kNo);
   f1020->SetFillColor(19);
   f1020->SetFillStyle(0);
   f1020->SetLineColor(2);
   f1020->SetLineWidth(1);
   f1020->SetChisquare(10.01575);
   f1020->SetNDF(6);
   f1020->GetXaxis()->SetNdivisions(505);
   f1020->GetXaxis()->SetLabelFont(42);
   f1020->GetXaxis()->SetTitleOffset(1);
   f1020->GetXaxis()->SetTitleFont(42);
   f1020->GetYaxis()->SetLabelFont(42);
   f1020->GetYaxis()->SetTitleFont(42);
   f1020->SetParameter(0,-0.001725241);
   f1020->SetParError(0,0.005533194);
   f1020->SetParLimits(0,0,0);
   f1020->SetParameter(1,0.01651757);
   f1020->SetParError(1,0.008015726);
   f1020->SetParLimits(1,0,0);
   f1020->SetParent(gre);
   gre->GetListOfFunctions()->Add(f1020);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.735,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 10.02 / 6");
   ptstats_LaTex = ptstats->AddText("Prob  = 0.124");
   ptstats_LaTex = ptstats->AddText("p0       = -0.001725 #pm 0.005533 ");
   ptstats_LaTex = ptstats->AddText("p1       = 0.01652 #pm 0.008016 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ape1");
   c1->Modified();
   c1->SetSelected(c1);
}
