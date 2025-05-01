#ifdef __CLING__
#pragma cling optimize(0)
#endif
void helicity_plus_piplus18532()
{
//=========Macro generated from canvas: c1/
//=========  (Mon Feb 24 13:51:23 2025) by ROOT version 6.30/04
   TCanvas *c1 = new TCanvas("c1", "",0,0,800,600);
   gStyle->SetOptFit(1);
   c1->SetHighLightColor(2);
   c1->Range(-1.315789,501.5799,1.315789,5430.645);
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
   
   TH1F *sinphi_h_pi_plus_helicty_plus18532__1 = new TH1F("sinphi_h_pi_plus_helicty_plus18532__1","",8,-1,1);
   sinphi_h_pi_plus_helicty_plus18532__1->SetBinContent(1,4315);
   sinphi_h_pi_plus_helicty_plus18532__1->SetBinContent(2,1666);
   sinphi_h_pi_plus_helicty_plus18532__1->SetBinContent(3,1415);
   sinphi_h_pi_plus_helicty_plus18532__1->SetBinContent(4,1299);
   sinphi_h_pi_plus_helicty_plus18532__1->SetBinContent(5,1392);
   sinphi_h_pi_plus_helicty_plus18532__1->SetBinContent(6,1704);
   sinphi_h_pi_plus_helicty_plus18532__1->SetBinContent(7,2000);
   sinphi_h_pi_plus_helicty_plus18532__1->SetBinContent(8,4593);
   sinphi_h_pi_plus_helicty_plus18532__1->SetBinError(1,65.68866);
   sinphi_h_pi_plus_helicty_plus18532__1->SetBinError(2,40.81666);
   sinphi_h_pi_plus_helicty_plus18532__1->SetBinError(3,37.61649);
   sinphi_h_pi_plus_helicty_plus18532__1->SetBinError(4,36.04164);
   sinphi_h_pi_plus_helicty_plus18532__1->SetBinError(5,37.30952);
   sinphi_h_pi_plus_helicty_plus18532__1->SetBinError(6,41.27953);
   sinphi_h_pi_plus_helicty_plus18532__1->SetBinError(7,44.72136);
   sinphi_h_pi_plus_helicty_plus18532__1->SetBinError(8,67.77168);
   sinphi_h_pi_plus_helicty_plus18532__1->SetEntries(18384);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.655,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *ptstats_LaTex = ptstats->AddText("sinphi_h_pi_plus_helicty_plus18532");
   ptstats_LaTex->SetTextSize(0.06439999);
   ptstats_LaTex = ptstats->AddText("Entries = 18384  ");
   ptstats_LaTex = ptstats->AddText("Mean  = 0.03183");
   ptstats_LaTex = ptstats->AddText("Std Dev   = 0.7183");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(1111);
   ptstats->Draw();
   sinphi_h_pi_plus_helicty_plus18532__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(sinphi_h_pi_plus_helicty_plus18532__1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   sinphi_h_pi_plus_helicty_plus18532__1->SetLineColor(ci);
   sinphi_h_pi_plus_helicty_plus18532__1->GetXaxis()->SetRange(1,8);
   sinphi_h_pi_plus_helicty_plus18532__1->GetXaxis()->SetNdivisions(505);
   sinphi_h_pi_plus_helicty_plus18532__1->GetXaxis()->SetLabelFont(42);
   sinphi_h_pi_plus_helicty_plus18532__1->GetXaxis()->SetTitleOffset(1);
   sinphi_h_pi_plus_helicty_plus18532__1->GetXaxis()->SetTitleFont(42);
   sinphi_h_pi_plus_helicty_plus18532__1->GetYaxis()->SetLabelFont(42);
   sinphi_h_pi_plus_helicty_plus18532__1->GetYaxis()->SetTitleFont(42);
   sinphi_h_pi_plus_helicty_plus18532__1->GetZaxis()->SetLabelFont(42);
   sinphi_h_pi_plus_helicty_plus18532__1->GetZaxis()->SetTitleOffset(1);
   sinphi_h_pi_plus_helicty_plus18532__1->GetZaxis()->SetTitleFont(42);
   sinphi_h_pi_plus_helicty_plus18532__1->Draw("");
   c1->Modified();
   c1->SetSelected(c1);
}
