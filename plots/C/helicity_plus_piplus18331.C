#ifdef __CLING__
#pragma cling optimize(0)
#endif
void helicity_plus_piplus18331()
{
//=========Macro generated from canvas: c1/
//=========  (Mon Feb 24 13:57:08 2025) by ROOT version 6.30/04
   TCanvas *c1 = new TCanvas("c1", "",0,0,800,600);
   gStyle->SetOptFit(1);
   c1->SetHighLightColor(2);
   c1->Range(-1.315789,142.8687,1.315789,3616.492);
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
   
   TH1F *sinphi_h_pi_plus_helicty_plus18331__1 = new TH1F("sinphi_h_pi_plus_helicty_plus18331__1","",8,-1,1);
   sinphi_h_pi_plus_helicty_plus18331__1->SetBinContent(1,2807);
   sinphi_h_pi_plus_helicty_plus18331__1->SetBinContent(2,1160);
   sinphi_h_pi_plus_helicty_plus18331__1->SetBinContent(3,802);
   sinphi_h_pi_plus_helicty_plus18331__1->SetBinContent(4,706);
   sinphi_h_pi_plus_helicty_plus18331__1->SetBinContent(5,849);
   sinphi_h_pi_plus_helicty_plus18331__1->SetBinContent(6,1101);
   sinphi_h_pi_plus_helicty_plus18331__1->SetBinContent(7,1395);
   sinphi_h_pi_plus_helicty_plus18331__1->SetBinContent(8,3019);
   sinphi_h_pi_plus_helicty_plus18331__1->SetBinError(1,52.98113);
   sinphi_h_pi_plus_helicty_plus18331__1->SetBinError(2,34.05877);
   sinphi_h_pi_plus_helicty_plus18331__1->SetBinError(3,28.3196);
   sinphi_h_pi_plus_helicty_plus18331__1->SetBinError(4,26.57066);
   sinphi_h_pi_plus_helicty_plus18331__1->SetBinError(5,29.1376);
   sinphi_h_pi_plus_helicty_plus18331__1->SetBinError(6,33.18132);
   sinphi_h_pi_plus_helicty_plus18331__1->SetBinError(7,37.3497);
   sinphi_h_pi_plus_helicty_plus18331__1->SetBinError(8,54.94543);
   sinphi_h_pi_plus_helicty_plus18331__1->SetEntries(11839);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.655,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("sinphi_h_pi_plus_helicty_plus18331");
   ptstats_LaTex->SetTextSize(0.06439999);
   ptstats_LaTex = ptstats->AddText("Entries = 11839  ");
   ptstats_LaTex = ptstats->AddText("Mean  = 0.04075");
   ptstats_LaTex = ptstats->AddText("Std Dev   =  0.727");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   sinphi_h_pi_plus_helicty_plus18331__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(sinphi_h_pi_plus_helicty_plus18331__1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   sinphi_h_pi_plus_helicty_plus18331__1->SetLineColor(ci);
   sinphi_h_pi_plus_helicty_plus18331__1->GetXaxis()->SetRange(1,8);
   sinphi_h_pi_plus_helicty_plus18331__1->GetXaxis()->SetNdivisions(505);
   sinphi_h_pi_plus_helicty_plus18331__1->GetXaxis()->SetLabelFont(42);
   sinphi_h_pi_plus_helicty_plus18331__1->GetXaxis()->SetTitleOffset(1);
   sinphi_h_pi_plus_helicty_plus18331__1->GetXaxis()->SetTitleFont(42);
   sinphi_h_pi_plus_helicty_plus18331__1->GetYaxis()->SetLabelFont(42);
   sinphi_h_pi_plus_helicty_plus18331__1->GetYaxis()->SetTitleFont(42);
   sinphi_h_pi_plus_helicty_plus18331__1->GetZaxis()->SetLabelFont(42);
   sinphi_h_pi_plus_helicty_plus18331__1->GetZaxis()->SetTitleOffset(1);
   sinphi_h_pi_plus_helicty_plus18331__1->GetZaxis()->SetTitleFont(42);
   sinphi_h_pi_plus_helicty_plus18331__1->Draw("");
   c1->Modified();
   c1->SetSelected(c1);
}
