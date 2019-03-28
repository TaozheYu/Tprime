#include "TLine.h"
#include "TFile.h"
#include "TH1F.h"
#include "TGraphErrors.h"
#include "THStack.h"
#include "TLegend.h"
#include "TTree.h"
#include "TTreePlayer.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TGraphAsymmErrors.h"
#include "TMultiGraph.h"
#include "TEfficiency.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iostream>
using namespace std;

const int val = 11;
//const int val = 6;
//const bool save_plots = true;
void setTDRStyle();

void limit_dineutrino(bool only_leptonTAG=false, bool save_plots = false, float min=0.005, float max=10., TString plot_name="Limit_prova.png") {
  //setTDRStyleANIELLO(); 
  //setTDRStyle(); 
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
  TCanvas* c1  = new TCanvas("c1","c1",0,0,800,600); //c1->SetLogy();
  TPad *pad = new TPad("pad","pad",0.01,0.01,0.99,0.99);
  c1->SetLogy();
  save_plots = true;
  plot_name="Limit_dineutrino.png";
  c1->SetBottomMargin(0.11); 

  Double_t XMass[val]    = {0.700, 0.800, 0.900, 1.000, 1.100, 1.200, 1.300, 1.400, 1.500, 1.600, 1.700};

  //combine -M Asymptotic datacard.txt
  Double_t Limit_Obs[val]     = {
0.8333   ,  0.3858   ,  0.2467  ,  0.1712  ,  0.1236  ,  0.0932  ,  0.0728   , 0.0645  ,  0.0579  ,  0.0487  ,  0.0366
};
  Double_t Limit_Exp_m2s[val] = {
0.2485  ,   0.1195   ,  0.0747  ,  0.0498  ,  0.0399  ,  0.0319  ,  0.0256  ,  0.0220  ,  0.0187  ,  0.0176  ,  0.0154
};
  Double_t Limit_Exp_m1s[val] = {
0.3315  ,   0.1586  ,   0.0996  ,  0.0666  ,  0.0537  ,  0.0429  ,  0.0346   , 0.0298  ,  0.0253  ,  0.0237  ,  0.0203
};
  Double_t Limit_Exp[val]     = {
0.4609   ,  0.2217  ,   0.1396  ,  0.0938  ,  0.0752  ,  0.0601  ,  0.0488  ,  0.0420  ,  0.0356  ,  0.0337  ,  0.0298
};
  Double_t Limit_Exp_p1s[val] = {
0.6447   ,  0.3109   ,  0.1970  ,  0.1322  ,  0.1067  ,  0.0854  ,  0.0695  ,  0.0597  ,  0.0513   , 0.0485  ,  0.0426
};
  Double_t Limit_Exp_p2s[val] = {
0.8635   ,  0.4173   ,  0.2672  ,  0.1794   , 0.1453  ,  0.1162  ,  0.0951  ,  0.0823  ,  0.0714  ,  0.0666   , 0.0595
};


  float coupling = 0.5;
  Double_t XSEC[val] = {pow(coupling,2)*0.25*5.820,
			pow(coupling,2)*0.25*3.860,
			pow(coupling,2)*0.25*2.720,
			pow(coupling,2)*0.25*1.950,
			pow(coupling,2)*0.25*1.350,
			pow(coupling,2)*0.25*0.982,
			pow(coupling,2)*0.25*0.716,
			pow(coupling,2)*0.25*0.540,
			pow(coupling,2)*0.25*0.408,
			pow(coupling,2)*0.25*0.305,
			pow(coupling,2)*0.25*0.230};


  //Draw limit
  TLegend *legendr = new TLegend(0.38,0.67,0.88,0.88);
  legendr->SetTextSize(0.04);
  legendr->SetFillColor(0);
  legendr->SetBorderSize(0);
	
  //2 sigma 
  TGraph *band_2s = new TGraph(2*val+1);
  for(int i=0;i<val;i++){
    band_2s->SetPoint(i,XMass[i],Limit_Exp_p2s[i]);
    band_2s->SetPoint(i+val,XMass[val-1-i],Limit_Exp_m2s[val-1-i]);
  }
  band_2s->SetPoint(2*val,XMass[0],Limit_Exp_p2s[0]);
  band_2s->SetLineStyle(1);
  band_2s->SetFillColor(kOrange);
  band_2s->Draw("ALF2");
  band_2s->SetMinimum(min);
  band_2s->SetMaximum(max);
  band_2s->SetTitle(0);
  //band_2s->GetXaxis()->SetTitle("M(Z,H) [GeV]");
  band_2s->GetXaxis()->SetTitle("#it{m}_{T} [TeV]");
  //band_2s->GetYaxis()->SetTitle("#sigma(pp #rightarrow Tb) #bf{#it{#Beta}}(T_{LH} #rightarrow tZ) [pb]");
  band_2s->GetYaxis()->SetTitle("#sigma(pp #rightarrow Tbq #rightarrow tZbq) [pb]");
  band_2s->GetXaxis()->SetTitleOffset(0.9);
  band_2s->GetYaxis()->SetTitleOffset(0.9);
  band_2s->GetXaxis()->SetRangeUser(0.700,1.700);
  band_2s->GetXaxis()->SetTitleSize(0.050);
  band_2s->GetYaxis()->SetTitleSize(0.050);
  band_2s->GetXaxis()->SetLabelSize(0.045);
  band_2s->GetYaxis()->SetLabelSize(0.045);
  band_2s->GetXaxis()->SetNdivisions(515);
  band_2s->Draw("LF2");
	
  //1 sigma
  TGraph *band_1s = new TGraph(2*val+1);
  for(int i=0;i<val;i++){
    band_1s->SetPoint(i,XMass[i],Limit_Exp_p1s[i]);
    band_1s->SetPoint(i+val,XMass[val-1-i],Limit_Exp_m1s[val-1-i]);
  }
  band_1s->SetPoint(2*val,XMass[0],Limit_Exp_p1s[0]);
  band_1s->SetLineStyle(1);
  band_1s->SetFillColor(kGreen+1);
  band_1s->Draw("LF2");
  //Expected
  TGraph *limit_exp = new TGraph(val,XMass,Limit_Exp);
  limit_exp->SetLineWidth(2);
  limit_exp->SetLineStyle(2);
  limit_exp->SetMarkerSize(1.3);
  limit_exp->Draw("LP");
  //Observed
  TGraph *limit_obs = new TGraph(val,XMass,Limit_Obs);
  //limit_obs->SetMarkerStyle(21);
  limit_obs->SetLineColor(1);
  limit_obs->SetLineWidth(2);
  //limit_obs->Draw("LP");

  TGraph *xsec = new TGraph(val,XMass,XSEC);
  //xsec->SetMarkerStyle(21);
  xsec->SetLineColor(2);
  xsec->SetMarkerColor(2);
  xsec->SetLineWidth(2);
  xsec->Draw("LP");

  TGraph *band_1s2 = new TGraph(2*val+1);
  TGraph *band_2s2 = new TGraph(2*val+1);
  band_1s2->SetLineStyle(2);
  band_1s2->SetFillColor(kGreen+1);
  band_1s2->SetLineColor(kBlue);
  band_1s2->SetMarkerColor(kBlue);
  band_2s2->SetLineStyle(2);
  band_2s2->SetFillColor(kOrange);
  band_2s2->SetLineColor(kBlue);
  band_2s2->SetMarkerColor(kBlue);

  //Legend
  //legendr->AddEntry(limit_obs, "Observed","LP");
  legendr->AddEntry(limit_exp, "Median expected","LP");
  legendr->AddEntry(band_1s, "68% expected","f");
  legendr->AddEntry(band_2s, "95% expected","f");
  legendr->AddEntry(xsec,"#sigma(NLO), C(bW)=0.5, #bf{#it{#Beta}}(tZ)=0.25","LP");
  legendr->Draw();

  TString cmsText     = "CMS";
  float cmsTextFont   = 61;  // default is helvetic-bold
  bool writeExtraText = true;
  TString extraText   = "";//Preliminary";
  TString extraText2   = "negligible width";//"width/mass = 0";
  //TString extraText   = "";
  float extraTextFont = 52;  // default is helvetica-italics
  // text sizes and text offsets with respect to the top frame in unit of the top margin size
  float lumiTextSize     = 0.6;
  float lumiTextOffset   = 0.2;
  float cmsTextSize      = 0.75;
  float cmsTextOffset    = 0.1;  // only used in outOfFrame version
  float relPosX    = 0.045;
  float relPosY    = 0.035;
  float relExtraDY = 1.2;
  // ratio of "CMS" and extra text size
  float extraOverCmsTextSize  = 0.76;
  //TString lumi_13TeV = "38.8 fb^{-1}";
  TString lumi_13TeV = "41.5 fb^{-1}";
  //TString lumi_8TeV  = "19.7 fb^{-1}";
  //TString lumi_7TeV  = "5.1 fb^{-1}";
  TString lumiText;
  lumiText += lumi_13TeV;
  lumiText += " (13 TeV)";
  float t = pad->GetTopMargin();
  float b = pad->GetBottomMargin();
  float r = pad->GetRightMargin();
  float l = pad->GetLeftMargin();
  TLatex latex;
  latex.SetNDC();
  latex.SetTextAngle(0);
  latex.SetTextColor(kBlack);    
  float extraTextSize = extraOverCmsTextSize*cmsTextSize;
  latex.SetTextFont(42);
  latex.SetTextAlign(31); 
  latex.SetTextSize(lumiTextSize*t);    
  latex.DrawLatex(1-r,1-t+lumiTextOffset*t,lumiText);
  latex.SetTextFont(cmsTextFont);
  latex.SetTextAlign(11); 
  latex.SetTextSize(cmsTextSize*t);    
  //latex.DrawLatex(l+0.04, 1-t+lumiTextOffset*t-0.71-0.06,cmsText);//l+0.03,1-t+lumiTextOffset*t-0.71,cmsText); 
  latex.DrawLatex(l+0.025, 1-t+lumiTextOffset*t-0.1,cmsText);//l+0.03,1-t+lumiTextOffset*t-0.71,cmsText);   
  latex.SetTextFont(extraTextFont);
  latex.SetTextSize(extraTextSize*t);
  latex.DrawLatex(l+0.025, 1-t+lumiTextOffset*t-0.085-0.055, extraText); 
  latex.SetTextFont(42);
  latex.SetTextSize(0.04);
  latex.DrawLatex(0.695, 0.635, extraText2); 
	
  //Save plot
  if(save_plots) c1->SaveAs(plot_name); 
}
/////
//   Set setTDRStyle_modified (from link https://twiki.cern.ch/twiki/pub/CMS/TRK10001/setTDRStyle_modified.C)
/////
void setTDRStyle(){
  TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");

  // For the canvas:
  tdrStyle->SetCanvasBorderMode(0);
  tdrStyle->SetCanvasColor(kWhite);
  tdrStyle->SetCanvasDefH(600); //Height of canvas
  tdrStyle->SetCanvasDefW(600); //Width of canvas
  tdrStyle->SetCanvasDefX(0);   //POsition on screen
  tdrStyle->SetCanvasDefY(0);
  // For the Pad:
  tdrStyle->SetPadBorderMode(0);
  tdrStyle->SetPadColor(kWhite);
  tdrStyle->SetPadGridX(false);
  tdrStyle->SetPadGridY(false);
  tdrStyle->SetGridColor(0);
  tdrStyle->SetGridStyle(3);
  tdrStyle->SetGridWidth(1);
  // For the frame:
  tdrStyle->SetFrameBorderMode(0);
  tdrStyle->SetFrameBorderSize(1);
  tdrStyle->SetFrameFillColor(0);
  tdrStyle->SetFrameFillStyle(0);
  tdrStyle->SetFrameLineColor(1);
  tdrStyle->SetFrameLineStyle(1);
  tdrStyle->SetFrameLineWidth(1);

  // For the histo:
  tdrStyle->SetHistFillColor(0);
  tdrStyle->SetHistLineColor(1);
  tdrStyle->SetHistLineStyle(0);
  tdrStyle->SetHistLineWidth(1);
  tdrStyle->SetErrorX(0.);
  tdrStyle->SetMarkerStyle(20);

  //For the fit/function:
  tdrStyle->SetOptFit(1);
  tdrStyle->SetFitFormat("5.4g");
  tdrStyle->SetFuncStyle(1);
  tdrStyle->SetFuncWidth(1);

  //For the date:
  tdrStyle->SetOptDate(0);

  // For the statistics box:
  tdrStyle->SetOptFile(0);
  tdrStyle->SetOptStat("e");
  tdrStyle->SetStatColor(kGray);
  tdrStyle->SetStatFont(42);

  tdrStyle->SetStatTextColor(1);
  tdrStyle->SetStatFormat("6.4g");
  tdrStyle->SetStatBorderSize(0);
  tdrStyle->SetStatX(1.); //Starting position on X axis
  tdrStyle->SetStatY(1.); //Starting position on Y axis
  tdrStyle->SetStatFontSize(0.025); //Vertical Size
  tdrStyle->SetStatW(0.15); //Horizontal size 
  // tdrStyle->SetStatStyle(Style_t style = 1001);

  // Margins:
  tdrStyle->SetPadTopMargin(0.05);
  tdrStyle->SetPadBottomMargin(0.125);
  tdrStyle->SetPadLeftMargin(0.105);
  tdrStyle->SetPadRightMargin(0.1);

  // For the Global title:

  //  tdrStyle->SetOptTitle(0);
  tdrStyle->SetTitleFont(42);
  tdrStyle->SetTitleColor(1);
  tdrStyle->SetTitleTextColor(1);
  tdrStyle->SetTitleFillColor(10);
  tdrStyle->SetTitleFontSize(0.05);

  // For the axis titles:
  tdrStyle->SetTitleColor(1, "XYZ");
  tdrStyle->SetTitleFont(42, "XYZ");
  tdrStyle->SetTitleSize(0.05, "XYZ");
  tdrStyle->SetTitleXOffset(0.9);
  tdrStyle->SetTitleYOffset(0.8);
  tdrStyle->SetTitleOffset(0.7, "Y"); // Another way to set the Offset

  // For the axis labels:
  tdrStyle->SetLabelColor(1, "XYZ");
  tdrStyle->SetLabelFont(42, "XYZ");
  tdrStyle->SetLabelOffset(0.007, "XYZ");
  tdrStyle->SetLabelSize(0.045, "XYZ");

  // For the axis:

  tdrStyle->SetAxisColor(1, "XYZ");
  tdrStyle->SetStripDecimals(kTRUE);
  tdrStyle->SetTickLength(0.03, "XYZ");
  tdrStyle->SetNdivisions(510, "XYZ");
  tdrStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  tdrStyle->SetPadTickY(1);

  // Change for log plots:
  tdrStyle->SetOptLogx(0);
  tdrStyle->SetOptLogy(0);
  tdrStyle->SetOptLogz(0);

  tdrStyle->cd();
}
