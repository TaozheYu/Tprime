#include "BackgroundEstimation_dineutrino.h"

void BackgroundEstimation_dineutrino(){ 
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

  vector<TString> name;                vector<int> bin;      vector<double> Min;      vector<double> Max;     vector<TString> axis;

  ///name.push_back("Jet1ResolvedPt"); bin.push_back(18);     Min.push_back(0);    Max.push_back(900);    axis.push_back("jet1(resolved) pt [GeV]");
  /*name.push_back("Jet2ResolvedPt"); bin.push_back(18);     Min.push_back(0);    Max.push_back(900);    axis.push_back("jet2(resolved) pt [GeV]");
  name.push_back("Jet3ResolvedPt"); bin.push_back(18);     Min.push_back(0);    Max.push_back(900);    axis.push_back("jet3(resolved) pt [GeV]");

  name.push_back("Jet1ResolvedEta"); bin.push_back(10);     Min.push_back(-2.5);    Max.push_back(2.5);    axis.push_back("jet1(resolved) #eta");
  name.push_back("Jet2ResolvedEta"); bin.push_back(10);     Min.push_back(-2.5);    Max.push_back(2.5);    axis.push_back("jet2(resolved) #eta");
  name.push_back("Jet3ResolvedEta"); bin.push_back(10);     Min.push_back(-2.5);    Max.push_back(2.5);    axis.push_back("jet3(resolved) #eta");*/
 
  //name.push_back("Jet1PartialPt"); bin.push_back(40);     Min.push_back(0);    Max.push_back(500);    axis.push_back("W-jet(partial) pt[GeV]");
  //name.push_back("Jet2PartialPt"); bin.push_back(40);     Min.push_back(0);    Max.push_back(500);    axis.push_back("jet(partial) pt[GeV]");
  
  
  //name.push_back("Jet1PartialEta"); bin.push_back(40);     Min.push_back(-2.5);    Max.push_back(2.5);    axis.push_back("W-jet(resolved) #eta");
  //name.push_back("Jet2PartialEta"); bin.push_back(40);     Min.push_back(-2.5);    Max.push_back(2.5);    axis.push_back("jet(resolved) #eta");

  //name.push_back("Jet1MergedPt"); bin.push_back(40);     Min.push_back(0);    Max.push_back(1000);    axis.push_back("top-jet(partial) pt[GeV]");
  //name.push_back("Jet1MergedEta"); bin.push_back(40);     Min.push_back(-2.5);    Max.push_back(2.5);    axis.push_back("top-jet(resolved) #eta");

  //name.push_back("TopMass"); bin.push_back(10);     Min.push_back(0);    Max.push_back(500);    axis.push_back("Top Mass[GeV]");
  //name.push_back("TopPt");   bin.push_back(16);     Min.push_back(200);    Max.push_back(1000);   axis.push_back("Top pt[GeV] ");
  //name.push_back("TopEta");  bin.push_back(12);     Min.push_back(-3);   Max.push_back(3);      axis.push_back("Top #eta");
 
  //name.push_back("Met_pt");  bin.push_back(16);     Min.push_back(0);    Max.push_back(1000);   axis.push_back("Met pt[GeV] ");
  //name.push_back("Met_phi"); bin.push_back(12);     Min.push_back(-3);   Max.push_back(3);      axis.push_back("Met #phi");
  name.push_back("HT"); bin.push_back(10);     Min.push_back(200);    Max.push_back(1200);    axis.push_back("HT pt[GeV]");

  //name.push_back("deltaPhiMetTop"); bin.push_back(9);     Min.push_back(0);    Max.push_back(3);    axis.push_back("#Delta#phi(Met,top)");
 // name.push_back("MinDeltaPhiJetMet"); bin.push_back(9);     Min.push_back(0);    Max.push_back(3);    axis.push_back("Min#Delta#phi(Met,Jet)");

  //name.push_back("NVertices"); bin.push_back(80);     Min.push_back(0);    Max.push_back(80);    axis.push_back("Number of vertices");

  //name.push_back("NumSelBJetsM"); bin.push_back(6);     Min.push_back(0);    Max.push_back(6);    axis.push_back("Number of medium B jets");
  //name.push_back("NumSelBJetsL"); bin.push_back(8);     Min.push_back(0);    Max.push_back(8);    axis.push_back("Number of loose B jets");

  //name.push_back("TopPhiResolved"); bin.push_back(40);     Min.push_back(-4);    Max.push_back(4);    axis.push_back("top #phi");
  //name.push_back("TopPhiResolved-Met_phi"); bin.push_back(40);     Min.push_back(-8);    Max.push_back(8);    axis.push_back("#Delta#phi(Met,top)");

  //name.push_back("TransverseMassMetTop"); bin.push_back(15);     Min.push_back(500);    Max.push_back(2000);    axis.push_back("TransverseMassMetTop");

  
  for(int i=0; i<name.size(); i++){
    const char *plot = name[i];
    char CUT[1000]; char CUTmuo1[1000]; char CUTmuo2[1000]; char CUTele1[1000]; char CUTele2[1000]; char CUTtri1[1000]; char CUTtri2[1000]; char CUTtri3[1000]; char CUTtri4[1000]; char CUTpup1[1000]; char CUTpup2[1000]; char CUTbta1[1000]; char CUTbta2[1000]; char CUTtop1[1000]; char CUTtop2[1000]; char CUTfor1[1000]; char CUTfor2[1000]; char CUTwje1[1000]; char CUTwje2[1000];
	char CUTCS1[1000];   char CS1[1000];
	char CUTCS2[1000];   char CS2[1000];
	char CUTCS3[1000];   char CS3[1000];
	char CUTPre[1000];   char Pre[1000];
	 
	sprintf(CUT,    "((category0==1)&&(Jet1ResolvedPt>0)&&(Jet2ResolvedPt>0)&&(Jet3ResolvedPt>0)&&(MinDeltaPhiJetMet>0.6)&&(TopPt>200)&&(TransverseMassMetTop>500)");

	sprintf(Pre,    "(category0==1))"); 
	sprintf(CS1,    "(NumSelBJetsM==0)&&(NumSelLeps==0)&&(TopPt>340))");    //Z->nunu: signal selection but NumSelBJetsM==0 instead of NumSelBJetsM>1
	sprintf(CS2,    "(NumSelBJetsM==0)&&(NumSelLeps==1)&&(TopPt>340))");   //Wjets:     signal selection but NumSelBJetsM==0 and NumSelLeps==1
	sprintf(CS3,    "(NumSelBJetsM>0)&&(NumSelLeps==0)&&(TopPt<340))");   //ttbar:       signal selection with NumSelBJetsM>1 but TopPt<340
	//sprintf(CS3,    "(NumSelBJetsM>0)&&(NumSelLeps==0)&&(TopPt>340))");   //ttbar:       signal selection with NumSelBJetsM>1 but TopPt<340


	sprintf(CUTPre,    "PUWeight   *w_for  *w_Btag  *w_topJet  *w_WJet  *genWeight*%s&&%s",CUT,Pre );
	sprintf(CUTCS1,    "PUWeight   *w_for  *w_Btag  *w_topJet  *w_WJet  *genWeight*%s&&%s",CUT,CS1);
	sprintf(CUTCS2,    "PUWeight   *w_for  *w_Btag  *w_topJet  *w_WJet  *genWeight*%s&&%s",CUT,CS2);
	sprintf(CUTCS3,    "PUWeight   *w_for  *w_Btag  *w_topJet  *w_WJet  *genWeight*%s&&%s",CUT,CS3);

  
	MakeHistos(CUTPre, CUTCS1,CUTCS2,CUTCS3,plot,bin[i],Min[i],Max[i],0,
		       data_SR,background_SR,background_PRE, 
			   ZToNuNu_PRE,ZToNuNu_1_SR,ZToNuNu_2_SR,ZToNuNu_3_SR,ZToNuNu_4_SR,ZToNuNu_5_SR,ZToNuNu_6_SR,ZToNuNu_7_SR,
		       QCD_SR,QCD_1_SR,QCD_2_SR,QCD_3_SR,QCD_4_SR,QCD_5_SR,QCD_6_SR,QCD_7_SR,
			   WToLNu_PRE,WToLNu_1_SR,WToLNu_2_SR,WToLNu_3_SR,WToLNu_4_SR,WToLNu_5_SR,WToLNu_6_SR,WToLNu_7_SR,
			   TT_PRE, TT_1_SR,TT_2_SR,
			   ST_SR, ST_1_SR,ST_2_SR,ST_3_SR,ST_4_SR,
			   VV_SR, ZZ1_SR,ZZ2_SR,ZZ3_SR,WW1_SR,WW2_SR,WZ1_SR,WZ2_SR,WZ3_SR,
			   tptzm0700lh_SR,tptzm0900lh_SR,tptzm1400lh_SR,tptzm1700lh_SR,
			   SF1_h,SF2_h,SF3_h);

    TCanvas* canvasSF1 = new TCanvas("canvasSF1","canvasSF1",0,0,600,900);
	SF1_h->SetLineWidth(2); 
    SF1_h->SetLineColor(kGreen+3);
    SF1_h->SetMarkerColor(kGreen+3); 
    SF1_h->SetMarkerStyle(20); 
    SF1_h->SetMarkerSize(1.3);
    SF1_h->GetYaxis()->SetTitleSize(0.045);
    SF1_h->GetXaxis()->SetTitleSize(0.045);
    SF1_h->GetYaxis()->SetLabelSize(0.045);
    SF1_h->GetXaxis()->SetLabelSize(0.045); 
    SF1_h->SetMinimum(0);
    SF1_h->SetMaximum(2.0);
    SF1_h->SetTitle("");
    SF1_h->GetYaxis()->SetTitle("SF1");
    SF1_h->GetXaxis()->SetTitle("HT [GeV]"); 
	SF1_h->Draw("E");
	canvasSF1->Draw();
	canvasSF1->SaveAs("SF1.png");

	TCanvas* canvasSF2 = new TCanvas("canvasSF2","canvasSF2",0,0,600,900); 
	SF2_h->SetLineWidth(2); 
    SF2_h->SetLineColor(kGreen+3);
    SF2_h->SetMarkerColor(kGreen+3); 
    SF2_h->SetMarkerStyle(20); 
    SF2_h->SetMarkerSize(1.3);
    SF2_h->GetYaxis()->SetTitleSize(0.045);
    SF2_h->GetXaxis()->SetTitleSize(0.045);
    SF2_h->GetYaxis()->SetLabelSize(0.045);
    SF2_h->GetXaxis()->SetLabelSize(0.045); 
    SF2_h->SetMinimum(0);
    SF2_h->SetMaximum(2.0);
    SF2_h->SetTitle("");
    SF2_h->GetYaxis()->SetTitle("SF2");
    SF2_h->GetXaxis()->SetTitle("HT [GeV]"); 
	SF2_h->Draw("E");
	canvasSF2->Draw();
	canvasSF2->SaveAs("SF2.png");
	
	TCanvas* canvasSF3 = new TCanvas("canvasSF3","canvasSF3",0,0,600,900); 
	SF3_h->SetLineWidth(2); 
    SF3_h->SetLineColor(kGreen+3);
    SF3_h->SetMarkerColor(kGreen+3); 
    SF3_h->SetMarkerStyle(20); 
    SF3_h->SetMarkerSize(1.3);
    SF3_h->GetYaxis()->SetTitleSize(0.045);
    SF3_h->GetXaxis()->SetTitleSize(0.045);
    SF3_h->GetYaxis()->SetLabelSize(0.045);
    SF3_h->GetXaxis()->SetLabelSize(0.045); 
    SF3_h->SetMinimum(0);
    SF3_h->SetMaximum(2.0);
    SF3_h->SetTitle("");
    SF3_h->GetYaxis()->SetTitle("SF3");
    SF3_h->GetXaxis()->SetTitle("HT [GeV]"); 
	SF3_h->Draw("E");
	canvasSF3->Draw();
	canvasSF3->SaveAs("SF3.png");

	tptzm0700lh_SR->SetLineWidth(2); tptzm0900lh_SR->SetLineWidth(2); tptzm1400lh_SR->SetLineWidth(2); tptzm1700lh_SR->SetLineWidth(2); 
	
	ZToNuNu_PRE->SetLineWidth(2); ZToNuNu_1_SR->SetLineWidth(2); ZToNuNu_2_SR->SetLineWidth(2);ZToNuNu_3_SR->SetLineWidth(2); ZToNuNu_4_SR->SetLineWidth(2); ZToNuNu_5_SR->SetLineWidth(2); ZToNuNu_6_SR->SetLineWidth(2); ZToNuNu_7_SR->SetLineWidth(2);
	QCD_SR->SetLineWidth(2);QCD_1_SR->SetLineWidth(2); QCD_2_SR->SetLineWidth(2);QCD_3_SR->SetLineWidth(2); QCD_4_SR->SetLineWidth(2); QCD_5_SR->SetLineWidth(2); QCD_6_SR->SetLineWidth(2); QCD_7_SR->SetLineWidth(2);
	WToLNu_PRE->SetLineWidth(2); WToLNu_1_SR->SetLineWidth(2); WToLNu_2_SR->SetLineWidth(2); WToLNu_3_SR->SetLineWidth(2); WToLNu_4_SR->SetLineWidth(2); WToLNu_5_SR->SetLineWidth(2); WToLNu_6_SR->SetLineWidth(2); WToLNu_7_SR->SetLineWidth(2);
	TT_PRE->SetLineWidth(2); TT_1_SR->SetLineWidth(2); TT_2_SR->SetLineWidth(2);
	ST_SR->SetLineWidth(2); ST_1_SR->SetLineWidth(2); ST_2_SR->SetLineWidth(2); ST_3_SR->SetLineWidth(2); ST_4_SR->SetLineWidth(2); 
	VV_SR->SetLineWidth(2); ZZ1_SR->SetLineWidth(2); ZZ2_SR->SetLineWidth(2); ZZ3_SR->SetLineWidth(2); WW1_SR->SetLineWidth(2); WW2_SR->SetLineWidth(2); WZ1_SR->SetLineWidth(2); WZ2_SR->SetLineWidth(2); WZ3_SR->SetLineWidth(2);
	
	tptzm1700lh_SR->SetLineStyle(2); tptzm0700lh_SR->SetLineColor(2); tptzm0900lh_SR->SetLineColor(2); tptzm1400lh_SR->SetLineColor(2); tptzm1700lh_SR->SetLineColor(2); 
	

	ZToNuNu_PRE->SetLineColor(kOrange); ZToNuNu_1_SR->SetLineColor(kOrange); ZToNuNu_2_SR->SetLineColor(kOrange);ZToNuNu_3_SR->SetLineColor(kOrange); ZToNuNu_4_SR->SetLineColor(kOrange); ZToNuNu_5_SR->SetLineColor(kOrange); ZToNuNu_6_SR->SetLineColor(kOrange); ZToNuNu_7_SR->SetLineColor(kOrange);
	QCD_SR->SetLineColor(kGreen-3); QCD_1_SR->SetLineColor(kGreen-3); QCD_2_SR->SetLineColor(kGreen-3);QCD_3_SR->SetLineColor(kGreen-3); QCD_4_SR->SetLineColor(kGreen-3); QCD_5_SR->SetLineColor(kGreen-3); QCD_6_SR->SetLineColor(kGreen-3); QCD_7_SR->SetLineColor(kGreen-3);
	WToLNu_PRE->SetLineColor(kCyan-4); WToLNu_1_SR->SetLineColor(kCyan-4); WToLNu_2_SR->SetLineColor(kCyan-4); WToLNu_3_SR->SetLineColor(kCyan-4); WToLNu_4_SR->SetLineColor(kCyan-4); WToLNu_5_SR->SetLineColor(kCyan-4); WToLNu_6_SR->SetLineColor(kCyan-4); WToLNu_7_SR->SetLineColor(kCyan-4);
	TT_PRE->SetLineColor(kGreen+3); TT_1_SR->SetLineColor(kGreen+3); TT_2_SR->SetLineColor(kGreen+3);
	ST_SR->SetLineColor(kGreen+3); ST_1_SR->SetLineColor(kGreen+3); ST_2_SR->SetLineColor(kGreen+3); ST_3_SR->SetLineColor(kGreen+3); ST_4_SR->SetLineColor(kGreen+3); 
	VV_SR->SetLineColor(kCyan+2); ZZ1_SR->SetLineColor(kCyan+2); ZZ2_SR->SetLineColor(kCyan+2); ZZ3_SR->SetLineColor(kCyan+2); WW1_SR->SetLineColor(kCyan+2); WW2_SR->SetLineColor(kCyan+2); WZ1_SR->SetLineColor(kCyan+2); WZ2_SR->SetLineColor(kCyan+2); WZ3_SR->SetLineColor(kCyan+2); 

	ZToNuNu_PRE->SetFillColor(kOrange); ZToNuNu_1_SR->SetFillColor(kOrange); ZToNuNu_2_SR->SetFillColor(kOrange);ZToNuNu_3_SR->SetFillColor(kOrange); ZToNuNu_4_SR->SetFillColor(kOrange); ZToNuNu_5_SR->SetFillColor(kOrange); ZToNuNu_6_SR->SetFillColor(kOrange); ZToNuNu_7_SR->SetFillColor(kOrange);
	QCD_SR->SetFillColor(kGreen-3); QCD_1_SR->SetFillColor(kGreen-3); QCD_2_SR->SetFillColor(kGreen-3);QCD_3_SR->SetFillColor(kGreen-3); QCD_4_SR->SetFillColor(kGreen-3); QCD_5_SR->SetFillColor(kGreen-3); QCD_6_SR->SetFillColor(kGreen-3); QCD_7_SR->SetFillColor(kGreen-3);
	WToLNu_PRE->SetFillColor(kCyan-4); WToLNu_1_SR->SetFillColor(kCyan-4); WToLNu_2_SR->SetFillColor(kCyan-4); WToLNu_3_SR->SetFillColor(kCyan-4); WToLNu_4_SR->SetFillColor(kCyan-4); WToLNu_5_SR->SetFillColor(kCyan-4); WToLNu_6_SR->SetFillColor(kCyan-4); WToLNu_7_SR->SetFillColor(kCyan-4);
	TT_PRE->SetFillColor(kGreen+3); TT_1_SR->SetFillColor(kGreen+3); TT_2_SR->SetFillColor(kGreen+3); 
	ST_SR->SetFillColor(kGreen+3); ST_1_SR->SetFillColor(kGreen+3); ST_2_SR->SetFillColor(kGreen+3); ST_3_SR->SetFillColor(kGreen+3); ST_4_SR->SetFillColor(kGreen+3); 
	VV_SR->SetFillColor(kCyan+2); ZZ1_SR->SetFillColor(kCyan+2); ZZ2_SR->SetFillColor(kCyan+2); ZZ3_SR->SetFillColor(kCyan+2); WW1_SR->SetFillColor(kCyan+2); WW2_SR->SetFillColor(kCyan+2); WZ1_SR->SetFillColor(kCyan+2); WZ2_SR->SetFillColor(kCyan+2); WZ3_SR->SetFillColor(kCyan+2); 
	
	data_SR->SetLineWidth(2); data_SR->SetLineColor(1); data_SR->SetMarkerColor(1); data_SR->SetMarkerStyle(20); data_SR->SetMarkerSize(1.3);

    Double_t dataErr   = 0; Float_t dataYield = data_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX()-1,dataErr,"");
    Double_t ZToNuNu_1Err   = 0; Float_t ZToNuNu_1Yield = ZToNuNu_1_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_1Err,"");
    Double_t ZToNuNu_2Err   = 0; Float_t ZToNuNu_2Yield = ZToNuNu_2_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_2Err,"");
    Double_t ZToNuNu_3Err   = 0; Float_t ZToNuNu_3Yield = ZToNuNu_3_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_3Err,"");
    Double_t ZToNuNu_4Err   = 0; Float_t ZToNuNu_4Yield = ZToNuNu_4_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_4Err,"");
	Double_t ZToNuNu_5Err   = 0; Float_t ZToNuNu_5Yield = ZToNuNu_5_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_5Err,"");
	Double_t ZToNuNu_6Err   = 0; Float_t ZToNuNu_6Yield = ZToNuNu_6_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_6Err,"");
	Double_t ZToNuNu_7Err   = 0; Float_t ZToNuNu_7Yield = ZToNuNu_7_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_7Err,"");
	Double_t ZToNuNu_Err   = 0; Float_t ZToNuNu_Yield = ZToNuNu_PRE->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_Err,"");
	Double_t QCD_1Err   = 0; Float_t QCD_1Yield = QCD_1_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_1Err,"");
    Double_t QCD_2Err   = 0; Float_t QCD_2Yield = QCD_2_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_2Err,"");
    Double_t QCD_3Err   = 0; Float_t QCD_3Yield = QCD_3_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_3Err,"");
    Double_t QCD_4Err   = 0; Float_t QCD_4Yield = QCD_4_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_4Err,"");
	Double_t QCD_5Err   = 0; Float_t QCD_5Yield = QCD_5_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_5Err,"");
	Double_t QCD_6Err   = 0; Float_t QCD_6Yield = QCD_6_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_6Err,"");
	Double_t QCD_7Err   = 0; Float_t QCD_7Yield = QCD_7_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_7Err,"");
	Double_t QCD_Err   = 0;  Float_t QCD_Yield = QCD_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_Err,"");
    Double_t WToLNu_1Err = 0; Float_t WToLNu_1Yield = WToLNu_1_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WToLNu_1Err,"");
	Double_t WToLNu_2Err = 0; Float_t WToLNu_2Yield = WToLNu_2_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WToLNu_2Err,"");
	Double_t WToLNu_3Err = 0; Float_t WToLNu_3Yield = WToLNu_3_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WToLNu_3Err,"");
	Double_t WToLNu_4Err = 0; Float_t WToLNu_4Yield = WToLNu_4_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WToLNu_4Err,"");
	Double_t WToLNu_5Err = 0; Float_t WToLNu_5Yield = WToLNu_5_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WToLNu_5Err,"");
	Double_t WToLNu_6Err = 0; Float_t WToLNu_6Yield = WToLNu_6_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WToLNu_6Err,"");
	Double_t WToLNu_7Err = 0; Float_t WToLNu_7Yield = WToLNu_7_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WToLNu_7Err,"");
	Double_t WToLNu_Err = 0; Float_t WToLNu_Yield = WToLNu_PRE->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WToLNu_Err,"");
    Double_t TT_1Err = 0; Float_t TT_1Yield = TT_1_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),TT_1Err,"");
	Double_t TT_2Err = 0; Float_t TT_2Yield = TT_2_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),TT_2Err,"");
	Double_t TT_Err = 0; Float_t TT_Yield = TT_PRE->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),TT_Err,"");
    Double_t ST_1Err = 0; Float_t ST_1Yield = ST_1_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ST_1Err,"");
	Double_t ST_2Err = 0; Float_t ST_2Yield = ST_2_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ST_2Err,"");
	Double_t ST_3Err = 0; Float_t ST_3Yield = ST_3_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ST_3Err,"");
	Double_t ST_4Err = 0; Float_t ST_4Yield = ST_4_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ST_4Err,"");
	Double_t ST_Err = 0; Float_t ST_Yield = ST_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ST_Err,"");
    Double_t ZZ1Err    = 0; Float_t ZZ1Yield  = ZZ1_SR ->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZZ1Err, "");
    Double_t ZZ2Err    = 0; Float_t ZZ2Yield  = ZZ2_SR ->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZZ2Err, "");
    Double_t ZZ3Err    = 0; Float_t ZZ3Yield  = ZZ3_SR ->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZZ3Err, "");
    Double_t WZ1Err    = 0; Float_t WZ1Yield  = WZ1_SR ->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WZ1Err, "");
    Double_t WZ2Err    = 0; Float_t WZ2Yield  = WZ2_SR ->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WZ2Err, "");
    Double_t WZ3Err    = 0; Float_t WZ3Yield  = WZ3_SR ->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WZ3Err, "");
    Double_t WW1Err    = 0; Float_t WW1Yield  = WW1_SR ->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WW1Err, "");
    Double_t WW2Err    = 0; Float_t WW2Yield  = WW2_SR ->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WW2Err, "");
	Double_t VV_Err    = 0; Float_t VV_Yield  = VV_SR ->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),VV_Err, "");
	Double_t tptzm0700_Err= 0; Float_t tptzm0700_Yield = tptzm0700lh_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),tptzm0700_Err,"");
	Double_t tptzm0900_Err= 0; Float_t tptzm0900_Yield = tptzm0900lh_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),tptzm0900_Err,"");
    Double_t tptzm1400_Err= 0; Float_t tptzm1400_Yield = tptzm1400lh_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),tptzm1400_Err,"");
	Double_t tptzm1700_Err= 0; Float_t tptzm1700_Yield = tptzm1700lh_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),tptzm1700_Err,"");
	
    if(i==0){
      cout<<endl;
      //cout<<"Plotting "<<name[i]<<endl;
      cout<<"DATA      = "<<data_SR->Integral()<<" +/- "<<dataErr<<endl;
      cout<<"ZToNuNu   = "<<ZToNuNu_1_SR->Integral()+ZToNuNu_2_SR->Integral()+ZToNuNu_3_SR->Integral()+ZToNuNu_4_SR->Integral()+ZToNuNu_5_SR->Integral()+ZToNuNu_6_SR->Integral()+ZToNuNu_7_SR->Integral()<<" +/- "<<
	sqrt(ZToNuNu_1Err*ZToNuNu_1Err+ZToNuNu_2Err*ZToNuNu_2Err+ZToNuNu_3Err*ZToNuNu_3Err+ZToNuNu_4Err*ZToNuNu_4Err+ZToNuNu_5Err*ZToNuNu_5Err+ZToNuNu_6Err*ZToNuNu_6Err+ZToNuNu_7Err*ZToNuNu_7Err)<<endl;
      cout<<"QCD       = "<<QCD_1_SR->Integral()+QCD_2_SR->Integral()+QCD_3_SR->Integral()+QCD_4_SR->Integral()+QCD_5_SR->Integral()+QCD_6_SR->Integral()+QCD_7_SR->Integral()<<" +/- "<<
	  sqrt(QCD_1Err*QCD_1Err+QCD_2Err*QCD_2Err+QCD_3Err*QCD_3Err+QCD_4Err*QCD_4Err+QCD_5Err*QCD_5Err+QCD_6Err*QCD_6Err+QCD_7Err*QCD_7Err)<<endl;
	  cout<<"WToLNu    = "<<WToLNu_1_SR->Integral()+WToLNu_2_SR->Integral()+WToLNu_3_SR->Integral()+WToLNu_4_SR->Integral()+WToLNu_5_SR->Integral()+WToLNu_6_SR->Integral()+WToLNu_7_SR->Integral()<<" +/- "<<sqrt(WToLNu_1Err*WToLNu_1Err+WToLNu_2Err*WToLNu_2Err+WToLNu_3Err*WToLNu_3Err+WToLNu_4Err*WToLNu_4Err+WToLNu_5Err*WToLNu_5Err+WToLNu_6Err*WToLNu_6Err+WToLNu_7Err*WToLNu_7Err)<<endl;
	  cout<<"TT        = "<<TT_1_SR->Integral()+TT_2_SR->Integral()<<" +/- "<<sqrt(TT_1Err*TT_1Err+TT_2Err*TT_2Err)<<endl;
	  cout<<"ST        = "<<ST_1_SR->Integral()+ST_2_SR->Integral()+ST_3_SR->Integral()+ST_4_SR->Integral()<<" +/- "<<sqrt(ST_1Err*ST_1Err+ST_2Err*ST_2Err+ST_3Err*ST_3Err+ST_4Err*ST_4Err)<<endl;
      cout<<"Diboson   = "<<ZZ1_SR->Integral()+ZZ2_SR->Integral()+ZZ3_SR->Integral()+WZ1_SR->Integral()+WZ2_SR->Integral()+WZ3_SR->Integral()+WW1_SR->Integral()+WW2_SR->Integral()<<" +/- "<<sqrt(ZZ1Err*ZZ1Err+ZZ2Err*ZZ2Err+ZZ3Err*ZZ3Err+WZ1Err*WZ1Err+WZ2Err*WZ2Err+WZ3Err*WZ3Err+WW1Err*WW1Err+WW2Err*WW2Err)<<endl;
      cout<<"Total BKG = "<<ZToNuNu_1_SR->Integral()+ZToNuNu_2_SR->Integral()+ZToNuNu_3_SR->Integral()+ZToNuNu_4_SR->Integral()+ZToNuNu_5_SR->Integral()+ZToNuNu_6_SR->Integral()+ZToNuNu_7_SR->Integral()+QCD_1_SR->Integral()+QCD_2_SR->Integral()+QCD_3_SR->Integral()+QCD_4_SR->Integral()+QCD_5_SR->Integral()+QCD_6_SR->Integral()+QCD_7_SR->Integral()+WToLNu_1_SR->Integral()+WToLNu_2_SR->Integral()+WToLNu_3_SR->Integral()+WToLNu_4_SR->Integral()+WToLNu_5_SR->Integral()+WToLNu_6_SR->Integral()+WToLNu_7_SR->Integral()+TT_1_SR->Integral()+TT_2_SR->Integral()+ST_1_SR->Integral()+ST_2_SR->Integral()+ST_3_SR->Integral()+ST_4_SR->Integral()+ZZ1_SR->Integral()+ZZ2_SR->Integral()+ZZ3_SR->Integral()+WZ1_SR->Integral()+WZ2_SR->Integral()+WZ3_SR->Integral()+WW1_SR->Integral()+WW2_SR->Integral()<<" +/- "<<
		  sqrt(ZToNuNu_1Err*ZToNuNu_1Err+ZToNuNu_2Err*ZToNuNu_2Err+ZToNuNu_3Err*ZToNuNu_3Err+ZToNuNu_4Err*ZToNuNu_4Err+ZToNuNu_5Err*ZToNuNu_5Err+ZToNuNu_6Err*ZToNuNu_6Err+ZToNuNu_7Err*ZToNuNu_7Err+QCD_1Err*QCD_1Err+QCD_2Err*QCD_2Err+QCD_3Err*QCD_3Err+QCD_4Err*QCD_4Err+QCD_5Err*QCD_5Err+QCD_6Err*QCD_6Err+QCD_7Err*QCD_7Err+WToLNu_1Err*WToLNu_1Err+WToLNu_2Err*WToLNu_2Err+WToLNu_3Err*WToLNu_3Err+WToLNu_4Err*WToLNu_4Err+WToLNu_5Err*WToLNu_5Err+WToLNu_6Err*WToLNu_6Err+WToLNu_7Err*WToLNu_7Err+ZZ1Err*ZZ1Err+ZZ2Err*ZZ2Err+ZZ3Err*ZZ3Err+WZ1Err*WZ1Err+WZ2Err*WZ2Err+WZ3Err*WZ3Err+WW1Err*WW1Err+WW2Err*WW2Err+ST_1Err*ST_1Err+ST_2Err*ST_2Err+ST_3Err*ST_3Err+ST_4Err*ST_4Err+
		  TT_1Err*TT_1Err+TT_2Err*TT_2Err)<<endl;
      
	  /*cout<<"ZToNuNu   = "<<ZToNuNu_PRE->Integral()<<" +/- "<<sqrt(ZToNuNu_Err*ZToNuNu_Err)<<endl;
	  cout<<"QCD       = "<<QCD_SR->Integral()<<" +/- "<<sqrt(QCD_Err*QCD_Err)<<endl;
	  cout<<"WToLNu    = "<<WToLNu_PRE->Integral()<<" +/- "<<sqrt(WToLNu_Err*WToLNu_Err)<<endl;
	  cout<<"TT        = "<<TT_PRE->Integral()<<" +/- "<<sqrt(TT_Err*TT_Err)<<endl;
	  cout<<"ST        = "<<ST_SR->Integral()<<" +/- "<<sqrt(ST_Err*ST_Err)<<endl;
	  cout<<"Diboson   = "<<VV_SR->Integral()<<" +/- "<<sqrt(VV_Err*VV_Err)<<endl;
	  cout<<"Total BKG = "<<ZToNuNu_PRE->Integral()+QCD_SR->Integral()+WToLNu_PRE->Integral()+TT_PRE->Integral()+ST_SR->Integral()+VV_SR->Integral()<<" +/- "<<
		  sqrt(ZToNuNu_Err*ZToNuNu_Err+QCD_Err*QCD_Err+WToLNu_Err*WToLNu_Err+TT_Err*TT_Err+ST_Err*ST_Err+VV_Err*VV_Err)<<endl;*/

	  cout<<"Tprime LH 0700 = "<<tptzm0700lh_SR->Integral()<<" +/- "<<sqrt(tptzm0700_Err*tptzm0700_Err)<<endl;
	  cout<<"Tprime LH 0900 = "<<tptzm0900lh_SR->Integral()<<" +/- "<<sqrt(tptzm0900_Err*tptzm0900_Err)<<endl;
	  cout<<"Tprime LH 1400 = "<<tptzm1400lh_SR->Integral()<<" +/- "<<sqrt(tptzm1400_Err*tptzm1400_Err)<<endl;
	  cout<<"Tprime LH 1700 = "<<tptzm1700lh_SR->Integral()<<" +/- "<<sqrt(tptzm1700_Err*tptzm1700_Err)<<endl;
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

	/*TH1F *RATIO2 = (TH1F*)background_PRE->Clone();
    Double_t x[bin[i]]; Double_t exl[bin[i]]; Double_t exh[bin[i]];
    Double_t y[bin[i]]; Double_t eyl[bin[i]]; Double_t eyh[bin[i]]; 
    for(int m=0; m<background_PRE->GetNbinsX(); m++){ 
      x[m]=Min[i]+m*(Max[i]-Min[i])/bin[i]+(Max[i]-Min[i])/(2*bin[i]);
      exl[m]=(Max[i]-Min[i])/(2*bin[i]);
      exh[m]=(Max[i]-Min[i])/(2*bin[i]);
      RATIO2->SetBinContent(m+1,1);
      if(background_PRE->GetBinContent(m+1)!=0) {
	y[m]=data_SR->GetBinContent(m+1)/background_PRE->GetBinContent(m+1);
	eyl[m]=sqrt(gDATA->GetErrorYlow(m)*gDATA->GetErrorYlow(m))/background_PRE->GetBinContent(m+1);
	eyh[m]=sqrt(gDATA->GetErrorYhigh(m)*gDATA->GetErrorYhigh(m))/background_PRE->GetBinContent(m+1);
	RATIO2->SetBinError(m+1,background_PRE->GetBinError(m+1)/background_PRE->GetBinContent(m+1));
      } else {
	y[m]=-1;
	eyl[m]=0;
	eyh[m]=0;
      }
    }*/

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
    RATIO->GetYaxis()->SetTitle("observed/MC");
    //RATIO->GetYaxis()->SetTitle("observed/expected");
	//RATIO->GetYaxis()->SetTitle("expected/MC");
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
    hs->Add(TT_1_SR);
	hs->Add(TT_2_SR);
    hs->Add(WToLNu_1_SR);
	hs->Add(WToLNu_2_SR);
	hs->Add(WToLNu_3_SR);
    hs->Add(WToLNu_4_SR);
    hs->Add(WToLNu_5_SR);
	hs->Add(WToLNu_6_SR);
	hs->Add(WToLNu_7_SR);
    hs->Add(ZZ1_SR);
    hs->Add(ZZ2_SR);
    hs->Add(ZZ3_SR);
    hs->Add(WZ1_SR);
    hs->Add(WZ2_SR);
    hs->Add(WZ3_SR);
    hs->Add(WW1_SR);
    hs->Add(WW2_SR);
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

	/*hs->Add(ST_SR);
	hs->Add(TT_PRE);
	hs->Add(WToLNu_PRE);
	hs->Add(VV_SR);
	hs->Add(QCD_SR);
	hs->Add(ZToNuNu_PRE);*/
	
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
    tptzm0900lh_SR->Draw("samehisto");
    tptzm1700lh_SR->Draw("samehisto");

    data_SR->Draw("E same"); 

    background_SR->SetFillStyle(3005);
    background_SR->SetFillColor(12);
    background_SR->SetLineColor(12);
    background_SR->Draw("E2same");

	/*background_PRE->SetFillStyle(3005);
    background_PRE->SetFillColor(12);
    background_PRE->SetLineColor(12);
    background_PRE->Draw("E2same");*/
    
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
    ple2 = pl2->AddEntry(QCD_SR, "QCD",  "F");
	ple2 = pl2->AddEntry(WToLNu_1_SR, "W to LNu",  "F");
    ple2 = pl2->AddEntry(ZZ1_SR, "VV (V = Z or W)",  "F");
    ple2 = pl2->AddEntry(ST_1_SR, "t#bar{t} and single-top",  "F");
    ple2 = pl2->AddEntry(tptzm0900lh_SR, "T, M=0.9TeV, #sigma#times100",  "L"); 
    ple2 = pl2->AddEntry(tptzm1700lh_SR, "T, M=1.7TeV, #sigma#times100",  "L"); 
    pl2->Draw();
    
    TString NAME = name[i];
    cout<<"Finished "<<NAME<<endl;
    c1->SaveAs(NAME+".png");
	//c1->SaveAs(NAME+".png");
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

void MakeHistos(char CUTPre[1000],char CUTCS1[1000],char CUTCS2[1000],char CUTCS3[1000],const char *plot,int BIN,double MIN,double MAX,int JETSyst,
		TH1F* &data_func,TH1F* &background_func,TH1F* &background_PRE_func,
		TH1F* &ZToNuNu_func,TH1F* &ZToNuNu_1_func,TH1F* &ZToNuNu_2_func,TH1F* &ZToNuNu_3_func,TH1F* &ZToNuNu_4_func,TH1F* &ZToNuNu_5_func,TH1F* &ZToNuNu_6_func,TH1F* &ZToNuNu_7_func,
		TH1F* &QCD_func,TH1F* &QCD_1_func,TH1F* &QCD_2_func,TH1F* &QCD_3_func,TH1F* &QCD_4_func,TH1F* &QCD_5_func,TH1F* &QCD_6_func,TH1F* &QCD_7_func,
		TH1F* &WToLNu_func,TH1F* &WToLNu_1_func,TH1F* &WToLNu_2_func,TH1F* &WToLNu_3_func,TH1F* &WToLNu_4_func,TH1F* &WToLNu_5_func,TH1F* &WToLNu_6_func,TH1F* &WToLNu_7_func,
		TH1F* &TT_func,TH1F* &TT_1_func,TH1F* &TT_2_func,
		TH1F* &ST_func,TH1F* &ST_1_func,TH1F* &ST_2_func,TH1F* &ST_3_func,TH1F* &ST_4_func,
		TH1F* &VV_func,TH1F* &ZZ1_func,TH1F* &ZZ2_func,TH1F* &ZZ3_func,TH1F* &WW1_func,TH1F* &WW2_func,TH1F* &WZ1_func,TH1F* &WZ2_func,TH1F* &WZ3_func,
		TH1F* &tptzm0700lh_func,TH1F* &tptzm0900lh_func,TH1F* &tptzm1400lh_func,TH1F* &tptzm1700lh_func,
		TH1F* &SF1_h_func,TH1F* &SF2_h_func,TH1F* &SF3_h_func){
  TH1F *data; TH1F *tptzm0700lh; TH1F *tptzm0900lh; TH1F *tptzm1400lh; TH1F *tptzm1700lh; 
  TH1F *ZToNuNu = new TH1F("", "", BIN,MIN,MAX);  TH1F *ZToNuNu_1; TH1F *ZToNuNu_2; TH1F *ZToNuNu_3; TH1F *ZToNuNu_4; TH1F *ZToNuNu_5; TH1F *ZToNuNu_6; TH1F *ZToNuNu_7; 
  TH1F *QCD     = new TH1F("", "", BIN,MIN,MAX);  TH1F *QCD_1; TH1F *QCD_2; TH1F *QCD_3; TH1F *QCD_4; TH1F *QCD_5; TH1F *QCD_6; TH1F *QCD_7; 
  TH1F *WToLNu  = new TH1F("", "", BIN,MIN,MAX);  TH1F *WToLNu_1; TH1F *WToLNu_2; TH1F *WToLNu_3; TH1F *WToLNu_4; TH1F *WToLNu_5; TH1F *WToLNu_6; TH1F *WToLNu_7;
  TH1F *TT      = new TH1F("", "", BIN,MIN,MAX);  TH1F *TT_1; TH1F *TT_2; 
  TH1F *ST      = new TH1F("", "", BIN,MIN,MAX);  TH1F *ST_1; TH1F *ST_2; TH1F *ST_3; TH1F *ST_4; 
  TH1F *VV      = new TH1F("", "", BIN,MIN,MAX);  TH1F *ZZ1; TH1F *ZZ2; TH1F *ZZ3; TH1F *WZ1; TH1F *WZ2; TH1F *WZ3; TH1F *WW1; TH1F *WW2; 

  TH1F *data_CS1; TH1F *tptzm0700lh_CS1; TH1F *tptzm0900lh_CS1; TH1F *tptzm1400lh_CS1; TH1F *tptzm1700lh_CS1; 
  TH1F *ZToNuNu_CS1 = new TH1F("", "", BIN,MIN,MAX);  TH1F *ZToNuNu_1_CS1; TH1F *ZToNuNu_2_CS1; TH1F *ZToNuNu_3_CS1; TH1F *ZToNuNu_4_CS1; TH1F *ZToNuNu_5_CS1; TH1F *ZToNuNu_6_CS1; TH1F *ZToNuNu_7_CS1; 
  TH1F *QCD_CS1     = new TH1F("", "", BIN,MIN,MAX);  TH1F *QCD_1_CS1; TH1F *QCD_2_CS1; TH1F *QCD_3_CS1; TH1F *QCD_4_CS1; TH1F *QCD_5_CS1; TH1F *QCD_6_CS1; TH1F *QCD_7_CS1; 
  TH1F *WToLNu_CS1  = new TH1F("", "", BIN,MIN,MAX);  TH1F *WToLNu_1_CS1; TH1F *WToLNu_2_CS1; TH1F *WToLNu_3_CS1; TH1F *WToLNu_4_CS1; TH1F *WToLNu_5_CS1; TH1F *WToLNu_6_CS1; TH1F *WToLNu_7_CS1;
  TH1F *TT_CS1      = new TH1F("", "", BIN,MIN,MAX);  TH1F *TT_1_CS1; TH1F *TT_2_CS1; 
  TH1F *ST_CS1      = new TH1F("", "", BIN,MIN,MAX);  TH1F *ST_1_CS1; TH1F *ST_2_CS1; TH1F *ST_3_CS1; TH1F *ST_4_CS1; 
  TH1F *VV_CS1      = new TH1F("", "", BIN,MIN,MAX);  TH1F *ZZ1_CS1; TH1F *ZZ2_CS1; TH1F *ZZ3_CS1; TH1F *WZ1_CS1; TH1F *WZ2_CS1; TH1F *WZ3_CS1; TH1F *WW1_CS1; TH1F *WW2_CS1; 

  TH1F *data_CS2; TH1F *tptzm0700lh_CS2; TH1F *tptzm0900lh_CS2; TH1F *tptzm1400lh_CS2; TH1F *tptzm1700lh_CS2; 
  TH1F *ZToNuNu_CS2 = new TH1F("", "", BIN,MIN,MAX);  TH1F *ZToNuNu_1_CS2; TH1F *ZToNuNu_2_CS2; TH1F *ZToNuNu_3_CS2; TH1F *ZToNuNu_4_CS2; TH1F *ZToNuNu_5_CS2; TH1F *ZToNuNu_6_CS2; TH1F *ZToNuNu_7_CS2; 
  TH1F *QCD_CS2     = new TH1F("", "", BIN,MIN,MAX);  TH1F *QCD_1_CS2; TH1F *QCD_2_CS2; TH1F *QCD_3_CS2; TH1F *QCD_4_CS2; TH1F *QCD_5_CS2; TH1F *QCD_6_CS2; TH1F *QCD_7_CS2;  
  TH1F *WToLNu_CS2  = new TH1F("", "", BIN,MIN,MAX);  TH1F *WToLNu_1_CS2; TH1F *WToLNu_2_CS2; TH1F *WToLNu_3_CS2; TH1F *WToLNu_4_CS2; TH1F *WToLNu_5_CS2; TH1F *WToLNu_6_CS2; TH1F *WToLNu_7_CS2;
  TH1F *TT_CS2      = new TH1F("", "", BIN,MIN,MAX);  TH1F *TT_1_CS2; TH1F *TT_2_CS2; 
  TH1F *ST_CS2      = new TH1F("", "", BIN,MIN,MAX);  TH1F *ST_1_CS2; TH1F *ST_2_CS2; TH1F *ST_3_CS2; TH1F *ST_4_CS2; 
  TH1F *VV_CS2      = new TH1F("", "", BIN,MIN,MAX);  TH1F *ZZ1_CS2; TH1F *ZZ2_CS2; TH1F *ZZ3_CS2; TH1F *WZ1_CS2; TH1F *WZ2_CS2; TH1F *WZ3_CS2; TH1F *WW1_CS2; TH1F *WW2_CS2; 

  TH1F *data_CS3; TH1F *tptzm0700lh_CS3; TH1F *tptzm0900lh_CS3; TH1F *tptzm1400lh_CS3; TH1F *tptzm1700lh_CS3; 
  TH1F *ZToNuNu_CS3 = new TH1F("", "", BIN,MIN,MAX);  TH1F *ZToNuNu_1_CS3; TH1F *ZToNuNu_2_CS3; TH1F *ZToNuNu_3_CS3; TH1F *ZToNuNu_4_CS3; TH1F *ZToNuNu_5_CS3; TH1F *ZToNuNu_6_CS3; TH1F *ZToNuNu_7_CS3; 
  TH1F *QCD_CS3     = new TH1F("", "", BIN,MIN,MAX);  TH1F *QCD_1_CS3; TH1F *QCD_2_CS3; TH1F *QCD_3_CS3; TH1F *QCD_4_CS3; TH1F *QCD_5_CS3; TH1F *QCD_6_CS3; TH1F *QCD_7_CS3; 
  TH1F *WToLNu_CS3  = new TH1F("", "", BIN,MIN,MAX);  TH1F *WToLNu_1_CS3; TH1F *WToLNu_2_CS3; TH1F *WToLNu_3_CS3; TH1F *WToLNu_4_CS3; TH1F *WToLNu_5_CS3; TH1F *WToLNu_6_CS3; TH1F *WToLNu_7_CS3;
  TH1F *TT_CS3      = new TH1F("", "", BIN,MIN,MAX);  TH1F *TT_1_CS3; TH1F *TT_2_CS3; 
  TH1F *ST_CS3      = new TH1F("", "", BIN,MIN,MAX);  TH1F *ST_1_CS3; TH1F *ST_2_CS3; TH1F *ST_3_CS3; TH1F *ST_4_CS3; 
  TH1F *VV_CS3      = new TH1F("", "", BIN,MIN,MAX);  TH1F *ZZ1_CS3; TH1F *ZZ2_CS3; TH1F *ZZ3_CS3; TH1F *WZ1_CS3; TH1F *WZ2_CS3; TH1F *WZ3_CS3; TH1F *WW1_CS3; TH1F *WW2_CS3; 

  TH1F *SF1_h = new TH1F("", "", BIN,MIN,MAX);
  TH1F *SF2_h = new TH1F("", "", BIN,MIN,MAX);
  TH1F *SF3_h = new TH1F("", "", BIN,MIN,MAX);
  if(JETSyst==0){
    GetHisto(CUTPre, Tree01, data        ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree02, tptzm0700lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree04, tptzm0900lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09, tptzm1400lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree12, tptzm1700lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree14, ZToNuNu_1   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree15, ZToNuNu_2   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree16, ZToNuNu_3   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree17, ZToNuNu_4   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree18, ZToNuNu_5   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree19, ZToNuNu_6   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree20, ZToNuNu_7   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree21, QCD_1      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree22, QCD_2      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree23, QCD_3      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree24, QCD_4      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree25, QCD_5      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree26, QCD_6      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree27, QCD_7      ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree28, WToLNu_1   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree29, WToLNu_2   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree30, WToLNu_3   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree31, WToLNu_4   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree32, WToLNu_5   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree33, WToLNu_6   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree34, WToLNu_7   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree35, TT_1    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree36, TT_2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree37, ST_1    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree38, ST_2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree39, ST_3    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree40, ST_4    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree41, ZZ1    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree42, ZZ2    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree43, ZZ3    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree44, WW1    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree45, WW2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree46, WZ1    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree47, WZ2    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree48, WZ3    ,plot,BIN,MIN,MAX);

	GetHisto(CUTCS1, Tree01, data_CS1        ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree02, tptzm0700lh_CS1 ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree04, tptzm0900lh_CS1 ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree09, tptzm1400lh_CS1 ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree12, tptzm1700lh_CS1 ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree14, ZToNuNu_1_CS1   ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree15, ZToNuNu_2_CS1   ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree16, ZToNuNu_3_CS1   ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree17, ZToNuNu_4_CS1   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS1, Tree18, ZToNuNu_5_CS1   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS1, Tree19, ZToNuNu_6_CS1   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS1, Tree20, ZToNuNu_7_CS1   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS1, Tree21, QCD_1_CS1      ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree22, QCD_2_CS1      ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree23, QCD_3_CS1      ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree24, QCD_4_CS1      ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree25, QCD_5_CS1      ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree26, QCD_6_CS1      ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree27, QCD_7_CS1      ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS1, Tree28, WToLNu_1_CS1   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS1, Tree29, WToLNu_2_CS1   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS1, Tree30, WToLNu_3_CS1   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS1, Tree31, WToLNu_4_CS1   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS1, Tree32, WToLNu_5_CS1   ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree33, WToLNu_6_CS1   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS1, Tree34, WToLNu_7_CS1   ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree35, TT_1_CS1    ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS1, Tree36, TT_2_CS1    ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree37, ST_1_CS1    ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree38, ST_2_CS1    ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree39, ST_3_CS1    ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree40, ST_4_CS1    ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree41, ZZ1_CS1    ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS1, Tree42, ZZ2_CS1    ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS1, Tree43, ZZ3_CS1    ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS1, Tree44, WW1_CS1    ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS1, Tree45, WW2_CS1    ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree46, WZ1_CS1    ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS1, Tree47, WZ2_CS1    ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS1, Tree48, WZ3_CS1    ,plot,BIN,MIN,MAX);

	GetHisto(CUTCS2, Tree01, data_CS2        ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree02, tptzm0700lh_CS2 ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree04, tptzm0900lh_CS2 ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree09, tptzm1400lh_CS2 ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree12, tptzm1700lh_CS2 ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree14, ZToNuNu_1_CS2   ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree15, ZToNuNu_2_CS2   ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree16, ZToNuNu_3_CS2   ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree17, ZToNuNu_4_CS2   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS2, Tree18, ZToNuNu_5_CS2   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS2, Tree19, ZToNuNu_6_CS2   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS2, Tree20, ZToNuNu_7_CS2   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS2, Tree21, QCD_1_CS2      ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree22, QCD_2_CS2      ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree23, QCD_3_CS2      ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree24, QCD_4_CS2      ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree25, QCD_5_CS2      ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree26, QCD_6_CS2      ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree27, QCD_7_CS2      ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS2, Tree28, WToLNu_1_CS2   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS2, Tree29, WToLNu_2_CS2   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS2, Tree30, WToLNu_3_CS2   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS2, Tree31, WToLNu_4_CS2   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS2, Tree32, WToLNu_5_CS2   ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree33, WToLNu_6_CS2   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS2, Tree34, WToLNu_7_CS2   ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree35, TT_1_CS2    ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS2, Tree36, TT_2_CS2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree37, ST_1_CS2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree38, ST_2_CS2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree39, ST_3_CS2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree40, ST_4_CS2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree41, ZZ1_CS2    ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS2, Tree42, ZZ2_CS2    ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS2, Tree43, ZZ3_CS2    ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS2, Tree44, WW1_CS2    ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS2, Tree45, WW2_CS2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree46, WZ1_CS2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS2, Tree47, WZ2_CS2    ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS2, Tree48, WZ3_CS2    ,plot,BIN,MIN,MAX);

	GetHisto(CUTCS3, Tree01, data_CS3        ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree02, tptzm0700lh_CS3 ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree04, tptzm0900lh_CS3 ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree09, tptzm1400lh_CS3 ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree12, tptzm1700lh_CS3 ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree14, ZToNuNu_1_CS3   ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree15, ZToNuNu_2_CS3   ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree16, ZToNuNu_3_CS3   ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree17, ZToNuNu_4_CS3   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS3, Tree18, ZToNuNu_5_CS3   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS3, Tree19, ZToNuNu_6_CS3   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS3, Tree20, ZToNuNu_7_CS3   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS3, Tree21, QCD_1_CS3      ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree22, QCD_2_CS3      ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree23, QCD_3_CS3      ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree24, QCD_4_CS3      ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree25, QCD_5_CS3      ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree26, QCD_6_CS3      ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree27, QCD_7_CS3      ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS3, Tree28, WToLNu_1_CS3   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS3, Tree29, WToLNu_2_CS3   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS3, Tree30, WToLNu_3_CS3   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS3, Tree31, WToLNu_4_CS3   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS3, Tree32, WToLNu_5_CS3   ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree33, WToLNu_6_CS3   ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS3, Tree34, WToLNu_7_CS3   ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree35, TT_1_CS3    ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS3, Tree36, TT_2_CS3    ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree37, ST_1_CS3    ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree38, ST_2_CS3    ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree39, ST_3_CS3    ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree40, ST_4_CS3    ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree41, ZZ1_CS3    ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS3, Tree42, ZZ2_CS3    ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS3, Tree43, ZZ3_CS3    ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS3, Tree44, WW1_CS3    ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS3, Tree45, WW2_CS3    ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree46, WZ1_CS3    ,plot,BIN,MIN,MAX);
    GetHisto(CUTCS3, Tree47, WZ2_CS3    ,plot,BIN,MIN,MAX);
	GetHisto(CUTCS3, Tree48, WZ3_CS3    ,plot,BIN,MIN,MAX);


  }  
  
  TH1F *background = new TH1F("","",data->GetNbinsX(),data->GetXaxis()->GetXmin(),data->GetXaxis()->GetXmax());
  TH1F *background_PRE = new TH1F("","",data->GetNbinsX(),data->GetXaxis()->GetXmin(),data->GetXaxis()->GetXmax());
  TH1F *background_CS1 = new TH1F("","",data->GetNbinsX(),data->GetXaxis()->GetXmin(),data->GetXaxis()->GetXmax());
  TH1F *background_CS2 = new TH1F("","",data->GetNbinsX(),data->GetXaxis()->GetXmin(),data->GetXaxis()->GetXmax());
  TH1F *background_CS3 = new TH1F("","",data->GetNbinsX(),data->GetXaxis()->GetXmin(),data->GetXaxis()->GetXmax());
  for(int j=1; j<data->GetNbinsX()+1; j++){
    if(tptzm0700lh->GetBinContent(j)>0){tptzm0700lh->SetBinError(j,sqrt(w0700*w0700*tptzm0700lh->GetBinContent(j)));}else{tptzm0700lh->SetBinError(j,0);}
    if(tptzm0900lh->GetBinContent(j)>0){tptzm0900lh->SetBinError(j,sqrt(w0900*w0900*tptzm0900lh->GetBinContent(j)));}else{tptzm0900lh->SetBinError(j,0);}
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
    if(WToLNu_1->GetBinContent(j)>0){WToLNu_1->SetBinError(j,sqrt(w15*w15*WToLNu_1->GetBinContent(j)));}else{WToLNu_1->SetBinError(j,0);}//w15);}
	if(WToLNu_2->GetBinContent(j)>0){WToLNu_2->SetBinError(j,sqrt(w16*w16*WToLNu_2->GetBinContent(j)));}else{WToLNu_2->SetBinError(j,0);}//w16);}
	if(WToLNu_3->GetBinContent(j)>0){WToLNu_3->SetBinError(j,sqrt(w17*w17*WToLNu_3->GetBinContent(j)));}else{WToLNu_3->SetBinError(j,0);}//w17);}
	if(WToLNu_4->GetBinContent(j)>0){WToLNu_4->SetBinError(j,sqrt(w18*w18*WToLNu_4->GetBinContent(j)));}else{WToLNu_4->SetBinError(j,0);}//w18);}
	if(WToLNu_5->GetBinContent(j)>0){WToLNu_5->SetBinError(j,sqrt(w19*w19*WToLNu_5->GetBinContent(j)));}else{WToLNu_5->SetBinError(j,0);}//w19);}
	if(WToLNu_6->GetBinContent(j)>0){WToLNu_6->SetBinError(j,sqrt(w20*w20*WToLNu_6->GetBinContent(j)));}else{WToLNu_6->SetBinError(j,0);}//w20);}
	if(WToLNu_7->GetBinContent(j)>0){WToLNu_7->SetBinError(j,sqrt(w21*w21*WToLNu_7->GetBinContent(j)));}else{WToLNu_7->SetBinError(j,0);}//w21);}
	if(TT_1->GetBinContent(j)>0){TT_1->SetBinError(j,sqrt(w22*w22*TT_1->GetBinContent(j)));}else{TT_1->SetBinError(j,0);}//w22);}
	if(TT_2->GetBinContent(j)>0){TT_2->SetBinError(j,sqrt(w23*w23*TT_2->GetBinContent(j)));}else{TT_2->SetBinError(j,0);}//w23);}
    if(ST_1->GetBinContent(j)>0){ST_1->SetBinError(j,sqrt(w24*w24*ST_1->GetBinContent(j)));}else{ST_1->SetBinError(j,0);}//w24);}
    if(ST_2->GetBinContent(j)>0){ST_2->SetBinError(j,sqrt(w25*w25*ST_2->GetBinContent(j)));}else{ST_2->SetBinError(j,0);}//w25);}
    if(ST_3->GetBinContent(j)>0){ST_3->SetBinError(j,sqrt(w26*w26*ST_3->GetBinContent(j)));}else{ST_3->SetBinError(j,0);}//w26);}
    if(ST_4->GetBinContent(j)>0){ST_4->SetBinError(j,sqrt(w27*w27*ST_4->GetBinContent(j)));}else{ST_4->SetBinError(j,0);}//w27);}
    if(ZZ1->GetBinContent(j)>0){ZZ1->SetBinError(j,sqrt(w28*w28*ZZ1->GetBinContent(j)));}else{ZZ1->SetBinError(j,0);}//w28);}
	if(ZZ2->GetBinContent(j)>0){ZZ2->SetBinError(j,sqrt(w29*w29*ZZ2->GetBinContent(j)));}else{ZZ2->SetBinError(j,0);}//w29);}
	if(ZZ3->GetBinContent(j)>0){ZZ3->SetBinError(j,sqrt(w30*w30*ZZ3->GetBinContent(j)));}else{ZZ3->SetBinError(j,0);}//w30);}
    if(WW1->GetBinContent(j)>0){WW1->SetBinError(j,sqrt(w31*w31*WW1->GetBinContent(j)));}else{WW1->SetBinError(j,0);}//w31);}
	if(WW2->GetBinContent(j)>0){WW2->SetBinError(j,sqrt(w32*w32*WW2->GetBinContent(j)));}else{WW2->SetBinError(j,0);}//w32);}
	if(WZ1->GetBinContent(j)>0){WZ1->SetBinError(j,sqrt(w33*w33*WZ1->GetBinContent(j)));}else{WZ1->SetBinError(j,0);}//w33);}
	if(WZ2->GetBinContent(j)>0){WZ2->SetBinError(j,sqrt(w34*w34*WZ2->GetBinContent(j)));}else{WZ2->SetBinError(j,0);}//w34);}
	if(WZ3->GetBinContent(j)>0){WZ3->SetBinError(j,sqrt(w35*w35*WZ3->GetBinContent(j)));}else{WZ3->SetBinError(j,0);}//w35);}
	//if(WToLNu->GetBinContent(j)>0){WToLNu->SetBinError(j,sqrt(w36*w36*WToLNu->GetBinContent(j)));}else{WToLNu->SetBinError(j,0);}//w36);}

	if(tptzm0700lh_CS1->GetBinContent(j)>0){tptzm0700lh_CS1->SetBinError(j,sqrt(w0700*w0700*tptzm0700lh_CS1->GetBinContent(j)));}else{tptzm0700lh_CS1->SetBinError(j,0);}
    if(tptzm0900lh_CS1->GetBinContent(j)>0){tptzm0900lh_CS1->SetBinError(j,sqrt(w0900*w0900*tptzm0900lh_CS1->GetBinContent(j)));}else{tptzm0900lh_CS1->SetBinError(j,0);}
    if(tptzm1400lh_CS1->GetBinContent(j)>0){tptzm1400lh_CS1->SetBinError(j,sqrt(w1400*w1400*tptzm1400lh_CS1->GetBinContent(j)));}else{tptzm1400lh_CS1->SetBinError(j,0);}
    if(tptzm1700lh_CS1->GetBinContent(j)>0){tptzm1700lh_CS1->SetBinError(j,sqrt(w1700*w1700*tptzm1700lh_CS1->GetBinContent(j)));}else{tptzm1700lh_CS1->SetBinError(j,0);}
    if(ZToNuNu_1_CS1 ->GetBinContent(j)>0){ZToNuNu_1_CS1 ->SetBinError(j,sqrt(w01*w01*ZToNuNu_1_CS1 ->GetBinContent(j)));}else{ZToNuNu_1_CS1 ->SetBinError(j,0);}//w01);}
    if(ZToNuNu_2_CS1 ->GetBinContent(j)>0){ZToNuNu_2_CS1 ->SetBinError(j,sqrt(w02*w02*ZToNuNu_2_CS1 ->GetBinContent(j)));}else{ZToNuNu_2_CS1 ->SetBinError(j,0);}//w02);}
    if(ZToNuNu_3_CS1 ->GetBinContent(j)>0){ZToNuNu_3_CS1 ->SetBinError(j,sqrt(w03*w03*ZToNuNu_3_CS1 ->GetBinContent(j)));}else{ZToNuNu_3_CS1 ->SetBinError(j,0);}//w03);}
    if(ZToNuNu_4_CS1 ->GetBinContent(j)>0){ZToNuNu_4_CS1 ->SetBinError(j,sqrt(w04*w04*ZToNuNu_4_CS1 ->GetBinContent(j)));}else{ZToNuNu_4_CS1 ->SetBinError(j,0);}//w04);}
	if(ZToNuNu_5_CS1 ->GetBinContent(j)>0){ZToNuNu_5_CS1 ->SetBinError(j,sqrt(w05*w05*ZToNuNu_5_CS1 ->GetBinContent(j)));}else{ZToNuNu_5_CS1 ->SetBinError(j,0);}//w05);}
	if(ZToNuNu_6_CS1 ->GetBinContent(j)>0){ZToNuNu_6_CS1 ->SetBinError(j,sqrt(w06*w06*ZToNuNu_6_CS1 ->GetBinContent(j)));}else{ZToNuNu_6_CS1 ->SetBinError(j,0);}//w06);}
	if(ZToNuNu_7_CS1 ->GetBinContent(j)>0){ZToNuNu_7_CS1 ->SetBinError(j,sqrt(w07*w07*ZToNuNu_7_CS1 ->GetBinContent(j)));}else{ZToNuNu_7_CS1 ->SetBinError(j,0);}//w07);}
	if(QCD_1_CS1->GetBinContent(j)>0){QCD_1_CS1 ->SetBinError(j,sqrt(w08*w08*QCD_1_CS1 ->GetBinContent(j)));}else{QCD_1_CS1 ->SetBinError(j,0);}//w08);}
    if(QCD_2_CS1->GetBinContent(j)>0){QCD_2_CS1 ->SetBinError(j,sqrt(w09*w09*QCD_2_CS1 ->GetBinContent(j)));}else{QCD_2_CS1 ->SetBinError(j,0);}//w09);}
    if(QCD_3_CS1->GetBinContent(j)>0){QCD_3_CS1 ->SetBinError(j,sqrt(w10*w10*QCD_3_CS1 ->GetBinContent(j)));}else{QCD_3_CS1 ->SetBinError(j,0);}//w10);}
	if(QCD_4_CS1->GetBinContent(j)>0){QCD_4_CS1 ->SetBinError(j,sqrt(w11*w11*QCD_4_CS1 ->GetBinContent(j)));}else{QCD_4_CS1 ->SetBinError(j,0);}//w11);}
    if(QCD_5_CS1->GetBinContent(j)>0){QCD_5_CS1 ->SetBinError(j,sqrt(w12*w12*QCD_5_CS1 ->GetBinContent(j)));}else{QCD_5_CS1 ->SetBinError(j,0);}//w12);}
    if(QCD_6_CS1->GetBinContent(j)>0){QCD_6_CS1 ->SetBinError(j,sqrt(w13*w13*QCD_6_CS1 ->GetBinContent(j)));}else{QCD_6_CS1 ->SetBinError(j,0);}//w13);}
    if(QCD_7_CS1->GetBinContent(j)>0){QCD_7_CS1 ->SetBinError(j,sqrt(w14*w14*QCD_7_CS1 ->GetBinContent(j)));}else{QCD_7_CS1 ->SetBinError(j,0);}//w14);}
    if(WToLNu_1_CS1->GetBinContent(j)>0){WToLNu_1_CS1->SetBinError(j,sqrt(w15*w15*WToLNu_1_CS1->GetBinContent(j)));}else{WToLNu_1_CS1->SetBinError(j,0);}//w15);}
	if(WToLNu_2_CS1->GetBinContent(j)>0){WToLNu_2_CS1->SetBinError(j,sqrt(w16*w16*WToLNu_2_CS1->GetBinContent(j)));}else{WToLNu_2_CS1->SetBinError(j,0);}//w16);}
	if(WToLNu_3_CS1->GetBinContent(j)>0){WToLNu_3_CS1->SetBinError(j,sqrt(w17*w17*WToLNu_3_CS1->GetBinContent(j)));}else{WToLNu_3_CS1->SetBinError(j,0);}//w17);}
	if(WToLNu_4_CS1->GetBinContent(j)>0){WToLNu_4_CS1->SetBinError(j,sqrt(w18*w18*WToLNu_4_CS1->GetBinContent(j)));}else{WToLNu_4_CS1->SetBinError(j,0);}//w18);}
	if(WToLNu_5_CS1->GetBinContent(j)>0){WToLNu_5_CS1->SetBinError(j,sqrt(w19*w19*WToLNu_5_CS1->GetBinContent(j)));}else{WToLNu_5_CS1->SetBinError(j,0);}//w19);}
	if(WToLNu_6_CS1->GetBinContent(j)>0){WToLNu_6_CS1->SetBinError(j,sqrt(w20*w20*WToLNu_6_CS1->GetBinContent(j)));}else{WToLNu_6_CS1->SetBinError(j,0);}//w20);}
	if(WToLNu_7_CS1->GetBinContent(j)>0){WToLNu_7_CS1->SetBinError(j,sqrt(w21*w21*WToLNu_7_CS1->GetBinContent(j)));}else{WToLNu_7_CS1->SetBinError(j,0);}//w21);}
	if(TT_1_CS1->GetBinContent(j)>0){TT_1_CS1->SetBinError(j,sqrt(w22*w22*TT_1_CS1->GetBinContent(j)));}else{TT_1_CS1->SetBinError(j,0);}//w22);}
	if(TT_2_CS1->GetBinContent(j)>0){TT_2_CS1->SetBinError(j,sqrt(w23*w23*TT_2_CS1->GetBinContent(j)));}else{TT_2_CS1->SetBinError(j,0);}//w23);}
    if(ST_1_CS1->GetBinContent(j)>0){ST_1_CS1->SetBinError(j,sqrt(w24*w24*ST_1_CS1->GetBinContent(j)));}else{ST_1_CS1->SetBinError(j,0);}//w24);}
    if(ST_2_CS1->GetBinContent(j)>0){ST_2_CS1->SetBinError(j,sqrt(w25*w25*ST_2_CS1->GetBinContent(j)));}else{ST_2_CS1->SetBinError(j,0);}//w25);}
    if(ST_3_CS1->GetBinContent(j)>0){ST_3_CS1->SetBinError(j,sqrt(w26*w26*ST_3_CS1->GetBinContent(j)));}else{ST_3_CS1->SetBinError(j,0);}//w26);}
    if(ST_4_CS1->GetBinContent(j)>0){ST_4_CS1->SetBinError(j,sqrt(w27*w27*ST_4_CS1->GetBinContent(j)));}else{ST_4_CS1->SetBinError(j,0);}//w27);}
    if(ZZ1_CS1->GetBinContent(j)>0){ZZ1_CS1->SetBinError(j,sqrt(w28*w28*ZZ1_CS1->GetBinContent(j)));}else{ZZ1_CS1->SetBinError(j,0);}//w28);}
	if(ZZ2_CS1->GetBinContent(j)>0){ZZ2_CS1->SetBinError(j,sqrt(w29*w29*ZZ2_CS1->GetBinContent(j)));}else{ZZ2_CS1->SetBinError(j,0);}//w29);}
	if(ZZ3_CS1->GetBinContent(j)>0){ZZ3_CS1->SetBinError(j,sqrt(w30*w30*ZZ3_CS1->GetBinContent(j)));}else{ZZ3_CS1->SetBinError(j,0);}//w30);}
    if(WW1_CS1->GetBinContent(j)>0){WW1_CS1->SetBinError(j,sqrt(w31*w31*WW1_CS1->GetBinContent(j)));}else{WW1_CS1->SetBinError(j,0);}//w31);}
	if(WW2_CS1->GetBinContent(j)>0){WW2_CS1->SetBinError(j,sqrt(w32*w32*WW2_CS1->GetBinContent(j)));}else{WW2_CS1->SetBinError(j,0);}//w32);}
	if(WZ1_CS1->GetBinContent(j)>0){WZ1_CS1->SetBinError(j,sqrt(w33*w33*WZ1_CS1->GetBinContent(j)));}else{WZ1_CS1->SetBinError(j,0);}//w33);}
	if(WZ2_CS1->GetBinContent(j)>0){WZ2_CS1->SetBinError(j,sqrt(w34*w34*WZ2_CS1->GetBinContent(j)));}else{WZ2_CS1->SetBinError(j,0);}//w34);}
	if(WZ3_CS1->GetBinContent(j)>0){WZ3_CS1->SetBinError(j,sqrt(w35*w35*WZ3_CS1->GetBinContent(j)));}else{WZ3_CS1->SetBinError(j,0);}//w35);}

	if(tptzm0700lh_CS2->GetBinContent(j)>0){tptzm0700lh_CS2->SetBinError(j,sqrt(w0700*w0700*tptzm0700lh_CS2->GetBinContent(j)));}else{tptzm0700lh_CS2->SetBinError(j,0);}
    if(tptzm0900lh_CS2->GetBinContent(j)>0){tptzm0900lh_CS2->SetBinError(j,sqrt(w0900*w0900*tptzm0900lh_CS2->GetBinContent(j)));}else{tptzm0900lh_CS2->SetBinError(j,0);}
    if(tptzm1400lh_CS2->GetBinContent(j)>0){tptzm1400lh_CS2->SetBinError(j,sqrt(w1400*w1400*tptzm1400lh_CS2->GetBinContent(j)));}else{tptzm1400lh_CS2->SetBinError(j,0);}
    if(tptzm1700lh_CS2->GetBinContent(j)>0){tptzm1700lh_CS2->SetBinError(j,sqrt(w1700*w1700*tptzm1700lh_CS2->GetBinContent(j)));}else{tptzm1700lh_CS2->SetBinError(j,0);}
    if(ZToNuNu_1_CS2 ->GetBinContent(j)>0){ZToNuNu_1_CS2 ->SetBinError(j,sqrt(w01*w01*ZToNuNu_1_CS2 ->GetBinContent(j)));}else{ZToNuNu_1_CS2 ->SetBinError(j,0);}//w01);}
    if(ZToNuNu_2_CS2 ->GetBinContent(j)>0){ZToNuNu_2_CS2 ->SetBinError(j,sqrt(w02*w02*ZToNuNu_2_CS2 ->GetBinContent(j)));}else{ZToNuNu_2_CS2 ->SetBinError(j,0);}//w02);}
    if(ZToNuNu_3_CS2 ->GetBinContent(j)>0){ZToNuNu_3_CS2 ->SetBinError(j,sqrt(w03*w03*ZToNuNu_3_CS2 ->GetBinContent(j)));}else{ZToNuNu_3_CS2 ->SetBinError(j,0);}//w03);}
    if(ZToNuNu_4_CS2 ->GetBinContent(j)>0){ZToNuNu_4_CS2 ->SetBinError(j,sqrt(w04*w04*ZToNuNu_4_CS2 ->GetBinContent(j)));}else{ZToNuNu_4_CS2 ->SetBinError(j,0);}//w04);}
	if(ZToNuNu_5_CS2 ->GetBinContent(j)>0){ZToNuNu_5_CS2 ->SetBinError(j,sqrt(w05*w05*ZToNuNu_5_CS2 ->GetBinContent(j)));}else{ZToNuNu_5_CS2 ->SetBinError(j,0);}//w05);}
	if(ZToNuNu_6_CS2 ->GetBinContent(j)>0){ZToNuNu_6_CS2 ->SetBinError(j,sqrt(w06*w06*ZToNuNu_6_CS2 ->GetBinContent(j)));}else{ZToNuNu_6_CS2 ->SetBinError(j,0);}//w06);}
	if(ZToNuNu_7_CS2 ->GetBinContent(j)>0){ZToNuNu_7_CS2 ->SetBinError(j,sqrt(w07*w07*ZToNuNu_7_CS2 ->GetBinContent(j)));}else{ZToNuNu_7_CS2 ->SetBinError(j,0);}//w07);}
	if(QCD_1_CS2->GetBinContent(j)>0){QCD_1_CS2 ->SetBinError(j,sqrt(w08*w08*QCD_1_CS2 ->GetBinContent(j)));}else{QCD_1_CS2 ->SetBinError(j,0);}//w08);}
    if(QCD_2_CS2->GetBinContent(j)>0){QCD_2_CS2 ->SetBinError(j,sqrt(w09*w09*QCD_2_CS2 ->GetBinContent(j)));}else{QCD_2_CS2 ->SetBinError(j,0);}//w09);}
    if(QCD_3_CS2->GetBinContent(j)>0){QCD_3_CS2 ->SetBinError(j,sqrt(w10*w10*QCD_3_CS2 ->GetBinContent(j)));}else{QCD_3_CS2 ->SetBinError(j,0);}//w10);}
	if(QCD_4_CS2->GetBinContent(j)>0){QCD_4_CS2 ->SetBinError(j,sqrt(w11*w11*QCD_4_CS2 ->GetBinContent(j)));}else{QCD_4_CS2 ->SetBinError(j,0);}//w11);}
    if(QCD_5_CS2->GetBinContent(j)>0){QCD_5_CS2 ->SetBinError(j,sqrt(w12*w12*QCD_5_CS2 ->GetBinContent(j)));}else{QCD_5_CS2 ->SetBinError(j,0);}//w12);}
    if(QCD_6_CS2->GetBinContent(j)>0){QCD_6_CS2 ->SetBinError(j,sqrt(w13*w13*QCD_6_CS2 ->GetBinContent(j)));}else{QCD_6_CS2 ->SetBinError(j,0);}//w13);}
    if(QCD_7_CS2->GetBinContent(j)>0){QCD_7_CS2 ->SetBinError(j,sqrt(w14*w14*QCD_7_CS2 ->GetBinContent(j)));}else{QCD_7_CS2 ->SetBinError(j,0);}//w14);}
    if(WToLNu_1_CS2->GetBinContent(j)>0){WToLNu_1_CS2->SetBinError(j,sqrt(w15*w15*WToLNu_1_CS2->GetBinContent(j)));}else{WToLNu_1_CS2->SetBinError(j,0);}//w15);}
	if(WToLNu_2_CS2->GetBinContent(j)>0){WToLNu_2_CS2->SetBinError(j,sqrt(w16*w16*WToLNu_2_CS2->GetBinContent(j)));}else{WToLNu_2_CS2->SetBinError(j,0);}//w16);}
	if(WToLNu_3_CS2->GetBinContent(j)>0){WToLNu_3_CS2->SetBinError(j,sqrt(w17*w17*WToLNu_3_CS2->GetBinContent(j)));}else{WToLNu_3_CS2->SetBinError(j,0);}//w17);}
	if(WToLNu_4_CS2->GetBinContent(j)>0){WToLNu_4_CS2->SetBinError(j,sqrt(w18*w18*WToLNu_4_CS2->GetBinContent(j)));}else{WToLNu_4_CS2->SetBinError(j,0);}//w18);}
	if(WToLNu_5_CS2->GetBinContent(j)>0){WToLNu_5_CS2->SetBinError(j,sqrt(w19*w19*WToLNu_5_CS2->GetBinContent(j)));}else{WToLNu_5_CS2->SetBinError(j,0);}//w19);}
	if(WToLNu_6_CS2->GetBinContent(j)>0){WToLNu_6_CS2->SetBinError(j,sqrt(w20*w20*WToLNu_6_CS2->GetBinContent(j)));}else{WToLNu_6_CS2->SetBinError(j,0);}//w20);}
	if(WToLNu_7_CS2->GetBinContent(j)>0){WToLNu_7_CS2->SetBinError(j,sqrt(w21*w21*WToLNu_7_CS2->GetBinContent(j)));}else{WToLNu_7_CS2->SetBinError(j,0);}//w21);}
	if(TT_1_CS2->GetBinContent(j)>0){TT_1_CS2->SetBinError(j,sqrt(w22*w22*TT_1_CS2->GetBinContent(j)));}else{TT_1_CS2->SetBinError(j,0);}//w22);}
	if(TT_2_CS2->GetBinContent(j)>0){TT_2_CS2->SetBinError(j,sqrt(w23*w23*TT_2_CS2->GetBinContent(j)));}else{TT_2_CS2->SetBinError(j,0);}//w23);}
    if(ST_1_CS2->GetBinContent(j)>0){ST_1_CS2->SetBinError(j,sqrt(w24*w24*ST_1_CS2->GetBinContent(j)));}else{ST_1_CS2->SetBinError(j,0);}//w24);}
    if(ST_2_CS2->GetBinContent(j)>0){ST_2_CS2->SetBinError(j,sqrt(w25*w25*ST_2_CS2->GetBinContent(j)));}else{ST_2_CS2->SetBinError(j,0);}//w25);}
    if(ST_3_CS2->GetBinContent(j)>0){ST_3_CS2->SetBinError(j,sqrt(w26*w26*ST_3_CS2->GetBinContent(j)));}else{ST_3_CS2->SetBinError(j,0);}//w26);}
    if(ST_4_CS2->GetBinContent(j)>0){ST_4_CS2->SetBinError(j,sqrt(w27*w27*ST_4_CS2->GetBinContent(j)));}else{ST_4_CS2->SetBinError(j,0);}//w27);}
    if(ZZ1_CS2->GetBinContent(j)>0){ZZ1_CS2->SetBinError(j,sqrt(w28*w28*ZZ1_CS2->GetBinContent(j)));}else{ZZ1_CS2->SetBinError(j,0);}//w28);}
	if(ZZ2_CS2->GetBinContent(j)>0){ZZ2_CS2->SetBinError(j,sqrt(w29*w29*ZZ2_CS2->GetBinContent(j)));}else{ZZ2_CS2->SetBinError(j,0);}//w29);}
	if(ZZ3_CS2->GetBinContent(j)>0){ZZ3_CS2->SetBinError(j,sqrt(w30*w30*ZZ3_CS2->GetBinContent(j)));}else{ZZ3_CS2->SetBinError(j,0);}//w30);}
    if(WW1_CS2->GetBinContent(j)>0){WW1_CS2->SetBinError(j,sqrt(w31*w31*WW1_CS2->GetBinContent(j)));}else{WW1_CS2->SetBinError(j,0);}//w31);}
	if(WW2_CS2->GetBinContent(j)>0){WW2_CS2->SetBinError(j,sqrt(w32*w32*WW2_CS2->GetBinContent(j)));}else{WW2_CS2->SetBinError(j,0);}//w32);}
	if(WZ1_CS2->GetBinContent(j)>0){WZ1_CS2->SetBinError(j,sqrt(w33*w33*WZ1_CS2->GetBinContent(j)));}else{WZ1_CS2->SetBinError(j,0);}//w33);}
	if(WZ2_CS2->GetBinContent(j)>0){WZ2_CS2->SetBinError(j,sqrt(w34*w34*WZ2_CS2->GetBinContent(j)));}else{WZ2_CS2->SetBinError(j,0);}//w34);}
	if(WZ3_CS2->GetBinContent(j)>0){WZ3_CS2->SetBinError(j,sqrt(w35*w35*WZ3_CS2->GetBinContent(j)));}else{WZ3_CS2->SetBinError(j,0);}//w35);}

	if(tptzm0700lh_CS3->GetBinContent(j)>0){tptzm0700lh_CS3->SetBinError(j,sqrt(w0700*w0700*tptzm0700lh_CS3->GetBinContent(j)));}else{tptzm0700lh_CS3->SetBinError(j,0);}
    if(tptzm0900lh_CS3->GetBinContent(j)>0){tptzm0900lh_CS3->SetBinError(j,sqrt(w0900*w0900*tptzm0900lh_CS3->GetBinContent(j)));}else{tptzm0900lh_CS3->SetBinError(j,0);}
    if(tptzm1400lh_CS3->GetBinContent(j)>0){tptzm1400lh_CS3->SetBinError(j,sqrt(w1400*w1400*tptzm1400lh_CS3->GetBinContent(j)));}else{tptzm1400lh_CS3->SetBinError(j,0);}
    if(tptzm1700lh_CS3->GetBinContent(j)>0){tptzm1700lh_CS3->SetBinError(j,sqrt(w1700*w1700*tptzm1700lh_CS3->GetBinContent(j)));}else{tptzm1700lh_CS3->SetBinError(j,0);}
    if(ZToNuNu_1_CS3 ->GetBinContent(j)>0){ZToNuNu_1_CS3 ->SetBinError(j,sqrt(w01*w01*ZToNuNu_1_CS3 ->GetBinContent(j)));}else{ZToNuNu_1_CS3 ->SetBinError(j,0);}//w01);}
    if(ZToNuNu_2_CS3 ->GetBinContent(j)>0){ZToNuNu_2_CS3 ->SetBinError(j,sqrt(w02*w02*ZToNuNu_2_CS3 ->GetBinContent(j)));}else{ZToNuNu_2_CS3 ->SetBinError(j,0);}//w02);}
    if(ZToNuNu_3_CS3 ->GetBinContent(j)>0){ZToNuNu_3_CS3 ->SetBinError(j,sqrt(w03*w03*ZToNuNu_3_CS3 ->GetBinContent(j)));}else{ZToNuNu_3_CS3 ->SetBinError(j,0);}//w03);}
    if(ZToNuNu_4_CS3 ->GetBinContent(j)>0){ZToNuNu_4_CS3 ->SetBinError(j,sqrt(w04*w04*ZToNuNu_4_CS3 ->GetBinContent(j)));}else{ZToNuNu_4_CS3 ->SetBinError(j,0);}//w04);}
	if(ZToNuNu_5_CS3 ->GetBinContent(j)>0){ZToNuNu_5_CS3 ->SetBinError(j,sqrt(w05*w05*ZToNuNu_5_CS3 ->GetBinContent(j)));}else{ZToNuNu_5_CS3 ->SetBinError(j,0);}//w05);}
	if(ZToNuNu_6_CS3 ->GetBinContent(j)>0){ZToNuNu_6_CS3 ->SetBinError(j,sqrt(w06*w06*ZToNuNu_6_CS3 ->GetBinContent(j)));}else{ZToNuNu_6_CS3 ->SetBinError(j,0);}//w06);}
	if(ZToNuNu_7_CS3 ->GetBinContent(j)>0){ZToNuNu_7_CS3 ->SetBinError(j,sqrt(w07*w07*ZToNuNu_7_CS3 ->GetBinContent(j)));}else{ZToNuNu_7_CS3 ->SetBinError(j,0);}//w07);}
	if(QCD_1_CS3->GetBinContent(j)>0){QCD_1_CS3 ->SetBinError(j,sqrt(w08*w08*QCD_1_CS3 ->GetBinContent(j)));}else{QCD_1_CS3 ->SetBinError(j,0);}//w08);}
    if(QCD_2_CS3->GetBinContent(j)>0){QCD_2_CS3 ->SetBinError(j,sqrt(w09*w09*QCD_2_CS3 ->GetBinContent(j)));}else{QCD_2_CS3 ->SetBinError(j,0);}//w09);}
    if(QCD_3_CS3->GetBinContent(j)>0){QCD_3_CS3 ->SetBinError(j,sqrt(w10*w10*QCD_3_CS3 ->GetBinContent(j)));}else{QCD_3_CS3 ->SetBinError(j,0);}//w10);}
	if(QCD_4_CS3->GetBinContent(j)>0){QCD_4_CS3 ->SetBinError(j,sqrt(w11*w11*QCD_4_CS3 ->GetBinContent(j)));}else{QCD_4_CS3 ->SetBinError(j,0);}//w11);}
    if(QCD_5_CS3->GetBinContent(j)>0){QCD_5_CS3 ->SetBinError(j,sqrt(w12*w12*QCD_5_CS3 ->GetBinContent(j)));}else{QCD_5_CS3 ->SetBinError(j,0);}//w12);}
    if(QCD_6_CS3->GetBinContent(j)>0){QCD_6_CS3 ->SetBinError(j,sqrt(w13*w13*QCD_6_CS3 ->GetBinContent(j)));}else{QCD_6_CS3 ->SetBinError(j,0);}//w13);}
    if(QCD_7_CS3->GetBinContent(j)>0){QCD_7_CS3 ->SetBinError(j,sqrt(w14*w14*QCD_7_CS3 ->GetBinContent(j)));}else{QCD_7_CS3 ->SetBinError(j,0);}//w14);}
    if(WToLNu_1_CS3->GetBinContent(j)>0){WToLNu_1_CS3->SetBinError(j,sqrt(w15*w15*WToLNu_1_CS3->GetBinContent(j)));}else{WToLNu_1_CS3->SetBinError(j,0);}//w15);}
	if(WToLNu_2_CS3->GetBinContent(j)>0){WToLNu_2_CS3->SetBinError(j,sqrt(w16*w16*WToLNu_2_CS3->GetBinContent(j)));}else{WToLNu_2_CS3->SetBinError(j,0);}//w16);}
	if(WToLNu_3_CS3->GetBinContent(j)>0){WToLNu_3_CS3->SetBinError(j,sqrt(w17*w17*WToLNu_3_CS3->GetBinContent(j)));}else{WToLNu_3_CS3->SetBinError(j,0);}//w17);}
	if(WToLNu_4_CS3->GetBinContent(j)>0){WToLNu_4_CS3->SetBinError(j,sqrt(w18*w18*WToLNu_4_CS3->GetBinContent(j)));}else{WToLNu_4_CS3->SetBinError(j,0);}//w18);}
	if(WToLNu_5_CS3->GetBinContent(j)>0){WToLNu_5_CS3->SetBinError(j,sqrt(w19*w19*WToLNu_5_CS3->GetBinContent(j)));}else{WToLNu_5_CS3->SetBinError(j,0);}//w19);}
	if(WToLNu_6_CS3->GetBinContent(j)>0){WToLNu_6_CS3->SetBinError(j,sqrt(w20*w20*WToLNu_6_CS3->GetBinContent(j)));}else{WToLNu_6_CS3->SetBinError(j,0);}//w20);}
	if(WToLNu_7_CS3->GetBinContent(j)>0){WToLNu_7_CS3->SetBinError(j,sqrt(w21*w21*WToLNu_7_CS3->GetBinContent(j)));}else{WToLNu_7_CS3->SetBinError(j,0);}//w21);}
	if(TT_1_CS3->GetBinContent(j)>0){TT_1_CS3->SetBinError(j,sqrt(w22*w22*TT_1_CS3->GetBinContent(j)));}else{TT_1_CS3->SetBinError(j,0);}//w22);}
	if(TT_2_CS3->GetBinContent(j)>0){TT_2_CS3->SetBinError(j,sqrt(w23*w23*TT_2_CS3->GetBinContent(j)));}else{TT_2_CS3->SetBinError(j,0);}//w23);}
    if(ST_1_CS3->GetBinContent(j)>0){ST_1_CS3->SetBinError(j,sqrt(w24*w24*ST_1_CS3->GetBinContent(j)));}else{ST_1_CS3->SetBinError(j,0);}//w24);}
    if(ST_2_CS3->GetBinContent(j)>0){ST_2_CS3->SetBinError(j,sqrt(w25*w25*ST_2_CS3->GetBinContent(j)));}else{ST_2_CS3->SetBinError(j,0);}//w25);}
    if(ST_3_CS3->GetBinContent(j)>0){ST_3_CS3->SetBinError(j,sqrt(w26*w26*ST_3_CS3->GetBinContent(j)));}else{ST_3_CS3->SetBinError(j,0);}//w26);}
    if(ST_4_CS3->GetBinContent(j)>0){ST_4_CS3->SetBinError(j,sqrt(w27*w27*ST_4_CS3->GetBinContent(j)));}else{ST_4_CS3->SetBinError(j,0);}//w27);}
    if(ZZ1_CS3->GetBinContent(j)>0){ZZ1_CS3->SetBinError(j,sqrt(w28*w28*ZZ1_CS3->GetBinContent(j)));}else{ZZ1_CS3->SetBinError(j,0);}//w28);}
	if(ZZ2_CS3->GetBinContent(j)>0){ZZ2_CS3->SetBinError(j,sqrt(w29*w29*ZZ2_CS3->GetBinContent(j)));}else{ZZ2_CS3->SetBinError(j,0);}//w29);}
	if(ZZ3_CS3->GetBinContent(j)>0){ZZ3_CS3->SetBinError(j,sqrt(w30*w30*ZZ3_CS3->GetBinContent(j)));}else{ZZ3_CS3->SetBinError(j,0);}//w30);}
    if(WW1_CS3->GetBinContent(j)>0){WW1_CS3->SetBinError(j,sqrt(w31*w31*WW1_CS3->GetBinContent(j)));}else{WW1_CS3->SetBinError(j,0);}//w31);}
	if(WW2_CS3->GetBinContent(j)>0){WW2_CS3->SetBinError(j,sqrt(w32*w32*WW2_CS3->GetBinContent(j)));}else{WW2_CS3->SetBinError(j,0);}//w32);}
	if(WZ1_CS3->GetBinContent(j)>0){WZ1_CS3->SetBinError(j,sqrt(w33*w33*WZ1_CS3->GetBinContent(j)));}else{WZ1_CS3->SetBinError(j,0);}//w33);}
	if(WZ2_CS3->GetBinContent(j)>0){WZ2_CS3->SetBinError(j,sqrt(w34*w34*WZ2_CS3->GetBinContent(j)));}else{WZ2_CS3->SetBinError(j,0);}//w34);}
	if(WZ3_CS3->GetBinContent(j)>0){WZ3_CS3->SetBinError(j,sqrt(w35*w35*WZ3_CS3->GetBinContent(j)));}else{WZ3_CS3->SetBinError(j,0);}//w35);}
	

    double N_data_SR_err    = data->GetBinError(j)*data->GetBinError(j);
    double N_ZToNuNu_SR_err = ZToNuNu_1->GetBinError(j)*ZToNuNu_1->GetBinError(j) + ZToNuNu_2->GetBinError(j)*ZToNuNu_2->GetBinError(j) + ZToNuNu_3->GetBinError(j)*ZToNuNu_3->GetBinError(j) + ZToNuNu_4->GetBinError(j)*ZToNuNu_4->GetBinError(j) + ZToNuNu_5->GetBinError(j)*ZToNuNu_5->GetBinError(j) + ZToNuNu_6->GetBinError(j)*ZToNuNu_6->GetBinError(j) + ZToNuNu_7->GetBinError(j)*ZToNuNu_7->GetBinError(j);
    double N_QCD_SR_err     = QCD_1->GetBinError(j)*QCD_1->GetBinError(j) + QCD_2->GetBinError(j)*QCD_2->GetBinError(j) + QCD_3->GetBinError(j)*QCD_3->GetBinError(j) + QCD_4->GetBinError(j)*QCD_4->GetBinError(j) + QCD_5->GetBinError(j)*QCD_5->GetBinError(j) + QCD_6->GetBinError(j)*QCD_6->GetBinError(j) + QCD_7->GetBinError(j)*QCD_7->GetBinError(j);
    double N_WToLNu_SR_err  = WToLNu_1->GetBinError(j)*WToLNu_1->GetBinError(j)+WToLNu_2->GetBinError(j)*WToLNu_2->GetBinError(j)+WToLNu_3->GetBinError(j)*WToLNu_3->GetBinError(j)+WToLNu_4->GetBinError(j)*WToLNu_4->GetBinError(j)+WToLNu_5->GetBinError(j)*WToLNu_5->GetBinError(j)+WToLNu_6->GetBinError(j)*WToLNu_6->GetBinError(j)+WToLNu_7->GetBinError(j)*WToLNu_7->GetBinError(j);
	double N_TT_SR_err      = TT_1->GetBinError(j)*TT_1->GetBinError(j)+TT_2->GetBinError(j)*TT_2->GetBinError(j);
	double N_ST_SR_err      = ST_1->GetBinError(j)*ST_1->GetBinError(j) + ST_2->GetBinError(j)*ST_2->GetBinError(j)+ ST_3->GetBinError(j)*ST_3->GetBinError(j)+ ST_4->GetBinError(j)*ST_4->GetBinError(j);
    double N_VV_SR_err      = ZZ1->GetBinError(j)*ZZ1->GetBinError(j) + ZZ2->GetBinError(j)*ZZ2->GetBinError(j) + ZZ3->GetBinError(j)*ZZ3->GetBinError(j) + WW1->GetBinError(j)*WW1->GetBinError(j) + WW2->GetBinError(j)*WW2->GetBinError(j) + WZ1->GetBinError(j)*WZ1->GetBinError(j) + WZ2->GetBinError(j)*WZ2->GetBinError(j) + WZ3->GetBinError(j)*WZ3->GetBinError(j); 

	double N_data_CS1_err   = data_CS1->GetBinError(j)*data_CS1->GetBinError(j);
    double N_ZToNuNu_CS1_err= ZToNuNu_1_CS1->GetBinError(j)*ZToNuNu_1_CS1->GetBinError(j) + ZToNuNu_2_CS1->GetBinError(j)*ZToNuNu_2_CS1->GetBinError(j) + ZToNuNu_3_CS1->GetBinError(j)*ZToNuNu_3_CS1->GetBinError(j) + ZToNuNu_4_CS1->GetBinError(j)*ZToNuNu_4_CS1->GetBinError(j) + ZToNuNu_5_CS1->GetBinError(j)*ZToNuNu_5_CS1->GetBinError(j) + ZToNuNu_6_CS1->GetBinError(j)*ZToNuNu_6_CS1->GetBinError(j) + ZToNuNu_7_CS1->GetBinError(j)*ZToNuNu_7_CS1->GetBinError(j);
    double N_QCD_CS1_err    = QCD_1_CS1->GetBinError(j)*QCD_1_CS1->GetBinError(j) + QCD_2_CS1->GetBinError(j)*QCD_2_CS1->GetBinError(j) + QCD_3_CS1->GetBinError(j)*QCD_3_CS1->GetBinError(j) + QCD_4_CS1->GetBinError(j)*QCD_4_CS1->GetBinError(j) + QCD_5_CS1->GetBinError(j)*QCD_5_CS1->GetBinError(j) + QCD_6_CS1->GetBinError(j)*QCD_6_CS1->GetBinError(j) + QCD_7_CS1->GetBinError(j)*QCD_7_CS1->GetBinError(j);
	double N_WToLNu_CS1_err = WToLNu_1_CS1->GetBinError(j)*WToLNu_1_CS1->GetBinError(j)+WToLNu_2_CS1->GetBinError(j)*WToLNu_2_CS1->GetBinError(j)+WToLNu_3_CS1->GetBinError(j)*WToLNu_3_CS1->GetBinError(j)+WToLNu_4_CS1->GetBinError(j)*WToLNu_4_CS1->GetBinError(j)+WToLNu_5_CS1->GetBinError(j)*WToLNu_5_CS1->GetBinError(j)+WToLNu_6_CS1->GetBinError(j)*WToLNu_6_CS1->GetBinError(j)+WToLNu_7_CS1->GetBinError(j)*WToLNu_7_CS1->GetBinError(j);
	double N_TT_CS1_err     = TT_1_CS1->GetBinError(j)*TT_1_CS1->GetBinError(j)+TT_2_CS1->GetBinError(j)*TT_2_CS1->GetBinError(j);
	double N_ST_CS1_err     = ST_1_CS1->GetBinError(j)*ST_1_CS1->GetBinError(j) + ST_2_CS1->GetBinError(j)*ST_2_CS1->GetBinError(j)+ ST_3_CS1->GetBinError(j)*ST_3_CS1->GetBinError(j)+ ST_4_CS1->GetBinError(j)*ST_4_CS1->GetBinError(j);
    double N_VV_CS1_err     = ZZ1_CS1->GetBinError(j)*ZZ1_CS1->GetBinError(j) + ZZ2_CS1->GetBinError(j)*ZZ2_CS1->GetBinError(j) + ZZ3_CS1->GetBinError(j)*ZZ3_CS1->GetBinError(j) + WW1_CS1->GetBinError(j)*WW1_CS1->GetBinError(j) + WW2_CS1->GetBinError(j)*WW2_CS1->GetBinError(j) + WZ1_CS1->GetBinError(j)*WZ1_CS1->GetBinError(j) + WZ2_CS1->GetBinError(j)*WZ2_CS1->GetBinError(j) + WZ3_CS1->GetBinError(j)*WZ3_CS1->GetBinError(j); 
	

	double N_data_CS2_err   = data_CS2->GetBinError(j)*data_CS2->GetBinError(j);
    double N_ZToNuNu_CS2_err= ZToNuNu_1_CS2->GetBinError(j)*ZToNuNu_1_CS2->GetBinError(j) + ZToNuNu_2_CS2->GetBinError(j)*ZToNuNu_2_CS2->GetBinError(j) + ZToNuNu_3_CS2->GetBinError(j)*ZToNuNu_3_CS2->GetBinError(j) + ZToNuNu_4_CS2->GetBinError(j)*ZToNuNu_4_CS2->GetBinError(j) + ZToNuNu_5_CS2->GetBinError(j)*ZToNuNu_5_CS2->GetBinError(j) + ZToNuNu_6_CS2->GetBinError(j)*ZToNuNu_6_CS2->GetBinError(j) + ZToNuNu_7_CS2->GetBinError(j)*ZToNuNu_7_CS2->GetBinError(j);
    double N_QCD_CS2_err    = QCD_1_CS2->GetBinError(j)*QCD_1_CS2->GetBinError(j) + QCD_2_CS2->GetBinError(j)*QCD_2_CS2->GetBinError(j) + QCD_3_CS2->GetBinError(j)*QCD_3_CS2->GetBinError(j) + QCD_4_CS2->GetBinError(j)*QCD_4_CS2->GetBinError(j) + QCD_5_CS2->GetBinError(j)*QCD_5_CS2->GetBinError(j) + QCD_6_CS2->GetBinError(j)*QCD_6_CS2->GetBinError(j) + QCD_7_CS2->GetBinError(j)*QCD_7_CS2->GetBinError(j);
	double N_WToLNu_CS2_err = WToLNu_1_CS2->GetBinError(j)*WToLNu_1_CS2->GetBinError(j)+WToLNu_2_CS2->GetBinError(j)*WToLNu_2_CS2->GetBinError(j)+WToLNu_3_CS2->GetBinError(j)*WToLNu_3_CS2->GetBinError(j)+WToLNu_4_CS2->GetBinError(j)*WToLNu_4_CS2->GetBinError(j)+WToLNu_5_CS2->GetBinError(j)*WToLNu_5_CS2->GetBinError(j)+WToLNu_6_CS2->GetBinError(j)*WToLNu_6_CS2->GetBinError(j)+WToLNu_7_CS2->GetBinError(j)*WToLNu_7_CS2->GetBinError(j);
	double N_TT_CS2_err     = TT_1_CS2->GetBinError(j)*TT_1_CS2->GetBinError(j)+TT_2_CS2->GetBinError(j)*TT_2_CS2->GetBinError(j);
	double N_ST_CS2_err     = ST_1_CS2->GetBinError(j)*ST_1_CS2->GetBinError(j) + ST_2_CS2->GetBinError(j)*ST_2_CS2->GetBinError(j)+ ST_3_CS2->GetBinError(j)*ST_3_CS2->GetBinError(j)+ ST_4_CS2->GetBinError(j)*ST_4_CS2->GetBinError(j);
    double N_VV_CS2_err     = ZZ1_CS2->GetBinError(j)*ZZ1_CS2->GetBinError(j) + ZZ2_CS2->GetBinError(j)*ZZ2_CS2->GetBinError(j) + ZZ3_CS2->GetBinError(j)*ZZ3_CS2->GetBinError(j) + WW1_CS2->GetBinError(j)*WW1_CS2->GetBinError(j) + WW2_CS2->GetBinError(j)*WW2_CS2->GetBinError(j) + WZ1_CS2->GetBinError(j)*WZ1_CS2->GetBinError(j) + WZ2_CS2->GetBinError(j)*WZ2_CS2->GetBinError(j) + WZ3_CS2->GetBinError(j)*WZ3_CS2->GetBinError(j);  
    

	double N_data_CS3_err   = data_CS3->GetBinError(j)*data_CS3->GetBinError(j);
    double N_ZToNuNu_CS3_err= ZToNuNu_1_CS3->GetBinError(j)*ZToNuNu_1_CS3->GetBinError(j) + ZToNuNu_2_CS3->GetBinError(j)*ZToNuNu_2_CS3->GetBinError(j) + ZToNuNu_3_CS3->GetBinError(j)*ZToNuNu_3_CS3->GetBinError(j) + ZToNuNu_4_CS3->GetBinError(j)*ZToNuNu_4_CS3->GetBinError(j) + ZToNuNu_5_CS3->GetBinError(j)*ZToNuNu_5_CS3->GetBinError(j) + ZToNuNu_6_CS3->GetBinError(j)*ZToNuNu_6_CS3->GetBinError(j) + ZToNuNu_7_CS3->GetBinError(j)*ZToNuNu_7_CS3->GetBinError(j);
    double N_QCD_CS3_err    = QCD_1_CS3->GetBinError(j)*QCD_1_CS3->GetBinError(j) + QCD_2_CS3->GetBinError(j)*QCD_2_CS3->GetBinError(j) + QCD_3_CS3->GetBinError(j)*QCD_3_CS3->GetBinError(j) + QCD_4_CS3->GetBinError(j)*QCD_4_CS3->GetBinError(j) + QCD_5_CS3->GetBinError(j)*QCD_5_CS3->GetBinError(j) + QCD_6_CS3->GetBinError(j)*QCD_6_CS3->GetBinError(j) + QCD_7_CS3->GetBinError(j)*QCD_7_CS3->GetBinError(j);
	double N_WToLNu_CS3_err = WToLNu_1_CS3->GetBinError(j)*WToLNu_1_CS3->GetBinError(j)+WToLNu_2_CS3->GetBinError(j)*WToLNu_2_CS3->GetBinError(j)+WToLNu_3_CS3->GetBinError(j)*WToLNu_3_CS3->GetBinError(j)+WToLNu_4_CS3->GetBinError(j)*WToLNu_4_CS3->GetBinError(j)+WToLNu_5_CS3->GetBinError(j)*WToLNu_5_CS3->GetBinError(j)+WToLNu_6_CS3->GetBinError(j)*WToLNu_6_CS3->GetBinError(j)+WToLNu_7_CS3->GetBinError(j)*WToLNu_7_CS3->GetBinError(j);
	double N_TT_CS3_err     = TT_1_CS3->GetBinError(j)*TT_1_CS3->GetBinError(j)+TT_2_CS3->GetBinError(j)*TT_2_CS3->GetBinError(j);
	double N_ST_CS3_err     = ST_1_CS3->GetBinError(j)*ST_1_CS3->GetBinError(j) + ST_2_CS3->GetBinError(j)*ST_2_CS3->GetBinError(j)+ ST_3_CS3->GetBinError(j)*ST_3_CS3->GetBinError(j)+ ST_4_CS3->GetBinError(j)*ST_4_CS3->GetBinError(j);
    double N_VV_CS3_err     = ZZ1_CS3->GetBinError(j)*ZZ1_CS3->GetBinError(j) + ZZ2_CS3->GetBinError(j)*ZZ2_CS3->GetBinError(j) + ZZ3_CS3->GetBinError(j)*ZZ3_CS3->GetBinError(j) + WW1_CS3->GetBinError(j)*WW1_CS3->GetBinError(j) + WW2_CS3->GetBinError(j)*WW2_CS3->GetBinError(j) + WZ1_CS3->GetBinError(j)*WZ1_CS3->GetBinError(j) + WZ2_CS3->GetBinError(j)*WZ2_CS3->GetBinError(j) + WZ3_CS3->GetBinError(j)*WZ3_CS3->GetBinError(j); 
   

	//background->SetBinError(j,sqrt(err01+err02+err03+err04+err05+err06));
	//background->SetBinError(j,sqrt(err01+err02+err04+err05+err06+err07));
	
    tptzm0700lh->SetBinContent(j,w0700*tptzm0700lh->GetBinContent(j));
    tptzm0900lh->SetBinContent(j,w0900*tptzm0900lh->GetBinContent(j));
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
    WToLNu_1->SetBinContent(j,w15*WToLNu_1->GetBinContent(j));
	WToLNu_2->SetBinContent(j,w16*WToLNu_2->GetBinContent(j));
	WToLNu_3->SetBinContent(j,w17*WToLNu_3->GetBinContent(j));
	WToLNu_4->SetBinContent(j,w18*WToLNu_4->GetBinContent(j));
	WToLNu_5->SetBinContent(j,w19*WToLNu_5->GetBinContent(j));
	WToLNu_6->SetBinContent(j,w20*WToLNu_6->GetBinContent(j));
	WToLNu_7->SetBinContent(j,w21*WToLNu_7->GetBinContent(j));
    TT_1->SetBinContent(j,w22*TT_1->GetBinContent(j));
	TT_2->SetBinContent(j,w23*TT_2->GetBinContent(j));
    ST_1->SetBinContent(j,w24*ST_1->GetBinContent(j));
    ST_2->SetBinContent(j,w25*ST_2->GetBinContent(j));
    ST_3->SetBinContent(j,w26*ST_3->GetBinContent(j));
    ST_4->SetBinContent(j,w27*ST_4->GetBinContent(j));
    ZZ1->SetBinContent(j,w28*ZZ1->GetBinContent(j));
    ZZ2->SetBinContent(j,w29*ZZ2->GetBinContent(j));
    ZZ3->SetBinContent(j,w30*ZZ3->GetBinContent(j));
    WW1->SetBinContent(j,w31*WW1->GetBinContent(j));
    WW2->SetBinContent(j,w32*WW2->GetBinContent(j));
    WZ1->SetBinContent(j,w33*WZ1->GetBinContent(j));
    WZ2->SetBinContent(j,w34*WZ2->GetBinContent(j));
    WZ3->SetBinContent(j,w35*WZ3->GetBinContent(j));


	tptzm0700lh_CS1->SetBinContent(j,w0700*tptzm0700lh_CS1->GetBinContent(j));
    tptzm0900lh_CS1->SetBinContent(j,w0900*tptzm0900lh_CS1->GetBinContent(j));
    tptzm1400lh_CS1->SetBinContent(j,w1400*tptzm1400lh_CS1->GetBinContent(j));
    tptzm1700lh_CS1->SetBinContent(j,w1700*tptzm1700lh_CS1->GetBinContent(j));
    ZToNuNu_1_CS1->SetBinContent(j,w01*ZToNuNu_1_CS1->GetBinContent(j));
    ZToNuNu_2_CS1->SetBinContent(j,w02*ZToNuNu_2_CS1->GetBinContent(j));
    ZToNuNu_3_CS1->SetBinContent(j,w03*ZToNuNu_3_CS1->GetBinContent(j));
    ZToNuNu_4_CS1->SetBinContent(j,w04*ZToNuNu_4_CS1->GetBinContent(j));
	ZToNuNu_5_CS1->SetBinContent(j,w05*ZToNuNu_5_CS1->GetBinContent(j));
	ZToNuNu_6_CS1->SetBinContent(j,w06*ZToNuNu_6_CS1->GetBinContent(j));
	ZToNuNu_7_CS1->SetBinContent(j,w07*ZToNuNu_7_CS1->GetBinContent(j));
    QCD_1_CS1->SetBinContent(j,w08*QCD_1_CS1->GetBinContent(j));
    QCD_2_CS1->SetBinContent(j,w09*QCD_2_CS1->GetBinContent(j));
    QCD_3_CS1->SetBinContent(j,w10*QCD_3_CS1->GetBinContent(j));
	QCD_4_CS1->SetBinContent(j,w11*QCD_4_CS1->GetBinContent(j));
    QCD_5_CS1->SetBinContent(j,w12*QCD_5_CS1->GetBinContent(j));
    QCD_6_CS1->SetBinContent(j,w13*QCD_6_CS1->GetBinContent(j));
    QCD_7_CS1->SetBinContent(j,w14*QCD_7_CS1->GetBinContent(j));
    WToLNu_1_CS1->SetBinContent(j,w15*WToLNu_1_CS1->GetBinContent(j));
	WToLNu_2_CS1->SetBinContent(j,w16*WToLNu_2_CS1->GetBinContent(j));
	WToLNu_3_CS1->SetBinContent(j,w17*WToLNu_3_CS1->GetBinContent(j));
	WToLNu_4_CS1->SetBinContent(j,w18*WToLNu_4_CS1->GetBinContent(j));
	WToLNu_5_CS1->SetBinContent(j,w19*WToLNu_5_CS1->GetBinContent(j));
	WToLNu_6_CS1->SetBinContent(j,w20*WToLNu_6_CS1->GetBinContent(j));
	WToLNu_7_CS1->SetBinContent(j,w21*WToLNu_7_CS1->GetBinContent(j));
    TT_1_CS1->SetBinContent(j,w22*TT_1_CS1->GetBinContent(j));
	TT_2_CS1->SetBinContent(j,w23*TT_2_CS1->GetBinContent(j));
    ST_1_CS1->SetBinContent(j,w24*ST_1_CS1->GetBinContent(j));
    ST_2_CS1->SetBinContent(j,w25*ST_2_CS1->GetBinContent(j));
    ST_3_CS1->SetBinContent(j,w26*ST_3_CS1->GetBinContent(j));
    ST_4_CS1->SetBinContent(j,w27*ST_4_CS1->GetBinContent(j));
    ZZ1_CS1->SetBinContent(j,w28*ZZ1_CS1->GetBinContent(j));
    ZZ2_CS1->SetBinContent(j,w29*ZZ2_CS1->GetBinContent(j));
    ZZ3_CS1->SetBinContent(j,w30*ZZ3_CS1->GetBinContent(j));
    WW1_CS1->SetBinContent(j,w31*WW1_CS1->GetBinContent(j));
    WW2_CS1->SetBinContent(j,w32*WW2_CS1->GetBinContent(j));
    WZ1_CS1->SetBinContent(j,w33*WZ1_CS1->GetBinContent(j));
    WZ2_CS1->SetBinContent(j,w34*WZ2_CS1->GetBinContent(j));
    WZ3_CS1->SetBinContent(j,w35*WZ3_CS1->GetBinContent(j));

	tptzm0700lh_CS2->SetBinContent(j,w0700*tptzm0700lh_CS2->GetBinContent(j));
    tptzm0900lh_CS2->SetBinContent(j,w0900*tptzm0900lh_CS2->GetBinContent(j));
    tptzm1400lh_CS2->SetBinContent(j,w1400*tptzm1400lh_CS2->GetBinContent(j));
    tptzm1700lh_CS2->SetBinContent(j,w1700*tptzm1700lh_CS2->GetBinContent(j));
    ZToNuNu_1_CS2->SetBinContent(j,w01*ZToNuNu_1_CS2->GetBinContent(j));
    ZToNuNu_2_CS2->SetBinContent(j,w02*ZToNuNu_2_CS2->GetBinContent(j));
    ZToNuNu_3_CS2->SetBinContent(j,w03*ZToNuNu_3_CS2->GetBinContent(j));
    ZToNuNu_4_CS2->SetBinContent(j,w04*ZToNuNu_4_CS2->GetBinContent(j));
	ZToNuNu_5_CS2->SetBinContent(j,w05*ZToNuNu_5_CS2->GetBinContent(j));
	ZToNuNu_6_CS2->SetBinContent(j,w06*ZToNuNu_6_CS2->GetBinContent(j));
	ZToNuNu_7_CS2->SetBinContent(j,w07*ZToNuNu_7_CS2->GetBinContent(j));
	QCD_1_CS2->SetBinContent(j,w08*QCD_1_CS2->GetBinContent(j));
    QCD_2_CS2->SetBinContent(j,w09*QCD_2_CS2->GetBinContent(j));
    QCD_3_CS2->SetBinContent(j,w10*QCD_3_CS2->GetBinContent(j));
	QCD_4_CS2->SetBinContent(j,w11*QCD_4_CS2->GetBinContent(j));
    QCD_5_CS2->SetBinContent(j,w12*QCD_5_CS2->GetBinContent(j));
    QCD_6_CS2->SetBinContent(j,w13*QCD_6_CS2->GetBinContent(j));
    QCD_7_CS2->SetBinContent(j,w14*QCD_7_CS2->GetBinContent(j));
    WToLNu_1_CS2->SetBinContent(j,w15*WToLNu_1_CS2->GetBinContent(j));
	WToLNu_2_CS2->SetBinContent(j,w16*WToLNu_2_CS2->GetBinContent(j));
	WToLNu_3_CS2->SetBinContent(j,w17*WToLNu_3_CS2->GetBinContent(j));
	WToLNu_4_CS2->SetBinContent(j,w18*WToLNu_4_CS2->GetBinContent(j));
	WToLNu_5_CS2->SetBinContent(j,w19*WToLNu_5_CS2->GetBinContent(j));
	WToLNu_6_CS2->SetBinContent(j,w20*WToLNu_6_CS2->GetBinContent(j));
	WToLNu_7_CS2->SetBinContent(j,w21*WToLNu_7_CS2->GetBinContent(j));
    TT_1_CS2->SetBinContent(j,w22*TT_1_CS2->GetBinContent(j));
	TT_2_CS2->SetBinContent(j,w23*TT_2_CS2->GetBinContent(j));
    ST_1_CS2->SetBinContent(j,w24*ST_1_CS2->GetBinContent(j));
    ST_2_CS2->SetBinContent(j,w25*ST_2_CS2->GetBinContent(j));
    ST_3_CS2->SetBinContent(j,w26*ST_3_CS2->GetBinContent(j));
    ST_4_CS2->SetBinContent(j,w27*ST_4_CS2->GetBinContent(j));
    ZZ1_CS2->SetBinContent(j,w28*ZZ1_CS2->GetBinContent(j));
    ZZ2_CS2->SetBinContent(j,w29*ZZ2_CS2->GetBinContent(j));
    ZZ3_CS2->SetBinContent(j,w30*ZZ3_CS2->GetBinContent(j));
    WW1_CS2->SetBinContent(j,w31*WW1_CS2->GetBinContent(j));
    WW2_CS2->SetBinContent(j,w32*WW2_CS2->GetBinContent(j));
    WZ1_CS2->SetBinContent(j,w33*WZ1_CS2->GetBinContent(j));
    WZ2_CS2->SetBinContent(j,w34*WZ2_CS2->GetBinContent(j));
    WZ3_CS2->SetBinContent(j,w35*WZ3_CS2->GetBinContent(j));

	tptzm0700lh_CS3->SetBinContent(j,w0700*tptzm0700lh_CS3->GetBinContent(j));
    tptzm0900lh_CS3->SetBinContent(j,w0900*tptzm0900lh_CS3->GetBinContent(j));
    tptzm1400lh_CS3->SetBinContent(j,w1400*tptzm1400lh_CS3->GetBinContent(j));
    tptzm1700lh_CS3->SetBinContent(j,w1700*tptzm1700lh_CS3->GetBinContent(j));
    ZToNuNu_1_CS3->SetBinContent(j,w01*ZToNuNu_1_CS3->GetBinContent(j));
    ZToNuNu_2_CS3->SetBinContent(j,w02*ZToNuNu_2_CS3->GetBinContent(j));
    ZToNuNu_3_CS3->SetBinContent(j,w03*ZToNuNu_3_CS3->GetBinContent(j));
    ZToNuNu_4_CS3->SetBinContent(j,w04*ZToNuNu_4_CS3->GetBinContent(j));
	ZToNuNu_5_CS3->SetBinContent(j,w05*ZToNuNu_5_CS3->GetBinContent(j));
	ZToNuNu_6_CS3->SetBinContent(j,w06*ZToNuNu_6_CS3->GetBinContent(j));
	ZToNuNu_7_CS3->SetBinContent(j,w07*ZToNuNu_7_CS3->GetBinContent(j));
	QCD_1_CS3->SetBinContent(j,w08*QCD_1_CS3->GetBinContent(j));
    QCD_2_CS3->SetBinContent(j,w09*QCD_2_CS3->GetBinContent(j));
    QCD_3_CS3->SetBinContent(j,w10*QCD_3_CS3->GetBinContent(j));
	QCD_4_CS3->SetBinContent(j,w11*QCD_4_CS3->GetBinContent(j));
    QCD_5_CS3->SetBinContent(j,w12*QCD_5_CS3->GetBinContent(j));
    QCD_6_CS3->SetBinContent(j,w13*QCD_6_CS3->GetBinContent(j));
    QCD_7_CS3->SetBinContent(j,w14*QCD_7_CS3->GetBinContent(j));
    WToLNu_1_CS3->SetBinContent(j,w15*WToLNu_1_CS3->GetBinContent(j));
	WToLNu_2_CS3->SetBinContent(j,w16*WToLNu_2_CS3->GetBinContent(j));
	WToLNu_3_CS3->SetBinContent(j,w17*WToLNu_3_CS3->GetBinContent(j));
	WToLNu_4_CS3->SetBinContent(j,w18*WToLNu_4_CS3->GetBinContent(j));
	WToLNu_5_CS3->SetBinContent(j,w19*WToLNu_5_CS3->GetBinContent(j));
	WToLNu_6_CS3->SetBinContent(j,w20*WToLNu_6_CS3->GetBinContent(j));
	WToLNu_7_CS3->SetBinContent(j,w21*WToLNu_7_CS3->GetBinContent(j));
    TT_1_CS3->SetBinContent(j,w22*TT_1_CS3->GetBinContent(j));
	TT_2_CS3->SetBinContent(j,w23*TT_2_CS3->GetBinContent(j));
    ST_1_CS3->SetBinContent(j,w24*ST_1_CS3->GetBinContent(j));
    ST_2_CS3->SetBinContent(j,w25*ST_2_CS3->GetBinContent(j));
    ST_3_CS3->SetBinContent(j,w26*ST_3_CS3->GetBinContent(j));
    ST_4_CS3->SetBinContent(j,w27*ST_4_CS3->GetBinContent(j));
    ZZ1_CS3->SetBinContent(j,w28*ZZ1_CS3->GetBinContent(j));
    ZZ2_CS3->SetBinContent(j,w29*ZZ2_CS3->GetBinContent(j));
    ZZ3_CS3->SetBinContent(j,w30*ZZ3_CS3->GetBinContent(j));
    WW1_CS3->SetBinContent(j,w31*WW1_CS3->GetBinContent(j));
    WW2_CS3->SetBinContent(j,w32*WW2_CS3->GetBinContent(j));
    WZ1_CS3->SetBinContent(j,w33*WZ1_CS3->GetBinContent(j));
    WZ2_CS3->SetBinContent(j,w34*WZ2_CS3->GetBinContent(j));
    WZ3_CS3->SetBinContent(j,w35*WZ3_CS3->GetBinContent(j));
	
    double N_data_SR    = data->GetBinContent(j);
    double N_ZToNuNu_SR = ZToNuNu_1->GetBinContent(j) + ZToNuNu_2->GetBinContent(j) + ZToNuNu_3->GetBinContent(j) + ZToNuNu_4->GetBinContent(j) + ZToNuNu_5->GetBinContent(j) + ZToNuNu_6->GetBinContent(j) + ZToNuNu_7->GetBinContent(j);
    double N_QCD_SR     = QCD_1->GetBinContent(j) + QCD_2->GetBinContent(j) + QCD_3->GetBinContent(j) + QCD_4->GetBinContent(j) + QCD_5->GetBinContent(j) + QCD_6->GetBinContent(j) + QCD_7->GetBinContent(j);
    double N_WToLNu_SR  = WToLNu_1->GetBinContent(j) + WToLNu_2->GetBinContent(j) + WToLNu_3->GetBinContent(j) + WToLNu_4->GetBinContent(j) + WToLNu_5->GetBinContent(j) + WToLNu_6->GetBinContent(j)+ WToLNu_7->GetBinContent(j);
	double N_TT_SR      = TT_1->GetBinContent(j) + TT_2->GetBinContent(j);
    double N_ST_SR      = ST_1 ->GetBinContent(j) + ST_2 ->GetBinContent(j) + ST_3 ->GetBinContent(j) + ST_4 ->GetBinContent(j);
	double N_VV_SR      = ZZ1->GetBinContent(j)+ZZ2->GetBinContent(j)+ZZ3->GetBinContent(j)+WW1->GetBinContent(j)+WW2->GetBinContent(j)+WZ1->GetBinContent(j)+WZ2->GetBinContent(j)+WZ3->GetBinContent(j);

	double N_data_CS1   = data_CS1->GetBinContent(j);
    double N_ZToNuNu_CS1= ZToNuNu_1_CS1->GetBinContent(j) + ZToNuNu_2_CS1->GetBinContent(j) + ZToNuNu_3_CS1->GetBinContent(j) + ZToNuNu_4_CS1->GetBinContent(j) + ZToNuNu_5_CS1->GetBinContent(j) + ZToNuNu_6_CS1->GetBinContent(j) + ZToNuNu_7_CS1->GetBinContent(j);
    double N_QCD_CS1    = QCD_1_CS1->GetBinContent(j) + QCD_2_CS1->GetBinContent(j) + QCD_3_CS1->GetBinContent(j) + QCD_4_CS1->GetBinContent(j) + QCD_5_CS1->GetBinContent(j) + QCD_6_CS1->GetBinContent(j) + QCD_7_CS1->GetBinContent(j);
	double N_WToLNu_CS1 = WToLNu_1_CS1->GetBinContent(j) + WToLNu_2_CS1->GetBinContent(j) + WToLNu_3_CS1->GetBinContent(j) + WToLNu_4_CS1->GetBinContent(j) + WToLNu_5_CS1->GetBinContent(j) + WToLNu_6_CS1->GetBinContent(j)+ WToLNu_7_CS1->GetBinContent(j);
	double N_TT_CS1     = TT_1_CS1->GetBinContent(j) + TT_2_CS1->GetBinContent(j);
    double N_ST_CS1     = ST_1_CS1->GetBinContent(j) + ST_2_CS1->GetBinContent(j) + ST_3_CS1 ->GetBinContent(j) + ST_4_CS1 ->GetBinContent(j);
	double N_VV_CS1     = ZZ1_CS1->GetBinContent(j)+ZZ2_CS1->GetBinContent(j)+ZZ3_CS1->GetBinContent(j)+WW1_CS1->GetBinContent(j)+WW2_CS1->GetBinContent(j)+WZ1_CS1->GetBinContent(j)+WZ2_CS1->GetBinContent(j)+WZ3_CS1->GetBinContent(j);

	
	double N_data_CS2   = data_CS2->GetBinContent(j);
    double N_ZToNuNu_CS2= ZToNuNu_1_CS2->GetBinContent(j) + ZToNuNu_2_CS2->GetBinContent(j) + ZToNuNu_3_CS2->GetBinContent(j) + ZToNuNu_4_CS2->GetBinContent(j) + ZToNuNu_5_CS2->GetBinContent(j) + ZToNuNu_6_CS2->GetBinContent(j) + ZToNuNu_7_CS2->GetBinContent(j);
    double N_QCD_CS2    = QCD_1_CS2->GetBinContent(j) + QCD_2_CS2->GetBinContent(j) + QCD_3_CS2->GetBinContent(j) + QCD_4_CS2->GetBinContent(j) + QCD_5_CS2->GetBinContent(j) + QCD_6_CS2->GetBinContent(j) + QCD_7_CS2->GetBinContent(j);
	double N_WToLNu_CS2 = WToLNu_1_CS2->GetBinContent(j) + WToLNu_2_CS2->GetBinContent(j) + WToLNu_3_CS2->GetBinContent(j) + WToLNu_4_CS2->GetBinContent(j) + WToLNu_5_CS2->GetBinContent(j) + WToLNu_6_CS2->GetBinContent(j)+ WToLNu_7_CS2->GetBinContent(j);
	double N_TT_CS2     = TT_1_CS2->GetBinContent(j) + TT_2_CS2->GetBinContent(j);
    double N_ST_CS2     = ST_1_CS2->GetBinContent(j) + ST_2_CS2->GetBinContent(j) + ST_3_CS2 ->GetBinContent(j) + ST_4_CS2 ->GetBinContent(j);
	double N_VV_CS2     = ZZ1_CS2->GetBinContent(j)+ZZ2_CS2->GetBinContent(j)+ZZ3_CS2->GetBinContent(j)+WW1_CS2->GetBinContent(j)+WW2_CS2->GetBinContent(j)+WZ1_CS2->GetBinContent(j)+WZ2_CS2->GetBinContent(j)+WZ3_CS2->GetBinContent(j);


	double N_data_CS3   = data_CS3->GetBinContent(j);
    double N_ZToNuNu_CS3= ZToNuNu_1_CS3->GetBinContent(j) + ZToNuNu_2_CS3->GetBinContent(j) + ZToNuNu_3_CS3->GetBinContent(j) + ZToNuNu_4_CS3->GetBinContent(j) + ZToNuNu_5_CS3->GetBinContent(j) + ZToNuNu_6_CS3->GetBinContent(j) + ZToNuNu_7_CS3->GetBinContent(j);
    double N_QCD_CS3    = QCD_1_CS3->GetBinContent(j) + QCD_2_CS3->GetBinContent(j) + QCD_3_CS3->GetBinContent(j) + QCD_4_CS3->GetBinContent(j) + QCD_5_CS3->GetBinContent(j) + QCD_6_CS3->GetBinContent(j) + QCD_7_CS3->GetBinContent(j);
	double N_WToLNu_CS3 = WToLNu_1_CS3->GetBinContent(j) + WToLNu_2_CS3->GetBinContent(j) + WToLNu_3_CS3->GetBinContent(j) + WToLNu_4_CS3->GetBinContent(j) + WToLNu_5_CS3->GetBinContent(j) + WToLNu_6_CS3->GetBinContent(j)+ WToLNu_7_CS3->GetBinContent(j);
	double N_TT_CS3     = TT_1_CS3->GetBinContent(j) + TT_2_CS3->GetBinContent(j);
    double N_ST_CS3     = ST_1_CS3->GetBinContent(j) + ST_2_CS3->GetBinContent(j) + ST_3_CS3 ->GetBinContent(j) + ST_4_CS3 ->GetBinContent(j);
	double N_VV_CS3     = ZZ1_CS3->GetBinContent(j)+ZZ2_CS3->GetBinContent(j)+ZZ3_CS3->GetBinContent(j)+WW1_CS3->GetBinContent(j)+WW2_CS3->GetBinContent(j)+WZ1_CS3->GetBinContent(j)+WZ2_CS3->GetBinContent(j)+WZ3_CS3->GetBinContent(j);

    background->SetBinError(j,sqrt(N_ZToNuNu_SR_err+N_QCD_SR_err+N_WToLNu_SR_err+N_TT_SR_err+N_ST_SR_err+N_VV_SR_err));
	background->SetBinContent(j,N_ZToNuNu_SR+N_QCD_SR+N_WToLNu_SR+N_TT_SR+N_ST_SR+N_VV_SR);

	//N(CS1 in data) = SF1*N(Znunu in MC) + SF2*N(WJets in MC) + SF3*N(ttbar in MC) + N(other bkgs in MC)
    //N(CS2 in data) = SF1*N(Znunu in MC) + SF2*N(WJets in MC) + SF3*N(ttbar in MC) + N(other bkgs in MC)
    //N(CS3 in data) = SF1*N(Znunu in MC) + SF2*N(WJets in MC) + SF3*N(ttbar in MC) + N(other bkgs in MC)

	double a1 = N_ZToNuNu_CS1;  double b1 = N_WToLNu_CS1;  double c1 = N_TT_CS1;  double d1 = N_QCD_CS1 + N_ST_CS1 + N_VV_CS1 - N_data_CS1;
	double a2 = N_ZToNuNu_CS2;  double b2 = N_WToLNu_CS2;  double c2 = N_TT_CS2;  double d2 = N_QCD_CS2 + N_ST_CS2 + N_VV_CS2 - N_data_CS2;
	double a3 = N_ZToNuNu_CS3;  double b3 = N_WToLNu_CS3;  double c3 = N_TT_CS3;  double d3 = N_QCD_CS3 + N_ST_CS3 + N_VV_CS3 - N_data_CS3;

	double a1_err = N_ZToNuNu_CS1_err;  double b1_err = N_WToLNu_CS1_err;  double c1_err = N_TT_CS1_err;  double d1_err = N_QCD_CS1_err + N_ST_CS1_err + N_VV_CS1_err ;
	double a2_err = N_ZToNuNu_CS2_err;  double b2_err = N_WToLNu_CS2_err;  double c2_err = N_TT_CS2_err;  double d2_err = N_QCD_CS2_err + N_ST_CS2_err + N_VV_CS2_err ;
	double a3_err = N_ZToNuNu_CS3_err;  double b3_err = N_WToLNu_CS3_err;  double c3_err = N_TT_CS3_err;  double d3_err = N_QCD_CS3_err + N_ST_CS3_err + N_VV_CS3_err ;

	cout<<"d1_err = "<<d1_err<<endl;
	cout<<"d2_err = "<<d2_err<<endl;
	cout<<"d3_err = "<<d3_err<<endl;

	double SF_den  = a3*b2*c1 - a2*b3*c1 - a3*b1*c2 + a1*b3*c2 + a2*b1*c3 - a1*b2*c3;
	double SF1_num = b3*c2*d1 - b2*c3*d1 - b3*c1*d2 + b1*c3*d2 + b2*c1*d3 - b1*c2*d3;
	double SF2_num =-a3*c2*d1 + a2*c3*d1 + a3*c1*d2 - a1*c3*d2 - a2*c1*d3 + a1*c2*d3;
	double SF3_num = a3*b2*d1 - a2*b3*d1 - a3*b1*d2 + a1*b3*d2 + a2*b1*d3 - a1*b2*d3;

	if (SF_den==0) continue;

    double SF1 = -SF1_num/SF_den;
	double SF2 = -SF2_num/SF_den;
	double SF3 = -SF3_num/SF_den;

	//if (SF1<0) SF1=0;
	//if (SF2<0) SF2=0;
	//if (SF3<0) SF3=0;

	cout<<"SF1 = "<<SF1<<endl;
	cout<<"SF2 = "<<SF2<<endl;
	cout<<"SF3 = "<<SF3<<endl;
	cout<<endl;


	SF_den_err = (a3_err*b2*c1*b2*c1 + b2_err*a3*c1*a3*c1 + c1_err*a3*b2*a3*b2) + 
		         (a2_err*b3*c1*b3*c1 + b3_err*a2*c1*a2*c1 + c1_err*a2*b3*a2*b3) +
			     (a3_err*b1*c2*b1*c2 + b1_err*a3*c2*a3*c2 + c2_err*a3*b1*a3*b1) +
				 (a1_err*b3*c2*b3*c2 + b3_err*a1*c2*a1*c2 + c2_err*a1*b3*a1*b3) +
				 (a2_err*b1*c3*b1*c3 + b1_err*a2*c3*a2*c3 + c3_err*a2*b1*a2*b1) +
			     (a1_err*b2*c3*b2*c3 + b2_err*a1*c3*a1*c3 + c3_err*a1*b2*a1*b2) ;
	

	SF1_num_err= (b3_err*c2*d1*c2*d1 + c2_err*b3*d1*b3*d1 + d1_err*b3*c2*b3*c2) + 
		         (b2_err*c3*d1*c3*d1 + c3_err*b2*d1*b2*d1 + d1_err*b2*c3*b2*c3) +
			     (b3_err*c1*d2*c1*d2 + c1_err*b3*d2*b3*d2 + d2_err*b3*c1*b3*c1) +
				 (b1_err*c3*d2*c3*d2 + c3_err*b1*d2*b1*d2 + d2_err*b1*c3*b1*c3) +
				 (b2_err*c1*d3*c1*d3 + c1_err*b2*d3*b2*d3 + d3_err*b2*c1*b2*c1) +
				 (b1_err*c2*d3*c2*d3 + c2_err*b1*d3*b1*d3 + d3_err*b1*c2*b1*c2) ;
	
    SF2_num_err =(a3_err*c2*d1*c2*d1 + c2_err*a3*d1*a3*d1 + d1_err*a3*c2*a3*c2) + 
		         (a2_err*c3*d1*c3*d1 + c3_err*a2*d1*a2*d1 + d1_err*a2*c3*a2*c3) +
			     (a3_err*c1*d2*c1*d2 + c1_err*a3*d2*a3*d2 + d2_err*a3*c1*a3*c1) +
				 (a1_err*c3*d2*c3*d2 + c3_err*a1*d2*a1*d2 + d2_err*a1*c3*a1*c3) +
				 (a2_err*c1*d3*c1*d3 + c1_err*a2*d3*a2*d3 + d3_err*a2*c1*a2*c1) +
				 (a1_err*c2*d3*c2*d3 + c2_err*a1*d3*a1*d3 + d3_err*a1*c2*a1*c2) ;

    SF3_num_err =(a3_err*b2*d1*b2*d1 + b2_err*a3*d1*a3*d1 + d1_err*a3*b2*a3*b2) + 
		         (a2_err*b3*d1*b3*d1 + b3_err*a2*d1*a2*d1 + d1_err*a2*b3*a2*b3) +
				 (a3_err*b1*d2*b1*d2 + b1_err*a3*d2*a3*d2 + d2_err*a3*b1*a3*b1) +
				 (a1_err*b3*d2*b3*d2 + b3_err*a1*d2*a1*d2 + d2_err*a1*b3*a1*b3) +
				 (a2_err*b1*d3*b1*d3 + b1_err*a2*d3*a2*d3 + d3_err*a2*b1*a2*b1) +
				 (a1_err*b2*d3*b2*d3 + b2_err*a1*d3*a1*d3 + d3_err*a1*b2*a1*b2) ;

	cout<<"SF1_num_err = "<<SF1_num_err<<endl;
	cout<<"SF2_num_err = "<<SF2_num_err<<endl;
	cout<<"SF3_num_err = "<<SF3_num_err<<endl;
	cout<<"SF_den_err = "<<SF_den_err<<endl;

	
	double SF1_err = (SF1_num_err*SF_den*SF_den + SF_den_err*SF1_num*SF1_num)/(SF_den*SF_den*SF_den*SF_den);

	double SF2_err = (SF2_num_err*SF_den*SF_den + SF_den_err*SF2_num*SF2_num)/(SF_den*SF_den*SF_den*SF_den);

	double SF3_err = (SF3_num_err*SF_den*SF_den + SF_den_err*SF3_num*SF3_num)/(SF_den*SF_den*SF_den*SF_den);

	cout<<"SF1 err = "<< SF1_err <<endl;
	cout<<"SF2 err = "<< SF2_err <<endl;
	cout<<"SF3 err = "<< SF3_err <<endl;

	double N_ZToNuNu_PRE_err = (SF1_err*N_ZToNuNu_SR*N_ZToNuNu_SR+N_ZToNuNu_SR_err*SF1*SF1);
    double N_WToLNu_PRE_err  = (SF2_err*N_WToLNu_SR*N_WToLNu_SR  +N_WToLNu_SR_err *SF2*SF2);
	double N_TT_PRE_err      = (SF3_err*N_TT_SR*N_TT_SR  +N_TT_SR_err*SF3*SF3);
  
	double N_ZToNuNu_PRE = SF1*N_ZToNuNu_SR;
	double N_WToLNu_PRE  = SF2*N_WToLNu_SR;
	double N_TT_PRE      = SF3*N_TT_SR;

    //N(CS1 in data) = SF1*N(Znunu in MC) + SF2*N(WJets in MC)  + N(other bkgs in MC)
    //N(CS2 in data) = SF1*N(Znunu in MC) + SF2*N(WJets in MC)  + N(other bkgs in MC)

	/*float a1 = N_ZToNuNu_CS1;  float b1 = N_WToLNu_CS1;  float c1 = N_TT_CS1 + N_QCD_CS1 + N_ST_CS1 + N_VV_CS1 - N_data_CS1;
	float a2 = N_ZToNuNu_CS2;  float b2 = N_WToLNu_CS2;  float c2 = N_TT_CS2 + N_QCD_CS2 + N_ST_CS2 + N_VV_CS2 - N_data_CS2;

	float a1_err = N_ZToNuNu_CS1_err;  float b1_err = N_WToLNu_CS1_err;  float c1_err = N_TT_CS1_err + N_QCD_CS1_err + N_ST_CS1_err + N_VV_CS1_err ;
	float a2_err = N_ZToNuNu_CS2_err;  float b2_err = N_WToLNu_CS2_err;  float c2_err = N_TT_CS2_err + N_QCD_CS2_err + N_ST_CS2_err + N_VV_CS2_err ; 

	float SF_den  = a2*b1-a1*b2;
	float SF1_num =-b2*c1+b1*c2;
	float SF2_num = a2*c1-a1*c2;

	if (SF_den==0) continue;

    float SF1 = -SF1_num/SF_den;
	float SF2 = -SF1_num/SF_den;

	SF_den_err = (a2_err*b1*b1 + b1_err*a2*a2) + 
		         (a1_err*b2*b2 + b2_err*a1*a1) ;
	
	SF1_num_err= (b2_err*c1*c1 + c1_err*b2*b2) + 
		         (b1_err*c2*c2 + c2_err*b1*b1) ;
	
    SF2_num_err =(a2_err*c1*c1 + c1_err*a2*a2) + 
		         (a1_err*c2*c2 + c2_err*a1*a1 ) ;

	float SF1_err = (SF1_num_err*SF_den*SF_den + SF_den_err*SF1_num*SF1_num)/(SF_den*SF_den*SF_den*SF_den);

	float SF2_err = (SF2_num_err*SF_den*SF_den + SF_den_err*SF2_num*SF2_num)/(SF_den*SF_den*SF_den*SF_den);

	float N_ZToNuNu_PRE_err = (SF1_err*N_ZToNuNu_SR*N_ZToNuNu_SR+N_ZToNuNu_SR_err*SF1*SF1);
    float N_WToLNu_PRE_err  = (SF2_err*N_WToLNu_SR*N_WToLNu_SR  +N_WToLNu_SR_err *SF2*SF2);
	float N_TT_PRE_err      = N_TT_SR_err;
  
	float N_ZToNuNu_PRE = SF1*N_ZToNuNu_SR;
	float N_WToLNu_PRE  = SF2*N_WToLNu_SR;
	float N_TT_PRE      = N_TT_SR;*/


	ZToNuNu->SetBinError(j,sqrt(N_ZToNuNu_PRE_err));
	ZToNuNu->SetBinContent(j,N_ZToNuNu_PRE);

	QCD->SetBinError(j,sqrt(N_QCD_SR_err));
	QCD->SetBinContent(j,N_QCD_SR);

	WToLNu->SetBinError(j,sqrt(N_WToLNu_PRE_err));
	WToLNu->SetBinContent(j,N_WToLNu_PRE);

	TT->SetBinError(j,sqrt(N_TT_PRE_err));
	TT->SetBinContent(j,N_TT_PRE);

	ST->SetBinError(j,sqrt(N_ST_SR_err));
	ST->SetBinContent(j,N_ST_SR);

	VV->SetBinError(j,sqrt(N_VV_SR_err));
	VV->SetBinContent(j,N_VV_SR);

	background_PRE->SetBinError(j,sqrt(N_ZToNuNu_PRE_err+N_QCD_SR_err+N_WToLNu_PRE_err+N_TT_PRE_err+N_ST_SR_err+N_VV_SR_err));
	background_PRE->SetBinContent(j,N_ZToNuNu_PRE+N_QCD_SR+N_WToLNu_PRE+N_TT_PRE+N_ST_SR+N_VV_SR);

	background_CS1->SetBinError(j,sqrt(N_ZToNuNu_CS1_err+N_QCD_CS1_err+N_WToLNu_CS1_err+N_TT_CS1_err+N_ST_CS1_err+N_VV_CS1_err));
	background_CS1->SetBinContent(j,N_ZToNuNu_CS1+N_QCD_CS1+N_WToLNu_CS1+N_TT_CS1+N_ST_CS1+N_VV_CS1);

	background_CS2->SetBinError(j,sqrt(N_ZToNuNu_CS2_err+N_QCD_CS2_err+N_WToLNu_CS2_err+N_TT_CS2_err+N_ST_CS2_err+N_VV_CS2_err));
	background_CS2->SetBinContent(j,N_ZToNuNu_CS2+N_QCD_CS2+N_WToLNu_CS2+N_TT_CS2+N_ST_CS2+N_VV_CS2);

	background_CS3->SetBinError(j,sqrt(N_ZToNuNu_CS3_err+N_QCD_CS3_err+N_WToLNu_CS3_err+N_TT_CS3_err+N_ST_CS3_err+N_VV_CS3_err));
	background_CS3->SetBinContent(j,N_ZToNuNu_CS3+N_QCD_CS3+N_WToLNu_CS3+N_TT_CS3+N_ST_CS3+N_VV_CS3);

	if(SF1>0) SF1_h->SetBinContent(j,SF1);
	if(SF2>0) SF2_h->SetBinContent(j,SF2);
	if(SF3>0) SF3_h->SetBinContent(j,SF3);

	SF1_h->SetBinError(j,SF1_err);
	SF2_h->SetBinError(j,SF2_err);
	SF3_h->SetBinError(j,SF3_err);

  }

  /*background_func  = (TH1F*)background ->Clone();
  background_PRE_func  = (TH1F*)background_PRE ->Clone();
  data_func        = (TH1F*)data       ->Clone(); 
  tptzm0700lh_func = (TH1F*)tptzm0700lh->Clone(); 
  tptzm0900lh_func = (TH1F*)tptzm0900lh->Clone(); 
  tptzm1400lh_func = (TH1F*)tptzm1400lh->Clone(); 
  tptzm1700lh_func = (TH1F*)tptzm1700lh->Clone(); 
  ZToNuNu_1_func   = (TH1F*)ZToNuNu_1->Clone(); 
  ZToNuNu_2_func   = (TH1F*)ZToNuNu_2->Clone(); 
  ZToNuNu_3_func   = (TH1F*)ZToNuNu_3->Clone();  
  ZToNuNu_4_func   = (TH1F*)ZToNuNu_4->Clone(); 
  ZToNuNu_5_func   = (TH1F*)ZToNuNu_5->Clone();
  ZToNuNu_6_func   = (TH1F*)ZToNuNu_6->Clone();
  ZToNuNu_7_func   = (TH1F*)ZToNuNu_7->Clone();
  ZToNuNu_func   = (TH1F*)ZToNuNu->Clone();
  QCD_1_func = (TH1F*)QCD_1->Clone();    
  QCD_2_func = (TH1F*)QCD_2->Clone();
  QCD_3_func = (TH1F*)QCD_3->Clone(); 
  QCD_4_func = (TH1F*)QCD_4->Clone();
  QCD_5_func = (TH1F*)QCD_5->Clone();  
  QCD_6_func = (TH1F*)QCD_6->Clone(); 
  QCD_7_func = (TH1F*)QCD_7->Clone();
  QCD_func = (TH1F*)QCD->Clone();
  WToLNu_1_func = (TH1F*)WToLNu_1->Clone(); 
  WToLNu_2_func = (TH1F*)WToLNu_2->Clone();
  WToLNu_3_func = (TH1F*)WToLNu_3->Clone();
  WToLNu_4_func = (TH1F*)WToLNu_4->Clone();
  WToLNu_5_func = (TH1F*)WToLNu_5->Clone();
  WToLNu_6_func = (TH1F*)WToLNu_6->Clone();
  WToLNu_7_func = (TH1F*)WToLNu_7->Clone();
  WToLNu_func = (TH1F*)WToLNu->Clone();
  TT_1_func = (TH1F*)TT_1->Clone();  
  TT_2_func = (TH1F*)TT_2->Clone();
  TT_func = (TH1F*)TT->Clone();
  ST_1_func = (TH1F*)ST_1->Clone();    
  ST_2_func = (TH1F*)ST_2->Clone();    
  ST_3_func = (TH1F*)ST_3->Clone();    
  ST_4_func = (TH1F*)ST_4->Clone();  
  ST_func = (TH1F*)ST->Clone();
  ZZ1_func  = (TH1F*)ZZ1->Clone(); 
  ZZ2_func  = (TH1F*)ZZ2->Clone();
  ZZ3_func  = (TH1F*)ZZ3->Clone();    
  WW1_func  = (TH1F*)WW1->Clone(); 
  WW2_func  = (TH1F*)WW2->Clone(); 
  WZ1_func  = (TH1F*)WZ1->Clone(); 
  WZ2_func  = (TH1F*)WZ2->Clone();
  WZ3_func  = (TH1F*)WZ3->Clone();
  VV_func  = (TH1F*)VV->Clone();*/

  /*background_func  = (TH1F*)background_CS1 ->Clone(); 
  background_PRE_func  = (TH1F*)background_PRE ->Clone();
  data_func        = (TH1F*)data_CS1       ->Clone(); 
  tptzm0700lh_func = (TH1F*)tptzm0700lh_CS1->Clone(); 
  tptzm0900lh_func = (TH1F*)tptzm0900lh_CS1->Clone(); 
  tptzm1400lh_func = (TH1F*)tptzm1400lh_CS1->Clone(); 
  tptzm1700lh_func = (TH1F*)tptzm1700lh_CS1->Clone(); 
  ZToNuNu_1_func   = (TH1F*)ZToNuNu_1_CS1->Clone(); 
  ZToNuNu_2_func   = (TH1F*)ZToNuNu_2_CS1->Clone(); 
  ZToNuNu_3_func   = (TH1F*)ZToNuNu_3_CS1->Clone();  
  ZToNuNu_4_func   = (TH1F*)ZToNuNu_4_CS1->Clone(); 
  ZToNuNu_5_func   = (TH1F*)ZToNuNu_5_CS1->Clone();
  ZToNuNu_6_func   = (TH1F*)ZToNuNu_6_CS1->Clone();
  ZToNuNu_7_func   = (TH1F*)ZToNuNu_7_CS1->Clone();
  ZToNuNu_func   = (TH1F*)ZToNuNu->Clone();
  QCD_1_func = (TH1F*)QCD_1_CS1->Clone();    
  QCD_2_func = (TH1F*)QCD_2_CS1->Clone();
  QCD_3_func = (TH1F*)QCD_3_CS1->Clone(); 
  QCD_4_func = (TH1F*)QCD_4_CS1->Clone();
  QCD_5_func = (TH1F*)QCD_5_CS1->Clone();  
  QCD_6_func = (TH1F*)QCD_6_CS1->Clone(); 
  QCD_7_func = (TH1F*)QCD_7_CS1->Clone();
  QCD_func = (TH1F*)QCD_CS1->Clone(); 
  WToLNu_1_func = (TH1F*)WToLNu_1_CS1->Clone(); 
  WToLNu_2_func = (TH1F*)WToLNu_2_CS1->Clone();
  WToLNu_3_func = (TH1F*)WToLNu_3_CS1->Clone();
  WToLNu_4_func = (TH1F*)WToLNu_4_CS1->Clone();
  WToLNu_5_func = (TH1F*)WToLNu_5_CS1->Clone();
  WToLNu_6_func = (TH1F*)WToLNu_6_CS1->Clone();
  WToLNu_7_func = (TH1F*)WToLNu_7_CS1->Clone();
  WToLNu_func = (TH1F*)WToLNu->Clone();
  TT_1_func = (TH1F*)TT_1_CS1->Clone();  
  TT_2_func = (TH1F*)TT_2_CS1->Clone();
  TT_func = (TH1F*)TT->Clone();
  ST_1_func = (TH1F*)ST_1_CS1->Clone();    
  ST_2_func = (TH1F*)ST_2_CS1->Clone();    
  ST_3_func = (TH1F*)ST_3_CS1->Clone();    
  ST_4_func = (TH1F*)ST_4_CS1->Clone(); 
  ST_func = (TH1F*)ST->Clone();
  ZZ1_func  = (TH1F*)ZZ1_CS1->Clone(); 
  ZZ2_func  = (TH1F*)ZZ2_CS1->Clone();
  ZZ3_func  = (TH1F*)ZZ3_CS1->Clone();    
  WW1_func  = (TH1F*)WW1_CS1->Clone(); 
  WW2_func  = (TH1F*)WW2_CS1->Clone(); 
  WZ1_func  = (TH1F*)WZ1_CS1->Clone(); 
  WZ2_func  = (TH1F*)WZ2_CS1->Clone();
  WZ3_func  = (TH1F*)WZ3_CS1->Clone();
  VV_func  = (TH1F*)VV->Clone();*/

  /*background_func  = (TH1F*)background_CS2 ->Clone(); 
  background_PRE_func  = (TH1F*)background_PRE ->Clone();
  data_func        = (TH1F*)data_CS2       ->Clone(); 
  tptzm0700lh_func = (TH1F*)tptzm0700lh_CS2->Clone(); 
  tptzm0900lh_func = (TH1F*)tptzm0900lh_CS2->Clone(); 
  tptzm1400lh_func = (TH1F*)tptzm1400lh_CS2->Clone(); 
  tptzm1700lh_func = (TH1F*)tptzm1700lh_CS2->Clone(); 
  ZToNuNu_1_func   = (TH1F*)ZToNuNu_1_CS2->Clone(); 
  ZToNuNu_2_func   = (TH1F*)ZToNuNu_2_CS2->Clone(); 
  ZToNuNu_3_func   = (TH1F*)ZToNuNu_3_CS2->Clone();  
  ZToNuNu_4_func   = (TH1F*)ZToNuNu_4_CS2->Clone(); 
  ZToNuNu_5_func   = (TH1F*)ZToNuNu_5_CS2->Clone();
  ZToNuNu_6_func   = (TH1F*)ZToNuNu_6_CS2->Clone();
  ZToNuNu_7_func   = (TH1F*)ZToNuNu_7_CS2->Clone();
  ZToNuNu_func   = (TH1F*)ZToNuNu->Clone();
  QCD_1_func = (TH1F*)QCD_1_CS2->Clone();    
  QCD_2_func = (TH1F*)QCD_2_CS2->Clone();
  QCD_3_func = (TH1F*)QCD_3_CS2->Clone(); 
  QCD_4_func = (TH1F*)QCD_4_CS2->Clone();
  QCD_5_func = (TH1F*)QCD_5_CS2->Clone();  
  QCD_6_func = (TH1F*)QCD_6_CS2->Clone(); 
  QCD_7_func = (TH1F*)QCD_7_CS2->Clone();
  QCD_func = (TH1F*)QCD_CS2->Clone(); 
  WToLNu_1_func = (TH1F*)WToLNu_1_CS2->Clone(); 
  WToLNu_2_func = (TH1F*)WToLNu_2_CS2->Clone();
  WToLNu_3_func = (TH1F*)WToLNu_3_CS2->Clone();
  WToLNu_4_func = (TH1F*)WToLNu_4_CS2->Clone();
  WToLNu_5_func = (TH1F*)WToLNu_5_CS2->Clone();
  WToLNu_6_func = (TH1F*)WToLNu_6_CS2->Clone();
  WToLNu_7_func = (TH1F*)WToLNu_7_CS2->Clone();
  WToLNu_func = (TH1F*)WToLNu->Clone();
  TT_1_func = (TH1F*)TT_1_CS2->Clone();  
  TT_2_func = (TH1F*)TT_2_CS2->Clone();
  TT_func = (TH1F*)TT->Clone();
  ST_1_func = (TH1F*)ST_1_CS2->Clone();    
  ST_2_func = (TH1F*)ST_2_CS2->Clone();    
  ST_3_func = (TH1F*)ST_3_CS2->Clone();    
  ST_4_func = (TH1F*)ST_4_CS2->Clone(); 
  ST_func = (TH1F*)ST->Clone();
  ZZ1_func  = (TH1F*)ZZ1_CS2->Clone(); 
  ZZ2_func  = (TH1F*)ZZ2_CS2->Clone();
  ZZ3_func  = (TH1F*)ZZ3_CS2->Clone();    
  WW1_func  = (TH1F*)WW1_CS2->Clone(); 
  WW2_func  = (TH1F*)WW2_CS2->Clone(); 
  WZ1_func  = (TH1F*)WZ1_CS2->Clone(); 
  WZ2_func  = (TH1F*)WZ2_CS2->Clone();
  WZ3_func  = (TH1F*)WZ3_CS2->Clone();
  VV_func  = (TH1F*)VV->Clone();*/

  background_func  = (TH1F*)background_CS3 ->Clone(); 
  background_PRE_func  = (TH1F*)background_PRE ->Clone();
  data_func        = (TH1F*)data_CS3       ->Clone(); 
  tptzm0700lh_func = (TH1F*)tptzm0700lh_CS3->Clone(); 
  tptzm0900lh_func = (TH1F*)tptzm0900lh_CS3->Clone(); 
  tptzm1400lh_func = (TH1F*)tptzm1400lh_CS3->Clone(); 
  tptzm1700lh_func = (TH1F*)tptzm1700lh_CS3->Clone(); 
  ZToNuNu_1_func   = (TH1F*)ZToNuNu_1_CS3->Clone(); 
  ZToNuNu_2_func   = (TH1F*)ZToNuNu_2_CS3->Clone(); 
  ZToNuNu_3_func   = (TH1F*)ZToNuNu_3_CS3->Clone();  
  ZToNuNu_4_func   = (TH1F*)ZToNuNu_4_CS3->Clone(); 
  ZToNuNu_5_func   = (TH1F*)ZToNuNu_5_CS3->Clone();
  ZToNuNu_6_func   = (TH1F*)ZToNuNu_6_CS3->Clone();
  ZToNuNu_7_func   = (TH1F*)ZToNuNu_7_CS3->Clone();
  ZToNuNu_func   = (TH1F*)ZToNuNu->Clone();
  QCD_1_func = (TH1F*)QCD_1_CS3->Clone();    
  QCD_2_func = (TH1F*)QCD_2_CS3->Clone();
  QCD_3_func = (TH1F*)QCD_3_CS3->Clone(); 
  QCD_4_func = (TH1F*)QCD_4_CS3->Clone();
  QCD_5_func = (TH1F*)QCD_5_CS3->Clone();  
  QCD_6_func = (TH1F*)QCD_6_CS3->Clone(); 
  QCD_7_func = (TH1F*)QCD_7_CS3->Clone();
  QCD_func = (TH1F*)QCD_CS3->Clone(); 
  WToLNu_1_func = (TH1F*)WToLNu_1_CS3->Clone(); 
  WToLNu_2_func = (TH1F*)WToLNu_2_CS3->Clone();
  WToLNu_3_func = (TH1F*)WToLNu_3_CS3->Clone();
  WToLNu_4_func = (TH1F*)WToLNu_4_CS3->Clone();
  WToLNu_5_func = (TH1F*)WToLNu_5_CS3->Clone();
  WToLNu_6_func = (TH1F*)WToLNu_6_CS3->Clone();
  WToLNu_7_func = (TH1F*)WToLNu_7_CS3->Clone();
  WToLNu_func = (TH1F*)WToLNu->Clone();
  TT_1_func = (TH1F*)TT_1_CS3->Clone();  
  TT_2_func = (TH1F*)TT_2_CS3->Clone();
  TT_func = (TH1F*)TT->Clone();
  ST_1_func = (TH1F*)ST_1_CS3->Clone();    
  ST_2_func = (TH1F*)ST_2_CS3->Clone();    
  ST_3_func = (TH1F*)ST_3_CS3->Clone();    
  ST_4_func = (TH1F*)ST_4_CS3->Clone(); 
  ST_func = (TH1F*)ST->Clone();
  ZZ1_func  = (TH1F*)ZZ1_CS3->Clone(); 
  ZZ2_func  = (TH1F*)ZZ2_CS3->Clone();
  ZZ3_func  = (TH1F*)ZZ3_CS3->Clone();    
  WW1_func  = (TH1F*)WW1_CS3->Clone(); 
  WW2_func  = (TH1F*)WW2_CS3->Clone(); 
  WZ1_func  = (TH1F*)WZ1_CS3->Clone(); 
  WZ2_func  = (TH1F*)WZ2_CS3->Clone();
  WZ3_func  = (TH1F*)WZ3_CS3->Clone();
  VV_func  = (TH1F*)VV->Clone();

  SF1_h_func = (TH1F*)SF1_h->Clone();
  SF2_h_func = (TH1F*)SF2_h->Clone();
  SF3_h_func = (TH1F*)SF3_h->Clone();


  delete data; delete background; delete background_PRE; delete tptzm0700lh; delete tptzm0900lh; delete tptzm1400lh; delete tptzm1700lh;
  delete ZToNuNu; delete ZToNuNu_1; delete ZToNuNu_2; delete ZToNuNu_3; delete ZToNuNu_4;  delete ZToNuNu_5;  delete ZToNuNu_6;  delete ZToNuNu_7;
  delete QCD;  delete QCD_1; delete QCD_2; delete QCD_3; delete QCD_4; delete QCD_5; delete QCD_6; delete QCD_7; 
  delete WToLNu; delete WToLNu_1; delete WToLNu_2; delete WToLNu_3; delete WToLNu_4; delete WToLNu_5; delete WToLNu_6; delete WToLNu_7; 
  delete TT; delete TT_1; delete TT_2; 
  delete ST; delete ST_1; delete ST_2;  delete ST_3; delete ST_4;  
  delete VV; delete WW1; delete WW2; delete WZ1; delete WZ2; delete WZ3; delete ZZ1; delete ZZ2;  delete ZZ3; 

  delete data_CS1; delete background_CS1; delete tptzm0700lh_CS1; delete tptzm0900lh_CS1; delete tptzm1400lh_CS1; delete tptzm1700lh_CS1; 
  delete ZToNuNu_CS1; delete ZToNuNu_1_CS1; delete ZToNuNu_2_CS1; delete ZToNuNu_3_CS1; delete ZToNuNu_4_CS1;  delete ZToNuNu_5_CS1;  delete ZToNuNu_6_CS1;  delete ZToNuNu_7_CS1;
  delete QCD_CS1;  delete QCD_1_CS1; delete QCD_2_CS1; delete QCD_3_CS1; delete QCD_4_CS1; delete QCD_5_CS1; delete QCD_6_CS1; delete QCD_7_CS1; 
  delete WToLNu_CS1; delete WToLNu_1_CS1; delete WToLNu_2_CS1; delete WToLNu_3_CS1; delete WToLNu_4_CS1; delete WToLNu_5_CS1; delete WToLNu_6_CS1; delete WToLNu_7_CS1; 
  delete TT_CS1; delete TT_1_CS1; delete TT_2_CS1; 
  delete ST_CS1; delete ST_1_CS1; delete ST_2_CS1;  delete ST_3_CS1; delete ST_4_CS1;  
  delete VV_CS1; delete WW1_CS1; delete WW2_CS1; delete WZ1_CS1; delete WZ2_CS1; delete WZ3_CS1; delete ZZ1_CS1; delete ZZ2_CS1;  delete ZZ3_CS1; 

  delete data_CS2; delete background_CS2; delete tptzm0700lh_CS2; delete tptzm0900lh_CS2; delete tptzm1400lh_CS2; delete tptzm1700lh_CS2;  
  delete ZToNuNu_CS2; delete ZToNuNu_1_CS2; delete ZToNuNu_2_CS2; delete ZToNuNu_3_CS2; delete ZToNuNu_4_CS2;  delete ZToNuNu_5_CS2;  delete ZToNuNu_6_CS2;  delete ZToNuNu_7_CS2;
  delete QCD_CS2;  delete QCD_1_CS2; delete QCD_2_CS2; delete QCD_3_CS2; delete QCD_4_CS2; delete QCD_5_CS2; delete QCD_6_CS2; delete QCD_7_CS2;
  delete WToLNu_CS2; delete WToLNu_1_CS2; delete WToLNu_2_CS2; delete WToLNu_3_CS2; delete WToLNu_4_CS2; delete WToLNu_5_CS2; delete WToLNu_6_CS2; delete WToLNu_7_CS2; 
  delete TT_CS2; delete TT_1_CS2; delete TT_2_CS2; 
  delete ST_CS2; delete ST_1_CS2; delete ST_2_CS2;  delete ST_3_CS2; delete ST_4_CS2;  
  delete VV_CS2; delete WW1_CS2; delete WW2_CS2; delete WZ1_CS2; delete WZ2_CS2; delete WZ3_CS2; delete ZZ1_CS2; delete ZZ2_CS2;  delete ZZ3_CS2; 

  delete data_CS3; delete background_CS3; delete tptzm0700lh_CS3; delete tptzm0900lh_CS3; delete tptzm1400lh_CS3; delete tptzm1700lh_CS3; 
  delete ZToNuNu_CS3; delete ZToNuNu_1_CS3; delete ZToNuNu_2_CS3; delete ZToNuNu_3_CS3; delete ZToNuNu_4_CS3;  delete ZToNuNu_5_CS3;  delete ZToNuNu_6_CS3;  delete ZToNuNu_7_CS3;
  delete QCD_CS3;  delete QCD_1_CS3; delete QCD_2_CS3; delete QCD_3_CS3; delete QCD_4_CS3; delete QCD_5_CS3; delete QCD_6_CS3; delete QCD_7_CS3;
  delete WToLNu_CS3; delete WToLNu_1_CS3; delete WToLNu_2_CS3; delete WToLNu_3_CS3; delete WToLNu_4_CS3; delete WToLNu_5_CS3; delete WToLNu_6_CS3; delete WToLNu_7_CS3; 
  delete TT_CS3; delete TT_1_CS3; delete TT_2_CS3; 
  delete ST_CS3; delete ST_1_CS3; delete ST_2_CS3;  delete ST_3_CS3; delete ST_4_CS3;  
  delete VV_CS3; delete WW1_CS3; delete WW2_CS3; delete WZ1_CS3; delete WZ2_CS3; delete WZ3_CS3; delete ZZ1_CS3; delete ZZ2_CS3;  delete ZZ3_CS3; 

  delete SF1_h;  delete SF2_h; delete SF3_h;
  
}
