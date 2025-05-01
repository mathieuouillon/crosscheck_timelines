#ifdef __CLING__
#pragma cling optimize(0)
#endif
void beam_spin_asymmetry_piplus_18770()
{
//=========Macro generated from canvas: c1/
//=========  (Wed Feb 19 18:47:15 2025) by ROOT version 6.30/04
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
   
   Double_t Graph_fx1010[8] = { -0.875, -0.625, -0.375, -0.125, 0.125, 0.375, 0.625, 0.875 };
   Double_t Graph_fy1010[8] = { -0.01077752, -0.001669449, 0.03161265, 0.02360877, 0.01956272, 0.0186593, 0.02714932, 0.0001217582 };
   Double_t Graph_fex1010[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t Graph_fey1010[8] = { 0.01132713, 0.01827265, 0.020004, 0.02053254, 0.01958527, 0.01858877, 0.01681682, 0.01103441 };
   TGraphErrors *gre = new TGraphErrors(8,Graph_fx1010,Graph_fy1010,Graph_fex1010,Graph_fey1010);
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
   
   TH1F *Graph_Graph1010 = new TH1F("Graph_Graph1010","",100,-1.05,1.05);
   Graph_Graph1010->SetMinimum(-0.06);
   Graph_Graph1010->SetMaximum(0.06);
   Graph_Graph1010->SetDirectory(nullptr);
   Graph_Graph1010->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1010->SetLineColor(ci);
   Graph_Graph1010->GetXaxis()->SetTitle("sin(#phi_{h})");
   Graph_Graph1010->GetXaxis()->SetNdivisions(505);
   Graph_Graph1010->GetXaxis()->SetLabelFont(42);
   Graph_Graph1010->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1010->GetXaxis()->SetTitleFont(42);
   Graph_Graph1010->GetYaxis()->SetTitle("Beam Spin Asymmetry");
   Graph_Graph1010->GetYaxis()->SetLabelFont(42);
   Graph_Graph1010->GetYaxis()->SetTitleFont(42);
   Graph_Graph1010->GetZaxis()->SetLabelFont(42);
   Graph_Graph1010->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1010->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1010);
   
   
   TF1 *f1011 = new TF1("f","pol1",-1.05,1.05, TF1::EAddToList::kNo);
   f1011->SetFillColor(19);
   f1011->SetFillStyle(0);
   f1011->SetLineColor(2);
   f1011->SetLineWidth(1);
   f1011->SetChisquare(6.540969);
   f1011->SetNDF(6);
   f1011->GetXaxis()->SetNdivisions(505);
   f1011->GetXaxis()->SetLabelFont(42);
   f1011->GetXaxis()->SetTitleOffset(1);
   f1011->GetXaxis()->SetTitleFont(42);
   f1011->GetYaxis()->SetLabelFont(42);
   f1011->GetYaxis()->SetTitleFont(42);
   f1011->SetParameter(0,0.007328278);
   f1011->SetParError(0,0.005516513);
   f1011->SetParLimits(0,0,0);
   f1011->SetParameter(1,0.007737442);
   f1011->SetParError(1,0.008001519);
   f1011->SetParLimits(1,0,0);
   f1011->SetParent(gre);
   gre->GetListOfFunctions()->Add(f1011);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.735,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 6.541 / 6");
   ptstats_LaTex = ptstats->AddText("Prob  = 0.3654");
   ptstats_LaTex = ptstats->AddText("p0       = 0.007328 #pm 0.005517 ");
   ptstats_LaTex = ptstats->AddText("p1       = 0.007737 #pm 0.008002 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ape1");
   c1->Modified();
   c1->SetSelected(c1);
}
