#include "plotterPreselection_dineutrino_ABCDmethod.h"

void plotterPreselection_dineutrino_ABCDmethod(){ 
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

  //name.push_back("Jet1ResolvedPt"); bin.push_back(40);     Min.push_back(0);    Max.push_back(900);    axis.push_back("jet1(resolved) pt [GeV]");
  //name.push_back("Jet2ResolvedPt"); bin.push_back(40);     Min.push_back(0);    Max.push_back(900);    axis.push_back("jet2(resolved) pt [GeV]");
  //name.push_back("Jet3ResolvedPt"); bin.push_back(40);     Min.push_back(0);    Max.push_back(900);    axis.push_back("jet3(resolved) pt [GeV]");

  //name.push_back("Jet1ResolvedEta"); bin.push_back(40);     Min.push_back(-2.5);    Max.push_back(2.5);    axis.push_back("jet1(resolved) #eta");
  //name.push_back("Jet2ResolvedEta"); bin.push_back(40);     Min.push_back(-2.5);    Max.push_back(2.5);    axis.push_back("jet2(resolved) #eta");
  //name.push_back("Jet3ResolvedEta"); bin.push_back(40);     Min.push_back(-2.5);    Max.push_back(2.5);    axis.push_back("jet3(resolved) #eta");
  
  //name.push_back("Jet1PartialPt"); bin.push_back(40);     Min.push_back(0);    Max.push_back(500);    axis.push_back("W-jet(partial) pt[GeV]");
  //name.push_back("Jet2PartialPt"); bin.push_back(40);     Min.push_back(0);    Max.push_back(500);    axis.push_back("jet(partial) pt[GeV]");
  
  
  //name.push_back("Jet1PartialEta"); bin.push_back(40);     Min.push_back(-2.5);    Max.push_back(2.5);    axis.push_back("W-jet(resolved) #eta");
  //name.push_back("Jet2PartialEta"); bin.push_back(40);     Min.push_back(-2.5);    Max.push_back(2.5);    axis.push_back("jet(resolved) #eta");

  //name.push_back("Jet1MergedPt"); bin.push_back(40);     Min.push_back(0);    Max.push_back(1000);    axis.push_back("top-jet(partial) pt[GeV]");
  //name.push_back("Jet1MergedEta"); bin.push_back(40);     Min.push_back(-2.5);    Max.push_back(2.5);    axis.push_back("top-jet(resolved) #eta");

  //name.push_back("TopMass"); bin.push_back(20);     Min.push_back(0);    Max.push_back(500);    axis.push_back("Top Mass[GeV]");
  //name.push_back("TopPt");   bin.push_back(40);     Min.push_back(0);    Max.push_back(1000);   axis.push_back("Top pt[GeV] ");
  //name.push_back("TopEta");  bin.push_back(40);     Min.push_back(-3);   Max.push_back(3);      axis.push_back("Top #eta");
  
  //name.push_back("Met_pt");  bin.push_back(40);     Min.push_back(0);    Max.push_back(1000);   axis.push_back("Met pt[GeV] ");
  //name.push_back("Met_phi"); bin.push_back(40);     Min.push_back(-4);   Max.push_back(4);      axis.push_back("Met #phi");

  name.push_back("deltaPhiMetTop"); bin.push_back(15);     Min.push_back(0);    Max.push_back(3);    axis.push_back("#Delta#phi(Met,top)");
  //name.push_back("MinDeltaPhiJetMet"); bin.push_back(30);     Min.push_back(0);    Max.push_back(3);    axis.push_back("Min#Delta#phi(Met,Jet)");
  
  //name.push_back("HT"); bin.push_back(29);     Min.push_back(100);    Max.push_back(3000);    axis.push_back("HT pt[GeV]");

  //name.push_back("NVertices"); bin.push_back(80);     Min.push_back(0);    Max.push_back(80);    axis.push_back("Number of vertices");

  //name.push_back("NumSelBJetsM"); bin.push_back(6);     Min.push_back(0);    Max.push_back(6);    axis.push_back("Number of medium B jets");
  //name.push_back("NumSelBJetsL"); bin.push_back(8);     Min.push_back(0);    Max.push_back(8);    axis.push_back("Number of loose B jets");

  //name.push_back("TopPhiResolved"); bin.push_back(40);     Min.push_back(-4);    Max.push_back(4);    axis.push_back("top #phi");
  //name.push_back("TopPhiResolved-Met_phi"); bin.push_back(40);     Min.push_back(-8);    Max.push_back(8);    axis.push_back("#Delta#phi(Met,top)");
  
  for(int i=0; i<name.size(); i++){
    const char *plot = name[i];
    char CUT[1000]; char CUTmuo1[1000]; char CUTmuo2[1000]; char CUTele1[1000]; char CUTele2[1000]; char CUTtri1[1000]; char CUTtri2[1000]; char CUTtri3[1000]; char CUTtri4[1000]; char CUTpup1[1000]; char CUTpup2[1000]; char CUTbta1[1000]; char CUTbta2[1000]; char CUTtop1[1000]; char CUTtop2[1000]; char CUTfor1[1000]; char CUTfor2[1000]; char CUTwje1[1000]; char CUTwje2[1000];
	
	sprintf(CUT,    "PUWeight  *w_Btag  *w_for  *w_topJet  *w_WJet  *genWeight*(category0==1)");
	//sprintf(CUT,    "PUWeight  *w_Btag  *w_for  *w_topJet  *w_WJet  *genWeight*((NumSelBJetsM>=1)&&(HT>200)&&(TopPtResolved>340)&&(Jet1ResolvedPt>30)&&(Jet2ResolvedPt>30)&&(Jet3ResolvedPt>30)&&(category0==1))");
	//sprintf(CUT,    "PUWeight  *w_Btag  *w_for  *w_topJet  *w_WJet  *genWeight*((Jet1ResolvedPt>20)&&(Jet2ResolvedPt>20)&&(Jet3ResolvedPt>20)&&(category0==1)&&(category1==0)&&(category2==0))");
	//sprintf(CUT,    "PUWeight  *w_Btag  *w_for  *w_topJet  *w_WJet  *genWeight*(NumSelJets>=1)*((Jet1ResolvedPt>30)&&(Jet2ResolvedPt>30)&&(Jet3ResolvedPt>30))");
	//sprintf(CUT,    "PUWeight  *w_BtagLoose  *w_for  *w_topJet  *w_WJet  *genWeight*((HT>200)&&(TopPtResolved>200)&&(Jet1ResolvedPt>30)&&(Jet2ResolvedPt>30)&&(Jet3ResolvedPt>30)&&(category0==1))");
	//sprintf(CUT,    "PUWeight  *w_Btag  *w_for  *w_topJet  *w_WJet  *genWeight*((NumSelBJetsT>=1)&&(TopPtResolved>340)&&(Jet1ResolvedPt>30)&&(Jet2ResolvedPt>30)&&(Jet3ResolvedPt>30)&&(category0==1))");
  
	MakeHistos(CUT,plot,bin[i],Min[i],Max[i],0,data_SR,background_SR,ZToNuNu_1_SR,ZToNuNu_2_SR,ZToNuNu_3_SR,ZToNuNu_4_SR,ZToNuNu_5_SR,ZToNuNu_6_SR,ZToNuNu_7_SR,
		       /*QCD_1_SR,QCD_2_SR,QCD_3_SR,QCD_4_SR,QCD_5_SR,QCD_6_SR,QCD_7_SR,*/ QCD_SR,
			   WToLNu_1_SR,WToLNu_2_SR,WToLNu_3_SR,WToLNu_4_SR,WToLNu_5_SR,WToLNu_6_SR,WToLNu_7_SR,
			   TT_1_SR,TT_2_SR,ST_1_SR,ST_2_SR,ST_3_SR,ST_4_SR,ZZ1_SR,ZZ2_SR,ZZ3_SR,WW1_SR,WW2_SR,WZ1_SR,WZ2_SR,WZ3_SR,WToLNu_SR,tptzm0700lh_SR,tptzm0900lh_SR,tptzm1400lh_SR,tptzm1700lh_SR);
	
	tptzm0700lh_SR->SetLineWidth(2); tptzm0900lh_SR->SetLineWidth(2); tptzm1400lh_SR->SetLineWidth(2); tptzm1700lh_SR->SetLineWidth(2); 
	
	ZToNuNu_1_SR->SetLineWidth(2); ZToNuNu_2_SR->SetLineWidth(2);ZToNuNu_3_SR->SetLineWidth(2); ZToNuNu_4_SR->SetLineWidth(2); ZToNuNu_5_SR->SetLineWidth(2); ZToNuNu_6_SR->SetLineWidth(2); ZToNuNu_7_SR->SetLineWidth(2);
	//QCD_1_SR->SetLineWidth(2); QCD_2_SR->SetLineWidth(2);QCD_3_SR->SetLineWidth(2); QCD_4_SR->SetLineWidth(2); QCD_5_SR->SetLineWidth(2); QCD_6_SR->SetLineWidth(2); QCD_7_SR->SetLineWidth(2);
	QCD_SR->SetLineWidth(2);
	WToLNu_1_SR->SetLineWidth(2); WToLNu_2_SR->SetLineWidth(2); WToLNu_3_SR->SetLineWidth(2); WToLNu_4_SR->SetLineWidth(2); WToLNu_5_SR->SetLineWidth(2); WToLNu_6_SR->SetLineWidth(2); WToLNu_7_SR->SetLineWidth(2);
	TT_1_SR->SetLineWidth(2); TT_2_SR->SetLineWidth(2);
	ST_1_SR->SetLineWidth(2); ST_2_SR->SetLineWidth(2); ST_3_SR->SetLineWidth(2); ST_4_SR->SetLineWidth(2); 
	ZZ1_SR->SetLineWidth(2); ZZ2_SR->SetLineWidth(2); ZZ3_SR->SetLineWidth(2); WW1_SR->SetLineWidth(2); WW2_SR->SetLineWidth(2); WZ1_SR->SetLineWidth(2); WZ2_SR->SetLineWidth(2); WZ3_SR->SetLineWidth(2);
	//WToLNu_SR->SetLineWidth(2);
	
	tptzm1700lh_SR->SetLineStyle(2); tptzm0700lh_SR->SetLineColor(2); 
	tptzm0900lh_SR->SetLineColor(2); tptzm1400lh_SR->SetLineColor(2); 
	tptzm1700lh_SR->SetLineColor(2); 
	

	ZToNuNu_1_SR->SetLineColor(kOrange); ZToNuNu_2_SR->SetLineColor(kOrange);ZToNuNu_3_SR->SetLineColor(kOrange); ZToNuNu_4_SR->SetLineColor(kOrange); ZToNuNu_5_SR->SetLineColor(kOrange); ZToNuNu_6_SR->SetLineColor(kOrange); ZToNuNu_7_SR->SetLineColor(kOrange);
	//QCD_1_SR->SetLineColor(kGreen-3); QCD_2_SR->SetLineColor(kGreen-3);QCD_3_SR->SetLineColor(kGreen-3); QCD_4_SR->SetLineColor(kGreen-3); QCD_5_SR->SetLineColor(kGreen-3); QCD_6_SR->SetLineColor(kGreen-3); QCD_7_SR->SetLineColor(kGreen-3);
	QCD_SR->SetLineColor(kGreen-3);
	WToLNu_1_SR->SetLineColor(kCyan-4); WToLNu_2_SR->SetLineColor(kCyan-4); WToLNu_3_SR->SetLineColor(kCyan-4); WToLNu_4_SR->SetLineColor(kCyan-4); WToLNu_5_SR->SetLineColor(kCyan-4); WToLNu_6_SR->SetLineColor(kCyan-4); WToLNu_7_SR->SetLineColor(kCyan-4);
	TT_1_SR->SetLineColor(kGreen+3); TT_2_SR->SetLineColor(kGreen+3);
	ST_1_SR->SetLineColor(kGreen+3); ST_2_SR->SetLineColor(kGreen+3); ST_3_SR->SetLineColor(kGreen+3); ST_4_SR->SetLineColor(kGreen+3); 
	ZZ1_SR->SetLineColor(kCyan+2); ZZ2_SR->SetLineColor(kCyan+2); ZZ3_SR->SetLineColor(kCyan+2); WW1_SR->SetLineColor(kCyan+2); WW2_SR->SetLineColor(kCyan+2); WZ1_SR->SetLineColor(kCyan+2); WZ2_SR->SetLineColor(kCyan+2); WZ3_SR->SetLineColor(kCyan+2); 
	//WToLNu_SR->SetLineColor(kCyan-4);

	ZToNuNu_1_SR->SetFillColor(kOrange); ZToNuNu_2_SR->SetFillColor(kOrange);ZToNuNu_3_SR->SetFillColor(kOrange); ZToNuNu_4_SR->SetFillColor(kOrange); ZToNuNu_5_SR->SetFillColor(kOrange); ZToNuNu_6_SR->SetFillColor(kOrange); ZToNuNu_7_SR->SetFillColor(kOrange);
	//QCD_1_SR->SetFillColor(kGreen-3); QCD_2_SR->SetFillColor(kGreen-3);QCD_3_SR->SetFillColor(kGreen-3); QCD_4_SR->SetFillColor(kGreen-3); QCD_5_SR->SetFillColor(kGreen-3); QCD_6_SR->SetFillColor(kGreen-3); QCD_7_SR->SetFillColor(kGreen-3);
	QCD_SR->SetFillColor(kGreen-3);
	WToLNu_1_SR->SetFillColor(kCyan-4); WToLNu_2_SR->SetFillColor(kCyan-4); WToLNu_3_SR->SetFillColor(kCyan-4); WToLNu_4_SR->SetFillColor(kCyan-4); WToLNu_5_SR->SetFillColor(kCyan-4); WToLNu_6_SR->SetFillColor(kCyan-4); WToLNu_7_SR->SetFillColor(kCyan-4);
	TT_1_SR->SetFillColor(kGreen+3); TT_2_SR->SetFillColor(kGreen+3); 
	ST_1_SR->SetFillColor(kGreen+3); ST_2_SR->SetFillColor(kGreen+3); ST_3_SR->SetFillColor(kGreen+3); ST_4_SR->SetFillColor(kGreen+3); 
	ZZ1_SR->SetFillColor(kCyan+2); ZZ2_SR->SetFillColor(kCyan+2); ZZ3_SR->SetFillColor(kCyan+2); WW1_SR->SetFillColor(kCyan+2); WW2_SR->SetFillColor(kCyan+2); WZ1_SR->SetFillColor(kCyan+2); WZ2_SR->SetFillColor(kCyan+2); WZ3_SR->SetFillColor(kCyan+2); 
	data_SR->SetLineWidth(2); data_SR->SetLineColor(1); data_SR->SetMarkerColor(1); data_SR->SetMarkerStyle(20); data_SR->SetMarkerSize(1.3);
    Double_t dataErr   = 0; Float_t dataYield = data_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX()-1,dataErr,"");
    Double_t ZToNuNu_1Err   = 0; Float_t ZToNuNu_1Yield = ZToNuNu_1_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_1Err,"");
    Double_t ZToNuNu_2Err   = 0; Float_t ZToNuNu_2Yield = ZToNuNu_2_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_2Err,"");
    Double_t ZToNuNu_3Err   = 0; Float_t ZToNuNu_3Yield = ZToNuNu_3_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_3Err,"");
    Double_t ZToNuNu_4Err   = 0; Float_t ZToNuNu_4Yield = ZToNuNu_4_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_4Err,"");
	Double_t ZToNuNu_5Err   = 0; Float_t ZToNuNu_5Yield = ZToNuNu_5_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_5Err,"");
	Double_t ZToNuNu_6Err   = 0; Float_t ZToNuNu_6Yield = ZToNuNu_6_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_6Err,"");
	Double_t ZToNuNu_7Err   = 0; Float_t ZToNuNu_7Yield = ZToNuNu_7_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZToNuNu_7Err,"");
	//Double_t QCD_1Err   = 0; Float_t QCD_1Yield = QCD_1_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_1Err,"");
    //Double_t QCD_2Err   = 0; Float_t QCD_2Yield = QCD_2_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_2Err,"");
    //Double_t QCD_3Err   = 0; Float_t QCD_3Yield = QCD_3_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_3Err,"");
    //Double_t QCD_4Err   = 0; Float_t QCD_4Yield = QCD_4_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_4Err,"");
	//Double_t QCD_5Err   = 0; Float_t QCD_5Yield = QCD_5_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_5Err,"");
	//Double_t QCD_6Err   = 0; Float_t QCD_6Yield = QCD_6_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_6Err,"");
	//Double_t QCD_7Err   = 0; Float_t QCD_7Yield = QCD_7_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_7Err,"");
	Double_t QCD_Err   = 0; Float_t QCD_Yield = QCD_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),QCD_Err,"");
    Double_t WToLNu_1Err = 0; Float_t WToLNu_1Yield = WToLNu_1_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WToLNu_1Err,"");
	Double_t WToLNu_2Err = 0; Float_t WToLNu_2Yield = WToLNu_2_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WToLNu_2Err,"");
	Double_t WToLNu_3Err = 0; Float_t WToLNu_3Yield = WToLNu_3_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WToLNu_3Err,"");
	Double_t WToLNu_4Err = 0; Float_t WToLNu_4Yield = WToLNu_4_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WToLNu_4Err,"");
	Double_t WToLNu_5Err = 0; Float_t WToLNu_5Yield = WToLNu_5_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WToLNu_5Err,"");
	Double_t WToLNu_6Err = 0; Float_t WToLNu_6Yield = WToLNu_6_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WToLNu_6Err,"");
	Double_t WToLNu_7Err = 0; Float_t WToLNu_7Yield = WToLNu_7_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WToLNu_7Err,"");
    Double_t TT_1Err = 0; Float_t TT_1Yield = TT_1_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),TT_1Err,"");
	Double_t TT_2Err = 0; Float_t TT_2Yield = TT_2_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),TT_2Err,"");
    Double_t ST_1Err = 0; Float_t ST_1Yield = ST_1_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ST_1Err,"");
	Double_t ST_2Err = 0; Float_t ST_2Yield = ST_2_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ST_2Err,"");
	Double_t ST_3Err = 0; Float_t ST_3Yield = ST_3_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ST_3Err,"");
	Double_t ST_4Err = 0; Float_t ST_4Yield = ST_4_SR->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ST_4Err,"");
    Double_t ZZ1Err    = 0; Float_t ZZ1Yield  = ZZ1_SR ->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZZ1Err, "");
    Double_t ZZ2Err    = 0; Float_t ZZ2Yield  = ZZ2_SR ->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZZ2Err, "");
    Double_t ZZ3Err    = 0; Float_t ZZ3Yield  = ZZ3_SR ->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),ZZ3Err, "");
    Double_t WZ1Err    = 0; Float_t WZ1Yield  = WZ1_SR ->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WZ1Err, "");
    Double_t WZ2Err    = 0; Float_t WZ2Yield  = WZ2_SR ->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WZ2Err, "");
    Double_t WZ3Err    = 0; Float_t WZ3Yield  = WZ3_SR ->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WZ3Err, "");
    Double_t WW1Err    = 0; Float_t WW1Yield  = WW1_SR ->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WW1Err, "");
    Double_t WW2Err    = 0; Float_t WW2Yield  = WW2_SR ->IntegralAndError(1,tptzm0700lh_SR->GetNbinsX(),WW2Err, "");
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
      //cout<<"QCD       = "<<QCD_1_SR->Integral()+QCD_2_SR->Integral()+QCD_3_SR->Integral()+QCD_4_SR->Integral()+QCD_5_SR->Integral()+QCD_6_SR->Integral()+QCD_7_SR->Integral()<<" +/- "<<
	//sqrt(QCD_1Err*QCD_1Err+QCD_2Err*QCD_2Err+QCD_3Err*QCD_3Err+QCD_4Err*QCD_4Err+QCD_5Err*QCD_5Err+QCD_6Err*QCD_6Err+QCD_7Err*QCD_7Err)<<endl;
	  cout<<"QCD       = "<<QCD_SR->Integral()<<" +/- "<<sqrt(QCD_Err*QCD_Err)<<endl;
	  cout<<"WToLNu    = "<<WToLNu_1_SR->Integral()+WToLNu_2_SR->Integral()+WToLNu_3_SR->Integral()+WToLNu_4_SR->Integral()+WToLNu_5_SR->Integral()+WToLNu_6_SR->Integral()+WToLNu_7_SR->Integral()<<" +/- "<<sqrt(WToLNu_1Err*WToLNu_1Err+WToLNu_2Err*WToLNu_2Err+WToLNu_3Err*WToLNu_3Err+WToLNu_4Err*WToLNu_4Err+WToLNu_5Err*WToLNu_5Err+WToLNu_6Err*WToLNu_6Err+WToLNu_7Err*WToLNu_7Err)<<endl;
      //cout<<"WToLNu    = "<<WToLNu_SR->Integral()<<" +/- "<<sqrt(WToLNu_Err*WToLNu_Err)<<endl;
	  cout<<"TT        = "<<TT_1_SR->Integral()+TT_2_SR->Integral()<<" +/- "<<sqrt(TT_1Err*TT_1Err+TT_2Err*TT_2Err)<<endl;
	  cout<<"ST        = "<<ST_1_SR->Integral()+ST_2_SR->Integral()+ST_3_SR->Integral()+ST_4_SR->Integral()<<" +/- "<<sqrt(ST_1Err*ST_1Err+ST_2Err*ST_2Err+ST_3Err*ST_3Err+ST_4Err*ST_4Err)<<endl;
      cout<<"Diboson   = "<<ZZ1_SR->Integral()+ZZ2_SR->Integral()+ZZ3_SR->Integral()+WZ1_SR->Integral()+WZ2_SR->Integral()+WZ3_SR->Integral()+WW1_SR->Integral()+WW2_SR->Integral()<<" +/- "<<sqrt(ZZ1Err*ZZ1Err+ZZ2Err*ZZ2Err+ZZ3Err*ZZ3Err+WZ1Err*WZ1Err+WZ2Err*WZ2Err+WZ3Err*WZ3Err+WW1Err*WW1Err+WW2Err*WW2Err)<<endl;
      cout<<"Total BKG = "<<ZToNuNu_1_SR->Integral()+ZToNuNu_2_SR->Integral()+ZToNuNu_3_SR->Integral()+ZToNuNu_4_SR->Integral()+ZToNuNu_5_SR->Integral()+ZToNuNu_6_SR->Integral()+ZToNuNu_7_SR->Integral()+QCD_SR->Integral()/*QCD_1_SR->Integral()+QCD_2_SR->Integral()+QCD_3_SR->Integral()+QCD_4_SR->Integral()+QCD_5_SR->Integral()+QCD_6_SR->Integral()+QCD_7_SR->Integral()*/+WToLNu_1_SR->Integral()+WToLNu_2_SR->Integral()+WToLNu_3_SR->Integral()+WToLNu_4_SR->Integral()+WToLNu_5_SR->Integral()+WToLNu_6_SR->Integral()+WToLNu_7_SR->Integral()+TT_1_SR->Integral()+TT_2_SR->Integral()+ST_1_SR->Integral()+ST_2_SR->Integral()+ST_3_SR->Integral()+ST_4_SR->Integral()+ZZ1_SR->Integral()+ZZ2_SR->Integral()+ZZ3_SR->Integral()+WZ1_SR->Integral()+WZ2_SR->Integral()+WZ3_SR->Integral()+WW1_SR->Integral()+WW2_SR->Integral()<<" +/- "<<
		  sqrt(ZToNuNu_1Err*ZToNuNu_1Err+ZToNuNu_2Err*ZToNuNu_2Err+ZToNuNu_3Err*ZToNuNu_3Err+ZToNuNu_4Err*ZToNuNu_4Err+ZToNuNu_5Err*ZToNuNu_5Err+ZToNuNu_6Err*ZToNuNu_6Err+ZToNuNu_7Err*ZToNuNu_7Err+QCD_Err*QCD_Err/*+QCD_1Err*QCD_1Err+QCD_2Err*QCD_2Err+QCD_3Err*QCD_3Err+QCD_4Err*QCD_4Err+QCD_5Err*QCD_5Err+QCD_6Err*QCD_6Err+QCD_7Err*QCD_7Err*/+WToLNu_1Err*WToLNu_1Err+WToLNu_2Err*WToLNu_2Err+WToLNu_3Err*WToLNu_3Err+WToLNu_4Err*WToLNu_4Err+WToLNu_5Err*WToLNu_5Err+WToLNu_6Err*WToLNu_6Err+WToLNu_7Err*WToLNu_7Err+ZZ1Err*ZZ1Err+ZZ2Err*ZZ2Err+ZZ3Err*ZZ3Err+WZ1Err*WZ1Err+WZ2Err*WZ2Err+WZ3Err*WZ3Err+WW1Err*WW1Err+WW2Err*WW2Err+ST_1Err*ST_1Err+ST_2Err*ST_2Err+ST_3Err*ST_3Err+ST_4Err*ST_4Err+TT_1Err*TT_1Err+TT_2Err*TT_2Err)<<endl;
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
    hs->Add(TT_1_SR);
	hs->Add(TT_2_SR);
    hs->Add(WToLNu_1_SR);
	hs->Add(WToLNu_2_SR);
	hs->Add(WToLNu_3_SR);
    hs->Add(WToLNu_4_SR);
    hs->Add(WToLNu_5_SR);
	hs->Add(WToLNu_6_SR);
	hs->Add(WToLNu_7_SR);
	//hs->Add(WToLNu_SR);
    hs->Add(ZZ1_SR);
    hs->Add(ZZ2_SR);
    hs->Add(ZZ3_SR);
    hs->Add(WZ1_SR);
    hs->Add(WZ2_SR);
    hs->Add(WZ3_SR);
    hs->Add(WW1_SR);
    hs->Add(WW2_SR);
	/*hs->Add(QCD_1_SR);
    hs->Add(QCD_2_SR);
    hs->Add(QCD_3_SR);
    hs->Add(QCD_4_SR);
	hs->Add(QCD_5_SR);
	hs->Add(QCD_6_SR);
	hs->Add(QCD_7_SR);*/
	hs->Add(QCD_SR);
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
    tptzm0900lh_SR->Draw("samehisto");
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
		TH1F* &data_func,TH1F* &background_func,TH1F* &ZToNuNu_1_func,TH1F* &ZToNuNu_2_func,TH1F* &ZToNuNu_3_func,TH1F* &ZToNuNu_4_func,TH1F* &ZToNuNu_5_func,TH1F* &ZToNuNu_6_func,TH1F* &ZToNuNu_7_func,
		//TH1F* &QCD_1_func,TH1F* &QCD_2_func,TH1F* &QCD_3_func,TH1F* &QCD_4_func,TH1F* &QCD_5_func,TH1F* &QCD_6_func,TH1F* &QCD_7_func,
		TH1F* &QCD_func,
		TH1F* &WToLNu_1_func,TH1F* &WToLNu_2_func,TH1F* &WToLNu_3_func,TH1F* &WToLNu_4_func,TH1F* &WToLNu_5_func,TH1F* &WToLNu_6_func,TH1F* &WToLNu_7_func,
		TH1F* &TT_1_func,TH1F* &TT_2_func,TH1F* &ST_1_func,TH1F* &ST_2_func,TH1F* &ST_3_func,TH1F* &ST_4_func,
		TH1F* &ZZ1_func,TH1F* &ZZ2_func,TH1F* &ZZ3_func,TH1F* &WW1_func,TH1F* &WW2_func,TH1F* &WZ1_func,TH1F* &WZ2_func,TH1F* &WZ3_func, TH1F* &WToLNu_func,
		TH1F* &tptzm0700lh_func,TH1F* &tptzm0900lh_func,TH1F* &tptzm1400lh_func,TH1F* &tptzm1700lh_func){
  TH1F *data; TH1F *tptzm0700lh; TH1F *tptzm0900lh; TH1F *tptzm1400lh; TH1F *tptzm1700lh; 
  TH1F *ZToNuNu_1; TH1F *ZToNuNu_2; TH1F *ZToNuNu_3; TH1F *ZToNuNu_4; TH1F *ZToNuNu_5; TH1F *ZToNuNu_6; TH1F *ZToNuNu_7; 
  //TH1F *QCD_1; TH1F *QCD_2; TH1F *QCD_3; TH1F *QCD_4; TH1F *QCD_5; TH1F *QCD_6; TH1F *QCD_7; 
  TH1F *QCD = new TH1F("", "", BIN,MIN,MAX);
  TH1F *WToLNu_1; TH1F *WToLNu_2; TH1F *WToLNu_3; TH1F *WToLNu_4; TH1F *WToLNu_5; TH1F *WToLNu_6; TH1F *WToLNu_7;
  TH1F *TT_1; TH1F *TT_2; TH1F *ST_1; TH1F *ST_2; TH1F *ST_3; TH1F *ST_4; 
  TH1F *ZZ1; TH1F *ZZ2; TH1F *ZZ3; TH1F *WZ1; TH1F *WZ2; TH1F *WZ3; TH1F *WW1; TH1F *WW2; TH1F *WToLNu;

  TH1F *data_B; TH1F *tptzm0700lh_B; TH1F *tptzm0900lh_B; TH1F *tptzm1400lh_B; TH1F *tptzm1700lh_B; 
  TH1F *ZToNuNu_1_B; TH1F *ZToNuNu_2_B; TH1F *ZToNuNu_3_B; TH1F *ZToNuNu_4_B; TH1F *ZToNuNu_5_B; TH1F *ZToNuNu_6_B; TH1F *ZToNuNu_7_B; 
  //TH1F *QCD_1; TH1F *QCD_2; TH1F *QCD_3; TH1F *QCD_4; TH1F *QCD_5; TH1F *QCD_6; TH1F *QCD_7; 
  TH1F *WToLNu_1_B; TH1F *WToLNu_2_B; TH1F *WToLNu_3_B; TH1F *WToLNu_4_B; TH1F *WToLNu_5_B; TH1F *WToLNu_6_B; TH1F *WToLNu_7_B;
  TH1F *TT_1_B; TH1F *TT_2_B; TH1F *ST_1_B; TH1F *ST_2_B; TH1F *ST_3_B; TH1F *ST_4_B; 
  TH1F *ZZ1_B; TH1F *ZZ2_B; TH1F *ZZ3_B; TH1F *WZ1_B; TH1F *WZ2_B; TH1F *WZ3_B; TH1F *WW1_B; TH1F *WW2_B; TH1F *WToLNu_B;

  TH1F *data_C; TH1F *tptzm0700lh_C; TH1F *tptzm0900lh_C; TH1F *tptzm1400lh_C; TH1F *tptzm1700lh_C; 
  TH1F *ZToNuNu_1_C; TH1F *ZToNuNu_2_C; TH1F *ZToNuNu_3_C; TH1F *ZToNuNu_4_C; TH1F *ZToNuNu_5_C; TH1F *ZToNuNu_6_C; TH1F *ZToNuNu_7_C; 
  //TH1F *QCD_1; TH1F *QCD_2; TH1F *QCD_3; TH1F *QCD_4; TH1F *QCD_5; TH1F *QCD_6; TH1F *QCD_7; 
  TH1F *WToLNu_1_C; TH1F *WToLNu_2_C; TH1F *WToLNu_3_C; TH1F *WToLNu_4_C; TH1F *WToLNu_5_C; TH1F *WToLNu_6_C; TH1F *WToLNu_7_C;
  TH1F *TT_1_C; TH1F *TT_2_C; TH1F *ST_1_C; TH1F *ST_2_C; TH1F *ST_3_C; TH1F *ST_4_C; 
  TH1F *ZZ1_C; TH1F *ZZ2_C; TH1F *ZZ3_C; TH1F *WZ1_C; TH1F *WZ2_C; TH1F *WZ3_C; TH1F *WW1_C; TH1F *WW2_C; TH1F *WToLNu_C;

  TH1F *data_D; TH1F *tptzm0700lh_D; TH1F *tptzm0900lh_D; TH1F *tptzm1400lh_D; TH1F *tptzm1700lh_D; 
  TH1F *ZToNuNu_1_D; TH1F *ZToNuNu_2_D; TH1F *ZToNuNu_3_D; TH1F *ZToNuNu_4_D; TH1F *ZToNuNu_5_D; TH1F *ZToNuNu_6_D; TH1F *ZToNuNu_7_D; 
  //TH1F *QCD_1; TH1F *QCD_2; TH1F *QCD_3; TH1F *QCD_4; TH1F *QCD_5; TH1F *QCD_6; TH1F *QCD_7; 
  TH1F *WToLNu_1_D; TH1F *WToLNu_2_D; TH1F *WToLNu_3_D; TH1F *WToLNu_4_D; TH1F *WToLNu_5_D; TH1F *WToLNu_6_D; TH1F *WToLNu_7_D;
  TH1F *TT_1_D; TH1F *TT_2_D; TH1F *ST_1_D; TH1F *ST_2_D; TH1F *ST_3_D; TH1F *ST_4_D; 
  TH1F *ZZ1_D; TH1F *ZZ2_D; TH1F *ZZ3_D; TH1F *WZ1_D; TH1F *WZ2_D; TH1F *WZ3_D; TH1F *WW1_D; TH1F *WW2_D; TH1F *WToLNu_D;

  if(JETSyst==0){
    GetHisto(CUT, Tree01, data        ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree02, tptzm0700lh ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree04, tptzm0900lh ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree09, tptzm1400lh ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree12, tptzm1700lh ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree14, ZToNuNu_1   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree15, ZToNuNu_2   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree16, ZToNuNu_3   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree17, ZToNuNu_4   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree18, ZToNuNu_5   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree19, ZToNuNu_6   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree20, ZToNuNu_7   ,plot,BIN,MIN,MAX);
    /*GetHisto(CUT, Tree21, QCD_1      ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree22, QCD_2      ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree23, QCD_3      ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree24, QCD_4      ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree25, QCD_5      ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree26, QCD_6      ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree27, QCD_7      ,plot,BIN,MIN,MAX);*/
	GetHisto(CUT, Tree28, WToLNu_1   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree29, WToLNu_2   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree30, WToLNu_3   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree31, WToLNu_4   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree32, WToLNu_5   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree33, WToLNu_6   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree34, WToLNu_7   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree35, TT_1    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree36, TT_2    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree37, ST_1    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree38, ST_2    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree39, ST_3    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree40, ST_4    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree41, ZZ1    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree42, ZZ2    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree43, ZZ3    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree44, WW1    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree45, WW2    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree46, WZ1    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree47, WZ2    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree48, WZ3    ,plot,BIN,MIN,MAX);
	//GetHisto(CUT, Tree49, WToLNu ,plot,BIN,MIN,MAX);

	GetHisto(CUT, Tree01_B, data_B        ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree02_B, tptzm0700lh_B ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree04_B, tptzm0900lh_B ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree09_B, tptzm1400lh_B ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree12_B, tptzm1700lh_B ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree14_B, ZToNuNu_1_B   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree15_B, ZToNuNu_2_B   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree16_B, ZToNuNu_3_B   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree17_B, ZToNuNu_4_B   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree18_B, ZToNuNu_5_B   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree19_B, ZToNuNu_6_B   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree20_B, ZToNuNu_7_B   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree28_B, WToLNu_1_B   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree29_B, WToLNu_2_B   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree30_B, WToLNu_3_B   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree31_B, WToLNu_4_B   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree32_B, WToLNu_5_B   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree33_B, WToLNu_6_B   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree34_B, WToLNu_7_B   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree35_B, TT_1_B    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree36_B, TT_2_B    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree37_B, ST_1_B    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree38_B, ST_2_B    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree39_B, ST_3_B    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree40_B, ST_4_B    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree41_B, ZZ1_B    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree42_B, ZZ2_B    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree43_B, ZZ3_B    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree44_B, WW1_B    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree45_B, WW2_B    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree46_B, WZ1_B    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree47_B, WZ2_B    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree48_B, WZ3_B    ,plot,BIN,MIN,MAX);
	//GetHisto(CUT, Tree49, WToLNu ,plot,BIN,MIN,MAX);

	GetHisto(CUT, Tree01_C, data_C        ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree02_C, tptzm0700lh_C ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree04_C, tptzm0900lh_C ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree09_C, tptzm1400lh_C ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree12_C, tptzm1700lh_C ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree14_C, ZToNuNu_1_C   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree15_C, ZToNuNu_2_C   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree16_C, ZToNuNu_3_C   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree17_C, ZToNuNu_4_C   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree18_C, ZToNuNu_5_C   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree19_C, ZToNuNu_6_C   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree20_C, ZToNuNu_7_C   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree28_C, WToLNu_1_C   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree29_C, WToLNu_2_C   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree30_C, WToLNu_3_C   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree31_C, WToLNu_4_C   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree32_C, WToLNu_5_C   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree33_C, WToLNu_6_C   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree34_C, WToLNu_7_C   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree35_C, TT_1_C    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree36_C, TT_2_C    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree37_C, ST_1_C    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree38_C, ST_2_C    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree39_C, ST_3_C    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree40_C, ST_4_C    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree41_C, ZZ1_C    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree42_C, ZZ2_C    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree43_C, ZZ3_C    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree44_C, WW1_C    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree45_C, WW2_C    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree46_C, WZ1_C    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree47_C, WZ2_C    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree48_C, WZ3_C    ,plot,BIN,MIN,MAX);

	GetHisto(CUT, Tree01_D, data_D        ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree02_D, tptzm0700lh_D ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree04_D, tptzm0900lh_D ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree09_D, tptzm1400lh_D ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree12_D, tptzm1700lh_D ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree14_D, ZToNuNu_1_D   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree15_D, ZToNuNu_2_D   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree16_D, ZToNuNu_3_D   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree17_D, ZToNuNu_4_D   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree18_D, ZToNuNu_5_D   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree19_D, ZToNuNu_6_D   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree20_D, ZToNuNu_7_D   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree28_D, WToLNu_1_D   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree29_D, WToLNu_2_D   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree30_D, WToLNu_3_D   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree31_D, WToLNu_4_D   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree32_D, WToLNu_5_D   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree33_D, WToLNu_6_D   ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree34_D, WToLNu_7_D   ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree35_D, TT_1_D    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree36_D, TT_2_D    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree37_D, ST_1_D    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree38_D, ST_2_D    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree39_D, ST_3_D    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree40_D, ST_4_D    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree41_D, ZZ1_D    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree42_D, ZZ2_D    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree43_D, ZZ3_D    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree44_D, WW1_D    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree45_D, WW2_D    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree46_D, WZ1_D    ,plot,BIN,MIN,MAX);
    GetHisto(CUT, Tree47_D, WZ2_D    ,plot,BIN,MIN,MAX);
	GetHisto(CUT, Tree48_D, WZ3_D    ,plot,BIN,MIN,MAX);


  }  
  
  TH1F *background = new TH1F("","",data->GetNbinsX(),data->GetXaxis()->GetXmin(),data->GetXaxis()->GetXmax());
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
    //if(QCD_1->GetBinContent(j)>0){QCD_1 ->SetBinError(j,sqrt(w08*w08*QCD_1 ->GetBinContent(j)));}else{QCD_1 ->SetBinError(j,0);}//w08);}
    //if(QCD_2->GetBinContent(j)>0){QCD_2 ->SetBinError(j,sqrt(w09*w09*QCD_2 ->GetBinContent(j)));}else{QCD_2 ->SetBinError(j,0);}//w09);}
    //if(QCD_3->GetBinContent(j)>0){QCD_3 ->SetBinError(j,sqrt(w10*w10*QCD_3 ->GetBinContent(j)));}else{QCD_3 ->SetBinError(j,0);}//w10);}
	//if(QCD_4->GetBinContent(j)>0){QCD_4 ->SetBinError(j,sqrt(w11*w11*QCD_4 ->GetBinContent(j)));}else{QCD_4 ->SetBinError(j,0);}//w11);}
    //if(QCD_5->GetBinContent(j)>0){QCD_5 ->SetBinError(j,sqrt(w12*w12*QCD_5 ->GetBinContent(j)));}else{QCD_5 ->SetBinError(j,0);}//w12);}
    //if(QCD_6->GetBinContent(j)>0){QCD_6 ->SetBinError(j,sqrt(w13*w13*QCD_6 ->GetBinContent(j)));}else{QCD_6 ->SetBinError(j,0);}//w13);}
    //if(QCD_7->GetBinContent(j)>0){QCD_7 ->SetBinError(j,sqrt(w14*w14*QCD_7 ->GetBinContent(j)));}else{QCD_7 ->SetBinError(j,0);}//w14);}
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

	if(tptzm0700lh_B->GetBinContent(j)>0){tptzm0700lh_B->SetBinError(j,sqrt(w0700*w0700*tptzm0700lh_B->GetBinContent(j)));}else{tptzm0700lh_B->SetBinError(j,0);}
    if(tptzm0900lh_B->GetBinContent(j)>0){tptzm0900lh_B->SetBinError(j,sqrt(w0900*w0900*tptzm0900lh_B->GetBinContent(j)));}else{tptzm0900lh_B->SetBinError(j,0);}
    if(tptzm1400lh_B->GetBinContent(j)>0){tptzm1400lh_B->SetBinError(j,sqrt(w1400*w1400*tptzm1400lh_B->GetBinContent(j)));}else{tptzm1400lh_B->SetBinError(j,0);}
    if(tptzm1700lh_B->GetBinContent(j)>0){tptzm1700lh_B->SetBinError(j,sqrt(w1700*w1700*tptzm1700lh_B->GetBinContent(j)));}else{tptzm1700lh_B->SetBinError(j,0);}
    if(ZToNuNu_1_B ->GetBinContent(j)>0){ZToNuNu_1_B ->SetBinError(j,sqrt(w01*w01*ZToNuNu_1_B ->GetBinContent(j)));}else{ZToNuNu_1_B ->SetBinError(j,0);}//w01);}
    if(ZToNuNu_2_B ->GetBinContent(j)>0){ZToNuNu_2_B ->SetBinError(j,sqrt(w02*w02*ZToNuNu_2_B ->GetBinContent(j)));}else{ZToNuNu_2_B ->SetBinError(j,0);}//w02);}
    if(ZToNuNu_3_B ->GetBinContent(j)>0){ZToNuNu_3_B ->SetBinError(j,sqrt(w03*w03*ZToNuNu_3_B ->GetBinContent(j)));}else{ZToNuNu_3_B ->SetBinError(j,0);}//w03);}
    if(ZToNuNu_4_B ->GetBinContent(j)>0){ZToNuNu_4_B ->SetBinError(j,sqrt(w04*w04*ZToNuNu_4_B ->GetBinContent(j)));}else{ZToNuNu_4_B ->SetBinError(j,0);}//w04);}
	if(ZToNuNu_5_B ->GetBinContent(j)>0){ZToNuNu_5_B ->SetBinError(j,sqrt(w05*w05*ZToNuNu_5_B ->GetBinContent(j)));}else{ZToNuNu_5_B ->SetBinError(j,0);}//w05);}
	if(ZToNuNu_6_B ->GetBinContent(j)>0){ZToNuNu_6_B ->SetBinError(j,sqrt(w06*w06*ZToNuNu_6_B ->GetBinContent(j)));}else{ZToNuNu_6_B ->SetBinError(j,0);}//w06);}
	if(ZToNuNu_7_B ->GetBinContent(j)>0){ZToNuNu_7_B ->SetBinError(j,sqrt(w07*w07*ZToNuNu_7_B ->GetBinContent(j)));}else{ZToNuNu_7_B ->SetBinError(j,0);}//w07);}
    if(WToLNu_1_B->GetBinContent(j)>0){WToLNu_1_B->SetBinError(j,sqrt(w15*w15*WToLNu_1_B->GetBinContent(j)));}else{WToLNu_1_B->SetBinError(j,0);}//w15);}
	if(WToLNu_2_B->GetBinContent(j)>0){WToLNu_2_B->SetBinError(j,sqrt(w16*w16*WToLNu_2_B->GetBinContent(j)));}else{WToLNu_2_B->SetBinError(j,0);}//w16);}
	if(WToLNu_3_B->GetBinContent(j)>0){WToLNu_3_B->SetBinError(j,sqrt(w17*w17*WToLNu_3_B->GetBinContent(j)));}else{WToLNu_3_B->SetBinError(j,0);}//w17);}
	if(WToLNu_4_B->GetBinContent(j)>0){WToLNu_4_B->SetBinError(j,sqrt(w18*w18*WToLNu_4_B->GetBinContent(j)));}else{WToLNu_4_B->SetBinError(j,0);}//w18);}
	if(WToLNu_5_B->GetBinContent(j)>0){WToLNu_5_B->SetBinError(j,sqrt(w19*w19*WToLNu_5_B->GetBinContent(j)));}else{WToLNu_5_B->SetBinError(j,0);}//w19);}
	if(WToLNu_6_B->GetBinContent(j)>0){WToLNu_6_B->SetBinError(j,sqrt(w20*w20*WToLNu_6_B->GetBinContent(j)));}else{WToLNu_6_B->SetBinError(j,0);}//w20);}
	if(WToLNu_7_B->GetBinContent(j)>0){WToLNu_7_B->SetBinError(j,sqrt(w21*w21*WToLNu_7_B->GetBinContent(j)));}else{WToLNu_7_B->SetBinError(j,0);}//w21);}
	if(TT_1_B->GetBinContent(j)>0){TT_1_B->SetBinError(j,sqrt(w22*w22*TT_1_B->GetBinContent(j)));}else{TT_1_B->SetBinError(j,0);}//w22);}
	if(TT_2_B->GetBinContent(j)>0){TT_2_B->SetBinError(j,sqrt(w23*w23*TT_2_B->GetBinContent(j)));}else{TT_2_B->SetBinError(j,0);}//w23);}
    if(ST_1_B->GetBinContent(j)>0){ST_1_B->SetBinError(j,sqrt(w24*w24*ST_1_B->GetBinContent(j)));}else{ST_1_B->SetBinError(j,0);}//w24);}
    if(ST_2_B->GetBinContent(j)>0){ST_2_B->SetBinError(j,sqrt(w25*w25*ST_2_B->GetBinContent(j)));}else{ST_2_B->SetBinError(j,0);}//w25);}
    if(ST_3_B->GetBinContent(j)>0){ST_3_B->SetBinError(j,sqrt(w26*w26*ST_3_B->GetBinContent(j)));}else{ST_3_B->SetBinError(j,0);}//w26);}
    if(ST_4_B->GetBinContent(j)>0){ST_4_B->SetBinError(j,sqrt(w27*w27*ST_4_B->GetBinContent(j)));}else{ST_4_B->SetBinError(j,0);}//w27);}
    if(ZZ1_B->GetBinContent(j)>0){ZZ1_B->SetBinError(j,sqrt(w28*w28*ZZ1_B->GetBinContent(j)));}else{ZZ1_B->SetBinError(j,0);}//w28);}
	if(ZZ2_B->GetBinContent(j)>0){ZZ2_B->SetBinError(j,sqrt(w29*w29*ZZ2_B->GetBinContent(j)));}else{ZZ2_B->SetBinError(j,0);}//w29);}
	if(ZZ3_B->GetBinContent(j)>0){ZZ3_B->SetBinError(j,sqrt(w30*w30*ZZ3_B->GetBinContent(j)));}else{ZZ3_B->SetBinError(j,0);}//w30);}
    if(WW1_B->GetBinContent(j)>0){WW1_B->SetBinError(j,sqrt(w31*w31*WW1_B->GetBinContent(j)));}else{WW1_B->SetBinError(j,0);}//w31);}
	if(WW2_B->GetBinContent(j)>0){WW2_B->SetBinError(j,sqrt(w32*w32*WW2_B->GetBinContent(j)));}else{WW2_B->SetBinError(j,0);}//w32);}
	if(WZ1_B->GetBinContent(j)>0){WZ1_B->SetBinError(j,sqrt(w33*w33*WZ1_B->GetBinContent(j)));}else{WZ1_B->SetBinError(j,0);}//w33);}
	if(WZ2_B->GetBinContent(j)>0){WZ2_B->SetBinError(j,sqrt(w34*w34*WZ2_B->GetBinContent(j)));}else{WZ2_B->SetBinError(j,0);}//w34);}
	if(WZ3_B->GetBinContent(j)>0){WZ3_B->SetBinError(j,sqrt(w35*w35*WZ3_B->GetBinContent(j)));}else{WZ3_B->SetBinError(j,0);}//w35);}

	if(tptzm0700lh_C->GetBinContent(j)>0){tptzm0700lh_C->SetBinError(j,sqrt(w0700*w0700*tptzm0700lh_C->GetBinContent(j)));}else{tptzm0700lh_C->SetBinError(j,0);}
    if(tptzm0900lh_C->GetBinContent(j)>0){tptzm0900lh_C->SetBinError(j,sqrt(w0900*w0900*tptzm0900lh_C->GetBinContent(j)));}else{tptzm0900lh_C->SetBinError(j,0);}
    if(tptzm1400lh_C->GetBinContent(j)>0){tptzm1400lh_C->SetBinError(j,sqrt(w1400*w1400*tptzm1400lh_C->GetBinContent(j)));}else{tptzm1400lh_C->SetBinError(j,0);}
    if(tptzm1700lh_C->GetBinContent(j)>0){tptzm1700lh_C->SetBinError(j,sqrt(w1700*w1700*tptzm1700lh_C->GetBinContent(j)));}else{tptzm1700lh_C->SetBinError(j,0);}
    if(ZToNuNu_1_C ->GetBinContent(j)>0){ZToNuNu_1_C ->SetBinError(j,sqrt(w01*w01*ZToNuNu_1_C ->GetBinContent(j)));}else{ZToNuNu_1_C ->SetBinError(j,0);}//w01);}
    if(ZToNuNu_2_C ->GetBinContent(j)>0){ZToNuNu_2_C ->SetBinError(j,sqrt(w02*w02*ZToNuNu_2_C ->GetBinContent(j)));}else{ZToNuNu_2_C ->SetBinError(j,0);}//w02);}
    if(ZToNuNu_3_C ->GetBinContent(j)>0){ZToNuNu_3_C ->SetBinError(j,sqrt(w03*w03*ZToNuNu_3_C ->GetBinContent(j)));}else{ZToNuNu_3_C ->SetBinError(j,0);}//w03);}
    if(ZToNuNu_4_C ->GetBinContent(j)>0){ZToNuNu_4_C ->SetBinError(j,sqrt(w04*w04*ZToNuNu_4_C ->GetBinContent(j)));}else{ZToNuNu_4_C ->SetBinError(j,0);}//w04);}
	if(ZToNuNu_5_C ->GetBinContent(j)>0){ZToNuNu_5_C ->SetBinError(j,sqrt(w05*w05*ZToNuNu_5_C ->GetBinContent(j)));}else{ZToNuNu_5_C ->SetBinError(j,0);}//w05);}
	if(ZToNuNu_6_C ->GetBinContent(j)>0){ZToNuNu_6_C ->SetBinError(j,sqrt(w06*w06*ZToNuNu_6_C ->GetBinContent(j)));}else{ZToNuNu_6_C ->SetBinError(j,0);}//w06);}
	if(ZToNuNu_7_C ->GetBinContent(j)>0){ZToNuNu_7_C ->SetBinError(j,sqrt(w07*w07*ZToNuNu_7_C ->GetBinContent(j)));}else{ZToNuNu_7_C ->SetBinError(j,0);}//w07);}
    if(WToLNu_1_C->GetBinContent(j)>0){WToLNu_1_C->SetBinError(j,sqrt(w15*w15*WToLNu_1_C->GetBinContent(j)));}else{WToLNu_1_C->SetBinError(j,0);}//w15);}
	if(WToLNu_2_C->GetBinContent(j)>0){WToLNu_2_C->SetBinError(j,sqrt(w16*w16*WToLNu_2_C->GetBinContent(j)));}else{WToLNu_2_C->SetBinError(j,0);}//w16);}
	if(WToLNu_3_C->GetBinContent(j)>0){WToLNu_3_C->SetBinError(j,sqrt(w17*w17*WToLNu_3_C->GetBinContent(j)));}else{WToLNu_3_C->SetBinError(j,0);}//w17);}
	if(WToLNu_4_C->GetBinContent(j)>0){WToLNu_4_C->SetBinError(j,sqrt(w18*w18*WToLNu_4_C->GetBinContent(j)));}else{WToLNu_4_C->SetBinError(j,0);}//w18);}
	if(WToLNu_5_C->GetBinContent(j)>0){WToLNu_5_C->SetBinError(j,sqrt(w19*w19*WToLNu_5_C->GetBinContent(j)));}else{WToLNu_5_C->SetBinError(j,0);}//w19);}
	if(WToLNu_6_C->GetBinContent(j)>0){WToLNu_6_C->SetBinError(j,sqrt(w20*w20*WToLNu_6_C->GetBinContent(j)));}else{WToLNu_6_C->SetBinError(j,0);}//w20);}
	if(WToLNu_7_C->GetBinContent(j)>0){WToLNu_7_C->SetBinError(j,sqrt(w21*w21*WToLNu_7_C->GetBinContent(j)));}else{WToLNu_7_C->SetBinError(j,0);}//w21);}
	if(TT_1_C->GetBinContent(j)>0){TT_1_C->SetBinError(j,sqrt(w22*w22*TT_1_C->GetBinContent(j)));}else{TT_1_C->SetBinError(j,0);}//w22);}
	if(TT_2_C->GetBinContent(j)>0){TT_2_C->SetBinError(j,sqrt(w23*w23*TT_2_C->GetBinContent(j)));}else{TT_2_C->SetBinError(j,0);}//w23);}
    if(ST_1_C->GetBinContent(j)>0){ST_1_C->SetBinError(j,sqrt(w24*w24*ST_1_C->GetBinContent(j)));}else{ST_1_C->SetBinError(j,0);}//w24);}
    if(ST_2_C->GetBinContent(j)>0){ST_2_C->SetBinError(j,sqrt(w25*w25*ST_2_C->GetBinContent(j)));}else{ST_2_C->SetBinError(j,0);}//w25);}
    if(ST_3_C->GetBinContent(j)>0){ST_3_C->SetBinError(j,sqrt(w26*w26*ST_3_C->GetBinContent(j)));}else{ST_3_C->SetBinError(j,0);}//w26);}
    if(ST_4_C->GetBinContent(j)>0){ST_4_C->SetBinError(j,sqrt(w27*w27*ST_4_C->GetBinContent(j)));}else{ST_4_C->SetBinError(j,0);}//w27);}
    if(ZZ1_C->GetBinContent(j)>0){ZZ1_C->SetBinError(j,sqrt(w28*w28*ZZ1_C->GetBinContent(j)));}else{ZZ1_C->SetBinError(j,0);}//w28);}
	if(ZZ2_C->GetBinContent(j)>0){ZZ2_C->SetBinError(j,sqrt(w29*w29*ZZ2_C->GetBinContent(j)));}else{ZZ2_C->SetBinError(j,0);}//w29);}
	if(ZZ3_C->GetBinContent(j)>0){ZZ3_C->SetBinError(j,sqrt(w30*w30*ZZ3_C->GetBinContent(j)));}else{ZZ3_C->SetBinError(j,0);}//w30);}
    if(WW1_C->GetBinContent(j)>0){WW1_C->SetBinError(j,sqrt(w31*w31*WW1_C->GetBinContent(j)));}else{WW1_C->SetBinError(j,0);}//w31);}
	if(WW2_C->GetBinContent(j)>0){WW2_C->SetBinError(j,sqrt(w32*w32*WW2_C->GetBinContent(j)));}else{WW2_C->SetBinError(j,0);}//w32);}
	if(WZ1_C->GetBinContent(j)>0){WZ1_C->SetBinError(j,sqrt(w33*w33*WZ1_C->GetBinContent(j)));}else{WZ1_C->SetBinError(j,0);}//w33);}
	if(WZ2_C->GetBinContent(j)>0){WZ2_C->SetBinError(j,sqrt(w34*w34*WZ2_C->GetBinContent(j)));}else{WZ2_C->SetBinError(j,0);}//w34);}
	if(WZ3_C->GetBinContent(j)>0){WZ3_C->SetBinError(j,sqrt(w35*w35*WZ3_C->GetBinContent(j)));}else{WZ3_C->SetBinError(j,0);}//w35);}

	if(tptzm0700lh_D->GetBinContent(j)>0){tptzm0700lh_D->SetBinError(j,sqrt(w0700*w0700*tptzm0700lh_D->GetBinContent(j)));}else{tptzm0700lh_D->SetBinError(j,0);}
    if(tptzm0900lh_D->GetBinContent(j)>0){tptzm0900lh_D->SetBinError(j,sqrt(w0900*w0900*tptzm0900lh_D->GetBinContent(j)));}else{tptzm0900lh_D->SetBinError(j,0);}
    if(tptzm1400lh_D->GetBinContent(j)>0){tptzm1400lh_D->SetBinError(j,sqrt(w1400*w1400*tptzm1400lh_D->GetBinContent(j)));}else{tptzm1400lh_D->SetBinError(j,0);}
    if(tptzm1700lh_D->GetBinContent(j)>0){tptzm1700lh_D->SetBinError(j,sqrt(w1700*w1700*tptzm1700lh_D->GetBinContent(j)));}else{tptzm1700lh_D->SetBinError(j,0);}
    if(ZToNuNu_1_D ->GetBinContent(j)>0){ZToNuNu_1_D ->SetBinError(j,sqrt(w01*w01*ZToNuNu_1_D ->GetBinContent(j)));}else{ZToNuNu_1_D ->SetBinError(j,0);}//w01);}
    if(ZToNuNu_2_D ->GetBinContent(j)>0){ZToNuNu_2_D ->SetBinError(j,sqrt(w02*w02*ZToNuNu_2_D ->GetBinContent(j)));}else{ZToNuNu_2_D ->SetBinError(j,0);}//w02);}
    if(ZToNuNu_3_D ->GetBinContent(j)>0){ZToNuNu_3_D ->SetBinError(j,sqrt(w03*w03*ZToNuNu_3_D ->GetBinContent(j)));}else{ZToNuNu_3_D ->SetBinError(j,0);}//w03);}
    if(ZToNuNu_4_D ->GetBinContent(j)>0){ZToNuNu_4_D ->SetBinError(j,sqrt(w04*w04*ZToNuNu_4_D ->GetBinContent(j)));}else{ZToNuNu_4_D ->SetBinError(j,0);}//w04);}
	if(ZToNuNu_5_D ->GetBinContent(j)>0){ZToNuNu_5_D ->SetBinError(j,sqrt(w05*w05*ZToNuNu_5_D ->GetBinContent(j)));}else{ZToNuNu_5_D ->SetBinError(j,0);}//w05);}
	if(ZToNuNu_6_D ->GetBinContent(j)>0){ZToNuNu_6_D ->SetBinError(j,sqrt(w06*w06*ZToNuNu_6_D ->GetBinContent(j)));}else{ZToNuNu_6_D ->SetBinError(j,0);}//w06);}
	if(ZToNuNu_7_D ->GetBinContent(j)>0){ZToNuNu_7_D ->SetBinError(j,sqrt(w07*w07*ZToNuNu_7_D ->GetBinContent(j)));}else{ZToNuNu_7_D ->SetBinError(j,0);}//w07);}
    if(WToLNu_1_D->GetBinContent(j)>0){WToLNu_1_D->SetBinError(j,sqrt(w15*w15*WToLNu_1_D->GetBinContent(j)));}else{WToLNu_1_D->SetBinError(j,0);}//w15);}
	if(WToLNu_2_D->GetBinContent(j)>0){WToLNu_2_D->SetBinError(j,sqrt(w16*w16*WToLNu_2_D->GetBinContent(j)));}else{WToLNu_2_D->SetBinError(j,0);}//w16);}
	if(WToLNu_3_D->GetBinContent(j)>0){WToLNu_3_D->SetBinError(j,sqrt(w17*w17*WToLNu_3_D->GetBinContent(j)));}else{WToLNu_3_D->SetBinError(j,0);}//w17);}
	if(WToLNu_4_D->GetBinContent(j)>0){WToLNu_4_D->SetBinError(j,sqrt(w18*w18*WToLNu_4_D->GetBinContent(j)));}else{WToLNu_4_D->SetBinError(j,0);}//w18);}
	if(WToLNu_5_D->GetBinContent(j)>0){WToLNu_5_D->SetBinError(j,sqrt(w19*w19*WToLNu_5_D->GetBinContent(j)));}else{WToLNu_5_D->SetBinError(j,0);}//w19);}
	if(WToLNu_6_D->GetBinContent(j)>0){WToLNu_6_D->SetBinError(j,sqrt(w20*w20*WToLNu_6_D->GetBinContent(j)));}else{WToLNu_6_D->SetBinError(j,0);}//w20);}
	if(WToLNu_7_D->GetBinContent(j)>0){WToLNu_7_D->SetBinError(j,sqrt(w21*w21*WToLNu_7_D->GetBinContent(j)));}else{WToLNu_7_D->SetBinError(j,0);}//w21);}
	if(TT_1_D->GetBinContent(j)>0){TT_1_D->SetBinError(j,sqrt(w22*w22*TT_1_D->GetBinContent(j)));}else{TT_1_D->SetBinError(j,0);}//w22);}
	if(TT_2_D->GetBinContent(j)>0){TT_2_D->SetBinError(j,sqrt(w23*w23*TT_2_D->GetBinContent(j)));}else{TT_2_D->SetBinError(j,0);}//w23);}
    if(ST_1_D->GetBinContent(j)>0){ST_1_D->SetBinError(j,sqrt(w24*w24*ST_1_D->GetBinContent(j)));}else{ST_1_D->SetBinError(j,0);}//w24);}
    if(ST_2_D->GetBinContent(j)>0){ST_2_D->SetBinError(j,sqrt(w25*w25*ST_2_D->GetBinContent(j)));}else{ST_2_D->SetBinError(j,0);}//w25);}
    if(ST_3_D->GetBinContent(j)>0){ST_3_D->SetBinError(j,sqrt(w26*w26*ST_3_D->GetBinContent(j)));}else{ST_3_D->SetBinError(j,0);}//w26);}
    if(ST_4_D->GetBinContent(j)>0){ST_4_D->SetBinError(j,sqrt(w27*w27*ST_4_D->GetBinContent(j)));}else{ST_4_D->SetBinError(j,0);}//w27);}
    if(ZZ1_D->GetBinContent(j)>0){ZZ1_D->SetBinError(j,sqrt(w28*w28*ZZ1_D->GetBinContent(j)));}else{ZZ1_D->SetBinError(j,0);}//w28);}
	if(ZZ2_D->GetBinContent(j)>0){ZZ2_D->SetBinError(j,sqrt(w29*w29*ZZ2_D->GetBinContent(j)));}else{ZZ2_D->SetBinError(j,0);}//w29);}
	if(ZZ3_D->GetBinContent(j)>0){ZZ3_D->SetBinError(j,sqrt(w30*w30*ZZ3_D->GetBinContent(j)));}else{ZZ3_D->SetBinError(j,0);}//w30);}
    if(WW1_D->GetBinContent(j)>0){WW1_D->SetBinError(j,sqrt(w31*w31*WW1_D->GetBinContent(j)));}else{WW1_D->SetBinError(j,0);}//w31);}
	if(WW2_D->GetBinContent(j)>0){WW2_D->SetBinError(j,sqrt(w32*w32*WW2_D->GetBinContent(j)));}else{WW2_D->SetBinError(j,0);}//w32);}
	if(WZ1_D->GetBinContent(j)>0){WZ1_D->SetBinError(j,sqrt(w33*w33*WZ1_D->GetBinContent(j)));}else{WZ1_D->SetBinError(j,0);}//w33);}
	if(WZ2_D->GetBinContent(j)>0){WZ2_D->SetBinError(j,sqrt(w34*w34*WZ2_D->GetBinContent(j)));}else{WZ2_D->SetBinError(j,0);}//w34);}
	if(WZ3_D->GetBinContent(j)>0){WZ3_D->SetBinError(j,sqrt(w35*w35*WZ3_D->GetBinContent(j)));}else{WZ3_D->SetBinError(j,0);}//w35);}
	

    float err00 = data->GetBinError(j)*data->GetBinError(j);
    float err01 = ZToNuNu_1->GetBinError(j)*ZToNuNu_1->GetBinError(j) + ZToNuNu_2->GetBinError(j)*ZToNuNu_2->GetBinError(j) + ZToNuNu_3->GetBinError(j)*ZToNuNu_3->GetBinError(j) + ZToNuNu_4->GetBinError(j)*ZToNuNu_4->GetBinError(j) + ZToNuNu_5->GetBinError(j)*ZToNuNu_5->GetBinError(j) + ZToNuNu_6->GetBinError(j)*ZToNuNu_6->GetBinError(j) + ZToNuNu_7->GetBinError(j)*ZToNuNu_7->GetBinError(j);
    //float err02 = QCD_1->GetBinError(j)*QCD_1->GetBinError(j) + QCD_2->GetBinError(j)*QCD_2->GetBinError(j) + QCD_3->GetBinError(j)*QCD_3->GetBinError(j) + QCD_4->GetBinError(j)*QCD_4->GetBinError(j) + QCD_5->GetBinError(j)*QCD_5->GetBinError(j) + QCD_6->GetBinError(j)*QCD_6->GetBinError(j) + QCD_7->GetBinError(j)*QCD_7->GetBinError(j);
    float err03 = WToLNu_1->GetBinError(j)*WToLNu_1->GetBinError(j)+WToLNu_2->GetBinError(j)*WToLNu_2->GetBinError(j)+WToLNu_3->GetBinError(j)*WToLNu_3->GetBinError(j)+WToLNu_4->GetBinError(j)*WToLNu_4->GetBinError(j)+WToLNu_5->GetBinError(j)*WToLNu_5->GetBinError(j)+WToLNu_6->GetBinError(j)*WToLNu_6->GetBinError(j)+WToLNu_7->GetBinError(j)*WToLNu_7->GetBinError(j);
	float err04 = TT_1->GetBinError(j)*TT_1->GetBinError(j)+TT_2->GetBinError(j)*TT_2->GetBinError(j);
	float err05 = ST_1->GetBinError(j)*ST_1->GetBinError(j) + ST_2->GetBinError(j)*ST_2->GetBinError(j)+ ST_3->GetBinError(j)*ST_3->GetBinError(j)+ ST_4->GetBinError(j)*ST_4->GetBinError(j);
    float err06 = ZZ1->GetBinError(j)*ZZ1->GetBinError(j) + ZZ2->GetBinError(j)*ZZ2->GetBinError(j) + ZZ3->GetBinError(j)*ZZ3->GetBinError(j) + WW1->GetBinError(j)*WW1->GetBinError(j) + WW2->GetBinError(j)*WW2->GetBinError(j) + WZ1->GetBinError(j)*WZ1->GetBinError(j) + WZ2->GetBinError(j)*WZ2->GetBinError(j) + WZ3->GetBinError(j)*WZ3->GetBinError(j); 
	//float err07 = WToLNu->GetBinError(j);

	float err00_B = data_B->GetBinError(j)*data_B->GetBinError(j);
    float err01_B = ZToNuNu_1_B->GetBinError(j)*ZToNuNu_1_B->GetBinError(j) + ZToNuNu_2_B->GetBinError(j)*ZToNuNu_2_B->GetBinError(j) + ZToNuNu_3_B->GetBinError(j)*ZToNuNu_3_B->GetBinError(j) + ZToNuNu_4_B->GetBinError(j)*ZToNuNu_4_B->GetBinError(j) + ZToNuNu_5_B->GetBinError(j)*ZToNuNu_5_B->GetBinError(j) + ZToNuNu_6_B->GetBinError(j)*ZToNuNu_6_B->GetBinError(j) + ZToNuNu_7_B->GetBinError(j)*ZToNuNu_7_B->GetBinError(j);
    float err03_B = WToLNu_1_B->GetBinError(j)*WToLNu_1_B->GetBinError(j)+WToLNu_2_B->GetBinError(j)*WToLNu_2_B->GetBinError(j)+WToLNu_3_B->GetBinError(j)*WToLNu_3_B->GetBinError(j)+WToLNu_4_B->GetBinError(j)*WToLNu_4_B->GetBinError(j)+WToLNu_5_B->GetBinError(j)*WToLNu_5_B->GetBinError(j)+WToLNu_6_B->GetBinError(j)*WToLNu_6_B->GetBinError(j)+WToLNu_7_B->GetBinError(j)*WToLNu_7_B->GetBinError(j);
	float err04_B = TT_1_B->GetBinError(j)*TT_1_B->GetBinError(j)+TT_2_B->GetBinError(j)*TT_2_B->GetBinError(j);
	float err05_B = ST_1_B->GetBinError(j)*ST_1_B->GetBinError(j) + ST_2_B->GetBinError(j)*ST_2_B->GetBinError(j)+ ST_3_B->GetBinError(j)*ST_3_B->GetBinError(j)+ ST_4_B->GetBinError(j)*ST_4_B->GetBinError(j);
    float err06_B = ZZ1_B->GetBinError(j)*ZZ1_B->GetBinError(j) + ZZ2_B->GetBinError(j)*ZZ2_B->GetBinError(j) + ZZ3_B->GetBinError(j)*ZZ3_B->GetBinError(j) + WW1_B->GetBinError(j)*WW1_B->GetBinError(j) + WW2_B->GetBinError(j)*WW2_B->GetBinError(j) + WZ1_B->GetBinError(j)*WZ1_B->GetBinError(j) + WZ2_B->GetBinError(j)*WZ2_B->GetBinError(j) + WZ3_B->GetBinError(j)*WZ3_B->GetBinError(j); 
	float err02_B = err00_B+err02_B+err03_B+err04_B+err05_B+err06_B;

	float err00_C = data_C->GetBinError(j)*data_C->GetBinError(j);
    float err01_C = ZToNuNu_1_C->GetBinError(j)*ZToNuNu_1_C->GetBinError(j) + ZToNuNu_2_C->GetBinError(j)*ZToNuNu_2_C->GetBinError(j) + ZToNuNu_3_C->GetBinError(j)*ZToNuNu_3_C->GetBinError(j) + ZToNuNu_4_C->GetBinError(j)*ZToNuNu_4_C->GetBinError(j) + ZToNuNu_5_C->GetBinError(j)*ZToNuNu_5_C->GetBinError(j) + ZToNuNu_6_C->GetBinError(j)*ZToNuNu_6_C->GetBinError(j) + ZToNuNu_7_C->GetBinError(j)*ZToNuNu_7_C->GetBinError(j);
    float err03_C = WToLNu_1_C->GetBinError(j)*WToLNu_1_C->GetBinError(j)+WToLNu_2_C->GetBinError(j)*WToLNu_2_C->GetBinError(j)+WToLNu_3_C->GetBinError(j)*WToLNu_3_C->GetBinError(j)+WToLNu_4_C->GetBinError(j)*WToLNu_4_C->GetBinError(j)+WToLNu_5_C->GetBinError(j)*WToLNu_5_C->GetBinError(j)+WToLNu_6_C->GetBinError(j)*WToLNu_6_C->GetBinError(j)+WToLNu_7_C->GetBinError(j)*WToLNu_7_C->GetBinError(j);
	float err04_C = TT_1_C->GetBinError(j)*TT_1_C->GetBinError(j)+TT_2_C->GetBinError(j)*TT_2_C->GetBinError(j);
	float err05_C = ST_1_C->GetBinError(j)*ST_1_C->GetBinError(j) + ST_2_C->GetBinError(j)*ST_2_C->GetBinError(j)+ ST_3_C->GetBinError(j)*ST_3_C->GetBinError(j)+ ST_4_C->GetBinError(j)*ST_4_C->GetBinError(j);
    float err06_C = ZZ1_C->GetBinError(j)*ZZ1_C->GetBinError(j) + ZZ2_C->GetBinError(j)*ZZ2_C->GetBinError(j) + ZZ3_C->GetBinError(j)*ZZ3_C->GetBinError(j) + WW1_C->GetBinError(j)*WW1_C->GetBinError(j) + WW2_C->GetBinError(j)*WW2_C->GetBinError(j) + WZ1_C->GetBinError(j)*WZ1_C->GetBinError(j) + WZ2_C->GetBinError(j)*WZ2_C->GetBinError(j) + WZ3_C->GetBinError(j)*WZ3_C->GetBinError(j);  
    float err02_C = err00_C+err02_C+err03_C+err04_C+err05_C+err06_C;

	float err00_D = data_D->GetBinError(j)*data_D->GetBinError(j);
    float err01_D = ZToNuNu_1_D->GetBinError(j)*ZToNuNu_1_D->GetBinError(j) + ZToNuNu_2_D->GetBinError(j)*ZToNuNu_2_D->GetBinError(j) + ZToNuNu_3_D->GetBinError(j)*ZToNuNu_3_D->GetBinError(j) + ZToNuNu_4_D->GetBinError(j)*ZToNuNu_4_D->GetBinError(j) + ZToNuNu_5_D->GetBinError(j)*ZToNuNu_5_D->GetBinError(j) + ZToNuNu_6_D->GetBinError(j)*ZToNuNu_6_D->GetBinError(j) + ZToNuNu_7_D->GetBinError(j)*ZToNuNu_7_D->GetBinError(j);
    float err03_D = WToLNu_1_D->GetBinError(j)*WToLNu_1_D->GetBinError(j)+WToLNu_2_D->GetBinError(j)*WToLNu_2_D->GetBinError(j)+WToLNu_3_D->GetBinError(j)*WToLNu_3_D->GetBinError(j)+WToLNu_4_D->GetBinError(j)*WToLNu_4_D->GetBinError(j)+WToLNu_5_D->GetBinError(j)*WToLNu_5_D->GetBinError(j)+WToLNu_6_D->GetBinError(j)*WToLNu_6_D->GetBinError(j)+WToLNu_7_D->GetBinError(j)*WToLNu_7_D->GetBinError(j);
	float err04_D = TT_1_D->GetBinError(j)*TT_1_D->GetBinError(j)+TT_2_D->GetBinError(j)*TT_2_D->GetBinError(j);
	float err05_D = ST_1_D->GetBinError(j)*ST_1_D->GetBinError(j) + ST_2_D->GetBinError(j)*ST_2_D->GetBinError(j)+ ST_3_D->GetBinError(j)*ST_3_D->GetBinError(j)+ ST_4_D->GetBinError(j)*ST_4_D->GetBinError(j);
    float err06_D = ZZ1_D->GetBinError(j)*ZZ1_D->GetBinError(j) + ZZ2_D->GetBinError(j)*ZZ2_D->GetBinError(j) + ZZ3_D->GetBinError(j)*ZZ3_D->GetBinError(j) + WW1_D->GetBinError(j)*WW1_D->GetBinError(j) + WW2_D->GetBinError(j)*WW2_D->GetBinError(j) + WZ1_D->GetBinError(j)*WZ1_D->GetBinError(j) + WZ2_D->GetBinError(j)*WZ2_D->GetBinError(j) + WZ3_D->GetBinError(j)*WZ3_D->GetBinError(j); 
    float err02_D = err00_D+err02_D+err03_D+err04_D+err05_D+err06_D;

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
    //QCD_1->SetBinContent(j,w08*QCD_1->GetBinContent(j));
    //QCD_2->SetBinContent(j,w09*QCD_2->GetBinContent(j));
    //QCD_3->SetBinContent(j,w10*QCD_3->GetBinContent(j));
	//QCD_4->SetBinContent(j,w11*QCD_4->GetBinContent(j));
    //QCD_5->SetBinContent(j,w12*QCD_5->GetBinContent(j));
    //QCD_6->SetBinContent(j,w13*QCD_6->GetBinContent(j));
    //QCD_7->SetBinContent(j,w14*QCD_7->GetBinContent(j));
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
	//WToLNu->SetBinContent(j,w36*WToLNu->GetBinContent(j));

	tptzm0700lh_B->SetBinContent(j,w0700*tptzm0700lh_B->GetBinContent(j));
    tptzm0900lh_B->SetBinContent(j,w0900*tptzm0900lh_B->GetBinContent(j));
    tptzm1400lh_B->SetBinContent(j,w1400*tptzm1400lh_B->GetBinContent(j));
    tptzm1700lh_B->SetBinContent(j,w1700*tptzm1700lh_B->GetBinContent(j));
    ZToNuNu_1_B->SetBinContent(j,w01*ZToNuNu_1_B->GetBinContent(j));
    ZToNuNu_2_B->SetBinContent(j,w02*ZToNuNu_2_B->GetBinContent(j));
    ZToNuNu_3_B->SetBinContent(j,w03*ZToNuNu_3_B->GetBinContent(j));
    ZToNuNu_4_B->SetBinContent(j,w04*ZToNuNu_4_B->GetBinContent(j));
	ZToNuNu_5_B->SetBinContent(j,w05*ZToNuNu_5_B->GetBinContent(j));
	ZToNuNu_6_B->SetBinContent(j,w06*ZToNuNu_6_B->GetBinContent(j));
	ZToNuNu_7_B->SetBinContent(j,w07*ZToNuNu_7_B->GetBinContent(j));
    //QCD_1->SetBinContent(j,w08*QCD_1->GetBinContent(j));
    //QCD_2->SetBinContent(j,w09*QCD_2->GetBinContent(j));
    //QCD_3->SetBinContent(j,w10*QCD_3->GetBinContent(j));
	//QCD_4->SetBinContent(j,w11*QCD_4->GetBinContent(j));
    //QCD_5->SetBinContent(j,w12*QCD_5->GetBinContent(j));
    //QCD_6->SetBinContent(j,w13*QCD_6->GetBinContent(j));
    //QCD_7->SetBinContent(j,w14*QCD_7->GetBinContent(j));
    WToLNu_1_B->SetBinContent(j,w15*WToLNu_1_B->GetBinContent(j));
	WToLNu_2_B->SetBinContent(j,w16*WToLNu_2_B->GetBinContent(j));
	WToLNu_3_B->SetBinContent(j,w17*WToLNu_3_B->GetBinContent(j));
	WToLNu_4_B->SetBinContent(j,w18*WToLNu_4_B->GetBinContent(j));
	WToLNu_5_B->SetBinContent(j,w19*WToLNu_5_B->GetBinContent(j));
	WToLNu_6_B->SetBinContent(j,w20*WToLNu_6_B->GetBinContent(j));
	WToLNu_7_B->SetBinContent(j,w21*WToLNu_7_B->GetBinContent(j));
    TT_1_B->SetBinContent(j,w22*TT_1_B->GetBinContent(j));
	TT_2_B->SetBinContent(j,w23*TT_2_B->GetBinContent(j));
    ST_1_B->SetBinContent(j,w24*ST_1_B->GetBinContent(j));
    ST_2_B->SetBinContent(j,w25*ST_2_B->GetBinContent(j));
    ST_3_B->SetBinContent(j,w26*ST_3_B->GetBinContent(j));
    ST_4_B->SetBinContent(j,w27*ST_4_B->GetBinContent(j));
    ZZ1_B->SetBinContent(j,w28*ZZ1_B->GetBinContent(j));
    ZZ2_B->SetBinContent(j,w29*ZZ2_B->GetBinContent(j));
    ZZ3_B->SetBinContent(j,w30*ZZ3_B->GetBinContent(j));
    WW1_B->SetBinContent(j,w31*WW1_B->GetBinContent(j));
    WW2_B->SetBinContent(j,w32*WW2_B->GetBinContent(j));
    WZ1_B->SetBinContent(j,w33*WZ1_B->GetBinContent(j));
    WZ2_B->SetBinContent(j,w34*WZ2_B->GetBinContent(j));
    WZ3_B->SetBinContent(j,w35*WZ3_B->GetBinContent(j));

	tptzm0700lh_C->SetBinContent(j,w0700*tptzm0700lh_C->GetBinContent(j));
    tptzm0900lh_C->SetBinContent(j,w0900*tptzm0900lh_C->GetBinContent(j));
    tptzm1400lh_C->SetBinContent(j,w1400*tptzm1400lh_C->GetBinContent(j));
    tptzm1700lh_C->SetBinContent(j,w1700*tptzm1700lh_C->GetBinContent(j));
    ZToNuNu_1_C->SetBinContent(j,w01*ZToNuNu_1_C->GetBinContent(j));
    ZToNuNu_2_C->SetBinContent(j,w02*ZToNuNu_2_C->GetBinContent(j));
    ZToNuNu_3_C->SetBinContent(j,w03*ZToNuNu_3_C->GetBinContent(j));
    ZToNuNu_4_C->SetBinContent(j,w04*ZToNuNu_4_C->GetBinContent(j));
	ZToNuNu_5_C->SetBinContent(j,w05*ZToNuNu_5_C->GetBinContent(j));
	ZToNuNu_6_C->SetBinContent(j,w06*ZToNuNu_6_C->GetBinContent(j));
	ZToNuNu_7_C->SetBinContent(j,w07*ZToNuNu_7_C->GetBinContent(j));
    WToLNu_1_C->SetBinContent(j,w15*WToLNu_1_C->GetBinContent(j));
	WToLNu_2_C->SetBinContent(j,w16*WToLNu_2_C->GetBinContent(j));
	WToLNu_3_C->SetBinContent(j,w17*WToLNu_3_C->GetBinContent(j));
	WToLNu_4_C->SetBinContent(j,w18*WToLNu_4_C->GetBinContent(j));
	WToLNu_5_C->SetBinContent(j,w19*WToLNu_5_C->GetBinContent(j));
	WToLNu_6_C->SetBinContent(j,w20*WToLNu_6_C->GetBinContent(j));
	WToLNu_7_C->SetBinContent(j,w21*WToLNu_7_C->GetBinContent(j));
    TT_1_C->SetBinContent(j,w22*TT_1_C->GetBinContent(j));
	TT_2_C->SetBinContent(j,w23*TT_2_C->GetBinContent(j));
    ST_1_C->SetBinContent(j,w24*ST_1_C->GetBinContent(j));
    ST_2_C->SetBinContent(j,w25*ST_2_C->GetBinContent(j));
    ST_3_C->SetBinContent(j,w26*ST_3_C->GetBinContent(j));
    ST_4_C->SetBinContent(j,w27*ST_4_C->GetBinContent(j));
    ZZ1_C->SetBinContent(j,w28*ZZ1_C->GetBinContent(j));
    ZZ2_C->SetBinContent(j,w29*ZZ2_C->GetBinContent(j));
    ZZ3_C->SetBinContent(j,w30*ZZ3_C->GetBinContent(j));
    WW1_C->SetBinContent(j,w31*WW1_C->GetBinContent(j));
    WW2_C->SetBinContent(j,w32*WW2_C->GetBinContent(j));
    WZ1_C->SetBinContent(j,w33*WZ1_C->GetBinContent(j));
    WZ2_C->SetBinContent(j,w34*WZ2_C->GetBinContent(j));
    WZ3_C->SetBinContent(j,w35*WZ3_C->GetBinContent(j));

	tptzm0700lh_D->SetBinContent(j,w0700*tptzm0700lh_D->GetBinContent(j));
    tptzm0900lh_D->SetBinContent(j,w0900*tptzm0900lh_D->GetBinContent(j));
    tptzm1400lh_D->SetBinContent(j,w1400*tptzm1400lh_D->GetBinContent(j));
    tptzm1700lh_D->SetBinContent(j,w1700*tptzm1700lh_D->GetBinContent(j));
    ZToNuNu_1_D->SetBinContent(j,w01*ZToNuNu_1_D->GetBinContent(j));
    ZToNuNu_2_D->SetBinContent(j,w02*ZToNuNu_2_D->GetBinContent(j));
    ZToNuNu_3_D->SetBinContent(j,w03*ZToNuNu_3_D->GetBinContent(j));
    ZToNuNu_4_D->SetBinContent(j,w04*ZToNuNu_4_D->GetBinContent(j));
	ZToNuNu_5_D->SetBinContent(j,w05*ZToNuNu_5_D->GetBinContent(j));
	ZToNuNu_6_D->SetBinContent(j,w06*ZToNuNu_6_D->GetBinContent(j));
	ZToNuNu_7_D->SetBinContent(j,w07*ZToNuNu_7_D->GetBinContent(j));
    WToLNu_1_D->SetBinContent(j,w15*WToLNu_1_D->GetBinContent(j));
	WToLNu_2_D->SetBinContent(j,w16*WToLNu_2_D->GetBinContent(j));
	WToLNu_3_D->SetBinContent(j,w17*WToLNu_3_D->GetBinContent(j));
	WToLNu_4_D->SetBinContent(j,w18*WToLNu_4_D->GetBinContent(j));
	WToLNu_5_D->SetBinContent(j,w19*WToLNu_5_D->GetBinContent(j));
	WToLNu_6_D->SetBinContent(j,w20*WToLNu_6_D->GetBinContent(j));
	WToLNu_7_D->SetBinContent(j,w21*WToLNu_7_D->GetBinContent(j));
    TT_1_D->SetBinContent(j,w22*TT_1_D->GetBinContent(j));
	TT_2_D->SetBinContent(j,w23*TT_2_D->GetBinContent(j));
    ST_1_D->SetBinContent(j,w24*ST_1_D->GetBinContent(j));
    ST_2_D->SetBinContent(j,w25*ST_2_D->GetBinContent(j));
    ST_3_D->SetBinContent(j,w26*ST_3_D->GetBinContent(j));
    ST_4_D->SetBinContent(j,w27*ST_4_D->GetBinContent(j));
    ZZ1_D->SetBinContent(j,w28*ZZ1_D->GetBinContent(j));
    ZZ2_D->SetBinContent(j,w29*ZZ2_D->GetBinContent(j));
    ZZ3_D->SetBinContent(j,w30*ZZ3_D->GetBinContent(j));
    WW1_D->SetBinContent(j,w31*WW1_D->GetBinContent(j));
    WW2_D->SetBinContent(j,w32*WW2_D->GetBinContent(j));
    WZ1_D->SetBinContent(j,w33*WZ1_D->GetBinContent(j));
    WZ2_D->SetBinContent(j,w34*WZ2_D->GetBinContent(j));
    WZ3_D->SetBinContent(j,w35*WZ3_D->GetBinContent(j));
	
    float DATA = data->GetBinContent(j);
    float bkg0 = ZToNuNu_1->GetBinContent(j) + ZToNuNu_2->GetBinContent(j) + ZToNuNu_3->GetBinContent(j) + ZToNuNu_4->GetBinContent(j) + ZToNuNu_5->GetBinContent(j) + ZToNuNu_6->GetBinContent(j) + ZToNuNu_7->GetBinContent(j);
    //float bkg1 = QCD_1->GetBinContent(j) + QCD_2->GetBinContent(j) + QCD_3->GetBinContent(j) + QCD_4->GetBinContent(j) + QCD_5->GetBinContent(j) + QCD_6->GetBinContent(j) + QCD_7->GetBinContent(j);
    float bkg2 = WToLNu_1->GetBinContent(j) + WToLNu_2->GetBinContent(j) + WToLNu_3->GetBinContent(j) + WToLNu_4->GetBinContent(j) + WToLNu_5->GetBinContent(j) + WToLNu_6->GetBinContent(j)+ WToLNu_7->GetBinContent(j);
	float bkg3 = TT_1->GetBinContent(j) + TT_2->GetBinContent(j);
    float bkg4 = ST_1 ->GetBinContent(j) + ST_2 ->GetBinContent(j) + ST_3 ->GetBinContent(j) + ST_4 ->GetBinContent(j);
	float bkg5 = ZZ1->GetBinContent(j)+ZZ2->GetBinContent(j)+ZZ3->GetBinContent(j)+WW1->GetBinContent(j)+WW2->GetBinContent(j)+WZ1->GetBinContent(j)+WZ2->GetBinContent(j)+WZ3->GetBinContent(j);
	//float bkg6 = WToLNu->GetBinContent(j);

	float DATA_B = data_B->GetBinContent(j);
    float bkg0_B = ZToNuNu_1_B->GetBinContent(j) + ZToNuNu_2_B->GetBinContent(j) + ZToNuNu_3_B->GetBinContent(j) + ZToNuNu_4_B->GetBinContent(j) + ZToNuNu_5_B->GetBinContent(j) + ZToNuNu_6_B->GetBinContent(j) + ZToNuNu_7_B->GetBinContent(j);
    float bkg2_B = WToLNu_1_B->GetBinContent(j) + WToLNu_2_B->GetBinContent(j) + WToLNu_3_B->GetBinContent(j) + WToLNu_4_B->GetBinContent(j) + WToLNu_5_B->GetBinContent(j) + WToLNu_6_B->GetBinContent(j)+ WToLNu_7_B->GetBinContent(j);
	float bkg3_B = TT_1_B->GetBinContent(j) + TT_2_B->GetBinContent(j);
    float bkg4_B = ST_1_B->GetBinContent(j) + ST_2_B->GetBinContent(j) + ST_3_B ->GetBinContent(j) + ST_4_B ->GetBinContent(j);
	float bkg5_B = ZZ1_B->GetBinContent(j)+ZZ2_B->GetBinContent(j)+ZZ3_B->GetBinContent(j)+WW1_B->GetBinContent(j)+WW2_B->GetBinContent(j)+WZ1_B->GetBinContent(j)+WZ2_B->GetBinContent(j)+WZ3_B->GetBinContent(j);
    float bkg1_B = DATA_B-(bkg0_B+bkg2_B+bkg3_B+bkg4_B+bkg5_B);
	

	float DATA_C = data_C->GetBinContent(j);
    float bkg0_C = ZToNuNu_1_C->GetBinContent(j) + ZToNuNu_2_C->GetBinContent(j) + ZToNuNu_3_C->GetBinContent(j) + ZToNuNu_4_C->GetBinContent(j) + ZToNuNu_5_C->GetBinContent(j) + ZToNuNu_6_C->GetBinContent(j) + ZToNuNu_7_C->GetBinContent(j);
    float bkg2_C = WToLNu_1_C->GetBinContent(j) + WToLNu_2_C->GetBinContent(j) + WToLNu_3_C->GetBinContent(j) + WToLNu_4_C->GetBinContent(j) + WToLNu_5_C->GetBinContent(j) + WToLNu_6_C->GetBinContent(j)+ WToLNu_7_C->GetBinContent(j);
	float bkg3_C = TT_1_C->GetBinContent(j) + TT_2_C->GetBinContent(j);
    float bkg4_C = ST_1_C->GetBinContent(j) + ST_2_C->GetBinContent(j) + ST_3_C ->GetBinContent(j) + ST_4_C ->GetBinContent(j);
	float bkg5_C = ZZ1_C->GetBinContent(j)+ZZ2_C->GetBinContent(j)+ZZ3_C->GetBinContent(j)+WW1_C->GetBinContent(j)+WW2_C->GetBinContent(j)+WZ1_C->GetBinContent(j)+WZ2_C->GetBinContent(j)+WZ3_C->GetBinContent(j);
	float bkg1_C = DATA_C-(bkg0_C+bkg2_C+bkg3_C+bkg4_C+bkg5_C);
	

	float DATA_D = data_D->GetBinContent(j);
    float bkg0_D = ZToNuNu_1_D->GetBinContent(j) + ZToNuNu_2_D->GetBinContent(j) + ZToNuNu_3_D->GetBinContent(j) + ZToNuNu_4_D->GetBinContent(j) + ZToNuNu_5_D->GetBinContent(j) + ZToNuNu_6_D->GetBinContent(j) + ZToNuNu_7_D->GetBinContent(j);
    float bkg2_D = WToLNu_1_D->GetBinContent(j) + WToLNu_2_D->GetBinContent(j) + WToLNu_3_D->GetBinContent(j) + WToLNu_4_D->GetBinContent(j) + WToLNu_5_D->GetBinContent(j) + WToLNu_6_D->GetBinContent(j)+ WToLNu_7_D->GetBinContent(j);
	float bkg3_D = TT_1_D->GetBinContent(j) + TT_2_D->GetBinContent(j);
    float bkg4_D = ST_1_D->GetBinContent(j) + ST_2_D->GetBinContent(j) + ST_3_D ->GetBinContent(j) + ST_4_D ->GetBinContent(j);
	float bkg5_D = ZZ1_D->GetBinContent(j)+ZZ2_D->GetBinContent(j)+ZZ3_D->GetBinContent(j)+WW1_D->GetBinContent(j)+WW2_D->GetBinContent(j)+WZ1_D->GetBinContent(j)+WZ2_D->GetBinContent(j)+WZ3_D->GetBinContent(j);
    float bkg1_D = DATA_D-(bkg0_D+bkg2_D+bkg3_D+bkg4_D+bkg5_D);

	cout<<endl;
	cout<<bkg1_B<<endl;
	cout<<bkg1_C<<endl;
	cout<<bkg1_D<<endl;
	cout<<endl;
	float bkg1;
	if (bkg1_D>0) { bkg1 =  (bkg1_B*bkg1_C)/(bkg1_D);} else {bkg1 = 0; }
	//if (bkg1_B==0&&bkg1_D==0) bkg1 =  bkg1_C;

	float err02;
	if (bkg1_B>0&&bkg1_C>0&&bkg1_D>0)  {err02 = (err02_B/(bkg1_B*bkg1_B)+err02_C/(bkg1_C*bkg1_C)+err02_D/(bkg1_D*bkg1_D))*bkg1*bkg1;}else { err02 = 0;}
	

	QCD->SetBinContent(j,bkg1);
	QCD->SetBinError(j,sqrt(err02));
	background->SetBinError(j,sqrt(err01+err02+err03+err04+err05+err06));
	background->SetBinContent(j,bkg0+bkg1+bkg2+bkg3+bkg4+bkg5);
	//background->SetBinContent(j,bkg0+bkg1+bkg3+bkg4+bkg5+bkg6);
	
  }

  background_func  = (TH1F*)background ->Clone(); 
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
  //QCD_1_func = (TH1F*)QCD_1->Clone();    
  //QCD_2_func = (TH1F*)QCD_2->Clone();
  //QCD_3_func = (TH1F*)QCD_3->Clone(); 
  //QCD_4_func = (TH1F*)QCD_4->Clone();
  //QCD_5_func = (TH1F*)QCD_5->Clone();  
  //QCD_6_func = (TH1F*)QCD_6->Clone(); 
  //QCD_7_func = (TH1F*)QCD_7->Clone();
  QCD_func = (TH1F*)QCD->Clone(); 
  WToLNu_1_func = (TH1F*)WToLNu_1->Clone(); 
  WToLNu_2_func = (TH1F*)WToLNu_2->Clone();
  WToLNu_3_func = (TH1F*)WToLNu_3->Clone();
  WToLNu_4_func = (TH1F*)WToLNu_4->Clone();
  WToLNu_5_func = (TH1F*)WToLNu_5->Clone();
  WToLNu_6_func = (TH1F*)WToLNu_6->Clone();
  WToLNu_7_func = (TH1F*)WToLNu_7->Clone();
  TT_1_func = (TH1F*)TT_1->Clone();  
  TT_2_func = (TH1F*)TT_2->Clone();
  ST_1_func = (TH1F*)ST_1->Clone();    
  ST_2_func = (TH1F*)ST_2->Clone();    
  ST_3_func = (TH1F*)ST_3->Clone();    
  ST_4_func = (TH1F*)ST_4->Clone();    
  ZZ1_func  = (TH1F*)ZZ1->Clone(); 
  ZZ2_func  = (TH1F*)ZZ2->Clone();
  ZZ3_func  = (TH1F*)ZZ3->Clone();    
  WW1_func  = (TH1F*)WW1->Clone(); 
  WW2_func  = (TH1F*)WW2->Clone(); 
  WZ1_func  = (TH1F*)WZ1->Clone(); 
  WZ2_func  = (TH1F*)WZ2->Clone();
  WZ3_func  = (TH1F*)WZ3->Clone();
  //WToLNu_func = (TH1F*)WToLNu->Clone();
  delete data; delete background; delete ZToNuNu_1; delete ZToNuNu_2; delete ZToNuNu_3; delete ZToNuNu_4;  delete ZToNuNu_5;  delete ZToNuNu_6;  delete ZToNuNu_7;
  delete QCD;//delete QCD_1; delete QCD_2; delete QCD_3; delete QCD_4; delete QCD_5; delete QCD_6; delete QCD_7; 
  delete WToLNu_1; delete WToLNu_2; delete WToLNu_3; delete WToLNu_4; delete WToLNu_5; delete WToLNu_6; delete WToLNu_7; 
  delete TT_1; delete TT_2; delete ST_1; delete ST_2;  delete ST_3; delete ST_4;  
  delete WW1; delete WW2; delete WZ1; delete WZ2; delete WZ3; delete ZZ1; delete ZZ2;  delete ZZ3; //delete WToLNu;
  
}
