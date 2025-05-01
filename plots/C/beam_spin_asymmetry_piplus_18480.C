#ifdef __CLING__
#pragma cling optimize(0)
#endif
void beam_spin_asymmetry_piplus_18480()
{
//=========Macro generated from canvas: c1/
//=========  (Wed Feb 19 18:47:33 2025) by ROOT version 6.30/04
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
   
   Double_t Graph_fx1025[8] = { -0.875, -0.625, -0.375, -0.125, 0.125, 0.375, 0.625, 0.875 };
   Double_t Graph_fy1025[8] = { -0.01556612, 0.009143807, -0.02315563, 0.001082251, -0.03313253, -0.001716738, 0.009857612, 0.01794872 };
   Double_t Graph_fex1025[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t Graph_fey1025[8] = { 0.01280054, 0.02038695, 0.02320567, 0.02326211, 0.02240554, 0.02071677, 0.01910751, 0.01265924 };
   TGraphErrors *gre = new TGraphErrors(8,Graph_fx1025,Graph_fy1025,Graph_fex1025,Graph_fey1025);
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
   
   TH1F *Graph_Graph1025 = new TH1F("Graph_Graph1025","",100,-1.05,1.05);
   Graph_Graph1025->SetMinimum(-0.06);
   Graph_Graph1025->SetMaximum(0.06);
   Graph_Graph1025->SetDirectory(nullptr);
   Graph_Graph1025->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1025->SetLineColor(ci);
   Graph_Graph1025->GetXaxis()->SetTitle("sin(#phi_{h})");
   Graph_Graph1025->GetXaxis()->SetNdivisions(505);
   Graph_Graph1025->GetXaxis()->SetLabelFont(42);
   Graph_Graph1025->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1025->GetXaxis()->SetTitleFont(42);
   Graph_Graph1025->GetYaxis()->SetTitle("Beam Spin Asymmetry");
   Graph_Graph1025->GetYaxis()->SetLabelFont(42);
   Graph_Graph1025->GetYaxis()->SetTitleFont(42);
   Graph_Graph1025->GetZaxis()->SetLabelFont(42);
   Graph_Graph1025->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1025->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1025);
   
   
   TF1 *f1026 = new TF1("f","pol1",-1.05,1.05, TF1::EAddToList::kNo);
   f1026->SetFillColor(19);
   f1026->SetFillStyle(0);
   f1026->SetLineColor(2);
   f1026->SetLineWidth(1);
   f1026->SetChisquare(4.04357);
   f1026->SetNDF(6);
   f1026->GetXaxis()->SetNdivisions(505);
   f1026->GetXaxis()->SetLabelFont(42);
   f1026->GetXaxis()->SetTitleOffset(1);
   f1026->GetXaxis()->SetTitleFont(42);
   f1026->GetYaxis()->SetLabelFont(42);
   f1026->GetYaxis()->SetTitleFont(42);
   f1026->SetParameter(0,-0.002088021);
   f1026->SetParError(0,0.006263179);
   f1026->SetParLimits(0,0,0);
   f1026->SetParameter(1,0.01581245);
   f1026->SetParError(1,0.009091684);
   f1026->SetParLimits(1,0,0);
   f1026->SetParent(gre);
   gre->GetListOfFunctions()->Add(f1026);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.735,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 4.044 / 6");
   ptstats_LaTex = ptstats->AddText("Prob  = 0.6708");
   ptstats_LaTex = ptstats->AddText("p0       = -0.002088 #pm 0.006263 ");
   ptstats_LaTex = ptstats->AddText("p1       = 0.01581 #pm 0.009092 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ape1");
   c1->Modified();
   c1->SetSelected(c1);
}
