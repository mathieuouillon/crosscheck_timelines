#ifdef __CLING__
#pragma cling optimize(0)
#endif
void beam_spin_asymmetry_piplus_18379()
{
//=========Macro generated from canvas: c1/
//=========  (Wed Feb 19 18:47:16 2025) by ROOT version 6.30/04
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
   
   Double_t Graph_fx1013[8] = { -0.875, -0.625, -0.375, -0.125, 0.125, 0.375, 0.625, 0.875 };
   Double_t Graph_fy1013[8] = { -0.009786154, -0.04014273, 0.001283697, 0.01098901, 0.03813038, -0.01374885, -0.03263234, -0.01530967 };
   Double_t Graph_fex1013[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t Graph_fey1013[8] = { 0.01903812, 0.02986738, 0.03582872, 0.03706247, 0.03507153, 0.03027524, 0.02692885, 0.01865334 };
   TGraphErrors *gre = new TGraphErrors(8,Graph_fx1013,Graph_fy1013,Graph_fex1013,Graph_fey1013);
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
   
   TH1F *Graph_Graph1013 = new TH1F("Graph_Graph1013","",100,-1.05,1.05);
   Graph_Graph1013->SetMinimum(-0.06);
   Graph_Graph1013->SetMaximum(0.06);
   Graph_Graph1013->SetDirectory(nullptr);
   Graph_Graph1013->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1013->SetLineColor(ci);
   Graph_Graph1013->GetXaxis()->SetTitle("sin(#phi_{h})");
   Graph_Graph1013->GetXaxis()->SetNdivisions(505);
   Graph_Graph1013->GetXaxis()->SetLabelFont(42);
   Graph_Graph1013->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1013->GetXaxis()->SetTitleFont(42);
   Graph_Graph1013->GetYaxis()->SetTitle("Beam Spin Asymmetry");
   Graph_Graph1013->GetYaxis()->SetLabelFont(42);
   Graph_Graph1013->GetYaxis()->SetTitleFont(42);
   Graph_Graph1013->GetZaxis()->SetLabelFont(42);
   Graph_Graph1013->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1013->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1013);
   
   
   TF1 *f1014 = new TF1("f","pol1",-1.05,1.05, TF1::EAddToList::kNo);
   f1014->SetFillColor(19);
   f1014->SetFillStyle(0);
   f1014->SetLineColor(2);
   f1014->SetLineWidth(1);
   f1014->SetChisquare(4.055652);
   f1014->SetNDF(6);
   f1014->GetXaxis()->SetNdivisions(505);
   f1014->GetXaxis()->SetLabelFont(42);
   f1014->GetXaxis()->SetTitleOffset(1);
   f1014->GetXaxis()->SetTitleFont(42);
   f1014->GetYaxis()->SetLabelFont(42);
   f1014->GetYaxis()->SetTitleFont(42);
   f1014->SetParameter(0,-0.01169967);
   f1014->SetParError(0,0.009318247);
   f1014->SetParLimits(0,0,0);
   f1014->SetParameter(1,-0.002410702);
   f1014->SetParError(1,0.01340715);
   f1014->SetParLimits(1,0,0);
   f1014->SetParent(gre);
   gre->GetListOfFunctions()->Add(f1014);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.735,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 4.056 / 6");
   ptstats_LaTex = ptstats->AddText("Prob  = 0.6691");
   ptstats_LaTex = ptstats->AddText("p0       = -0.0117 #pm 0.009318 ");
   ptstats_LaTex = ptstats->AddText("p1       = -0.002411 #pm 0.01341 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ape1");
   c1->Modified();
   c1->SetSelected(c1);
}
