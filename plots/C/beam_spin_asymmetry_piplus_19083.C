#ifdef __CLING__
#pragma cling optimize(0)
#endif
void beam_spin_asymmetry_piplus_19083()
{
//=========Macro generated from canvas: c1/
//=========  (Wed Feb 19 18:47:47 2025) by ROOT version 6.30/04
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
   
   Double_t Graph_fx1043[8] = { -0.875, -0.625, -0.375, -0.125, 0.125, 0.375, 0.625, 0.875 };
   Double_t Graph_fy1043[8] = { -0.0001787949, 0.01180745, -0.01633987, -0.02451288, -0.03483724, -0.01213003, -0.00346287, 0.01584507 };
   Double_t Graph_fex1043[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t Graph_fey1043[8] = { 0.01337142, 0.02131039, 0.023338, 0.02507061, 0.02389775, 0.02202729, 0.01961539, 0.01326862 };
   TGraphErrors *gre = new TGraphErrors(8,Graph_fx1043,Graph_fy1043,Graph_fex1043,Graph_fey1043);
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
   
   TH1F *Graph_Graph1043 = new TH1F("Graph_Graph1043","",100,-1.05,1.05);
   Graph_Graph1043->SetMinimum(-0.06);
   Graph_Graph1043->SetMaximum(0.06);
   Graph_Graph1043->SetDirectory(nullptr);
   Graph_Graph1043->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1043->SetLineColor(ci);
   Graph_Graph1043->GetXaxis()->SetTitle("sin(#phi_{h})");
   Graph_Graph1043->GetXaxis()->SetNdivisions(505);
   Graph_Graph1043->GetXaxis()->SetLabelFont(42);
   Graph_Graph1043->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1043->GetXaxis()->SetTitleFont(42);
   Graph_Graph1043->GetYaxis()->SetTitle("Beam Spin Asymmetry");
   Graph_Graph1043->GetYaxis()->SetLabelFont(42);
   Graph_Graph1043->GetYaxis()->SetTitleFont(42);
   Graph_Graph1043->GetZaxis()->SetLabelFont(42);
   Graph_Graph1043->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1043->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1043);
   
   
   TF1 *f1044 = new TF1("f","pol1",-1.05,1.05, TF1::EAddToList::kNo);
   f1044->SetFillColor(19);
   f1044->SetFillStyle(0);
   f1044->SetLineColor(2);
   f1044->SetLineWidth(1);
   f1044->SetChisquare(5.235163);
   f1044->SetNDF(6);
   f1044->GetXaxis()->SetNdivisions(505);
   f1044->GetXaxis()->SetLabelFont(42);
   f1044->GetXaxis()->SetTitleOffset(1);
   f1044->GetXaxis()->SetTitleFont(42);
   f1044->GetYaxis()->SetLabelFont(42);
   f1044->GetYaxis()->SetTitleFont(42);
   f1044->SetParameter(0,-0.002197541);
   f1044->SetParError(0,0.006551716);
   f1044->SetParLimits(0,0,0);
   f1044->SetParameter(1,0.005205676);
   f1044->SetParError(1,0.009492164);
   f1044->SetParLimits(1,0,0);
   f1044->SetParent(gre);
   gre->GetListOfFunctions()->Add(f1044);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.735,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 5.235 / 6");
   ptstats_LaTex = ptstats->AddText("Prob  = 0.514");
   ptstats_LaTex = ptstats->AddText("p0       = -0.002198 #pm 0.006552 ");
   ptstats_LaTex = ptstats->AddText("p1       = 0.005206 #pm 0.009492 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ape1");
   c1->Modified();
   c1->SetSelected(c1);
}
