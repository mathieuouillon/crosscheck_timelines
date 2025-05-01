#ifdef __CLING__
#pragma cling optimize(0)
#endif
void helicity_minus_piplus18331()
{
//=========Macro generated from canvas: c1_n2/
//=========  (Mon Feb 24 13:57:08 2025) by ROOT version 6.30/04
   TCanvas *c1_n2 = new TCanvas("c1_n2", "",0,0,800,600);
   gStyle->SetOptFit(1);
   c1_n2->SetHighLightColor(2);
   c1_n2->Range(-1.315789,138.4771,1.315789,3570.664);
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
   
   TH1F *sinphi_h_pi_plus_helicty_minus18331__2 = new TH1F("sinphi_h_pi_plus_helicty_minus18331__2","",8,-1,1);
   sinphi_h_pi_plus_helicty_minus18331__2->SetBinContent(1,2958);
   sinphi_h_pi_plus_helicty_minus18331__2->SetBinContent(2,1199);
   sinphi_h_pi_plus_helicty_minus18331__2->SetBinContent(3,807);
   sinphi_h_pi_plus_helicty_minus18331__2->SetBinContent(4,695);
   sinphi_h_pi_plus_helicty_minus18331__2->SetBinContent(5,827);
   sinphi_h_pi_plus_helicty_minus18331__2->SetBinContent(6,1141);
   sinphi_h_pi_plus_helicty_minus18331__2->SetBinContent(7,1340);
   sinphi_h_pi_plus_helicty_minus18331__2->SetBinContent(8,2980);
   sinphi_h_pi_plus_helicty_minus18331__2->SetBinError(1,54.3875);
   sinphi_h_pi_plus_helicty_minus18331__2->SetBinError(2,34.62658);
   sinphi_h_pi_plus_helicty_minus18331__2->SetBinError(3,28.40775);
   sinphi_h_pi_plus_helicty_minus18331__2->SetBinError(4,26.36285);
   sinphi_h_pi_plus_helicty_minus18331__2->SetBinError(5,28.75761);
   sinphi_h_pi_plus_helicty_minus18331__2->SetBinError(6,33.77869);
   sinphi_h_pi_plus_helicty_minus18331__2->SetBinError(7,36.60601);
   sinphi_h_pi_plus_helicty_minus18331__2->SetBinError(8,54.58938);
   sinphi_h_pi_plus_helicty_minus18331__2->SetEntries(11947);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.655,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("sinphi_h_pi_plus_helicty_minus18331");
   ptstats_LaTex->SetTextSize(0.06439999);
   ptstats_LaTex = ptstats->AddText("Entries = 11947  ");
   ptstats_LaTex = ptstats->AddText("Mean  = 0.0211");
   ptstats_LaTex = ptstats->AddText("Std Dev   = 0.7306");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   sinphi_h_pi_plus_helicty_minus18331__2->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(sinphi_h_pi_plus_helicty_minus18331__2);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   sinphi_h_pi_plus_helicty_minus18331__2->SetLineColor(ci);
   sinphi_h_pi_plus_helicty_minus18331__2->GetXaxis()->SetRange(1,8);
   sinphi_h_pi_plus_helicty_minus18331__2->GetXaxis()->SetNdivisions(505);
   sinphi_h_pi_plus_helicty_minus18331__2->GetXaxis()->SetLabelFont(42);
   sinphi_h_pi_plus_helicty_minus18331__2->GetXaxis()->SetTitleOffset(1);
   sinphi_h_pi_plus_helicty_minus18331__2->GetXaxis()->SetTitleFont(42);
   sinphi_h_pi_plus_helicty_minus18331__2->GetYaxis()->SetLabelFont(42);
   sinphi_h_pi_plus_helicty_minus18331__2->GetYaxis()->SetTitleFont(42);
   sinphi_h_pi_plus_helicty_minus18331__2->GetZaxis()->SetLabelFont(42);
   sinphi_h_pi_plus_helicty_minus18331__2->GetZaxis()->SetTitleOffset(1);
   sinphi_h_pi_plus_helicty_minus18331__2->GetZaxis()->SetTitleFont(42);
   sinphi_h_pi_plus_helicty_minus18331__2->Draw("");
   c1_n2->Modified();
   c1_n2->SetSelected(c1_n2);
}
