#include "BackgroundEstimation_dineutrino_2016.h"
#include "SaveRootFileForLimit_dineutrino_2016.h"

void BackgroundEstimation_dineutrino_2016(){ 
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

  bool SYST = true;
  bool save = false;

    //CUT VALUES
  //int category=0;
  double dPMet=0.6;            //0.6
  int    BTag = 1;              //1
  double TopPt=250.;           //
  double ht = 200;          //300
  double dPTop = 0;
  double Met = 200;
  double Mht = 200 ;

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
  name.push_back("TransverseMassMetTop");      bin.push_back(30);     Min.push_back(500);     Max.push_back(2000);     axis.push_back("TransverseMassMetTop");

   //name.push_back("HT"); bin.push_back(18);     Min.push_back(200);    Max.push_back(2000);    axis.push_back("HT pt[GeV]");

  for (int i=0; i<name.size(); i++){
    const char *plot = name[i];
    for(int category=0; category<2; category++){

    char CUT[1000]; char CUTpup1[1000]; char CUTpup2[1000]; char CUTbta1[1000]; char CUTbta2[1000];  char CUTfir1[1000]; char CUTfir2[1000]; char CUTwje1[1000]; char CUTwje2[1000];
	char CUTSR[1000]; char CUTzje1[1000];  char CUTzje2[1000];  char CUTttb1[1000];  char CUTttb2[1000];char CUTqcd1[1000]; char CUTqcd2[1000];char CUTpdf1[1000]; char CUTpdf2[1000];  char CUTtri1[1000];  char CUTtri2[1000]; char CUTzbe1[1000]; char CUTzbe2[1000]; char CUTwbe1[1000]; char CUTwbe2[1000]; char CUTtbe1[1000]; char CUTtbe2[1000];
	
        if(category==0) sprintf(CUT,    "((category0==1)&&(Jet1ResolvedPt>0)&&(Jet2ResolvedPt>0)&&(Jet3ResolvedPt>0)&&(MinDeltaPhiJetMet>%f)&&(TransverseMassMetTop>500)&&(NumSelLeps==0)&&(MostForwardJetEta>-4&&MostForwardJetEta<4)&&(NumSelBJetsM>=%i)&&(TopPt>%f)&&(deltaPhiMetTop>%f)&&(NumSelForwardJets==0)&&(HT>%f)&&(Met_pt>%f)&&(MHT>%f))",dPMet, BTag, TopPt, dPTop, ht, Met, Mht);
	if(category==1) sprintf(CUT,    "((category0==1)&&(Jet1ResolvedPt>0)&&(Jet2ResolvedPt>0)&&(Jet3ResolvedPt>0)&&(MinDeltaPhiJetMet>%f)&&(TransverseMassMetTop>500)&&(NumSelLeps==0)&&(MostForwardJetEta>-4&&MostForwardJetEta<4)&&(NumSelBJetsM>=%i)&&(TopPt>%f)&&(deltaPhiMetTop>%f)&&(NumSelForwardJets>0)&&(HT>%f)&&(Met_pt>%f)&&(MHT>%f))", dPMet, BTag, TopPt, dPTop, ht, Met, Mht);

	sprintf(CUTSR,   "PUWeight    *w_Btag    *genWeight   *prefiringweight    *w_Trig    *w_ZToNuNu    *w_WToLNu    *w_ttbar*%s",CUT );
	sprintf(CUTpup1, "PUWeightUP  *w_Btag    *genWeight   *prefiringweight    *w_Trig    *w_ZToNuNu    *w_WToLNu    *w_ttbar*%s",CUT );
	sprintf(CUTpup2, "PUWeightDOWN*w_Btag    *genWeight   *prefiringweight    *w_Trig    *w_ZToNuNu    *w_WToLNu    *w_ttbar*%s",CUT );
	sprintf(CUTfir1, "PUWeight    *w_Btag    *genWeight   *prefiringweightup  *w_Trig    *w_ZToNuNu    *w_WToLNu    *w_ttbar*%s",CUT );
	sprintf(CUTfir2, "PUWeight    *w_Btag    *genWeight   *prefiringweightdown*w_Trig    *w_ZToNuNu    *w_WToLNu    *w_ttbar*%s",CUT );
	sprintf(CUTbta1, "PUWeight    *w_BtagUp  *genWeight   *prefiringweight    *w_Trig    *w_ZToNuNu    *w_WToLNu    *w_ttbar*%s",CUT );
	sprintf(CUTbta2, "PUWeight    *w_BtagDown*genWeight   *prefiringweight    *w_Trig    *w_ZToNuNu    *w_WToLNu    *w_ttbar*%s",CUT );
	sprintf(CUTzje1, "PUWeight    *w_Btag    *genWeight   *prefiringweight    *w_Trig    *w_ZToNuNuUp  *w_WToLNu    *w_ttbar*%s",CUT );
	sprintf(CUTzje2, "PUWeight    *w_Btag    *genWeight   *prefiringweight    *w_Trig    *w_ZToNuNuDown*w_WToLNu    *w_ttbar*%s",CUT );
	sprintf(CUTzbe1, "PUWeight    *w_Btag    *genWeight   *prefiringweight    *w_Trig    *w_ZToNuNu_BtagUp    *w_WToLNu    *w_ttbar*%s",CUT );
	sprintf(CUTzbe2, "PUWeight    *w_Btag    *genWeight   *prefiringweight    *w_Trig    *w_ZToNuNu_BtagDown  *w_WToLNu    *w_ttbar*%s",CUT );
  sprintf(CUTwje1, "PUWeight    *w_Btag    *genWeight   *prefiringweight    *w_Trig    *w_ZToNuNu    *w_WToLNuUp  *w_ttbar*%s",CUT );
	sprintf(CUTwje2, "PUWeight    *w_Btag    *genWeight   *prefiringweight    *w_Trig    *w_ZToNuNu    *w_WToLNuDown*w_ttbar*%s",CUT );
  sprintf(CUTwbe1, "PUWeight    *w_Btag    *genWeight   *prefiringweight    *w_Trig    *w_ZToNuNu    *w_WToLNu_BtagUp    *w_ttbar*%s",CUT );
	sprintf(CUTwbe2, "PUWeight    *w_Btag    *genWeight   *prefiringweight    *w_Trig    *w_ZToNuNu    *w_WToLNu_BtagDown  *w_ttbar*%s",CUT );
	sprintf(CUTttb1, "PUWeight    *w_Btag    *genWeight   *prefiringweight    *w_Trig    *w_ZToNuNu    *w_WToLNu    *w_ttbarUp*%s" ,CUT );
	sprintf(CUTttb2, "PUWeight    *w_Btag    *genWeight   *prefiringweight    *w_Trig    *w_ZToNuNu    *w_WToLNu    *w_ttbarDown*%s",CUT);
	sprintf(CUTtbe1, "PUWeight    *w_Btag    *genWeight   *prefiringweight    *w_Trig    *w_ZToNuNu    *w_WToLNu    *w_ttbar_BtagUp*%s" ,CUT );
	sprintf(CUTtbe2, "PUWeight    *w_Btag    *genWeight   *prefiringweight    *w_Trig    *w_ZToNuNu    *w_WToLNu    *w_ttbar_BtagDown*%s",CUT);
	sprintf(CUTqcd1, "PUWeight    *w_Btag    *genWeight   *prefiringweight    *w_Trig    *w_ZToNuNu    *w_WToLNu    *w_ttbar*w_QCDUp*%s",CUT );
	sprintf(CUTqcd2, "PUWeight    *w_Btag    *genWeight   *prefiringweight    *w_Trig    *w_ZToNuNu    *w_WToLNu    *w_ttbar*w_QCDDown*%s",CUT );
	sprintf(CUTpdf1, "PUWeight    *w_Btag    *genWeight   *prefiringweight    *w_Trig    *w_ZToNuNu    *w_WToLNu    *w_ttbar*w_PDFUp*%s",CUT );
	sprintf(CUTpdf2, "PUWeight    *w_Btag    *genWeight   *prefiringweight    *w_Trig    *w_ZToNuNu    *w_WToLNu    *w_ttbar*w_PDFDown*%s",CUT );
        sprintf(CUTtri1, "PUWeight    *w_Btag    *genWeight   *prefiringweight    *w_TrigUp  *w_ZToNuNu    *w_WToLNu    *w_ttbar   *%s",CUT);
        sprintf(CUTtri2, "PUWeight    *w_Btag    *genWeight   *prefiringweight    *w_TrigDown*w_ZToNuNu    *w_WToLNu    *w_ttbar   *%s",CUT);

	MakeHistos(CUTSR,   plot,bin[i],Min[i],Max[i],0,
		       data,background, 
			   ZToNuNu,QCD,WToLNu,TT,ST,VV,ttV,
			   tptzm0600lh,tptzm0700lh,tptzm0800lh,tptzm0900lh,tptzm1000lh,tptzm1100lh,tptzm1200lh,tptzm1300lh,tptzm1400lh,tptzm1500lh,tptzm1600lh,tptzm1700lh,tptzm1800lh,
                           tptzm0700lh_10p,tptzm0800lh_10p,tptzm0800lh_20p,tptzm0800lh_30p,tptzm0900lh_10p,tptzm1000lh_10p,tptzm1000lh_20p,tptzm1000lh_30p,tptzm1100lh_10p,tptzm1200lh_10p,tptzm1200lh_20p,tptzm1200lh_30p,tptzm1300lh_10p,tptzm1400lh_10p,tptzm1400lh_20p,tptzm1400lh_30p,tptzm1500lh_10p,tptzm1600lh_10p,tptzm1600lh_20p,tptzm1600lh_30p,tptzm1700lh_10p);

	if(SYST){
	MakeHistos(CUTpup1, plot,bin[i],Min[i],Max[i],0,
		       data_pup1,background_pup1, 
			   ZToNuNu_pup1,QCD_pup1,WToLNu_pup1,TT_pup1,ST_pup1,VV_pup1,ttV_pup1,
			   tptzm0600lh_pup1,tptzm0700lh_pup1,tptzm0800lh_pup1,tptzm0900lh_pup1,tptzm1000lh_pup1,tptzm1100lh_pup1,tptzm1200lh_pup1,tptzm1300lh_pup1,tptzm1400lh_pup1,tptzm1500lh_pup1,tptzm1600lh_pup1,tptzm1700lh_pup1,tptzm1800lh_pup1,
                           tptzm0700lh_10p_pup1,tptzm0800lh_10p_pup1,tptzm0800lh_20p_pup1,tptzm0800lh_30p_pup1,tptzm0900lh_10p_pup1,tptzm1000lh_10p_pup1,tptzm1000lh_20p_pup1,tptzm1000lh_30p_pup1,tptzm1100lh_10p_pup1,tptzm1200lh_10p_pup1,tptzm1200lh_20p_pup1,tptzm1200lh_30p_pup1,tptzm1300lh_10p_pup1,tptzm1400lh_10p_pup1,tptzm1400lh_20p_pup1,tptzm1400lh_30p_pup1,tptzm1500lh_10p_pup1,tptzm1600lh_10p_pup1,tptzm1600lh_20p_pup1,tptzm1600lh_30p_pup1,tptzm1700lh_10p_pup1);

	MakeHistos(CUTpup2, plot,bin[i],Min[i],Max[i],0,
		       data_pup2,background_pup2, 
			   ZToNuNu_pup2,QCD_pup2,WToLNu_pup2,TT_pup2,ST_pup2,VV_pup2,ttV_pup2,
			   tptzm0600lh_pup2,tptzm0700lh_pup2,tptzm0800lh_pup2,tptzm0900lh_pup2,tptzm1000lh_pup2,tptzm1100lh_pup2,tptzm1200lh_pup2,tptzm1300lh_pup2,tptzm1400lh_pup2,tptzm1500lh_pup2,tptzm1600lh_pup2,tptzm1700lh_pup2,tptzm1800lh_pup2,
                           tptzm0700lh_10p_pup2,tptzm0800lh_10p_pup2,tptzm0800lh_20p_pup2,tptzm0800lh_30p_pup2,tptzm0900lh_10p_pup2,tptzm1000lh_10p_pup2,tptzm1000lh_20p_pup2,tptzm1000lh_30p_pup2,tptzm1100lh_10p_pup2,tptzm1200lh_10p_pup2,tptzm1200lh_20p_pup2,tptzm1200lh_30p_pup2,tptzm1300lh_10p_pup2,tptzm1400lh_10p_pup2,tptzm1400lh_20p_pup2,tptzm1400lh_30p_pup2,tptzm1500lh_10p_pup2,tptzm1600lh_10p_pup2,tptzm1600lh_20p_pup2,tptzm1600lh_30p_pup2,tptzm1700lh_10p_pup2);
    
	MakeHistos(CUTfir1, plot,bin[i],Min[i],Max[i],0,
		       data_fir1,background_fir1, 
			   ZToNuNu_fir1,QCD_fir1,WToLNu_fir1,TT_fir1,ST_fir1,VV_fir1,ttV_fir1,
			   tptzm0600lh_fir1,tptzm0700lh_fir1,tptzm0800lh_fir1,tptzm0900lh_fir1,tptzm1000lh_fir1,tptzm1100lh_fir1,tptzm1200lh_fir1,tptzm1300lh_fir1,tptzm1400lh_fir1,tptzm1500lh_fir1,tptzm1600lh_fir1,tptzm1700lh_fir1,tptzm1800lh_fir1,
                           tptzm0700lh_10p_fir1,tptzm0800lh_10p_fir1,tptzm0800lh_20p_fir1,tptzm0800lh_30p_fir1,tptzm0900lh_10p_fir1,tptzm1000lh_10p_fir1,tptzm1000lh_20p_fir1,tptzm1000lh_30p_fir1,tptzm1100lh_10p_fir1,tptzm1200lh_10p_fir1,tptzm1200lh_20p_fir1,tptzm1200lh_30p_fir1,tptzm1300lh_10p_fir1,tptzm1400lh_10p_fir1,tptzm1400lh_20p_fir1,tptzm1400lh_30p_fir1,tptzm1500lh_10p_fir1,tptzm1600lh_10p_fir1,tptzm1600lh_20p_fir1,tptzm1600lh_30p_fir1,tptzm1700lh_10p_fir1);

	MakeHistos(CUTfir2, plot,bin[i],Min[i],Max[i],0,
		       data_fir2,background_fir2, 
			   ZToNuNu_fir2,QCD_fir2,WToLNu_fir2,TT_fir2,ST_fir2,VV_fir2,ttV_fir2,
			   tptzm0600lh_fir2,tptzm0700lh_fir2,tptzm0800lh_fir2,tptzm0900lh_fir2,tptzm1000lh_fir2,tptzm1100lh_fir2,tptzm1200lh_fir2,tptzm1300lh_fir2,tptzm1400lh_fir2,tptzm1500lh_fir2,tptzm1600lh_fir2,tptzm1700lh_fir2,tptzm1800lh_fir2,
                           tptzm0700lh_10p_fir2,tptzm0800lh_10p_fir2,tptzm0800lh_20p_fir2,tptzm0800lh_30p_fir2,tptzm0900lh_10p_fir2,tptzm1000lh_10p_fir2,tptzm1000lh_20p_fir2,tptzm1000lh_30p_fir2,tptzm1100lh_10p_fir2,tptzm1200lh_10p_fir2,tptzm1200lh_20p_fir2,tptzm1200lh_30p_fir2,tptzm1300lh_10p_fir2,tptzm1400lh_10p_fir2,tptzm1400lh_20p_fir2,tptzm1400lh_30p_fir2,tptzm1500lh_10p_fir2,tptzm1600lh_10p_fir2,tptzm1600lh_20p_fir2,tptzm1600lh_30p_fir2,tptzm1700lh_10p_fir2);
    
	MakeHistos(CUTbta1, plot,bin[i],Min[i],Max[i],0,
		       data_bta1,background_bta1, 
			   ZToNuNu_bta1,QCD_bta1,WToLNu_bta1,TT_bta1,ST_bta1,VV_bta1,ttV_bta1,
			   tptzm0600lh_bta1,tptzm0700lh_bta1,tptzm0800lh_bta1,tptzm0900lh_bta1,tptzm1000lh_bta1,tptzm1100lh_bta1,tptzm1200lh_bta1,tptzm1300lh_bta1,tptzm1400lh_bta1,tptzm1500lh_bta1,tptzm1600lh_bta1,tptzm1700lh_bta1,tptzm1800lh_bta1,
                           tptzm0700lh_10p_bta1,tptzm0800lh_10p_bta1,tptzm0800lh_20p_bta1,tptzm0800lh_30p_bta1,tptzm0900lh_10p_bta1,tptzm1000lh_10p_bta1,tptzm1000lh_20p_bta1,tptzm1000lh_30p_bta1,tptzm1100lh_10p_bta1,tptzm1200lh_10p_bta1,tptzm1200lh_20p_bta1,tptzm1200lh_30p_bta1,tptzm1300lh_10p_bta1,tptzm1400lh_10p_bta1,tptzm1400lh_20p_bta1,tptzm1400lh_30p_bta1,tptzm1500lh_10p_bta1,tptzm1600lh_10p_bta1,tptzm1600lh_20p_bta1,tptzm1600lh_30p_bta1,tptzm1700lh_10p_bta1);

	MakeHistos(CUTbta2, plot,bin[i],Min[i],Max[i],0,
		       data_bta2,background_bta2, 
			   ZToNuNu_bta2,QCD_bta2,WToLNu_bta2,TT_bta2,ST_bta2,VV_bta2,ttV_bta2,
			   tptzm0600lh_bta2,tptzm0700lh_bta2,tptzm0800lh_bta2,tptzm0900lh_bta2,tptzm1000lh_bta2,tptzm1100lh_bta2,tptzm1200lh_bta2,tptzm1300lh_bta2,tptzm1400lh_bta2,tptzm1500lh_bta2,tptzm1600lh_bta2,tptzm1700lh_bta2,tptzm1800lh_bta2,
                           tptzm0700lh_10p_bta2,tptzm0800lh_10p_bta2,tptzm0800lh_20p_bta2,tptzm0800lh_30p_bta2,tptzm0900lh_10p_bta2,tptzm1000lh_10p_bta2,tptzm1000lh_20p_bta2,tptzm1000lh_30p_bta2,tptzm1100lh_10p_bta2,tptzm1200lh_10p_bta2,tptzm1200lh_20p_bta2,tptzm1200lh_30p_bta2,tptzm1300lh_10p_bta2,tptzm1400lh_10p_bta2,tptzm1400lh_20p_bta2,tptzm1400lh_30p_bta2,tptzm1500lh_10p_bta2,tptzm1600lh_10p_bta2,tptzm1600lh_20p_bta2,tptzm1600lh_30p_bta2,tptzm1700lh_10p_bta2);

	MakeHistos(CUTzje1, plot,bin[i],Min[i],Max[i],0,
		       data_zje1,background_zje1, 
			   ZToNuNu_zje1,QCD_zje1,WToLNu_zje1,TT_zje1,ST_zje1,VV_zje1,ttV_zje1,
			   tptzm0600lh_zje1,tptzm0700lh_zje1,tptzm0800lh_zje1,tptzm0900lh_zje1,tptzm1000lh_zje1,tptzm1100lh_zje1,tptzm1200lh_zje1,tptzm1300lh_zje1,tptzm1400lh_zje1,tptzm1500lh_zje1,tptzm1600lh_zje1,tptzm1700lh_zje1,tptzm1800lh_zje1,
                           tptzm0700lh_10p_zje1,tptzm0800lh_10p_zje1,tptzm0800lh_20p_zje1,tptzm0800lh_30p_zje1,tptzm0900lh_10p_zje1,tptzm1000lh_10p_zje1,tptzm1000lh_20p_zje1,tptzm1000lh_30p_zje1,tptzm1100lh_10p_zje1,tptzm1200lh_10p_zje1,tptzm1200lh_20p_zje1,tptzm1200lh_30p_zje1,tptzm1300lh_10p_zje1,tptzm1400lh_10p_zje1,tptzm1400lh_20p_zje1,tptzm1400lh_30p_zje1,tptzm1500lh_10p_zje1,tptzm1600lh_10p_zje1,tptzm1600lh_20p_zje1,tptzm1600lh_30p_zje1,tptzm1700lh_10p_zje1);

	MakeHistos(CUTzje2, plot,bin[i],Min[i],Max[i],0,
		       data_zje2,background_zje2, 
			   ZToNuNu_zje2,QCD_zje2,WToLNu_zje2,TT_zje2,ST_zje2,VV_zje2,ttV_zje2,
			   tptzm0600lh_zje2,tptzm0700lh_zje2,tptzm0800lh_zje2,tptzm0900lh_zje2,tptzm1000lh_zje2,tptzm1100lh_zje2,tptzm1200lh_zje2,tptzm1300lh_zje2,tptzm1400lh_zje2,tptzm1500lh_zje2,tptzm1600lh_zje2,tptzm1700lh_zje2,tptzm1800lh_zje2,
                           tptzm0700lh_10p_zje2,tptzm0800lh_10p_zje2,tptzm0800lh_20p_zje2,tptzm0800lh_30p_zje2,tptzm0900lh_10p_zje2,tptzm1000lh_10p_zje2,tptzm1000lh_20p_zje2,tptzm1000lh_30p_zje2,tptzm1100lh_10p_zje2,tptzm1200lh_10p_zje2,tptzm1200lh_20p_zje2,tptzm1200lh_30p_zje2,tptzm1300lh_10p_zje2,tptzm1400lh_10p_zje2,tptzm1400lh_20p_zje2,tptzm1400lh_30p_zje2,tptzm1500lh_10p_zje2,tptzm1600lh_10p_zje2,tptzm1600lh_20p_zje2,tptzm1600lh_30p_zje2,tptzm1700lh_10p_zje2);

	MakeHistos(CUTzbe1, plot,bin[i],Min[i],Max[i],0,
		       data_zbe1,background_zbe1, 
			   ZToNuNu_zbe1,QCD_zbe1,WToLNu_zbe1,TT_zbe1,ST_zbe1,VV_zbe1,ttV_zbe1,
			   tptzm0600lh_zbe1,tptzm0700lh_zbe1,tptzm0800lh_zbe1,tptzm0900lh_zbe1,tptzm1000lh_zbe1,tptzm1100lh_zbe1,tptzm1200lh_zbe1,tptzm1300lh_zbe1,tptzm1400lh_zbe1,tptzm1500lh_zbe1,tptzm1600lh_zbe1,tptzm1700lh_zbe1,tptzm1800lh_zbe1,
                           tptzm0700lh_10p_zbe1,tptzm0800lh_10p_zbe1,tptzm0800lh_20p_zbe1,tptzm0800lh_30p_zbe1,tptzm0900lh_10p_zbe1,tptzm1000lh_10p_zbe1,tptzm1000lh_20p_zbe1,tptzm1000lh_30p_zbe1,tptzm1100lh_10p_zbe1,tptzm1200lh_10p_zbe1,tptzm1200lh_20p_zbe1,tptzm1200lh_30p_zbe1,tptzm1300lh_10p_zbe1,tptzm1400lh_10p_zbe1,tptzm1400lh_20p_zbe1,tptzm1400lh_30p_zbe1,tptzm1500lh_10p_zbe1,tptzm1600lh_10p_zbe1,tptzm1600lh_20p_zbe1,tptzm1600lh_30p_zbe1,tptzm1700lh_10p_zbe1);

	MakeHistos(CUTzbe2, plot,bin[i],Min[i],Max[i],0,
		       data_zbe2,background_zbe2, 
			   ZToNuNu_zbe2,QCD_zbe2,WToLNu_zbe2,TT_zbe2,ST_zbe2,VV_zbe2,ttV_zbe2,
			   tptzm0600lh_zbe2,tptzm0700lh_zbe2,tptzm0800lh_zbe2,tptzm0900lh_zbe2,tptzm1000lh_zbe2,tptzm1100lh_zbe2,tptzm1200lh_zbe2,tptzm1300lh_zbe2,tptzm1400lh_zbe2,tptzm1500lh_zbe2,tptzm1600lh_zbe2,tptzm1700lh_zbe2,tptzm1800lh_zbe2,
                           tptzm0700lh_10p_zbe2,tptzm0800lh_10p_zbe2,tptzm0800lh_20p_zbe2,tptzm0800lh_30p_zbe2,tptzm0900lh_10p_zbe2,tptzm1000lh_10p_zbe2,tptzm1000lh_20p_zbe2,tptzm1000lh_30p_zbe2,tptzm1100lh_10p_zbe2,tptzm1200lh_10p_zbe2,tptzm1200lh_20p_zbe2,tptzm1200lh_30p_zbe2,tptzm1300lh_10p_zbe2,tptzm1400lh_10p_zbe2,tptzm1400lh_20p_zbe2,tptzm1400lh_30p_zbe2,tptzm1500lh_10p_zbe2,tptzm1600lh_10p_zbe2,tptzm1600lh_20p_zbe2,tptzm1600lh_30p_zbe2,tptzm1700lh_10p_zbe2);

	MakeHistos(CUTwje1, plot,bin[i],Min[i],Max[i],0,
		       data_wje1,background_wje1, 
			   ZToNuNu_wje1,QCD_wje1,WToLNu_wje1,TT_wje1,ST_wje1,VV_wje1,ttV_wje1,
			   tptzm0600lh_wje1,tptzm0700lh_wje1,tptzm0800lh_wje1,tptzm0900lh_wje1,tptzm1000lh_wje1,tptzm1100lh_wje1,tptzm1200lh_wje1,tptzm1300lh_wje1,tptzm1400lh_wje1,tptzm1500lh_wje1,tptzm1600lh_wje1,tptzm1700lh_wje1,tptzm1800lh_wje1,
                           tptzm0700lh_10p_wje1,tptzm0800lh_10p_wje1,tptzm0800lh_20p_wje1,tptzm0800lh_30p_wje1,tptzm0900lh_10p_wje1,tptzm1000lh_10p_wje1,tptzm1000lh_20p_wje1,tptzm1000lh_30p_wje1,tptzm1100lh_10p_wje1,tptzm1200lh_10p_wje1,tptzm1200lh_20p_wje1,tptzm1200lh_30p_wje1,tptzm1300lh_10p_wje1,tptzm1400lh_10p_wje1,tptzm1400lh_20p_wje1,tptzm1400lh_30p_wje1,tptzm1500lh_10p_wje1,tptzm1600lh_10p_wje1,tptzm1600lh_20p_wje1,tptzm1600lh_30p_wje1,tptzm1700lh_10p_wje1);

	MakeHistos(CUTwje2, plot,bin[i],Min[i],Max[i],0,
		       data_wje2,background_wje2, 
			   ZToNuNu_wje2,QCD_wje2,WToLNu_wje2,TT_wje2,ST_wje2,VV_wje2,ttV_wje2,
			   tptzm0600lh_wje2,tptzm0700lh_wje2,tptzm0800lh_wje2,tptzm0900lh_wje2,tptzm1000lh_wje2,tptzm1100lh_wje2,tptzm1200lh_wje2,tptzm1300lh_wje2,tptzm1400lh_wje2,tptzm1500lh_wje2,tptzm1600lh_wje2,tptzm1700lh_wje2,tptzm1800lh_wje2,
                           tptzm0700lh_10p_wje2,tptzm0800lh_10p_wje2,tptzm0800lh_20p_wje2,tptzm0800lh_30p_wje2,tptzm0900lh_10p_wje2,tptzm1000lh_10p_wje2,tptzm1000lh_20p_wje2,tptzm1000lh_30p_wje2,tptzm1100lh_10p_wje2,tptzm1200lh_10p_wje2,tptzm1200lh_20p_wje2,tptzm1200lh_30p_wje2,tptzm1300lh_10p_wje2,tptzm1400lh_10p_wje2,tptzm1400lh_20p_wje2,tptzm1400lh_30p_wje2,tptzm1500lh_10p_wje2,tptzm1600lh_10p_wje2,tptzm1600lh_20p_wje2,tptzm1600lh_30p_wje2,tptzm1700lh_10p_wje2);

	MakeHistos(CUTwbe1, plot,bin[i],Min[i],Max[i],0,
		       data_wbe1,background_wbe1, 
			   ZToNuNu_wbe1,QCD_wbe1,WToLNu_wbe1,TT_wbe1,ST_wbe1,VV_wbe1,ttV_wbe1,
			   tptzm0600lh_wbe1,tptzm0700lh_wbe1,tptzm0800lh_wbe1,tptzm0900lh_wbe1,tptzm1000lh_wbe1,tptzm1100lh_wbe1,tptzm1200lh_wbe1,tptzm1300lh_wbe1,tptzm1400lh_wbe1,tptzm1500lh_wbe1,tptzm1600lh_wbe1,tptzm1700lh_wbe1,tptzm1800lh_wbe1,
                           tptzm0700lh_10p_wbe1,tptzm0800lh_10p_wbe1,tptzm0800lh_20p_wbe1,tptzm0800lh_30p_wbe1,tptzm0900lh_10p_wbe1,tptzm1000lh_10p_wbe1,tptzm1000lh_20p_wbe1,tptzm1000lh_30p_wbe1,tptzm1100lh_10p_wbe1,tptzm1200lh_10p_wbe1,tptzm1200lh_20p_wbe1,tptzm1200lh_30p_wbe1,tptzm1300lh_10p_wbe1,tptzm1400lh_10p_wbe1,tptzm1400lh_20p_wbe1,tptzm1400lh_30p_wbe1,tptzm1500lh_10p_wbe1,tptzm1600lh_10p_wbe1,tptzm1600lh_20p_wbe1,tptzm1600lh_30p_wbe1,tptzm1700lh_10p_wbe1);

	MakeHistos(CUTwbe2, plot,bin[i],Min[i],Max[i],0,
		       data_wbe2,background_wbe2, 
			   ZToNuNu_wbe2,QCD_wbe2,WToLNu_wbe2,TT_wbe2,ST_wbe2,VV_wbe2,ttV_wbe2,
			   tptzm0600lh_wbe2,tptzm0700lh_wbe2,tptzm0800lh_wbe2,tptzm0900lh_wbe2,tptzm1000lh_wbe2,tptzm1100lh_wbe2,tptzm1200lh_wbe2,tptzm1300lh_wbe2,tptzm1400lh_wbe2,tptzm1500lh_wbe2,tptzm1600lh_wbe2,tptzm1700lh_wbe2,tptzm1800lh_wbe2,
                           tptzm0700lh_10p_wbe2,tptzm0800lh_10p_wbe2,tptzm0800lh_20p_wbe2,tptzm0800lh_30p_wbe2,tptzm0900lh_10p_wbe2,tptzm1000lh_10p_wbe2,tptzm1000lh_20p_wbe2,tptzm1000lh_30p_wbe2,tptzm1100lh_10p_wbe2,tptzm1200lh_10p_wbe2,tptzm1200lh_20p_wbe2,tptzm1200lh_30p_wbe2,tptzm1300lh_10p_wbe2,tptzm1400lh_10p_wbe2,tptzm1400lh_20p_wbe2,tptzm1400lh_30p_wbe2,tptzm1500lh_10p_wbe2,tptzm1600lh_10p_wbe2,tptzm1600lh_20p_wbe2,tptzm1600lh_30p_wbe2,tptzm1700lh_10p_wbe2);

	MakeHistos(CUTttb1, plot,bin[i],Min[i],Max[i],0,
		       data_ttb1,background_ttb1, 
			   ZToNuNu_ttb1,QCD_ttb1,WToLNu_ttb1,TT_ttb1,ST_ttb1,VV_ttb1,ttV_ttb1,
			   tptzm0600lh_ttb1,tptzm0700lh_ttb1,tptzm0800lh_ttb1,tptzm0900lh_ttb1,tptzm1000lh_ttb1,tptzm1100lh_ttb1,tptzm1200lh_ttb1,tptzm1300lh_ttb1,tptzm1400lh_ttb1,tptzm1500lh_ttb1,tptzm1600lh_ttb1,tptzm1700lh_ttb1,tptzm1800lh_ttb1,
                           tptzm0700lh_10p_ttb1,tptzm0800lh_10p_ttb1,tptzm0800lh_20p_ttb1,tptzm0800lh_30p_ttb1,tptzm0900lh_10p_ttb1,tptzm1000lh_10p_ttb1,tptzm1000lh_20p_ttb1,tptzm1000lh_30p_ttb1,tptzm1100lh_10p_ttb1,tptzm1200lh_10p_ttb1,tptzm1200lh_20p_ttb1,tptzm1200lh_30p_ttb1,tptzm1300lh_10p_ttb1,tptzm1400lh_10p_ttb1,tptzm1400lh_20p_ttb1,tptzm1400lh_30p_ttb1,tptzm1500lh_10p_ttb1,tptzm1600lh_10p_ttb1,tptzm1600lh_20p_ttb1,tptzm1600lh_30p_ttb1,tptzm1700lh_10p_ttb1);

	MakeHistos(CUTttb2, plot,bin[i],Min[i],Max[i],0,
		       data_ttb2,background_ttb2, 
			   ZToNuNu_ttb2,QCD_ttb2,WToLNu_ttb2,TT_ttb2,ST_ttb2,VV_ttb2,ttV_ttb2,
			   tptzm0600lh_ttb2,tptzm0700lh_ttb2,tptzm0800lh_ttb2,tptzm0900lh_ttb2,tptzm1000lh_ttb2,tptzm1100lh_ttb2,tptzm1200lh_ttb2,tptzm1300lh_ttb2,tptzm1400lh_ttb2,tptzm1500lh_ttb2,tptzm1600lh_ttb2,tptzm1700lh_ttb2,tptzm1800lh_ttb2,
                           tptzm0700lh_10p_ttb2,tptzm0800lh_10p_ttb2,tptzm0800lh_20p_ttb2,tptzm0800lh_30p_ttb2,tptzm0900lh_10p_ttb2,tptzm1000lh_10p_ttb2,tptzm1000lh_20p_ttb2,tptzm1000lh_30p_ttb2,tptzm1100lh_10p_ttb2,tptzm1200lh_10p_ttb2,tptzm1200lh_20p_ttb2,tptzm1200lh_30p_ttb2,tptzm1300lh_10p_ttb2,tptzm1400lh_10p_ttb2,tptzm1400lh_20p_ttb2,tptzm1400lh_30p_ttb2,tptzm1500lh_10p_ttb2,tptzm1600lh_10p_ttb2,tptzm1600lh_20p_ttb2,tptzm1600lh_30p_ttb2,tptzm1700lh_10p_ttb2);
	
	MakeHistos(CUTtbe1, plot,bin[i],Min[i],Max[i],0,
		       data_tbe1,background_tbe1, 
			   ZToNuNu_tbe1,QCD_tbe1,WToLNu_tbe1,TT_tbe1,ST_tbe1,VV_tbe1,ttV_tbe1,
			   tptzm0600lh_tbe1,tptzm0700lh_tbe1,tptzm0800lh_tbe1,tptzm0900lh_tbe1,tptzm1000lh_tbe1,tptzm1100lh_tbe1,tptzm1200lh_tbe1,tptzm1300lh_tbe1,tptzm1400lh_tbe1,tptzm1500lh_tbe1,tptzm1600lh_tbe1,tptzm1700lh_tbe1,tptzm1800lh_tbe1,
                           tptzm0700lh_10p_tbe1,tptzm0800lh_10p_tbe1,tptzm0800lh_20p_tbe1,tptzm0800lh_30p_tbe1,tptzm0900lh_10p_tbe1,tptzm1000lh_10p_tbe1,tptzm1000lh_20p_tbe1,tptzm1000lh_30p_tbe1,tptzm1100lh_10p_tbe1,tptzm1200lh_10p_tbe1,tptzm1200lh_20p_tbe1,tptzm1200lh_30p_tbe1,tptzm1300lh_10p_tbe1,tptzm1400lh_10p_tbe1,tptzm1400lh_20p_tbe1,tptzm1400lh_30p_tbe1,tptzm1500lh_10p_tbe1,tptzm1600lh_10p_tbe1,tptzm1600lh_20p_tbe1,tptzm1600lh_30p_tbe1,tptzm1700lh_10p_tbe1);

	MakeHistos(CUTtbe2, plot,bin[i],Min[i],Max[i],0,
		       data_tbe2,background_tbe2, 
			   ZToNuNu_tbe2,QCD_tbe2,WToLNu_tbe2,TT_tbe2,ST_tbe2,VV_tbe2,ttV_tbe2,
			   tptzm0600lh_tbe2,tptzm0700lh_tbe2,tptzm0800lh_tbe2,tptzm0900lh_tbe2,tptzm1000lh_tbe2,tptzm1100lh_tbe2,tptzm1200lh_tbe2,tptzm1300lh_tbe2,tptzm1400lh_tbe2,tptzm1500lh_tbe2,tptzm1600lh_tbe2,tptzm1700lh_tbe2,tptzm1800lh_tbe2,
                           tptzm0700lh_10p_tbe2,tptzm0800lh_10p_tbe2,tptzm0800lh_20p_tbe2,tptzm0800lh_30p_tbe2,tptzm0900lh_10p_tbe2,tptzm1000lh_10p_tbe2,tptzm1000lh_20p_tbe2,tptzm1000lh_30p_tbe2,tptzm1100lh_10p_tbe2,tptzm1200lh_10p_tbe2,tptzm1200lh_20p_tbe2,tptzm1200lh_30p_tbe2,tptzm1300lh_10p_tbe2,tptzm1400lh_10p_tbe2,tptzm1400lh_20p_tbe2,tptzm1400lh_30p_tbe2,tptzm1500lh_10p_tbe2,tptzm1600lh_10p_tbe2,tptzm1600lh_20p_tbe2,tptzm1600lh_30p_tbe2,tptzm1700lh_10p_tbe2);
	
	MakeHistos(CUTSR,   plot,bin[i],Min[i],Max[i],1,
		       data_jes1,background_jes1, 
			   ZToNuNu_jes1,QCD_jes1,WToLNu_jes1,TT_jes1,ST_jes1,VV_jes1,ttV_jes1,
			   tptzm0600lh_jes1,tptzm0700lh_jes1,tptzm0800lh_jes1,tptzm0900lh_jes1,tptzm1000lh_jes1,tptzm1100lh_jes1,tptzm1200lh_jes1,tptzm1300lh_jes1,tptzm1400lh_jes1,tptzm1500lh_jes1,tptzm1600lh_jes1,tptzm1700lh_jes1,tptzm1800lh_jes1,
                           tptzm0700lh_10p_jes1,tptzm0800lh_10p_jes1,tptzm0800lh_20p_jes1,tptzm0800lh_30p_jes1,tptzm0900lh_10p_jes1,tptzm1000lh_10p_jes1,tptzm1000lh_20p_jes1,tptzm1000lh_30p_jes1,tptzm1100lh_10p_jes1,tptzm1200lh_10p_jes1,tptzm1200lh_20p_jes1,tptzm1200lh_30p_jes1,tptzm1300lh_10p_jes1,tptzm1400lh_10p_jes1,tptzm1400lh_20p_jes1,tptzm1400lh_30p_jes1,tptzm1500lh_10p_jes1,tptzm1600lh_10p_jes1,tptzm1600lh_20p_jes1,tptzm1600lh_30p_jes1,tptzm1700lh_10p_jes1);

	MakeHistos(CUTSR,   plot,bin[i],Min[i],Max[i],2,
		       data_jes2,background_jes2, 
			   ZToNuNu_jes2,QCD_jes2,WToLNu_jes2,TT_jes2,ST_jes2,VV_jes2,ttV_jes2,
			   tptzm0600lh_jes2,tptzm0700lh_jes2,tptzm0800lh_jes2,tptzm0900lh_jes2,tptzm1000lh_jes2,tptzm1100lh_jes2,tptzm1200lh_jes2,tptzm1300lh_jes2,tptzm1400lh_jes2,tptzm1500lh_jes2,tptzm1600lh_jes2,tptzm1700lh_jes2,tptzm1800lh_jes2,
                           tptzm0700lh_10p_jes2,tptzm0800lh_10p_jes2,tptzm0800lh_20p_jes2,tptzm0800lh_30p_jes2,tptzm0900lh_10p_jes2,tptzm1000lh_10p_jes2,tptzm1000lh_20p_jes2,tptzm1000lh_30p_jes2,tptzm1100lh_10p_jes2,tptzm1200lh_10p_jes2,tptzm1200lh_20p_jes2,tptzm1200lh_30p_jes2,tptzm1300lh_10p_jes2,tptzm1400lh_10p_jes2,tptzm1400lh_20p_jes2,tptzm1400lh_30p_jes2,tptzm1500lh_10p_jes2,tptzm1600lh_10p_jes2,tptzm1600lh_20p_jes2,tptzm1600lh_30p_jes2,tptzm1700lh_10p_jes2);

	MakeHistos(CUTSR,   plot,bin[i],Min[i],Max[i],3,
		       data_jer1,background_jer1, 
			   ZToNuNu_jer1,QCD_jer1,WToLNu_jer1,TT_jer1,ST_jer1,VV_jer1,ttV_jer1,
			   tptzm0600lh_jer1,tptzm0700lh_jer1,tptzm0800lh_jer1,tptzm0900lh_jer1,tptzm1000lh_jer1,tptzm1100lh_jer1,tptzm1200lh_jer1,tptzm1300lh_jer1,tptzm1400lh_jer1,tptzm1500lh_jer1,tptzm1600lh_jer1,tptzm1700lh_jer1,tptzm1800lh_jer1,
                           tptzm0700lh_10p_jer1,tptzm0800lh_10p_jer1,tptzm0800lh_20p_jer1,tptzm0800lh_30p_jer1,tptzm0900lh_10p_jer1,tptzm1000lh_10p_jer1,tptzm1000lh_20p_jer1,tptzm1000lh_30p_jer1,tptzm1100lh_10p_jer1,tptzm1200lh_10p_jer1,tptzm1200lh_20p_jer1,tptzm1200lh_30p_jer1,tptzm1300lh_10p_jer1,tptzm1400lh_10p_jer1,tptzm1400lh_20p_jer1,tptzm1400lh_30p_jer1,tptzm1500lh_10p_jer1,tptzm1600lh_10p_jer1,tptzm1600lh_20p_jer1,tptzm1600lh_30p_jer1,tptzm1700lh_10p_jer1);

	MakeHistos(CUTSR,   plot,bin[i],Min[i],Max[i],4,
		       data_jer2,background_jer2, 
			   ZToNuNu_jer2,QCD_jer2,WToLNu_jer2,TT_jer2,ST_jer2,VV_jer2,ttV_jer2,
			   tptzm0600lh_jer2,tptzm0700lh_jer2,tptzm0800lh_jer2,tptzm0900lh_jer2,tptzm1000lh_jer2,tptzm1100lh_jer2,tptzm1200lh_jer2,tptzm1300lh_jer2,tptzm1400lh_jer2,tptzm1500lh_jer2,tptzm1600lh_jer2,tptzm1700lh_jer2,tptzm1800lh_jer2,
                           tptzm0700lh_10p_jer2,tptzm0800lh_10p_jer2,tptzm0800lh_20p_jer2,tptzm0800lh_30p_jer2,tptzm0900lh_10p_jer2,tptzm1000lh_10p_jer2,tptzm1000lh_20p_jer2,tptzm1000lh_30p_jer2,tptzm1100lh_10p_jer2,tptzm1200lh_10p_jer2,tptzm1200lh_20p_jer2,tptzm1200lh_30p_jer2,tptzm1300lh_10p_jer2,tptzm1400lh_10p_jer2,tptzm1400lh_20p_jer2,tptzm1400lh_30p_jer2,tptzm1500lh_10p_jer2,tptzm1600lh_10p_jer2,tptzm1600lh_20p_jer2,tptzm1600lh_30p_jer2,tptzm1700lh_10p_jer2);
	
	MakeHistos(CUTqcd1, plot,bin[i],Min[i],Max[i],0,
		       data_qcd1,background_qcd1, 
			   ZToNuNu_qcd1,QCD_qcd1,WToLNu_qcd1,TT_qcd1,ST_qcd1,VV_qcd1,ttV_qcd1,
			   tptzm0600lh_qcd1,tptzm0700lh_qcd1,tptzm0800lh_qcd1,tptzm0900lh_qcd1,tptzm1000lh_qcd1,tptzm1100lh_qcd1,tptzm1200lh_qcd1,tptzm1300lh_qcd1,tptzm1400lh_qcd1,tptzm1500lh_qcd1,tptzm1600lh_qcd1,tptzm1700lh_qcd1,tptzm1800lh_qcd1,
                           tptzm0700lh_10p_qcd1,tptzm0800lh_10p_qcd1,tptzm0800lh_20p_qcd1,tptzm0800lh_30p_qcd1,tptzm0900lh_10p_qcd1,tptzm1000lh_10p_qcd1,tptzm1000lh_20p_qcd1,tptzm1000lh_30p_qcd1,tptzm1100lh_10p_qcd1,tptzm1200lh_10p_qcd1,tptzm1200lh_20p_qcd1,tptzm1200lh_30p_qcd1,tptzm1300lh_10p_qcd1,tptzm1400lh_10p_qcd1,tptzm1400lh_20p_qcd1,tptzm1400lh_30p_qcd1,tptzm1500lh_10p_qcd1,tptzm1600lh_10p_qcd1,tptzm1600lh_20p_qcd1,tptzm1600lh_30p_qcd1,tptzm1700lh_10p_qcd1);

	MakeHistos(CUTqcd2, plot,bin[i],Min[i],Max[i],0,
		       data_qcd2,background_qcd2, 
			   ZToNuNu_qcd2,QCD_qcd2,WToLNu_qcd2,TT_qcd2,ST_qcd2,VV_qcd2,ttV_qcd2,
			   tptzm0600lh_qcd2,tptzm0700lh_qcd2,tptzm0800lh_qcd2,tptzm0900lh_qcd2,tptzm1000lh_qcd2,tptzm1100lh_qcd2,tptzm1200lh_qcd2,tptzm1300lh_qcd2,tptzm1400lh_qcd2,tptzm1500lh_qcd2,tptzm1600lh_qcd2,tptzm1700lh_qcd2,tptzm1800lh_qcd2,
                           tptzm0700lh_10p_qcd2,tptzm0800lh_10p_qcd2,tptzm0800lh_20p_qcd2,tptzm0800lh_30p_qcd2,tptzm0900lh_10p_qcd2,tptzm1000lh_10p_qcd2,tptzm1000lh_20p_qcd2,tptzm1000lh_30p_qcd2,tptzm1100lh_10p_qcd2,tptzm1200lh_10p_qcd2,tptzm1200lh_20p_qcd2,tptzm1200lh_30p_qcd2,tptzm1300lh_10p_qcd2,tptzm1400lh_10p_qcd2,tptzm1400lh_20p_qcd2,tptzm1400lh_30p_qcd2,tptzm1500lh_10p_qcd2,tptzm1600lh_10p_qcd2,tptzm1600lh_20p_qcd2,tptzm1600lh_30p_qcd2,tptzm1700lh_10p_qcd2);
	
	MakeHistos(CUTpdf1, plot,bin[i],Min[i],Max[i],0,
		       data_pdf1,background_pdf1, 
			   ZToNuNu_pdf1,QCD_pdf1,WToLNu_pdf1,TT_pdf1,ST_pdf1,VV_pdf1,ttV_pdf1,
			   tptzm0600lh_pdf1,tptzm0700lh_pdf1,tptzm0800lh_pdf1,tptzm0900lh_pdf1,tptzm1000lh_pdf1,tptzm1100lh_pdf1,tptzm1200lh_pdf1,tptzm1300lh_pdf1,tptzm1400lh_pdf1,tptzm1500lh_pdf1,tptzm1600lh_pdf1,tptzm1700lh_pdf1,tptzm1800lh_pdf1,
                           tptzm0700lh_10p_pdf1,tptzm0800lh_10p_pdf1,tptzm0800lh_20p_pdf1,tptzm0800lh_30p_pdf1,tptzm0900lh_10p_pdf1,tptzm1000lh_10p_pdf1,tptzm1000lh_20p_pdf1,tptzm1000lh_30p_pdf1,tptzm1100lh_10p_pdf1,tptzm1200lh_10p_pdf1,tptzm1200lh_20p_pdf1,tptzm1200lh_30p_pdf1,tptzm1300lh_10p_pdf1,tptzm1400lh_10p_pdf1,tptzm1400lh_20p_pdf1,tptzm1400lh_30p_pdf1,tptzm1500lh_10p_pdf1,tptzm1600lh_10p_pdf1,tptzm1600lh_20p_pdf1,tptzm1600lh_30p_pdf1,tptzm1700lh_10p_pdf1);

	MakeHistos(CUTpdf2, plot,bin[i],Min[i],Max[i],0,
		       data_pdf2,background_pdf2, 
			   ZToNuNu_pdf2,QCD_pdf2,WToLNu_pdf2,TT_pdf2,ST_pdf2,VV_pdf2,ttV_pdf2,
			   tptzm0600lh_pdf2,tptzm0700lh_pdf2,tptzm0800lh_pdf2,tptzm0900lh_pdf2,tptzm1000lh_pdf2,tptzm1100lh_pdf2,tptzm1200lh_pdf2,tptzm1300lh_pdf2,tptzm1400lh_pdf2,tptzm1500lh_pdf2,tptzm1600lh_pdf2,tptzm1700lh_pdf2,tptzm1800lh_pdf2,
                           tptzm0700lh_10p_pdf2,tptzm0800lh_10p_pdf2,tptzm0800lh_20p_pdf2,tptzm0800lh_30p_pdf2,tptzm0900lh_10p_pdf2,tptzm1000lh_10p_pdf2,tptzm1000lh_20p_pdf2,tptzm1000lh_30p_pdf2,tptzm1100lh_10p_pdf2,tptzm1200lh_10p_pdf2,tptzm1200lh_20p_pdf2,tptzm1200lh_30p_pdf2,tptzm1300lh_10p_pdf2,tptzm1400lh_10p_pdf2,tptzm1400lh_20p_pdf2,tptzm1400lh_30p_pdf2,tptzm1500lh_10p_pdf2,tptzm1600lh_10p_pdf2,tptzm1600lh_20p_pdf2,tptzm1600lh_30p_pdf2,tptzm1700lh_10p_pdf2);
	
	MakeHistos(CUTtri1, plot,bin[i],Min[i],Max[i],0,
		       data_tri1,background_tri1, 
			   ZToNuNu_tri1,QCD_tri1,WToLNu_tri1,TT_tri1,ST_tri1,VV_tri1,ttV_tri1,
			   tptzm0600lh_tri1,tptzm0700lh_tri1,tptzm0800lh_tri1,tptzm0900lh_tri1,tptzm1000lh_tri1,tptzm1100lh_tri1,tptzm1200lh_tri1,tptzm1300lh_tri1,tptzm1400lh_tri1,tptzm1500lh_tri1,tptzm1600lh_tri1,tptzm1700lh_tri1,tptzm1800lh_tri1,
                           tptzm0700lh_10p_tri1,tptzm0800lh_10p_tri1,tptzm0800lh_20p_tri1,tptzm0800lh_30p_tri1,tptzm0900lh_10p_tri1,tptzm1000lh_10p_tri1,tptzm1000lh_20p_tri1,tptzm1000lh_30p_tri1,tptzm1100lh_10p_tri1,tptzm1200lh_10p_tri1,tptzm1200lh_20p_tri1,tptzm1200lh_30p_tri1,tptzm1300lh_10p_tri1,tptzm1400lh_10p_tri1,tptzm1400lh_20p_tri1,tptzm1400lh_30p_tri1,tptzm1500lh_10p_tri1,tptzm1600lh_10p_tri1,tptzm1600lh_20p_tri1,tptzm1600lh_30p_tri1,tptzm1700lh_10p_tri1);

	MakeHistos(CUTtri2, plot,bin[i],Min[i],Max[i],0,
		       data_tri2,background_tri2, 
			   ZToNuNu_tri2,QCD_tri2,WToLNu_tri2,TT_tri2,ST_tri2,VV_tri2,ttV_tri2,
			   tptzm0600lh_tri2,tptzm0700lh_tri2,tptzm0800lh_tri2,tptzm0900lh_tri2,tptzm1000lh_tri2,tptzm1100lh_tri2,tptzm1200lh_tri2,tptzm1300lh_tri2,tptzm1400lh_tri2,tptzm1500lh_tri2,tptzm1600lh_tri2,tptzm1700lh_tri2,tptzm1800lh_tri2,
                           tptzm0700lh_10p_tri2,tptzm0800lh_10p_tri2,tptzm0800lh_20p_tri2,tptzm0800lh_30p_tri2,tptzm0900lh_10p_tri2,tptzm1000lh_10p_tri2,tptzm1000lh_20p_tri2,tptzm1000lh_30p_tri2,tptzm1100lh_10p_tri2,tptzm1200lh_10p_tri2,tptzm1200lh_20p_tri2,tptzm1200lh_30p_tri2,tptzm1300lh_10p_tri2,tptzm1400lh_10p_tri2,tptzm1400lh_20p_tri2,tptzm1400lh_30p_tri2,tptzm1500lh_10p_tri2,tptzm1600lh_10p_tri2,tptzm1600lh_20p_tri2,tptzm1600lh_30p_tri2,tptzm1700lh_10p_tri2);

	}else {
        CloneHistos();
    }

	SaveRootFileForLimit_dineutrino_v2(save,category,dPMet,BTag,TopPt,dPTop,ht,Met,Mht);

	double ZToNuNuYield_errStat= 0.; double ZToNuNuYield     = ZToNuNu    ->IntegralAndError(1,bin[i],ZToNuNuYield_errStat); 
	double QCDYield_errStat    = 0.; double QCDYield         = QCD        ->IntegralAndError(1,bin[i],QCDYield_errStat);
	double WToLNuYield_errStat = 0.; double WToLNuYield      = WToLNu     ->IntegralAndError(1,bin[i],WToLNuYield_errStat); 
	double TTYield_errStat     = 0.; double TTYield          = TT         ->IntegralAndError(1,bin[i],TTYield_errStat); 
	double STYield_errStat     = 0.; double STYield          = ST         ->IntegralAndError(1,bin[i],STYield_errStat); 
	double VVYield_errStat     = 0.; double VVYield          = VV         ->IntegralAndError(1,bin[i],VVYield_errStat); 
	double ttVYield_errStat    = 0.; double ttVYield         = ttV        ->IntegralAndError(1,bin[i],ttVYield_errStat); 
	double tptzm0700lh_errStat = 0.; double tptzm0700lhYield = tptzm0700lh->IntegralAndError(1,bin[i],tptzm0700lh_errStat); 
	double tptzm0900lh_errStat = 0.; double tptzm0900lhYield = tptzm0900lh->IntegralAndError(1,bin[i],tptzm0900lh_errStat); 
	double tptzm1400lh_errStat = 0.; double tptzm1400lhYield = tptzm1400lh->IntegralAndError(1,bin[i],tptzm1400lh_errStat); 
	double tptzm1700lh_errStat = 0.; double tptzm1700lhYield = tptzm1700lh->IntegralAndError(1,bin[i],tptzm1700lh_errStat);

	MakeHistoErrors(ZToNuNu, ZToNuNu_zje1, ZToNuNu_zje2, ZToNuNu_wje1, ZToNuNu_wje2, ZToNuNu_ttb1, ZToNuNu_ttb2, ZToNuNu_pup1, ZToNuNu_pup2, ZToNuNu_fir1,  ZToNuNu_fir2,  ZToNuNu_bta1,  ZToNuNu_bta2,  ZToNuNu_jes1,  ZToNuNu_jes2,  ZToNuNu_jer1,  ZToNuNu_jer2, ZToNuNu_qcd1, ZToNuNu_qcd2, ZToNuNu_pdf1, ZToNuNu_pdf2, ZToNuNu_tri1, ZToNuNu_tri2);
	MakeHistoErrors(WToLNu, WToLNu_zje1, WToLNu_zje2, WToLNu_wje1, WToLNu_wje2, WToLNu_ttb1, WToLNu_ttb2,  WToLNu_pup1, WToLNu_pup2, WToLNu_fir1,  WToLNu_fir2,  WToLNu_bta1,  WToLNu_bta2,  WToLNu_jes1,  WToLNu_jes2,  WToLNu_jer1,  WToLNu_jer2, WToLNu_qcd1, WToLNu_qcd2, WToLNu_pdf1, WToLNu_pdf2, WToLNu_tri1, WToLNu_tri2);
	MakeHistoErrors(TT, TT_zje1, TT_zje2, TT_wje1, TT_wje2, TT_ttb1, TT_ttb2,  TT_pup1, TT_pup2, TT_fir1,  TT_fir2,  TT_bta1,  TT_bta2,  TT_jes1,  TT_jes2,  TT_jer1,  TT_jer2, TT_qcd1, TT_qcd2, TT_pdf1, TT_pdf2, TT_tri1, TT_tri2);
	MakeHistoErrorsMC( QCD,  QCD_pup1, QCD_pup2, QCD_fir1,  QCD_fir2,  QCD_bta1,  QCD_bta2,  QCD_jes1,  QCD_jes2,  QCD_jer1,  QCD_jer2, QCD_qcd1, QCD_qcd2, QCD_pdf1, QCD_pdf2, QCD_tri1, QCD_tri2);
	MakeHistoErrorsMC( ST,   ST_pup1,  ST_pup2, ST_fir1, ST_fir2, ST_bta1,  ST_bta2, ST_jes1, ST_jes2, ST_jer1, ST_jer2, ST_qcd1, ST_qcd2, ST_pdf1, ST_pdf2, ST_tri1, ST_tri2);
	MakeHistoErrorsMC( VV,   VV_pup1,  VV_pup2, VV_fir1, VV_fir2, VV_bta1,  VV_bta2, VV_jes1, VV_jes2, VV_jer1, VV_jer2, VV_qcd1, VV_qcd2, VV_pdf1, VV_pdf2, VV_tri1, VV_tri2);
	MakeHistoErrorsMC( ttV,  ttV_pup1,  ttV_pup2, ttV_fir1, ttV_fir2, ttV_bta1,  ttV_bta2, ttV_jes1, ttV_jes2, ttV_jer1, ttV_jer2, ttV_qcd1, ttV_qcd2, ttV_pdf1, ttV_pdf2, ttV_tri1, ttV_tri2);
	MakeHistoErrorsMC( tptzm0700lh,   tptzm0700lh_pup1,  tptzm0700lh_pup2, tptzm0700lh_fir1, tptzm0700lh_fir2, tptzm0700lh_bta1, tptzm0700lh_bta2, tptzm0700lh_jes1, tptzm0700lh_jes2, tptzm0700lh_jer1, tptzm0700lh_jer2, tptzm0700lh_qcd1, tptzm0700lh_qcd2, tptzm0700lh_pdf1, tptzm0700lh_pdf2, tptzm0700lh_tri1, tptzm0700lh_tri2);
	MakeHistoErrorsMC( tptzm0900lh,   tptzm0900lh_pup1,  tptzm0900lh_pup2, tptzm0900lh_fir1, tptzm0900lh_fir2, tptzm0900lh_bta1, tptzm0900lh_bta2, tptzm0900lh_jes1, tptzm0900lh_jes2, tptzm0900lh_jer1, tptzm0900lh_jer2, tptzm0900lh_qcd1, tptzm0900lh_qcd2, tptzm0900lh_pdf1, tptzm0900lh_pdf2, tptzm0900lh_tri1, tptzm0900lh_tri2);
	MakeHistoErrorsMC( tptzm1400lh,   tptzm1400lh_pup1,  tptzm1400lh_pup2, tptzm1400lh_fir1, tptzm1400lh_fir2, tptzm1400lh_bta1, tptzm1400lh_bta2, tptzm1400lh_jes1, tptzm1400lh_jes2, tptzm1400lh_jer1, tptzm1400lh_jer2, tptzm1400lh_qcd1, tptzm1400lh_qcd2, tptzm1400lh_pdf1, tptzm1400lh_pdf2, tptzm1400lh_tri1, tptzm1400lh_tri2);
	MakeHistoErrorsMC( tptzm1700lh,   tptzm1700lh_pup1,  tptzm1700lh_pup2, tptzm1700lh_fir1, tptzm1700lh_fir2, tptzm1700lh_bta1, tptzm1700lh_bta2, tptzm1700lh_jes1, tptzm1700lh_jes2, tptzm1700lh_jer1, tptzm1700lh_jer2, tptzm1700lh_qcd1, tptzm1700lh_qcd2, tptzm1700lh_pdf1, tptzm1700lh_pdf2, tptzm1700lh_tri1, tptzm1700lh_tri2);

	double ZToNuNuYield_errSyst= 0.; ZToNuNuYield     = ZToNuNu    ->IntegralAndError(1,bin[i],ZToNuNuYield_errSyst); 
	double QCDYield_errSyst    = 0.; QCDYield         = QCD        ->IntegralAndError(1,bin[i],QCDYield_errSyst);
	double WToLNuYield_errSyst = 0.; WToLNuYield      = WToLNu     ->IntegralAndError(1,bin[i],WToLNuYield_errSyst); 
	double TTYield_errSyst     = 0.; TTYield          = TT         ->IntegralAndError(1,bin[i],TTYield_errSyst); 
	double STYield_errSyst     = 0.; STYield          = ST         ->IntegralAndError(1,bin[i],STYield_errSyst); 
	double VVYield_errSyst     = 0.; VVYield          = VV         ->IntegralAndError(1,bin[i],VVYield_errSyst); 
	double ttVYield_errSyst    = 0.; ttVYield         = ttV        ->IntegralAndError(1,bin[i],ttVYield_errSyst); 
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
	ttVYield_errSyst     = sqrt(pow(ttVYield_errSyst    ,2) - pow(ttVYield_errStat    ,2));
	tptzm0700lh_errSyst = sqrt(pow(tptzm0700lh_errSyst,2) - pow(tptzm0700lh_errStat,2));
	tptzm0900lh_errSyst = sqrt(pow(tptzm0900lh_errSyst,2) - pow(tptzm0900lh_errStat,2));
	tptzm1400lh_errSyst = sqrt(pow(tptzm1400lh_errSyst,2) - pow(tptzm1400lh_errStat,2));
	tptzm1700lh_errSyst = sqrt(pow(tptzm1700lh_errSyst,2) - pow(tptzm1700lh_errStat,2));
        
        Double_t dataErr     = 0; Float_t dataYield     = data   ->IntegralAndError(1,tptzm0700lh->GetNbinsX()-1,dataErr,"");
	Double_t ZToNuNu_Err = 0; Float_t ZToNuNu_Yield = ZToNuNu->IntegralAndError(1,tptzm0700lh->GetNbinsX(),ZToNuNu_Err,"");
	Double_t QCD_Err     = 0; Float_t QCD_Yield     = QCD    ->IntegralAndError(1,tptzm0700lh->GetNbinsX(),QCD_Err,"");
	Double_t WToLNu_Err  = 0; Float_t WToLNu_Yield  = WToLNu ->IntegralAndError(1,tptzm0700lh->GetNbinsX(),WToLNu_Err,"");
	Double_t TT_Err = 0; Float_t TT_Yield = TT->IntegralAndError(1,tptzm0700lh->GetNbinsX(),TT_Err,"");
	Double_t ST_Err = 0; Float_t ST_Yield = ST->IntegralAndError(1,tptzm0700lh->GetNbinsX(),ST_Err,"");
	Double_t VV_Err = 0; Float_t VV_Yield = VV->IntegralAndError(1,tptzm0700lh->GetNbinsX(),VV_Err, "");
	Double_t ttV_Err = 0; Float_t ttV_Yield = ttV->IntegralAndError(1,tptzm0700lh->GetNbinsX(),ttV_Err, "");
	Double_t tptzm0700_Err= 0; Float_t tptzm0700_Yield = tptzm0700lh->IntegralAndError(1,tptzm0700lh->GetNbinsX(),tptzm0700_Err,"");
	Double_t tptzm0900_Err= 0; Float_t tptzm0900_Yield = tptzm0900lh->IntegralAndError(1,tptzm0700lh->GetNbinsX(),tptzm0900_Err,"");
        Double_t tptzm1400_Err= 0; Float_t tptzm1400_Yield = tptzm1400lh->IntegralAndError(1,tptzm0700lh->GetNbinsX(),tptzm1400_Err,"");
	Double_t tptzm1700_Err= 0; Float_t tptzm1700_Yield = tptzm1700lh->IntegralAndError(1,tptzm0700lh->GetNbinsX(),tptzm1700_Err,"");
	
	if(i==0){
          cout<<endl;
          //cout<<"Plotting "<<name[i]<<endl;
          cout<<"DATA      = "<<data->Integral()<<" +/- "<<dataErr<<endl; 
	  cout<<"ZToNuNu   = "<<ZToNuNu->Integral()<<" +/- "<<sqrt(ZToNuNu_Err*ZToNuNu_Err)<<endl;
	  cout<<"QCD       = "<<QCD->Integral()<<" +/- "<<sqrt(QCD_Err*QCD_Err)<<endl;
	  cout<<"WToLNu    = "<<WToLNu->Integral()<<" +/- "<<sqrt(WToLNu_Err*WToLNu_Err)<<endl;
	  cout<<"TT        = "<<TT->Integral()<<" +/- "<<sqrt(TT_Err*TT_Err)<<endl;
	  cout<<"ST        = "<<ST->Integral()<<" +/- "<<sqrt(ST_Err*ST_Err)<<endl;
	  cout<<"Diboson   = "<<VV->Integral()<<" +/- "<<sqrt(VV_Err*VV_Err)<<endl;
	  cout<<"ttV   = "<<ttV->Integral()<<" +/- "<<sqrt(ttV_Err*ttV_Err)<<endl;
	  cout<<"Total BKG = "<<ZToNuNu->Integral()+QCD->Integral()+WToLNu->Integral()+TT->Integral()+ST->Integral()+VV->Integral()<<" +/- "<<
		  sqrt(ZToNuNu_Err*ZToNuNu_Err+QCD_Err*QCD_Err+WToLNu_Err*WToLNu_Err+TT_Err*TT_Err+ST_Err*ST_Err+VV_Err*VV_Err)<<endl;
	  cout<<"Tprime LH 0700 = "<<tptzm0700lh->Integral()<<" +/- "<<sqrt(tptzm0700_Err*tptzm0700_Err)<<endl;
          cout<<"Tprime LH 0800_10p = "<< tptzm0800lh_10p->Integral()<<endl;
          cout<<"Tprime LH 0800_20p = "<< tptzm0800lh_20p->Integral()<<endl;
          cout<<"Tprime LH 0800_30p = "<< tptzm0800lh_30p->Integral()<<endl;
          cout<<"Tprime LH 1000_10p = "<< tptzm1000lh_10p->Integral()<<endl;
          cout<<"Tprime LH 1000_20p = "<< tptzm1000lh_20p->Integral()<<endl;
          cout<<"Tprime LH 1000_30p = "<< tptzm1000lh_30p->Integral()<<endl;
          cout<<"Tprime LH 1200_10p = "<< tptzm1200lh_10p->Integral()<<endl;
          cout<<"Tprime LH 1200_20p = "<< tptzm1200lh_20p->Integral()<<endl;
          cout<<"Tprime LH 1200_30p = "<< tptzm1200lh_30p->Integral()<<endl;
	  cout<<"Tprime LH 0900 = "<<tptzm0900lh->Integral()<<" +/- "<<sqrt(tptzm0900_Err*tptzm0900_Err)<<endl;
	  cout<<"Tprime LH 1400 = "<<tptzm1400lh->Integral()<<" +/- "<<sqrt(tptzm1400_Err*tptzm1400_Err)<<endl;
	  cout<<"Tprime LH 1700 = "<<tptzm1700lh->Integral()<<" +/- "<<sqrt(tptzm1700_Err*tptzm1700_Err)<<endl;
          /*
	  cout<<"Number of ZToNuNu  events    = "<<ZToNuNuYield<<"+/-"<<ZToNuNuYield_errStat<<"(stat)+/-"<<ZToNuNuYield_errSyst<<"(syst)"<<endl;
	  cout<<"Number of QCD  events from MC   = "<<QCDYield<<"+/-"<<QCDYield_errStat<<"(stat)+/-"<<QCDYield_errSyst<<"(syst)"<<endl;
	  cout<<"Number of WToLNu  events   = "<<WToLNuYield<<"+/-"<<WToLNuYield_errStat<<"(stat)+/-"<<WToLNuYield_errSyst<<"(syst)"<<endl;
	  cout<<"Number of ST  events from MC   = "<<STYield<<"+/-"<<STYield_errStat<<"(stat)+/-"<<STYield_errSyst<<"(syst)"<<endl;
	  cout<<"Number of TT  events    = "<<TTYield<<"+/-"<<TTYield_errStat<<"(stat)+/-"<<TTYield_errSyst<<"(syst)"<<endl;
	  cout<<"Number of VV  events from MC   = "<<VVYield<<"+/-"<<VVYield_errStat<<"(stat)+/-"<<VVYield_errSyst<<"(syst)"<<endl;
	  cout<<"Number of ttV events from MC   = "<<ttVYield<<"+/-"<<ttVYield_errStat<<"(stat)+/-"<<ttVYield_errSyst<<"(syst)"<<endl;
	  cout<<"Number of signal events 0.7TeV = "<<tptzm0700lh->Integral()<<"+/-"<<tptzm0700lh_errStat<<"(stat)+/-"<<tptzm0700lh_errSyst<<"(syst)"<<endl;
	  cout<<"Number of signal events 0.9TeV = "<<tptzm0900lh->Integral()<<"+/-"<<tptzm0900lh_errStat<<"(stat)+/-"<<tptzm0900lh_errSyst<<"(syst)"<<endl;
	  cout<<"Number of signal events 1.4TeV = "<<tptzm1400lh->Integral()<<"+/-"<<tptzm1400lh_errStat<<"(stat)+/-"<<tptzm1400lh_errSyst<<"(syst)"<<endl;
	  cout<<"Number of signal events 1.7TeV = "<<tptzm1700lh->Integral()<<"+/-"<<tptzm1700lh_errStat<<"(stat)+/-"<<tptzm1700lh_errSyst<<"(syst)"<<endl;
	*/
	}
                
        tptzm0700lh->SetLineWidth(2); tptzm0900lh->SetLineWidth(2); tptzm1400lh->SetLineWidth(2); tptzm1700lh->SetLineWidth(2); 
	tptzm1700lh->SetLineStyle(2); tptzm0700lh->SetLineColor(2); tptzm0900lh->SetLineColor(2); tptzm1400lh->SetLineColor(2); tptzm1700lh->SetLineColor(2); 
	ZToNuNu->SetLineWidth(2);  QCD->SetLineWidth(2); WToLNu->SetLineWidth(2); TT->SetLineWidth(2); ST->SetLineWidth(2); VV->SetLineWidth(2); ttV->SetLineWidth(2);
	ZToNuNu->SetLineColor(kOrange); QCD->SetLineColor(kGreen-3); WToLNu->SetLineColor(kCyan-4); TT->SetLineColor(kGreen+3); ST->SetLineColor(kGreen+3); VV->SetLineColor(kCyan+2); ttV->SetLineColor(kOrange+4);
	ZToNuNu->SetFillColor(kOrange); QCD->SetFillColor(kGreen-3); WToLNu->SetFillColor(kCyan-4); TT->SetFillColor(kGreen+3); ST->SetFillColor(kGreen+3); VV->SetFillColor(kCyan+2); ttV->SetFillColor(kOrange+4);
	data->SetLineWidth(2); data->SetLineColor(1); data->SetMarkerColor(1); data->SetMarkerStyle(20); data->SetMarkerSize(1.3);
        
    TCanvas* c1 = new TCanvas("c1","c1",0,0,900,600);

	//////
	//画下面data/MC的比率计算图
	//////
    /*TPad *c1_1 = new TPad("c1_1","newpad",0.01,0.01,0.99,0.32);
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
    //RATIO->Draw("AE0p");
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
    //RATIO2->Draw("E2same");
    //RATIO->Draw("E0psame");

    TLine* line = new TLine(Min[i],1,Max[i],1);
    line->SetLineColor(2);
    line->SetLineWidth(2);
    //line->Draw("same");	
    c1->cd();*/
    
	/////
	//画上面的data/MC图
	/////
    TPad *c1_2 = new TPad("c1_2", "newpad",0.01,0.01,0.99,0.99);
    c1_2->Draw();
    c1_2->cd();
    c1_2->SetTopMargin(0.08);
    c1_2->SetBottomMargin(0.15);
    c1_2->SetRightMargin(0.035);
    c1_2->SetLeftMargin(0.11);
    
    THStack *hs = new THStack("hs","hs");

    hs->Add(ST);
    hs->Add(TT);
    hs->Add(ttV);
    hs->Add(WToLNu);
    hs->Add(VV);
    hs->Add(QCD);
    hs->Add(ZToNuNu);

    hs->Draw("histo");
    hs->SetMinimum(0);
    hs->GetYaxis()->SetTitleSize(0.060);
    hs->GetXaxis()->SetTitleSize(0.06);
    hs->GetYaxis()->SetLabelSize(0.060);
    hs->GetXaxis()->SetLabelSize(0.05); 
    hs->GetXaxis()->SetRangeUser(Min[i],Max[i]);
    hs->SetTitle("");
    hs->GetYaxis()->SetTitle("Events");
    hs->GetXaxis()->SetTitle(axis[i]);
    hs->GetYaxis()->SetTitleOffset(0.80);
    hs->GetXaxis()->SetTitleOffset(0.90);
    tptzm0900lh->Draw("samehisto");
    tptzm1700lh->Draw("samehisto");

    //data->Draw("E same"); 

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
    TString channelText;
    if(category==0) channelText = "N(forward jets) = 0";
    if(category==1) channelText = "N(forward jets) > 0";
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
    lumi_13TeV = "35.9fb^{-1}";
    TString lumiText;
    lumiText += lumi_13TeV;
    lumiText += " (2016, 13 TeV)";
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
    latex.DrawLatex(0.56,  0.43, channelText); 


    //定义图中各个线和直方图的颜色
    TLegend *pl2 = new TLegend(0.55,0.50,0.95,0.91);
    pl2->SetTextSize(0.045); 
    pl2->SetFillColor(0);
    TLegendEntry *ple2 = pl2->AddEntry(data, "data",  "L"); 
    ple2 = pl2->AddEntry(ZToNuNu, "Z to NuNu",  "F");
    ple2 = pl2->AddEntry(QCD, "QCD",  "F");
    ple2 = pl2->AddEntry(WToLNu, "W to LNu",  "F");
    ple2 = pl2->AddEntry(VV, "VV (V = Z or W)",  "F");
    ple2 = pl2->AddEntry(ST, "t#bar{t} and single-top",  "F");
    ple2 = pl2->AddEntry(ttV, "ttV and tZq (V = Z or W)",  "F");
    ple2 = pl2->AddEntry(tptzm0900lh, "T, M=0.9TeV, ",  "L"); 
    ple2 = pl2->AddEntry(tptzm1700lh, "T, M=1.7TeV, ",  "L"); 
    pl2->Draw();

    char cat[2]; sprintf(cat,"%i",   category); TString CAT = cat;
    TString NAME = name[i];
    cout<<"Finished "<<NAME<<endl;
    //c1->SaveAs("/publicfs/cms/user/yutz/Tprime/2016_dineutrino/"+NAME+"_cat"+CAT+".png");
    //c1->SaveAs("/publicfs/cms/user/yutz/Tprime/2016_dineutrino/"+NAME+"_cat"+CAT+".pdf");
    c1->SaveAs(NAME+"_cat"+CAT+".pdf");
    c1->SaveAs(NAME+"_cat"+CAT+".png");
    //c1->Draw(); 
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
		TH1F* &ZToNuNu_func,TH1F* &QCD_func,TH1F* &WToLNu_func,TH1F* &TT_func,TH1F* &ST_func,TH1F* &VV_func,TH1F* &ttV_func,
		TH1F* &tptzm0600lh_func,TH1F* &tptzm0700lh_func,TH1F* &tptzm0800lh_func,TH1F* &tptzm0900lh_func,TH1F* &tptzm1000lh_func,TH1F* &tptzm1100lh_func,TH1F* &tptzm1200lh_func,TH1F* &tptzm1300lh_func,TH1F* &tptzm1400lh_func,TH1F* &tptzm1500lh_func,TH1F* &tptzm1600lh_func,TH1F* &tptzm1700lh_func,TH1F* &tptzm1800lh_func,
                TH1F* &tptzm0700lh_10p_func,TH1F* &tptzm0800lh_10p_func,TH1F* &tptzm0800lh_20p_func,TH1F* &tptzm0800lh_30p_func,TH1F* &tptzm0900lh_10p_func,TH1F* &tptzm1000lh_10p_func,TH1F* &tptzm1000lh_20p_func,TH1F* &tptzm1000lh_30p_func,TH1F* &tptzm1100lh_10p_func,TH1F* &tptzm1200lh_10p_func,TH1F* &tptzm1200lh_20p_func,TH1F* &tptzm1200lh_30p_func,TH1F* &tptzm1300lh_10p_func,TH1F* &tptzm1400lh_10p_func,TH1F* &tptzm1400lh_20p_func,TH1F* &tptzm1400lh_30p_func,TH1F* &tptzm1500lh_10p_func,TH1F* &tptzm1600lh_10p_func,TH1F* &tptzm1600lh_20p_func,TH1F* &tptzm1600lh_30p_func,TH1F* &tptzm1700lh_10p_func){

  TH1F *data; TH1F *tptzm0600lh; TH1F *tptzm0700lh; TH1F *tptzm0800lh; TH1F *tptzm0900lh; TH1F *tptzm1000lh; TH1F *tptzm1100lh; TH1F *tptzm1200lh; TH1F *tptzm1300lh; TH1F *tptzm1400lh; TH1F *tptzm1500lh; TH1F *tptzm1600lh; TH1F *tptzm1700lh; TH1F *tptzm1800lh; 
  TH1F *tptzm0700lh_10p; TH1F *tptzm0800lh_10p; TH1F *tptzm0800lh_20p; TH1F *tptzm0800lh_30p; TH1F *tptzm0900lh_10p; TH1F *tptzm1000lh_10p; TH1F *tptzm1000lh_20p; TH1F *tptzm1000lh_30p; TH1F *tptzm1100lh_10p; TH1F *tptzm1200lh_10p; TH1F *tptzm1200lh_20p; TH1F *tptzm1200lh_30p; TH1F *tptzm1300lh_10p; TH1F *tptzm1400lh_10p; TH1F *tptzm1400lh_20p; TH1F *tptzm1400lh_30p; TH1F *tptzm1500lh_10p; TH1F *tptzm1600lh_10p; TH1F *tptzm1600lh_20p; TH1F *tptzm1600lh_30p; TH1F *tptzm1700lh_10p; 
  TH1F *ZToNuNu_1; TH1F *ZToNuNu_2; TH1F *ZToNuNu_3; TH1F *ZToNuNu_4; TH1F *ZToNuNu_5; TH1F *ZToNuNu_6; TH1F *ZToNuNu_7; 
  TH1F *QCD_1; TH1F *QCD_2; TH1F *QCD_3; TH1F *QCD_4; TH1F *QCD_5; TH1F *QCD_6; TH1F *QCD_7; 
  TH1F *WToLNu_1; TH1F *WToLNu_2; TH1F *WToLNu_3; TH1F *WToLNu_4; TH1F *WToLNu_5; TH1F *WToLNu_6; TH1F *WToLNu_7;
  TH1F *TT_1; TH1F *TT_2; 
  TH1F *ST_1; TH1F *ST_2; TH1F *ST_3; TH1F *ST_4; 
  TH1F *ZZ1; TH1F *ZZ2; TH1F *ZZ3; TH1F *WZ1; TH1F *WZ2; TH1F *WZ3; TH1F *WW1; TH1F *WW2; 
  TH1F *ttW; TH1F *ttZ; TH1F *tZq; TH1F *ZZ4; TH1F *WZ4;
  if(JETSyst==0){  
    GetHisto(CUTPre, Tree00, data        ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree01, tptzm0600lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree02, tptzm0700lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree02_10p, tptzm0700lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree03, tptzm0800lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree03_10p, tptzm0800lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree03_20p, tptzm0800lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree03_30p, tptzm0800lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree04, tptzm0900lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree04_10p, tptzm0900lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree05, tptzm1000lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree05_10p, tptzm1000lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree05_20p, tptzm1000lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree05_30p, tptzm1000lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree06, tptzm1100lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree06_10p, tptzm1100lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree07, tptzm1200lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree07_10p, tptzm1200lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree07_20p, tptzm1200lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree07_30p, tptzm1200lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree08, tptzm1300lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree08_10p, tptzm1300lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09, tptzm1400lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_10p, tptzm1400lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_20p, tptzm1400lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_30p, tptzm1400lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree10, tptzm1500lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree10_10p, tptzm1500lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree11, tptzm1600lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree11_10p, tptzm1600lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree11_20p, tptzm1600lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree11_30p, tptzm1600lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree12, tptzm1700lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree12_10p, tptzm1700lh_10p ,plot,BIN,MIN,MAX);
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
    GetHisto(CUTPre, Tree49, ttW    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree50, ttZ    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree51, tZq    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree52, ZZ4    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree53, WZ4    ,plot,BIN,MIN,MAX);
  }else if(JETSyst==1){
    GetHisto(CUTPre, Tree00_J1, data        ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree01_J1, tptzm0600lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree02_J1, tptzm0700lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree02_10p_J1, tptzm0700lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree03_J1, tptzm0800lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree03_10p_J1, tptzm0800lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree03_20p_J1, tptzm0800lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree03_30p_J1, tptzm0800lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree04_J1, tptzm0900lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree04_10p_J1, tptzm0900lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree05_J1, tptzm1000lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree05_10p_J1, tptzm1000lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree05_20p_J1, tptzm1000lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree05_30p_J1, tptzm1000lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree06_J1, tptzm1100lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree06_10p_J1, tptzm1100lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree07_J1, tptzm1200lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree07_10p_J1, tptzm1200lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree07_20p_J1, tptzm1200lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree07_30p_J1, tptzm1200lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree08_J1, tptzm1300lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree08_10p_J1, tptzm1300lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_J1, tptzm1400lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_10p_J1, tptzm1400lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_20p_J1, tptzm1400lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_30p_J1, tptzm1400lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree10_J1, tptzm1500lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree10_10p_J1, tptzm1500lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree11_J1, tptzm1600lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree11_10p_J1, tptzm1600lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree11_20p_J1, tptzm1600lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree11_30p_J1, tptzm1600lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree12_J1, tptzm1700lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree12_10p_J1, tptzm1700lh_10p ,plot,BIN,MIN,MAX);
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
    GetHisto(CUTPre, Tree49_J1, ttW    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree50_J1, ttZ    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree51_J1, tZq    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree52_J1, ZZ4    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree53_J1, WZ4    ,plot,BIN,MIN,MAX);
  }else if(JETSyst==2){
    GetHisto(CUTPre, Tree00_J2, data        ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree01_J2, tptzm0600lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree02_J2, tptzm0700lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree02_10p_J2, tptzm0700lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree03_J2, tptzm0800lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree03_10p_J2, tptzm0800lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree03_20p_J2, tptzm0800lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree03_30p_J2, tptzm0800lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree04_J2, tptzm0900lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree04_10p_J2, tptzm0900lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree05_J2, tptzm1000lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree05_10p_J2, tptzm1000lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree05_20p_J2, tptzm1000lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree05_30p_J2, tptzm1000lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree06_J2, tptzm1100lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree06_10p_J2, tptzm1100lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree07_J2, tptzm1200lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree07_10p_J2, tptzm1200lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree07_20p_J2, tptzm1200lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree07_30p_J2, tptzm1200lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree08_J2, tptzm1300lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree08_10p_J2, tptzm1300lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_J2, tptzm1400lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_10p_J2, tptzm1400lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_20p_J2, tptzm1400lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_30p_J2, tptzm1400lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree10_J2, tptzm1500lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree10_10p_J2, tptzm1500lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree11_J2, tptzm1600lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree11_10p_J2, tptzm1600lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree11_20p_J2, tptzm1600lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree11_30p_J2, tptzm1600lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree12_J2, tptzm1700lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree12_10p_J2, tptzm1700lh_10p ,plot,BIN,MIN,MAX);
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
    GetHisto(CUTPre, Tree49_J2, ttW    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree50_J2, ttZ    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree51_J2, tZq    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree52_J2, ZZ4    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree53_J2, WZ4    ,plot,BIN,MIN,MAX);
  }else if(JETSyst==3){
    GetHisto(CUTPre, Tree00_J3, data        ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree01_J3, tptzm0600lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree02_J3, tptzm0700lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree02_10p_J3, tptzm0700lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree03_J3, tptzm0800lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree03_10p_J3, tptzm0800lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree03_20p_J3, tptzm0800lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree03_30p_J3, tptzm0800lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree04_J3, tptzm0900lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree04_10p_J3, tptzm0900lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree05_J3, tptzm1000lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree05_10p_J3, tptzm1000lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree05_20p_J3, tptzm1000lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree05_30p_J3, tptzm1000lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree06_J3, tptzm1100lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree06_10p_J3, tptzm1100lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree07_J3, tptzm1200lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree07_10p_J3, tptzm1200lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree07_20p_J3, tptzm1200lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree07_30p_J3, tptzm1200lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree08_J3, tptzm1300lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree08_10p_J3, tptzm1300lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_J3, tptzm1400lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_10p_J3, tptzm1400lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_20p_J3, tptzm1400lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_30p_J3, tptzm1400lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree10_J3, tptzm1500lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree10_10p_J3, tptzm1500lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree11_J3, tptzm1600lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree11_10p_J3, tptzm1600lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree11_20p_J3, tptzm1600lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree11_30p_J3, tptzm1600lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree12_J3, tptzm1700lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree12_10p_J3, tptzm1700lh_10p ,plot,BIN,MIN,MAX);
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
    GetHisto(CUTPre, Tree49_J3, ttW    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree50_J3, ttZ    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree51_J3, tZq    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree52_J3, ZZ4    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree53_J3, WZ4    ,plot,BIN,MIN,MAX);
  }else if(JETSyst==4){
    GetHisto(CUTPre, Tree00_J4, data        ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree01_J4, tptzm0600lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree02_J4, tptzm0700lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree02_10p_J4, tptzm0700lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree03_J4, tptzm0800lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree03_10p_J4, tptzm0800lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree03_20p_J4, tptzm0800lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree03_30p_J4, tptzm0800lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree04_J4, tptzm0900lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree04_10p_J4, tptzm0900lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree05_J4, tptzm1000lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree05_10p_J4, tptzm1000lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree05_20p_J4, tptzm1000lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree05_30p_J4, tptzm1000lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree06_J4, tptzm1100lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree06_10p_J4, tptzm1100lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree07_J4, tptzm1200lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree07_10p_J4, tptzm1200lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree07_20p_J4, tptzm1200lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree07_30p_J4, tptzm1200lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree08_J4, tptzm1300lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree08_10p_J4, tptzm1300lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_J4, tptzm1400lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_10p_J4, tptzm1400lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_20p_J4, tptzm1400lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree09_30p_J4, tptzm1400lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree10_J4, tptzm1500lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree10_10p_J4, tptzm1500lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree11_J4, tptzm1600lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree11_10p_J4, tptzm1600lh_10p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree11_20p_J4, tptzm1600lh_20p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree11_30p_J4, tptzm1600lh_30p ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree12_J4, tptzm1700lh ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree12_10p_J4, tptzm1700lh_10p ,plot,BIN,MIN,MAX);
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
    GetHisto(CUTPre, Tree49_J4, ttW    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree50_J4, ttZ    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree51_J4, tZq    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree52_J4, ZZ4    ,plot,BIN,MIN,MAX);
    GetHisto(CUTPre, Tree53_J4, WZ4    ,plot,BIN,MIN,MAX);
  }
	
  for(int j=1; j<data->GetNbinsX()+1; j++){
    if(tptzm0600lh->GetBinContent(j)>0){tptzm0600lh->SetBinError(j,sqrt(w0600*w0600*tptzm0600lh->GetBinContent(j)));}else{tptzm0600lh->SetBinError(j,0);}
    if(tptzm0700lh->GetBinContent(j)>0){tptzm0700lh->SetBinError(j,sqrt(w0700*w0700*tptzm0700lh->GetBinContent(j)));}else{tptzm0700lh->SetBinError(j,0);}
    if(tptzm0700lh_10p->GetBinContent(j)>0){tptzm0700lh_10p->SetBinError(j,sqrt(w0700_10p*w0700_10p*tptzm0700lh_10p->GetBinContent(j)));}else{tptzm0700lh_10p->SetBinError(j,0);}
    if(tptzm0800lh->GetBinContent(j)>0){tptzm0800lh->SetBinError(j,sqrt(w0800*w0800*tptzm0800lh->GetBinContent(j)));}else{tptzm0800lh->SetBinError(j,0);}
    if(tptzm0800lh_10p->GetBinContent(j)>0){tptzm0800lh_10p->SetBinError(j,sqrt(w0800_10p*w0800_10p*tptzm0800lh_10p->GetBinContent(j)));}else{tptzm0800lh_10p->SetBinError(j,0);}
    if(tptzm0800lh_20p->GetBinContent(j)>0){tptzm0800lh_20p->SetBinError(j,sqrt(w0800_20p*w0800_20p*tptzm0800lh_20p->GetBinContent(j)));}else{tptzm0800lh_20p->SetBinError(j,0);}
    if(tptzm0800lh_30p->GetBinContent(j)>0){tptzm0800lh_30p->SetBinError(j,sqrt(w0800_30p*w0800_30p*tptzm0800lh_30p->GetBinContent(j)));}else{tptzm0800lh_30p->SetBinError(j,0);}
    if(tptzm0900lh->GetBinContent(j)>0){tptzm0900lh->SetBinError(j,sqrt(w0900*w0900*tptzm0900lh->GetBinContent(j)));}else{tptzm0900lh->SetBinError(j,0);}
    if(tptzm0900lh_10p->GetBinContent(j)>0){tptzm0900lh_10p->SetBinError(j,sqrt(w0900_10p*w0900_10p*tptzm0900lh_10p->GetBinContent(j)));}else{tptzm0900lh_10p->SetBinError(j,0);}
    if(tptzm1000lh->GetBinContent(j)>0){tptzm1000lh->SetBinError(j,sqrt(w1000*w1000*tptzm1000lh->GetBinContent(j)));}else{tptzm1000lh->SetBinError(j,0);}
    if(tptzm1000lh_10p->GetBinContent(j)>0){tptzm1000lh_10p->SetBinError(j,sqrt(w1000_10p*w1000_10p*tptzm1000lh_10p->GetBinContent(j)));}else{tptzm1000lh_10p->SetBinError(j,0);}
    if(tptzm1000lh_20p->GetBinContent(j)>0){tptzm1000lh_20p->SetBinError(j,sqrt(w1000_20p*w1000_20p*tptzm1000lh_20p->GetBinContent(j)));}else{tptzm1000lh_20p->SetBinError(j,0);}
    if(tptzm1000lh_30p->GetBinContent(j)>0){tptzm1000lh_30p->SetBinError(j,sqrt(w1000_30p*w1000_30p*tptzm1000lh_30p->GetBinContent(j)));}else{tptzm1000lh_30p->SetBinError(j,0);}
    if(tptzm1100lh->GetBinContent(j)>0){tptzm1100lh->SetBinError(j,sqrt(w1100*w1100*tptzm1100lh->GetBinContent(j)));}else{tptzm1100lh->SetBinError(j,0);}
    if(tptzm1100lh_10p->GetBinContent(j)>0){tptzm1100lh_10p->SetBinError(j,sqrt(w1100_10p*w1100_10p*tptzm1100lh_10p->GetBinContent(j)));}else{tptzm1100lh_10p->SetBinError(j,0);}
    if(tptzm1200lh->GetBinContent(j)>0){tptzm1200lh->SetBinError(j,sqrt(w1200*w1200*tptzm1200lh->GetBinContent(j)));}else{tptzm1200lh->SetBinError(j,0);}
    if(tptzm1200lh_10p->GetBinContent(j)>0){tptzm1200lh_10p->SetBinError(j,sqrt(w1200_10p*w1200_10p*tptzm1200lh_10p->GetBinContent(j)));}else{tptzm1200lh_10p->SetBinError(j,0);}
    if(tptzm1200lh_20p->GetBinContent(j)>0){tptzm1200lh_20p->SetBinError(j,sqrt(w1200_20p*w1200_20p*tptzm1200lh_20p->GetBinContent(j)));}else{tptzm1200lh_20p->SetBinError(j,0);}
    if(tptzm1200lh_30p->GetBinContent(j)>0){tptzm1200lh_30p->SetBinError(j,sqrt(w1200_30p*w1200_30p*tptzm1200lh_30p->GetBinContent(j)));}else{tptzm1200lh_30p->SetBinError(j,0);}
    if(tptzm1300lh->GetBinContent(j)>0){tptzm1300lh->SetBinError(j,sqrt(w1300*w1300*tptzm1300lh->GetBinContent(j)));}else{tptzm1300lh->SetBinError(j,0);}
    if(tptzm1300lh_10p->GetBinContent(j)>0){tptzm1300lh_10p->SetBinError(j,sqrt(w1300_10p*w1300_10p*tptzm1300lh_10p->GetBinContent(j)));}else{tptzm1300lh_10p->SetBinError(j,0);}
    if(tptzm1400lh->GetBinContent(j)>0){tptzm1400lh->SetBinError(j,sqrt(w1400*w1400*tptzm1400lh->GetBinContent(j)));}else{tptzm1400lh->SetBinError(j,0);}
    if(tptzm1400lh_10p->GetBinContent(j)>0){tptzm1400lh_10p->SetBinError(j,sqrt(w1400_10p*w1400_10p*tptzm1400lh_10p->GetBinContent(j)));}else{tptzm1400lh_10p->SetBinError(j,0);}
    if(tptzm1400lh_20p->GetBinContent(j)>0){tptzm1400lh_20p->SetBinError(j,sqrt(w1400_20p*w1400_20p*tptzm1400lh_20p->GetBinContent(j)));}else{tptzm1400lh_20p->SetBinError(j,0);}
    if(tptzm1400lh_30p->GetBinContent(j)>0){tptzm1400lh_30p->SetBinError(j,sqrt(w1400_30p*w1400_30p*tptzm1400lh_30p->GetBinContent(j)));}else{tptzm1400lh_30p->SetBinError(j,0);}
    if(tptzm1500lh->GetBinContent(j)>0){tptzm1500lh->SetBinError(j,sqrt(w1500*w1500*tptzm1500lh->GetBinContent(j)));}else{tptzm1500lh->SetBinError(j,0);}
    if(tptzm1500lh_10p->GetBinContent(j)>0){tptzm1500lh_10p->SetBinError(j,sqrt(w1500_10p*w1500_10p*tptzm1500lh_10p->GetBinContent(j)));}else{tptzm1500lh_10p->SetBinError(j,0);}
    if(tptzm1600lh->GetBinContent(j)>0){tptzm1600lh->SetBinError(j,sqrt(w1600*w1600*tptzm1600lh->GetBinContent(j)));}else{tptzm1600lh->SetBinError(j,0);}
    if(tptzm1600lh_10p->GetBinContent(j)>0){tptzm1600lh_10p->SetBinError(j,sqrt(w1600_10p*w1600_10p*tptzm1600lh_10p->GetBinContent(j)));}else{tptzm1600lh_10p->SetBinError(j,0);}
    if(tptzm1600lh_20p->GetBinContent(j)>0){tptzm1600lh_20p->SetBinError(j,sqrt(w1600_20p*w1600_20p*tptzm1600lh_20p->GetBinContent(j)));}else{tptzm1600lh_20p->SetBinError(j,0);}
    if(tptzm1600lh_30p->GetBinContent(j)>0){tptzm1600lh_30p->SetBinError(j,sqrt(w1600_30p*w1600_30p*tptzm1600lh_30p->GetBinContent(j)));}else{tptzm1600lh_30p->SetBinError(j,0);}
    if(tptzm1700lh->GetBinContent(j)>0){tptzm1700lh->SetBinError(j,sqrt(w1700*w1700*tptzm1700lh->GetBinContent(j)));}else{tptzm1700lh->SetBinError(j,0);}
    if(tptzm1700lh_10p->GetBinContent(j)>0){tptzm1700lh_10p->SetBinError(j,sqrt(w1700_10p*w1700_10p*tptzm1700lh_10p->GetBinContent(j)));}else{tptzm1700lh_10p->SetBinError(j,0);}
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
  if(ttW->GetBinContent(j)>0){ttW->SetBinError(j,sqrt(w36*w36*ttW->GetBinContent(j)));}else{ttW->SetBinError(j,0);}//w36);}
  if(ttZ->GetBinContent(j)>0){ttZ->SetBinError(j,sqrt(w37*w37*ttZ->GetBinContent(j)));}else{ttZ->SetBinError(j,0);}//w37);}
  if(tZq->GetBinContent(j)>0){tZq->SetBinError(j,sqrt(w38*w38*tZq->GetBinContent(j)));}else{tZq->SetBinError(j,0);}//w38);}
  if(ZZ4->GetBinContent(j)>0){ZZ4->SetBinError(j,sqrt(w39*w39*ZZ4->GetBinContent(j)));}else{ZZ4->SetBinError(j,0);}//w39);}
  if(WZ4->GetBinContent(j)>0){WZ4->SetBinError(j,sqrt(w40*w40*WZ4->GetBinContent(j)));}else{WZ4->SetBinError(j,0);}//w40);}

  double N_tptzm0600lh_err = tptzm0600lh->GetBinError(j)*tptzm0600lh->GetBinError(j);
  double N_tptzm0700lh_err = tptzm0700lh->GetBinError(j)*tptzm0700lh->GetBinError(j);
  double N_tptzm0700lh_10p_err = tptzm0700lh_10p->GetBinError(j)*tptzm0700lh_10p->GetBinError(j);
  double N_tptzm0800lh_err = tptzm0800lh->GetBinError(j)*tptzm0800lh->GetBinError(j);
  double N_tptzm0800lh_10p_err = tptzm0800lh_10p->GetBinError(j)*tptzm0800lh_10p->GetBinError(j);
  double N_tptzm0800lh_20p_err = tptzm0800lh_20p->GetBinError(j)*tptzm0800lh_20p->GetBinError(j);
  double N_tptzm0800lh_30p_err = tptzm0800lh_30p->GetBinError(j)*tptzm0800lh_30p->GetBinError(j);
  double N_tptzm0900lh_err = tptzm0900lh->GetBinError(j)*tptzm0900lh->GetBinError(j);
  double N_tptzm0900lh_10p_err = tptzm0900lh_10p->GetBinError(j)*tptzm0900lh_10p->GetBinError(j);
  double N_tptzm1000lh_err = tptzm1000lh->GetBinError(j)*tptzm1000lh->GetBinError(j);
  double N_tptzm1000lh_10p_err = tptzm1000lh_10p->GetBinError(j)*tptzm1000lh_10p->GetBinError(j);
  double N_tptzm1000lh_20p_err = tptzm1000lh_20p->GetBinError(j)*tptzm1000lh_20p->GetBinError(j);
  double N_tptzm1000lh_30p_err = tptzm1000lh_30p->GetBinError(j)*tptzm1000lh_30p->GetBinError(j);
  double N_tptzm1100lh_err = tptzm1100lh->GetBinError(j)*tptzm1100lh->GetBinError(j);
  double N_tptzm1100lh_10p_err = tptzm1100lh_10p->GetBinError(j)*tptzm1100lh_10p->GetBinError(j);
  double N_tptzm1200lh_err = tptzm1200lh->GetBinError(j)*tptzm1200lh->GetBinError(j);
  double N_tptzm1200lh_10p_err = tptzm1200lh_10p->GetBinError(j)*tptzm1200lh_10p->GetBinError(j);
  double N_tptzm1200lh_20p_err = tptzm1200lh_20p->GetBinError(j)*tptzm1200lh_20p->GetBinError(j);
  double N_tptzm1200lh_30p_err = tptzm1200lh_30p->GetBinError(j)*tptzm1200lh_30p->GetBinError(j);
  double N_tptzm1300lh_err = tptzm1300lh->GetBinError(j)*tptzm1300lh->GetBinError(j);
  double N_tptzm1300lh_10p_err = tptzm1300lh_10p->GetBinError(j)*tptzm1300lh_10p->GetBinError(j);
  double N_tptzm1400lh_err = tptzm1400lh->GetBinError(j)*tptzm1400lh->GetBinError(j);
  double N_tptzm1400lh_10p_err = tptzm1400lh_10p->GetBinError(j)*tptzm1400lh_10p->GetBinError(j);
  double N_tptzm1400lh_20p_err = tptzm1400lh_20p->GetBinError(j)*tptzm1400lh_20p->GetBinError(j);
  double N_tptzm1400lh_30p_err = tptzm1400lh_30p->GetBinError(j)*tptzm1400lh_30p->GetBinError(j);
  double N_tptzm1500lh_err = tptzm1500lh->GetBinError(j)*tptzm1500lh->GetBinError(j);
  double N_tptzm1500lh_10p_err = tptzm1500lh_10p->GetBinError(j)*tptzm1500lh_10p->GetBinError(j);
  double N_tptzm1600lh_err = tptzm1600lh->GetBinError(j)*tptzm1600lh->GetBinError(j);
  double N_tptzm1600lh_10p_err = tptzm1600lh_10p->GetBinError(j)*tptzm1600lh_10p->GetBinError(j);
  double N_tptzm1600lh_20p_err = tptzm1600lh_20p->GetBinError(j)*tptzm1600lh_20p->GetBinError(j);
  double N_tptzm1600lh_30p_err = tptzm1600lh_30p->GetBinError(j)*tptzm1600lh_30p->GetBinError(j);
  double N_tptzm1700lh_err = tptzm1700lh->GetBinError(j)*tptzm1700lh->GetBinError(j);
  double N_tptzm1700lh_10p_err = tptzm1700lh_10p->GetBinError(j)*tptzm1700lh_10p->GetBinError(j);
  double N_tptzm1800lh_err = tptzm1800lh->GetBinError(j)*tptzm1800lh->GetBinError(j);

  double N_data_err    = data->GetBinError(j)*data->GetBinError(j);
  double N_ZToNuNu_err = ZToNuNu_1->GetBinError(j)*ZToNuNu_1->GetBinError(j) + ZToNuNu_2->GetBinError(j)*ZToNuNu_2->GetBinError(j) + ZToNuNu_3->GetBinError(j)*ZToNuNu_3->GetBinError(j) + ZToNuNu_4->GetBinError(j)*ZToNuNu_4->GetBinError(j) + ZToNuNu_5->GetBinError(j)*ZToNuNu_5->GetBinError(j) + ZToNuNu_6->GetBinError(j)*ZToNuNu_6->GetBinError(j) + ZToNuNu_7->GetBinError(j)*ZToNuNu_7->GetBinError(j);
  double N_QCD_err     = QCD_1->GetBinError(j)*QCD_1->GetBinError(j) + QCD_2->GetBinError(j)*QCD_2->GetBinError(j) + QCD_3->GetBinError(j)*QCD_3->GetBinError(j) + QCD_4->GetBinError(j)*QCD_4->GetBinError(j) + QCD_5->GetBinError(j)*QCD_5->GetBinError(j) + QCD_6->GetBinError(j)*QCD_6->GetBinError(j) + QCD_7->GetBinError(j)*QCD_7->GetBinError(j);
  double N_WToLNu_err  = WToLNu_1->GetBinError(j)*WToLNu_1->GetBinError(j)+WToLNu_2->GetBinError(j)*WToLNu_2->GetBinError(j)+WToLNu_3->GetBinError(j)*WToLNu_3->GetBinError(j)+WToLNu_4->GetBinError(j)*WToLNu_4->GetBinError(j)+WToLNu_5->GetBinError(j)*WToLNu_5->GetBinError(j)+WToLNu_6->GetBinError(j)*WToLNu_6->GetBinError(j)+WToLNu_7->GetBinError(j)*WToLNu_7->GetBinError(j);
  double N_TT_err      = TT_1->GetBinError(j)*TT_1->GetBinError(j)+TT_2->GetBinError(j)*TT_2->GetBinError(j);
  double N_ST_err      = ST_1->GetBinError(j)*ST_1->GetBinError(j) + ST_2->GetBinError(j)*ST_2->GetBinError(j)+ ST_3->GetBinError(j)*ST_3->GetBinError(j)+ ST_4->GetBinError(j)*ST_4->GetBinError(j);
  double N_VV_err      = ZZ1->GetBinError(j)*ZZ1->GetBinError(j) + ZZ2->GetBinError(j)*ZZ2->GetBinError(j) + ZZ3->GetBinError(j)*ZZ3->GetBinError(j) + ZZ4->GetBinError(j)*ZZ4->GetBinError(j) + WW1->GetBinError(j)*WW1->GetBinError(j) + WW2->GetBinError(j)*WW2->GetBinError(j) + WZ1->GetBinError(j)*WZ1->GetBinError(j) + WZ2->GetBinError(j)*WZ2->GetBinError(j) + WZ3->GetBinError(j)*WZ3->GetBinError(j) + WZ4->GetBinError(j)*WZ4->GetBinError(j); 
  double N_ttV_err     = ttW->GetBinError(j)*ttW->GetBinError(j) + ttZ->GetBinError(j)*ttZ->GetBinError(j) + tZq->GetBinError(j)*tZq->GetBinError(j);

  tptzm0600lh->SetBinContent(j,w0600*tptzm0600lh->GetBinContent(j));
  tptzm0700lh->SetBinContent(j,w0700*tptzm0700lh->GetBinContent(j));
  tptzm0700lh_10p->SetBinContent(j,w0700_10p*tptzm0700lh_10p->GetBinContent(j));
  tptzm0800lh->SetBinContent(j,w0800*tptzm0800lh->GetBinContent(j));
  tptzm0800lh_10p->SetBinContent(j,w0800_10p*tptzm0800lh_10p->GetBinContent(j));
  tptzm0800lh_20p->SetBinContent(j,w0800_20p*tptzm0800lh_20p->GetBinContent(j));
  tptzm0800lh_30p->SetBinContent(j,w0800_30p*tptzm0800lh_30p->GetBinContent(j));
  tptzm0900lh->SetBinContent(j,w0900*tptzm0900lh->GetBinContent(j));
  tptzm0900lh_10p->SetBinContent(j,w0900_10p*tptzm0900lh_10p->GetBinContent(j));
  tptzm1000lh->SetBinContent(j,w1000*tptzm1000lh->GetBinContent(j));
  tptzm1000lh_10p->SetBinContent(j,w1000_10p*tptzm1000lh_10p->GetBinContent(j));
  tptzm1000lh_20p->SetBinContent(j,w1000_20p*tptzm1000lh_20p->GetBinContent(j));
  tptzm1000lh_30p->SetBinContent(j,w1000_30p*tptzm1000lh_30p->GetBinContent(j));
  tptzm1100lh->SetBinContent(j,w1100*tptzm1100lh->GetBinContent(j));
  tptzm1100lh_10p->SetBinContent(j,w1100_10p*tptzm1100lh_10p->GetBinContent(j));
  tptzm1200lh->SetBinContent(j,w1200*tptzm1200lh->GetBinContent(j));
  tptzm1200lh_10p->SetBinContent(j,w1200_10p*tptzm1200lh_10p->GetBinContent(j));
  tptzm1200lh_20p->SetBinContent(j,w1200_20p*tptzm1200lh_20p->GetBinContent(j));
  tptzm1200lh_30p->SetBinContent(j,w1200_30p*tptzm1200lh_30p->GetBinContent(j));
  tptzm1300lh->SetBinContent(j,w1300*tptzm1300lh->GetBinContent(j));
  tptzm1300lh_10p->SetBinContent(j,w1300_10p*tptzm1300lh_10p->GetBinContent(j));
  tptzm1400lh->SetBinContent(j,w1400*tptzm1400lh->GetBinContent(j));
  tptzm1400lh_10p->SetBinContent(j,w1400_10p*tptzm1400lh_10p->GetBinContent(j));
  tptzm1400lh_20p->SetBinContent(j,w1400_20p*tptzm1400lh_20p->GetBinContent(j));
  tptzm1400lh_30p->SetBinContent(j,w1400_30p*tptzm1400lh_30p->GetBinContent(j));
  tptzm1500lh->SetBinContent(j,w1500*tptzm1500lh->GetBinContent(j));
  tptzm1500lh_10p->SetBinContent(j,w1500_10p*tptzm1500lh_10p->GetBinContent(j));
  tptzm1600lh->SetBinContent(j,w1600*tptzm1600lh->GetBinContent(j));
  tptzm1600lh_10p->SetBinContent(j,w1600_10p*tptzm1600lh_10p->GetBinContent(j));
  tptzm1600lh_20p->SetBinContent(j,w1600_20p*tptzm1600lh_20p->GetBinContent(j));
  tptzm1600lh_30p->SetBinContent(j,w1600_30p*tptzm1600lh_30p->GetBinContent(j));
  tptzm1700lh->SetBinContent(j,w1700*tptzm1700lh->GetBinContent(j));
  tptzm1700lh_10p->SetBinContent(j,w1700_10p*tptzm1700lh_10p->GetBinContent(j));
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
  ttW->SetBinContent(j,w36*ttW->GetBinContent(j));
  ttZ->SetBinContent(j,w37*ttZ->GetBinContent(j));
  tZq->SetBinContent(j,w38*tZq->GetBinContent(j));
  ZZ4->SetBinContent(j,w39*ZZ4->GetBinContent(j));
  WZ4->SetBinContent(j,w40*WZ4->GetBinContent(j));

  double N_tptzm0600lh = tptzm0600lh->GetBinContent(j);
  double N_tptzm0700lh = tptzm0700lh->GetBinContent(j);
  double N_tptzm0700lh_10p = tptzm0700lh_10p->GetBinContent(j);
  double N_tptzm0800lh = tptzm0800lh->GetBinContent(j);
  double N_tptzm0800lh_10p = tptzm0800lh_10p->GetBinContent(j);
  double N_tptzm0800lh_20p = tptzm0800lh_20p->GetBinContent(j);
  double N_tptzm0800lh_30p = tptzm0800lh_30p->GetBinContent(j);
  double N_tptzm0900lh = tptzm0900lh->GetBinContent(j);
  double N_tptzm0900lh_10p = tptzm0900lh_10p->GetBinContent(j);
  double N_tptzm1000lh = tptzm1000lh->GetBinContent(j);
  double N_tptzm1000lh_10p = tptzm1000lh_10p->GetBinContent(j);
  double N_tptzm1000lh_20p = tptzm1000lh_20p->GetBinContent(j);
  double N_tptzm1000lh_30p = tptzm1000lh_30p->GetBinContent(j);
  double N_tptzm1100lh = tptzm1100lh->GetBinContent(j);
  double N_tptzm1100lh_10p = tptzm1100lh_10p->GetBinContent(j);
  double N_tptzm1200lh = tptzm1200lh->GetBinContent(j);
  double N_tptzm1200lh_10p = tptzm1200lh_10p->GetBinContent(j);
  double N_tptzm1200lh_20p = tptzm1200lh_20p->GetBinContent(j);
  double N_tptzm1200lh_30p = tptzm1200lh_30p->GetBinContent(j);
  double N_tptzm1300lh = tptzm1300lh->GetBinContent(j);
  double N_tptzm1300lh_10p = tptzm1300lh_10p->GetBinContent(j);
  double N_tptzm1400lh = tptzm1400lh->GetBinContent(j);
  double N_tptzm1400lh_10p = tptzm1400lh_10p->GetBinContent(j);
  double N_tptzm1400lh_20p = tptzm1400lh_20p->GetBinContent(j);
  double N_tptzm1400lh_30p = tptzm1400lh_30p->GetBinContent(j);
  double N_tptzm1500lh = tptzm1500lh->GetBinContent(j);
  double N_tptzm1500lh_10p = tptzm1500lh_10p->GetBinContent(j);
  double N_tptzm1600lh = tptzm1600lh->GetBinContent(j);
  double N_tptzm1600lh_10p = tptzm1600lh_10p->GetBinContent(j);
  double N_tptzm1600lh_20p = tptzm1600lh_20p->GetBinContent(j);
  double N_tptzm1600lh_30p = tptzm1600lh_30p->GetBinContent(j);
  double N_tptzm1700lh = tptzm1700lh->GetBinContent(j);
  double N_tptzm1700lh_10p = tptzm1700lh_10p->GetBinContent(j);
  double N_tptzm1800lh = tptzm1800lh->GetBinContent(j);
  double N_data    = data->GetBinContent(j);
  double N_ZToNuNu = ZToNuNu_1->GetBinContent(j) + ZToNuNu_2->GetBinContent(j) + ZToNuNu_3->GetBinContent(j) + ZToNuNu_4->GetBinContent(j) + ZToNuNu_5->GetBinContent(j) + ZToNuNu_6->GetBinContent(j) + ZToNuNu_7->GetBinContent(j);
  double N_QCD     = QCD_1->GetBinContent(j) + QCD_2->GetBinContent(j) + QCD_3->GetBinContent(j) + QCD_4->GetBinContent(j) + QCD_5->GetBinContent(j) + QCD_6->GetBinContent(j) + QCD_7->GetBinContent(j);
  double N_WToLNu  = WToLNu_1->GetBinContent(j) + WToLNu_2->GetBinContent(j) + WToLNu_3->GetBinContent(j) + WToLNu_4->GetBinContent(j) + WToLNu_5->GetBinContent(j) + WToLNu_6->GetBinContent(j)+ WToLNu_7->GetBinContent(j);
  double N_TT      = TT_1->GetBinContent(j) + TT_2->GetBinContent(j);
  double N_ST      = ST_1 ->GetBinContent(j) + ST_2 ->GetBinContent(j) + ST_3 ->GetBinContent(j) + ST_4 ->GetBinContent(j);
  double N_VV      = ZZ1->GetBinContent(j)+ZZ2->GetBinContent(j)+ZZ3->GetBinContent(j)+ZZ4->GetBinContent(j)+WW1->GetBinContent(j)+WW2->GetBinContent(j)+WZ1->GetBinContent(j)+WZ2->GetBinContent(j)+WZ3->GetBinContent(j)+WZ4->GetBinContent(j);
  double N_ttV     = ttW->GetBinContent(j) + ttZ->GetBinContent(j) + tZq->GetBinContent(j);

  data_func->SetBinError(j,sqrt(N_data_err));
  data_func->SetBinContent(j,N_data);    
  tptzm0600lh_func->SetBinError(j,sqrt(N_tptzm0600lh_err));
  tptzm0700lh_func->SetBinError(j,sqrt(N_tptzm0700lh_err));
  tptzm0700lh_10p_func->SetBinError(j,sqrt(N_tptzm0700lh_10p_err));
  tptzm0800lh_func->SetBinError(j,sqrt(N_tptzm0800lh_err));
  tptzm0800lh_10p_func->SetBinError(j,sqrt(N_tptzm0800lh_10p_err));
  tptzm0800lh_20p_func->SetBinError(j,sqrt(N_tptzm0800lh_20p_err));
  tptzm0800lh_30p_func->SetBinError(j,sqrt(N_tptzm0800lh_30p_err));
  tptzm0900lh_func->SetBinError(j,sqrt(N_tptzm0900lh_err));
  tptzm0900lh_10p_func->SetBinError(j,sqrt(N_tptzm0900lh_10p_err));
  tptzm1000lh_func->SetBinError(j,sqrt(N_tptzm1000lh_err));
  tptzm1000lh_10p_func->SetBinError(j,sqrt(N_tptzm1000lh_10p_err));
  tptzm1000lh_20p_func->SetBinError(j,sqrt(N_tptzm1000lh_20p_err));
  tptzm1000lh_30p_func->SetBinError(j,sqrt(N_tptzm1000lh_30p_err));
  tptzm1100lh_func->SetBinError(j,sqrt(N_tptzm1100lh_err));
  tptzm1100lh_10p_func->SetBinError(j,sqrt(N_tptzm1100lh_10p_err));
  tptzm1200lh_func->SetBinError(j,sqrt(N_tptzm1200lh_err));
  tptzm1200lh_10p_func->SetBinError(j,sqrt(N_tptzm1200lh_10p_err));
  tptzm1200lh_20p_func->SetBinError(j,sqrt(N_tptzm1200lh_20p_err));
  tptzm1200lh_30p_func->SetBinError(j,sqrt(N_tptzm1200lh_30p_err));
  tptzm1300lh_func->SetBinError(j,sqrt(N_tptzm1300lh_err));
  tptzm1300lh_10p_func->SetBinError(j,sqrt(N_tptzm1300lh_10p_err));
  tptzm1400lh_func->SetBinError(j,sqrt(N_tptzm1400lh_err));
  tptzm1400lh_10p_func->SetBinError(j,sqrt(N_tptzm1400lh_10p_err));
  tptzm1400lh_20p_func->SetBinError(j,sqrt(N_tptzm1400lh_20p_err));
  tptzm1400lh_30p_func->SetBinError(j,sqrt(N_tptzm1400lh_30p_err));
  tptzm1500lh_func->SetBinError(j,sqrt(N_tptzm1500lh_err));
  tptzm1500lh_10p_func->SetBinError(j,sqrt(N_tptzm1500lh_10p_err));
  tptzm1600lh_func->SetBinError(j,sqrt(N_tptzm1600lh_err));
  tptzm1600lh_10p_func->SetBinError(j,sqrt(N_tptzm1600lh_10p_err));
  tptzm1600lh_20p_func->SetBinError(j,sqrt(N_tptzm1600lh_20p_err));
  tptzm1600lh_30p_func->SetBinError(j,sqrt(N_tptzm1600lh_30p_err));
  tptzm1700lh_func->SetBinError(j,sqrt(N_tptzm1700lh_err));
  tptzm1700lh_10p_func->SetBinError(j,sqrt(N_tptzm1700lh_10p_err));
  tptzm1800lh_func->SetBinError(j,sqrt(N_tptzm1800lh_err));
  tptzm0600lh_func->SetBinContent(j,N_tptzm0600lh);
  tptzm0700lh_func->SetBinContent(j,N_tptzm0700lh);
  tptzm0700lh_10p_func->SetBinContent(j,N_tptzm0700lh_10p);
  tptzm0800lh_func->SetBinContent(j,N_tptzm0800lh);
  tptzm0800lh_10p_func->SetBinContent(j,N_tptzm0800lh_10p);
  tptzm0800lh_20p_func->SetBinContent(j,N_tptzm0800lh_20p);
  tptzm0800lh_30p_func->SetBinContent(j,N_tptzm0800lh_30p);
  tptzm0900lh_func->SetBinContent(j,N_tptzm0900lh);
  tptzm0900lh_10p_func->SetBinContent(j,N_tptzm0900lh_10p);
  tptzm1000lh_func->SetBinContent(j,N_tptzm1000lh);
  tptzm1000lh_10p_func->SetBinContent(j,N_tptzm1000lh_10p);
  tptzm1000lh_20p_func->SetBinContent(j,N_tptzm1000lh_20p);
  tptzm1000lh_30p_func->SetBinContent(j,N_tptzm1000lh_30p);
  tptzm1100lh_func->SetBinContent(j,N_tptzm1100lh);
  tptzm1100lh_10p_func->SetBinContent(j,N_tptzm1100lh_10p);
  tptzm1200lh_func->SetBinContent(j,N_tptzm1200lh);
  tptzm1200lh_10p_func->SetBinContent(j,N_tptzm1200lh_10p);
  tptzm1200lh_20p_func->SetBinContent(j,N_tptzm1200lh_20p);
  tptzm1200lh_30p_func->SetBinContent(j,N_tptzm1200lh_30p);
  tptzm1300lh_func->SetBinContent(j,N_tptzm1300lh);
  tptzm1300lh_10p_func->SetBinContent(j,N_tptzm1300lh_10p);
  tptzm1400lh_func->SetBinContent(j,N_tptzm1400lh);
  tptzm1400lh_10p_func->SetBinContent(j,N_tptzm1400lh_10p);
  tptzm1400lh_20p_func->SetBinContent(j,N_tptzm1400lh_20p);
  tptzm1400lh_30p_func->SetBinContent(j,N_tptzm1400lh_30p);
  tptzm1500lh_func->SetBinContent(j,N_tptzm1500lh);
  tptzm1500lh_10p_func->SetBinContent(j,N_tptzm1500lh_10p);
  tptzm1600lh_func->SetBinContent(j,N_tptzm1600lh);
  tptzm1600lh_10p_func->SetBinContent(j,N_tptzm1600lh_10p);
  tptzm1600lh_20p_func->SetBinContent(j,N_tptzm1600lh_20p);
  tptzm1600lh_30p_func->SetBinContent(j,N_tptzm1600lh_30p);
  tptzm1700lh_func->SetBinContent(j,N_tptzm1700lh);
  tptzm1700lh_10p_func->SetBinContent(j,N_tptzm1700lh_10p);
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
  ttV_func->SetBinError(j,sqrt(N_ttV_err));
  ttV_func->SetBinContent(j,N_ttV);
  background_func->SetBinError(j,sqrt(N_ZToNuNu_err+N_QCD_err+N_WToLNu_err+N_TT_err+N_ST_err+N_VV_err+N_ttV_err));
  background_func->SetBinContent(j,N_ZToNuNu+N_QCD+N_WToLNu+N_TT+N_ST+N_VV+N_ttV);

  }

delete data; delete tptzm0600lh; delete tptzm0700lh; delete tptzm0800lh; delete tptzm0900lh; delete tptzm1000lh; delete tptzm1100lh; delete tptzm1200lh; delete tptzm1300lh; delete tptzm1400lh; delete tptzm1500lh; delete tptzm1600lh; delete tptzm1700lh; delete tptzm1800lh;
delete tptzm0700lh_10p;  delete tptzm0800lh_10p;  delete tptzm0800lh_20p;  delete tptzm0800lh_30p;  delete tptzm0900lh_10p;  delete tptzm1000lh_10p;  delete tptzm1000lh_20p;  delete tptzm1000lh_30p;  delete tptzm1100lh_10p;  delete tptzm1200lh_10p;  delete tptzm1200lh_20p;  delete tptzm1200lh_30p;  delete tptzm1300lh_10p;  delete tptzm1400lh_10p;  delete tptzm1400lh_20p;  delete tptzm1400lh_30p;  delete tptzm1500lh_10p;  delete tptzm1600lh_10p;  delete tptzm1600lh_20p;  delete tptzm1600lh_30p;  delete tptzm1700lh_10p; 
delete ZToNuNu_1; delete ZToNuNu_2; delete ZToNuNu_3; delete ZToNuNu_4;  delete ZToNuNu_5;  delete ZToNuNu_6;  delete ZToNuNu_7;
delete QCD_1; delete QCD_2; delete QCD_3; delete QCD_4; delete QCD_5; delete QCD_6; delete QCD_7; 
delete WToLNu_1; delete WToLNu_2; delete WToLNu_3; delete WToLNu_4; delete WToLNu_5; delete WToLNu_6; delete WToLNu_7; 
delete TT_1; delete TT_2; 
delete ST_1; delete ST_2;  delete ST_3; delete ST_4;  
delete WW1; delete WW2; delete WZ1; delete WZ2; delete WZ3; delete WZ4; delete ZZ1; delete ZZ2;  delete ZZ3; delete ZZ4;
delete ttW; delete ttZ; delete tZq;
}


void MakeHistoErrors(TH1F* &histo_SR, TH1F* histo_Z1, TH1F* histo_Z2, TH1F* histo_W1, TH1F* histo_W2, TH1F* histo_T1, TH1F* histo_T2,  TH1F* histo_P1, TH1F* histo_P2, TH1F* histo_F1, TH1F* histo_F2, TH1F* histo_B1, TH1F* histo_B2, TH1F* histo_J1, TH1F* histo_J2, TH1F* histo_J3, TH1F* histo_J4, TH1F* histo_QCD1, TH1F* histo_QCD2, TH1F* histo_PDF1, TH1F* histo_PDF2, TH1F* histo_TRI1, TH1F* histo_TRI2){
  for(int m=1; m<histo_SR->GetNbinsX()+1; m++){
    float ErrMc = histo_SR->GetBinError(m); 
    float ErrZJ = max(fabs(histo_SR->GetBinContent(m)-histo_Z1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_Z2->GetBinContent(m)));
    float ErrWT = max(fabs(histo_SR->GetBinContent(m)-histo_W1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_W2->GetBinContent(m)));
    float ErrTT = max(fabs(histo_SR->GetBinContent(m)-histo_T1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_T2->GetBinContent(m)));
    float ErrPU = max(fabs(histo_SR->GetBinContent(m)-histo_P1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_P2->GetBinContent(m)));
    float ErrFO = max(fabs(histo_SR->GetBinContent(m)-histo_F1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_F2->GetBinContent(m)));
    float ErrBT = max(fabs(histo_SR->GetBinContent(m)-histo_B1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_B2->GetBinContent(m))); 
    float ErrTR = max(fabs(histo_SR->GetBinContent(m)-histo_TRI1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_TRI2->GetBinContent(m))); 
    float ErrJS = max(fabs(histo_SR->GetBinContent(m)-histo_J1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_J2->GetBinContent(m))); 
    float ErrJR = max(fabs(histo_SR->GetBinContent(m)-histo_J3->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_J4->GetBinContent(m))); 
    float ErrQC = max(fabs(histo_SR->GetBinContent(m)-histo_QCD1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_QCD2->GetBinContent(m))); 
    float ErrPD = max(fabs(histo_SR->GetBinContent(m)-histo_PDF1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_PDF2->GetBinContent(m))); 
    float TOTAL = sqrt(ErrMc*ErrMc + ErrZJ*ErrZJ + ErrWT*ErrWT + ErrTT*ErrTT + + ErrPU*ErrPU + ErrBT*ErrBT + ErrTR*ErrTR + ErrFO*ErrFO + ErrJS*ErrJS + ErrJR*ErrJR + ErrQC*ErrQC + ErrPD*ErrPD );
    //cout<<m<<" "<<histo_SR->GetBinContent(m)<<" "<<ErrMc<<" "<<ErrBT<<" "<<ErrJS<<" "<<ErrQC<<" "<<endl;
    histo_SR ->SetBinError(m,TOTAL);
  }
}

void MakeHistoErrorsMC(TH1F* &histo_SR,  TH1F* histo_P1, TH1F* histo_P2, TH1F* histo_F1, TH1F* histo_F2, TH1F* histo_B1, TH1F* histo_B2, TH1F* histo_J1, TH1F* histo_J2, TH1F* histo_J3, TH1F* histo_J4, TH1F* histo_QCD1, TH1F* histo_QCD2, TH1F* histo_PDF1, TH1F* histo_PDF2, TH1F* histo_TRI1, TH1F* histo_TRI2){
  for(int m=1; m<histo_SR->GetNbinsX()+1; m++){
    float ErrMc = histo_SR->GetBinError(m); 
    //float ErrLU = 0.026*histo_SR->GetBinContent(m);
    float ErrPU = max(fabs(histo_SR->GetBinContent(m)-histo_P1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_P2->GetBinContent(m)));
    float ErrFO = max(fabs(histo_SR->GetBinContent(m)-histo_F1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_F2->GetBinContent(m)));
    float ErrBT = max(fabs(histo_SR->GetBinContent(m)-histo_B1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_B2->GetBinContent(m))); 
    float ErrTR = max(fabs(histo_SR->GetBinContent(m)-histo_TRI1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_TRI2->GetBinContent(m))); 
    float ErrJS = max(fabs(histo_SR->GetBinContent(m)-histo_J1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_J2->GetBinContent(m))); 
    float ErrJR = max(fabs(histo_SR->GetBinContent(m)-histo_J3->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_J4->GetBinContent(m))); 
    float ErrQC = max(fabs(histo_SR->GetBinContent(m)-histo_QCD1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_QCD2->GetBinContent(m))); 
    float ErrPD = max(fabs(histo_SR->GetBinContent(m)-histo_PDF1->GetBinContent(m)),fabs(histo_SR->GetBinContent(m)-histo_PDF2->GetBinContent(m))); 
    float TOTAL = sqrt(ErrMc*ErrMc + ErrPU*ErrPU + ErrBT*ErrBT + ErrTR*ErrTR + ErrFO*ErrFO + ErrJS*ErrJS + ErrJR*ErrJR + ErrQC*ErrQC + ErrPD*ErrPD );
    //cout<<m<<" "<<histo_SR->GetBinContent(m)<<" "<<ErrMc<<" "<<ErrBT<<" "<<ErrJS<<" "<<ErrQC<<" "<<endl;
    histo_SR ->SetBinError(m,TOTAL);
  }
}


void CloneHistos(){
	tptzm0600lh_pup1 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_pup1 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_pup1 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_pup1 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_pup1 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_pup1 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_pup1 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_pup1 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_pup1 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_pup1 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_pup1 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_pup1 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_pup1 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_pup1 = (TH1F*)ZToNuNu->Clone(); QCD_pup1 = (TH1F*)QCD->Clone(); WToLNu_pup1 = (TH1F*)WToLNu->Clone(); TT_pup1 = (TH1F*)TT->Clone(); VV_pup1 = (TH1F*)VV->Clone(); ttV_pup1 = (TH1F*)ttV->Clone(); 
	data_pup1 = (TH1F*)data->Clone(); 

	tptzm0600lh_pup2 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_pup2 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_pup2 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_pup2 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_pup2 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_pup2 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_pup2 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_pup2 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_pup2 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_pup2 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_pup2 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_pup2 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_pup2 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_pup2 = (TH1F*)ZToNuNu->Clone(); QCD_pup2 = (TH1F*)QCD->Clone(); WToLNu_pup2 = (TH1F*)WToLNu->Clone(); TT_pup2 = (TH1F*)TT->Clone(); VV_pup2 = (TH1F*)VV->Clone(); ttV_pup2 = (TH1F*)ttV->Clone(); 
	data_pup2 = (TH1F*)data->Clone();

	tptzm0600lh_fir1 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_fir1 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_fir1 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_fir1 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_fir1 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_fir1 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_fir1 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_fir1 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_fir1 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_fir1 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_fir1 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_fir1 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_fir1 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_fir1 = (TH1F*)ZToNuNu->Clone(); QCD_fir1 = (TH1F*)QCD->Clone(); WToLNu_fir1 = (TH1F*)WToLNu->Clone(); TT_fir1 = (TH1F*)TT->Clone(); VV_fir1 = (TH1F*)VV->Clone(); ttV_fir1 = (TH1F*)ttV->Clone(); 
	data_fir1 = (TH1F*)data->Clone();

	tptzm0600lh_fir2 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_fir2 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_fir2 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_fir2 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_fir2 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_fir2 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_fir2 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_fir2 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_fir2 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_fir2 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_fir2 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_fir2 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_fir2 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_fir2 = (TH1F*)ZToNuNu->Clone(); QCD_fir2 = (TH1F*)QCD->Clone(); WToLNu_fir2 = (TH1F*)WToLNu->Clone(); TT_fir2 = (TH1F*)TT->Clone(); VV_fir2 = (TH1F*)VV->Clone(); ttV_fir2 = (TH1F*)ttV->Clone(); 
	data_fir2 = (TH1F*)data->Clone();

	tptzm0600lh_bta1 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_bta1 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_bta1 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_bta1 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_bta1 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_bta1 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_bta1 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_bta1 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_bta1 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_bta1 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_bta1 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_bta1 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_bta1 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_bta1 = (TH1F*)ZToNuNu->Clone(); QCD_bta1 = (TH1F*)QCD->Clone(); WToLNu_bta1 = (TH1F*)WToLNu->Clone(); TT_bta1 = (TH1F*)TT->Clone(); VV_bta1 = (TH1F*)VV->Clone(); ttV_bta1 = (TH1F*)ttV->Clone(); 
	data_bta1 = (TH1F*)data->Clone();

	tptzm0600lh_bta2 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_bta2 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_bta2 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_bta2 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_bta2 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_bta2 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_bta2 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_bta2 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_bta2 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_bta2 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_bta2 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_bta2 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_bta2 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_bta2 = (TH1F*)ZToNuNu->Clone(); QCD_bta2 = (TH1F*)QCD->Clone(); WToLNu_bta2 = (TH1F*)WToLNu->Clone(); TT_bta2 = (TH1F*)TT->Clone(); VV_bta2 = (TH1F*)VV->Clone(); ttV_bta2 = (TH1F*)ttV->Clone(); 
	data_bta2 = (TH1F*)data->Clone();

	tptzm0600lh_zje1 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_zje1 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_zje1 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_zje1 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_zje1 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_zje1 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_zje1 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_zje1 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_zje1 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_zje1 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_zje1 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_zje1 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_zje1 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_zje1 = (TH1F*)ZToNuNu->Clone(); QCD_zje1 = (TH1F*)QCD->Clone(); WToLNu_zje1 = (TH1F*)WToLNu->Clone(); TT_zje1 = (TH1F*)TT->Clone(); VV_zje1 = (TH1F*)VV->Clone(); ttV_zje1 = (TH1F*)ttV->Clone(); 
	data_zje1 = (TH1F*)data->Clone();

	tptzm0600lh_zje2 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_zje2 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_zje2 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_zje2 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_zje2 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_zje2 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_zje2 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_zje2 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_zje2 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_zje2 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_zje2 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_zje2 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_zje2 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_zje2 = (TH1F*)ZToNuNu->Clone(); QCD_zje2 = (TH1F*)QCD->Clone(); WToLNu_zje2 = (TH1F*)WToLNu->Clone(); TT_zje2 = (TH1F*)TT->Clone(); VV_zje2 = (TH1F*)VV->Clone(); ttV_zje2 = (TH1F*)ttV->Clone(); 
	data_zje2 = (TH1F*)data->Clone();

	tptzm0600lh_wje1 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_wje1 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_wje1 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_wje1 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_wje1 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_wje1 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_wje1 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_wje1 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_wje1 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_wje1 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_wje1 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_wje1 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_wje1 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_wje1 = (TH1F*)ZToNuNu->Clone(); QCD_wje1 = (TH1F*)QCD->Clone(); WToLNu_wje1 = (TH1F*)WToLNu->Clone(); TT_wje1 = (TH1F*)TT->Clone(); VV_wje1 = (TH1F*)VV->Clone(); ttV_wje1 = (TH1F*)ttV->Clone(); 
	data_wje1 = (TH1F*)data->Clone();

	tptzm0600lh_wje2 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_wje2 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_wje2 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_wje2 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_wje2 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_wje2 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_wje2 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_wje2 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_wje2 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_wje2 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_wje2 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_wje2 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_wje2 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_wje2 = (TH1F*)ZToNuNu->Clone(); QCD_wje2 = (TH1F*)QCD->Clone(); WToLNu_wje2 = (TH1F*)WToLNu->Clone(); TT_wje2 = (TH1F*)TT->Clone(); VV_wje2 = (TH1F*)VV->Clone(); ttV_wje2 = (TH1F*)ttV->Clone(); 
	data_wje2 = (TH1F*)data->Clone();

	tptzm0600lh_ttb1 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_ttb1 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_ttb1 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_ttb1 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_ttb1 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_ttb1 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_ttb1 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_ttb1 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_ttb1 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_ttb1 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_ttb1 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_ttb1 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_ttb1 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_ttb1 = (TH1F*)ZToNuNu->Clone(); QCD_ttb1 = (TH1F*)QCD->Clone(); WToLNu_ttb1 = (TH1F*)WToLNu->Clone(); TT_ttb1 = (TH1F*)TT->Clone(); VV_ttb1 = (TH1F*)VV->Clone(); ttV_ttb1 = (TH1F*)ttV->Clone(); 
	data_ttb1 = (TH1F*)data->Clone();

	tptzm0600lh_ttb2 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_ttb2 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_ttb2 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_ttb2 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_ttb2 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_ttb2 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_ttb2 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_ttb2 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_ttb2 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_ttb2 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_ttb2 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_ttb2 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_ttb2 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_ttb2 = (TH1F*)ZToNuNu->Clone(); QCD_ttb2 = (TH1F*)QCD->Clone(); WToLNu_ttb2 = (TH1F*)WToLNu->Clone(); TT_ttb2 = (TH1F*)TT->Clone(); VV_ttb2 = (TH1F*)VV->Clone(); ttV_ttb2 = (TH1F*)ttV->Clone(); 
	data_ttb2 = (TH1F*)data->Clone();

	tptzm0600lh_qcd1 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_qcd1 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_qcd1 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_qcd1 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_qcd1 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_qcd1 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_qcd1 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_qcd1 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_qcd1 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_qcd1 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_qcd1 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_qcd1 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_qcd1 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_qcd1 = (TH1F*)ZToNuNu->Clone(); QCD_qcd1 = (TH1F*)QCD->Clone(); WToLNu_qcd1 = (TH1F*)WToLNu->Clone(); TT_qcd1 = (TH1F*)TT->Clone(); VV_qcd1 = (TH1F*)VV->Clone(); ttV_qcd1 = (TH1F*)ttV->Clone(); 
	data_qcd1 = (TH1F*)data->Clone();

	tptzm0600lh_qcd2 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_qcd2 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_qcd2 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_qcd2 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_qcd2 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_qcd2 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_qcd2 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_qcd2 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_qcd2 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_qcd2 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_qcd2 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_qcd2 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_qcd2 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_qcd2 = (TH1F*)ZToNuNu->Clone(); QCD_qcd2 = (TH1F*)QCD->Clone(); WToLNu_qcd2 = (TH1F*)WToLNu->Clone(); TT_qcd2 = (TH1F*)TT->Clone(); VV_qcd2 = (TH1F*)VV->Clone(); ttV_qcd2 = (TH1F*)ttV->Clone(); 
	data_qcd2 = (TH1F*)data->Clone();

	tptzm0600lh_pdf1 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_pdf1 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_pdf1 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_pdf1 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_pdf1 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_pdf1 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_pdf1 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_pdf1 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_pdf1 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_pdf1 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_pdf1 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_pdf1 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_pdf1 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_pdf1 = (TH1F*)ZToNuNu->Clone(); QCD_pdf1 = (TH1F*)QCD->Clone(); WToLNu_pdf1 = (TH1F*)WToLNu->Clone(); TT_pdf1 = (TH1F*)TT->Clone(); VV_pdf1 = (TH1F*)VV->Clone(); ttV_pdf1 = (TH1F*)ttV->Clone(); 
	data_pdf1 = (TH1F*)data->Clone();

	tptzm0600lh_pdf2 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_pdf2 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_pdf2 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_pdf2 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_pdf2 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_pdf2 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_pdf2 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_pdf2 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_pdf2 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_pdf2 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_pdf2 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_pdf2 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_pdf2 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_pdf2 = (TH1F*)ZToNuNu->Clone(); QCD_pdf2 = (TH1F*)QCD->Clone(); WToLNu_pdf2 = (TH1F*)WToLNu->Clone(); TT_pdf2 = (TH1F*)TT->Clone(); VV_pdf2 = (TH1F*)VV->Clone(); ttV_pdf2 = (TH1F*)ttV->Clone(); 
	data_pdf2 = (TH1F*)data->Clone();

	tptzm0600lh_jes1 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_jes1 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_jes1 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_jes1 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_jes1 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_jes1 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_jes1 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_jes1 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_jes1 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_jes1 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_jes1 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_jes1 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_jes1 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_jes1 = (TH1F*)ZToNuNu->Clone(); QCD_jes1 = (TH1F*)QCD->Clone(); WToLNu_jes1 = (TH1F*)WToLNu->Clone(); TT_jes1 = (TH1F*)TT->Clone(); VV_jes1 = (TH1F*)VV->Clone(); ttV_jes1 = (TH1F*)ttV->Clone(); 
	data_jes1 = (TH1F*)data->Clone();

	tptzm0600lh_jes2 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_jes2 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_jes2 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_jes2 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_jes2 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_jes2 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_jes2 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_jes2 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_jes2 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_jes2 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_jes2 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_jes2 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_jes2 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_jes2 = (TH1F*)ZToNuNu->Clone(); QCD_jes2 = (TH1F*)QCD->Clone(); WToLNu_jes2 = (TH1F*)WToLNu->Clone(); TT_jes2 = (TH1F*)TT->Clone(); VV_jes2 = (TH1F*)VV->Clone(); ttV_jes2 = (TH1F*)ttV->Clone(); 
	data_jes2 = (TH1F*)data->Clone();

	tptzm0600lh_jer1 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_jer1 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_jer1 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_jer1 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_jer1 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_jer1 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_jer1 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_jer1 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_jer1 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_jer1 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_jer1 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_jer1 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_jer1 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_jer1 = (TH1F*)ZToNuNu->Clone(); QCD_jer1 = (TH1F*)QCD->Clone(); WToLNu_jer1 = (TH1F*)WToLNu->Clone(); TT_jer1 = (TH1F*)TT->Clone(); VV_jer1 = (TH1F*)VV->Clone(); ttV_jer1 = (TH1F*)ttV->Clone(); 
	data_jer1 = (TH1F*)data->Clone();

	tptzm0600lh_jer2 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_jer2 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_jer2 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_jer2 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_jer2 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_jer2 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_jer2 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_jer2 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_jer2 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_jer2 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_jer2 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_jer2 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_jer2 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_jer2 = (TH1F*)ZToNuNu->Clone(); QCD_jer2 = (TH1F*)QCD->Clone(); WToLNu_jer2 = (TH1F*)WToLNu->Clone(); TT_jer2 = (TH1F*)TT->Clone(); VV_jer2 = (TH1F*)VV->Clone(); ttV_jer2 = (TH1F*)ttV->Clone(); 
	data_jer2 = (TH1F*)data->Clone();



	tptzm0600lh_tri1 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_tri1 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_tri1 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_tri1 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_tri1 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_tri1 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_tri1 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_tri1 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_tri1 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_tri1 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_tri1 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_tri1 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_tri1 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_tri1 = (TH1F*)ZToNuNu->Clone(); QCD_tri1 = (TH1F*)QCD->Clone(); WToLNu_tri1 = (TH1F*)WToLNu->Clone(); TT_tri1 = (TH1F*)TT->Clone(); VV_tri1 = (TH1F*)VV->Clone(); ttV_tri1 = (TH1F*)ttV->Clone(); 
	data_tri1 = (TH1F*)data->Clone();

	tptzm0600lh_tri2 = (TH1F*)tptzm0600lh->Clone(); tptzm0700lh_tri2 = (TH1F*)tptzm0700lh->Clone(); tptzm0800lh_tri2 = (TH1F*)tptzm0800lh->Clone(); tptzm0900lh_tri2 = (TH1F*)tptzm0900lh->Clone(); tptzm1000lh_tri2 = (TH1F*)tptzm1000lh->Clone();
	tptzm1100lh_tri2 = (TH1F*)tptzm1100lh->Clone(); tptzm1200lh_tri2 = (TH1F*)tptzm1200lh->Clone(); tptzm1300lh_tri2 = (TH1F*)tptzm1300lh->Clone(); tptzm1400lh_tri2 = (TH1F*)tptzm1400lh->Clone();
	tptzm1500lh_tri2 = (TH1F*)tptzm1500lh->Clone(); tptzm1600lh_tri2 = (TH1F*)tptzm1600lh->Clone(); tptzm1700lh_tri2 = (TH1F*)tptzm1700lh->Clone(); tptzm1800lh_tri2 = (TH1F*)tptzm1800lh->Clone();
	ZToNuNu_tri2 = (TH1F*)ZToNuNu->Clone(); QCD_tri2 = (TH1F*)QCD->Clone(); WToLNu_tri2 = (TH1F*)WToLNu->Clone(); TT_tri2 = (TH1F*)TT->Clone(); VV_tri2 = (TH1F*)VV->Clone(); ttV_tri2 = (TH1F*)ttV->Clone(); 
	data_tri2 = (TH1F*)data->Clone();

}
