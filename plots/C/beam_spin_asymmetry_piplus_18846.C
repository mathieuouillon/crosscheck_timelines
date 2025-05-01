#ifdef __CLING__
#pragma cling optimize(0)
#endif
void beam_spin_asymmetry_piplus_18846()
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
   
   Double_t Graph_fx1031[8] = { -0.875, -0.625, -0.375, -0.125, 0.125, 0.375, 0.625, 0.875 };
   Double_t Graph_fy1031[8] = { -0.01847257, -0.03293522, -0.00655308, -0.0199027, 0.01013514, 0.01827302, 0.01543739, 0.01855019 };
   Double_t Graph_fex1031[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
   Double_t Graph_fey1031[8] = { 0.01174117, 0.01902434, 0.02090148, 0.02103051, 0.02054987, 0.01892867, 0.01690792, 0.01147003 };
   TGraphErrors *gre = new TGraphErrors(8,Graph_fx1031,Graph_fy1031,Graph_fex1031,Graph_fey1031);
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
   
   TH1F *Graph_Graph1031 = new TH1F("Graph_Graph1031","",100,-1.05,1.05);
   Graph_Graph1031->SetMinimum(-0.06);
   Graph_Graph1031->SetMaximum(0.06);
   Graph_Graph1031->SetDirectory(nullptr);
   Graph_Graph1031->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph1031->SetLineColor(ci);
   Graph_Graph1031->GetXaxis()->SetTitle("sin(#phi_{h})");
   Graph_Graph1031->GetXaxis()->SetNdivisions(505);
   Graph_Graph1031->GetXaxis()->SetLabelFont(42);
   Graph_Graph1031->GetXaxis()->SetTitleOffset(1);
   Graph_Graph1031->GetXaxis()->SetTitleFont(42);
   Graph_Graph1031->GetYaxis()->SetTitle("Beam Spin Asymmetry");
   Graph_Graph1031->GetYaxis()->SetLabelFont(42);
   Graph_Graph1031->GetYaxis()->SetTitleFont(42);
   Graph_Graph1031->GetZaxis()->SetLabelFont(42);
   Graph_Graph1031->GetZaxis()->SetTitleOffset(1);
   Graph_Graph1031->GetZaxis()->SetTitleFont(42);
   gre->SetHistogram(Graph_Graph1031);
   
   
   TF1 *f1032 = new TF1("f","pol1",-1.05,1.05, TF1::EAddToList::kNo);
   f1032->SetFillColor(19);
   f1032->SetFillStyle(0);
   f1032->SetLineColor(2);
   f1032->SetLineWidth(1);
   f1032->SetChisquare(1.938393);
   f1032->SetNDF(6);
   f1032->GetXaxis()->SetNdivisions(505);
   f1032->GetXaxis()->SetLabelFont(42);
   f1032->GetXaxis()->SetTitleOffset(1);
   f1032->GetXaxis()->SetTitleFont(42);
   f1032->GetYaxis()->SetLabelFont(42);
   f1032->GetYaxis()->SetTitleFont(42);
   f1032->SetParameter(0,-0.001270471);
   f1032->SetParError(0,0.005701613);
   f1032->SetParLimits(0,0,0);
   f1032->SetParameter(1,0.02504836);
   f1032->SetParError(1,0.008282989);
   f1032->SetParLimits(1,0,0);
   f1032->SetParent(gre);
   gre->GetListOfFunctions()->Add(f1032);
   
   TPaveStats *ptstats = new TPaveStats(0.62,0.735,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("#chi^{2} / ndf = 1.938 / 6");
   ptstats_LaTex = ptstats->AddText("Prob  = 0.9253");
   ptstats_LaTex = ptstats->AddText("p0       = -0.00127 #pm 0.005702 ");
   ptstats_LaTex = ptstats->AddText("p1       = 0.02505 #pm 0.008283 ");
   ptstats->SetOptStat(0);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   gre->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(gre->GetListOfFunctions());
   gre->Draw("ape1");
   c1->Modified();
   c1->SetSelected(c1);
}
