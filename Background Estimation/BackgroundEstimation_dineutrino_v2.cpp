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

  vector<TString> name;                vector<int> bin;      vector<float> Min;      vector<float> Max;     vector<TString> axis;
  name.push_back("TransverseMassMetTop");      bin.push_back(15);     Min.push_back(500);     Max.push_back(2000);     axis.push_back("TransverseMassMetTop");

    const char *plot = name[0];
    
    char CUT[1000]; char CUTpup1[1000]; char CUTpup2[1000]; char CUTbta1[1000]; char CUTbta2[1000];  char CUTfor1[1000]; char CUTfor2[1000]; char CUTwje1[1000]; char CUTwje2[1000];
	char CUTSR[1000]; char CUTzje1[1000];  char CUTzje2[1000];  char CUTttb1[1000];  char CUTttb2[1000];
	sprintf(CUT,    "((category0==1)&&(Jet1ResolvedPt>0)&&(Jet2ResolvedPt>0)&&(Jet3ResolvedPt>0)&&(MinDeltaPhiJetMet>0.6)&&(TransverseMassMetTop>500)&&(NumSelLeps==0)&&(NumSelBJetsM>0)&&(TopPt>340))");
	//sprintf(CUT,    "((category0==1)&&(Jet1ResolvedPt>0)&&(Jet2ResolvedPt>0)&&(Jet3ResolvedPt>0)&&(MinDeltaPhiJetMet>0.6)&&(TransverseMassMetTop>500)&&(NumSelLeps==0)&&(TopPt>200))");
	sprintf(CUTSR,   "PUWeight   *w_for  *w_Btag   *genWeight  *w_ZToNuNu  *w_WToLNu  *w_ttbar*%s",CUT );
	sprintf(CUTpup1, "PUWeightUP   *w_for  *w_Btag    *genWeight  *w_ZToNuNu  *w_WToLNu  *w_ttbar*%s",CUT );
	sprintf(CUTpup2, "PUWeightDOWN *w_for  *w_Btag    *genWeight  *w_ZToNuNu  *w_WToLNu  *w_ttbar*%s",CUT );
	sprintf(CUTbta1, "PUWeight   *w_for  *w_BtagUp    *genWeight  *w_ZToNuNu  *w_WToLNu  *w_ttbar*%s",CUT );
	sprintf(CUTbta2, "PUWeight   *w_for  *w_BtagDown  *genWeight  *w_ZToNuNu  *w_WToLNu  *w_ttbar*%s",CUT );
	sprintf(CUTzje1, "PUWeight   *w_for  *w_Btag   *genWeight  *w_ZToNuNuUp   *w_WToLNu  *w_ttbar*%s",CUT );
	sprintf(CUTzje2, "PUWeight   *w_for  *w_Btag   *genWeight  *w_ZToNuNuDown *w_WToLNu  *w_ttbar*%s",CUT );
    sprintf(CUTwje1, "PUWeight   *w_for  *w_Btag   *genWeight  *w_ZToNuNu  *w_WToLNuUp   *w_ttbar*%s",CUT );
	sprintf(CUTwje2, "PUWeight   *w_for  *w_Btag   *genWeight  *w_ZToNuNu  *w_WToLNuDown *w_ttbar*%s",CUT );
	sprintf(CUTttb1, "PUWeight   *w_for  *w_Btag   *genWeight  *w_ZToNuNu  *w_WToLNu  *w_ttbarUp*%s",CUT  );
	sprintf(CUTttb2, "PUWeight   *w_for  *w_Btag   *genWeight  *w_ZToNuNu  *w_WToLNu  *w_ttbarDown*%s",CUT);

	
	MakeHistos(CUTSR, plot,bin[0],Min[0],Max[0],0,
		       data,background, 
			   ZToNuNu,QCD,WToLNu,TT,ST,VV,
			   tptzm0700lh,tptzm0800lh,tptzm0900lh,tptzm1000lh,tptzm1100lh,tptzm1200lh,tptzm1300lh,tptzm1400lh,tptzm1500lh,tptzm1600lh,tptzm1700lh,tptzm1800lh);

	MakeHistos(CUTpup1, plot,bin[0],Min[0],Max[0],0,
		       data_pup1,background_pup1, 
			   ZToNuNu_pup1,QCD,WToLNu_pup1,TT_pup1,ST_pup1,VV_pup1,
			   tptzm0700lh_pup1,tptzm0800lh_pup1,tptzm0900lh_pup1,tptzm1000lh_pup1,tptzm1100lh_pup1,tptzm1200lh_pup1,tptzm1300lh_pup1,tptzm1400lh_pup1,tptzm1500lh_pup1,tptzm1600lh_pup1,tptzm1700lh_pup1,tptzm1800lh_pup1);

	MakeHistos(CUTpup2, plot,bin[0],Min[0],Max[0],0,
		       data_pup2,background_pup2, 
			   ZToNuNu_pup2,QCD_pup2,WToLNu_pup2,TT_pup2,ST_pup2,VV_pup2,
			   tptzm0700lh_pup2,tptzm0800lh_pup2,tptzm0900lh_pup2,tptzm1000lh_pup2,tptzm1100lh_pup2,tptzm1200lh_pup2,tptzm1300lh_pup2,tptzm1400lh_pup2,tptzm1500lh_pup2,tptzm1600lh_pup2,tptzm1700lh_pup2,tptzm1800lh_pup2);

	MakeHistos(CUTbta1, plot,bin[0],Min[0],Max[0],0,
		       data_bta1,background_bta1, 
			   ZToNuNu_bta1,QCD_bta1,WToLNu_bta1,TT_bta1,ST_bta1,VV_bta1,
			   tptzm0700lh_bta1,tptzm0800lh_bta1,tptzm0900lh_bta1,tptzm1000lh_bta1,tptzm1100lh_bta1,tptzm1200lh_bta1,tptzm1300lh_bta1,tptzm1400lh_bta1,tptzm1500lh_bta1,tptzm1600lh_bta1,tptzm1700lh_bta1,tptzm1800lh_bta1);

	MakeHistos(CUTbta2, plot,bin[0],Min[0],Max[0],0,
		       data_bta2,background_bta2, 
			   ZToNuNu_bta2,QCD_bta2,WToLNu_bta2,TT_bta2,ST_bta2,VV_bta2,
			   tptzm0700lh_bta2,tptzm0800lh_bta2,tptzm0900lh_bta2,tptzm1000lh_bta2,tptzm1100lh_bta2,tptzm1200lh_bta2,tptzm1300lh_bta2,tptzm1400lh_bta2,tptzm1500lh_bta2,tptzm1600lh_bta2,tptzm1700lh_bta2,tptzm1800lh_bta2);

	MakeHistos(CUTzje1, plot,bin[0],Min[0],Max[0],0,
		       data_zje1,background_zje1, 
			   ZToNuNu_zje1,QCD_zje1,WToLNu_zje1,TT_zje1,ST_zje1,VV_zje1,
			   tptzm0700lh_zje1,tptzm0800lh_zje1,tptzm0900lh_zje1,tptzm1000lh_zje1,tptzm1100lh_zje1,tptzm1200lh_zje1,tptzm1300lh_zje1,tptzm1400lh_zje1,tptzm1500lh_zje1,tptzm1600lh_zje1,tptzm1700lh_zje1,tptzm1800lh_zje1);

	MakeHistos(CUTzje2, plot,bin[0],Min[0],Max[0],0,
		       data_zje2,background_zje2, 
			   ZToNuNu_zje2,QCD_zje2,WToLNu_zje2,TT_zje2,ST_zje2,VV_zje2,
			   tptzm0700lh_zje2,tptzm0800lh_zje2,tptzm0900lh_zje2,tptzm1000lh_zje2,tptzm1100lh_zje2,tptzm1200lh_zje2,tptzm1300lh_zje2,tptzm1400lh_zje2,tptzm1500lh_zje2,tptzm1600lh_zje2,tptzm1700lh_zje2,tptzm1800lh_zje2);

	MakeHistos(CUTwje1, plot,bin[0],Min[0],Max[0],0,
		       data_wje1,background_wje1, 
			   ZToNuNu_wje1,QCD_wje1,WToLNu_wje1,TT_wje1,ST_wje1,VV_wje1,
			   tptzm0700lh_wje1,tptzm0800lh_wje1,tptzm0900lh_wje1,tptzm1000lh_wje1,tptzm1100lh_wje1,tptzm1200lh_wje1,tptzm1300lh_wje1,tptzm1400lh_wje1,tptzm1500lh_wje1,tptzm1600lh_wje1,tptzm1700lh_wje1,tptzm1800lh_wje1);

	MakeHistos(CUTwje2, plot,bin[0],Min[0],Max[0],0,
		       data_wje2,background_wje2, 
			   ZToNuNu_wje2,QCD_wje2,WToLNu_wje2,TT_wje2,ST_wje2,VV_wje2,
			   tptzm0700lh_wje2,tptzm0800lh_wje2,tptzm0900lh_wje2,tptzm1000lh_wje2,tptzm1100lh_wje2,tptzm1200lh_wje2,tptzm1300lh_wje2,tptzm1400lh_wje2,tptzm1500lh_wje2,tptzm1600lh_wje2,tptzm1700lh_wje2,tptzm1800lh_wje2);

	MakeHistos(CUTttb1, plot,bin[0],Min[0],Max[0],0,
		       data_ttb1,background_ttb1, 
			   ZToNuNu_ttb1,QCD_ttb1,WToLNu_ttb1,TT_ttb1,ST_ttb1,VV_ttb1,
			   tptzm0700lh_ttb1,tptzm0800lh_ttb1,tptzm0900lh_ttb1,tptzm1000lh_ttb1,tptzm1100lh_ttb1,tptzm1200lh_ttb1,tptzm1300lh_ttb1,tptzm1400lh_ttb1,tptzm1500lh_ttb1,tptzm1600lh_ttb1,tptzm1700lh_ttb1,tptzm1800lh_ttb1);

	MakeHistos(CUTttb2, plot,bin[0],Min[0],Max[0],0,
		       data_ttb2,background_ttb2, 
			   ZToNuNu_ttb2,QCD_ttb2,WToLNu_ttb2,TT_ttb2,ST_ttb2,VV_ttb2,
			   tptzm0700lh_ttb2,tptzm0800lh_ttb2,tptzm0900lh_ttb2,tptzm1000lh_ttb2,tptzm1100lh_ttb2,tptzm1200lh_ttb2,tptzm1300lh_ttb2,tptzm1400lh_ttb2,tptzm1500lh_ttb2,tptzm1600lh_ttb2,tptzm1700lh_ttb2,tptzm1800lh_ttb2);
	
	SaveRootFileForLimit_dineutrino_v2(save);
	
	tptzm0700lh->SetLineWidth(2); tptzm0900lh->SetLineWidth(2); tptzm1400lh->SetLineWidth(2); tptzm1700lh->SetLineWidth(2); 
	tptzm1700lh->SetLineStyle(2); tptzm0700lh->SetLineColor(2); tptzm0900lh->SetLineColor(2); tptzm1400lh->SetLineColor(2); tptzm1700lh->SetLineColor(2); 
	ZToNuNu->SetLineWidth(2);  QCD->SetLineWidth(2); WToLNu->SetLineWidth(2); TT->SetLineWidth(2); ST->SetLineWidth(2); VV->SetLineWidth(2); 
	ZToNuNu->SetLineColor(kOrange); QCD->SetLineColor(kGreen-3); WToLNu->SetLineColor(kCyan-4); TT->SetLineColor(kGreen+3); ST->SetLineColor(kGreen+3); VV->SetLineColor(kCyan+2);
	ZToNuNu->SetFillColor(kOrange); QCD->SetFillColor(kGreen-3); WToLNu->SetFillColor(kCyan-4); TT->SetFillColor(kGreen+3); ST->SetFillColor(kGreen+3); VV->SetFillColor(kCyan+2); 
	data->SetLineWidth(2); data->SetLineColor(1); data->SetMarkerColor(1); data->SetMarkerStyle(20); data->SetMarkerSize(1.3);



    Double_t dataErr     = 0; Float_t dataYield     = data   ->IntegralAndError(1,tptzm0700lh->GetNbinsX()-1,dataErr,"");
	Double_t ZToNuNu_Err = 0; Float_t ZToNuNu_Yield = ZToNuNu->IntegralAndError(1,tptzm0700lh->GetNbinsX(),ZToNuNu_Err,"");
	Double_t QCD_Err     = 0; Float_t QCD_Yield     = QCD    ->IntegralAndError(1,tptzm0700lh->GetNbinsX(),QCD_Err,"");
	Double_t WToLNu_Err  = 0; Float_t WToLNu_Yield  = WToLNu ->IntegralAndError(1,tptzm0700lh->GetNbinsX(),WToLNu_Err,"");
	Double_t TT_Err = 0; Float_t TT_Yield = TT->IntegralAndError(1,tptzm0700lh->GetNbinsX(),TT_Err,"");
	Double_t ST_Err = 0; Float_t ST_Yield = ST->IntegralAndError(1,tptzm0700lh->GetNbinsX(),ST_Err,"");
	Double_t VV_Err = 0; Float_t VV_Yield = VV->IntegralAndError(1,tptzm0700lh->GetNbinsX(),VV_Err, "");
	Double_t tptzm0700_Err= 0; Float_t tptzm0700_Yield = tptzm0700lh->IntegralAndError(1,tptzm0700lh->GetNbinsX(),tptzm0700_Err,"");
	Double_t tptzm0900_Err= 0; Float_t tptzm0900_Yield = tptzm0900lh->IntegralAndError(1,tptzm0700lh->GetNbinsX(),tptzm0900_Err,"");
    Double_t tptzm1400_Err= 0; Float_t tptzm1400_Yield = tptzm1400lh->IntegralAndError(1,tptzm0700lh->GetNbinsX(),tptzm1400_Err,"");
	Double_t tptzm1700_Err= 0; Float_t tptzm1700_Yield = tptzm1700lh->IntegralAndError(1,tptzm0700lh->GetNbinsX(),tptzm1700_Err,"");
	
  
      cout<<endl;
      //cout<<"Plotting "<<name[i]<<endl;
      cout<<"DATA      = "<<data->Integral()<<" +/- "<<dataErr<<endl; 
	  cout<<"ZToNuNu   = "<<ZToNuNu->Integral()<<" +/- "<<sqrt(ZToNuNu_Err*ZToNuNu_Err)<<endl;
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
	  cout<<"Tprime LH 1700 = "<<tptzm1700lh->Integral()<<" +/- "<<sqrt(tptzm1700_Err*tptzm1700_Err)<<endl;
	
   cout<<"this step is ok 2"<<endl;
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
    Double_t x[bin[0]]; Double_t exl[bin[0]]; Double_t exh[bin[0]];
    Double_t y[bin[0]]; Double_t eyl[bin[0]]; Double_t eyh[bin[0]]; 
    for(int m=0; m<background->GetNbinsX(); m++){ 
      x[m]=Min[0]+m*(Max[0]-Min[0])/bin[0]+(Max[0]-Min[0])/(2*bin[0]);
      exl[m]=(Max[0]-Min[0])/(2*bin[0]);
      exh[m]=(Max[0]-Min[0])/(2*bin[0]);
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

    TGraphAsymmErrors *RATIO = new TGraphAsymmErrors(bin[0],x,y,exl,exh,eyl,eyh);
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
    RATIO->GetXaxis()->SetTitle(axis[0]);
    RATIO->GetXaxis()->SetLabelSize(0.13);
    RATIO->GetYaxis()->SetLabelSize(0.13);
    RATIO->GetXaxis()->SetTitleSize(0.15);
    RATIO->GetYaxis()->SetTitleSize(0.09);
    RATIO->GetYaxis()->SetNdivisions(505);
    RATIO->GetXaxis()->SetRangeUser(Min[0],Max[0]);
    RATIO2->SetFillStyle(3002);
    RATIO2->SetFillColor(12);
    RATIO2->SetLineColor(12);
    RATIO2->SetMarkerSize(0);
    RATIO2->Draw("E2same");
    RATIO->Draw("E0psame");

    TLine* line = new TLine(Min[0],1,Max[0],1);
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
    
    TString NAME = name[0];
    cout<<"Finished "<<NAME<<endl;
    //c1->SaveAs("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/"+NAME+".png");
	c1->SaveAs(NAME+".png");
    c1->Draw(); 

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
