#ifdef __CLING__
#pragma cling optimize(0)
#endif
void beam_spin_asymmetry_piplus_18703()
{
//=========Macro generated from canvas: c1/
//=========  (Wed Feb 19 18:47:37 2025) by ROOT version 6.30/04
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
   
   Double_t Graph_fx1028[8] = { -0.875, -0.625, -0.375, -0.125, 0.125, 0.375, 0.625, 0.875 };
   Double_t Graph_fy1028[8] = { -0.03013315, -0.04138245, 0.03125, 0.001098901, 0.002159827, 0.07417582, 0.00814901, 0.01563586 };
   Double_t Graph_fex1028[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t Graph_fey1028[8] = { 0.01323604, 0.02132492, 0.02362278, 0.02344036, 0.02323697, 0.02139802, 0.01969894, 0.01318073 };
   TGraphErrors *gre = new TGraphErrors(8,Graph_fx1028,Graph_fy1028,Graph_fex1028,Graph_fey1028);
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
   
   TH1F *Graph_Graph1028 = new TH1F("Graph_Graph1028","",100,-1.05,1.05);
   Graph_Graph1028->SetMinimum(-0.06);
   Graph_Graph1028->SetMaximum(0.06);
   Graph_Graph1028->SetDirectory(nullptr);
   Graph_Graph1028->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1028->SetLineColor(ci);
   Graph_Graph1028->GetXaxis()->SetTitle("sin(#phi_{h})");
   Graph_Graph1028->GetXaxis()->SetNdivisions(505);
   Graph_Graph1028->GetXaxis()->SetLabelFont(42);
   Graph_Graph1028->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1028->GetXaxis()->SetTitleFont(42);
   Graph_Graph1028->GetYaxis()->SetTitle("Beam Spin Asymmetry");
   Graph_Graph1028->GetYaxis()->SetLabelFont(42);
   Graph_Graph1028->GetYaxis()->SetTitleFont(42);
   Graph_Graph1028->GetZaxis()->SetLabelFont(42);
   Graph_Graph1028->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1028->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1028);
   
   
   TF1 *f1029 = new TF1("f","pol1",-1.05,1.05, TF1::EAddToList::kNo);
   f1029->SetFillColor(19);
   f1029->SetFillStyle(0);
   f1029->SetLineColor(2);
   f1029->SetLineWidth(1);
   f1029->SetChisquare(13.93636);
   f1029->SetNDF(6);
   f1029->GetXaxis()->SetNdivisions(505);
   f1029->GetXaxis()->SetLabelFont(42);
   f1029->GetXaxis()->SetTitleOffset(1);
   f1029->GetXaxis()->SetTitleFont(42);
   f1029->GetYaxis()->SetLabelFont(42);
   f1029->GetYaxis()->SetTitleFont(42);
   f1029->SetParameter(0,0.002474332);
   f1029->SetParError(0,0.006472304);
   f1029->SetParLimits(0,0,0);
   f1029->SetParameter(1,0.03003645);
   f1029->SetParError(1,0.009427447);
   f1029->SetParLimits(1,0,0);
   f1029->SetParent(gre);
   gre->GetListOfFunctions()->Add(f1029);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.735,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 13.94 / 6");
   ptstats_LaTex = ptstats->AddText("Prob  = 0.03036");
   ptstats_LaTex = ptstats->AddText("p0       = 0.002474 #pm 0.006472 ");
   ptstats_LaTex = ptstats->AddText("p1       = 0.03004 #pm 0.009427 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ape1");
   c1->Modified();
   c1->SetSelected(c1);
}
