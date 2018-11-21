#include "BackgroundEstimation_dineutrino_v2.h"
#include "SaveRootFileForLimit_dineutrino_v2.h"

void BackgroundEstimation_dineutrino_v2(){ 
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
  bool save = true;

    //CUT VALUES
  //int category=0;
  double dPMet=0.9;            //0.6
  int    BTag = 1;              //1
  double TopPt=250.;           //
  double ht = 200;          //300
  double dPTop = 0;
  double Met = 200;

  vector<TString> name;                vector<int> bin;      vector<float> Min;      vector<float> Max;     vector<TString> axis;

  /*name.push_back("Jet1ResolvedPt"); bin.push_back(18);     Min.push_back(0);    Max.push_back(900);    axis.push_back("jet1(resolved) pt [GeV]");
  name.push_back("Jet2ResolvedPt"); bin.push_back(18);     Min.push_back(0);    Max.push_back(900);    axis.push_back("jet2(resolved) pt [GeV]");
  name.push_back("Jet3ResolvedPt"); bin.push_back(18);     Min.push_back(0);    Max.push_back(900);    axis.push_back("jet3(resolved) pt [GeV]");

  name.push_back("Jet1ResolvedEta"); bin.push_back(10);     Min.push_back(-2.5);    Max.push_back(2.5);    axis.push_back("jet1(resolved) #eta");
  name.push_back("Jet2ResolvedEta"); bin.push_back(10);     Min.push_back(-2.5);    Max.push_back(2.5);    axis.push_back("jet2(resolved) #eta");
  name.push_back("Jet3ResolvedEta"); bin.push_back(10);     Min.push_back(-2.5);    Max.push_back(2.5);    axis.push_back("jet3(resolved) #eta");
  name.push_back("TopMass"); bin.push_back(10);     Min.push_back(0);    Max.push_back(500);    axis.push_back("Top Mass[GeV]");
  name.push_back("TopPt");   bin.push_back(16);     Min.push_back(200);    Max.push_back(1000);   axis.push_back("Top pt[GeV] ");
  name.push_back("TopEta");  bin.push_back(12);     Min.push_back(-3);   Max.push_back(3);      axis.push_back("Top #eta");
  
  name.push_back("Met_pt");  bin.push_back(16);     Min.push_back(200);    Max.push_back(1000);   axis.push_back("Met pt[GeV] ");
  name.push_back("Met_phi"); bin.push_back(12);     Min.push_back(-3);   Max.push_back(3);      axis.push_back("Met #phi");
 
  name.push_back("deltaPhiMetTop"); bin.push_back(15);     Min.push_back(0);    Max.push_back(3);    axis.push_back("#Delta#phi(Met,top)");
  name.push_back("MinDeltaPhiJetMet"); bin.push_back(9);     Min.push_back(0);    Max.push_back(3);    axis.push_back("Min#Delta#phi(Met,Jet)");*/
  name.push_back("TransverseMassMetTop");      bin.push_back(15);     Min.push_back(500);     Max.push_back(2000);     axis.push_back("TransverseMassMetTop");

   //name.push_back("HT"); bin.push_back(18);     Min.push_back(200);    Max.push_back(2000);    axis.push_back("HT pt[GeV]");

  for (int i=0; i<name.size(); i++){
    const char *plot = name[i];
    for(int category=0; category<1; category++){

    char CUT[1000]; char CUTpup1[1000]; char CUTpup2[1000]; char CUTbta1[1000]; char CUTbta2[1000];  char CUTfor1[1000]; char CUTfor2[1000]; char CUTwje1[1000]; char CUTwje2[1000];
	char CUTSR[1000]; char CUTzje1[1000];  char CUTzje2[1000];  char CUTttb1[1000];  char CUTttb2[1000];
	//sprintf(CUT,    "((category0==1)&&(Jet1ResolvedPt>0)&&(Jet2ResolvedPt>0)&&(Jet3ResolvedPt>0)&&(MinDeltaPhiJetMet>0.6)&&(TransverseMassMetTop>500)&&(NumSelLeps==0)&&(NumSelBJetsM>0)&&(TopPt>340))");
	if(category==0) sprintf(CUT,    "((category0==1)&&(Jet1ResolvedPt>0)&&(Jet2ResolvedPt>0)&&(Jet3ResolvedPt>0)&&(MinDeltaPhiJetMet>%f)&&(TransverseMassMetTop>500)&&(NumSelLeps==0)&&(NumSelBJetsM>=%i)&&(TopPt>%f)&&(deltaPhiMetTop>%f)&&(NumSelForwardJets==0)&&(HT>%f)&&(Met_pt>%f))",dPMet, BTag, TopPt,dPTop, ht,Met);
	if(category==1) sprintf(CUT,    "((category0==1)&&(Jet1ResolvedPt>0)&&(Jet2ResolvedPt>0)&&(Jet3ResolvedPt>0)&&(MinDeltaPhiJetMet>%f)&&(TransverseMassMetTop>500)&&(NumSelLeps==0)&&(NumSelBJetsM>=%i)&&(TopPt>%f)&&(deltaPhiMetTop>%f)&&(NumSelForwardJets>0)&&(HT>%f)&&(Met_pt>%f))", dPMet, BTag, TopPt,dPTop, ht,Met);
	//sprintf(CUT,    "((category0==1)&&(Jet1ResolvedPt>0)&&(Jet2ResolvedPt>0)&&(Jet3ResolvedPt>0)&&(MinDeltaPhiJetMet>0.6)&&(TransverseMassMetTop>500)&&(NumSelLeps==0)&&(TopPt>200))");
	sprintf(CUTSR,   "PUWeight    *w_Btag   *genWeight  *w_ZToNuNu  *w_WToLNu  *w_ttbar*%s",CUT );
	sprintf(CUTpup1, "PUWeightUP  *w_Btag    *genWeight  *w_ZToNuNu  *w_WToLNu  *w_ttbar*%s",CUT );
	sprintf(CUTpup2, "PUWeightDOWN*w_Btag    *genWeight  *w_ZToNuNu  *w_WToLNu  *w_ttbar*%s",CUT );
	sprintf(CUTfor1, "PUWeight    *w_Btag    *genWeight  *w_ZToNuNu  *w_WToLNu  *w_ttbar*%s",CUT );
	sprintf(CUTfor2, "PUWeight    *w_Btag    *genWeight  *w_ZToNuNu  *w_WToLNu  *w_ttbar*%s",CUT );
	sprintf(CUTbta1, "PUWeight    *w_BtagUp    *genWeight  *w_ZToNuNu  *w_WToLNu  *w_ttbar*%s",CUT );
	sprintf(CUTbta2, "PUWeight    *w_BtagDown  *genWeight  *w_ZToNuNu  *w_WToLNu  *w_ttbar*%s",CUT );
	sprintf(CUTzje1, "PUWeight    *w_Btag   *genWeight  *w_ZToNuNuUp   *w_WToLNu  *w_ttbar*%s",CUT );
	sprintf(CUTzje2, "PUWeight    *w_Btag   *genWeight  *w_ZToNuNuDown *w_WToLNu  *w_ttbar*%s",CUT );
    sprintf(CUTwje1, "PUWeight    *w_Btag   *genWeight  *w_ZToNuNu  *w_WToLNuUp   *w_ttbar*%s",CUT );
	sprintf(CUTwje2, "PUWeight    *w_Btag   *genWeight  *w_ZToNuNu  *w_WToLNuDown *w_ttbar*%s",CUT );
	sprintf(CUTttb1, "PUWeight    *w_Btag   *genWeight  *w_ZToNuNu  *w_WToLNu  *w_ttbarUp*%s" ,CUT );
	sprintf(CUTttb2, "PUWeight    *w_Btag   *genWeight  *w_ZToNuNu  *w_WToLNu  *w_ttbarDown*%s",CUT);

	
	MakeHistos(CUTSR,   plot,bin[i],Min[i],Max[i],0,
		       data,background, 
			   ZToNuNu,QCD,WToLNu,TT,ST,VV,
			   tptzm0700lh,tptzm0800lh,tptzm0900lh,tptzm1000lh,tptzm1100lh,tptzm1200lh,tptzm1300lh,tptzm1400lh,tptzm1500lh,tptzm1600lh,tptzm1700lh,tptzm1800lh);

	/*MakeHistos(CUTpup1, plot,bin[i],Min[i],Max[i],0,
		       data_pup1,background_pup1, 
			   ZToNuNu_pup1,QCD_pup1,WToLNu_pup1,TT_pup1,ST_pup1,VV_pup1,
			   tptzm0700lh_pup1,tptzm0800lh_pup1,tptzm0900lh_pup1,tptzm1000lh_pup1,tptzm1100lh_pup1,tptzm1200lh_pup1,tptzm1300lh_pup1,tptzm1400lh_pup1,tptzm1500lh_pup1,tptzm1600lh_pup1,tptzm1700lh_pup1,tptzm1800lh_pup1);

	MakeHistos(CUTpup2, plot,bin[i],Min[i],Max[i],0,
		       data_pup2,background_pup2, 
			   ZToNuNu_pup2,QCD_pup2,WToLNu_pup2,TT_pup2,ST_pup2,VV_pup2,
			   tptzm0700lh_pup2,tptzm0800lh_pup2,tptzm0900lh_pup2,tptzm1000lh_pup2,tptzm1100lh_pup2,tptzm1200lh_pup2,tptzm1300lh_pup2,tptzm1400lh_pup2,tptzm1500lh_pup2,tptzm1600lh_pup2,tptzm1700lh_pup2,tptzm1800lh_pup2);
    */
	/*MakeHistos(CUTfor1, plot,bin[i],Min[i],Max[i],0,
		       data_for1,background_for1, 
			   ZToNuNu_for1,QCD_for1,WToLNu_for1,TT_for1,ST_for1,VV_for1,
			   tptzm0700lh_for1,tptzm0800lh_for1,tptzm0900lh_for1,tptzm1000lh_for1,tptzm1100lh_for1,tptzm1200lh_for1,tptzm1300lh_for1,tptzm1400lh_for1,tptzm1500lh_for1,tptzm1600lh_for1,tptzm1700lh_for1,tptzm1800lh_for1);

	MakeHistos(CUTfor2, plot,bin[i],Min[i],Max[i],0,
		       data_for2,background_for2, 
			   ZToNuNu_for2,QCD_for2,WToLNu_for2,TT_for2,ST_for2,VV_for2,
			   tptzm0700lh_for2,tptzm0800lh_for2,tptzm0900lh_for2,tptzm1000lh_for2,tptzm1100lh_for2,tptzm1200lh_for2,tptzm1300lh_for2,tptzm1400lh_for2,tptzm1500lh_for2,tptzm1600lh_for2,tptzm1700lh_for2,tptzm1800lh_for2);
    */
	/*MakeHistos(CUTbta1, plot,bin[i],Min[i],Max[i],0,
		       data_bta1,background_bta1, 
			   ZToNuNu_bta1,QCD_bta1,WToLNu_bta1,TT_bta1,ST_bta1,VV_bta1,
			   tptzm0700lh_bta1,tptzm0800lh_bta1,tptzm0900lh_bta1,tptzm1000lh_bta1,tptzm1100lh_bta1,tptzm1200lh_bta1,tptzm1300lh_bta1,tptzm1400lh_bta1,tptzm1500lh_bta1,tptzm1600lh_bta1,tptzm1700lh_bta1,tptzm1800lh_bta1);

	MakeHistos(CUTbta2, plot,bin[i],Min[i],Max[i],0,
		       data_bta2,background_bta2, 
			   ZToNuNu_bta2,QCD_bta2,WToLNu_bta2,TT_bta2,ST_bta2,VV_bta2,
			   tptzm0700lh_bta2,tptzm0800lh_bta2,tptzm0900lh_bta2,tptzm1000lh_bta2,tptzm1100lh_bta2,tptzm1200lh_bta2,tptzm1300lh_bta2,tptzm1400lh_bta2,tptzm1500lh_bta2,tptzm1600lh_bta2,tptzm1700lh_bta2,tptzm1800lh_bta2);

	MakeHistos(CUTzje1, plot,bin[i],Min[i],Max[i],0,
		       data_zje1,background_zje1, 
			   ZToNuNu_zje1,QCD_zje1,WToLNu_zje1,TT_zje1,ST_zje1,VV_zje1,
			   tptzm0700lh_zje1,tptzm0800lh_zje1,tptzm0900lh_zje1,tptzm1000lh_zje1,tptzm1100lh_zje1,tptzm1200lh_zje1,tptzm1300lh_zje1,tptzm1400lh_zje1,tptzm1500lh_zje1,tptzm1600lh_zje1,tptzm1700lh_zje1,tptzm1800lh_zje1);

	MakeHistos(CUTzje2, plot,bin[i],Min[i],Max[i],0,
		       data_zje2,background_zje2, 
			   ZToNuNu_zje2,QCD_zje2,WToLNu_zje2,TT_zje2,ST_zje2,VV_zje2,
			   tptzm0700lh_zje2,tptzm0800lh_zje2,tptzm0900lh_zje2,tptzm1000lh_zje2,tptzm1100lh_zje2,tptzm1200lh_zje2,tptzm1300lh_zje2,tptzm1400lh_zje2,tptzm1500lh_zje2,tptzm1600lh_zje2,tptzm1700lh_zje2,tptzm1800lh_zje2);

	MakeHistos(CUTwje1, plot,bin[i],Min[i],Max[i],0,
		       data_wje1,background_wje1, 
			   ZToNuNu_wje1,QCD_wje1,WToLNu_wje1,TT_wje1,ST_wje1,VV_wje1,
			   tptzm0700lh_wje1,tptzm0800lh_wje1,tptzm0900lh_wje1,tptzm1000lh_wje1,tptzm1100lh_wje1,tptzm1200lh_wje1,tptzm1300lh_wje1,tptzm1400lh_wje1,tptzm1500lh_wje1,tptzm1600lh_wje1,tptzm1700lh_wje1,tptzm1800lh_wje1);

	MakeHistos(CUTwje2, plot,bin[i],Min[i],Max[i],0,
		       data_wje2,background_wje2, 
			   ZToNuNu_wje2,QCD_wje2,WToLNu_wje2,TT_wje2,ST_wje2,VV_wje2,
			   tptzm0700lh_wje2,tptzm0800lh_wje2,tptzm0900lh_wje2,tptzm1000lh_wje2,tptzm1100lh_wje2,tptzm1200lh_wje2,tptzm1300lh_wje2,tptzm1400lh_wje2,tptzm1500lh_wje2,tptzm1600lh_wje2,tptzm1700lh_wje2,tptzm1800lh_wje2);

	MakeHistos(CUTttb1, plot,bin[i],Min[i],Max[i],0,
		       data_ttb1,background_ttb1, 
			   ZToNuNu_ttb1,QCD_ttb1,WToLNu_ttb1,TT_ttb1,ST_ttb1,VV_ttb1,
			   tptzm0700lh_ttb1,tptzm0800lh_ttb1,tptzm0900lh_ttb1,tptzm1000lh_ttb1,tptzm1100lh_ttb1,tptzm1200lh_ttb1,tptzm1300lh_ttb1,tptzm1400lh_ttb1,tptzm1500lh_ttb1,tptzm1600lh_ttb1,tptzm1700lh_ttb1,tptzm1800lh_ttb1);

	MakeHistos(CUTttb2, plot,bin[i],Min[i],Max[i],0,
		       data_ttb2,background_ttb2, 
			   ZToNuNu_ttb2,QCD_ttb2,WToLNu_ttb2,TT_ttb2,ST_ttb2,VV_ttb2,
			   tptzm0700lh_ttb2,tptzm0800lh_ttb2,tptzm0900lh_ttb2,tptzm1000lh_ttb2,tptzm1100lh_ttb2,tptzm1200lh_ttb2,tptzm1300lh_ttb2,tptzm1400lh_ttb2,tptzm1500lh_ttb2,tptzm1600lh_ttb2,tptzm1700lh_ttb2,tptzm1800lh_ttb2);
	
	MakeHistos(CUTSR,   plot,bin[i],Min[i],Max[i],1,
		       data_jes1,background_jes1, 
			   ZToNuNu_jes1,QCD_jes1,WToLNu_jes1,TT_jes1,ST_jes1,VV_jes1,
			   tptzm0700lh_jes1,tptzm0800lh_jes1,tptzm0900lh_jes1,tptzm1000lh_jes1,tptzm1100lh_jes1,tptzm1200lh_jes1,tptzm1300lh_jes1,tptzm1400lh_jes1,tptzm1500lh_jes1,tptzm1600lh_jes1,tptzm1700lh_jes1,tptzm1800lh_jes1);

	MakeHistos(CUTSR,   plot,bin[i],Min[i],Max[i],2,
		       data_jes2,background_jes2, 
			   ZToNuNu_jes2,QCD_jes2,WToLNu_jes2,TT_jes2,ST_jes2,VV_jes2,
			   tptzm0700lh_jes2,tptzm0800lh_jes2,tptzm0900lh_jes2,tptzm1000lh_jes2,tptzm1100lh_jes2,tptzm1200lh_jes2,tptzm1300lh_jes2,tptzm1400lh_jes2,tptzm1500lh_jes2,tptzm1600lh_jes2,tptzm1700lh_jes2,tptzm1800lh_jes2);

	MakeHistos(CUTSR,   plot,bin[i],Min[i],Max[i],3,
		       data_jer1,background_jer1, 
			   ZToNuNu_jer1,QCD_jer1,WToLNu_jer1,TT_jer1,ST_jer1,VV_jer1,
			   tptzm0700lh_jer1,tptzm0800lh_jer1,tptzm0900lh_jer1,tptzm1000lh_jer1,tptzm1100lh_jer1,tptzm1200lh_jer1,tptzm1300lh_jer1,tptzm1400lh_jer1,tptzm1500lh_jer1,tptzm1600lh_jer1,tptzm1700lh_jer1,tptzm1800lh_jer1);

	MakeHistos(CUTSR,   plot,bin[i],Min[i],Max[i],4,
		       data_jer2,background_jer2, 
			   ZToNuNu_jer2,QCD_jer2,WToLNu_jer2,TT_jer2,ST_jer2,VV_jer2,
			   tptzm0700lh_jer2,tptzm0800lh_jer2,tptzm0900lh_jer2,tptzm1000lh_jer2,tptzm1100lh_jer2,tptzm1200lh_jer2,tptzm1300lh_jer2,tptzm1400lh_jer2,tptzm1500lh_jer2,tptzm1600lh_jer2,tptzm1700lh_jer2,tptzm1800lh_jer2);
	*/
	
	MakeHistosPdfQcd(CUT,plot,bin[i],Min[i],Max[i],0,8, 
			   ZToNuNu_qcd1,QCD_qcd1,WToLNu_qcd1,TT_qcd1,ST_qcd1,VV_qcd1,
			   tptzm0700lh_qcd1,tptzm0800lh_qcd1,tptzm0900lh_qcd1,tptzm1000lh_qcd1,tptzm1100lh_qcd1,tptzm1200lh_qcd1,tptzm1300lh_qcd1,tptzm1400lh_qcd1,tptzm1500lh_qcd1,tptzm1600lh_qcd1,tptzm1700lh_qcd1,tptzm1800lh_qcd1,
			   ZToNuNu_qcd2,QCD_qcd2,WToLNu_qcd2,TT_qcd2,ST_qcd2,VV_qcd2,
			   tptzm0700lh_qcd2,tptzm0800lh_qcd2,tptzm0900lh_qcd2,tptzm1000lh_qcd2,tptzm1100lh_qcd2,tptzm1200lh_qcd2,tptzm1300lh_qcd2,tptzm1400lh_qcd2,tptzm1500lh_qcd2,tptzm1600lh_qcd2,tptzm1700lh_qcd2,tptzm1800lh_qcd2);
	
	MakeHistosPdfQcd(CUT,plot,bin[i],Min[i],Max[i],111,213, 
			   ZToNuNu_pdf1,QCD_pdf1,WToLNu_pdf1,TT_pdf1,ST_pdf1,VV_pdf1,
			   tptzm0700lh_pdf1,tptzm0800lh_pdf1,tptzm0900lh_pdf1,tptzm1000lh_pdf1,tptzm1100lh_pdf1,tptzm1200lh_pdf1,tptzm1300lh_pdf1,tptzm1400lh_pdf1,tptzm1500lh_pdf1,tptzm1600lh_pdf1,tptzm1700lh_pdf1,tptzm1800lh_pdf1,
			   ZToNuNu_pdf2,QCD_pdf2,WToLNu_pdf2,TT_pdf2,ST_pdf2,VV_pdf2,
			   tptzm0700lh_pdf2,tptzm0800lh_pdf2,tptzm0900lh_pdf2,tptzm1000lh_pdf2,tptzm1100lh_pdf2,tptzm1200lh_pdf2,tptzm1300lh_pdf2,tptzm1400lh_pdf2,tptzm1500lh_pdf2,tptzm1600lh_pdf2,tptzm1700lh_pdf2,tptzm1800lh_pdf2);
	

	SaveRootFileForLimit_dineutrino_v2(save,category,dPMet,BTag,TopPt,dPTop,ht,Met);

	double ZToNuNuYield_errStat= 0.; double ZToNuNuYield     = ZToNuNu    ->IntegralAndError(1,bin[i],ZToNuNuYield_errStat); 
	double QCDYield_errStat    = 0.; double QCDYield         = QCD        ->IntegralAndError(1,bin[i],QCDYield_errStat);
    double WToLNuYield_errStat = 0.; double WToLNuYield      = WToLNu     ->IntegralAndError(1,bin[i],WToLNuYield_errStat); 
    double TTYield_errStat     = 0.; double TTYield          = TT         ->IntegralAndError(1,bin[i],TTYield_errStat); 
    double STYield_errStat     = 0.; double STYield          = ST         ->IntegralAndError(1,bin[i],STYield_errStat); 
    double VVYield_errStat     = 0.; double VVYield          = VV         ->IntegralAndError(1,bin[i],VVYield_errStat); 
    double tptzm0700lh_errStat = 0.; double tptzm0700lhYield = tptzm0700lh->IntegralAndError(1,bin[i],tptzm0700lh_errStat); 
    double tptzm0900lh_errStat = 0.; double tptzm0900lhYield = tptzm0900lh->IntegralAndError(1,bin[i],tptzm0900lh_errStat); 
	double tptzm1400lh_errStat = 0.; double tptzm1400lhYield = tptzm1400lh->IntegralAndError(1,bin[i],tptzm1400lh_errStat); 
    double tptzm1700lh_errStat = 0.; double tptzm1700lhYield = tptzm1700lh->IntegralAndError(1,bin[i],tptzm1700lh_errStat);

	MakeHistoErrors(ZToNuNu, ZToNuNu_zje1, ZToNuNu_zje2, ZToNuNu_wje1, ZToNuNu_wje2, ZToNuNu_ttb1, ZToNuNu_ttb2);
	MakeHistoErrors(WToLNu, WToLNu_zje1, WToLNu_zje2, WToLNu_wje1, WToLNu_wje2, WToLNu_ttb1, WToLNu_ttb2);
	MakeHistoErrors(TT, TT_zje1, TT_zje2, TT_wje1, TT_wje2, TT_ttb1, TT_ttb2);
	MakeHistoErrorsMC( QCD,  QCD_pup1, QCD_pup2, QCD_for1,  QCD_for2,  QCD_bta1,  QCD_bta2,  QCD_jes1,  QCD_jes2,  QCD_jer1,  QCD_jer2 );
	MakeHistoErrorsMC( ST,   ST_pup1,  ST_pup2, ST_for1, ST_for2, ST_bta1,  ST_bta2, ST_jes1, ST_jes2, ST_jer1, ST_jer2 );
	MakeHistoErrorsMC( VV,   VV_pup1,  VV_pup2, VV_for1, VV_for2, VV_bta1,  VV_bta2, VV_jes1, VV_jes2, VV_jer1, VV_jer2);
	MakeHistoErrorsMC( tptzm0700lh,   tptzm0700lh_pup1,  tptzm0700lh_pup2, tptzm0700lh_for1, tptzm0700lh_for2, tptzm0700lh_bta1, tptzm0700lh_bta2, tptzm0700lh_jes1, tptzm0700lh_jes2, tptzm0700lh_jer1, tptzm0700lh_jer2);
	MakeHistoErrorsMC( tptzm0900lh,   tptzm0900lh_pup1,  tptzm0900lh_pup2, tptzm0900lh_for1, tptzm0900lh_for2, tptzm0900lh_bta1, tptzm0900lh_bta2, tptzm0900lh_jes1, tptzm0900lh_jes2, tptzm0900lh_jer1, tptzm0900lh_jer2);
	MakeHistoErrorsMC( tptzm1400lh,   tptzm1400lh_pup1,  tptzm1400lh_pup2, tptzm1400lh_for1, tptzm1400lh_for2, tptzm1400lh_bta1, tptzm1400lh_bta2, tptzm1400lh_jes1, tptzm1400lh_jes2, tptzm1400lh_jer1, tptzm1400lh_jer2);
	MakeHistoErrorsMC( tptzm1700lh,   tptzm1700lh_pup1,  tptzm1700lh_pup2, tptzm1700lh_for1, tptzm1700lh_for2, tptzm1700lh_bta1, tptzm1700lh_bta2, tptzm1700lh_jes1, tptzm1700lh_jes2, tptzm1700lh_jer1, tptzm1700lh_jer2);

	double ZToNuNuYield_errSyst= 0.; ZToNuNuYield     = ZToNuNu    ->IntegralAndError(1,bin[i],ZToNuNuYield_errSyst); 
	double QCDYield_errSyst    = 0.; QCDYield         = QCD        ->IntegralAndError(1,bin[i],QCDYield_errSyst);
    double WToLNuYield_errSyst = 0.; WToLNuYield      = WToLNu     ->IntegralAndError(1,bin[i],WToLNuYield_errSyst); 
    double TTYield_errSyst     = 0.; TTYield          = TT         ->IntegralAndError(1,bin[i],TTYield_errSyst); 
    double STYield_errSyst     = 0.; STYield          = ST         ->IntegralAndError(1,bin[i],STYield_errSyst); 
    double VVYield_errSyst     = 0.; VVYield          = VV         ->IntegralAndError(1,bin[i],VVYield_errSyst); 
    double tptzm0700lh_errSyst = 0.; tptzm0700lhYield = tptzm0700lh->IntegralAndError(1,bin[i],tptzm0700lh_errSyst); 
    double tptzm0900lh_errSyst = 0.; tptzm0900lhYield = tptzm0900lh->IntegralAndError(1,bin[i],tptzm0900lh_errSyst); 
	double tptzm1400lh_errSyst = 0.; tptzm1400lhYield = tptzm1400lh->IntegralAndError(1,bin[i],tptzm1400lh_errSyst); 
    double tptzm1700lh_errSyst = 0.; tptzm1700lhYield = tptzm1700lh->IntegralAndError(1,bin[i],tptzm1700lh_errSyst);

    ZToNuNuYield_errSyst = sqrt(pow(ZToNuNuYield_errSyst,2) - pow(ZToNuNuYield_errStat,2));
	QCDYield_errSyst     = sqrt(pow(QCDYield_errSyst    ,2) - pow(QCDYield_errStat    ,2));
	WToLNuYield_errSyst  = sqrt(pow(WToLNuYield_errSyst ,2) - pow(WToLNuYield_errStat ,2));
	TTYield_errSyst      = sqrt(pow(TTYield_errSyst     ,2) - pow(TTYield_errStat     ,2));
    STYield_errSyst      = sqrt(pow(STYield_errSyst     ,2) - pow(STYield_errStat     ,2));
    VVYield_errSyst      = sqrt(pow(VVYield_errSyst     ,2) - pow(VVYield_errStat     ,2));
    tptzm0700lh_errSyst = sqrt(pow(tptzm0700lh_errSyst,2) - pow(tptzm0700lh_errStat,2));
    tptzm0900lh_errSyst = sqrt(pow(tptzm0900lh_errSyst,2) - pow(tptzm0900lh_errStat,2));
	tptzm1400lh_errSyst = sqrt(pow(tptzm1400lh_errSyst,2) - pow(tptzm1400lh_errStat,2));
    tptzm1700lh_errSyst = sqrt(pow(tptzm1700lh_errSyst,2) - pow(tptzm1700lh_errStat,2));

    /*Double_t dataErr     = 0; Float_t dataYield     = data   ->IntegralAndError(1,tptzm0700lh->GetNbinsX()-1,dataErr,"");
	Double_t ZToNuNu_Err = 0; Float_t ZToNuNu_Yield = ZToNuNu->IntegralAndError(1,tptzm0700lh->GetNbinsX(),ZToNuNu_Err,"");
	Double_t QCD_Err     = 0; Float_t QCD_Yield     = QCD    ->IntegralAndError(1,tptzm0700lh->GetNbinsX(),QCD_Err,"");
	Double_t WToLNu_Err  = 0; Float_t WToLNu_Yield  = WToLNu ->IntegralAndError(1,tptzm0700lh->GetNbinsX(),WToLNu_Err,"");
	Double_t TT_Err = 0; Float_t TT_Yield = TT->IntegralAndError(1,tptzm0700lh->GetNbinsX(),TT_Err,"");
	Double_t ST_Err = 0; Float_t ST_Yield = ST->IntegralAndError(1,tptzm0700lh->GetNbinsX(),ST_Err,"");
	Double_t VV_Err = 0; Float_t VV_Yield = VV->IntegralAndError(1,tptzm0700lh->GetNbinsX(),VV_Err, "");
	Double_t tptzm0700_Err= 0; Float_t tptzm0700_Yield = tptzm0700lh->IntegralAndError(1,tptzm0700lh->GetNbinsX(),tptzm0700_Err,"");
	Double_t tptzm0900_Err= 0; Float_t tptzm0900_Yield = tptzm0900lh->IntegralAndError(1,tptzm0700lh->GetNbinsX(),tptzm0900_Err,"");
    Double_t tptzm1400_Err= 0; Float_t tptzm1400_Yield = tptzm1400lh->IntegralAndError(1,tptzm0700lh->GetNbinsX(),tptzm1400_Err,"");
	Double_t tptzm1700_Err= 0; Float_t tptzm1700_Yield = tptzm1700lh->IntegralAndError(1,tptzm0700lh->GetNbinsX(),tptzm1700_Err,"");*/
	
	if(i==0){
      cout<<endl;
      //cout<<"Plotting "<<name[i]<<endl;
      //cout<<"DATA      = "<<data->Integral()<<" +/- "<<dataErr<<endl; 
	  /*cout<<"ZToNuNu   = "<<ZToNuNu->Integral()<<" +/- "<<sqrt(ZToNuNu_Err*ZToNuNu_Err)<<endl;
	  cout<<"QCD       = "<<QCD->Integral()<<" +/- "<<sqrt(QCD_Err*QCD_Err)<<endl;
	  cout<<"WToLNu    = "<<WToLNu->Integral()<<" +/- "<<sqrt(WToLNu_Err*WToLNu_Err)<<endl;
	  cout<<"TT        = "<<TT->Integral()<<" +/- "<<sqrt(TT_Err*TT_Err)<<endl;
	  cout<<"ST        = "<<ST->Integral()<<" +/- "<<sqrt(ST_Err*ST_Err)<<endl;
	  cout<<"Diboson   = "<<VV->Integral()<<" +/- "<<sqrt(VV_Err*VV_Err)<<endl;
	  cout<<"Total BKG = "<<ZToNuNu->Integral()+QCD->Integral()+WToLNu->Integral()+TT->Integral()+ST->Integral()+VV->Integral()<<" +/- "<<
		  sqrt(ZToNuNu_Err*ZToNuNu_Err+QCD_Err*QCD_Err+WToLNu_Err*WToLNu_Err+TT_Err*TT_Err+ST_Err*ST_Err+VV_Err*VV_Err)<<endl;
	  cout<<"Tprime LH 0700 = "<<tptzm0700lh->Integral()<<" +/- "<<sqrt(tptzm0700_Err*tptzm0700_Err)<<endl;
	  cout<<"Tprime LH 0900 = "<<tptzm0900lh->Integral()<<" +/- "<<sqrt(tptzm0900_Err*tptzm0900_Err)<<endl;
	  cout<<"Tprime LH 1400 = "<<tptzm1400lh->Integral()<<" +/- "<<sqrt(tptzm1400_Err*tptzm1400_Err)<<endl;
	  cout<<"Tprime LH 1700 = "<<tptzm1700lh->Integral()<<" +/- "<<sqrt(tptzm1700_Err*tptzm1700_Err)<<endl;*/

	  cout<<"Number of ZToNuNu  events    = "<<ZToNuNuYield<<"+/-"<<ZToNuNuYield_errStat<<"(stat)+/-"<<ZToNuNuYield_errSyst<<"(syst)"<<endl;
	  cout<<"Number of QCD  events from MC   = "<<QCDYield<<"+/-"<<QCDYield_errStat<<"(stat)+/-"<<QCDYield_errSyst<<"(syst)"<<endl;
	  cout<<"Number of WToLNu  events   = "<<WToLNuYield<<"+/-"<<WToLNuYield_errStat<<"(stat)+/-"<<WToLNuYield_errSyst<<"(syst)"<<endl;
      cout<<"Number of ST  events from MC   = "<<STYield<<"+/-"<<STYield_errStat<<"(stat)+/-"<<STYield_errSyst<<"(syst)"<<endl;
      cout<<"Number of TT  events    = "<<TTYield<<"+/-"<<TTYield_errStat<<"(stat)+/-"<<TTYield_errSyst<<"(syst)"<<endl;
      cout<<"Number of VV  events from MC   = "<<VVYield<<"+/-"<<VVYield_errStat<<"(stat)+/-"<<VVYield_errSyst<<"(syst)"<<endl;
      cout<<"Number of signal events 0.7TeV = "<<tptzm0700lh->Integral()<<"+/-"<<tptzm0700lh_errStat<<"(stat)+/-"<<tptzm0700lh_errSyst<<"(syst)"<<endl;
	  cout<<"Number of signal events 0.9TeV = "<<tptzm0900lh->Integral()<<"+/-"<<tptzm0900lh_errStat<<"(stat)+/-"<<tptzm0900lh_errSyst<<"(syst)"<<endl;
      cout<<"Number of signal events 1.4TeV = "<<tptzm1400lh->Integral()<<"+/-"<<tptzm1400lh_errStat<<"(stat)+/-"<<tptzm1400lh_errSyst<<"(syst)"<<endl;
	  cout<<"Number of signal events 1.7TeV = "<<tptzm1700lh->Integral()<<"+/-"<<tptzm1700lh_errStat<<"(stat)+/-"<<tptzm1700lh_errSyst<<"(syst)"<<endl;
	
	}

    tptzm0700lh->SetLineWidth(2); tptzm0900lh->SetLineWidth(2); tptzm1400lh->SetLineWidth(2); tptzm1700lh->SetLineWidth(2); 
	tptzm1700lh->SetLineStyle(2); tptzm0700lh->SetLineColor(2); tptzm0900lh->SetLineColor(2); tptzm1400lh->SetLineColor(2); tptzm1700lh->SetLineColor(2); 
	ZToNuNu->SetLineWidth(2);  QCD->SetLineWidth(2); WToLNu->SetLineWidth(2); TT->SetLineWidth(2); ST->SetLineWidth(2); VV->SetLineWidth(2); 
	ZToNuNu->SetLineColor(kOrange); QCD->SetLineColor(kGreen-3); WToLNu->SetLineColor(kCyan-4); TT->SetLineColor(kGreen+3); ST->SetLineColor(kGreen+3); VV->SetLineColor(kCyan+2);
	ZToNuNu->SetFillColor(kOrange); QCD->SetFillColor(kGreen-3); WToLNu->SetFillColor(kCyan-4); TT->SetFillColor(kGreen+3); ST->SetFillColor(kGreen+3); VV->SetFillColor(kCyan+2); 
	data->SetLineWidth(2); data->SetLineColor(1); data->SetMarkerColor(1); data->SetMarkerStyle(20); data->SetMarkerSize(1.3);

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
    
    TGraphAsymmErrors *gDATA = new TGraphAsymmErrors(data);	
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

    /*TH1F *RATIO2 = (TH1F*)background_SR->Clone();
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
    }*/

	TH1F *RATIO2 = (TH1F*)background->Clone();
    Double_t x[bin[i]]; Double_t exl[bin[i]]; Double_t exh[bin[i]];
    Double_t y[bin[i]]; Double_t eyl[bin[i]]; Double_t eyh[bin[i]]; 
    for(int m=0; m<background->GetNbinsX(); m++){ 
      x[m]=Min[i]+m*(Max[i]-Min[i])/bin[i]+(Max[i]-Min[i])/(2*bin[i]);
      exl[m]=(Max[i]-Min[i])/(2*bin[i]);
      exh[m]=(Max[i]-Min[i])/(2*bin[i]);
      RATIO2->SetBinContent(m+1,1);
      if(background->GetBinContent(m+1)!=0) {
	y[m]=data->GetBinContent(m+1)/background->GetBinContent(m+1);
	eyl[m]=sqrt(gDATA->GetErrorYlow(m)*gDATA->GetErrorYlow(m))/background->GetBinContent(m+1);
	eyh[m]=sqrt(gDATA->GetErrorYhigh(m)*gDATA->GetErrorYhigh(m))/background->GetBinContent(m+1);
	RATIO2->SetBinError(m+1,background->GetBinError(m+1)/background->GetBinContent(m+1));
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
    //RATIO->GetYaxis()->SetTitle("observed/MC");
    RATIO->GetYaxis()->SetTitle("observed/expected");
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

	hs->Add(ST);
	hs->Add(TT);
	hs->Add(WToLNu);
	hs->Add(VV);
	hs->Add(QCD);
	hs->Add(ZToNuNu);
	
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
    tptzm0900lh->Draw("samehisto");
    tptzm1700lh->Draw("samehisto");

    data->Draw("E same"); 

    /*background_SR->SetFillStyle(3005);
    background_SR->SetFillColor(12);
    background_SR->SetLineColor(12);
    background_SR->Draw("E2same");*/

	background->SetFillStyle(3005);
    background->SetFillColor(12);
    background->SetLineColor(12);
    background->Draw("E2same");
    
    float maxy=-10;
    float ADD=20;
    for(int ABC=0; ABC<data->GetNbinsX(); ABC++){
      if(background->GetBinContent(ABC+1)+ADD>=maxy) maxy=background->GetBinContent(ABC+1)+ADD;
      if(data      ->GetBinContent(ABC+1)+ADD>=maxy) maxy=data      ->GetBinContent(ABC+1)+ADD;
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
    TLegendEntry *ple2 = pl2->AddEntry(data, "data",  "L"); 
    ple2 = pl2->AddEntry(ZToNuNu, "Z to NuNu",  "F");
    ple2 = pl2->AddEntry(QCD, "QCD",  "F");
	ple2 = pl2->AddEntry(WToLNu, "W to LNu",  "F");
    ple2 = pl2->AddEntry(VV, "VV (V = Z or W)",  "F");
    ple2 = pl2->AddEntry(ST, "t#bar{t} and single-top",  "F");
    ple2 = pl2->AddEntry(tptzm0900lh, "T, M=0.9TeV, #sigma#times100",  "L"); 
    ple2 = pl2->AddEntry(tptzm1700lh, "T, M=1.7TeV, #sigma#times100",  "L"); 
    pl2->Draw();
    
    TString NAME = name[i];
    cout<<"Finished "<<NAME<<endl;
    //c1->SaveAs("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/"+NAME+".png");
	c1->SaveAs(NAME+".png");
    c1->Draw(); 
	}

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


void MakeHistos(char CUTPre[1000],const char *plot, int BIN,double MIN,double MAX,int JETSyst,
		TH1F* &data_func,TH1F* &background_func,
		TH1F* &ZToNuNu_func,TH1F* &QCD_func,TH1F* &WToLNu_func,TH1F* &TT_func,TH1F* &ST_func,TH1F* &VV_func,
		TH1F* &tptzm0700lh_func,TH1F* &tptzm0800lh_func,TH1F* &tptzm0900lh_func,TH1F* &tptzm1000lh_func,TH1F* &tptzm1100lh_func,TH1F* &tptzm1200lh_func,TH1F* &tptzm1300lh_func,TH1F* &tptzm1400lh_func,TH1F* &tptzm1500lh_func,TH1F* &tptzm1600lh_func,TH1F* &tptzm1700lh_func,TH1F* &tptzm1800lh_func){

  TH1F *data; TH1F *tptzm0700lh; TH1F *tptzm0800lh; TH1F *tptzm0900lh; TH1F *tptzm1000lh; TH1F *tptzm1100lh; TH1F *tptzm1200lh; TH1F *tptzm1300lh; TH1F *tptzm1400lh; TH1F *tptzm1500lh; TH1F *tptzm1600lh; TH1F *tptzm1700lh; TH1F *tptzm1800lh; 
  TH1F *ZToNuNu_1; TH1F *ZToNuNu_2; TH1F *ZToNuNu_3; TH1F *ZToNuNu_4; TH1F *ZToNuNu_5; TH1F *ZToNuNu_6; TH1F *ZToNuNu_7; 
  TH1F *QCD_1; TH1F *QCD_2; TH1F *QCD_3; TH1F *QCD_4; TH1F *QCD_5; TH1F *QCD_6; TH1F *QCD_7; 
  TH1F *WToLNu_1; TH1F *WToLNu_2; TH1F *WToLNu_3; TH1F *WToLNu_4; TH1F *WToLNu_5; TH1F *WToLNu_6; TH1F *WToLNu_7;
  TH1F *TT_1; TH1F *TT_2; 
  TH1F *ST_1; TH1F *ST_2; TH1F *ST_3; TH1F *ST_4; 
  TH1F *ZZ1; TH1F *ZZ2; TH1F *ZZ3; TH1F *WZ1; TH1F *WZ2; TH1F *WZ3; TH1F *WW1; TH1F *WW2; 
  if(JETSyst==0){  
    GetHisto(CUTPre, Tree01, data        ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree02, tptzm0700lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree03, tptzm0800lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree04, tptzm0900lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree05, tptzm1000lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree06, tptzm1100lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree07, tptzm1200lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree08, tptzm1300lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09, tptzm1400lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree10, tptzm1500lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree11, tptzm1600lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree12, tptzm1700lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree13, tptzm1800lh ,plot,BIN,MIN,MAX);
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
  }else if(JETSyst==1){
    GetHisto(CUTPre, Tree01_J1, data        ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree02_J1, tptzm0700lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree03_J1, tptzm0800lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree04_J1, tptzm0900lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree05_J1, tptzm1000lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree06_J1, tptzm1100lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree07_J1, tptzm1200lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree08_J1, tptzm1300lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_J1, tptzm1400lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree10_J1, tptzm1500lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree11_J1, tptzm1600lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree12_J1, tptzm1700lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree13_J1, tptzm1800lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree14_J1, ZToNuNu_1   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree15_J1, ZToNuNu_2   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree16_J1, ZToNuNu_3   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree17_J1, ZToNuNu_4   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree18_J1, ZToNuNu_5   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree19_J1, ZToNuNu_6   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree20_J1, ZToNuNu_7   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree21_J1, QCD_1      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree22_J1, QCD_2      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree23_J1, QCD_3      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree24_J1, QCD_4      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree25_J1, QCD_5      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree26_J1, QCD_6      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree27_J1, QCD_7      ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree28_J1, WToLNu_1   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree29_J1, WToLNu_2   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree30_J1, WToLNu_3   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree31_J1, WToLNu_4   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree32_J1, WToLNu_5   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree33_J1, WToLNu_6   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree34_J1, WToLNu_7   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree35_J1, TT_1    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree36_J1, TT_2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree37_J1, ST_1    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree38_J1, ST_2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree39_J1, ST_3    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree40_J1, ST_4    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree41_J1, ZZ1    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree42_J1, ZZ2    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree43_J1, ZZ3    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree44_J1, WW1    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree45_J1, WW2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree46_J1, WZ1    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree47_J1, WZ2    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree48_J1, WZ3    ,plot,BIN,MIN,MAX);
  }else if(JETSyst==2){
    GetHisto(CUTPre, Tree01_J2, data        ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree02_J2, tptzm0700lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree03_J2, tptzm0800lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree04_J2, tptzm0900lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree05_J2, tptzm1000lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree06_J2, tptzm1100lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree07_J2, tptzm1200lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree08_J2, tptzm1300lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_J2, tptzm1400lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree10_J2, tptzm1500lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree11_J2, tptzm1600lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree12_J2, tptzm1700lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree13_J2, tptzm1800lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree14_J2, ZToNuNu_1   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree15_J2, ZToNuNu_2   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree16_J2, ZToNuNu_3   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree17_J2, ZToNuNu_4   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree18_J2, ZToNuNu_5   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree19_J2, ZToNuNu_6   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree20_J2, ZToNuNu_7   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree21_J2, QCD_1      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree22_J2, QCD_2      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree23_J2, QCD_3      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree24_J2, QCD_4      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree25_J2, QCD_5      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree26_J2, QCD_6      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree27_J2, QCD_7      ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree28_J2, WToLNu_1   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree29_J2, WToLNu_2   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree30_J2, WToLNu_3   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree31_J2, WToLNu_4   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree32_J2, WToLNu_5   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree33_J2, WToLNu_6   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree34_J2, WToLNu_7   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree35_J2, TT_1    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree36_J2, TT_2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree37_J2, ST_1    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree38_J2, ST_2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree39_J2, ST_3    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree40_J2, ST_4    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree41_J2, ZZ1    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree42_J2, ZZ2    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree43_J2, ZZ3    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree44_J2, WW1    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree45_J2, WW2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree46_J2, WZ1    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree47_J2, WZ2    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree48_J2, WZ3    ,plot,BIN,MIN,MAX);
  }else if(JETSyst==3){
    GetHisto(CUTPre, Tree01_J3, data        ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree02_J3, tptzm0700lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree03_J3, tptzm0800lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree04_J3, tptzm0900lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree05_J3, tptzm1000lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree06_J3, tptzm1100lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree07_J3, tptzm1200lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree08_J3, tptzm1300lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_J3, tptzm1400lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree10_J3, tptzm1500lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree11_J3, tptzm1600lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree12_J3, tptzm1700lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree13_J3, tptzm1800lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree14_J3, ZToNuNu_1   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree15_J3, ZToNuNu_2   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree16_J3, ZToNuNu_3   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree17_J3, ZToNuNu_4   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree18_J3, ZToNuNu_5   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree19_J3, ZToNuNu_6   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree20_J3, ZToNuNu_7   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree21_J3, QCD_1      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree22_J3, QCD_2      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree23_J3, QCD_3      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree24_J3, QCD_4      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree25_J3, QCD_5      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree26_J3, QCD_6      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree27_J3, QCD_7      ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree28_J3, WToLNu_1   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree29_J3, WToLNu_2   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree30_J3, WToLNu_3   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree31_J3, WToLNu_4   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree32_J3, WToLNu_5   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree33_J3, WToLNu_6   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree34_J3, WToLNu_7   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree35_J3, TT_1    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree36_J3, TT_2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree37_J3, ST_1    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree38_J3, ST_2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree39_J3, ST_3    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree40_J3, ST_4    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree41_J3, ZZ1    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree42_J3, ZZ2    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree43_J3, ZZ3    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree44_J3, WW1    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree45_J3, WW2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree46_J3, WZ1    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree47_J3, WZ2    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree48_J3, WZ3    ,plot,BIN,MIN,MAX);
  }else if(JETSyst==4){
    GetHisto(CUTPre, Tree01_J4, data        ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree02_J4, tptzm0700lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree03_J4, tptzm0800lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree04_J4, tptzm0900lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree05_J4, tptzm1000lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree06_J4, tptzm1100lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree07_J4, tptzm1200lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree08_J4, tptzm1300lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_J4, tptzm1400lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree10_J4, tptzm1500lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree11_J4, tptzm1600lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree12_J4, tptzm1700lh ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree13_J4, tptzm1800lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree14_J4, ZToNuNu_1   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree15_J4, ZToNuNu_2   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree16_J4, ZToNuNu_3   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree17_J4, ZToNuNu_4   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree18_J4, ZToNuNu_5   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree19_J4, ZToNuNu_6   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree20_J4, ZToNuNu_7   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree21_J4, QCD_1      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree22_J4, QCD_2      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree23_J4, QCD_3      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree24_J4, QCD_4      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree25_J4, QCD_5      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree26_J4, QCD_6      ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree27_J4, QCD_7      ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree28_J4, WToLNu_1   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree29_J4, WToLNu_2   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree30_J4, WToLNu_3   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree31_J4, WToLNu_4   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree32_J4, WToLNu_5   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree33_J4, WToLNu_6   ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree34_J4, WToLNu_7   ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree35_J4, TT_1    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree36_J4, TT_2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree37_J4, ST_1    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree38_J4, ST_2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree39_J4, ST_3    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree40_J4, ST_4    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree41_J4, ZZ1    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree42_J4, ZZ2    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree43_J4, ZZ3    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree44_J4, WW1    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree45_J4, WW2    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree46_J4, WZ1    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree47_J4, WZ2    ,plot,BIN,MIN,MAX);
	GetHisto(CUTPre, Tree48_J4, WZ3    ,plot,BIN,MIN,MAX);
  }
	
	for(int j=1; j<data->GetNbinsX()+1; j++){
    if(tptzm0700lh->GetBinContent(j)>0){tptzm0700lh->SetBinError(j,sqrt(w0700*w0700*tptzm0700lh->GetBinContent(j)));}else{tptzm0700lh->SetBinError(j,0);}
	if(tptzm0800lh->GetBinContent(j)>0){tptzm0800lh->SetBinError(j,sqrt(w0800*w0800*tptzm0800lh->GetBinContent(j)));}else{tptzm0800lh->SetBinError(j,0);}
    if(tptzm0900lh->GetBinContent(j)>0){tptzm0900lh->SetBinError(j,sqrt(w0900*w0900*tptzm0900lh->GetBinContent(j)));}else{tptzm0900lh->SetBinError(j,0);}
	if(tptzm1000lh->GetBinContent(j)>0){tptzm1000lh->SetBinError(j,sqrt(w1000*w1000*tptzm1000lh->GetBinContent(j)));}else{tptzm1000lh->SetBinError(j,0);}
	if(tptzm1100lh->GetBinContent(j)>0){tptzm1100lh->SetBinError(j,sqrt(w1100*w1100*tptzm1100lh->GetBinContent(j)));}else{tptzm1100lh->SetBinError(j,0);}
	if(tptzm1200lh->GetBinContent(j)>0){tptzm1200lh->SetBinError(j,sqrt(w1200*w1200*tptzm1200lh->GetBinContent(j)));}else{tptzm1200lh->SetBinError(j,0);}
	if(tptzm1300lh->GetBinContent(j)>0){tptzm1300lh->SetBinError(j,sqrt(w1300*w1300*tptzm1300lh->GetBinContent(j)));}else{tptzm1300lh->SetBinError(j,0);}
    if(tptzm1400lh->GetBinContent(j)>0){tptzm1400lh->SetBinError(j,sqrt(w1400*w1400*tptzm1400lh->GetBinContent(j)));}else{tptzm1400lh->SetBinError(j,0);}
	if(tptzm1500lh->GetBinContent(j)>0){tptzm1500lh->SetBinError(j,sqrt(w1500*w1500*tptzm1500lh->GetBinContent(j)));}else{tptzm1500lh->SetBinError(j,0);}
	if(tptzm1600lh->GetBinContent(j)>0){tptzm1600lh->SetBinError(j,sqrt(w1600*w1600*tptzm1600lh->GetBinContent(j)));}else{tptzm1600lh->SetBinError(j,0);}
    if(tptzm1700lh->GetBinContent(j)>0){tptzm1700lh->SetBinError(j,sqrt(w1700*w1700*tptzm1700lh->GetBinContent(j)));}else{tptzm1700lh->SetBinError(j,0);}
	if(tptzm1800lh->GetBinContent(j)>0){tptzm1800lh->SetBinError(j,sqrt(w1800*w1800*tptzm1800lh->GetBinContent(j)));}else{tptzm1800lh->SetBinError(j,0);}
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

	double N_tptzm0700lh_err = tptzm0700lh->GetBinError(j)*tptzm0700lh->GetBinError(j);
	double N_tptzm0800lh_err = tptzm0800lh->GetBinError(j)*tptzm0800lh->GetBinError(j);
	double N_tptzm0900lh_err = tptzm0900lh->GetBinError(j)*tptzm0900lh->GetBinError(j);
	double N_tptzm1000lh_err = tptzm1000lh->GetBinError(j)*tptzm1000lh->GetBinError(j);
	double N_tptzm1100lh_err = tptzm1100lh->GetBinError(j)*tptzm1100lh->GetBinError(j);
	double N_tptzm1200lh_err = tptzm1200lh->GetBinError(j)*tptzm1200lh->GetBinError(j);
	double N_tptzm1300lh_err = tptzm1300lh->GetBinError(j)*tptzm1300lh->GetBinError(j);
	double N_tptzm1400lh_err = tptzm1400lh->GetBinError(j)*tptzm1400lh->GetBinError(j);
	double N_tptzm1500lh_err = tptzm1500lh->GetBinError(j)*tptzm1500lh->GetBinError(j);
	double N_tptzm1600lh_err = tptzm1600lh->GetBinError(j)*tptzm1600lh->GetBinError(j);
	double N_tptzm1700lh_err = tptzm1700lh->GetBinError(j)*tptzm1700lh->GetBinError(j);
	double N_tptzm1800lh_err = tptzm1800lh->GetBinError(j)*tptzm1800lh->GetBinError(j);
	
	double N_data_err    = data->GetBinError(j)*data->GetBinError(j);
    double N_ZToNuNu_err = ZToNuNu_1->GetBinError(j)*ZToNuNu_1->GetBinError(j) + ZToNuNu_2->GetBinError(j)*ZToNuNu_2->GetBinError(j) + ZToNuNu_3->GetBinError(j)*ZToNuNu_3->GetBinError(j) + ZToNuNu_4->GetBinError(j)*ZToNuNu_4->GetBinError(j) + ZToNuNu_5->GetBinError(j)*ZToNuNu_5->GetBinError(j) + ZToNuNu_6->GetBinError(j)*ZToNuNu_6->GetBinError(j) + ZToNuNu_7->GetBinError(j)*ZToNuNu_7->GetBinError(j);
    double N_QCD_err     = QCD_1->GetBinError(j)*QCD_1->GetBinError(j) + QCD_2->GetBinError(j)*QCD_2->GetBinError(j) + QCD_3->GetBinError(j)*QCD_3->GetBinError(j) + QCD_4->GetBinError(j)*QCD_4->GetBinError(j) + QCD_5->GetBinError(j)*QCD_5->GetBinError(j) + QCD_6->GetBinError(j)*QCD_6->GetBinError(j) + QCD_7->GetBinError(j)*QCD_7->GetBinError(j);
    double N_WToLNu_err  = WToLNu_1->GetBinError(j)*WToLNu_1->GetBinError(j)+WToLNu_2->GetBinError(j)*WToLNu_2->GetBinError(j)+WToLNu_3->GetBinError(j)*WToLNu_3->GetBinError(j)+WToLNu_4->GetBinError(j)*WToLNu_4->GetBinError(j)+WToLNu_5->GetBinError(j)*WToLNu_5->GetBinError(j)+WToLNu_6->GetBinError(j)*WToLNu_6->GetBinError(j)+WToLNu_7->GetBinError(j)*WToLNu_7->GetBinError(j);
	double N_TT_err      = TT_1->GetBinError(j)*TT_1->GetBinError(j)+TT_2->GetBinError(j)*TT_2->GetBinError(j);
	double N_ST_err      = ST_1->GetBinError(j)*ST_1->GetBinError(j) + ST_2->GetBinError(j)*ST_2->GetBinError(j)+ ST_3->GetBinError(j)*ST_3->GetBinError(j)+ ST_4->GetBinError(j)*ST_4->GetBinError(j);
    double N_VV_err      = ZZ1->GetBinError(j)*ZZ1->GetBinError(j) + ZZ2->GetBinError(j)*ZZ2->GetBinError(j) + ZZ3->GetBinError(j)*ZZ3->GetBinError(j) + WW1->GetBinError(j)*WW1->GetBinError(j) + WW2->GetBinError(j)*WW2->GetBinError(j) + WZ1->GetBinError(j)*WZ1->GetBinError(j) + WZ2->GetBinError(j)*WZ2->GetBinError(j) + WZ3->GetBinError(j)*WZ3->GetBinError(j); 
	
	tptzm0700lh->SetBinContent(j,w0700*tptzm0700lh->GetBinContent(j));
	tptzm0800lh->SetBinContent(j,w0800*tptzm0800lh->GetBinContent(j));
    tptzm0900lh->SetBinContent(j,w0900*tptzm0900lh->GetBinContent(j));
	tptzm1000lh->SetBinContent(j,w1000*tptzm1000lh->GetBinContent(j));
	tptzm1100lh->SetBinContent(j,w1100*tptzm1100lh->GetBinContent(j));
	tptzm1200lh->SetBinContent(j,w1200*tptzm1200lh->GetBinContent(j));
	tptzm1300lh->SetBinContent(j,w1300*tptzm1300lh->GetBinContent(j));
    tptzm1400lh->SetBinContent(j,w1400*tptzm1400lh->GetBinContent(j));
	tptzm1500lh->SetBinContent(j,w1500*tptzm1500lh->GetBinContent(j));
	tptzm1600lh->SetBinContent(j,w1600*tptzm1600lh->GetBinContent(j));
    tptzm1700lh->SetBinContent(j,w1700*tptzm1700lh->GetBinContent(j));
	tptzm1800lh->SetBinContent(j,w1800*tptzm1800lh->GetBinContent(j));
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
    
	double N_tptzm0700lh = tptzm0700lh->GetBinContent(j);
	double N_tptzm0800lh = tptzm0800lh->GetBinContent(j);
	double N_tptzm0900lh = tptzm0900lh->GetBinContent(j);
	double N_tptzm1000lh = tptzm1000lh->GetBinContent(j);
	double N_tptzm1100lh = tptzm1100lh->GetBinContent(j);
	double N_tptzm1200lh = tptzm1200lh->GetBinContent(j);
	double N_tptzm1300lh = tptzm1300lh->GetBinContent(j);
	double N_tptzm1400lh = tptzm1400lh->GetBinContent(j);
	double N_tptzm1500lh = tptzm1500lh->GetBinContent(j);
	double N_tptzm1600lh = tptzm1600lh->GetBinContent(j);
	double N_tptzm1700lh = tptzm1700lh->GetBinContent(j);
	double N_tptzm1800lh = tptzm1800lh->GetBinContent(j);
	double N_data    = data->GetBinContent(j);
    double N_ZToNuNu = ZToNuNu_1->GetBinContent(j) + ZToNuNu_2->GetBinContent(j) + ZToNuNu_3->GetBinContent(j) + ZToNuNu_4->GetBinContent(j) + ZToNuNu_5->GetBinContent(j) + ZToNuNu_6->GetBinContent(j) + ZToNuNu_7->GetBinContent(j);
    double N_QCD     = QCD_1->GetBinContent(j) + QCD_2->GetBinContent(j) + QCD_3->GetBinContent(j) + QCD_4->GetBinContent(j) + QCD_5->GetBinContent(j) + QCD_6->GetBinContent(j) + QCD_7->GetBinContent(j);
    double N_WToLNu  = WToLNu_1->GetBinContent(j) + WToLNu_2->GetBinContent(j) + WToLNu_3->GetBinContent(j) + WToLNu_4->GetBinContent(j) + WToLNu_5->GetBinContent(j) + WToLNu_6->GetBinContent(j)+ WToLNu_7->GetBinContent(j);
	double N_TT      = TT_1->GetBinContent(j) + TT_2->GetBinContent(j);
    double N_ST      = ST_1 ->GetBinContent(j) + ST_2 ->GetBinContent(j) + ST_3 ->GetBinContent(j) + ST_4 ->GetBinContent(j);
	double N_VV      = ZZ1->GetBinContent(j)+ZZ2->GetBinContent(j)+ZZ3->GetBinContent(j)+WW1->GetBinContent(j)+WW2->GetBinContent(j)+WZ1->GetBinContent(j)+WZ2->GetBinContent(j)+WZ3->GetBinContent(j);
	
	data_func->SetBinError(j,sqrt(N_data_err));
	data_func->SetBinContent(j,N_data);    
    tptzm0700lh_func->SetBinError(j,sqrt(N_tptzm0700lh_err));
	tptzm0700lh_func->SetBinContent(j,N_tptzm0700lh);
	tptzm0800lh_func->SetBinError(j,sqrt(N_tptzm0800lh_err));
	tptzm0800lh_func->SetBinContent(j,N_tptzm0800lh);
	tptzm0900lh_func->SetBinError(j,sqrt(N_tptzm0900lh_err));
	tptzm0900lh_func->SetBinContent(j,N_tptzm0900lh);
	tptzm1000lh_func->SetBinError(j,sqrt(N_tptzm1000lh_err));
	tptzm1000lh_func->SetBinContent(j,N_tptzm1000lh);
	tptzm1100lh_func->SetBinError(j,sqrt(N_tptzm1100lh_err));
	tptzm1100lh_func->SetBinContent(j,N_tptzm1100lh);
	tptzm1200lh_func->SetBinError(j,sqrt(N_tptzm1200lh_err));
	tptzm1200lh_func->SetBinContent(j,N_tptzm1200lh);
	tptzm1300lh_func->SetBinError(j,sqrt(N_tptzm1300lh_err));
	tptzm1300lh_func->SetBinContent(j,N_tptzm1300lh);
	tptzm1400lh_func->SetBinError(j,sqrt(N_tptzm1400lh_err));
	tptzm1400lh_func->SetBinContent(j,N_tptzm1400lh);
	tptzm1500lh_func->SetBinError(j,sqrt(N_tptzm1500lh_err));
	tptzm1500lh_func->SetBinContent(j,N_tptzm1500lh);
	tptzm1600lh_func->SetBinError(j,sqrt(N_tptzm1600lh_err));
	tptzm1600lh_func->SetBinContent(j,N_tptzm1600lh);
	tptzm1700lh_func->SetBinError(j,sqrt(N_tptzm1700lh_err));
	tptzm1700lh_func->SetBinContent(j,N_tptzm1700lh);
	tptzm1800lh_func->SetBinError(j,sqrt(N_tptzm1800lh_err));
	tptzm1800lh_func->SetBinContent(j,N_tptzm1800lh);
	ZToNuNu_func->SetBinError(j,sqrt(N_ZToNuNu_err));
	ZToNuNu_func->SetBinContent(j,N_ZToNuNu);
	QCD_func->SetBinError(j,sqrt(N_QCD_err));
	QCD_func->SetBinContent(j,N_QCD);
	WToLNu_func->SetBinError(j,sqrt(N_WToLNu_err));
	WToLNu_func->SetBinContent(j,N_WToLNu);
	TT_func->SetBinError(j,sqrt(N_TT_err));
	TT_func->SetBinContent(j,N_TT);
	ST_func->SetBinError(j,sqrt(N_ST_err));
	ST_func->SetBinContent(j,N_ST);
	VV_func->SetBinError(j,sqrt(N_VV_err));
	VV_func->SetBinContent(j,N_VV);
	background_func->SetBinError(j,sqrt(N_ZToNuNu_err+N_QCD_err+N_WToLNu_err+N_TT_err+N_ST_err+N_VV_err));
	background_func->SetBinContent(j,N_ZToNuNu+N_QCD+N_WToLNu+N_TT+N_ST+N_VV);
	
 }

  delete data; delete tptzm0700lh; delete tptzm0800lh; delete tptzm0900lh; delete tptzm1000lh; delete tptzm1100lh; delete tptzm1200lh; delete tptzm1300lh; delete tptzm1400lh; delete tptzm1500lh; delete tptzm1600lh; delete tptzm1700lh; delete tptzm1800lh;
  delete ZToNuNu_1; delete ZToNuNu_2; delete ZToNuNu_3; delete ZToNuNu_4;  delete ZToNuNu_5;  delete ZToNuNu_6;  delete ZToNuNu_7;
  delete QCD_1; delete QCD_2; delete QCD_3; delete QCD_4; delete QCD_5; delete QCD_6; delete QCD_7; 
  delete WToLNu_1; delete WToLNu_2; delete WToLNu_3; delete WToLNu_4; delete WToLNu_5; delete WToLNu_6; delete WToLNu_7; 
  delete TT_1; delete TT_2; 
  delete ST_1; delete ST_2;  delete ST_3; delete ST_4;  
  delete WW1; delete WW2; delete WZ1; delete WZ2; delete WZ3; delete ZZ1; delete ZZ2;  delete ZZ3;
  
}


void MakeHistoErrors(TH1F* &histo_SR, TH1F* histo_Z1, TH1F* histo_Z2, TH1F* histo_W1, TH1F* histo_W2, TH1F* histo_T1, TH1F* histo_T2){
  for(int m=1; m<histo_SR->GetNbinsX()+1; m++){
    float ErrMc = histo_SR->GetBinError(m); 
    float ErrZJ = max(fabs(histo_SR->GetBinContent(m)-histo_Z1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_Z2->GetBinContent(m)));
    float ErrWT = max(fabs(histo_SR->GetBinContent(m)-histo_W1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_W2->GetBinContent(m)));
    float ErrTT = max(fabs(histo_SR->GetBinContent(m)-histo_T1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_T2->GetBinContent(m)));
    float TOTAL = sqrt(ErrMc*ErrMc + ErrZJ*ErrZJ + ErrWT*ErrWT + ErrTT*ErrTT);
    //cout<<m<<" "<<histo_SR->GetBinContent(m)<<" "<<ErrMc<<" "<<ErrBT<<" "<<ErrZJ<<" "<<ErrCL<<" "<<TOTAL<<" "<<endl;
    histo_SR ->SetBinError(m,TOTAL);
  }
}

void MakeHistoErrorsMC(TH1F* &histo_SR,  TH1F* histo_P1, TH1F* histo_P2, TH1F* histo_F1, TH1F* histo_F2, TH1F* histo_B1, TH1F* histo_B2, TH1F* histo_J1, TH1F* histo_J2, TH1F* histo_J3, TH1F* histo_J4){
  for(int m=1; m<histo_SR->GetNbinsX()+1; m++){
    float ErrMc = histo_SR->GetBinError(m); 
    float ErrLU = 0.026*histo_SR->GetBinContent(m);
    float ErrPU = max(fabs(histo_SR->GetBinContent(m)-histo_P1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_P2->GetBinContent(m)));
	float ErrFO = max(fabs(histo_SR->GetBinContent(m)-histo_F1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_F2->GetBinContent(m)));
    float ErrBT = max(fabs(histo_SR->GetBinContent(m)-histo_B1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_B2->GetBinContent(m))); 
    float ErrJS = max(fabs(histo_SR->GetBinContent(m)-histo_J1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_J2->GetBinContent(m))); 
    float ErrJR = max(fabs(histo_SR->GetBinContent(m)-histo_J3->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_J4->GetBinContent(m))); 
	float TOTAL = sqrt(ErrMc*ErrMc + ErrLU*ErrLU + ErrPU*ErrPU + ErrBT*ErrBT + ErrFO*ErrFO + ErrJS*ErrJS + ErrJR*ErrJR );
    //cout<<m<<" "<<histo_SR->GetBinContent(m)<<" "<<ErrMc<<" "<<ErrLU<<" "<<ErrMU<<" "<<ErrEL<<" "<<ErrTM<<" "<<ErrTE<<" "<<ErrPU<<" "<<ErrBT<<" "<<ErrTO<<" "<<ErrFO<<" "<<ErrWJ<<" "<<ErrJS<<" "<<ErrJR<<endl;
    histo_SR ->SetBinError(m,TOTAL);
  }
}

/*void MakeHistosPdfQcd(char CUTinit[1000],const char *plot,int BIN ,float MIN,float MAX,int imin,int imax,
	          TH1F* &ZToNuNu_func1,TH1F* &QCD_func1,TH1F* &WToLNu_func1,TH1F* &TT_func1,TH1F* &ST_func1,TH1F* &VV_func1,
	          TH1F* &tptzm0700lh_func1,TH1F* &tptzm0800lh_func1,TH1F* &tptzm0900lh_func1,TH1F* &tptzm1000lh_func1,TH1F* &tptzm1100lh_func1,TH1F* &tptzm1200lh_func1,TH1F* &tptzm1300lh_func1,TH1F* &tptzm1400lh_func1,TH1F* &tptzm1500lh_func1,TH1F* &tptzm1600lh_func1,TH1F* &tptzm1700lh_func1,TH1F* &tptzm1800lh_func1,
			  TH1F* &ZToNuNu_func2,TH1F* &QCD_func2,TH1F* &WToLNu_func2,TH1F* &TT_func2,TH1F* &ST_func2,TH1F* &VV_func2,
			  TH1F* &tptzm0700lh_func2,TH1F* &tptzm0800lh_func2,TH1F* &tptzm0900lh_func2,TH1F* &tptzm1000lh_func2,TH1F* &tptzm1100lh_func2,TH1F* &tptzm1200lh_func2,TH1F* &tptzm1300lh_func2,TH1F* &tptzm1400lh_func2,TH1F* &tptzm1500lh_func2,TH1F* &tptzm1600lh_func2,TH1F* &tptzm1700lh_func2,TH1F* &tptzm1800lh_func2){
  //BIN1 = BIN1 + 1;
  TH1F *RMS0700_pre; TH1F *RMS0800_pre; TH1F *RMS0900_pre; TH1F *RMS1000_pre; TH1F *RMS1100_pre; TH1F *RMS1200_pre; TH1F *RMS1300_pre; TH1F *RMS1400_pre; TH1F *RMS1500_pre; TH1F *RMS1600_pre; TH1F *RMS1700_pre; TH1F *RMS1800_pre; 
  TH1F *RMSZToNuNu_1_pre; TH1F *RMSZToNuNu_2_pre; TH1F *RMSZToNuNu_3_pre; TH1F *RMSZToNuNu_4_pre; TH1F *RMSZToNuNu_5_pre; TH1F *RMSZToNuNu_6_pre; TH1F *RMSZToNuNu_7_pre;
  TH1F *RMSQCD_1_pre; TH1F *RMSQCD_2_pre; TH1F *RMSQCD_3_pre; TH1F *RMSQCD_4_pre; TH1F *RMSQCD_5_pre; TH1F *RMSQCD_6_pre; TH1F *RMSQCD_7_pre;
  TH1F *RMSWToLNu_1_pre; TH1F *RMSWToLNu_2_pre; TH1F *RMSWToLNu_3_pre; TH1F *RMSWToLNu_4_pre; TH1F *RMSWToLNu_5_pre; TH1F *RMSWToLNu_6_pre; TH1F *RMSWToLNu_7_pre;
  TH1F *RMSTT_1_pre; TH1F *RMSTT_2_pre; 
  TH1F *RMSST_1_pre; TH1F *RMSST_2_pre; TH1F *RMSST_3_pre; TH1F *RMSST_4_pre;
  TH1F *RMSZZ1_pre; TH1F *RMSZZ2_pre; TH1F *RMSZZ3_pre; TH1F *RMSWZ1_pre; TH1F *RMSWZ2_pre; TH1F *RMSWZ3_pre; TH1F *RMSWW1_pre; TH1F *RMSWW2_pre; 
  
  TH1F *RMS0700 = new TH1F("RMS0700", "RMS0700", 100,-0.5,0.5); TH1F *RMS0800 = new TH1F("RMS0800", "RMS0800", 100,-0.5,0.5);
  TH1F *RMS0900 = new TH1F("RMS0900", "RMS0900", 100,-0.5,0.5); TH1F *RMS1000 = new TH1F("RMS1000", "RMS1000", 100,-0.5,0.5);
  TH1F *RMS1100 = new TH1F("RMS1100", "RMS1100", 100,-0.5,0.5); TH1F *RMS1200 = new TH1F("RMS1200", "RMS1200", 100,-0.5,0.5);
  TH1F *RMS1300 = new TH1F("RMS1300", "RMS1300", 100,-0.5,0.5); TH1F *RMS1400 = new TH1F("RMS1400", "RMS1400", 100,-0.5,0.5);
  TH1F *RMS1500 = new TH1F("RMS1500", "RMS1500", 100,-0.5,0.5); TH1F *RMS1600 = new TH1F("RMS1600", "RMS1600", 100,-0.5,0.5);
  TH1F *RMS1700 = new TH1F("RMS1700", "RMS1700", 100,-0.5,0.5); TH1F *RMS1800 = new TH1F("RMS1800", "RMS1800", 100,-0.5,0.5);

  TH1F *RMSZToNuNu_1 = new TH1F("RMSZToNuNu_1", "RMSZToNuNu_1", 100,-0.5,0.5); TH1F *RMSZToNuNu_2 = new TH1F("RMSZToNuNu_2", "RMSZToNuNu_2", 100,-0.5,0.5);
  TH1F *RMSZToNuNu_3 = new TH1F("RMSZToNuNu_3", "RMSZToNuNu_3", 100,-0.5,0.5); TH1F *RMSZToNuNu_4 = new TH1F("RMSZToNuNu_4", "RMSZToNuNu_4", 100,-0.5,0.5);
  TH1F *RMSZToNuNu_5 = new TH1F("RMSZToNuNu_5", "RMSZToNuNu_5", 100,-0.5,0.5); TH1F *RMSZToNuNu_6 = new TH1F("RMSZToNuNu_6", "RMSZToNuNu_6", 100,-0.5,0.5);
  TH1F *RMSZToNuNu_7 = new TH1F("RMSZToNuNu_7", "RMSZToNuNu_7", 100,-0.5,0.5); 

  TH1F *RMSQCD_1 = new TH1F("RMSQCD_1", "RMSQCD_1", 100,-0.5,0.5); TH1F *RMSQCD_2 = new TH1F("RMSQCD_2", "RMSQCD_2", 100,-0.5,0.5);
  TH1F *RMSQCD_3 = new TH1F("RMSQCD_3", "RMSQCD_3", 100,-0.5,0.5); TH1F *RMSQCD_4 = new TH1F("RMSQCD_4", "RMSQCD_4", 100,-0.5,0.5);
  TH1F *RMSQCD_5 = new TH1F("RMSQCD_5", "RMSQCD_5", 100,-0.5,0.5); TH1F *RMSQCD_6 = new TH1F("RMSQCD_6", "RMSQCD_6", 100,-0.5,0.5);
  TH1F *RMSQCD_7 = new TH1F("RMSQCD_7", "RMSQCD_7", 100,-0.5,0.5); 

  TH1F *RMSWToLNu_1 = new TH1F("RMSWToLNu_1", "RMSWToLNu_1", 100,-0.5,0.5); TH1F *RMSWToLNu_2 = new TH1F("RMSWToLNu_2", "RMSWToLNu_2", 100,-0.5,0.5);
  TH1F *RMSWToLNu_3 = new TH1F("RMSWToLNu_3", "RMSWToLNu_3", 100,-0.5,0.5); TH1F *RMSWToLNu_4 = new TH1F("RMSWToLNu_4", "RMSWToLNu_4", 100,-0.5,0.5);
  TH1F *RMSWToLNu_5 = new TH1F("RMSWToLNu_5", "RMSWToLNu_5", 100,-0.5,0.5); TH1F *RMSWToLNu_6 = new TH1F("RMSWToLNu_6", "RMSWToLNu_6", 100,-0.5,0.5);
  TH1F *RMSWToLNu_7 = new TH1F("RMSWToLNu_7", "RMSWToLNu_7", 100,-0.5,0.5); 

  TH1F *RMSTT_1 = new TH1F("RMSTT_1", "RMSTT_1", 100,-0.5,0.5); TH1F *RMSTT_2 = new TH1F("RMSTT_2", "RMSTT_2", 100,-0.5,0.5);

  TH1F *RMSST_1 = new TH1F("RMSST_1", "RMSST_1", 100,-0.5,0.5); TH1F *RMSST_2 = new TH1F("RMSST_2", "RMSST_2", 100,-0.5,0.5);
  TH1F *RMSST_3 = new TH1F("RMSST_3", "RMSST_3", 100,-0.5,0.5); TH1F *RMSST_4 = new TH1F("RMSST_4", "RMSST_4", 100,-0.5,0.5);

  TH1F *RMSZZ1 = new TH1F("RMSZZ1", "RMSZZ1", 100,-0.5,0.5); TH1F *RMSZZ2 = new TH1F("RMSZZ2", "RMSZZ2", 100,-0.5,0.5);
  TH1F *RMSZZ3 = new TH1F("RMSZZ3", "RMSZZ3", 100,-0.5,0.5); TH1F *RMSWZ1 = new TH1F("RMSWZ1", "RMSWZ1", 100,-0.5,0.5);
  TH1F *RMSWZ2 = new TH1F("RMSWZ2", "RMSWZ2", 100,-0.5,0.5); TH1F *RMSWZ3 = new TH1F("RMSWZ3", "RMSWZ3", 100,-0.5,0.5);
  TH1F *RMSWW1 = new TH1F("RMSWW1", "RMSWW1", 100,-0.5,0.5); TH1F *RMSWW2 = new TH1F("RMSWW2", "RMSWW2", 100,-0.5,0.5);
  
  //float INIT1=1; float INIT2=1; float INIT3=1; float INIT4=1; float INIT5=1; float INIT6=1; float INIT7=1; float INIT8=1; float INIT9=1; float INIT10=1; float INIT11=1;
  for(int i=imin; i<imax; i++){
    if(i==0) continue;
    if(i==5) continue;
    if(i==7) continue;
    if(i==111) continue;
    
    char CUT[1000]; char genWeights_ratio[1000];
    sprintf(CUT,"%s",CUTinit);
	sprintf(genWeights_ratio,"(1-genWeights%i/genWeights0)",i);
    GetHisto(CUT, Tree02,  RMS0700_pre  ,genWeights_ratio,100,-0.5,0.5);
    GetHisto(CUT, Tree03,  RMS0800_pre  ,genWeights_ratio,100,-0.5,0.5);
    GetHisto(CUT, Tree04,  RMS0900_pre  ,genWeights_ratio,100,-0.5,0.5);
    GetHisto(CUT, Tree05,  RMS1000_pre  ,genWeights_ratio,100,-0.5,0.5);
    GetHisto(CUT, Tree06,  RMS1100_pre  ,genWeights_ratio,100,-0.5,0.5);
    GetHisto(CUT, Tree07,  RMS1200_pre  ,genWeights_ratio,100,-0.5,0.5);
    GetHisto(CUT, Tree08,  RMS1300_pre  ,genWeights_ratio,100,-0.5,0.5);
    GetHisto(CUT, Tree09,  RMS1400_pre  ,genWeights_ratio,100,-0.5,0.5);
    GetHisto(CUT, Tree10,  RMS1500_pre  ,genWeights_ratio,100,-0.5,0.5);
    GetHisto(CUT, Tree11,  RMS1600_pre  ,genWeights_ratio,100,-0.5,0.5);
    GetHisto(CUT, Tree12,  RMS1700_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree13,  RMS1800_pre  ,genWeights_ratio,100,-0.5,0.5);

	GetHisto(CUT, Tree14,  RMSZToNuNu_1_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree15,  RMSZToNuNu_2_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree16,  RMSZToNuNu_3_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree17,  RMSZToNuNu_4_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree18,  RMSZToNuNu_5_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree19,  RMSZToNuNu_6_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree20,  RMSZToNuNu_7_pre  ,genWeights_ratio,100,-0.5,0.5);

	GetHisto(CUT, Tree21,  RMSQCD_1_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree22,  RMSQCD_2_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree23,  RMSQCD_3_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree24,  RMSQCD_4_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree25,  RMSQCD_5_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree26,  RMSQCD_6_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree27,  RMSQCD_7_pre  ,genWeights_ratio,100,-0.5,0.5);

	GetHisto(CUT, Tree28,  RMSWToLNu_1_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree29,  RMSWToLNu_2_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree30,  RMSWToLNu_3_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree31,  RMSWToLNu_4_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree32,  RMSWToLNu_5_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree33,  RMSWToLNu_6_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree34,  RMSWToLNu_7_pre  ,genWeights_ratio,100,-0.5,0.5);

	GetHisto(CUT, Tree35,  RMSTT_1_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree36,  RMSTT_2_pre  ,genWeights_ratio,100,-0.5,0.5);

	GetHisto(CUT, Tree37,  RMSST_1_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree38,  RMSST_2_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree39,  RMSST_3_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree40,  RMSST_4_pre  ,genWeights_ratio,100,-0.5,0.5);

	GetHisto(CUT, Tree41,  RMSZZ1_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree42,  RMSZZ2_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree43,  RMSZZ3_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree44,  RMSWW1_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree45,  RMSWW2_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree46,  RMSWZ1_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree47,  RMSWZ2_pre  ,genWeights_ratio,100,-0.5,0.5);
	GetHisto(CUT, Tree48,  RMSWZ3_pre  ,genWeights_ratio,100,-0.5,0.5);

	RMS0700->Add(RMS0700_pre); RMS0800->Add(RMS0800_pre); RMS0900->Add(RMS0900_pre); RMS1000->Add(RMS1000_pre); RMS1100->Add(RMS1100_pre); RMS1200->Add(RMS1200_pre); RMS1300->Add(RMS1300_pre); RMS1400->Add(RMS1400_pre); RMS1500->Add(RMS1500_pre); RMS1600->Add(RMS1600_pre);  RMS1700->Add(RMS1700_pre); RMS1800->Add(RMS1800_pre);
    RMSZToNuNu_1->Add(RMSZToNuNu_1_pre); RMSZToNuNu_2->Add(RMSZToNuNu_2_pre); RMSZToNuNu_3->Add(RMSZToNuNu_3_pre); RMSZToNuNu_4->Add(RMSZToNuNu_4_pre); RMSZToNuNu_5->Add(RMSZToNuNu_5_pre); RMSZToNuNu_6->Add(RMSZToNuNu_6_pre); RMSZToNuNu_7->Add(RMSZToNuNu_7_pre);
	RMSQCD_1->Add(RMSQCD_1_pre); RMSQCD_2->Add(RMSQCD_2_pre); RMSQCD_3->Add(RMSQCD_3_pre); RMSQCD_4->Add(RMSQCD_4_pre); RMSQCD_5->Add(RMSQCD_5_pre); RMSQCD_6->Add(RMSQCD_6_pre); RMSQCD_7->Add(RMSQCD_7_pre);
	RMSWToLNu_1->Add(RMSWToLNu_1_pre); RMSWToLNu_2->Add(RMSWToLNu_2_pre); RMSWToLNu_3->Add(RMSWToLNu_3_pre); RMSWToLNu_4->Add(RMSWToLNu_4_pre); RMSWToLNu_5->Add(RMSWToLNu_5_pre); RMSWToLNu_6->Add(RMSWToLNu_6_pre); RMSWToLNu_7->Add(RMSWToLNu_7_pre);
    RMSTT_1->Add(RMSTT_1_pre); RMSTT_2->Add(RMSTT_2_pre);
	RMSST_1->Add(RMSST_1_pre); RMSST_2->Add(RMSST_2_pre); RMSST_3->Add(RMSST_3_pre); RMSST_4->Add(RMSST_4_pre);
    RMSZZ1->Add(RMSZZ1_pre); RMSZZ2->Add(RMSZZ2_pre); RMSZZ3->Add(RMSZZ3_pre); RMSWW1->Add(RMSWW1_pre); RMSWW2->Add(RMSWW2_pre); RMSWZ1->Add(RMSWZ1_pre); RMSWZ2->Add(RMSWZ2_pre); RMSWZ3->Add(RMSWZ3_pre);
  
  }
  TCanvas* c2 = new TCanvas("c1","c1",0,0,600,600);
  RMSTT_1->Draw();
  c2->SaveAs("RMSTT_1.png");

  float RMSZToNuNu = sqrt(RMSZToNuNu_1->GetRMS()*RMSZToNuNu_1->GetRMS() + RMSZToNuNu_2->GetRMS()*RMSZToNuNu_2->GetRMS() + RMSZToNuNu_3->GetRMS()*RMSZToNuNu_3->GetRMS() + RMSZToNuNu_4->GetRMS()*RMSZToNuNu_4->GetRMS() + RMSZToNuNu_5->GetRMS()*RMSZToNuNu_5->GetRMS() + RMSZToNuNu_6->GetRMS()*RMSZToNuNu_6->GetRMS() + RMSZToNuNu_7->GetRMS()*RMSZToNuNu_7->GetRMS());
  float RMSQCD =     sqrt(RMSQCD_1->GetRMS()*RMSQCD_1->GetRMS() + RMSQCD_2->GetRMS()*RMSQCD_2->GetRMS() + RMSQCD_3->GetRMS()*RMSQCD_3->GetRMS() + RMSQCD_4->GetRMS()*RMSQCD_4->GetRMS() + RMSQCD_5->GetRMS()*RMSQCD_5->GetRMS() + RMSQCD_6->GetRMS()*RMSQCD_6->GetRMS() + RMSQCD_7->GetRMS()*RMSQCD_7->GetRMS());
  float RMSWToLNu =  sqrt(RMSWToLNu_1->GetRMS()*RMSWToLNu_1->GetRMS() + RMSWToLNu_2->GetRMS()*RMSWToLNu_2->GetRMS() + RMSWToLNu_3->GetRMS()*RMSWToLNu_3->GetRMS() + RMSWToLNu_4->GetRMS()*RMSWToLNu_4->GetRMS() + RMSWToLNu_5->GetRMS()*RMSWToLNu_5->GetRMS() + RMSWToLNu_6->GetRMS()*RMSWToLNu_6->GetRMS() + RMSWToLNu_7->GetRMS()*RMSWToLNu_7->GetRMS());
  float RMSTT = sqrt(RMSTT_1->GetRMS()*RMSTT_1->GetRMS() + RMSTT_2->GetRMS()*RMSTT_2->GetRMS());
  float RMSST = sqrt(RMSST_1->GetRMS()*RMSST_1->GetRMS() + RMSST_2->GetRMS()*RMSST_2->GetRMS() + RMSST_3->GetRMS()*RMSST_3->GetRMS() + RMSST_4->GetRMS()*RMSST_4->GetRMS());
  float RMSVV = sqrt(RMSZZ1->GetRMS()*RMSZZ1->GetRMS() + RMSZZ2->GetRMS()*RMSZZ2->GetRMS() + RMSZZ3->GetRMS()*RMSZZ3->GetRMS() + RMSWW1->GetRMS()*RMSWW1->GetRMS() + RMSWW2->GetRMS()*RMSWW2->GetRMS() + RMSWZ1->GetRMS()*RMSWZ1->GetRMS() + RMSWZ2->GetRMS()*RMSWZ2->GetRMS() + RMSWZ3->GetRMS()*RMSWZ3->GetRMS());
  //cout<<"RMSZToNuNu = "<<RMSZToNuNu<<endl;
  //cout<<"RMSQCD = "<<RMSQCD<<endl;
  //cout<<"RMSWToLNu = "<<RMSWToLNu<<endl;
  //cout<<"RMSTT = "<<RMSTT<<endl;
  //cout<<"RMSST = "<<RMSST<<endl;
  //cout<<"RMSVV = "<<RMSVV<<endl;

  for(int j=1; j<BIN+1; j++){
  tptzm0700lh_func1->SetBinContent(j,tptzm0700lh->GetBinContent(j) + RMS0700->GetRMS());
  tptzm0800lh_func1->SetBinContent(j,tptzm0800lh->GetBinContent(j) + RMS0800->GetRMS());
  tptzm0900lh_func1->SetBinContent(j,tptzm0900lh->GetBinContent(j) + RMS0900->GetRMS());
  tptzm1000lh_func1->SetBinContent(j,tptzm1000lh->GetBinContent(j) + RMS1000->GetRMS());
  tptzm1100lh_func1->SetBinContent(j,tptzm1100lh->GetBinContent(j) + RMS1100->GetRMS());
  tptzm1200lh_func1->SetBinContent(j,tptzm1200lh->GetBinContent(j) + RMS1200->GetRMS());
  tptzm1300lh_func1->SetBinContent(j,tptzm1300lh->GetBinContent(j) + RMS1300->GetRMS());
  tptzm1400lh_func1->SetBinContent(j,tptzm1400lh->GetBinContent(j) + RMS1400->GetRMS());
  tptzm1500lh_func1->SetBinContent(j,tptzm1500lh->GetBinContent(j) + RMS1500->GetRMS());
  tptzm1600lh_func1->SetBinContent(j,tptzm1600lh->GetBinContent(j) + RMS1600->GetRMS());
  tptzm1700lh_func1->SetBinContent(j,tptzm1700lh->GetBinContent(j) + RMS1700->GetRMS());
  ZToNuNu_func1->SetBinContent(j,ZToNuNu->GetBinContent(j) + RMSZToNuNu);
  QCD_func1->SetBinContent(j,QCD->GetBinContent(j) + RMSQCD);
  WToLNu_func1->SetBinContent(j,WToLNu->GetBinContent(j) + RMSWToLNu);
  TT_func1->SetBinContent(j,TT->GetBinContent(j) + RMSTT);
  ST_func1->SetBinContent(j,ST->GetBinContent(j) + RMSST);
  VV_func1->SetBinContent(j,VV->GetBinContent(j) + RMSVV);

  tptzm0700lh_func2->SetBinContent(j,TMath::Max(0., tptzm0700lh->GetBinContent(j) - RMS0700->GetRMS()));
  tptzm0800lh_func2->SetBinContent(j,TMath::Max(0., tptzm0800lh->GetBinContent(j) - RMS0800->GetRMS()));
  tptzm0900lh_func2->SetBinContent(j,TMath::Max(0., tptzm0900lh->GetBinContent(j) - RMS0900->GetRMS()));
  tptzm1000lh_func2->SetBinContent(j,TMath::Max(0., tptzm1000lh->GetBinContent(j) - RMS1000->GetRMS()));
  tptzm1100lh_func2->SetBinContent(j,TMath::Max(0., tptzm1100lh->GetBinContent(j) - RMS1100->GetRMS()));
  tptzm1200lh_func2->SetBinContent(j,TMath::Max(0., tptzm1200lh->GetBinContent(j) - RMS1200->GetRMS()));
  tptzm1300lh_func2->SetBinContent(j,TMath::Max(0., tptzm1300lh->GetBinContent(j) - RMS1300->GetRMS()));
  tptzm1400lh_func2->SetBinContent(j,TMath::Max(0., tptzm1400lh->GetBinContent(j) - RMS1400->GetRMS()));
  tptzm1500lh_func2->SetBinContent(j,TMath::Max(0., tptzm1500lh->GetBinContent(j) - RMS1500->GetRMS()));
  tptzm1600lh_func2->SetBinContent(j,TMath::Max(0., tptzm1600lh->GetBinContent(j) - RMS1600->GetRMS()));
  tptzm1700lh_func2->SetBinContent(j,TMath::Max(0., tptzm1700lh->GetBinContent(j) - RMS1700->GetRMS()));

  ZToNuNu_func2->SetBinContent(j,TMath::Max(0.,ZToNuNu->GetBinContent(j) - RMSZToNuNu));
  QCD_func2->SetBinContent(j,TMath::Max(0.,QCD->GetBinContent(j) - RMSQCD));
  WToLNu_func2->SetBinContent(j,TMath::Max(0.,WToLNu->GetBinContent(j) - RMSWToLNu));
  TT_func2->SetBinContent(j,TMath::Max(0.,TT->GetBinContent(j) - RMSTT));
  ST_func2->SetBinContent(j,TMath::Max(0.,ST->GetBinContent(j) - RMSST));
  VV_func2->SetBinContent(j,TMath::Max(0.,VV->GetBinContent(j) - RMSVV));

  }

  delete RMS0700; delete RMS0800; delete RMS0900; delete RMS1000; delete RMS1100; delete RMS1200; delete RMS1300; delete RMS1400; delete RMS1500; delete RMS1600; delete RMS1700;  delete RMS1800;
  delete RMSZToNuNu_1; delete RMSZToNuNu_2; delete RMSZToNuNu_3; delete RMSZToNuNu_4; delete RMSZToNuNu_5; delete RMSZToNuNu_6; delete RMSZToNuNu_7;
  delete RMSQCD_1; delete RMSQCD_2; delete RMSQCD_3; delete RMSQCD_4; delete RMSQCD_5; delete RMSQCD_6; delete RMSQCD_7;
  delete RMSWToLNu_1; delete RMSWToLNu_2; delete RMSWToLNu_3; delete RMSWToLNu_4; delete RMSWToLNu_5; delete RMSWToLNu_6; delete RMSWToLNu_7;
  delete RMSTT_1; delete RMSTT_2; 
  delete RMSST_1; delete RMSST_2; delete RMSST_3; delete RMSST_4;
  delete RMSZZ1; delete RMSZZ2; delete RMSZZ3; delete RMSWZ1; delete RMSWZ2; delete RMSWZ3; delete RMSWW1; delete RMSWW2; 

  delete RMS0700_pre; delete RMS0800_pre; delete RMS0900_pre; delete RMS1000_pre; delete RMS1100_pre; delete RMS1200_pre; delete RMS1300_pre; delete RMS1400_pre; delete RMS1500_pre; delete RMS1600_pre; delete RMS1700_pre; delete RMS1800_pre;
  delete RMSZToNuNu_1_pre; delete RMSZToNuNu_2_pre; delete RMSZToNuNu_3_pre; delete RMSZToNuNu_4_pre; delete RMSZToNuNu_5_pre; delete RMSZToNuNu_6_pre; delete RMSZToNuNu_7_pre;
  delete RMSQCD_1_pre; delete RMSQCD_2_pre; delete RMSQCD_3_pre; delete RMSQCD_4_pre; delete RMSQCD_5_pre; delete RMSQCD_6_pre; delete RMSQCD_7_pre;
  delete RMSWToLNu_1_pre; delete RMSWToLNu_2_pre; delete RMSWToLNu_3_pre; delete RMSWToLNu_4_pre; delete RMSWToLNu_5_pre; delete RMSWToLNu_6_pre; delete RMSWToLNu_7_pre;
  delete RMSTT_1_pre; delete RMSTT_2_pre; 
  delete RMSST_1_pre; delete RMSST_2_pre; delete RMSST_3_pre; delete RMSST_4_pre;
  delete RMSZZ1_pre; delete RMSZZ2_pre; delete RMSZZ3_pre; delete RMSWZ1_pre; delete RMSWZ2_pre; delete RMSWZ3_pre; delete RMSWW1_pre; delete RMSWW2_pre; 
}

*/
void MakeHistosPdfQcd(char CUTinit[1000],const char *plot,int BIN ,float MIN,float MAX,int imin,int imax,
	          TH1F* &ZToNuNu_func1,TH1F* &QCD_func1,TH1F* &WToLNu_func1,TH1F* &TT_func1,TH1F* &ST_func1,TH1F* &VV_func1,
	          TH1F* &tptzm0700lh_func1,TH1F* &tptzm0800lh_func1,TH1F* &tptzm0900lh_func1,TH1F* &tptzm1000lh_func1,TH1F* &tptzm1100lh_func1,TH1F* &tptzm1200lh_func1,TH1F* &tptzm1300lh_func1,TH1F* &tptzm1400lh_func1,TH1F* &tptzm1500lh_func1,TH1F* &tptzm1600lh_func1,TH1F* &tptzm1700lh_func1,TH1F* &tptzm1800lh_func1,
			  TH1F* &ZToNuNu_func2,TH1F* &QCD_func2,TH1F* &WToLNu_func2,TH1F* &TT_func2,TH1F* &ST_func2,TH1F* &VV_func2,
			  TH1F* &tptzm0700lh_func2,TH1F* &tptzm0800lh_func2,TH1F* &tptzm0900lh_func2,TH1F* &tptzm1000lh_func2,TH1F* &tptzm1100lh_func2,TH1F* &tptzm1200lh_func2,TH1F* &tptzm1300lh_func2,TH1F* &tptzm1400lh_func2,TH1F* &tptzm1500lh_func2,TH1F* &tptzm1600lh_func2,TH1F* &tptzm1700lh_func2,TH1F* &tptzm1800lh_func2){
  //BIN1 = BIN1 + 1;
  TH1F *RMS0700_pre; TH1F *RMS0800_pre; TH1F *RMS0900_pre; TH1F *RMS1000_pre; TH1F *RMS1100_pre; TH1F *RMS1200_pre; TH1F *RMS1300_pre; TH1F *RMS1400_pre; TH1F *RMS1500_pre; TH1F *RMS1600_pre; TH1F *RMS1700_pre; TH1F *RMS1800_pre; 
  TH1F *RMSZToNuNu_1_pre; TH1F *RMSZToNuNu_2_pre; TH1F *RMSZToNuNu_3_pre; TH1F *RMSZToNuNu_4_pre; TH1F *RMSZToNuNu_5_pre; TH1F *RMSZToNuNu_6_pre; TH1F *RMSZToNuNu_7_pre;
  TH1F *RMSQCD_1_pre; TH1F *RMSQCD_2_pre; TH1F *RMSQCD_3_pre; TH1F *RMSQCD_4_pre; TH1F *RMSQCD_5_pre; TH1F *RMSQCD_6_pre; TH1F *RMSQCD_7_pre;
  TH1F *RMSWToLNu_1_pre; TH1F *RMSWToLNu_2_pre; TH1F *RMSWToLNu_3_pre; TH1F *RMSWToLNu_4_pre; TH1F *RMSWToLNu_5_pre; TH1F *RMSWToLNu_6_pre; TH1F *RMSWToLNu_7_pre;
  TH1F *RMSTT_1_pre; TH1F *RMSTT_2_pre; 
  TH1F *RMSST_1_pre; TH1F *RMSST_2_pre; TH1F *RMSST_3_pre; TH1F *RMSST_4_pre;
  TH1F *RMSZZ1_pre; TH1F *RMSZZ2_pre; TH1F *RMSZZ3_pre; TH1F *RMSWZ1_pre; TH1F *RMSWZ2_pre; TH1F *RMSWZ3_pre; TH1F *RMSWW1_pre; TH1F *RMSWW2_pre; 
  
  TH1F *RMS0700 = new TH1F("RMS0700", "RMS0700", 100,-0.5,0.5); TH1F *RMS0800 = new TH1F("RMS0800", "RMS0800", 100,-0.5,0.5);
  TH1F *RMS0900 = new TH1F("RMS0900", "RMS0900", 100,-0.5,0.5); TH1F *RMS1000 = new TH1F("RMS1000", "RMS1000", 100,-0.5,0.5);
  TH1F *RMS1100 = new TH1F("RMS1100", "RMS1100", 100,-0.5,0.5); TH1F *RMS1200 = new TH1F("RMS1200", "RMS1200", 100,-0.5,0.5);
  TH1F *RMS1300 = new TH1F("RMS1300", "RMS1300", 100,-0.5,0.5); TH1F *RMS1400 = new TH1F("RMS1400", "RMS1400", 100,-0.5,0.5);
  TH1F *RMS1500 = new TH1F("RMS1500", "RMS1500", 100,-0.5,0.5); TH1F *RMS1600 = new TH1F("RMS1600", "RMS1600", 100,-0.5,0.5);
  TH1F *RMS1700 = new TH1F("RMS1700", "RMS1700", 100,-0.5,0.5); TH1F *RMS1800 = new TH1F("RMS1800", "RMS1800", 100,-0.5,0.5);

  TH1F *RMSZToNuNu_1 = new TH1F("RMSZToNuNu_1", "RMSZToNuNu_1", 100,-0.5,0.5); TH1F *RMSZToNuNu_2 = new TH1F("RMSZToNuNu_2", "RMSZToNuNu_2", 100,-0.5,0.5);
  TH1F *RMSZToNuNu_3 = new TH1F("RMSZToNuNu_3", "RMSZToNuNu_3", 100,-0.5,0.5); TH1F *RMSZToNuNu_4 = new TH1F("RMSZToNuNu_4", "RMSZToNuNu_4", 100,-0.5,0.5);
  TH1F *RMSZToNuNu_5 = new TH1F("RMSZToNuNu_5", "RMSZToNuNu_5", 100,-0.5,0.5); TH1F *RMSZToNuNu_6 = new TH1F("RMSZToNuNu_6", "RMSZToNuNu_6", 100,-0.5,0.5);
  TH1F *RMSZToNuNu_7 = new TH1F("RMSZToNuNu_7", "RMSZToNuNu_7", 100,-0.5,0.5); TH1F *RMSZToNuNu = new TH1F("RMSZToNuNu", "RMSZToNuNu", 100,-0.5,0.5);

  TH1F *RMSQCD_1 = new TH1F("RMSQCD_1", "RMSQCD_1", 100,-0.5,0.5); TH1F *RMSQCD_2 = new TH1F("RMSQCD_2", "RMSQCD_2", 100,-0.5,0.5);
  TH1F *RMSQCD_3 = new TH1F("RMSQCD_3", "RMSQCD_3", 100,-0.5,0.5); TH1F *RMSQCD_4 = new TH1F("RMSQCD_4", "RMSQCD_4", 100,-0.5,0.5);
  TH1F *RMSQCD_5 = new TH1F("RMSQCD_5", "RMSQCD_5", 100,-0.5,0.5); TH1F *RMSQCD_6 = new TH1F("RMSQCD_6", "RMSQCD_6", 100,-0.5,0.5);
  TH1F *RMSQCD_7 = new TH1F("RMSQCD_7", "RMSQCD_7", 100,-0.5,0.5); TH1F *RMSQCD   = new TH1F("RMSQCD", "RMSQCD", 100,-0.5,0.5);

  TH1F *RMSWToLNu_1 = new TH1F("RMSWToLNu_1", "RMSWToLNu_1", 100,-0.5,0.5); TH1F *RMSWToLNu_2 = new TH1F("RMSWToLNu_2", "RMSWToLNu_2", 100,-0.5,0.5);
  TH1F *RMSWToLNu_3 = new TH1F("RMSWToLNu_3", "RMSWToLNu_3", 100,-0.5,0.5); TH1F *RMSWToLNu_4 = new TH1F("RMSWToLNu_4", "RMSWToLNu_4", 100,-0.5,0.5);
  TH1F *RMSWToLNu_5 = new TH1F("RMSWToLNu_5", "RMSWToLNu_5", 100,-0.5,0.5); TH1F *RMSWToLNu_6 = new TH1F("RMSWToLNu_6", "RMSWToLNu_6", 100,-0.5,0.5);
  TH1F *RMSWToLNu_7 = new TH1F("RMSWToLNu_7", "RMSWToLNu_7", 100,-0.5,0.5); TH1F *RMSWToLNu   = new TH1F("RMSWToLNu", "RMSWToLNu", 100,-0.5,0.5); 

  TH1F *RMSTT_1 = new TH1F("RMSTT_1", "RMSTT_1", 100,-0.5,0.5); TH1F *RMSTT_2 = new TH1F("RMSTT_2", "RMSTT_2", 100,-0.5,0.5);
  TH1F *RMSTT   = new TH1F("RMSTT", "RMSTT", 100,-0.5,0.5);

  TH1F *RMSST_1 = new TH1F("RMSST_1", "RMSST_1", 100,-0.5,0.5); TH1F *RMSST_2 = new TH1F("RMSST_2", "RMSST_2", 100,-0.5,0.5);
  TH1F *RMSST_3 = new TH1F("RMSST_3", "RMSST_3", 100,-0.5,0.5); TH1F *RMSST_4 = new TH1F("RMSST_4", "RMSST_4", 100,-0.5,0.5);
  TH1F *RMSST   = new TH1F("RMSST", "RMSST", 100,-0.5,0.5);

  TH1F *RMSZZ1 = new TH1F("RMSZZ1", "RMSZZ1", 100,-0.5,0.5); TH1F *RMSZZ2 = new TH1F("RMSZZ2", "RMSZZ2", 100,-0.5,0.5);
  TH1F *RMSZZ3 = new TH1F("RMSZZ3", "RMSZZ3", 100,-0.5,0.5); TH1F *RMSWZ1 = new TH1F("RMSWZ1", "RMSWZ1", 100,-0.5,0.5);
  TH1F *RMSWZ2 = new TH1F("RMSWZ2", "RMSWZ2", 100,-0.5,0.5); TH1F *RMSWZ3 = new TH1F("RMSWZ3", "RMSWZ3", 100,-0.5,0.5);
  TH1F *RMSWW1 = new TH1F("RMSWW1", "RMSWW1", 100,-0.5,0.5); TH1F *RMSWW2 = new TH1F("RMSWW2", "RMSWW2", 100,-0.5,0.5);
  TH1F *RMSVV  = new TH1F("RMSVV", "RMSVV", 100,-0.5,0.5);
  
  float INIT1=1;  float INIT2=1;  float INIT3=1;  float INIT4=1;  float INIT5=1;  float INIT6=1;  float INIT7=1;  float INIT8=1;  float INIT9=1;  float INIT10=1; float INIT11=1;
  float INIT12=1; float INIT13=1; float INIT14=1; float INIT15=1; float INIT16=1; float INIT17=1; float INIT18=1; float INIT19=1; float INIT20=1; float INIT21=1; float INIT22=1;
  float INIT23=1; float INIT24=1; float INIT25=1; float INIT26=1; float INIT27=1; float INIT28=1; float INIT29=1; float INIT30=1; float INIT31=1; float INIT32=1; float INIT33=1;
  float INIT34=1; float INIT35=1; float INIT36=1; float INIT37=1; float INIT38=1; float INIT39=1; float INIT40=1; float INIT41=1; float INIT42=1; float INIT43=1; float INIT44=1;
  float INIT45=1; float INIT46=1; float INIT47=1; 

 
  for(int j=1; j<BIN+1; j++){
    float min = MIN + (j-1)*(MAX-MIN)/BIN;
    float max = MIN + j*(MAX-MIN)/BIN;
	
    for(int i=imin; i<imax; i++){
       if(i==5) continue;
       if(i==7) continue;
       int I = 0;
       if(i==111) I=0;
       else       I=i;
    char CUT[1000]; char CUTTrans[1000];
	sprintf(CUTTrans,"((TransverseMassMetTop>%f)&&(TransverseMassMetTop<%f))",min,max);
    sprintf(CUT,"(genWeights%i/genWeights0)*%s*%s",I,CUTinit,CUTTrans);
    GetHisto(CUT, Tree02,  RMS0700_pre  ,plot,1,min,max);
    GetHisto(CUT, Tree03,  RMS0800_pre  ,plot,1,min,max);
    GetHisto(CUT, Tree04,  RMS0900_pre  ,plot,1,min,max);
    GetHisto(CUT, Tree05,  RMS1000_pre  ,plot,1,min,max);
    GetHisto(CUT, Tree06,  RMS1100_pre  ,plot,1,min,max);
    GetHisto(CUT, Tree07,  RMS1200_pre  ,plot,1,min,max);
    GetHisto(CUT, Tree08,  RMS1300_pre  ,plot,1,min,max);
    GetHisto(CUT, Tree09,  RMS1400_pre  ,plot,1,min,max);
    GetHisto(CUT, Tree10,  RMS1500_pre  ,plot,1,min,max);
    GetHisto(CUT, Tree11,  RMS1600_pre  ,plot,1,min,max);
    GetHisto(CUT, Tree12,  RMS1700_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree13,  RMS1800_pre  ,plot,1,min,max);

	GetHisto(CUT, Tree14,  RMSZToNuNu_1_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree15,  RMSZToNuNu_2_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree16,  RMSZToNuNu_3_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree17,  RMSZToNuNu_4_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree18,  RMSZToNuNu_5_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree19,  RMSZToNuNu_6_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree20,  RMSZToNuNu_7_pre  ,plot,1,min,max);

	GetHisto(CUT, Tree21,  RMSQCD_1_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree22,  RMSQCD_2_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree23,  RMSQCD_3_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree24,  RMSQCD_4_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree25,  RMSQCD_5_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree26,  RMSQCD_6_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree27,  RMSQCD_7_pre  ,plot,1,min,max);

	GetHisto(CUT, Tree28,  RMSWToLNu_1_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree29,  RMSWToLNu_2_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree30,  RMSWToLNu_3_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree31,  RMSWToLNu_4_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree32,  RMSWToLNu_5_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree33,  RMSWToLNu_6_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree34,  RMSWToLNu_7_pre  ,plot,1,min,max);

	GetHisto(CUT, Tree35,  RMSTT_1_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree36,  RMSTT_2_pre  ,plot,1,min,max);

	GetHisto(CUT, Tree37,  RMSST_1_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree38,  RMSST_2_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree39,  RMSST_3_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree40,  RMSST_4_pre  ,plot,1,min,max);

	GetHisto(CUT, Tree41,  RMSZZ1_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree42,  RMSZZ2_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree43,  RMSZZ3_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree44,  RMSWW1_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree45,  RMSWW2_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree46,  RMSWZ1_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree47,  RMSWZ2_pre  ,plot,1,min,max);
	GetHisto(CUT, Tree48,  RMSWZ3_pre  ,plot,1,min,max);

	if(I==0){ 
      INIT1  = RMS0700_pre ->Integral();
      INIT2  = RMS0800_pre ->Integral();
      INIT3  = RMS0900_pre ->Integral();
      INIT4  = RMS1000_pre ->Integral();
      INIT5  = RMS1100_pre ->Integral();
      INIT6  = RMS1200_pre ->Integral();
      INIT7  = RMS1300_pre ->Integral();
      INIT8  = RMS1400_pre ->Integral();
      INIT9  = RMS1500_pre ->Integral();
      INIT10 = RMS1600_pre ->Integral();
      INIT11 = RMS1700_pre ->Integral();
	  INIT12 = RMS1800_pre ->Integral();

	  INIT13 = RMSZToNuNu_1_pre->Integral();
	  INIT14 = RMSZToNuNu_2_pre->Integral();
	  INIT15 = RMSZToNuNu_3_pre->Integral();
	  INIT16 = RMSZToNuNu_4_pre->Integral();
	  INIT17 = RMSZToNuNu_5_pre->Integral();
	  INIT18 = RMSZToNuNu_6_pre->Integral();
	  INIT19 = RMSZToNuNu_7_pre->Integral();

	  INIT20 = RMSQCD_1_pre->Integral();
	  INIT21 = RMSQCD_2_pre->Integral();
	  INIT22 = RMSQCD_3_pre->Integral();
	  INIT23 = RMSQCD_4_pre->Integral();
	  INIT24 = RMSQCD_5_pre->Integral();
	  INIT25 = RMSQCD_6_pre->Integral();
	  INIT26 = RMSQCD_7_pre->Integral();

	  INIT27 = RMSWToLNu_1_pre->Integral();
	  INIT28 = RMSWToLNu_2_pre->Integral();
	  INIT29 = RMSWToLNu_3_pre->Integral();
	  INIT30 = RMSWToLNu_4_pre->Integral();
	  INIT31 = RMSWToLNu_5_pre->Integral();
	  INIT32 = RMSWToLNu_6_pre->Integral();
	  INIT33 = RMSWToLNu_7_pre->Integral();

	  INIT34 = RMSTT_1_pre->Integral();
	  INIT35 = RMSTT_2_pre->Integral();

	  INIT36 = RMSST_1_pre->Integral();
	  INIT37 = RMSST_2_pre->Integral();
	  INIT38 = RMSST_3_pre->Integral();
	  INIT39 = RMSST_4_pre->Integral();

	  INIT40 = RMSZZ1_pre->Integral();
	  INIT41 = RMSZZ2_pre->Integral();
	  INIT42 = RMSZZ3_pre->Integral();
	  INIT43 = RMSWW1_pre->Integral();
      INIT44 = RMSWW2_pre->Integral();
      INIT45 = RMSWZ1_pre->Integral();
	  INIT46 = RMSWZ2_pre->Integral();
	  INIT47 = RMSWZ3_pre->Integral();
	  
    } else {
      RMS0700->Fill((INIT1 -RMS0700_pre->Integral())/INIT1 );
      RMS0800->Fill((INIT2 -RMS0800_pre->Integral())/INIT2 );
      RMS0900->Fill((INIT3 -RMS0900_pre->Integral())/INIT3 );
      RMS1000->Fill((INIT4 -RMS1000_pre->Integral())/INIT4 );
      RMS1100->Fill((INIT5 -RMS1100_pre->Integral())/INIT5 );
      RMS1200->Fill((INIT6 -RMS1200_pre->Integral())/INIT6 );
      RMS1300->Fill((INIT7 -RMS1300_pre->Integral())/INIT7 );
      RMS1400->Fill((INIT8 -RMS1400_pre->Integral())/INIT8 );
      RMS1500->Fill((INIT9 -RMS1500_pre->Integral())/INIT9 );
      RMS1600->Fill((INIT10-RMS1600_pre->Integral())/INIT10);
      RMS1700->Fill((INIT11-RMS1700_pre->Integral())/INIT11); 
	  RMS1800->Fill((INIT12-RMS1800_pre->Integral())/INIT12); 

	  RMSZToNuNu->Fill((INIT13-RMSZToNuNu_1_pre->Integral())/INIT13);
	  RMSZToNuNu->Fill((INIT14-RMSZToNuNu_2_pre->Integral())/INIT14);
	  RMSZToNuNu->Fill((INIT15-RMSZToNuNu_3_pre->Integral())/INIT15);
	  RMSZToNuNu->Fill((INIT16-RMSZToNuNu_4_pre->Integral())/INIT16);
	  RMSZToNuNu->Fill((INIT17-RMSZToNuNu_5_pre->Integral())/INIT17);
	  RMSZToNuNu->Fill((INIT18-RMSZToNuNu_6_pre->Integral())/INIT18);
	  RMSZToNuNu->Fill((INIT19-RMSZToNuNu_7_pre->Integral())/INIT19);

	  RMSQCD->Fill((INIT20-RMSQCD_1_pre->Integral())/INIT20);
	  RMSQCD->Fill((INIT21-RMSQCD_2_pre->Integral())/INIT21);
	  RMSQCD->Fill((INIT22-RMSQCD_3_pre->Integral())/INIT22);
	  RMSQCD->Fill((INIT23-RMSQCD_4_pre->Integral())/INIT23);
	  RMSQCD->Fill((INIT24-RMSQCD_5_pre->Integral())/INIT24);
	  RMSQCD->Fill((INIT25-RMSQCD_6_pre->Integral())/INIT25);
	  RMSQCD->Fill((INIT26-RMSQCD_7_pre->Integral())/INIT26);

	  RMSWToLNu->Fill((INIT27-RMSWToLNu_1_pre->Integral())/INIT27);
	  RMSWToLNu->Fill((INIT28-RMSWToLNu_2_pre->Integral())/INIT28);
	  RMSWToLNu->Fill((INIT29-RMSWToLNu_3_pre->Integral())/INIT29);
	  RMSWToLNu->Fill((INIT30-RMSWToLNu_4_pre->Integral())/INIT30);
	  RMSWToLNu->Fill((INIT31-RMSWToLNu_5_pre->Integral())/INIT31);
	  RMSWToLNu->Fill((INIT32-RMSWToLNu_6_pre->Integral())/INIT32);
	  RMSWToLNu->Fill((INIT33-RMSWToLNu_7_pre->Integral())/INIT33);

	  RMSTT->Fill((INIT34-RMSTT_1_pre->Integral())/INIT34);
	  RMSTT->Fill((INIT35-RMSTT_2_pre->Integral())/INIT35);

	  RMSST->Fill((INIT36-RMSST_1_pre->Integral())/INIT36);
	  RMSST->Fill((INIT37-RMSST_2_pre->Integral())/INIT37);
	  RMSST->Fill((INIT38-RMSST_3_pre->Integral())/INIT38);
	  RMSST->Fill((INIT39-RMSST_4_pre->Integral())/INIT39);

	  RMSVV->Fill((INIT40 - RMSZZ1_pre->Integral())/INIT40);
	  RMSVV->Fill((INIT41 - RMSZZ2_pre->Integral())/INIT41);
	  RMSVV->Fill((INIT42 - RMSZZ3_pre->Integral())/INIT42);
	  RMSVV->Fill((INIT43 - RMSWW1_pre->Integral())/INIT43);
      RMSVV->Fill((INIT44 - RMSWW2_pre->Integral())/INIT44);
      RMSVV->Fill((INIT45 - RMSWZ1_pre->Integral())/INIT45);
	  RMSVV->Fill((INIT46 - RMSWZ2_pre->Integral())/INIT46);
	  RMSVV->Fill((INIT47 - RMSWZ3_pre->Integral())/INIT47);

    }

  }
  
  tptzm0700lh_func1->SetBinContent(j,tptzm0700lh->GetBinContent(j)*(1 + RMS0700->GetRMS()));
  tptzm0800lh_func1->SetBinContent(j,tptzm0800lh->GetBinContent(j)*(1 + RMS0800->GetRMS()));
  tptzm0900lh_func1->SetBinContent(j,tptzm0900lh->GetBinContent(j)*(1 + RMS0900->GetRMS()));
  tptzm1000lh_func1->SetBinContent(j,tptzm1000lh->GetBinContent(j)*(1 + RMS1000->GetRMS()));
  tptzm1100lh_func1->SetBinContent(j,tptzm1100lh->GetBinContent(j)*(1 + RMS1100->GetRMS()));
  tptzm1200lh_func1->SetBinContent(j,tptzm1200lh->GetBinContent(j)*(1 + RMS1200->GetRMS()));
  tptzm1300lh_func1->SetBinContent(j,tptzm1300lh->GetBinContent(j)*(1 + RMS1300->GetRMS()));
  tptzm1400lh_func1->SetBinContent(j,tptzm1400lh->GetBinContent(j)*(1 + RMS1400->GetRMS()));
  tptzm1500lh_func1->SetBinContent(j,tptzm1500lh->GetBinContent(j)*(1 + RMS1500->GetRMS()));
  tptzm1600lh_func1->SetBinContent(j,tptzm1600lh->GetBinContent(j)*(1 + RMS1600->GetRMS()));
  tptzm1700lh_func1->SetBinContent(j,tptzm1700lh->GetBinContent(j)*(1 + RMS1700->GetRMS()));
  ZToNuNu_func1->SetBinContent(j,ZToNuNu->GetBinContent(j)*(1+ RMSZToNuNu->GetRMS()));
  QCD_func1->SetBinContent(j,QCD->GetBinContent(j)*(1 + RMSQCD->GetRMS()));
  WToLNu_func1->SetBinContent(j,WToLNu->GetBinContent(j)*(1 + RMSWToLNu->GetRMS()));
  TT_func1->SetBinContent(j,TT->GetBinContent(j)*(1 + RMSTT->GetRMS()));
  ST_func1->SetBinContent(j,ST->GetBinContent(j)*(1 + RMSST->GetRMS()));
  VV_func1->SetBinContent(j,VV->GetBinContent(j)*(1 + RMSVV->GetRMS()));

  tptzm0700lh_func2->SetBinContent(j,TMath::Max(0., tptzm0700lh->GetBinContent(j)*(1 - RMS0700->GetRMS())));
  tptzm0800lh_func2->SetBinContent(j,TMath::Max(0., tptzm0800lh->GetBinContent(j)*(1 - RMS0800->GetRMS())));
  tptzm0900lh_func2->SetBinContent(j,TMath::Max(0., tptzm0900lh->GetBinContent(j)*(1 - RMS0900->GetRMS())));
  tptzm1000lh_func2->SetBinContent(j,TMath::Max(0., tptzm1000lh->GetBinContent(j)*(1 - RMS1000->GetRMS())));
  tptzm1100lh_func2->SetBinContent(j,TMath::Max(0., tptzm1100lh->GetBinContent(j)*(1 - RMS1100->GetRMS())));
  tptzm1200lh_func2->SetBinContent(j,TMath::Max(0., tptzm1200lh->GetBinContent(j)*(1 - RMS1200->GetRMS())));
  tptzm1300lh_func2->SetBinContent(j,TMath::Max(0., tptzm1300lh->GetBinContent(j)*(1 - RMS1300->GetRMS())));
  tptzm1400lh_func2->SetBinContent(j,TMath::Max(0., tptzm1400lh->GetBinContent(j)*(1 - RMS1400->GetRMS())));
  tptzm1500lh_func2->SetBinContent(j,TMath::Max(0., tptzm1500lh->GetBinContent(j)*(1 - RMS1500->GetRMS())));
  tptzm1600lh_func2->SetBinContent(j,TMath::Max(0., tptzm1600lh->GetBinContent(j)*(1 - RMS1600->GetRMS())));
  tptzm1700lh_func2->SetBinContent(j,TMath::Max(0., tptzm1700lh->GetBinContent(j)*(1 - RMS1700->GetRMS())));

  ZToNuNu_func2->SetBinContent(j,TMath::Max(0.,ZToNuNu->GetBinContent(j)*(1 - RMSZToNuNu->GetRMS())));
  QCD_func2->SetBinContent(j,TMath::Max(0.,QCD->GetBinContent(j)*(1 - RMSQCD->GetRMS())));
  WToLNu_func2->SetBinContent(j,TMath::Max(0.,WToLNu->GetBinContent(j)*(1 - RMSWToLNu->GetRMS())));
  TT_func2->SetBinContent(j,TMath::Max(0.,TT->GetBinContent(j)*(1 - RMSTT->GetRMS())));
  ST_func2->SetBinContent(j,TMath::Max(0.,ST->GetBinContent(j)*(1 - RMSST->GetRMS())));
  VV_func2->SetBinContent(j,TMath::Max(0.,VV->GetBinContent(j)*(1 - RMSVV->GetRMS())));

  }

  TCanvas* c2 = new TCanvas("c1","c1",0,0,600,600);
  RMSTT->Draw();
  c2->SaveAs("RMSTT.png");
  cout<<"this step is ok"<<endl;
  delete RMS0700; delete RMS0800; delete RMS0900; delete RMS1000; delete RMS1100; delete RMS1200; delete RMS1300; delete RMS1400; delete RMS1500; delete RMS1600; delete RMS1700;  delete RMS1800;
  delete RMSZToNuNu_1; delete RMSZToNuNu_2; delete RMSZToNuNu_3; delete RMSZToNuNu_4; delete RMSZToNuNu_5; delete RMSZToNuNu_6; delete RMSZToNuNu_7; delete RMSZToNuNu;
  delete RMSQCD_1; delete RMSQCD_2; delete RMSQCD_3; delete RMSQCD_4; delete RMSQCD_5; delete RMSQCD_6; delete RMSQCD_7; delete RMSQCD;
  delete RMSWToLNu_1; delete RMSWToLNu_2; delete RMSWToLNu_3; delete RMSWToLNu_4; delete RMSWToLNu_5; delete RMSWToLNu_6; delete RMSWToLNu_7; delete RMSWToLNu;
  delete RMSTT_1; delete RMSTT_2; delete RMSTT; 
  delete RMSST_1; delete RMSST_2; delete RMSST_3; delete RMSST_4; delete RMSST; 
  delete RMSZZ1; delete RMSZZ2; delete RMSZZ3; delete RMSWZ1; delete RMSWZ2; delete RMSWZ3; delete RMSWW1; delete RMSWW2;  delete RMSVV; 

  delete RMS0700_pre; delete RMS0800_pre; delete RMS0900_pre; delete RMS1000_pre; delete RMS1100_pre; delete RMS1200_pre; delete RMS1300_pre; delete RMS1400_pre; delete RMS1500_pre; delete RMS1600_pre; delete RMS1700_pre; delete RMS1800_pre;
  delete RMSZToNuNu_1_pre; delete RMSZToNuNu_2_pre; delete RMSZToNuNu_3_pre; delete RMSZToNuNu_4_pre; delete RMSZToNuNu_5_pre; delete RMSZToNuNu_6_pre; delete RMSZToNuNu_7_pre;
  delete RMSQCD_1_pre; delete RMSQCD_2_pre; delete RMSQCD_3_pre; delete RMSQCD_4_pre; delete RMSQCD_5_pre; delete RMSQCD_6_pre; delete RMSQCD_7_pre;
  delete RMSWToLNu_1_pre; delete RMSWToLNu_2_pre; delete RMSWToLNu_3_pre; delete RMSWToLNu_4_pre; delete RMSWToLNu_5_pre; delete RMSWToLNu_6_pre; delete RMSWToLNu_7_pre;
  delete RMSTT_1_pre; delete RMSTT_2_pre; 
  delete RMSST_1_pre; delete RMSST_2_pre; delete RMSST_3_pre; delete RMSST_4_pre;
  delete RMSZZ1_pre; delete RMSZZ2_pre; delete RMSZZ3_pre; delete RMSWZ1_pre; delete RMSWZ2_pre; delete RMSWZ3_pre; delete RMSWW1_pre; delete RMSWW2_pre; 
 
}
