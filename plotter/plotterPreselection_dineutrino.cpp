#include "plotterPreselection_dineutrino.h"

void plotterPreselection_dineutrino(){ 
  gROOT->Reset();
  gStyle->SetCanvasColor(0);
  gStyle->SetFrameBorderMode(0);
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1,0);
  gStyle->SetTitleX(0.5); //title X location 
  gStyle->SetTitleY(0.96); //title Y location 
  gStyle->SetPaintTextFormat(".2f");
  gErrorIgnoreLevel = kError;
  using namespace std; 

  bool SYST = false;

  vector<TString> name;                vector<int> bin;      vector<float> Min;      vector<float> Max;     vector<TString> axis;

  //name.push_back("TopMass"); bin.push_back(20);     Min.push_back(0);    Max.push_back(500);    axis.push_back("Top Mass[GeV]");
  //name.push_back("TopPt"); bin.push_back(40);     Min.push_back(0);    Max.push_back(1000);    axis.push_back("Top pt[GeV] ");
  //name.push_back("TopEta"); bin.push_back(40);     Min.push_back(-3);    Max.push_back(3);    axis.push_back("Top #eta");

  //name.push_back("Met_pt"); bin.push_back(40);     Min.push_back(0);    Max.push_back(1000);    axis.push_back("Met pt[GeV] ");
  //name.push_back("Met_phi"); bin.push_back(40);     Min.push_back(-3);    Max.push_back(3);    axis.push_back("Met #eta");

  name.push_back("deltaPhiMetTop"); bin.push_back(40);     Min.push_back(-3);    Max.push_back(3);    axis.push_back("#Delta#phi(Met,top)");
  



  for(int i=0; i<name.size(); i++){
    const char *plot = name[i];
    char CUT[1000]; char CUTmuo1[1000]; char CUTmuo2[1000]; char CUTele1[1000]; char CUTele2[1000]; char CUTtri1[1000]; char CUTtri2[1000]; char CUTtri3[1000]; char CUTtri4[1000]; char CUTpup1[1000]; char CUTpup2[1000]; char CUTbta1[1000]; char CUTbta2[1000]; char CUTtop1[1000]; char CUTtop2[1000]; char CUTfor1[1000]; char CUTfor2[1000]; char CUTwje1[1000]; char CUTwje2[1000];
	
	sprintf(CUT,    "PUWeight  *w_Btag  *w_for  *w_topJet  *w_WJet  *genWeight*(category0==1||category1==1||category2==1)");

	MakeHistos(CUT,plot,bin[i],Min[i],Max[i],0,data_SR,background_SR,ZToNuNu_1_SR,ZToNuNu_2_SR,ZToNuNu_3_SR,ZToNuNu_4_SR,ZToNuNu_5_SR,ZToNuNu_6_SR,ZToNuNu_7_SR,QCD_1_SR,QCD_2_SR,QCD_3_SR,QCD_4_SR,QCD_5_SR,QCD_6_SR,QCD_7_SR,WToLNu_SR,TT_SR,ST_1_SR,ST_2_SR,ST_3_SR,ST_4_SR,ZZ_SR,ZW_SR,WW_SR,tptzm0700lh_SR,tptzm1000lh_SR,tptzm1400lh_SR,tptzm1700lh_SR);

	tptzm0700lh_SR->SetLineWidth(2); tptzm1000lh_SR->SetLineWidth(2); tptzm1400lh_SR->SetLineWidth(2); tptzm1700lh_SR->SetLineWidth(2); 

	ZToNuNu_1_SR->SetLineWidth(2); ZToNuNu_2_SR->SetLineWidth(2);ZToNuNu_3_SR->SetLineWidth(2); ZToNuNu_4_SR->SetLineWidth(2); ZToNuNu_5_SR->SetLineWidth(2); ZToNuNu_6_SR->SetLineWidth(2); ZToNuNu_7_SR->SetLineWidth(2);
	ZToNuNu_1_SR->SetLineWidth(2); ZToNuNu_2_SR->SetLineWidth(2);ZToNuNu_3_SR->SetLineWidth(2); ZToNuNu_4_SR->SetLineWidth(2); ZToNuNu_5_SR->SetLineWidth(2); ZToNuNu_6_SR->SetLineWidth(2); ZToNuNu_7_SR->SetLineWidth(2);
	QCD_1_SR->SetLineWidth(2); QCD_2_SR->SetLineWidth(2);QCD_3_SR->SetLineWidth(2); QCD_4_SR->SetLineWidth(2); QCD_5_SR->SetLineWidth(2); QCD_6_SR->SetLineWidth(2); QCD_7_SR->SetLineWidth(2);
	QCD_1_SR->SetLineWidth(2); QCD_2_SR->SetLineWidth(2);QCD_3_SR->SetLineWidth(2); QCD_4_SR->SetLineWidth(2); QCD_5_SR->SetLineWidth(2); QCD_6_SR->SetLineWidth(2); QCD_7_SR->SetLineWidth(2); 
	WToLNu_SR->SetLineWidth(2);
	TT_SR->SetLineWidth(2);
	ST_1_SR->SetLineWidth(2); ST_2_SR->SetLineWidth(2); ST_3_SR->SetLineWidth(2); ST_4_SR->SetLineWidth(2); 
	ZZ_SR->SetLineWidth(2); ZW_SR->SetLineWidth(2); WW_SR->SetLineWidth(2); 

	tptzm1700lh_SR->SetLineStyle(2); tptzm0700lh_SR->SetLineColor(2); 
	tptzm1000lh_SR->SetLineColor(2); tptzm1400lh_SR->SetLineColor(2); 
	tptzm1700lh_SR->SetLineColor(2); 

	ZToNuNu_1_SR->SetLineColor(kOrange); ZToNuNu_2_SR->SetLineColor(kOrange);ZToNuNu_3_SR->SetLineColor(kOrange); ZToNuNu_4_SR->SetLineColor(kOrange); ZToNuNu_5_SR->SetLineColor(kOrange); ZToNuNu_6_SR->SetLineColor(kOrange); ZToNuNu_7_SR->SetLineColor(kOrange);
	ZToNuNu_1_SR->SetLineColor(kOrange); ZToNuNu_2_SR->SetLineColor(kOrange);ZToNuNu_3_SR->SetLineColor(kOrange); ZToNuNu_4_SR->SetLineColor(kOrange); ZToNuNu_5_SR->SetLineColor(kOrange); ZToNuNu_6_SR->SetLineColor(kOrange); ZToNuNu_7_SR->SetLineColor(kOrange);
	QCD_1_SR->SetLineColor(kGreen+3); QCD_2_SR->SetLineColor(kGreen+3);QCD_3_SR->SetLineColor(kGreen+3); QCD_4_SR->SetLineColor(kGreen+3); QCD_5_SR->SetLineColor(kGreen+3); QCD_6_SR->SetLineColor(kGreen+3); QCD_7_SR->SetLineColor(kGreen+3);
	QCD_1_SR->SetLineColor(kGreen+3); QCD_2_SR->SetLineColor(kGreen+3);QCD_3_SR->SetLineColor(kGreen+3); QCD_4_SR->SetLineColor(kGreen+3); QCD_5_SR->SetLineColor(kGreen+3); QCD_6_SR->SetLineColor(kGreen+3); QCD_7_SR->SetLineColor(kGreen+3); 
	WToLNu_SR->SetLineColor(kCyan+2);
	TT_SR->SetLineColor(kCyan-4);
	ST_1_SR->SetLineColor(kCyan-4); ST_2_SR->SetLineColor(kCyan-4); ST_3_SR->SetLineColor(kCyan-4); ST_4_SR->SetLineColor(kCyan-4); 
	ZZ_SR->SetLineColor(kCyan); ZW_SR->SetLineColor(kCyan); WW_SR->SetLineColor(kCyan); 


	ZToNuNu_1_SR->SetFillColor(kOrange); ZToNuNu_2_SR->SetFillColor(kOrange);ZToNuNu_3_SR->SetFillColor(kOrange); ZToNuNu_4_SR->SetFillColor(kOrange); ZToNuNu_5_SR->SetFillColor(kOrange); ZToNuNu_6_SR->SetFillColor(kOrange); ZToNuNu_7_SR->SetFillColor(kOrange);
	ZToNuNu_1_SR->SetFillColor(kOrange); ZToNuNu_2_SR->SetFillColor(kOrange);ZToNuNu_3_SR->SetFillColor(kOrange); ZToNuNu_4_SR->SetFillColor(kOrange); ZToNuNu_5_SR->SetFillColor(kOrange); ZToNuNu_6_SR->SetFillColor(kOrange); ZToNuNu_7_SR->SetFillColor(kOrange);
	QCD_1_SR->SetFillColor(kGreen+3); QCD_2_SR->SetFillColor(kGreen+3);QCD_3_SR->SetFillColor(kGreen+3); QCD_4_SR->SetFillColor(kGreen+3); QCD_5_SR->SetFillColor(kGreen+3); QCD_6_SR->SetFillColor(kGreen+3); QCD_7_SR->SetFillColor(kGreen+3);
	QCD_1_SR->SetFillColor(kGreen+3); QCD_2_SR->SetFillColor(kGreen+3);QCD_3_SR->SetFillColor(kGreen+3); QCD_4_SR->SetFillColor(kGreen+3); QCD_5_SR->SetFillColor(kGreen+3); QCD_6_SR->SetFillColor(kGreen+3); QCD_7_SR->SetFillColor(kGreen+3); 
	WToLNu_SR->SetFillColor(kCyan+2);
	TT_SR->SetFillColor(kCyan-4);
	ST_1_SR->SetFillColor(kCyan-4); ST_2_SR->SetFillColor(kCyan-4); ST_3_SR->SetFillColor(kCyan-4); ST_4_SR->SetFillColor(kCyan-4); 
	ZZ_SR->SetFillColor(kCyan); ZW_SR->SetFillColor(kCyan); WW_SR->SetFillColor(kCyan);

	data_SR->SetLineWidth(2); data_SR->SetLineColor(1); data_SR->SetMarkerColor(1); data_SR->SetMarkerStyle(20); data_SR->SetMarkerSize(1.3);

    Double_t dataErr   = 0; Float_t dataYield = data_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX()-1,dataErr,"");
    Double_t ZToNuNu_1Err   = 0; Float_t ZToNuNu_1Yield = ZToNuNu_1_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_1Err,"");
    Double_t ZToNuNu_2Err   = 0; Float_t ZToNuNu_2Yield = ZToNuNu_2_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_2Err,"");
    Double_t ZToNuNu_3Err   = 0; Float_t ZToNuNu_3Yield = ZToNuNu_3_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_3Err,"");
    Double_t ZToNuNu_4Err   = 0; Float_t ZToNuNu_4Yield = ZToNuNu_4_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_4Err,"");
	Double_t ZToNuNu_5Err   = 0; Float_t ZToNuNu_5Yield = ZToNuNu_5_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_5Err,"");
	Double_t ZToNuNu_6Err   = 0; Float_t ZToNuNu_6Yield = ZToNuNu_6_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_6Err,"");
	Double_t ZToNuNu_7Err   = 0; Float_t ZToNuNu_7Yield = ZToNuNu_7_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_7Err,"");
	Double_t QCD_1Err   = 0; Float_t QCD_1Yield = QCD_1_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_1Err,"");
    Double_t QCD_2Err   = 0; Float_t QCD_2Yield = QCD_2_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_2Err,"");
    Double_t QCD_3Err   = 0; Float_t QCD_3Yield = QCD_3_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_3Err,"");
    Double_t QCD_4Err   = 0; Float_t QCD_4Yield = QCD_4_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_4Err,"");
	Double_t QCD_5Err   = 0; Float_t QCD_5Yield = QCD_5_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_5Err,"");
	Double_t QCD_6Err   = 0; Float_t QCD_6Yield = QCD_6_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_6Err,"");
	Double_t QCD_7Err   = 0; Float_t QCD_7Yield = QCD_7_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_7Err,"");
    Double_t WToLNu_Err = 0; Float_t WToLNu_Yield = WToLNu_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WToLNu_Err,"");
    Double_t TT_Err    = 0; Float_t TT_Yield = TT_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),TT_Err,"");
    Double_t ST_1Err = 0; Float_t ST_1Yield = ST_1_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ST_1Err,"");
	Double_t ST_2Err = 0; Float_t ST_2Yield = ST_2_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ST_2Err,"");
	Double_t ST_3Err = 0; Float_t ST_3Yield = ST_3_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ST_3Err,"");
	Double_t ST_4Err = 0; Float_t ST_4Yield = ST_4_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ST_4Err,"");
    Double_t ZZErr    = 0; Float_t ZZYield  = ZZ_SR ->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZZErr, "");
    Double_t ZWErr    = 0; Float_t ZWYield  = ZW_SR ->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZWErr, "");
    Double_t WWErr    = 0; Float_t WWYield  = WW_SR ->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WWErr, "");
   
    if(i==0){
      cout<<endl;
      //cout<<"Plotting "<<name[i]<<endl;
      cout<<"DATA      = "<<data_SR->Integral()<<" +/- "<<dataErr<<endl;
      cout<<"ZToNuNu   = "<<ZToNuNu_1_SR->Integral()+ZToNuNu_2_SR->Integral()+ZToNuNu_3_SR->Integral()+ZToNuNu_4_SR->Integral()+ZToNuNu_5_SR->Integral()+ZToNuNu_6_SR->Integral()+ZToNuNu_7_SR->Integral()<<" +/- "<<
	sqrt(ZToNuNu_1Err*ZToNuNu_1Err+ZToNuNu_2Err*ZToNuNu_2Err+ZToNuNu_3Err*ZToNuNu_3Err+ZToNuNu_4Err*ZToNuNu_4Err+ZToNuNu_5Err*ZToNuNu_5Err+ZToNuNu_6Err*ZToNuNu_6Err+ZToNuNu_7Err*ZToNuNu_7Err)<<endl;
      cout<<"QCD       = "<<QCD_1_SR->Integral()+QCD_2_SR->Integral()+QCD_3_SR->Integral()+QCD_4_SR->Integral()+QCD_5_SR->Integral()+QCD_6_SR->Integral()+QCD_7_SR->Integral()<<" +/- "<<
	sqrt(QCD_1Err*QCD_1Err+QCD_2Err*QCD_2Err+QCD_3Err*QCD_3Err+QCD_4Err*QCD_4Err+QCD_5Err*QCD_5Err+QCD_6Err*QCD_6Err+QCD_7Err*QCD_7Err)<<endl;
	  cout<<"WToLNu    = "<<WToLNu_SR->Integral()<<" +/- "<<sqrt(WToLNu_Err*WToLNu_Err)<<endl;
      cout<<"TT        = "<<TT_SR->Integral()<<" +/- "<<sqrt(TT_Err+TT_Err)<<endl;
	  cout<<"ST        = "<<ST_1_SR->Integral()+ST_2_SR->Integral()+ST_3_SR->Integral()+ST_4_SR->Integral()<<" +/- "<<sqrt(ST_1Err*ST_1Err+ST_2Err*ST_2Err+ST_3Err*ST_3Err+ST_4Err*ST_4Err)<<endl;
      cout<<"VV        = "<<ZZ_SR->Integral()+ZW_SR->Integral()+WW_SR->Integral()<<" +/- "<<sqrt(ZZErr*ZZErr+ZWErr*ZWErr+WWErr*WWErr)<<endl;
      cout<<"Total BKG = "<<ZToNuNu_1_SR->Integral()+ZToNuNu_2_SR->Integral()+ZToNuNu_3_SR->Integral()+ZToNuNu_4_SR->Integral()+ZToNuNu_5_SR->Integral()+ZToNuNu_6_SR->Integral()+ZToNuNu_7_SR->Integral()+QCD_1_SR->Integral()+QCD_2_SR->Integral()+QCD_3_SR->Integral()+QCD_4_SR->Integral()+QCD_5_SR->Integral()+QCD_6_SR->Integral()+QCD_7_SR->Integral()+WToLNu_SR->Integral()+TT_SR->Integral()+ST_1_SR->Integral()+ST_2_SR->Integral()+ST_3_SR->Integral()+ST_4_SR->Integral()+ZZ_SR->Integral()+ZW_SR->Integral()+WW_SR->Integral()<<" +/- "<<
		  sqrt(ZToNuNu_1Err*ZToNuNu_1Err+ZToNuNu_2Err*ZToNuNu_2Err+ZToNuNu_3Err*ZToNuNu_3Err+ZToNuNu_4Err*ZToNuNu_4Err+ZToNuNu_5Err*ZToNuNu_5Err+ZToNuNu_6Err*ZToNuNu_6Err+ZToNuNu_7Err*ZToNuNu_7Err+QCD_1Err*QCD_1Err+QCD_2Err*QCD_2Err+QCD_3Err*QCD_3Err+QCD_4Err*QCD_4Err+QCD_5Err*QCD_5Err+QCD_6Err*QCD_6Err+QCD_7Err*QCD_7Err+WToLNu_Err*WToLNu_Err+ZZErr*ZZErr+ZWErr*ZWErr+WWErr*WWErr+ST_1Err*ST_1Err+ST_2Err*ST_2Err+ST_3Err*ST_3Err+ST_4Err*ST_4Err+TT_Err*TT_Err)<<endl;
    }

  TCanvas* c1 = new TCanvas("c1","c1",0,0,600,600);

	//////
	//画下面data/MC的比率计算图
	//////
    TPad *c1_1 = new TPad("c1_1","newpad",0.01,0.01,0.99,0.32);
    c1_1->Draw();
    c1_1->cd();
    c1_1->SetTopMargin(0.045);
    c1_1->SetBottomMargin(0.3);
    c1_1->SetRightMargin(0.035);
    c1_1->SetLeftMargin(0.11);
    
    TGraphAsymmErrors *gDATA = new TGraphAsymmErrors(data_SR);	
    gDATA->SetLineWidth(2); 
    gDATA->SetLineColor(1);
    gDATA->SetMarkerColor(1); 
    gDATA->SetMarkerStyle(20); 
    gDATA->SetMarkerSize(1.3);
    for (int i = 0; i < gDATA->GetN(); ++i) {
      double alpha = 1 - 0.6827;
      int M = gDATA->GetY()[i];
      double L =  (M==0) ? 0  : (ROOT::Math::gamma_quantile(alpha/2,M,1.));
      double U =  ROOT::Math::gamma_quantile_c(alpha/2,M+1,1);
      //if(M!=0){
      gDATA->SetPointEYlow(i, M-L);
      gDATA->SetPointEYhigh(i, U-M);
      //}
    }
    TH1F *RATIO2 = (TH1F*)background_SR->Clone();
    Double_t x[bin[i]]; Double_t exl[bin[i]]; Double_t exh[bin[i]];
    Double_t y[bin[i]]; Double_t eyl[bin[i]]; Double_t eyh[bin[i]]; 
    for(int m=0; m<background_SR->GetNbinsX(); m++){ 
      x[m]=Min[i]+m*(Max[i]-Min[i])/bin[i]+(Max[i]-Min[i])/(2*bin[i]);
      exl[m]=(Max[i]-Min[i])/(2*bin[i]);
      exh[m]=(Max[i]-Min[i])/(2*bin[i]);
      RATIO2->SetBinContent(m+1,1);
      if(background_SR->GetBinContent(m+1)!=0) {
	y[m]=data_SR->GetBinContent(m+1)/background_SR->GetBinContent(m+1);
	eyl[m]=sqrt(gDATA->GetErrorYlow(m)*gDATA->GetErrorYlow(m))/background_SR->GetBinContent(m+1);
	eyh[m]=sqrt(gDATA->GetErrorYhigh(m)*gDATA->GetErrorYhigh(m))/background_SR->GetBinContent(m+1);
	RATIO2->SetBinError(m+1,background_SR->GetBinError(m+1)/background_SR->GetBinContent(m+1));
      } else {
	y[m]=-1;
	eyl[m]=0;
	eyh[m]=0;
      }
    }

    TGraphAsymmErrors *RATIO = new TGraphAsymmErrors(bin[i],x,y,exl,exh,eyl,eyh);
    RATIO->Draw("AE0p");
    RATIO->SetMarkerColor(1); 
    RATIO->SetMarkerStyle(21); 
    RATIO->SetMarkerSize(1.0);
    RATIO->SetMaximum(1.7);
    RATIO->SetMinimum(0.3);
    RATIO->SetLineColor(1);
    RATIO->SetLineWidth(2);
    RATIO->GetXaxis()->SetTitleOffset(0.9);
    RATIO->GetYaxis()->SetTitleOffset(0.5);
    RATIO->SetTitle("");
    RATIO->GetYaxis()->SetTitle("observed/expected");
    RATIO->GetXaxis()->SetTitle(axis[i]);
    RATIO->GetXaxis()->SetLabelSize(0.13);
    RATIO->GetYaxis()->SetLabelSize(0.13);
    RATIO->GetXaxis()->SetTitleSize(0.15);
    RATIO->GetYaxis()->SetTitleSize(0.09);
    RATIO->GetYaxis()->SetNdivisions(505);
    RATIO->GetXaxis()->SetRangeUser(Min[i],Max[i]);
    RATIO2->SetFillStyle(3002);
    RATIO2->SetFillColor(12);
    RATIO2->SetLineColor(12);
    RATIO2->SetMarkerSize(0);
    RATIO2->Draw("E2same");
    RATIO->Draw("E0psame");

    TLine* line = new TLine(Min[i],1,Max[i],1);
    line->SetLineColor(2);
    line->SetLineWidth(2);
    line->Draw("same");	
    c1->cd();
    
	/////
	//画上面的data/MC图
	/////
    TPad *c1_2 = new TPad("c1_2", "newpad",0.01,0.32,0.99,1.0);
    c1_2->Draw();
    c1_2->cd();
    c1_2->SetTopMargin(0.08);
    c1_2->SetBottomMargin(0.02);
    c1_2->SetRightMargin(0.035);
    c1_2->SetLeftMargin(0.11);
    
    THStack *hs = new THStack("hs","hs");
    hs->Add(ST_1_SR);
    hs->Add(ST_2_SR);
    hs->Add(ST_3_SR);
	hs->Add(ST_4_SR);
    hs->Add(TT_SR);
    hs->Add(WToLNu_SR);
    hs->Add(ZZ_SR);
    hs->Add(ZW_SR);
    hs->Add(WW_SR);
	hs->Add(QCD_1_SR);
    hs->Add(QCD_2_SR);
    hs->Add(QCD_3_SR);
    hs->Add(QCD_4_SR);
	hs->Add(QCD_5_SR);
	hs->Add(QCD_6_SR);
	hs->Add(QCD_7_SR);
    hs->Add(ZToNuNu_1_SR);
    hs->Add(ZToNuNu_2_SR);
    hs->Add(ZToNuNu_3_SR);
    hs->Add(ZToNuNu_4_SR);
	hs->Add(ZToNuNu_5_SR);
	hs->Add(ZToNuNu_6_SR);
	hs->Add(ZToNuNu_7_SR);
    
    hs->Draw("histo");
    hs->SetMinimum(0);
    hs->GetYaxis()->SetTitleSize(0.070);
    hs->GetXaxis()->SetTitleSize(0.070);
    hs->GetYaxis()->SetLabelSize(0.070);
    hs->GetXaxis()->SetLabelSize(0.0); 
    hs->SetTitle("");
    hs->GetYaxis()->SetTitle("Events");
    hs->GetXaxis()->SetTitle("");
    hs->GetYaxis()->SetTitleOffset(0.80);
    hs->GetXaxis()->SetTitleOffset(0.85);
    tptzm1000lh_SR->Draw("samehisto");
    tptzm1700lh_SR->Draw("samehisto");
    data_SR->Draw("E same"); 
    
    background_SR->SetFillStyle(3005);
    background_SR->SetFillColor(12);
    background_SR->SetLineColor(12);
    background_SR->Draw("E2same");
    
    float maxy=-10;
    float ADD=20;
    for(int ABC=0; ABC<data_SR->GetNbinsX(); ABC++){
      if(background_SR->GetBinContent(ABC+1)+ADD>=maxy) maxy=background_SR->GetBinContent(ABC+1)+ADD;
      if(data_SR      ->GetBinContent(ABC+1)+ADD>=maxy) maxy=data_SR      ->GetBinContent(ABC+1)+ADD;
    }
    hs->SetMaximum(maxy);
    hs->SetMaximum(1000000);
    hs->SetMinimum(3);
    c1_2->SetLogy();

	/////
	//画图上各种说明文字
	/////
    TPad *pad = new TPad("pad","pad",0.01,0.01,0.99,0.99);
    gPad->RedrawAxis();
    TString channelText = "";
    float channelTextFont   = 42;
    float channelTextSize   = 0.06;
    TString cmsText     = "CMS";
    float cmsTextFont   = 61;  // default is helvetic-bold
    bool writeExtraText = true;
    TString extraText   = "Preliminary";
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
	TString lumi_13TeV;
	lumi_13TeV = "41.1fb^{-1}";
    TString lumiText;
    lumiText += lumi_13TeV;
    lumiText += " (2017, 13 TeV)";
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
    latex.DrawLatex(1-r+0.06,0.94,lumiText);
    latex.SetTextFont(cmsTextFont);
    latex.SetTextAlign(11); 
    latex.SetTextSize(cmsTextSize*t);    
    latex.DrawLatex(l+0.01, 0.94,cmsText);
    latex.SetTextFont(extraTextFont);
    latex.SetTextSize(extraTextSize*t);
    latex.DrawLatex(l+0.12, 0.94, extraText); 
    latex.SetTextFont(channelTextFont);
    latex.SetTextSize(channelTextSize);


    //定义图中各个线和直方图的颜色
    TLegend *pl2 = new TLegend(0.55,0.60,0.95,0.91);
    pl2->SetTextSize(0.045); 
    pl2->SetFillColor(0);
    TLegendEntry *ple2 = pl2->AddEntry(data_SR, "data",  "L"); 
    ple2 = pl2->AddEntry(ZToNuNu_1_SR, "Z to NuNu",  "F");
    ple2 = pl2->AddEntry(QCD_1_SR, "QCD",  "F");
	ple2 = pl2->AddEntry(WToLNu_SR, "W to LNu",  "F");
    ple2 = pl2->AddEntry(ZZ_SR, "VV (V = Z or W)",  "F");
    ple2 = pl2->AddEntry(ST_1_SR, "t#bar{t} and single-top",  "F");
    ple2 = pl2->AddEntry(tptzm1000lh_SR, "T, M=1.0TeV, #sigma#times100",  "L"); 
    ple2 = pl2->AddEntry(tptzm1700lh_SR, "T, M=1.7TeV, #sigma#times100",  "L"); 
    pl2->Draw();
    
    TString NAME = name[i];
    cout<<"Finished "<<NAME<<endl;
    c1->SaveAs(NAME+".png");
    c1->Draw(); 

  }

}

 void GetHisto(char CUT[1000], TTree *Tree, TH1F* & histo, const char *plot, int BIN, float MIN, float MAX){
  char input[50]; sprintf(input,"%s>>h(%i,%f,%f)",plot,BIN,MIN,MAX);
  TH1F *temp = new TH1F("", "", BIN,MIN,MAX);
  if(Tree->Draw(input,CUT)){ Tree->Draw(input,CUT); TH1F* h=(TH1F*)gDirectory->Get("h"); histo = (TH1F*)h->Clone(); delete h; } else { histo = (TH1F*)temp->Clone(); }
  histo->SetDirectory(0);
  histo->SetName("histo");
  delete temp;
 }

void MakeHistos(char CUT[1000],const char *plot,int BIN,float MIN,float MAX,int JETSyst,
		TH1F* &data_func,TH1F* &background_func,TH1F* &ZToNuNu_1_func,TH1F* &ZToNuNu_2_func,TH1F* &ZToNuNu_3_func,TH1F* &ZToNuNu_4_func,TH1F* &ZToNuNu_5_func,TH1F* &ZToNuNu_6_func,TH1F* &ZToNuNu_7_func,TH1F* &QCD_1_func,TH1F* &QCD_2_func,
		TH1F* &QCD_3_func,TH1F* &QCD_4_func,TH1F* &QCD_5_func,TH1F* &QCD_6_func,TH1F* &QCD_7_func,TH1F* &WToLNu_func,TH1F* &TT_func,TH1F* &ST_1_func,TH1F* &ST_2_func,TH1F* &ST_3_func,
		TH1F* &ST_4_func,TH1F* &ZZ_func,TH1F* &ZW_func,TH1F* &WW_func,TH1F* &tptzm0700lh_func,TH1F* &tptzm1000lh_func,TH1F* &tptzm1400lh_func,TH1F* &tptzm1700lh_func){
  TH1F *data; TH1F *tptzm0700lh; TH1F *tptzm1000lh; TH1F *tptzm1400lh; TH1F *tptzm1700lh; 
  TH1F *ZToNuNu_1; TH1F *ZToNuNu_2; TH1F *ZToNuNu_3; TH1F *ZToNuNu_4; TH1F *ZToNuNu_5; TH1F *ZToNuNu_6; TH1F *ZToNuNu_7; TH1F *QCD_1; TH1F *QCD_2; TH1F *QCD_3; TH1F *QCD_4; TH1F *QCD_5; TH1F *QCD_6; TH1F *QCD_7; TH1F *WToLNu; TH1F *TT; TH1F *ST_1; TH1F *ST_2; TH1F *ST_3; TH1F *ST_4; TH1F *ZZ; TH1F *ZW; TH1F *WW;
  if(JETSyst==0){
    GetHisto(CUT, Tree01, data        ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree02, tptzm0700lh ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree05, tptzm1000lh ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree09, tptzm1400lh ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree12, tptzm1700lh ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree14, ZToNuNu_1   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree15, ZToNuNu_2   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree16, ZToNuNu_3   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree17, ZToNuNu_4   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree18, ZToNuNu_5   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree19, ZToNuNu_6   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree20, ZToNuNu_7   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree21, QCD_1      ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree22, QCD_2      ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree23, QCD_3      ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree24, QCD_4      ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree25, QCD_5      ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree26, QCD_6      ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree27, QCD_7      ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree28, WToLNu      ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree29, TT    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree30, ST_1    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree31, ST_2    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree32, ST_3    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree33, ST_4    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree34, ZZ    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree35, ZW    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree36, WW    ,plot,BIN,MIN,MAX);
  } 
  
  TH1F *background = new TH1F("","",data->GetNbinsX(),data->GetXaxis()->GetXmin(),data->GetXaxis()->GetXmax());
  for(int j=1; j<data->GetNbinsX()+1; j++){
    if(tptzm0700lh->GetBinContent(j)>0){tptzm0700lh->SetBinError(j,sqrt(w0700*w0700*tptzm0700lh->GetBinContent(j)));}else{tptzm0700lh->SetBinError(j,0);}
    if(tptzm1000lh->GetBinContent(j)>0){tptzm1000lh->SetBinError(j,sqrt(w1000*w1000*tptzm1000lh->GetBinContent(j)));}else{tptzm1000lh->SetBinError(j,0);}
    if(tptzm1400lh->GetBinContent(j)>0){tptzm1400lh->SetBinError(j,sqrt(w1400*w1400*tptzm1400lh->GetBinContent(j)));}else{tptzm1400lh->SetBinError(j,0);}
    if(tptzm1700lh->GetBinContent(j)>0){tptzm1700lh->SetBinError(j,sqrt(w1700*w1700*tptzm1700lh->GetBinContent(j)));}else{tptzm1700lh->SetBinError(j,0);}
    if(ZToNuNu_1 ->GetBinContent(j)>0){ZToNuNu_1 ->SetBinError(j,sqrt(w01*w01*ZToNuNu_1 ->GetBinContent(j)));}else{ZToNuNu_1 ->SetBinError(j,0);}//w01);}
    if(ZToNuNu_2 ->GetBinContent(j)>0){ZToNuNu_2 ->SetBinError(j,sqrt(w02*w02*ZToNuNu_2 ->GetBinContent(j)));}else{ZToNuNu_2 ->SetBinError(j,0);}//w02);}
    if(ZToNuNu_3 ->GetBinContent(j)>0){ZToNuNu_3 ->SetBinError(j,sqrt(w03*w03*ZToNuNu_3 ->GetBinContent(j)));}else{ZToNuNu_3 ->SetBinError(j,0);}//w03);}
    if(ZToNuNu_4 ->GetBinContent(j)>0){ZToNuNu_4 ->SetBinError(j,sqrt(w04*w04*ZToNuNu_4 ->GetBinContent(j)));}else{ZToNuNu_4 ->SetBinError(j,0);}//w04);}
	if(ZToNuNu_5 ->GetBinContent(j)>0){ZToNuNu_5 ->SetBinError(j,sqrt(w05*w05*ZToNuNu_5 ->GetBinContent(j)));}else{ZToNuNu_5 ->SetBinError(j,0);}//w05);}
	if(ZToNuNu_6 ->GetBinContent(j)>0){ZToNuNu_6 ->SetBinError(j,sqrt(w06*w06*ZToNuNu_6 ->GetBinContent(j)));}else{ZToNuNu_6 ->SetBinError(j,0);}//w06);}
	if(ZToNuNu_7 ->GetBinContent(j)>0){ZToNuNu_7 ->SetBinError(j,sqrt(w07*w07*ZToNuNu_7 ->GetBinContent(j)));}else{ZToNuNu_7 ->SetBinError(j,0);}//w07);}
    if(QCD_1->GetBinContent(j)>0){QCD_1 ->SetBinError(j,sqrt(w08*w08*QCD_1 ->GetBinContent(j)));}else{QCD_1 ->SetBinError(j,0);}//w08);}
    if(QCD_2->GetBinContent(j)>0){QCD_2 ->SetBinError(j,sqrt(w09*w09*QCD_2 ->GetBinContent(j)));}else{QCD_2 ->SetBinError(j,0);}//w09);}
    if(QCD_3->GetBinContent(j)>0){QCD_3 ->SetBinError(j,sqrt(w10*w10*QCD_3 ->GetBinContent(j)));}else{QCD_3 ->SetBinError(j,0);}//w10);}
	if(QCD_4->GetBinContent(j)>0){QCD_4 ->SetBinError(j,sqrt(w11*w11*QCD_4 ->GetBinContent(j)));}else{QCD_4 ->SetBinError(j,0);}//w11);}
    if(QCD_5->GetBinContent(j)>0){QCD_5 ->SetBinError(j,sqrt(w12*w12*QCD_5 ->GetBinContent(j)));}else{QCD_5 ->SetBinError(j,0);}//w12);}
    if(QCD_6->GetBinContent(j)>0){QCD_6 ->SetBinError(j,sqrt(w13*w13*QCD_6 ->GetBinContent(j)));}else{QCD_6 ->SetBinError(j,0);}//w13);}
    if(QCD_7->GetBinContent(j)>0){QCD_7 ->SetBinError(j,sqrt(w14*w14*QCD_7 ->GetBinContent(j)));}else{QCD_7 ->SetBinError(j,0);}//w14);}
    if(WToLNu->GetBinContent(j)>0){WToLNu->SetBinError(j,sqrt(w15*w15*WToLNu->GetBinContent(j)));}else{WToLNu->SetBinError(j,0);}//w15);}
	if(TT->GetBinContent(j)>0){TT->SetBinError(j,sqrt(w16*w16*TT->GetBinContent(j)));}else{TT->SetBinError(j,0);}//w16);}
    if(ST_1->GetBinContent(j)>0){ST_1->SetBinError(j,sqrt(w17*w17*ST_1->GetBinContent(j)));}else{ST_1->SetBinError(j,0);}//w17);}
    if(ST_2->GetBinContent(j)>0){ST_2->SetBinError(j,sqrt(w18*w18*ST_2->GetBinContent(j)));}else{ST_2->SetBinError(j,0);}//w18);}
    if(ST_3->GetBinContent(j)>0){ST_3->SetBinError(j,sqrt(w19*w19*ST_3->GetBinContent(j)));}else{ST_3->SetBinError(j,0);}//w19);}
    if(ST_4->GetBinContent(j)>0){ST_4->SetBinError(j,sqrt(w20*w20*ST_4->GetBinContent(j)));}else{ST_4->SetBinError(j,0);}//w20);}
    if(ZZ->GetBinContent(j)>0){ZZ->SetBinError(j,sqrt(w21*w21*ZZ->GetBinContent(j)));}else{ZZ->SetBinError(j,0);}//w21);}
    if(ZW->GetBinContent(j)>0){ZW->SetBinError(j,sqrt(w22*w22*ZW->GetBinContent(j)));}else{ZW->SetBinError(j,0);}//w22);}
    if(WW->GetBinContent(j)>0){WW->SetBinError(j,sqrt(w23*w23*WW->GetBinContent(j)));}else{WW->SetBinError(j,0);}//w23);}
    float err00 = data->GetBinError(j)*data->GetBinError(j);
    float err01 = ZToNuNu_1->GetBinError(j)*ZToNuNu_1->GetBinError(j) + ZToNuNu_2->GetBinError(j)*ZToNuNu_2->GetBinError(j) + ZToNuNu_3->GetBinError(j)*ZToNuNu_3->GetBinError(j) + ZToNuNu_4->GetBinError(j)*ZToNuNu_4->GetBinError(j) + ZToNuNu_5->GetBinError(j)*ZToNuNu_5->GetBinError(j) + ZToNuNu_6->GetBinError(j)*ZToNuNu_6->GetBinError(j) + ZToNuNu_7->GetBinError(j)*ZToNuNu_7->GetBinError(j);
    float err02 = QCD_1->GetBinError(j)*QCD_1->GetBinError(j) + QCD_2->GetBinError(j)*QCD_2->GetBinError(j) + QCD_3->GetBinError(j)*QCD_3->GetBinError(j) + QCD_4->GetBinError(j)*QCD_4->GetBinError(j) + QCD_5->GetBinError(j)*QCD_5->GetBinError(j) + QCD_6->GetBinError(j)*QCD_6->GetBinError(j) + QCD_7->GetBinError(j)*QCD_7->GetBinError(j);
    float err03 = WToLNu->GetBinError(j)*WToLNu->GetBinError(j);
	float err04 = TT->GetBinError(j)*TT->GetBinError(j);
	float err05 = ST_1->GetBinError(j)*ST_1->GetBinError(j) + ST_2->GetBinError(j)*ST_2->GetBinError(j)+ ST_3->GetBinError(j)*ST_3->GetBinError(j)+ ST_4->GetBinError(j)*ST_4->GetBinError(j);
    float err06 = ZZ->GetBinError(j)*ZZ->GetBinError(j) + ZW->GetBinError(j)*ZW->GetBinError(j) + WW->GetBinError(j)*WW->GetBinError(j); 
    background->SetBinError(j,sqrt(err01+err02+err03+err04+err05+err06));
    tptzm0700lh->SetBinContent(j,w0700*tptzm0700lh->GetBinContent(j));
    tptzm1000lh->SetBinContent(j,w1000*tptzm1000lh->GetBinContent(j));
    tptzm1400lh->SetBinContent(j,w1400*tptzm1400lh->GetBinContent(j));
    tptzm1700lh->SetBinContent(j,w1700*tptzm1700lh->GetBinContent(j));
    ZToNuNu_1->SetBinContent(j,w01*ZToNuNu_1->GetBinContent(j));
    ZToNuNu_2->SetBinContent(j,w02*ZToNuNu_2->GetBinContent(j));
    ZToNuNu_3->SetBinContent(j,w03*ZToNuNu_3->GetBinContent(j));
    ZToNuNu_4->SetBinContent(j,w04*ZToNuNu_4->GetBinContent(j));
	ZToNuNu_5->SetBinContent(j,w05*ZToNuNu_5->GetBinContent(j));
	ZToNuNu_6->SetBinContent(j,w06*ZToNuNu_6->GetBinContent(j));
	ZToNuNu_7->SetBinContent(j,w07*ZToNuNu_7->GetBinContent(j));
    QCD_1->SetBinContent(j,w08*QCD_1->GetBinContent(j));
    QCD_2->SetBinContent(j,w09*QCD_2->GetBinContent(j));
    QCD_3->SetBinContent(j,w10*QCD_3->GetBinContent(j));
	QCD_4->SetBinContent(j,w11*QCD_4->GetBinContent(j));
    QCD_5->SetBinContent(j,w12*QCD_5->GetBinContent(j));
    QCD_6->SetBinContent(j,w13*QCD_6->GetBinContent(j));
    QCD_7->SetBinContent(j,w14*QCD_7->GetBinContent(j));
    WToLNu->SetBinContent(j,w15*WToLNu->GetBinContent(j));
    TT->SetBinContent(j,w16*TT->GetBinContent(j));
    ST_1->SetBinContent(j,w17*ST_1->GetBinContent(j));
    ST_2->SetBinContent(j,w18*ST_2->GetBinContent(j));
    ST_3->SetBinContent(j,w19*ST_3->GetBinContent(j));
    ST_4->SetBinContent(j,w20*ST_4->GetBinContent(j));
    ZZ->SetBinContent(j,w21*ZZ->GetBinContent(j));
    ZW->SetBinContent(j,w22*ZW->GetBinContent(j));
	WW->SetBinContent(j,w23*WW->GetBinContent(j));
    float DATA = data->GetBinContent(j);
    float bkg0 = ZToNuNu_1->GetBinContent(j) + ZToNuNu_2->GetBinContent(j) + ZToNuNu_3->GetBinContent(j) + ZToNuNu_4->GetBinContent(j) + ZToNuNu_5->GetBinContent(j) + ZToNuNu_6->GetBinContent(j) + ZToNuNu_7->GetBinContent(j);
    float bkg1 = QCD_1->GetBinContent(j) + QCD_2->GetBinContent(j) + QCD_3->GetBinContent(j) + QCD_4->GetBinContent(j) + QCD_5->GetBinContent(j) + QCD_6->GetBinContent(j) + QCD_7->GetBinContent(j);
    float bkg2 = WToLNu->GetBinContent(j);
	float bkg3 = TT->GetBinContent(j);
    float bkg4 = ST_1 ->GetBinContent(j) + ST_2 ->GetBinContent(j) + ST_3 ->GetBinContent(j) + ST_4 ->GetBinContent(j);
	float bkg5 = ZZ ->GetBinContent(j) + ZW ->GetBinContent(j) + WW ->GetBinContent(j);
    background->SetBinContent(j,bkg0+bkg1+bkg2+bkg3+bkg4+bkg5);
  }

  background_func  = (TH1F*)background ->Clone(); 
  data_func        = (TH1F*)data       ->Clone(); 
  tptzm0700lh_func = (TH1F*)tptzm0700lh->Clone(); 
  tptzm1000lh_func = (TH1F*)tptzm1000lh->Clone(); 
  tptzm1400lh_func = (TH1F*)tptzm1400lh->Clone(); 
  tptzm1700lh_func = (TH1F*)tptzm1700lh->Clone(); 
  ZToNuNu_1_func   = (TH1F*)ZToNuNu_1->Clone(); 
  ZToNuNu_2_func   = (TH1F*)ZToNuNu_2->Clone(); 
  ZToNuNu_3_func   = (TH1F*)ZToNuNu_3->Clone();  
  ZToNuNu_4_func   = (TH1F*)ZToNuNu_4->Clone(); 
  ZToNuNu_5_func   = (TH1F*)ZToNuNu_5->Clone();
  ZToNuNu_6_func   = (TH1F*)ZToNuNu_6->Clone();
  ZToNuNu_7_func   = (TH1F*)ZToNuNu_7->Clone();
  QCD_1_func = (TH1F*)QCD_1->Clone();    
  QCD_2_func = (TH1F*)QCD_2->Clone();
  QCD_3_func = (TH1F*)QCD_3->Clone(); 
  QCD_4_func = (TH1F*)QCD_4->Clone();
  QCD_5_func = (TH1F*)QCD_5->Clone();  
  QCD_6_func = (TH1F*)QCD_6->Clone(); 
  QCD_7_func = (TH1F*)QCD_7->Clone();
  WToLNu_func = (TH1F*)WToLNu->Clone();    
  TT_func   = (TH1F*)TT->Clone();    
  ST_1_func = (TH1F*)ST_1->Clone();    
  ST_2_func = (TH1F*)ST_2->Clone();    
  ST_3_func = (TH1F*)ST_3->Clone();    
  ST_4_func = (TH1F*)ST_4->Clone();    
  ZZ_func   = (TH1F*)ZZ  ->Clone();    
  ZW_func   = (TH1F*)ZW  ->Clone();    
  WW_func   = (TH1F*)WW  ->Clone(); 
  delete data; delete background; delete ZToNuNu_1; delete ZToNuNu_2; delete ZToNuNu_3; delete ZToNuNu_4;  delete ZToNuNu_5;  delete ZToNuNu_6;  delete ZToNuNu_7;  delete QCD_1; delete QCD_2; delete QCD_3; delete QCD_4; delete QCD_5; delete QCD_6; delete QCD_7; delete WToLNu; delete TT; delete ST_1; delete ST_2;  delete ST_3; delete ST_4; delete ZZ; delete ZW; delete WW;
}
