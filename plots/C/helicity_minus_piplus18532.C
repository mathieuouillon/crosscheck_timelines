#ifdef __CLING__
#pragma cling optimize(0)
#endif
void helicity_minus_piplus18532()
{
//=========Macro generated from canvas: c1_n2/
//=========  (Mon Feb 24 13:51:23 2025) by ROOT version 6.30/04
   TCanvas *c1_n2 = new TCanvas("c1_n2", "",0,0,800,600);
   gStyle->SetOptFit(1);
   c1_n2->SetHighLightColor(2);
   c1_n2->Range(-1.315789,516.451,1.315789,5291.787);
   c1_n2->SetFillColor(0);
   c1_n2->SetBorderMode(0);
   c1_n2->SetBorderSize(2);
   c1_n2->SetTickx(1);
   c1_n2->SetTicky(1);
   c1_n2->SetLeftMargin(0.12);
   c1_n2->SetRightMargin(0.12);
   c1_n2->SetTopMargin(0.12);
   c1_n2->SetBottomMargin(0.12);
   c1_n2->SetFrameBorderMode(0);
   c1_n2->SetFrameBorderMode(0);
   
   TH1F *sinphi_h_pi_plus_helicty_minus18532__2 = new TH1F("sinphi_h_pi_plus_helicty_minus18532__2","",8,-1,1);
   sinphi_h_pi_plus_helicty_minus18532__2->SetBinContent(1,4390);
   sinphi_h_pi_plus_helicty_minus18532__2->SetBinContent(2,1655);
   sinphi_h_pi_plus_helicty_minus18532__2->SetBinContent(3,1395);
   sinphi_h_pi_plus_helicty_minus18532__2->SetBinContent(4,1290);
   sinphi_h_pi_plus_helicty_minus18532__2->SetBinContent(5,1299);
   sinphi_h_pi_plus_helicty_minus18532__2->SetBinContent(6,1560);
   sinphi_h_pi_plus_helicty_minus18532__2->SetBinContent(7,2025);
   sinphi_h_pi_plus_helicty_minus18532__2->SetBinContent(8,4479);
   sinphi_h_pi_plus_helicty_minus18532__2->SetBinError(1,66.25708);
   sinphi_h_pi_plus_helicty_minus18532__2->SetBinError(2,40.68169);
   sinphi_h_pi_plus_helicty_minus18532__2->SetBinError(3,37.3497);
   sinphi_h_pi_plus_helicty_minus18532__2->SetBinError(4,35.91657);
   sinphi_h_pi_plus_helicty_minus18532__2->SetBinError(5,36.04164);
   sinphi_h_pi_plus_helicty_minus18532__2->SetBinError(6,39.49684);
   sinphi_h_pi_plus_helicty_minus18532__2->SetBinError(7,45);
   sinphi_h_pi_plus_helicty_minus18532__2->SetBinError(8,66.92533);
   sinphi_h_pi_plus_helicty_minus18532__2->SetEntries(18093);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.655,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("sinphi_h_pi_plus_helicty_minus18532");
   ptstats_LaTex->SetTextSize(0.06439999);
   ptstats_LaTex = ptstats->AddText("Entries = 18093  ");
   ptstats_LaTex = ptstats->AddText("Mean  = 0.02014");
   ptstats_LaTex = ptstats->AddText("Std Dev   = 0.7227");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   sinphi_h_pi_plus_helicty_minus18532__2->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(sinphi_h_pi_plus_helicty_minus18532__2);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   sinphi_h_pi_plus_helicty_minus18532__2->SetLineColor(ci);
   sinphi_h_pi_plus_helicty_minus18532__2->GetXaxis()->SetRange(1,8);
   sinphi_h_pi_plus_helicty_minus18532__2->GetXaxis()->SetNdivisions(505);
   sinphi_h_pi_plus_helicty_minus18532__2->GetXaxis()->SetLabelFont(42);
   sinphi_h_pi_plus_helicty_minus18532__2->GetXaxis()->SetTitleOffset(1);
   sinphi_h_pi_plus_helicty_minus18532__2->GetXaxis()->SetTitleFont(42);
   sinphi_h_pi_plus_helicty_minus18532__2->GetYaxis()->SetLabelFont(42);
   sinphi_h_pi_plus_helicty_minus18532__2->GetYaxis()->SetTitleFont(42);
   sinphi_h_pi_plus_helicty_minus18532__2->GetZaxis()->SetLabelFont(42);
   sinphi_h_pi_plus_helicty_minus18532__2->GetZaxis()->SetTitleOffset(1);
   sinphi_h_pi_plus_helicty_minus18532__2->GetZaxis()->SetTitleFont(42);
   sinphi_h_pi_plus_helicty_minus18532__2->Draw("");
   c1_n2->Modified();
   c1_n2->SetSelected(c1_n2);
}
