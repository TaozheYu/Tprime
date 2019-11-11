#include "plotterPreselection_dineutrino_3SF_correlation_2016.h"

void plotterPreselection_dineutrino_3SF_correlation_2016(){ 
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

  vector<TString> name_CR;             vector<int> bin_CR;   vector<float> Min_CR;   vector<float> Max_CR;  vector<TString> axis_CR;
  vector<TString> name;                vector<int> bin;      vector<float> Min;      vector<float> Max;     vector<TString> axis;

  name.push_back("HT"); name.push_back("Met_pt");// bin_CR.push_back(4);     Min_CR.push_back(200);    Max_CR.push_back(2000);    axis_CR.push_back("HT pt[GeV]");
  
    const char *plot_HT = name[0];
    const char *plot_Met= name[1];

    char CUT[1000]; char CUTmuo1[1000]; char CUTmuo2[1000]; char CUTele1[1000]; char CUTele2[1000]; char CUTtri1[1000]; char CUTtri2[1000]; char CUTtri3[1000]; char CUTtri4[1000]; char CUTpup1[1000]; char CUTpup2[1000]; char CUTbta1[1000]; char CUTbta2[1000]; char CUTtop1[1000]; char CUTtop2[1000]; char CUTfor1[1000]; char CUTfor2[1000]; char CUTwje1[1000]; char CUTwje2[1000];
    char CUTCS1[1000];   char CS1[1000];
    char CUTCS2[1000];   char CS2[1000];
    char CUTCS3[1000];   char CS3[1000];
    char CUTPre[1000];   char Pre[1000];

    sprintf(CUT,    "((category0==1)&&(Jet1ResolvedPt>0)&&(Jet2ResolvedPt>0)&&(Jet3ResolvedPt>0)&&(MinDeltaPhiJetMet>0.6)&&(TopPt>250)&&(HT>200)&&(TransverseMassMetTop>500)");

    sprintf(CS1,  "(NumSelBJetsM==0)&&(NumSelLeps==0)&&(MinDeltaPhiJetMet>0.6))");    //Z->nunu: signal selection but NumSelBJetsM==0 instead of NumSelBJetsM>1
    sprintf(CS2,  "(NumSelBJetsM==0)&&(NumSelLeps>0)&&(MinDeltaPhiJetMet>0.6))");   //Wjets:     signal selection but NumSelBJetsM==0 and NumSelLeps==1
    sprintf(CS3,  "(NumSelBJetsM>0)&&(NumSelLeps>0)&&(MinDeltaPhiJetMet>0.6))");   //ttbar:       signal selection with NumSelBJetsM>1 but TopPt<340

    sprintf(CUTCS1,  "PUWeight   *w_Btag  *genWeight*prefiringweight*w_Trig*%s&&%s",CUT,CS1);
    sprintf(CUTCS2,  "PUWeight   *w_Btag  *genWeight*prefiringweight*w_Trig*%s&&%s",CUT,CS2);
    sprintf(CUTCS3,  "PUWeight   *w_Btag  *genWeight*prefiringweight*w_Trig*%s&&%s",CUT,CS3);

    Double_t stops[9] = { 0.0000, 0.1250, 0.2500, 0.3750, 0.5000, 0.6250,0.7500, 0.8750, 1.0000};
    Double_t red[9] = { 37./255., 52./255., 74./255., 97./255., 116./255.,134./255., 154./255., 172./255., 185./255.};
    Double_t green[9] = { 0./255., 33./255., 68./255., 109./255., 140./255.,171./255., 192./255., 196./255., 209./255.};
    Double_t blue[9] = { 116./255., 137./255., 173./255., 201./255.,200./255., 201./255., 203./255., 220./255., 255./255.};
    TColor::CreateGradientColorTable(9, stops, red, green, blue, 255, 1);
    
    for(int j=0; j<N-1; j++){
      float xmin = xbins[j];
      float xmax = xbins[j+1];
      for(int k=0; k<M-1; k++){
        float ymin = ybins[k];
        float ymax = ybins[k+1];
        
        if((j==0&&k==2)||(j==1&&k==2)||(j==2&&k==2)){xmin = xbins[0]; xmax = xbins[3];}

	//category=0 caculate SF1, SF2, SF3
	CalculateSF(CUTCS1,CUTCS2,CUTCS3,0, plot_HT,plot_Met,1,xmin,xmax,1,ymin,ymax,SF1,SF2,SF3,SF1_err,SF2_err,SF3_err,SF_den);

	//cout<<"SF_den ="<< SF_den <<endl;
	if (SF_den==0) {SF1=1;SF2=1;SF3=1;SF1_err=0.99;SF2_err=0.99;SF3_err=0.99;};
        cout<<"SF1 ="<< SF1 <<endl;
        cout<<"SF2 ="<< SF2 <<endl;
        cout<<"SF3 ="<< SF3 <<endl;
        cout<<"SF1 err = "<< sqrt(SF1_err) <<endl;
        cout<<"SF2 err = "<< sqrt(SF2_err) <<endl;
        cout<<"SF3 err = "<< sqrt(SF3_err) <<endl;
        cout<<endl;
	if (SF1<0) { SF1=1; SF1_err=0.99;}
	if (SF2<0) { SF2=1; SF2_err=0.99;}
	if (SF3<0) { SF3=1; SF3_err=0.99;}
        if (SF1>3) { SF1=1; SF1_err=0.99;}
        if (SF2>3) { SF2=1; SF2_err=0.99;}
        if (SF3>3) { SF3=1; SF3_err=0.99;}

	if(SF1>0) SF1_h->SetBinContent(j+1,k+1,SF1);
	if(SF2>0) SF2_h->SetBinContent(j+1,k+1,SF2);
	if(SF3>0) SF3_h->SetBinContent(j+1,k+1,SF3);

	SF1_h->SetBinError(j+1,k+1,sqrt(SF1_err));
	SF2_h->SetBinError(j+1,k+1,sqrt(SF2_err));
	SF3_h->SetBinError(j+1,k+1,sqrt(SF3_err));
        
        SF1_zjetsUp=SF1+sqrt(SF1_err); SF1_zjetsDown=TMath::Max(0.01,SF1-sqrt(SF1_err));
        SF2_wjetsUp=SF2+sqrt(SF2_err); SF2_wjetsDown=TMath::Max(0.01,SF2-sqrt(SF2_err));
        SF3_topUp  =SF3+sqrt(SF3_err); SF3_topDown  =TMath::Max(0.01,SF3-sqrt(SF3_err));
        //category=1 apply SF1=SF1+SF1_err to get SF2+, SF3+ 
	CalculateSF(CUTCS1,CUTCS2,CUTCS3,1, plot_HT,plot_Met,1,xmin,xmax,1,ymin,ymax,SF1_zjetsUp,SF2_zjetsUp,SF3_zjetsUp,SF1_zjets_err,SF2_zjets_err,SF3_zjets_err,SF_den);
	if (SF_den==0) {SF1_zjetsUp=1;SF2_zjetsUp=1;SF3_zjetsUp=1;};
        cout<<"SF1_zjetsUp ="<< SF1+sqrt(SF1_err) <<endl;
        cout<<"SF2_zjetsUp ="<< SF2_zjetsUp <<endl;
        cout<<"SF3_zjetsUp ="<< SF3_zjetsUp <<endl;
        cout<<endl;
        if(SF2_zjetsUp<0||SF2_zjetsUp>6) SF2_zjetsUp=1;
        if(SF3_zjetsUp<0||SF3_zjetsUp>6) SF3_zjetsUp=1;
	if(SF1>0)         SF1_zjetsUp_h->SetBinContent(j+1,k+1,SF1+sqrt(SF1_err));
	if(SF2_zjetsUp>0) SF2_zjetsUp_h->SetBinContent(j+1,k+1,SF2_zjetsUp);
	if(SF3_zjetsUp>0) SF3_zjetsUp_h->SetBinContent(j+1,k+1,SF3_zjetsUp);
        
        //category=2 apply SF1=SF1-SF1_err to get SF2-, SF3- 
	CalculateSF(CUTCS1,CUTCS2,CUTCS3,2, plot_HT,plot_Met,1,xmin,xmax,1,ymin,ymax,SF1_zjetsDown,SF2_zjetsDown,SF3_zjetsDown,SF1_zjets_err,SF2_zjets_err,SF3_zjets_err,SF_den);
	if (SF_den==0) {SF1_zjetsDown=1;SF2_zjetsDown=1;SF3_zjetsDown=1;};
        cout<<"SF1_zjetsDown ="<< TMath::Max(0.,SF1-sqrt(SF1_err)) <<endl;
        cout<<"SF2_zjetsDown ="<< SF2_zjetsDown <<endl;
        cout<<"SF3_zjetsDown ="<< SF3_zjetsDown <<endl;
        cout<<endl;
        if(SF2_zjetsDown<0||SF2_zjetsDown>6) SF2_zjetsDown=1;
        if(SF3_zjetsDown<0||SF3_zjetsDown>6) SF3_zjetsDown=1;
	if(SF1>0) SF1_zjetsDown_h->SetBinContent(j+1,k+1,TMath::Max(0.,SF1-sqrt(SF1_err)));
	if(SF2_zjetsDown>0) SF2_zjetsDown_h->SetBinContent(j+1,k+1,SF2_zjetsDown);
	if(SF3_zjetsDown>0) SF3_zjetsDown_h->SetBinContent(j+1,k+1,SF3_zjetsDown);

        //category=3 apply SF2=SF2+SF2_err to get SF1+, SF3+ 
	CalculateSF(CUTCS1,CUTCS2,CUTCS3,3, plot_HT,plot_Met,1,xmin,xmax,1,ymin,ymax,SF1_wjetsUp,SF2_wjetsUp,SF3_wjetsUp,SF1_wjets_err,SF2_wjets_err,SF3_wjets_err,SF_den);
	if (SF_den==0) {SF1_wjetsUp=1;SF2_wjetsUp=1;SF3_wjetsUp=1;};
        cout<<"SF1_wjetsUp ="<< SF1_wjetsUp <<endl;
        cout<<"SF2_wjetsUp ="<< SF2+sqrt(SF2_err) <<endl;
        cout<<"SF3_wjetsUp ="<< SF3_wjetsUp <<endl;
        cout<<endl;
        if(SF1_wjetsUp<0||SF1_wjetsUp>6) SF1_wjetsUp=1;
        if(SF3_wjetsUp<0||SF3_wjetsUp>6) SF3_wjetsUp=1;
	if(SF1_wjetsUp>0) SF1_wjetsUp_h->SetBinContent(j+1,k+1,SF1_wjetsUp);
	if(SF2>0)        SF2_wjetsUp_h->SetBinContent(j+1,k+1,SF2+sqrt(SF2_err));
	if(SF3_wjetsUp>0) SF3_wjetsUp_h->SetBinContent(j+1,k+1,SF3_wjetsUp);
        
        //category=4 apply SF2=SF2-SF2_err to get SF1-, SF3- 
	CalculateSF(CUTCS1,CUTCS2,CUTCS3,4, plot_HT,plot_Met,1,xmin,xmax,1,ymin,ymax,SF1_wjetsDown,SF2_wjetsDown,SF3_wjetsDown,SF1_wjets_err,SF2_wjets_err,SF3_wjets_err,SF_den);
	if (SF_den==0) {SF1_wjetsDown=1;SF2_wjetsDown=1;SF3_wjetsDown=1;};
        cout<<"SF1_wjetsDown ="<< SF1_wjetsDown <<endl;
        cout<<"SF2_wjetsDown ="<< TMath::Max(0.,SF2-sqrt(SF2_err)) <<endl;
        cout<<"SF3_wjetsDown ="<< SF3_wjetsDown <<endl;
        cout<<endl;
        if(SF1_wjetsDown<0||SF1_wjetsDown>6) SF1_wjetsDown=1;
        if(SF3_wjetsDown<0||SF3_wjetsDown>6) SF3_wjetsDown=1;
	if(SF1_wjetsDown>0) SF1_wjetsDown_h->SetBinContent(j+1,k+1,SF1_wjetsDown);
	if(SF2>0)           SF2_wjetsDown_h->SetBinContent(j+1,k+1,TMath::Max(0.,SF2-sqrt(SF2_err)));
	if(SF3_wjetsDown>0) SF3_wjetsDown_h->SetBinContent(j+1,k+1,SF3_wjetsDown);

        //category=5 apply SF3=SF3+SF3_err to get SF1+, SF2+ 
	CalculateSF(CUTCS1,CUTCS2,CUTCS3,5, plot_HT,plot_Met,1,xmin,xmax,1,ymin,ymax,SF1_topUp,SF2_topUp,SF3_topUp,SF1_top_err,SF2_top_err,SF3_top_err,SF_den);
	if (SF_den==0) {SF1_topUp=1;SF2_topUp=1;SF3_topUp=1;};
        cout<<"SF1_topUp ="<< SF1_topUp <<endl;
        cout<<"SF2_topUp ="<< SF2_topUp <<endl;
        cout<<"SF3_topUp ="<< SF3+sqrt(SF3_err) <<endl;
        cout<<endl;
        if(SF1_topUp<0||SF1_topUp>6) SF1_topUp=1;
        if(SF2_topUp<0||SF2_topUp>6) SF2_topUp=1;
	if(SF1_topUp>0) SF1_topUp_h->SetBinContent(j+1,k+1,SF1_topUp);
	if(SF2_topUp>0) SF2_topUp_h->SetBinContent(j+1,k+1,SF2_topUp);
	if(SF3>0)       SF3_topUp_h->SetBinContent(j+1,k+1,SF3+sqrt(SF3_err));
        
        //category=6 apply SF3=SF3-SF3_err to get SF1-, SF2- 
	CalculateSF(CUTCS1,CUTCS2,CUTCS3,6, plot_HT,plot_Met,1,xmin,xmax,1,ymin,ymax,SF1_topDown,SF2_topDown,SF3_topDown,SF1_top_err,SF2_top_err,SF3_top_err,SF_den);
	if (SF_den==0) {SF1_topDown=1;SF2_topDown=1;SF3_topDown=1;};
        cout<<"SF1_topDown ="<< SF1_topDown <<endl;
        cout<<"SF2_topDown ="<< SF2_topDown <<endl;
        cout<<"SF3_topDown ="<< TMath::Max(0.,SF3-sqrt(SF3_err)) <<endl;
        cout<<endl;
        if(SF1_topDown<0||SF1_topDown>6) SF1_topDown=1;
        if(SF2_topDown<0||SF2_topDown>6) SF2_topDown=1;
	if(SF1_topDown>0) SF1_topDown_h->SetBinContent(j+1,k+1,SF1_topDown);
	if(SF2_topDown>0) SF2_topDown_h->SetBinContent(j+1,k+1,SF2_topDown);
	if(SF3>0)        SF3_topDown_h->SetBinContent(j+1,k+1,TMath::Max(0.,SF3-sqrt(SF3_err)));

      }
    }

    TCanvas* canvasSF1 = new TCanvas("canvasSF1","canvasSF1",0,0,900,600);
    //SF1_h->SetLineWidth(2); 
    //SF1_h->SetLineColor(kGreen+3);
    //SF1_h->SetMarkerColor(kGreen+3); 
    //SF1_h->SetMarkerStyle(20); 
    //SF1_h->SetMarkerSize(1.3);
    SF1_h->GetYaxis()->SetTitleSize(0.040);
    SF1_h->GetXaxis()->SetTitleSize(0.040);
    SF1_h->GetYaxis()->SetLabelSize(0.040);
    SF1_h->GetXaxis()->SetLabelSize(0.040); 
    SF1_h->SetMinimum(0);
    SF1_h->SetMaximum(3.0);
    SF1_h->SetTitle("SF1");
    SF1_h->GetYaxis()->SetTitle("MET [GeV]");
    SF1_h->GetXaxis()->SetTitle("HT [GeV]"); 
    SF1_h->Draw("COLZ");
    canvasSF1->Draw();
    //canvasSF1->SaveAs("/publicfs/cms/user/yutz/Tprime/2016_dineutrino/SF1.pdf");
    //canvasSF1->SaveAs("/publicfs/cms/user/yutz/Tprime/2016_dineutrino/SF1.png");
    //canvasSF1->SaveAs("SF1.png");
    //canvasSF1->SaveAs("SF1.pdf");

    TCanvas* canvasSF2 = new TCanvas("canvasSF2","canvasSF2",0,0,900,600); 
    //SF2_h->SetLineWidth(2); 
    //SF2_h->SetLineColor(kGreen+3);
    //SF2_h->SetMarkerColor(kGreen+3); 
    //SF2_h->SetMarkerStyle(20); 
    //SF2_h->SetMarkerSize(1.3);
    SF2_h->GetYaxis()->SetTitleSize(0.040);
    SF2_h->GetXaxis()->SetTitleSize(0.040);
    SF2_h->GetYaxis()->SetLabelSize(0.040);
    SF2_h->GetXaxis()->SetLabelSize(0.040); 
    SF2_h->SetMinimum(0);
    SF2_h->SetMaximum(3.0);
    SF2_h->SetTitle("SF2");
    SF2_h->GetYaxis()->SetTitle("MET [GeV]");
    SF2_h->GetXaxis()->SetTitle("HT [GeV]"); 
    SF2_h->Draw("COLZ");
    canvasSF2->Draw();
    //canvasSF2->SaveAs("/publicfs/cms/user/yutz/Tprime/2016_dineutrino/SF2.pdf");
    //canvasSF2->SaveAs("/publicfs/cms/user/yutz/Tprime/2016_dineutrino/SF2.png");
    //canvasSF2->SaveAs("SF2.png");
    //canvasSF2->SaveAs("SF2.pdf");
	
    TCanvas* canvasSF3 = new TCanvas("canvasSF3","canvasSF3",0,0,900,600); 
    //SF3_h->SetLineWidth(2); 
    //SF3_h->SetLineColor(kGreen+3);
    //SF3_h->SetMarkerColor(kGreen+3); 
    //SF3_h->SetMarkerStyle(20); 
    //SF3_h->SetMarkerSize(1.3);
    SF3_h->GetYaxis()->SetTitleSize(0.040);
    SF3_h->GetXaxis()->SetTitleSize(0.040);
    SF3_h->GetYaxis()->SetLabelSize(0.040);
    SF3_h->GetXaxis()->SetLabelSize(0.040); 
    SF3_h->SetMinimum(0);
    SF3_h->SetMaximum(3.0);
    SF3_h->SetTitle("SF3");
    SF3_h->GetYaxis()->SetTitle("MET [GeV]");
    SF3_h->GetXaxis()->SetTitle("HT [GeV]"); 
    SF3_h->Draw("COLZ");
    canvasSF3->Draw();
    //canvasSF3->SaveAs("/publicfs/cms/user/yutz/Tprime/2016_dineutrino/SF3.pdf");
    //canvasSF3->SaveAs("/publicfs/cms/user/yutz/Tprime/2016_dineutrino/SF3.png");
    //canvasSF3->SaveAs("SF3.png");
    //canvasSF3->SaveAs("SF3.pdf");
    
    //char NewFileName[500]; sprintf(NewFileName, "/publicfs/cms/user/yutz/Tprime/2016_dineutrino/SF_2D_veto.root");
    //char NewFileName[500]; sprintf(NewFileName, "/publicfs/cms/user/yutz/Tprime/2016_dineutrino/SF_2D.root");
    //char NewFileName[500]; sprintf(NewFileName, "/publicfs/cms/user/yutz/Tprime/2016_dineutrino/SF_2D_merge.root");
    char NewFileName[500]; sprintf(NewFileName, "/publicfs/cms/user/yutz/Tprime/2016_dineutrino/SF_2D_correlation.root");
    TFile f(NewFileName,"new");
    SF1_h->Write();
    SF2_h->Write();
    SF3_h->Write();
    SF1_zjetsUp_h->Write(); SF2_zjetsUp_h->Write(); SF3_zjetsUp_h->Write();
    SF1_zjetsDown_h->Write(); SF2_zjetsDown_h->Write(); SF3_zjetsDown_h->Write();
    SF1_wjetsUp_h->Write(); SF2_wjetsUp_h->Write(); SF3_wjetsUp_h->Write();
    SF1_wjetsDown_h->Write(); SF2_wjetsDown_h->Write(); SF3_wjetsDown_h->Write();
    SF1_topUp_h->Write(); SF2_topUp_h->Write(); SF3_topUp_h->Write();
    SF1_topDown_h->Write(); SF2_topDown_h->Write(); SF3_topDown_h->Write();
   
}
//}


void GetHisto(char CUT[1000], TTree *Tree, TH2F* & histo, const char *plotX,const char *plotY, int XBIN, float XMIN, float XMAX, int YBIN, float YMIN, float YMAX){
  char input[50]; sprintf(input,"%s:%s>>h(%i,%f,%f,%i,%f,%f)",plotY,plotX,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  TH2F *temp = new TH2F("", "", XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  if(Tree->Draw(input,CUT)){ Tree->Draw(input,CUT); TH2F* h=(TH2F*)gDirectory->Get("h"); histo = (TH2F*)h->Clone(); delete h; } else { histo = (TH2F*)temp->Clone(); }
  histo->SetDirectory(0);
  histo->SetName("histo");
  delete temp;
}


void CalculateSF(char CUTCS1[1000],char CUTCS2[1000],char CUTCS3[1000], int category, const char *plotX, const char *plotY, int XBIN,double XMIN,double XMAX,int YBIN,     double YMIN, double YMAX, double &SF1,double &SF2,double &SF3,double &SF1_err, double &SF2_err, double &SF3_err, double &SF_den){

  TH2F *data_CS1; 
  TH2F *ZToNuNu_1_CS1; TH2F *ZToNuNu_2_CS1; TH2F *ZToNuNu_3_CS1; TH2F *ZToNuNu_4_CS1; TH2F *ZToNuNu_5_CS1; TH2F *ZToNuNu_6_CS1; TH2F *ZToNuNu_7_CS1; 
  TH2F *QCD_1_CS1; TH2F *QCD_2_CS1; TH2F *QCD_3_CS1; TH2F *QCD_4_CS1; TH2F *QCD_5_CS1; TH2F *QCD_6_CS1; TH2F *QCD_7_CS1; 
  TH2F *WToLNu_1_CS1; TH2F *WToLNu_2_CS1; TH2F *WToLNu_3_CS1; TH2F *WToLNu_4_CS1; TH2F *WToLNu_5_CS1; TH2F *WToLNu_6_CS1; TH2F *WToLNu_7_CS1;
  TH2F *TT_1_CS1; TH2F *TT_2_CS1; 
  TH2F *ST_1_CS1; TH2F *ST_2_CS1; TH2F *ST_3_CS1; TH2F *ST_4_CS1; 
  TH2F *ZZ1_CS1; TH2F *ZZ2_CS1; TH2F *ZZ3_CS1; TH2F *WZ1_CS1; TH2F *WZ2_CS1; TH2F *WZ3_CS1; TH2F *WW1_CS1; TH2F *WW2_CS1; 
  TH2F *ttW_CS1; TH2F *ttZ_CS1; TH2F *tZq_CS1; TH2F *ZZ4_CS1; TH2F *WZ4_CS1;

  TH2F *data_CS2; 
  TH2F *ZToNuNu_1_CS2; TH2F *ZToNuNu_2_CS2; TH2F *ZToNuNu_3_CS2; TH2F *ZToNuNu_4_CS2; TH2F *ZToNuNu_5_CS2; TH2F *ZToNuNu_6_CS2; TH2F *ZToNuNu_7_CS2; 
  TH2F *QCD_1_CS2; TH2F *QCD_2_CS2; TH2F *QCD_3_CS2; TH2F *QCD_4_CS2; TH2F *QCD_5_CS2; TH2F *QCD_6_CS2; TH2F *QCD_7_CS2;  
  TH2F *WToLNu_1_CS2; TH2F *WToLNu_2_CS2; TH2F *WToLNu_3_CS2; TH2F *WToLNu_4_CS2; TH2F *WToLNu_5_CS2; TH2F *WToLNu_6_CS2; TH2F *WToLNu_7_CS2;
  TH2F *TT_1_CS2; TH2F *TT_2_CS2; 
  TH2F *ST_1_CS2; TH2F *ST_2_CS2; TH2F *ST_3_CS2; TH2F *ST_4_CS2; 
  TH2F *ZZ1_CS2; TH2F *ZZ2_CS2; TH2F *ZZ3_CS2; TH2F *WZ1_CS2; TH2F *WZ2_CS2; TH2F *WZ3_CS2; TH2F *WW1_CS2; TH2F *WW2_CS2;
  TH2F *ttW_CS2; TH2F *ttZ_CS2; TH2F *tZq_CS2; TH2F *ZZ4_CS2; TH2F *WZ4_CS2;

  TH2F *data_CS3;
  TH2F *ZToNuNu_1_CS3; TH2F *ZToNuNu_2_CS3; TH2F *ZToNuNu_3_CS3; TH2F *ZToNuNu_4_CS3; TH2F *ZToNuNu_5_CS3; TH2F *ZToNuNu_6_CS3; TH2F *ZToNuNu_7_CS3; 
  TH2F *QCD_1_CS3; TH2F *QCD_2_CS3; TH2F *QCD_3_CS3; TH2F *QCD_4_CS3; TH2F *QCD_5_CS3; TH2F *QCD_6_CS3; TH2F *QCD_7_CS3; 
  TH2F *WToLNu_1_CS3; TH2F *WToLNu_2_CS3; TH2F *WToLNu_3_CS3; TH2F *WToLNu_4_CS3; TH2F *WToLNu_5_CS3; TH2F *WToLNu_6_CS3; TH2F *WToLNu_7_CS3;
  TH2F *TT_1_CS3; TH2F *TT_2_CS3; 
  TH2F *ST_1_CS3; TH2F *ST_2_CS3; TH2F *ST_3_CS3; TH2F *ST_4_CS3; 
  TH2F *ZZ1_CS3; TH2F *ZZ2_CS3; TH2F *ZZ3_CS3; TH2F *WZ1_CS3; TH2F *WZ2_CS3; TH2F *WZ3_CS3; TH2F *WW1_CS3; TH2F *WW2_CS3; 
  TH2F *ttW_CS3; TH2F *ttZ_CS3; TH2F *tZq_CS3; TH2F *ZZ4_CS3; TH2F *WZ4_CS3;

  GetHisto(CUTCS1, Tree01, data_CS1        ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree14, ZToNuNu_1_CS1   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree15, ZToNuNu_2_CS1   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree16, ZToNuNu_3_CS1   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree17, ZToNuNu_4_CS1   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree18, ZToNuNu_5_CS1   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree19, ZToNuNu_6_CS1   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree20, ZToNuNu_7_CS1   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree21, QCD_1_CS1      ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree22, QCD_2_CS1      ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree23, QCD_3_CS1      ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree24, QCD_4_CS1      ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree25, QCD_5_CS1      ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree26, QCD_6_CS1      ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree27, QCD_7_CS1      ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree28, WToLNu_1_CS1   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree29, WToLNu_2_CS1   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree30, WToLNu_3_CS1   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree31, WToLNu_4_CS1   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree32, WToLNu_5_CS1   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree33, WToLNu_6_CS1   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree34, WToLNu_7_CS1   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree35, TT_1_CS1    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree36, TT_2_CS1    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree37, ST_1_CS1    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree38, ST_2_CS1    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree39, ST_3_CS1    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree40, ST_4_CS1    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree41, ZZ1_CS1    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree42, ZZ2_CS1    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree43, ZZ3_CS1    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree44, WW1_CS1    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree45, WW2_CS1    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree46, WZ1_CS1    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree47, WZ2_CS1    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree48, WZ3_CS1    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree49, ttW_CS1    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree50, ttZ_CS1    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree51, tZq_CS1    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree52, ZZ4_CS1    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS1, Tree53, WZ4_CS1    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);

  GetHisto(CUTCS2, Tree01, data_CS2        ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree14, ZToNuNu_1_CS2   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree15, ZToNuNu_2_CS2   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree16, ZToNuNu_3_CS2   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree17, ZToNuNu_4_CS2   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree18, ZToNuNu_5_CS2   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree19, ZToNuNu_6_CS2   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree20, ZToNuNu_7_CS2   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree21, QCD_1_CS2      ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree22, QCD_2_CS2      ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree23, QCD_3_CS2      ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree24, QCD_4_CS2      ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree25, QCD_5_CS2      ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree26, QCD_6_CS2      ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree27, QCD_7_CS2      ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree28, WToLNu_1_CS2   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree29, WToLNu_2_CS2   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree30, WToLNu_3_CS2   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree31, WToLNu_4_CS2   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree32, WToLNu_5_CS2   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree33, WToLNu_6_CS2   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree34, WToLNu_7_CS2   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree35, TT_1_CS2    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree36, TT_2_CS2    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree37, ST_1_CS2    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree38, ST_2_CS2    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree39, ST_3_CS2    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree40, ST_4_CS2    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree41, ZZ1_CS2    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree42, ZZ2_CS2    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree43, ZZ3_CS2    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree44, WW1_CS2    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree45, WW2_CS2    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree46, WZ1_CS2    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree47, WZ2_CS2    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree48, WZ3_CS2    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree49, ttW_CS2    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree50, ttZ_CS2    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree51, tZq_CS2    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree52, ZZ4_CS2    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS2, Tree53, WZ4_CS2    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);

  GetHisto(CUTCS3, Tree01, data_CS3        ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree14, ZToNuNu_1_CS3   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree15, ZToNuNu_2_CS3   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree16, ZToNuNu_3_CS3   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree17, ZToNuNu_4_CS3   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree18, ZToNuNu_5_CS3   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree19, ZToNuNu_6_CS3   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree20, ZToNuNu_7_CS3   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree21, QCD_1_CS3      ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree22, QCD_2_CS3      ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree23, QCD_3_CS3      ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree24, QCD_4_CS3      ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree25, QCD_5_CS3      ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree26, QCD_6_CS3      ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree27, QCD_7_CS3      ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree28, WToLNu_1_CS3   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree29, WToLNu_2_CS3   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree30, WToLNu_3_CS3   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree31, WToLNu_4_CS3   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree32, WToLNu_5_CS3   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree33, WToLNu_6_CS3   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree34, WToLNu_7_CS3   ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree35, TT_1_CS3    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree36, TT_2_CS3    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree37, ST_1_CS3    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree38, ST_2_CS3    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree39, ST_3_CS3    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree40, ST_4_CS3    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree41, ZZ1_CS3    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree42, ZZ2_CS3    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree43, ZZ3_CS3    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree44, WW1_CS3    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree45, WW2_CS3    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree46, WZ1_CS3    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree47, WZ2_CS3    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree48, WZ3_CS3    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX); 
  GetHisto(CUTCS3, Tree49, ttW_CS3    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree50, ttZ_CS3    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree51, tZq_CS3    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree52, ZZ4_CS3    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  GetHisto(CUTCS3, Tree53, WZ4_CS3    ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
 

  double N_ZToNuNu_1_CS1_err = 0; if(ZToNuNu_1_CS1->Integral()>0){N_ZToNuNu_1_CS1_err=sqrt(w01*w01*ZToNuNu_1_CS1->Integral());}
  double N_ZToNuNu_2_CS1_err = 0; if(ZToNuNu_2_CS1->Integral()>0){N_ZToNuNu_2_CS1_err=sqrt(w02*w02*ZToNuNu_2_CS1->Integral());}
  double N_ZToNuNu_3_CS1_err = 0; if(ZToNuNu_3_CS1->Integral()>0){N_ZToNuNu_3_CS1_err=sqrt(w03*w03*ZToNuNu_3_CS1->Integral());}
  double N_ZToNuNu_4_CS1_err = 0; if(ZToNuNu_4_CS1->Integral()>0){N_ZToNuNu_4_CS1_err=sqrt(w04*w04*ZToNuNu_4_CS1->Integral());}
  double N_ZToNuNu_5_CS1_err = 0; if(ZToNuNu_5_CS1->Integral()>0){N_ZToNuNu_5_CS1_err=sqrt(w05*w05*ZToNuNu_5_CS1->Integral());}
  double N_ZToNuNu_6_CS1_err = 0; if(ZToNuNu_6_CS1->Integral()>0){N_ZToNuNu_6_CS1_err=sqrt(w06*w06*ZToNuNu_6_CS1->Integral());}
  double N_ZToNuNu_7_CS1_err = 0; if(ZToNuNu_7_CS1->Integral()>0){N_ZToNuNu_7_CS1_err=sqrt(w07*w07*ZToNuNu_7_CS1->Integral());}
  double N_QCD_1_CS1_err = 0; if(QCD_1_CS1->Integral()>0){N_QCD_1_CS1_err=sqrt(w08*w08*QCD_1_CS1->Integral());}
  double N_QCD_2_CS1_err = 0; if(QCD_2_CS1->Integral()>0){N_QCD_2_CS1_err=sqrt(w09*w09*QCD_2_CS1->Integral());}
  double N_QCD_3_CS1_err = 0; if(QCD_3_CS1->Integral()>0){N_QCD_3_CS1_err=sqrt(w10*w10*QCD_3_CS1->Integral());}
  double N_QCD_4_CS1_err = 0; if(QCD_4_CS1->Integral()>0){N_QCD_4_CS1_err=sqrt(w11*w11*QCD_4_CS1->Integral());}
  double N_QCD_5_CS1_err = 0; if(QCD_5_CS1->Integral()>0){N_QCD_5_CS1_err=sqrt(w12*w12*QCD_5_CS1->Integral());}
  double N_QCD_6_CS1_err = 0; if(QCD_6_CS1->Integral()>0){N_QCD_6_CS1_err=sqrt(w13*w13*QCD_6_CS1->Integral());}
  double N_QCD_7_CS1_err = 0; if(QCD_7_CS1->Integral()>0){N_QCD_7_CS1_err=sqrt(w14*w14*QCD_7_CS1->Integral());}
  double N_WToLNu_1_CS1_err = 0; if(WToLNu_1_CS1->Integral()>0){N_WToLNu_1_CS1_err=sqrt(w15*w15*WToLNu_1_CS1->Integral());}
  double N_WToLNu_2_CS1_err = 0; if(WToLNu_2_CS1->Integral()>0){N_WToLNu_2_CS1_err=sqrt(w16*w16*WToLNu_2_CS1->Integral());}
  double N_WToLNu_3_CS1_err = 0; if(WToLNu_3_CS1->Integral()>0){N_WToLNu_3_CS1_err=sqrt(w17*w17*WToLNu_3_CS1->Integral());}
  double N_WToLNu_4_CS1_err = 0; if(WToLNu_4_CS1->Integral()>0){N_WToLNu_4_CS1_err=sqrt(w18*w18*WToLNu_4_CS1->Integral());}
  double N_WToLNu_5_CS1_err = 0; if(WToLNu_5_CS1->Integral()>0){N_WToLNu_5_CS1_err=sqrt(w19*w19*WToLNu_5_CS1->Integral());}
  double N_WToLNu_6_CS1_err = 0; if(WToLNu_6_CS1->Integral()>0){N_WToLNu_6_CS1_err=sqrt(w20*w20*WToLNu_6_CS1->Integral());}
  double N_WToLNu_7_CS1_err = 0; if(WToLNu_7_CS1->Integral()>0){N_WToLNu_7_CS1_err=sqrt(w21*w21*WToLNu_7_CS1->Integral());}
  double N_TT_1_CS1_err = 0; if(TT_1_CS1->Integral()>0){N_TT_1_CS1_err=sqrt(w22*w22*TT_1_CS1->Integral());}
  double N_TT_2_CS1_err = 0; if(TT_2_CS1->Integral()>0){N_TT_2_CS1_err=sqrt(w23*w23*TT_2_CS1->Integral());}
  double N_ST_1_CS1_err = 0; if(ST_1_CS1->Integral()>0){N_ST_1_CS1_err=sqrt(w24*w24*ST_1_CS1->Integral());}
  double N_ST_2_CS1_err = 0; if(ST_2_CS1->Integral()>0){N_ST_2_CS1_err=sqrt(w25*w25*ST_2_CS1->Integral());}
  double N_ST_3_CS1_err = 0; if(ST_3_CS1->Integral()>0){N_ST_3_CS1_err=sqrt(w26*w26*ST_3_CS1->Integral());}
  double N_ST_4_CS1_err = 0; if(ST_4_CS1->Integral()>0){N_ST_4_CS1_err=sqrt(w27*w27*ST_4_CS1->Integral());}
  double N_VV1_CS1_err = 0; if(ZZ1_CS1->Integral()>0){N_VV1_CS1_err=sqrt(w28*w28*ZZ1_CS1->Integral());}
  double N_VV2_CS1_err = 0; if(ZZ2_CS1->Integral()>0){N_VV2_CS1_err=sqrt(w29*w29*ZZ2_CS1->Integral());}
  double N_VV3_CS1_err = 0; if(ZZ3_CS1->Integral()>0){N_VV3_CS1_err=sqrt(w30*w30*ZZ3_CS1->Integral());}
  double N_VV4_CS1_err = 0; if(WW1_CS1->Integral()>0){N_VV4_CS1_err=sqrt(w31*w31*WW1_CS1->Integral());}
  double N_VV5_CS1_err = 0; if(WW2_CS1->Integral()>0){N_VV5_CS1_err=sqrt(w32*w32*WW2_CS1->Integral());}
  double N_VV6_CS1_err = 0; if(WZ1_CS1->Integral()>0){N_VV6_CS1_err=sqrt(w33*w33*WZ1_CS1->Integral());}
  double N_VV7_CS1_err = 0; if(WZ2_CS1->Integral()>0){N_VV7_CS1_err=sqrt(w34*w34*WZ2_CS1->Integral());}
  double N_VV8_CS1_err = 0; if(WZ3_CS1->Integral()>0){N_VV8_CS1_err=sqrt(w35*w35*WZ3_CS1->Integral());}
  double N_ttV_1_CS1_err= 0;if(ttW_CS1->Integral()>0){N_ttV_1_CS1_err=sqrt(w36*w36*ttW_CS1->Integral());}
  double N_ttV_2_CS1_err= 0;if(ttZ_CS1->Integral()>0){N_ttV_2_CS1_err=sqrt(w37*w37*ttZ_CS1->Integral());}
  double N_ttV_3_CS1_err= 0;if(tZq_CS1->Integral()>0){N_ttV_3_CS1_err=sqrt(w38*w38*tZq_CS1->Integral());}
  double N_VV9_CS1_err = 0; if(ZZ4_CS1->Integral()>0){N_VV9_CS1_err =sqrt(w39*w39*ZZ4_CS1->Integral());}
  double N_VV10_CS1_err= 0;	if(WZ4_CS1->Integral()>0){N_VV10_CS1_err=sqrt(w40*w40*WZ4_CS1->Integral());}

  double N_ZToNuNu_1_CS2_err = 0; if(ZToNuNu_1_CS2->Integral()>0){N_ZToNuNu_1_CS2_err=sqrt(w01*w01*ZToNuNu_1_CS2->Integral());}
  double N_ZToNuNu_2_CS2_err = 0; if(ZToNuNu_2_CS2->Integral()>0){N_ZToNuNu_2_CS2_err=sqrt(w02*w02*ZToNuNu_2_CS2->Integral());}
  double N_ZToNuNu_3_CS2_err = 0; if(ZToNuNu_3_CS2->Integral()>0){N_ZToNuNu_3_CS2_err=sqrt(w03*w03*ZToNuNu_3_CS2->Integral());}
  double N_ZToNuNu_4_CS2_err = 0; if(ZToNuNu_4_CS2->Integral()>0){N_ZToNuNu_4_CS2_err=sqrt(w04*w04*ZToNuNu_4_CS2->Integral());}
  double N_ZToNuNu_5_CS2_err = 0; if(ZToNuNu_5_CS2->Integral()>0){N_ZToNuNu_5_CS2_err=sqrt(w05*w05*ZToNuNu_5_CS2->Integral());}
  double N_ZToNuNu_6_CS2_err = 0; if(ZToNuNu_6_CS2->Integral()>0){N_ZToNuNu_6_CS2_err=sqrt(w06*w06*ZToNuNu_6_CS2->Integral());}
  double N_ZToNuNu_7_CS2_err = 0; if(ZToNuNu_7_CS2->Integral()>0){N_ZToNuNu_7_CS2_err=sqrt(w07*w07*ZToNuNu_7_CS2->Integral());}
  double N_QCD_1_CS2_err = 0; if(QCD_1_CS2->Integral()>0){N_QCD_1_CS2_err=sqrt(w08*w08*QCD_1_CS2->Integral());}
  double N_QCD_2_CS2_err = 0; if(QCD_2_CS2->Integral()>0){N_QCD_2_CS2_err=sqrt(w09*w09*QCD_2_CS2->Integral());}
  double N_QCD_3_CS2_err = 0; if(QCD_3_CS2->Integral()>0){N_QCD_3_CS2_err=sqrt(w10*w10*QCD_3_CS2->Integral());}
  double N_QCD_4_CS2_err = 0; if(QCD_4_CS2->Integral()>0){N_QCD_4_CS2_err=sqrt(w11*w11*QCD_4_CS2->Integral());}
  double N_QCD_5_CS2_err = 0; if(QCD_5_CS2->Integral()>0){N_QCD_5_CS2_err=sqrt(w12*w12*QCD_5_CS2->Integral());}
  double N_QCD_6_CS2_err = 0; if(QCD_6_CS2->Integral()>0){N_QCD_6_CS2_err=sqrt(w13*w13*QCD_6_CS2->Integral());}
  double N_QCD_7_CS2_err = 0; if(QCD_7_CS2->Integral()>0){N_QCD_7_CS2_err=sqrt(w14*w14*QCD_7_CS2->Integral());}
  double N_WToLNu_1_CS2_err = 0; if(WToLNu_1_CS2->Integral()>0){N_WToLNu_1_CS2_err=sqrt(w15*w15*WToLNu_1_CS2->Integral());}
  double N_WToLNu_2_CS2_err = 0; if(WToLNu_2_CS2->Integral()>0){N_WToLNu_2_CS2_err=sqrt(w16*w16*WToLNu_2_CS2->Integral());}
  double N_WToLNu_3_CS2_err = 0; if(WToLNu_3_CS2->Integral()>0){N_WToLNu_3_CS2_err=sqrt(w17*w17*WToLNu_3_CS2->Integral());}
  double N_WToLNu_4_CS2_err = 0; if(WToLNu_4_CS2->Integral()>0){N_WToLNu_4_CS2_err=sqrt(w18*w18*WToLNu_4_CS2->Integral());}
  double N_WToLNu_5_CS2_err = 0; if(WToLNu_5_CS2->Integral()>0){N_WToLNu_5_CS2_err=sqrt(w19*w19*WToLNu_5_CS2->Integral());}
  double N_WToLNu_6_CS2_err = 0; if(WToLNu_6_CS2->Integral()>0){N_WToLNu_6_CS2_err=sqrt(w20*w20*WToLNu_6_CS2->Integral());}
  double N_WToLNu_7_CS2_err = 0; if(WToLNu_7_CS2->Integral()>0){N_WToLNu_7_CS2_err=sqrt(w21*w21*WToLNu_7_CS2->Integral());}
  double N_TT_1_CS2_err = 0; if(TT_1_CS2->Integral()>0){N_TT_1_CS2_err=sqrt(w22*w22*TT_1_CS2->Integral());}
  double N_TT_2_CS2_err = 0; if(TT_2_CS2->Integral()>0){N_TT_2_CS2_err=sqrt(w23*w23*TT_2_CS2->Integral());}
  double N_ST_1_CS2_err = 0; if(ST_1_CS2->Integral()>0){N_ST_1_CS2_err=sqrt(w24*w24*ST_1_CS2->Integral());}
  double N_ST_2_CS2_err = 0; if(ST_2_CS2->Integral()>0){N_ST_2_CS2_err=sqrt(w25*w25*ST_2_CS2->Integral());}
  double N_ST_3_CS2_err = 0; if(ST_3_CS2->Integral()>0){N_ST_3_CS2_err=sqrt(w26*w26*ST_3_CS2->Integral());}
  double N_ST_4_CS2_err = 0; if(ST_4_CS2->Integral()>0){N_ST_4_CS2_err=sqrt(w27*w27*ST_4_CS2->Integral());}
  double N_VV1_CS2_err = 0; if(ZZ1_CS2->Integral()>0){N_VV1_CS2_err=sqrt(w28*w28*ZZ1_CS2->Integral());}
  double N_VV2_CS2_err = 0; if(ZZ2_CS2->Integral()>0){N_VV2_CS2_err=sqrt(w29*w29*ZZ2_CS2->Integral());}
  double N_VV3_CS2_err = 0; if(ZZ3_CS2->Integral()>0){N_VV3_CS2_err=sqrt(w30*w30*ZZ3_CS2->Integral());}
  double N_VV4_CS2_err = 0; if(WW1_CS2->Integral()>0){N_VV4_CS2_err=sqrt(w31*w31*WW1_CS2->Integral());}
  double N_VV5_CS2_err = 0; if(WW2_CS2->Integral()>0){N_VV5_CS2_err=sqrt(w32*w32*WW2_CS2->Integral());}
  double N_VV6_CS2_err = 0; if(WZ1_CS2->Integral()>0){N_VV6_CS2_err=sqrt(w33*w33*WZ1_CS2->Integral());}
  double N_VV7_CS2_err = 0; if(WZ2_CS2->Integral()>0){N_VV7_CS2_err=sqrt(w34*w34*WZ2_CS2->Integral());}
  double N_VV8_CS2_err = 0; if(WZ3_CS2->Integral()>0){N_VV8_CS2_err=sqrt(w35*w35*WZ3_CS2->Integral());}
  double N_ttV_1_CS2_err= 0;if(ttW_CS2->Integral()>0){N_ttV_1_CS2_err=sqrt(w36*w36*ttW_CS2->Integral());}
  double N_ttV_2_CS2_err= 0;if(ttZ_CS2->Integral()>0){N_ttV_2_CS2_err=sqrt(w37*w37*ttZ_CS2->Integral());}
  double N_ttV_3_CS2_err= 0;if(tZq_CS2->Integral()>0){N_ttV_3_CS2_err=sqrt(w38*w38*tZq_CS2->Integral());}
  double N_VV9_CS2_err = 0; if(ZZ4_CS2->Integral()>0){N_VV9_CS2_err =sqrt(w39*w39*ZZ4_CS2->Integral());}
  double N_VV10_CS2_err= 0;	if(WZ4_CS2->Integral()>0){N_VV10_CS2_err=sqrt(w40*w40*WZ4_CS2->Integral());}

  double N_ZToNuNu_1_CS3_err = 0; if(ZToNuNu_1_CS3->Integral()>0){N_ZToNuNu_1_CS3_err=sqrt(w01*w01*ZToNuNu_1_CS3->Integral());}
  double N_ZToNuNu_2_CS3_err = 0; if(ZToNuNu_2_CS3->Integral()>0){N_ZToNuNu_2_CS3_err=sqrt(w02*w02*ZToNuNu_2_CS3->Integral());}
  double N_ZToNuNu_3_CS3_err = 0; if(ZToNuNu_3_CS3->Integral()>0){N_ZToNuNu_3_CS3_err=sqrt(w03*w03*ZToNuNu_3_CS3->Integral());}
  double N_ZToNuNu_4_CS3_err = 0; if(ZToNuNu_4_CS3->Integral()>0){N_ZToNuNu_4_CS3_err=sqrt(w04*w04*ZToNuNu_4_CS3->Integral());}
  double N_ZToNuNu_5_CS3_err = 0; if(ZToNuNu_5_CS3->Integral()>0){N_ZToNuNu_5_CS3_err=sqrt(w05*w05*ZToNuNu_5_CS3->Integral());}
  double N_ZToNuNu_6_CS3_err = 0; if(ZToNuNu_6_CS3->Integral()>0){N_ZToNuNu_6_CS3_err=sqrt(w06*w06*ZToNuNu_6_CS3->Integral());}
  double N_ZToNuNu_7_CS3_err = 0; if(ZToNuNu_7_CS3->Integral()>0){N_ZToNuNu_7_CS3_err=sqrt(w07*w07*ZToNuNu_7_CS3->Integral());}
  double N_QCD_1_CS3_err = 0; if(QCD_1_CS3->Integral()>0){N_QCD_1_CS3_err=sqrt(w08*w08*QCD_1_CS3->Integral());}
  double N_QCD_2_CS3_err = 0; if(QCD_2_CS3->Integral()>0){N_QCD_2_CS3_err=sqrt(w09*w09*QCD_2_CS3->Integral());}
  double N_QCD_3_CS3_err = 0; if(QCD_3_CS3->Integral()>0){N_QCD_3_CS3_err=sqrt(w10*w10*QCD_3_CS3->Integral());}
  double N_QCD_4_CS3_err = 0; if(QCD_4_CS3->Integral()>0){N_QCD_4_CS3_err=sqrt(w11*w11*QCD_4_CS3->Integral());}
  double N_QCD_5_CS3_err = 0; if(QCD_5_CS3->Integral()>0){N_QCD_5_CS3_err=sqrt(w12*w12*QCD_5_CS3->Integral());}
  double N_QCD_6_CS3_err = 0; if(QCD_6_CS3->Integral()>0){N_QCD_6_CS3_err=sqrt(w13*w13*QCD_6_CS3->Integral());}
  double N_QCD_7_CS3_err = 0; if(QCD_7_CS3->Integral()>0){N_QCD_7_CS3_err=sqrt(w14*w14*QCD_7_CS3->Integral());}
  double N_WToLNu_1_CS3_err = 0; if(WToLNu_1_CS3->Integral()>0){N_WToLNu_1_CS3_err=sqrt(w15*w15*WToLNu_1_CS3->Integral());}
  double N_WToLNu_2_CS3_err = 0; if(WToLNu_2_CS3->Integral()>0){N_WToLNu_2_CS3_err=sqrt(w16*w16*WToLNu_2_CS3->Integral());}
  double N_WToLNu_3_CS3_err = 0; if(WToLNu_3_CS3->Integral()>0){N_WToLNu_3_CS3_err=sqrt(w17*w17*WToLNu_3_CS3->Integral());}
  double N_WToLNu_4_CS3_err = 0; if(WToLNu_4_CS3->Integral()>0){N_WToLNu_4_CS3_err=sqrt(w18*w18*WToLNu_4_CS3->Integral());}
  double N_WToLNu_5_CS3_err = 0; if(WToLNu_5_CS3->Integral()>0){N_WToLNu_5_CS3_err=sqrt(w19*w19*WToLNu_5_CS3->Integral());}
  double N_WToLNu_6_CS3_err = 0; if(WToLNu_6_CS3->Integral()>0){N_WToLNu_6_CS3_err=sqrt(w20*w20*WToLNu_6_CS3->Integral());}
  double N_WToLNu_7_CS3_err = 0; if(WToLNu_7_CS3->Integral()>0){N_WToLNu_7_CS3_err=sqrt(w21*w21*WToLNu_7_CS3->Integral());}
  double N_TT_1_CS3_err = 0; if(TT_1_CS3->Integral()>0){N_TT_1_CS3_err=sqrt(w22*w22*TT_1_CS3->Integral());}
  double N_TT_2_CS3_err = 0; if(TT_2_CS3->Integral()>0){N_TT_2_CS3_err=sqrt(w23*w23*TT_2_CS3->Integral());}
  double N_ST_1_CS3_err = 0; if(ST_1_CS3->Integral()>0){N_ST_1_CS3_err=sqrt(w24*w24*ST_1_CS3->Integral());}
  double N_ST_2_CS3_err = 0; if(ST_2_CS3->Integral()>0){N_ST_2_CS3_err=sqrt(w25*w25*ST_2_CS3->Integral());}
  double N_ST_3_CS3_err = 0; if(ST_3_CS3->Integral()>0){N_ST_3_CS3_err=sqrt(w26*w26*ST_3_CS3->Integral());}
  double N_ST_4_CS3_err = 0; if(ST_4_CS3->Integral()>0){N_ST_4_CS3_err=sqrt(w27*w27*ST_4_CS3->Integral());}
  double N_VV1_CS3_err = 0; if(ZZ1_CS3->Integral()>0){N_VV1_CS3_err=sqrt(w28*w28*ZZ1_CS3->Integral());}
  double N_VV2_CS3_err = 0; if(ZZ2_CS3->Integral()>0){N_VV2_CS3_err=sqrt(w29*w29*ZZ2_CS3->Integral());}
  double N_VV3_CS3_err = 0; if(ZZ3_CS3->Integral()>0){N_VV3_CS3_err=sqrt(w30*w30*ZZ3_CS3->Integral());}
  double N_VV4_CS3_err = 0; if(WW1_CS3->Integral()>0){N_VV4_CS3_err=sqrt(w31*w31*WW1_CS3->Integral());}
  double N_VV5_CS3_err = 0; if(WW2_CS3->Integral()>0){N_VV5_CS3_err=sqrt(w32*w32*WW2_CS3->Integral());}
  double N_VV6_CS3_err = 0; if(WZ1_CS3->Integral()>0){N_VV6_CS3_err=sqrt(w33*w33*WZ1_CS3->Integral());}
  double N_VV7_CS3_err = 0; if(WZ2_CS3->Integral()>0){N_VV7_CS3_err=sqrt(w34*w34*WZ2_CS3->Integral());}
  double N_VV8_CS3_err = 0; if(WZ3_CS3->Integral()>0){N_VV8_CS3_err=sqrt(w35*w35*WZ3_CS3->Integral());}
  double N_ttV_1_CS3_err= 0;if(ttW_CS3->Integral()>0){N_ttV_1_CS3_err=sqrt(w36*w36*ttW_CS3->Integral());}
  double N_ttV_2_CS3_err= 0;if(ttZ_CS3->Integral()>0){N_ttV_2_CS3_err=sqrt(w37*w37*ttZ_CS3->Integral());}
  double N_ttV_3_CS3_err= 0;if(tZq_CS3->Integral()>0){N_ttV_3_CS3_err=sqrt(w38*w38*tZq_CS3->Integral());}
  double N_VV9_CS3_err = 0; if(ZZ4_CS3->Integral()>0){N_VV9_CS3_err =sqrt(w39*w39*ZZ4_CS3->Integral());}
  double N_VV10_CS3_err= 0;	if(WZ4_CS3->Integral()>0){N_VV10_CS3_err=sqrt(w40*w40*WZ4_CS3->Integral());}

  double N_ZToNuNu_CS1_err  = N_ZToNuNu_1_CS1_err*N_ZToNuNu_1_CS1_err+N_ZToNuNu_2_CS1_err*N_ZToNuNu_2_CS1_err+N_ZToNuNu_3_CS1_err*N_ZToNuNu_3_CS1_err+N_ZToNuNu_4_CS1_err*N_ZToNuNu_4_CS1_err+N_ZToNuNu_5_CS1_err*N_ZToNuNu_5_CS1_err+N_ZToNuNu_6_CS1_err*N_ZToNuNu_6_CS1_err+N_ZToNuNu_7_CS1_err*N_ZToNuNu_7_CS1_err;
  double N_QCD_CS1_err      = N_QCD_1_CS1_err*N_QCD_1_CS1_err+N_QCD_2_CS1_err*N_QCD_2_CS1_err+N_QCD_3_CS1_err*N_QCD_3_CS1_err+N_QCD_4_CS1_err*N_QCD_4_CS1_err+N_QCD_5_CS1_err*N_QCD_5_CS1_err+N_QCD_6_CS1_err*N_QCD_6_CS1_err+N_QCD_7_CS1_err*N_QCD_7_CS1_err;
  double N_WToLNu_CS1_err   = N_WToLNu_1_CS1_err*N_WToLNu_1_CS1_err+N_WToLNu_2_CS1_err*N_WToLNu_2_CS1_err+N_WToLNu_3_CS1_err*N_WToLNu_3_CS1_err+N_WToLNu_4_CS1_err*N_WToLNu_4_CS1_err+N_WToLNu_5_CS1_err*N_WToLNu_5_CS1_err+N_WToLNu_6_CS1_err*N_WToLNu_6_CS1_err+N_WToLNu_7_CS1_err*N_WToLNu_7_CS1_err;
  double N_ST_CS1_err       = N_ST_1_CS1_err*N_ST_1_CS1_err+N_ST_2_CS1_err*N_ST_2_CS1_err+N_ST_3_CS1_err*N_ST_3_CS1_err+N_ST_4_CS1_err*N_ST_4_CS1_err; 
  double N_TT_CS1_err       = N_TT_1_CS1_err*N_TT_1_CS1_err+N_TT_2_CS1_err*N_TT_2_CS1_err;
  double N_VV_CS1_err       = N_VV1_CS1_err*N_VV1_CS1_err+N_VV2_CS1_err*N_VV2_CS1_err+N_VV3_CS1_err*N_VV3_CS1_err+N_VV4_CS1_err*N_VV4_CS1_err+N_VV5_CS1_err*N_VV5_CS1_err+N_VV6_CS1_err*N_VV6_CS1_err+N_VV7_CS1_err*N_VV7_CS1_err+N_VV8_CS1_err*N_VV8_CS1_err+N_VV9_CS1_err*N_VV9_CS1_err+N_VV10_CS1_err*N_VV10_CS1_err; 
  double N_ttV_CS1_err      = N_ttV_1_CS1_err*N_ttV_1_CS1_err+N_ttV_2_CS1_err*N_ttV_2_CS1_err+N_ttV_3_CS1_err*N_ttV_3_CS1_err;

  double N_ZToNuNu_CS2_err  = N_ZToNuNu_1_CS2_err*N_ZToNuNu_1_CS2_err+N_ZToNuNu_2_CS2_err*N_ZToNuNu_2_CS2_err+N_ZToNuNu_3_CS2_err*N_ZToNuNu_3_CS2_err+N_ZToNuNu_4_CS2_err*N_ZToNuNu_4_CS2_err+N_ZToNuNu_5_CS2_err*N_ZToNuNu_5_CS2_err+N_ZToNuNu_6_CS2_err*N_ZToNuNu_6_CS2_err+N_ZToNuNu_7_CS2_err*N_ZToNuNu_7_CS2_err;
  double N_QCD_CS2_err      = N_QCD_1_CS2_err*N_QCD_1_CS2_err+N_QCD_2_CS2_err*N_QCD_2_CS2_err+N_QCD_3_CS2_err*N_QCD_3_CS2_err+N_QCD_4_CS2_err*N_QCD_4_CS2_err+N_QCD_5_CS2_err*N_QCD_5_CS2_err+N_QCD_6_CS2_err*N_QCD_6_CS2_err+N_QCD_7_CS2_err*N_QCD_7_CS2_err;
  double N_WToLNu_CS2_err   = N_WToLNu_1_CS2_err*N_WToLNu_1_CS2_err+N_WToLNu_2_CS2_err*N_WToLNu_2_CS2_err+N_WToLNu_3_CS2_err*N_WToLNu_3_CS2_err+N_WToLNu_4_CS2_err*N_WToLNu_4_CS2_err+N_WToLNu_5_CS2_err*N_WToLNu_5_CS2_err+N_WToLNu_6_CS2_err*N_WToLNu_6_CS2_err+N_WToLNu_7_CS2_err*N_WToLNu_7_CS2_err;
  double N_ST_CS2_err       = N_ST_1_CS2_err*N_ST_1_CS2_err+N_ST_2_CS2_err*N_ST_2_CS2_err+N_ST_3_CS2_err*N_ST_3_CS2_err+N_ST_4_CS2_err*N_ST_4_CS2_err; 
  double N_TT_CS2_err       = N_TT_1_CS2_err*N_TT_1_CS2_err+N_TT_2_CS2_err*N_TT_2_CS2_err;
  double N_VV_CS2_err       = N_VV1_CS2_err*N_VV1_CS2_err+N_VV2_CS2_err*N_VV2_CS2_err+N_VV3_CS2_err*N_VV3_CS2_err+N_VV4_CS2_err*N_VV4_CS2_err+N_VV5_CS2_err*N_VV5_CS2_err+N_VV6_CS2_err*N_VV6_CS2_err+N_VV7_CS2_err*N_VV7_CS2_err+N_VV8_CS2_err*N_VV8_CS2_err+N_VV9_CS2_err*N_VV9_CS2_err+N_VV10_CS2_err*N_VV10_CS2_err; 
  double N_ttV_CS2_err      = N_ttV_1_CS2_err*N_ttV_1_CS2_err+N_ttV_2_CS2_err*N_ttV_2_CS2_err+N_ttV_3_CS2_err*N_ttV_3_CS2_err;

  double N_ZToNuNu_CS3_err  = N_ZToNuNu_1_CS3_err*N_ZToNuNu_1_CS3_err+N_ZToNuNu_2_CS3_err*N_ZToNuNu_2_CS3_err+N_ZToNuNu_3_CS3_err*N_ZToNuNu_3_CS3_err+N_ZToNuNu_4_CS3_err*N_ZToNuNu_4_CS3_err+N_ZToNuNu_5_CS3_err*N_ZToNuNu_5_CS3_err+N_ZToNuNu_6_CS3_err*N_ZToNuNu_6_CS3_err+N_ZToNuNu_7_CS3_err*N_ZToNuNu_7_CS3_err;
  double N_QCD_CS3_err      = N_QCD_1_CS3_err*N_QCD_1_CS3_err+N_QCD_2_CS3_err*N_QCD_2_CS3_err+N_QCD_3_CS3_err*N_QCD_3_CS3_err+N_QCD_4_CS3_err*N_QCD_4_CS3_err+N_QCD_5_CS3_err*N_QCD_5_CS3_err+N_QCD_6_CS3_err*N_QCD_6_CS3_err+N_QCD_7_CS3_err*N_QCD_7_CS3_err;
  double N_WToLNu_CS3_err   = N_WToLNu_1_CS3_err*N_WToLNu_1_CS3_err+N_WToLNu_2_CS3_err*N_WToLNu_2_CS3_err+N_WToLNu_3_CS3_err*N_WToLNu_3_CS3_err+N_WToLNu_4_CS3_err*N_WToLNu_4_CS3_err+N_WToLNu_5_CS3_err*N_WToLNu_5_CS3_err+N_WToLNu_6_CS3_err*N_WToLNu_6_CS3_err+N_WToLNu_7_CS3_err*N_WToLNu_7_CS3_err;
  double N_ST_CS3_err       = N_ST_1_CS3_err*N_ST_1_CS3_err+N_ST_2_CS3_err*N_ST_2_CS3_err+N_ST_3_CS3_err*N_ST_3_CS3_err+N_ST_4_CS3_err*N_ST_4_CS3_err; 
  double N_TT_CS3_err       = N_TT_1_CS3_err*N_TT_1_CS3_err+N_TT_2_CS3_err*N_TT_2_CS3_err;
  double N_VV_CS3_err       = N_VV1_CS3_err*N_VV1_CS3_err+N_VV2_CS3_err*N_VV2_CS3_err+N_VV3_CS3_err*N_VV3_CS3_err+N_VV4_CS3_err*N_VV4_CS3_err+N_VV5_CS3_err*N_VV5_CS3_err+N_VV6_CS3_err*N_VV6_CS3_err+N_VV7_CS3_err*N_VV7_CS3_err+N_VV8_CS3_err*N_VV8_CS3_err+N_VV9_CS3_err*N_VV9_CS3_err+N_VV10_CS3_err*N_VV10_CS3_err; 
  double N_ttV_CS3_err      = N_ttV_1_CS3_err*N_ttV_1_CS3_err+N_ttV_2_CS3_err*N_ttV_2_CS3_err+N_ttV_3_CS3_err*N_ttV_3_CS3_err;

    double N_data_CS1 = 0;      if(data_CS1->Integral()>0){N_data_CS1 = data_CS1->Integral();}
    double N_ZToNuNu_1_CS1 = 0; if(ZToNuNu_1_CS1->Integral()>0){N_ZToNuNu_1_CS1 =w01*ZToNuNu_1_CS1->Integral();}
    double N_ZToNuNu_2_CS1 = 0; if(ZToNuNu_2_CS1->Integral()>0){N_ZToNuNu_2_CS1 =w02*ZToNuNu_2_CS1->Integral();}
    double N_ZToNuNu_3_CS1 = 0; if(ZToNuNu_3_CS1->Integral()>0){N_ZToNuNu_3_CS1 =w03*ZToNuNu_3_CS1->Integral();}
    double N_ZToNuNu_4_CS1 = 0; if(ZToNuNu_4_CS1->Integral()>0){N_ZToNuNu_4_CS1 =w04*ZToNuNu_4_CS1->Integral();}
    double N_ZToNuNu_5_CS1 = 0; if(ZToNuNu_5_CS1->Integral()>0){N_ZToNuNu_5_CS1 =w05*ZToNuNu_5_CS1->Integral();}
    double N_ZToNuNu_6_CS1 = 0; if(ZToNuNu_6_CS1->Integral()>0){N_ZToNuNu_6_CS1 =w06*ZToNuNu_6_CS1->Integral();}
    double N_ZToNuNu_7_CS1 = 0; if(ZToNuNu_7_CS1->Integral()>0){N_ZToNuNu_7_CS1 =w07*ZToNuNu_7_CS1->Integral();}
    double N_QCD_1_CS1     = 0; if(QCD_1_CS1->Integral()>0){N_QCD_1_CS1 =w08*QCD_1_CS1->Integral();}
    double N_QCD_2_CS1     = 0; if(QCD_2_CS1->Integral()>0){N_QCD_2_CS1 =w09*QCD_2_CS1->Integral();}
    double N_QCD_3_CS1     = 0; if(QCD_3_CS1->Integral()>0){N_QCD_3_CS1 =w10*QCD_3_CS1->Integral();}
    double N_QCD_4_CS1     = 0; if(QCD_4_CS1->Integral()>0){N_QCD_4_CS1 =w11*QCD_4_CS1->Integral();}
    double N_QCD_5_CS1     = 0; if(QCD_5_CS1->Integral()>0){N_QCD_5_CS1 =w12*QCD_5_CS1->Integral();}
    double N_QCD_6_CS1     = 0; if(QCD_6_CS1->Integral()>0){N_QCD_6_CS1 =w13*QCD_6_CS1->Integral();}
    double N_QCD_7_CS1     = 0; if(QCD_7_CS1->Integral()>0){N_QCD_7_CS1 =w14*QCD_7_CS1->Integral();}
    double N_WToLNu_1_CS1  = 0; if(WToLNu_1_CS1->Integral()>0){N_WToLNu_1_CS1 =w15*WToLNu_1_CS1->Integral();}
    double N_WToLNu_2_CS1  = 0; if(WToLNu_2_CS1->Integral()>0){N_WToLNu_2_CS1 =w16*WToLNu_2_CS1->Integral();}
    double N_WToLNu_3_CS1  = 0; if(WToLNu_3_CS1->Integral()>0){N_WToLNu_3_CS1 =w17*WToLNu_3_CS1->Integral();}
    double N_WToLNu_4_CS1  = 0; if(WToLNu_4_CS1->Integral()>0){N_WToLNu_4_CS1 =w18*WToLNu_4_CS1->Integral();}
    double N_WToLNu_5_CS1  = 0; if(WToLNu_5_CS1->Integral()>0){N_WToLNu_5_CS1 =w19*WToLNu_5_CS1->Integral();}
    double N_WToLNu_6_CS1  = 0; if(WToLNu_6_CS1->Integral()>0){N_WToLNu_6_CS1 =w20*WToLNu_6_CS1->Integral();}
    double N_WToLNu_7_CS1  = 0; if(WToLNu_7_CS1->Integral()>0){N_WToLNu_7_CS1 =w21*WToLNu_7_CS1->Integral();}
    double N_TT_1_CS1     = 0; if(TT_1_CS1->Integral()>0){N_TT_1_CS1 =w22*TT_1_CS1->Integral();}
    double N_TT_2_CS1     = 0; if(TT_2_CS1->Integral()>0){N_TT_2_CS1 =w23*TT_2_CS1->Integral();}
    double N_ST_1_CS1     = 0; if(ST_1_CS1->Integral()>0){N_ST_1_CS1 =w24*ST_1_CS1->Integral();}
    double N_ST_2_CS1     = 0; if(ST_2_CS1->Integral()>0){N_ST_2_CS1 =w25*ST_2_CS1->Integral();}
    double N_ST_3_CS1     = 0; if(ST_3_CS1->Integral()>0){N_ST_3_CS1 =w26*ST_3_CS1->Integral();}
    double N_ST_4_CS1     = 0; if(ST_4_CS1->Integral()>0){N_ST_4_CS1 =w27*ST_4_CS1->Integral();}
    double N_VV1_CS1     = 0; if(ZZ1_CS1->Integral()>0){N_VV1_CS1 =w28*ZZ1_CS1->Integral();}
    double N_VV2_CS1     = 0; if(ZZ2_CS1->Integral()>0){N_VV2_CS1 =w29*ZZ2_CS1->Integral();}
    double N_VV3_CS1     = 0; if(ZZ3_CS1->Integral()>0){N_VV3_CS1 =w30*ZZ3_CS1->Integral();}
    double N_VV4_CS1     = 0; if(WW1_CS1->Integral()>0){N_VV4_CS1 =w31*WW1_CS1->Integral();}
    double N_VV5_CS1     = 0; if(WW2_CS1->Integral()>0){N_VV5_CS1 =w32*WW2_CS1->Integral();}
    double N_VV6_CS1     = 0; if(WZ1_CS1->Integral()>0){N_VV6_CS1 =w33*WZ1_CS1->Integral();}
    double N_VV7_CS1     = 0; if(WZ2_CS1->Integral()>0){N_VV7_CS1 =w34*WZ2_CS1->Integral();}
    double N_VV8_CS1     = 0; if(WZ3_CS1->Integral()>0){N_VV8_CS1 =w35*WZ3_CS1->Integral();}
    double N_ttV_1_CS1   = 0; if(ttW_CS1->Integral()>0){N_ttV_1_CS1=w36*ttW_CS1->Integral();}
    double N_ttV_2_CS1   = 0; if(ttZ_CS1->Integral()>0){N_ttV_2_CS1=w37*ttZ_CS1->Integral();}
    double N_ttV_3_CS1   = 0; if(tZq_CS1->Integral()>0){N_ttV_3_CS1=w38*tZq_CS1->Integral();}
    double N_VV9_CS1     = 0; if(ZZ4_CS1->Integral()>0){N_VV9_CS1 =w39*ZZ4_CS1->Integral();}
    double N_VV10_CS1    = 0; if(WZ4_CS1->Integral()>0){N_VV10_CS1=w40*WZ4_CS1->Integral();}


    double N_data_CS2 = 0;      if(data_CS2->Integral()>0){N_data_CS2 = data_CS2->Integral();}
    double N_ZToNuNu_1_CS2 = 0; if(ZToNuNu_1_CS2->Integral()>0){N_ZToNuNu_1_CS2 =w01*ZToNuNu_1_CS2->Integral();}
    double N_ZToNuNu_2_CS2 = 0; if(ZToNuNu_2_CS2->Integral()>0){N_ZToNuNu_2_CS2 =w02*ZToNuNu_2_CS2->Integral();}
    double N_ZToNuNu_3_CS2 = 0; if(ZToNuNu_3_CS2->Integral()>0){N_ZToNuNu_3_CS2 =w03*ZToNuNu_3_CS2->Integral();}
    double N_ZToNuNu_4_CS2 = 0; if(ZToNuNu_4_CS2->Integral()>0){N_ZToNuNu_4_CS2 =w04*ZToNuNu_4_CS2->Integral();}
    double N_ZToNuNu_5_CS2 = 0; if(ZToNuNu_5_CS2->Integral()>0){N_ZToNuNu_5_CS2 =w05*ZToNuNu_5_CS2->Integral();}
    double N_ZToNuNu_6_CS2 = 0; if(ZToNuNu_6_CS2->Integral()>0){N_ZToNuNu_6_CS2 =w06*ZToNuNu_6_CS2->Integral();}
    double N_ZToNuNu_7_CS2 = 0; if(ZToNuNu_7_CS2->Integral()>0){N_ZToNuNu_7_CS2 =w07*ZToNuNu_7_CS2->Integral();}
    double N_QCD_1_CS2     = 0; if(QCD_1_CS2->Integral()>0){N_QCD_1_CS2 =w08*QCD_1_CS2->Integral();}
    double N_QCD_2_CS2     = 0; if(QCD_2_CS2->Integral()>0){N_QCD_2_CS2 =w09*QCD_2_CS2->Integral();}
    double N_QCD_3_CS2     = 0; if(QCD_3_CS2->Integral()>0){N_QCD_3_CS2 =w10*QCD_3_CS2->Integral();}
    double N_QCD_4_CS2     = 0; if(QCD_4_CS2->Integral()>0){N_QCD_4_CS2 =w11*QCD_4_CS2->Integral();}
    double N_QCD_5_CS2     = 0; if(QCD_5_CS2->Integral()>0){N_QCD_5_CS2 =w12*QCD_5_CS2->Integral();}
    double N_QCD_6_CS2     = 0; if(QCD_6_CS2->Integral()>0){N_QCD_6_CS2 =w13*QCD_6_CS2->Integral();}
    double N_QCD_7_CS2     = 0; if(QCD_7_CS2->Integral()>0){N_QCD_7_CS2 =w14*QCD_7_CS2->Integral();}
    double N_WToLNu_1_CS2  = 0; if(WToLNu_1_CS2->Integral()>0){N_WToLNu_1_CS2 =w15*WToLNu_1_CS2->Integral();}
    double N_WToLNu_2_CS2  = 0; if(WToLNu_2_CS2->Integral()>0){N_WToLNu_2_CS2 =w16*WToLNu_2_CS2->Integral();}
    double N_WToLNu_3_CS2  = 0; if(WToLNu_3_CS2->Integral()>0){N_WToLNu_3_CS2 =w17*WToLNu_3_CS2->Integral();}
    double N_WToLNu_4_CS2  = 0; if(WToLNu_4_CS2->Integral()>0){N_WToLNu_4_CS2 =w18*WToLNu_4_CS2->Integral();}
    double N_WToLNu_5_CS2  = 0; if(WToLNu_5_CS2->Integral()>0){N_WToLNu_5_CS2 =w19*WToLNu_5_CS2->Integral();}
    double N_WToLNu_6_CS2  = 0; if(WToLNu_6_CS2->Integral()>0){N_WToLNu_6_CS2 =w20*WToLNu_6_CS2->Integral();}
    double N_WToLNu_7_CS2  = 0; if(WToLNu_7_CS2->Integral()>0){N_WToLNu_7_CS2 =w21*WToLNu_7_CS2->Integral();}
    double N_TT_1_CS2     = 0; if(TT_1_CS2->Integral()>0){N_TT_1_CS2 =w22*TT_1_CS2->Integral();}
    double N_TT_2_CS2     = 0; if(TT_2_CS2->Integral()>0){N_TT_2_CS2 =w23*TT_2_CS2->Integral();}
    double N_ST_1_CS2     = 0; if(ST_1_CS2->Integral()>0){N_ST_1_CS2 =w24*ST_1_CS2->Integral();}
    double N_ST_2_CS2     = 0; if(ST_2_CS2->Integral()>0){N_ST_2_CS2 =w25*ST_2_CS2->Integral();}
    double N_ST_3_CS2     = 0; if(ST_3_CS2->Integral()>0){N_ST_3_CS2 =w26*ST_3_CS2->Integral();}
    double N_ST_4_CS2     = 0; if(ST_4_CS2->Integral()>0){N_ST_4_CS2 =w27*ST_4_CS2->Integral();}
    double N_VV1_CS2     = 0; if(ZZ1_CS2->Integral()>0){N_VV1_CS2 =w28*ZZ1_CS2->Integral();}
    double N_VV2_CS2     = 0; if(ZZ2_CS2->Integral()>0){N_VV2_CS2 =w29*ZZ2_CS2->Integral();}
    double N_VV3_CS2     = 0; if(ZZ3_CS2->Integral()>0){N_VV3_CS2 =w30*ZZ3_CS2->Integral();}
    double N_VV4_CS2     = 0; if(WW1_CS2->Integral()>0){N_VV4_CS2 =w31*WW1_CS2->Integral();}
    double N_VV5_CS2     = 0; if(WW2_CS2->Integral()>0){N_VV5_CS2 =w32*WW2_CS2->Integral();}
    double N_VV6_CS2     = 0; if(WZ1_CS2->Integral()>0){N_VV6_CS2 =w33*WZ1_CS2->Integral();}
    double N_VV7_CS2     = 0; if(WZ2_CS2->Integral()>0){N_VV7_CS2 =w34*WZ2_CS2->Integral();}
    double N_VV8_CS2     = 0; if(WZ3_CS2->Integral()>0){N_VV8_CS2 =w35*WZ3_CS2->Integral();}
    double N_ttV_1_CS2   = 0; if(ttW_CS2->Integral()>0){N_ttV_1_CS2=w36*ttW_CS2->Integral();}
    double N_ttV_2_CS2   = 0; if(ttZ_CS2->Integral()>0){N_ttV_2_CS2=w37*ttZ_CS2->Integral();}
    double N_ttV_3_CS2   = 0; if(tZq_CS2->Integral()>0){N_ttV_3_CS2=w38*tZq_CS2->Integral();}
    double N_VV9_CS2     = 0; if(ZZ4_CS2->Integral()>0){N_VV9_CS2 =w39*ZZ4_CS2->Integral();}
    double N_VV10_CS2    = 0; if(WZ4_CS2->Integral()>0){N_VV10_CS2=w40*WZ4_CS2->Integral();}

    double N_data_CS3 = 0;      if(data_CS3->Integral()>0){N_data_CS3 = data_CS3->Integral();}
    double N_ZToNuNu_1_CS3 = 0; if(ZToNuNu_1_CS3->Integral()>0){N_ZToNuNu_1_CS3 =w01*ZToNuNu_1_CS3->Integral();}
    double N_ZToNuNu_2_CS3 = 0; if(ZToNuNu_2_CS3->Integral()>0){N_ZToNuNu_2_CS3 =w02*ZToNuNu_2_CS3->Integral();}
    double N_ZToNuNu_3_CS3 = 0; if(ZToNuNu_3_CS3->Integral()>0){N_ZToNuNu_3_CS3 =w03*ZToNuNu_3_CS3->Integral();}
    double N_ZToNuNu_4_CS3 = 0; if(ZToNuNu_4_CS3->Integral()>0){N_ZToNuNu_4_CS3 =w04*ZToNuNu_4_CS3->Integral();}
    double N_ZToNuNu_5_CS3 = 0; if(ZToNuNu_5_CS3->Integral()>0){N_ZToNuNu_5_CS3 =w05*ZToNuNu_5_CS3->Integral();}
    double N_ZToNuNu_6_CS3 = 0; if(ZToNuNu_6_CS3->Integral()>0){N_ZToNuNu_6_CS3 =w06*ZToNuNu_6_CS3->Integral();}
    double N_ZToNuNu_7_CS3 = 0; if(ZToNuNu_7_CS3->Integral()>0){N_ZToNuNu_7_CS3 =w07*ZToNuNu_7_CS3->Integral();}
    double N_QCD_1_CS3     = 0; if(QCD_1_CS3->Integral()>0){N_QCD_1_CS3 =w08*QCD_1_CS3->Integral();}
    double N_QCD_2_CS3     = 0; if(QCD_2_CS3->Integral()>0){N_QCD_2_CS3 =w09*QCD_2_CS3->Integral();}
    double N_QCD_3_CS3     = 0; if(QCD_3_CS3->Integral()>0){N_QCD_3_CS3 =w10*QCD_3_CS3->Integral();}
    double N_QCD_4_CS3     = 0; if(QCD_4_CS3->Integral()>0){N_QCD_4_CS3 =w11*QCD_4_CS3->Integral();}
    double N_QCD_5_CS3     = 0; if(QCD_5_CS3->Integral()>0){N_QCD_5_CS3 =w12*QCD_5_CS3->Integral();}
    double N_QCD_6_CS3     = 0; if(QCD_6_CS3->Integral()>0){N_QCD_6_CS3 =w13*QCD_6_CS3->Integral();}
    double N_QCD_7_CS3     = 0; if(QCD_7_CS3->Integral()>0){N_QCD_7_CS3 =w14*QCD_7_CS3->Integral();}
    double N_WToLNu_1_CS3  = 0; if(WToLNu_1_CS3->Integral()>0){N_WToLNu_1_CS3 =w15*WToLNu_1_CS3->Integral();}
    double N_WToLNu_2_CS3  = 0; if(WToLNu_2_CS3->Integral()>0){N_WToLNu_2_CS3 =w16*WToLNu_2_CS3->Integral();}
    double N_WToLNu_3_CS3  = 0; if(WToLNu_3_CS3->Integral()>0){N_WToLNu_3_CS3 =w17*WToLNu_3_CS3->Integral();}
    double N_WToLNu_4_CS3  = 0; if(WToLNu_4_CS3->Integral()>0){N_WToLNu_4_CS3 =w18*WToLNu_4_CS3->Integral();}
    double N_WToLNu_5_CS3  = 0; if(WToLNu_5_CS3->Integral()>0){N_WToLNu_5_CS3 =w19*WToLNu_5_CS3->Integral();}
    double N_WToLNu_6_CS3  = 0; if(WToLNu_6_CS3->Integral()>0){N_WToLNu_6_CS3 =w20*WToLNu_6_CS3->Integral();}
    double N_WToLNu_7_CS3  = 0; if(WToLNu_7_CS3->Integral()>0){N_WToLNu_7_CS3 =w21*WToLNu_7_CS3->Integral();}
    double N_TT_1_CS3     = 0; if(TT_1_CS3->Integral()>0){N_TT_1_CS3 =w22*TT_1_CS3->Integral();}
    double N_TT_2_CS3     = 0; if(TT_2_CS3->Integral()>0){N_TT_2_CS3 =w23*TT_2_CS3->Integral();}
    double N_ST_1_CS3     = 0; if(ST_1_CS3->Integral()>0){N_ST_1_CS3 =w24*ST_1_CS3->Integral();}
    double N_ST_2_CS3     = 0; if(ST_2_CS3->Integral()>0){N_ST_2_CS3 =w25*ST_2_CS3->Integral();}
    double N_ST_3_CS3     = 0; if(ST_3_CS3->Integral()>0){N_ST_3_CS3 =w26*ST_3_CS3->Integral();}
    double N_ST_4_CS3     = 0; if(ST_4_CS3->Integral()>0){N_ST_4_CS3 =w27*ST_4_CS3->Integral();}
    double N_VV1_CS3     = 0; if(ZZ1_CS3->Integral()>0){N_VV1_CS3 =w28*ZZ1_CS3->Integral();}
    double N_VV2_CS3     = 0; if(ZZ2_CS3->Integral()>0){N_VV2_CS3 =w29*ZZ2_CS3->Integral();}
    double N_VV3_CS3     = 0; if(ZZ3_CS3->Integral()>0){N_VV3_CS3 =w30*ZZ3_CS3->Integral();}
    double N_VV4_CS3     = 0; if(WW1_CS3->Integral()>0){N_VV4_CS3 =w31*WW1_CS3->Integral();}
    double N_VV5_CS3     = 0; if(WW2_CS3->Integral()>0){N_VV5_CS3 =w32*WW2_CS3->Integral();}
    double N_VV6_CS3     = 0; if(WZ1_CS3->Integral()>0){N_VV6_CS3 =w33*WZ1_CS3->Integral();}
    double N_VV7_CS3     = 0; if(WZ2_CS3->Integral()>0){N_VV7_CS3 =w34*WZ2_CS3->Integral();}
    double N_VV8_CS3     = 0; if(WZ3_CS3->Integral()>0){N_VV8_CS3 =w35*WZ3_CS3->Integral();}
    double N_ttV_1_CS3   = 0; if(ttW_CS3->Integral()>0){N_ttV_1_CS3=w36*ttW_CS3->Integral();}
    double N_ttV_2_CS3   = 0; if(ttZ_CS3->Integral()>0){N_ttV_2_CS3=w37*ttZ_CS3->Integral();}
    double N_ttV_3_CS3   = 0; if(tZq_CS3->Integral()>0){N_ttV_3_CS3=w38*tZq_CS3->Integral();}
    double N_VV9_CS3     = 0; if(ZZ4_CS3->Integral()>0){N_VV9_CS3 =w39*ZZ4_CS3->Integral();}
    double N_VV10_CS3    = 0; if(WZ4_CS3->Integral()>0){N_VV10_CS3=w40*WZ4_CS3->Integral();}
	
  double N_ZToNuNu_CS1 = N_ZToNuNu_1_CS1+N_ZToNuNu_2_CS1+N_ZToNuNu_3_CS1+N_ZToNuNu_4_CS1+N_ZToNuNu_5_CS1+N_ZToNuNu_6_CS1+N_ZToNuNu_7_CS1;
  double N_QCD_CS1     = N_QCD_1_CS1+N_QCD_2_CS1+N_QCD_3_CS1+N_QCD_4_CS1+N_QCD_5_CS1+N_QCD_6_CS1+N_QCD_7_CS1;
  double N_WToLNu_CS1  = N_WToLNu_1_CS1+N_WToLNu_2_CS1+N_WToLNu_3_CS1+N_WToLNu_4_CS1+N_WToLNu_5_CS1+N_WToLNu_6_CS1+N_WToLNu_7_CS1;
  double N_ST_CS1      = N_ST_1_CS1+N_ST_2_CS1+N_ST_3_CS1+N_ST_4_CS1;
  double N_TT_CS1      = N_TT_1_CS1+N_TT_2_CS1;
  double N_VV_CS1      = N_VV1_CS1+N_VV2_CS1+N_VV3_CS1+N_VV4_CS1+N_VV5_CS1+N_VV6_CS1+N_VV7_CS1+N_VV8_CS1+N_VV9_CS1+N_VV10_CS1;
  double N_ttV_CS1     = N_ttV_1_CS1+N_ttV_2_CS1+N_ttV_3_CS1;	

  double N_ZToNuNu_CS2 = N_ZToNuNu_1_CS2+N_ZToNuNu_2_CS2+N_ZToNuNu_3_CS2+N_ZToNuNu_4_CS2+N_ZToNuNu_5_CS2+N_ZToNuNu_6_CS2+N_ZToNuNu_7_CS2;
  double N_QCD_CS2     = N_QCD_1_CS2+N_QCD_2_CS2+N_QCD_3_CS2+N_QCD_4_CS2+N_QCD_5_CS2+N_QCD_6_CS2+N_QCD_7_CS2;
  double N_WToLNu_CS2  = N_WToLNu_1_CS2+N_WToLNu_2_CS2+N_WToLNu_3_CS2+N_WToLNu_4_CS2+N_WToLNu_5_CS2+N_WToLNu_6_CS2+N_WToLNu_7_CS2;
  double N_ST_CS2      = N_ST_1_CS2+N_ST_2_CS2+N_ST_3_CS2+N_ST_4_CS2;
  double N_TT_CS2      = N_TT_1_CS2+N_TT_2_CS2;
  double N_VV_CS2      = N_VV1_CS2+N_VV2_CS2+N_VV3_CS2+N_VV4_CS2+N_VV5_CS2+N_VV6_CS2+N_VV7_CS2+N_VV8_CS2+N_VV9_CS2+N_VV10_CS2;
  double N_ttV_CS2     = N_ttV_1_CS2+N_ttV_2_CS2+N_ttV_3_CS2;

  double N_ZToNuNu_CS3 = N_ZToNuNu_1_CS3+N_ZToNuNu_2_CS3+N_ZToNuNu_3_CS3+N_ZToNuNu_4_CS3+N_ZToNuNu_5_CS3+N_ZToNuNu_6_CS3+N_ZToNuNu_7_CS3;
  double N_QCD_CS3     = N_QCD_1_CS3+N_QCD_2_CS3+N_QCD_3_CS3+N_QCD_4_CS3+N_QCD_5_CS3+N_QCD_6_CS3+N_QCD_7_CS3;
  double N_WToLNu_CS3  = N_WToLNu_1_CS3+N_WToLNu_2_CS3+N_WToLNu_3_CS3+N_WToLNu_4_CS3+N_WToLNu_5_CS3+N_WToLNu_6_CS3+N_WToLNu_7_CS3;
  double N_ST_CS3      = N_ST_1_CS3+N_ST_2_CS3+N_ST_3_CS3+N_ST_4_CS3;
  double N_TT_CS3      = N_TT_1_CS3+N_TT_2_CS3;
  double N_VV_CS3      = N_VV1_CS3+N_VV2_CS3+N_VV3_CS3+N_VV4_CS3+N_VV5_CS3+N_VV6_CS3+N_VV7_CS3+N_VV8_CS3+N_VV9_CS3+N_VV10_CS3;
  double N_ttV_CS3     = N_ttV_1_CS3+N_ttV_2_CS3+N_ttV_3_CS3;
  //N(CS1 in data) = SF1*N(Znunu in MC) + SF2*N(WJets in MC) + SF3*N(ttbar in MC) + N(other bkgs in MC)
  //N(CS2 in data) = SF1*N(Znunu in MC) + SF2*N(WJets in MC) + SF3*N(ttbar in MC) + N(other bkgs in MC)
  //N(CS3 in data) = SF1*N(Znunu in MC) + SF2*N(WJets in MC) + SF3*N(ttbar in MC) + N(other bkgs in MC)
  double a1 = N_ZToNuNu_CS1;  double b1 = N_WToLNu_CS1;  double c1 = N_TT_CS1 + N_ST_CS1 + N_ttV_CS1;  double d1 = N_QCD_CS1 + N_VV_CS1 - N_data_CS1;
  double a2 = N_ZToNuNu_CS2;  double b2 = N_WToLNu_CS2;  double c2 = N_TT_CS2 + N_ST_CS2 + N_ttV_CS2;  double d2 = N_QCD_CS2 + N_VV_CS2 - N_data_CS2;
  double a3 = N_ZToNuNu_CS3;  double b3 = N_WToLNu_CS3;  double c3 = N_TT_CS3 + N_ST_CS3 + N_ttV_CS3;  double d3 = N_QCD_CS3 + N_VV_CS3 - N_data_CS3;

  if(category==1||category==2) { a1=a1*SF1; a2=a2*SF1; a3=a3*SF1;}
  if(category==3||category==4) { b1=b1*SF2; b2=b2*SF2; b3=b3*SF2;}
  if(category==5||category==6) { c1=c1*SF3; c2=c2*SF3; c3=c3*SF3;}
 
  cout<<"N_ZToNuNu_CS1 = "<< a1 <<endl;  cout<<"N_ZToNuNu_CS2 = "<< a2 <<endl; cout<<"N_ZToNuNu_CS3 = "<< a3 <<endl;
  cout<<"N_WToLNu_CS1 = "<< b1 <<endl;  cout<<"N_WToLNu_CS2 = "<< b2 <<endl; cout<<"N_WToLNu_CS3 = "<< b3 <<endl;
  cout<<"N_top_CS1 = "<< c1 <<endl;  cout<<"N_top_CS2 = "<< c2 <<endl; cout<<"N_top_CS3 = "<< c3 <<endl;
  cout<<"N_other_CS1 = "<<N_data_CS1+d1<<endl;  cout<<"N_other_CS2 = "<<N_data_CS2+d2<<endl; cout<<"N_other_CS3 = "<<N_data_CS3+d3<<endl;
  cout<<"N_data_CS1 = "<<N_data_CS1<<endl;  cout<<"N_data_CS2 = "<<N_data_CS2<<endl; cout<<"N_data_CS3 = "<<N_data_CS3<<endl;
  

  double a1_err = N_ZToNuNu_CS1_err;  double b1_err = N_WToLNu_CS1_err;  double c1_err = N_TT_CS1_err + N_ST_CS1_err + N_ttV_CS1_err;  double d1_err = N_QCD_CS1_err + N_VV_CS1_err;
  double a2_err = N_ZToNuNu_CS2_err;  double b2_err = N_WToLNu_CS2_err;  double c2_err = N_TT_CS2_err + N_ST_CS2_err + N_ttV_CS2_err;  double d2_err = N_QCD_CS2_err + N_VV_CS2_err;
  double a3_err = N_ZToNuNu_CS3_err;  double b3_err = N_WToLNu_CS3_err;  double c3_err = N_TT_CS3_err + N_ST_CS3_err + N_ttV_CS3_err;  double d3_err = N_QCD_CS3_err + N_VV_CS3_err;

  SF_den  = a3*b2*c1 - a2*b3*c1 - a3*b1*c2 + a1*b3*c2 + a2*b1*c3 - a1*b2*c3;
  double SF1_num = b3*c2*d1 - b2*c3*d1 - b3*c1*d2 + b1*c3*d2 + b2*c1*d3 - b1*c2*d3;
  double SF2_num =-a3*c2*d1 + a2*c3*d1 + a3*c1*d2 - a1*c3*d2 - a2*c1*d3 + a1*c2*d3;
  double SF3_num = a3*b2*d1 - a2*b3*d1 - a3*b1*d2 + a1*b3*d2 + a2*b1*d3 - a1*b2*d3;

  if (SF_den==0) return;

  SF1 = -SF1_num/SF_den;
  SF2 = -SF2_num/SF_den;
  SF3 = -SF3_num/SF_den;

  //cout<<"SF1 ="<< SF1 <<endl;
  //cout<<"SF2 ="<< SF2 <<endl;
  //cout<<"SF3 ="<< SF3 <<endl;

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

	//cout<<"SF1_num_err = "<<SF1_num_err<<endl;
	//cout<<"SF2_num_err = "<<SF2_num_err<<endl;
	//cout<<"SF3_num_err = "<<SF3_num_err<<endl;
	//cout<<"SF_den_err = "<<SF_den_err<<endl;

  SF1_err = (SF1_num_err*SF_den*SF_den + SF_den_err*SF1_num*SF1_num)/(SF_den*SF_den*SF_den*SF_den);

  SF2_err = (SF2_num_err*SF_den*SF_den + SF_den_err*SF2_num*SF2_num)/(SF_den*SF_den*SF_den*SF_den);

  SF3_err = (SF3_num_err*SF_den*SF_den + SF_den_err*SF3_num*SF3_num)/(SF_den*SF_den*SF_den*SF_den);

  //cout<<"SF1 err = "<< sqrt(SF1_err) <<endl;
  //cout<<"SF2 err = "<< sqrt(SF2_err) <<endl;
  //cout<<"SF3 err = "<< sqrt(SF3_err) <<endl;
  //cout<<endl;

  delete data_CS1;
  delete ZToNuNu_1_CS1; delete ZToNuNu_2_CS1; delete ZToNuNu_3_CS1; delete ZToNuNu_4_CS1;  delete ZToNuNu_5_CS1;  delete ZToNuNu_6_CS1;  delete ZToNuNu_7_CS1;
  delete QCD_1_CS1; delete QCD_2_CS1; delete QCD_3_CS1; delete QCD_4_CS1; delete QCD_5_CS1; delete QCD_6_CS1; delete QCD_7_CS1; 
  delete WToLNu_1_CS1; delete WToLNu_2_CS1; delete WToLNu_3_CS1; delete WToLNu_4_CS1; delete WToLNu_5_CS1; delete WToLNu_6_CS1; delete WToLNu_7_CS1; 
  delete TT_1_CS1; delete TT_2_CS1; 
  delete ST_1_CS1; delete ST_2_CS1;  delete ST_3_CS1; delete ST_4_CS1;  
  delete WW1_CS1; delete WW2_CS1; delete WZ1_CS1; delete WZ2_CS1; delete WZ3_CS1;  delete ZZ1_CS1; delete ZZ2_CS1;  delete ZZ3_CS1; 
  delete ttW_CS1; delete ttZ_CS1; delete tZq_CS1; delete WZ4_CS1; delete ZZ4_CS1;

  delete data_CS2;
  delete ZToNuNu_1_CS2; delete ZToNuNu_2_CS2; delete ZToNuNu_3_CS2; delete ZToNuNu_4_CS2;  delete ZToNuNu_5_CS2;  delete ZToNuNu_6_CS2;  delete ZToNuNu_7_CS2;
  delete QCD_1_CS2; delete QCD_2_CS2; delete QCD_3_CS2; delete QCD_4_CS2; delete QCD_5_CS2; delete QCD_6_CS2; delete QCD_7_CS2;
  delete WToLNu_1_CS2; delete WToLNu_2_CS2; delete WToLNu_3_CS2; delete WToLNu_4_CS2; delete WToLNu_5_CS2; delete WToLNu_6_CS2; delete WToLNu_7_CS2; 
  delete TT_1_CS2; delete TT_2_CS2; 
  delete ST_1_CS2; delete ST_2_CS2;  delete ST_3_CS2; delete ST_4_CS2;  
  delete WW1_CS2; delete WW2_CS2; delete WZ1_CS2; delete WZ2_CS2; delete WZ3_CS2; delete ZZ1_CS2; delete ZZ2_CS2;  delete ZZ3_CS2; 
  delete ttW_CS2; delete ttZ_CS2; delete tZq_CS2; delete WZ4_CS2; delete ZZ4_CS2;

  delete data_CS3;
  delete ZToNuNu_1_CS3; delete ZToNuNu_2_CS3; delete ZToNuNu_3_CS3; delete ZToNuNu_4_CS3;  delete ZToNuNu_5_CS3;  delete ZToNuNu_6_CS3;  delete ZToNuNu_7_CS3;
  delete QCD_1_CS3; delete QCD_2_CS3; delete QCD_3_CS3; delete QCD_4_CS3; delete QCD_5_CS3; delete QCD_6_CS3; delete QCD_7_CS3;
  delete WToLNu_1_CS3; delete WToLNu_2_CS3; delete WToLNu_3_CS3; delete WToLNu_4_CS3; delete WToLNu_5_CS3; delete WToLNu_6_CS3; delete WToLNu_7_CS3; 
  delete TT_1_CS3; delete TT_2_CS3; 
  delete ST_1_CS3; delete ST_2_CS3;  delete ST_3_CS3; delete ST_4_CS3;  
  delete WW1_CS3; delete WW2_CS3; delete WZ1_CS3; delete WZ2_CS3; delete WZ3_CS3; delete ZZ1_CS3; delete ZZ2_CS3;  delete ZZ3_CS3; 
  delete ttW_CS3; delete ttZ_CS3; delete tZq_CS3; delete WZ4_CS3; delete ZZ4_CS3;
}

void CloneHistos(TH1F* &data_func,TH1F* &background_func,
		TH1F* &ZToNuNu_func,TH1F* &QCD_func,TH1F* &WToLNu_func,TH1F* &TT_func,TH1F* &ST_func,TH1F* &VV_func,TH1F* &ttV_func,
		TH1F* &tptzm0700lh_func,TH1F* &tptzm0900lh_func,TH1F* &tptzm1400lh_func,TH1F* &tptzm1700lh_func){
 background_PRE  = (TH1F*)background_func ->Clone();
 tptzm0700lh_PRE = (TH1F*)tptzm0700lh_func->Clone(); 
 tptzm0900lh_PRE = (TH1F*)tptzm0900lh_func->Clone(); 
 tptzm1400lh_PRE = (TH1F*)tptzm1400lh_func->Clone(); 
 tptzm1700lh_PRE = (TH1F*)tptzm1700lh_func->Clone(); 
 data_PRE        = (TH1F*)data_func       ->Clone(); 
 ZToNuNu_PRE     = (TH1F*)ZToNuNu_func->Clone();
 QCD_PRE         = (TH1F*)QCD_func->Clone();
 WToLNu_PRE      = (TH1F*)WToLNu_func->Clone();
 TT_PRE          = (TH1F*)TT_func->Clone();
 ST_PRE          = (TH1F*)ST_func->Clone();
 VV_PRE          = (TH1F*)VV_func->Clone();
 ttV_PRE          = (TH1F*)ttV_func->Clone();
}
