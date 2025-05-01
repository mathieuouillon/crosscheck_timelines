#ifdef __CLING__
#pragma cling optimize(0)
#endif
void beam_spin_asymmetry_piplus_19040()
{
//=========Macro generated from canvas: c1/
//=========  (Wed Feb 19 18:47:27 2025) by ROOT version 6.30/04
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
   
   Double_t Graph_fx1022[8] = { -0.875, -0.625, -0.375, -0.125, 0.125, 0.375, 0.625, 0.875 };
   Double_t Graph_fy1022[8] = { -0.008284024, 0.01922428, -0.01515772, 0.03850932, -0.001231022, -0.003791796, 0.01286353, 0.01868926 };
   Double_t Graph_fex1022[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t Graph_fey1022[8] = { 0.01146702, 0.01836486, 0.02024026, 0.02034892, 0.02025687, 0.01856633, 0.0167225, 0.01116222 };
   TGraphErrors *gre = new TGraphErrors(8,Graph_fx1022,Graph_fy1022,Graph_fex1022,Graph_fey1022);
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
   
   TH1F *Graph_Graph1022 = new TH1F("Graph_Graph1022","",100,-1.05,1.05);
   Graph_Graph1022->SetMinimum(-0.06);
   Graph_Graph1022->SetMaximum(0.06);
   Graph_Graph1022->SetDirectory(nullptr);
   Graph_Graph1022->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1022->SetLineColor(ci);
   Graph_Graph1022->GetXaxis()->SetTitle("sin(#phi_{h})");
   Graph_Graph1022->GetXaxis()->SetNdivisions(505);
   Graph_Graph1022->GetXaxis()->SetLabelFont(42);
   Graph_Graph1022->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1022->GetXaxis()->SetTitleFont(42);
   Graph_Graph1022->GetYaxis()->SetTitle("Beam Spin Asymmetry");
   Graph_Graph1022->GetYaxis()->SetLabelFont(42);
   Graph_Graph1022->GetYaxis()->SetTitleFont(42);
   Graph_Graph1022->GetZaxis()->SetLabelFont(42);
   Graph_Graph1022->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1022->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1022);
   
   
   TF1 *f1023 = new TF1("f","pol1",-1.05,1.05, TF1::EAddToList::kNo);
   f1023->SetFillColor(19);
   f1023->SetFillStyle(0);
   f1023->SetLineColor(2);
   f1023->SetLineWidth(1);
   f1023->SetChisquare(5.637684);
   f1023->SetNDF(6);
   f1023->GetXaxis()->SetNdivisions(505);
   f1023->GetXaxis()->SetLabelFont(42);
   f1023->GetXaxis()->SetTitleOffset(1);
   f1023->GetXaxis()->SetTitleFont(42);
   f1023->GetYaxis()->SetLabelFont(42);
   f1023->GetYaxis()->SetTitleFont(42);
   f1023->SetParameter(0,0.006849626);
   f1023->SetParError(0,0.005563271);
   f1023->SetParLimits(0,0,0);
   f1023->SetParameter(1,0.01113454);
   f1023->SetParError(1,0.008078417);
   f1023->SetParLimits(1,0,0);
   f1023->SetParent(gre);
   gre->GetListOfFunctions()->Add(f1023);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.735,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 5.638 / 6");
   ptstats_LaTex = ptstats->AddText("Prob  = 0.465");
   ptstats_LaTex = ptstats->AddText("p0       = 0.00685 #pm 0.005563 ");
   ptstats_LaTex = ptstats->AddText("p1       = 0.01113 #pm 0.008078 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ape1");
   c1->Modified();
   c1->SetSelected(c1);
}
