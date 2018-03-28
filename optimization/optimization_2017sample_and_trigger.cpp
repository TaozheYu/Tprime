void optimization_2017sample_and_trigger(){
  gROOT->Reset();
  gStyle->SetCanvasColor(0);
  gStyle->SetFrameBorderMode(0);
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1,0);
  gStyle->SetTitleX(0.5); //title X location 
  gStyle->SetTitleY(0.96); //title Y location 
  gStyle->SetPaintTextFormat(".2f");
  gErrorIgnoreLevel = kWarning;

  TCanvas* c1 = new TCanvas("c1","c1",0,0,800,600);
  using namespace std;

  //CUT VALUES
  double dRMuo=99;            //0.625
  double dREle=99;           //0.625
  double TopMass1=0.;
  double TopMass2=9999.;
  double TopPt=0.;
  double ZPt=0.; 
  int    BTag=1;              //1
  int    Forwardjets=1;       //1
  double MuoPt=-9999.;        //120
  double ElePt=120;        //120

  vector<string> PLOT;                   vector<int> BIN;     vector<float> MIN;   vector<float> MAX;   vector<bool> UP;       vector<TString> AXIS;

  //PLOT.push_back("deltaRMuo1Muo2");      BIN.push_back(20);   MIN.push_back(0);    MAX.push_back(2.5);  UP.push_back(true);    AXIS.push_back("#Delta (muo1,muo2)");
  PLOT.push_back("deltaREle1Ele2");      BIN.push_back(20);   MIN.push_back(0);    MAX.push_back(2.5);  UP.push_back(true);    AXIS.push_back("#Delta (ele1,ele2)");
  //PLOT.push_back("TopMassResolved");     BIN.push_back(20);   MIN.push_back(0);    MAX.push_back(800);  UP.push_back(false);   AXIS.push_back("top Mass[GeV]");
  //PLOT.push_back("TopPtResolved");       BIN.push_back(20);   MIN.push_back(0);    MAX.push_back(800);  UP.push_back(false);   AXIS.push_back("top pt[GeV]");
  //PLOT.push_back("ZPt");                 BIN.push_back(20);   MIN.push_back(0);    MAX.push_back(800);  UP.push_back(false);   AXIS.push_back("Z pt[GeV]");
  //PLOT.push_back("NumSelBJetsM");        BIN.push_back(6);    MIN.push_back(-0.5); MAX.push_back(5.5);  UP.push_back(false);   AXIS.push_back("Number of medium B jets"); 
  //PLOT.push_back("NumSelForwardJets");   BIN.push_back(6);    MIN.push_back(0);    MAX.push_back(6);    UP.push_back(false);   AXIS.push_back("Number of forward jets");
  //PLOT.push_back("Muon1Pt");             BIN.push_back(20);   MIN.push_back(0);    MAX.push_back(500);  UP.push_back(false);   AXIS.push_back("lead muon pt[GeV]");
  //PLOT.push_back("Electron1Pt");         BIN.push_back(20);   MIN.push_back(0);    MAX.push_back(500);  UP.push_back(false);   AXIS.push_back("lead electron pt[GeV]");
  
  //TFile *file01 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/data.root");//for muon  //DoubleEle33 and Mu50
  TFile *file02 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/Tprime_0700.root");
  TFile *file03 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/Tprime_0800.root");
  TFile *file04 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/Tprime_0900.root");
  TFile *file05 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/Tprime_1000.root");
  TFile *file06 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/Tprime_1100.root");
  TFile *file07 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/Tprime_1200.root");
  TFile *file08 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/Tprime_1300.root");
  TFile *file09 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/Tprime_1400.root");
  TFile *file10 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/Tprime_1500.root");
  TFile *file11 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/Tprime_1600.root");
  TFile *file12 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/Tprime_1700.root");
  TFile *file13 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/DYJetsToLL_HT100to200.root ");
  TFile *file14 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/DYJetsToLL_HT200to400.root ");
  TFile *file15 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/DYJetsToLL_HT400to600.root ");
  TFile *file16 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/DYJetsToLL_HT600to800.root ");
  TFile *file17 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/DYJetsToLL_HT800to1200.root ");
  TFile *file18 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/DYJetsToLL_HT1200to2500.root ");
  TFile *file19 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/DYJetsToLL_HT2500toInf.root ");
  TFile *file20 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/ST_tW_antitop.root ");
  TFile *file21 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/ST_tW_top.root ");
  TFile *file22 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/TTTo2L2Nu.root  ");
  TFile *file23 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/TTToSemiLeptonic.root");
  TFile *file24 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/ttZ.root");
  TFile *file25 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/ttW.root");
  TFile *file26 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/tZq.root");
  TFile *file27 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/ZZTo4L.root");
  TFile *file28 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/ZZTo2L2Q.root");
  TFile *file29 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/ZZTo2L2Nu.root");
  TFile *file30 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/WWTo2L2Nu.root");
  TFile *file31 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/WWToLNuQQ.root");
  TFile *file32 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/WZTo1L1Nu2Q.root ");
  TFile *file33 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/WZTo2L2Q.root");
  TFile *file34 = TFile::Open("/eos/user/t/tayu/2017sample_and_trigger/both/WZTo3LNu.root");

  /*TTree *Tree01 = (TTree*)file01->Get("tree");
  TTree *Tree02 = (TTree*)file02->Get("tree");
  TTree *Tree03 = (TTree*)file03->Get("tree");*/
  TTree *Tree04 = (TTree*)file04->Get("tree");
  TTree *Tree05 = (TTree*)file05->Get("tree");
  //TTree *Tree06 = (TTree*)file06->Get("tree");
  //TTree *Tree07 = (TTree*)file07->Get("tree");
  //TTree *Tree08 = (TTree*)file08->Get("tree");
  TTree *Tree09 = (TTree*)file09->Get("tree");
  //TTree *Tree10 = (TTree*)file10->Get("tree");
  //TTree *Tree11 = (TTree*)file11->Get("tree");
  TTree *Tree12 = (TTree*)file12->Get("tree");
  TTree *Tree13 = (TTree*)file13->Get("tree");
  TTree *Tree14 = (TTree*)file14->Get("tree");
  TTree *Tree15 = (TTree*)file15->Get("tree");
  TTree *Tree16 = (TTree*)file16->Get("tree");
  TTree *Tree17 = (TTree*)file17->Get("tree");
  TTree *Tree18 = (TTree*)file18->Get("tree");
  TTree *Tree19 = (TTree*)file19->Get("tree");
  TTree *Tree20 = (TTree*)file20->Get("tree");
  TTree *Tree21 = (TTree*)file21->Get("tree");
  TTree *Tree22 = (TTree*)file22->Get("tree");
  TTree *Tree23 = (TTree*)file23->Get("tree");
  TTree *Tree24 = (TTree*)file24->Get("tree");
  TTree *Tree25 = (TTree*)file25->Get("tree");
  TTree *Tree26 = (TTree*)file26->Get("tree");
  TTree *Tree27 = (TTree*)file27->Get("tree");
  TTree *Tree28 = (TTree*)file28->Get("tree");
  TTree *Tree29 = (TTree*)file29->Get("tree");
  TTree *Tree30 = (TTree*)file30->Get("tree");
  TTree *Tree31 = (TTree*)file31->Get("tree");
  TTree *Tree32 = (TTree*)file32->Get("tree");
  TTree *Tree33 = (TTree*)file33->Get("tree");
  TTree *Tree34 = (TTree*)file34->Get("tree");

  for(int category=0; category<6; category++){
  //for(int category=1; category<2; category++){
  //for(int category=2; category<3; category++){
  //for(int category=3; category<4; category++){
  //for(int category=4; category<5; category++){
  //for(int category=5; category<6; category++){
    for(int p=0; p<PLOT.size(); p++){
      if((category==0 || category==2 || category==4) && (PLOT[p]=="deltaREle1Ele2" || PLOT[p]=="Electron1Pt")) continue;
      if((category==1 || category==3 || category==5) && (PLOT[p]=="deltaRMuo1Muo2" || PLOT[p]=="Muon1Pt")) continue;
      const char *plot = PLOT[p].c_str();
      TString name = PLOT[p];
      int bin=BIN[p]; 
      float min=MIN[p]; 
      float max=MAX[p]; 
      TString axis = AXIS[p];
      TH1F *ROC               = new TH1F("ROC",               "ROC",               bin+1,min-(max-min)/(2*bin),max+(max-min)/(2*bin));
      TH1F *SignalEfficiency1 = new TH1F("SignalEfficiency1", "SignalEfficiency1", bin+1,min-(max-min)/(2*bin),max+(max-min)/(2*bin));
      TH1F *BackgroundYield1  = new TH1F("BackgroundYield1",  "BackgroundYield1",  bin+1,min-(max-min)/(2*bin),max+(max-min)/(2*bin));
      float max1 = 0;
      float Tprime_0900Integral = 0;
      float Tprime_1700Integral = 0;
      float cutValue = 0;
      if(UP[p]) cutValue = max;
      else cutValue = min;
      int KK=-1;
      float bestFoM=-99;
      float bestCut=-99;
      for(int i=0; i<bin+1; i++){
	char CUT [1000]; char CUTdy [1000];    
	if(UP[p]) sprintf(CUT, "w_for*w_TrigMuon*w_TrigElec*w_Muon1*w_Muon2*w_Electron1*w_Electron2*genWeight*(%s<%f  && category%i==1 && deltaRMuo1Muo2<%f && deltaREle1Ele2<%f && TopMass>%f && TopMass<%f && TopPt>%f && ZPt>%f && NumSelBJetsM>=%i && NumSelForwardJets>=%i && Electron1Pt>%f && Muon1Pt>%f&&TprimeMass>500&&TprimeMass<2100&NumSelLeps==2)", plot, cutValue, category, dRMuo, dREle, TopMass1, TopMass2, TopPt, ZPt, BTag, Forwardjets, ElePt, MuoPt);
	else      sprintf(CUT, "w_for*w_TrigMuon*w_TrigElec*w_Muon1*w_Muon2*w_Electron1*w_Electron2*genWeight*(%s>=%f && category%i==1 && deltaRMuo1Muo2<%f && deltaREle1Ele2<%f && TopMass>%f && TopMass<%f && TopPt>%f && ZPt>%f && NumSelBJetsM>=%i && NumSelForwardJets>=%i && Electron1Pt>%f && Muon1Pt>%f&&TprimeMass>500&&TprimeMass<2100&NumSelLeps==2)", plot, cutValue, category, dRMuo, dREle, TopMass1, TopMass2, TopPt, ZPt, BTag, Forwardjets, ElePt, MuoPt);
	char variable[50];
	if(PLOT[p]=="deltaRMuo1Muo2")         sprintf(variable, "deltaRMuo1Muo2");
	if(PLOT[p]=="deltaREle1Ele2")         sprintf(variable, "deltaREle1Ele2");
	if(PLOT[p]=="TopMassResolved")        sprintf(variable, "TopMassResolved");
	if(PLOT[p]=="TopPtResolved")          sprintf(variable, "TopPtResolved");
	if(PLOT[p]=="ZPt")                    sprintf(variable, "ZPt");
	if(PLOT[p]=="NumSelBJetsM")           sprintf(variable, "NumSelBJetsM");	
	if(PLOT[p]=="NumSelForwardJets")      sprintf(variable, "NumSelForwardJets");
	if(PLOT[p]=="Electron1Pt")            sprintf(variable, "Electron1Pt");
	if(PLOT[p]=="Muon1Pt")                sprintf(variable, "Muon1Pt");

    char input01[50]; sprintf(input01, "%s>>h01(1,-9,999999)",variable); 
	char input02[50]; sprintf(input02, "%s>>h02(1,-9,999999)",variable);
	char input03[50]; sprintf(input03, "%s>>h03(1,-9,999999)",variable);
	char input04[50]; sprintf(input04, "%s>>h04(1,-9,999999)",variable);
	char input05[50]; sprintf(input05, "%s>>h05(1,-9,999999)",variable);
	char input06[50]; sprintf(input06, "%s>>h06(1,-9,999999)",variable);
	char input07[50]; sprintf(input07, "%s>>h07(1,-9,999999)",variable);
	char input08[50]; sprintf(input08, "%s>>h08(1,-9,999999)",variable);
	char input09[50]; sprintf(input09, "%s>>h09(1,-9,999999)",variable);
	char input10[50]; sprintf(input10, "%s>>h10(1,-9,999999)",variable);
	char input11[50]; sprintf(input11, "%s>>h11(1,-9,999999)",variable);
	char input12[50]; sprintf(input12, "%s>>h12(1,-9,999999)",variable);
	char input13[50]; sprintf(input13, "%s>>h13(1,-9,999999)",variable);
	char input14[50]; sprintf(input14, "%s>>h14(1,-9,999999)",variable);
	char input15[50]; sprintf(input15, "%s>>h15(1,-9,999999)",variable);
	char input16[50]; sprintf(input16, "%s>>h16(1,-9,999999)",variable);
	char input17[50]; sprintf(input17, "%s>>h17(1,-9,999999)",variable);
	char input18[50]; sprintf(input18, "%s>>h18(1,-9,999999)",variable);
	char input19[50]; sprintf(input19, "%s>>h19(1,-9,999999)",variable);
	char input20[50]; sprintf(input20, "%s>>h20(1,-9,999999)",variable);
	char input21[50]; sprintf(input21, "%s>>h21(1,-9,999999)",variable);
	char input22[50]; sprintf(input22, "%s>>h22(1,-9,999999)",variable);
	char input23[50]; sprintf(input23, "%s>>h23(1,-9,999999)",variable);
	char input24[50]; sprintf(input24, "%s>>h24(1,-9,999999)",variable);
	char input25[50]; sprintf(input25, "%s>>h25(1,-9,999999)",variable);
	char input26[50]; sprintf(input26, "%s>>h26(1,-9,999999)",variable);
	char input27[50]; sprintf(input27, "%s>>h27(1,-9,999999)",variable);
	char input28[50]; sprintf(input28, "%s>>h28(1,-9,999999)",variable);
	char input29[50]; sprintf(input29, "%s>>h29(1,-9,999999)",variable);
	char input30[50]; sprintf(input30, "%s>>h30(1,-9,999999)",variable);
	char input31[50]; sprintf(input31, "%s>>h31(1,-9,999999)",variable);
	char input32[50]; sprintf(input32, "%s>>h32(1,-9,999999)",variable);
	char input33[50]; sprintf(input33, "%s>>h33(1,-9,999999)",variable);
    char input34[50]; sprintf(input34, "%s>>h34(1,-9,999999)",variable);
 
	TH1F *temp = new TH1F("", "", 1,-9,999999);
	TH1F *ZZ2d = new TH1F("", "", 1,-9,999999);
	TH1F *WW2d = new TH1F("", "", 1,-9,999999);
	TH1F *WZ1d = new TH1F("", "", 1,-9,999999);
	Tree04->Draw(input04,CUT);  TH1F* h04=(TH1F*)gDirectory->Get("h04"); TH1F *Tprime_0900 =(TH1F*)h04->Clone();
	Tree05->Draw(input05,CUT);  TH1F* h05=(TH1F*)gDirectory->Get("h05"); TH1F *Tprime_1000 =(TH1F*)h05->Clone();
	Tree09->Draw(input09,CUT);  TH1F* h09=(TH1F*)gDirectory->Get("h09"); TH1F *Tprime_1400 =(TH1F*)h09->Clone();
	Tree12->Draw(input12,CUT);  TH1F* h12=(TH1F*)gDirectory->Get("h12"); TH1F *Tprime_1700 =(TH1F*)h12->Clone();
	Tree13->Draw(input13,CUT);  TH1F* h13=(TH1F*)gDirectory->Get("h13"); TH1F *DY1         =(TH1F*)h13->Clone();
	Tree14->Draw(input14,CUT);  TH1F* h14=(TH1F*)gDirectory->Get("h14"); TH1F *DY2         =(TH1F*)h14->Clone();
	Tree15->Draw(input15,CUT);  TH1F* h15=(TH1F*)gDirectory->Get("h15"); TH1F *DY3         =(TH1F*)h15->Clone();
	Tree16->Draw(input16,CUT);  TH1F* h16=(TH1F*)gDirectory->Get("h16"); TH1F *DY4         =(TH1F*)h16->Clone();
	Tree17->Draw(input17,CUT);  TH1F* h17=(TH1F*)gDirectory->Get("h17"); TH1F *DY5         =(TH1F*)h17->Clone();
	Tree18->Draw(input18,CUT);  TH1F* h18=(TH1F*)gDirectory->Get("h18"); TH1F *DY6         =(TH1F*)h18->Clone();
	Tree19->Draw(input19,CUT);  TH1F* h19=(TH1F*)gDirectory->Get("h19"); TH1F *DY7         =(TH1F*)h19->Clone();
	Tree20->Draw(input20,CUT);  TH1F* h20=(TH1F*)gDirectory->Get("h20"); TH1F *ST1         =(TH1F*)h20->Clone();
	Tree21->Draw(input21,CUT);  TH1F* h21=(TH1F*)gDirectory->Get("h21"); TH1F *ST2         =(TH1F*)h21->Clone();
	Tree22->Draw(input22,CUT);  TH1F* h22=(TH1F*)gDirectory->Get("h22"); TH1F *TTb1        =(TH1F*)h22->Clone();
	Tree23->Draw(input23,CUT);  TH1F* h23=(TH1F*)gDirectory->Get("h23"); TH1F *TTb2        =(TH1F*)h23->Clone();
	Tree24->Draw(input24,CUT);  TH1F* h24=(TH1F*)gDirectory->Get("h24"); TH1F *ttZ         =(TH1F*)h24->Clone();
	Tree25->Draw(input25,CUT);  TH1F* h25=(TH1F*)gDirectory->Get("h25"); TH1F *ttW         =(TH1F*)h25->Clone();
	Tree26->Draw(input26,CUT);  TH1F* h26=(TH1F*)gDirectory->Get("h26"); TH1F *tZq         =(TH1F*)h26->Clone();
	Tree27->Draw(input27,CUT);  TH1F* h27=(TH1F*)gDirectory->Get("h27"); TH1F *ZZ1d        =(TH1F*)h27->Clone();
	//Tree28->Draw(input28,CUT);  TH1F* h28=(TH1F*)gDirectory->Get("h28"); TH1F *ZZ2d        =(TH1F*)h28->Clone();
	if(Tree28->Draw(input28,CUT)){ Tree28->Draw(input28,CUT); TH1F*h28=(TH1F*)gDirectory->Get("h28"); TH1F *ZZ2d =(TH1F*)h28->Clone();delete h28;} else {TH1F *ZZ2d =(TH1F*)temp->Clone();}
	Tree29->Draw(input29,CUT);  TH1F* h29=(TH1F*)gDirectory->Get("h29"); TH1F *ZZ3d        =(TH1F*)h29->Clone();
	Tree30->Draw(input30,CUT);  TH1F* h30=(TH1F*)gDirectory->Get("h30"); TH1F *WW1d        =(TH1F*)h30->Clone();
	if(Tree31->Draw(input31,CUT)){ Tree31->Draw(input31,CUT); TH1F*h31=(TH1F*)gDirectory->Get("h31"); TH1F *WW2d =(TH1F*)h31->Clone();delete h31;} else {TH1F *WW2d =(TH1F*)temp->Clone();}
	if(Tree32->Draw(input32,CUT)){ Tree32->Draw(input32,CUT); TH1F*h32=(TH1F*)gDirectory->Get("h32"); TH1F *WZ1d =(TH1F*)h32->Clone();delete h32;} else {TH1F *WZ1d =(TH1F*)temp->Clone();}         
	Tree33->Draw(input33,CUT);  TH1F* h33=(TH1F*)gDirectory->Get("h33"); TH1F *WZ2d        =(TH1F*)h33->Clone();
	Tree34->Draw(input34,CUT);  TH1F* h34=(TH1F*)gDirectory->Get("h34"); TH1F *WZ3d        =(TH1F*)h34->Clone(); 
	delete h04; delete h05; delete h09; delete h12; delete h13; delete h19; delete h20; delete h21; delete h22;
	delete h23; delete h24; delete h25; delete h26; delete h27; delete h29; delete h30; delete h33; delete h34;
	int SigSF = 1;
	float LUMI  = 40800.0; // for doubleEG
    //float LUMI  = 38800.0; // for SingleMuon
    float w0700 = SigSF*(0.5*0.5*5.820 *0.25*LUMI/388056); //SIG1
    float w0800 = SigSF*(0.5*0.5*5.820 *0.25*LUMI/400000.0); //SIG2
    float w0900 = SigSF*(0.5*0.5*5.820 *0.25*LUMI/400000.0); //SIG3
    float w1000 = SigSF*(0.5*0.5*1.950 *0.25*LUMI/400000.0); //SIG4
    float w1100 = SigSF*(0.5*0.5*1.950 *0.25*LUMI/400000.0); //SIG5
    float w1200 = SigSF*(0.5*0.5*1.950 *0.25*LUMI/400000.0); //SIG6
    float w1300 = SigSF*(0.5*0.5*1.950 *0.25*LUMI/400000.0); //SIG7
    float w1400 = SigSF*(0.5*0.5*0.540 *0.25*LUMI/400000.0); //SIG8
    float w1500 = SigSF*(0.5*0.5*0.540 *0.25*LUMI/400000.0); //SIG9
    float w1600 = SigSF*(0.5*0.5*0.540 *0.25*LUMI/400000.0); //SIG10
    float w1700 = SigSF*(0.5*0.5*0.230 *0.25*LUMI/400000.0); //SIG11
    float w01 = (213.400*LUMI/10031487);  //DY1
    float w02 = (65.4200*LUMI/9917255);     //DY2
    float w03 = (7.31000*LUMI/(4771799+4259062));  //DY3
    float w04 = (1.49000*LUMI/6961344);     //DY4
    float w05 = (0.66100*LUMI/3065315);     //DY5
    float w06 = (0.11900*LUMI/596079);      //DY6
    float w07 = (0.00280*LUMI/388323);      //DY7
    float w08 = (38.06*LUMI/5365983);       //ST1 antitop
    float w09 = (38.06*LUMI/4656358);       //ST2 top
    float w10 = (88.290*LUMI/68629812);     //TTbar1 2L2Nu
    float w11 = (365.34*LUMI/110512616);    //TTbar2 semileptonic
    float w12 = (0.2432*LUMI/(7295845*(0.74-0.26)));   //ttZ
    float w13 = (0.2001*LUMI/(4889942*(0.77-0.23)));   //ttW
    float w14 = (0.0758*LUMI/(13220024*(0.63-0.37)));  //tZq
    float w15 = (1.204*LUMI/(10419284*(0.85-0.15)));   //ZZTo4L
    float w16 = (3.222*LUMI/(15345572*(0.82-0.18)));   //ZZTo2L2Q
    float w17 = (0.5644*LUMI/8842475);     //ZZTo2L2Nu
    float w18 = (10.48*LUMI/1818828);      //WWTo2L2Nu
    float w19 = (43.53*LUMI/8516920);      //WWToLNuQQ
    float w20 = (10.73*LUMI/(23954757*(0.79-0.21)));   //WZTo1L1Nu2Q
    float w21 = (5.606*LUMI/(26517272*(0.8-0.2)));     //WZTo2L2Q
    float w22 = (4.43*LUMI/(10751052*(0.81-0.19)));    //WZTo3LNu

	Tprime_0900->Scale(w0900);
	Tprime_1000->Scale(w1000);
	Tprime_1400->Scale(w1400);
	Tprime_1700->Scale(w1700); 

	//(category==2 || category==3) Tprime_0900 =(TH1F*)Tprime_1000->Clone();
	//(category==4 || category==5) Tprime_0900 =(TH1F*)Tprime_1400->Clone();
	DY1 ->Scale(w01);
	DY2 ->Scale(w02);
	DY3 ->Scale(w03);
	DY4 ->Scale(w04);
	DY5 ->Scale(w05);
	DY6 ->Scale(w06);
	DY7 ->Scale(w07);
	ST1 ->Scale(w08);
	ST2 ->Scale(w09);
	TTb1->Scale(w10);
	TTb2->Scale(w11);
	ttZ ->Scale(w12);
	ttW ->Scale(w13);
	tZq ->Scale(w14);
	ZZ1d->Scale(w15);
	ZZ2d->Scale(w16);
	ZZ3d->Scale(w17);
	WW1d->Scale(w18);
	WW2d->Scale(w19);
	WZ1d->Scale(w20);
	WZ2d->Scale(w21);
	WZ3d->Scale(w22);
	
	
        
	DY1->Add(DY2);
	DY1->Add(DY3);
	DY1->Add(DY4);
	DY1->Add(DY5);
	DY1->Add(DY6);
	DY1->Add(DY7);
	DY1->Add(ST1);
	DY1->Add(ST2);
	DY1->Add(TTb1);
	DY1->Add(TTb2);
	DY1->Add(ttZ);
	DY1->Add(ttW);
	DY1->Add(tZq);
	DY1->Add(ZZ1d);
	DY1->Add(ZZ2d);
	DY1->Add(ZZ3d);
	DY1->Add(WW1d);
	DY1->Add(WW2d);
	DY1->Add(WZ1d);
	DY1->Add(WZ2d);
	DY1->Add(WZ3d);
	
	
    
	if(UP[p]){
	  if(bestFoM<(Tprime_0900->Integral()/(sqrt(Tprime_0900->Integral()+DY1->Integral())))) {
	    if((Tprime_0900->Integral()+DY1->Integral())>0){
	      bestFoM = (Tprime_0900->Integral()/(sqrt(Tprime_0900->Integral()+DY1->Integral()))); 
	      bestCut = ROC->GetBinCenter(ROC->GetXaxis()->GetNbins()-KK-1);
	    }
	  }
	  if((Tprime_0900->Integral()+DY1->Integral())>0){
	    ROC              ->SetBinContent(ROC->GetXaxis()->GetNbins()-KK-1, (Tprime_0900->Integral()/(sqrt(Tprime_0900->Integral()+DY1->Integral()))));
	    SignalEfficiency1->SetBinContent(ROC->GetXaxis()->GetNbins()-KK-1, Tprime_0900->Integral());
		//cout<<Tprime_0900->Integral()<<endl;
	    BackgroundYield1 ->SetBinContent(ROC->GetXaxis()->GetNbins()-KK-1, DY1->Integral());
	  }
	  ROC              ->SetBinError(ROC->GetXaxis()->GetNbins()-KK-1, 0.00001);
	  SignalEfficiency1->SetBinError(ROC->GetXaxis()->GetNbins()-KK-1, 0.00001);
	  BackgroundYield1 ->SetBinError(ROC->GetXaxis()->GetNbins()-KK-1, 0.00001);
	  KK=KK+1;
	} else {
	  if(bestFoM<(Tprime_0900->Integral()/(sqrt(Tprime_0900->Integral()+DY1->Integral())))) {
	    if((Tprime_0900->Integral()+DY1->Integral())>0){
	      bestFoM = (Tprime_0900->Integral()/(sqrt(Tprime_0900->Integral()+DY1->Integral()))); 
	      bestCut = ROC->GetBinCenter(i+1);
	    }
	  }
	  if((Tprime_0900->Integral()+DY1->Integral())>0){
	    ROC              ->SetBinContent(i+1, (Tprime_0900->Integral()/(sqrt(Tprime_0900->Integral()+DY1->Integral()))));
	    SignalEfficiency1->SetBinContent(i+1, Tprime_0900->Integral());
		//cout<<Tprime_0900->Integral()<<endl;
	    BackgroundYield1 ->SetBinContent(i+1, DY1->Integral());
	  }
	  ROC              ->SetBinError(i+1, 0.00001);
	  SignalEfficiency1->SetBinError(i+1, 0.00001);
	  BackgroundYield1 ->SetBinError(i+1, 0.00001);
	}
	if(UP[p]) cutValue = cutValue - (max-min)/bin;
	else cutValue = cutValue + (max-min)/bin;
	delete Tprime_0900; delete Tprime_1000; delete Tprime_1400; delete Tprime_1700; 
	delete DY1; delete DY2; delete DY3;  delete DY4;  delete DY5; delete DY6; delete DY7; 
	delete ST1; delete ST2; delete TTb1; delete TTb2; delete ttZ; delete ttW; delete tZq; 
	delete ZZ1d;delete ZZ2d;delete ZZ3d; delete WW1d; delete WW2d;delete WZ1d;delete WZ2d; delete WZ3d;
      }
  
      if(UP[p])  cout<<"Best cut for category "<<category<<" and variable '"<<axis<<"' is <"<<bestCut<<" (figure of merit is "<<bestFoM<<")"<<endl;
      if(!UP[p]) cout<<"Best cut for category "<<category<<" and variable '"<<axis<<"' is >"<<bestCut<<" (figure of merit is "<<bestFoM<<")"<<endl;

      TCanvas* c2 = new TCanvas("c2","c2",0,0,800,600);
      ROC->Draw("E");
      ROC->SetMinimum(0.0);
      //ROC->SetMaximum(0.05);
      ROC->SetMarkerStyle(21);
      ROC->SetLineColor(1);
      ROC->GetYaxis()->SetTitleSize(0.040);
      ROC->GetXaxis()->SetTitleSize(0.045);
      ROC->GetYaxis()->SetLabelSize(0.035);
      ROC->GetXaxis()->SetLabelSize(0.045);
      ROC->SetTitle("");
      ROC->GetXaxis()->SetTitle(axis);
      ROC->GetYaxis()->SetTitleOffset(1.25);
      ROC->GetYaxis()->SetTitle("S/(#sqrt{S+B})");
      char cat[2]; sprintf(cat,"%i",   category); TString CAT = cat;
      char drM[2]; sprintf(drM,"%.0f", dRMuo   ); TString DRM = drM;
      char drE[2]; sprintf(drE,"%.0f", dREle   ); TString DRE = drE;
      char tmU[2]; sprintf(tmU,"%.0f", TopMass1); TString TMU = tmU;
      char tmD[2]; sprintf(tmD,"%.0f", TopMass2); TString TMD = tmD;
      char tpt[2]; sprintf(tpt,"%.0f", TopPt   ); TString TPT = tpt;
      char zpt[2]; sprintf(zpt,"%.0f", ZPt     ); TString ZPT = zpt;
      char bta[2]; sprintf(bta,"%i",   BTag    ); TString BTA = bta;
	  char fdj[2]; sprintf(fdj,"%i",Forwardjets); TString FDJ = fdj;
      char ept[2]; sprintf(ept,"%.0f", ElePt   ); TString EPT = ept;
      char mpt[2]; sprintf(mpt,"%.0f", MuoPt   ); TString MPT = mpt;
      
      if(UP[p]) c2->SaveAs(name+"_cat"+CAT+"_drM"+DRM+"_drE"+DRE+"_tmU"+TMU+"_tmD"+TMD+"_tpt"+TPT+"_zpt"+ZPT+"_bta"+BTA+"_fdj"+FDJ+"_ept"+EPT+"_mpt"+MPT+"_UP.png");
      else      c2->SaveAs(name+"_cat"+CAT+"_drM"+DRM+"_drE"+DRE+"_tmU"+TMU+"_tmD"+TMD+"_tpt"+TPT+"_zpt"+ZPT+"_bta"+BTA+"_fdj"+FDJ+"_ept"+EPT+"_mpt"+MPT+"_DOWN.png");
      //if(UP[p]) c2->SaveAs(name+"_cat"+CAT+"_drM"+DRM+"_drE"+DRE+"_tmU"+TMU+"_tmD"+TMD+"_tpt"+TPT+"_zpt"+ZPT+"_bta"+BTA+"_fdj"+FDJ+"_ept"+EPT+"_mpt"+MPT+"_UP.pdf");
      //else      c2->SaveAs(name+"_cat"+CAT+"_drM"+DRM+"_drE"+DRE+"_tmU"+TMU+"_tmD"+TMD+"_tpt"+TPT+"_zpt"+ZPT+"_bta"+BTA+"_fdj"+FDJ+"_ept"+EPT+"_mpt"+MPT+"_DOWN.pdf");
      
      TCanvas* c4 = new TCanvas("c4","c4",0,0,800,600);
      TPad *pad1 = new TPad("pad1","",0,0,1,1);
      TPad *pad2 = new TPad("pad2","",0,0,1,1);
      pad2->SetFillStyle(4000); //will be transparent
      pad1->Draw();
      pad1->cd();
      
      SignalEfficiency1->Draw("E");
      SignalEfficiency1->SetMinimum(0.0);
      //SignalEfficiency1->SetMaximum(1.4);
      SignalEfficiency1->SetMarkerStyle(21);
      SignalEfficiency1->SetLineColor(1);
      SignalEfficiency1->GetYaxis()->SetTitleSize(0.045);
      SignalEfficiency1->GetXaxis()->SetTitleSize(0.045);
      SignalEfficiency1->GetYaxis()->SetLabelSize(0.045);
      SignalEfficiency1->GetXaxis()->SetLabelSize(0.045);
      SignalEfficiency1->SetTitle("");
      SignalEfficiency1->GetXaxis()->SetTitle(axis);
      SignalEfficiency1->GetYaxis()->SetTitle("Signal yield");
      
      c4->cd();
      Double_t ymin = 0;
      Double_t  ymax = BackgroundYield1->Integral();//max1*1.5;
      if(!UP[p]) ymax = BackgroundYield1->GetBinContent(1)+10;
      Double_t dy = (ymax-ymin)/0.8; //10 per cent margins top and bottom
      Double_t xmin = SignalEfficiency1->GetXaxis()->GetXmin();
      Double_t xmax = SignalEfficiency1->GetXaxis()->GetXmax();
      Double_t dx = (xmax-xmin)/0.8; //10 per cent margins left and right
      pad2->Range(xmin-0.1*dx,ymin-0.1*dy,xmax+0.1*dx,ymax+0.1*dy);
      pad2->Draw();
      pad2->cd();
      
      BackgroundYield1->SetMinimum(0.0);
      BackgroundYield1->GetYaxis()->SetTitleSize(0.045);
      BackgroundYield1->GetXaxis()->SetTitleSize(0.045);
      BackgroundYield1->GetYaxis()->SetLabelSize(0.045);
      BackgroundYield1->GetXaxis()->SetLabelSize(0.045);
      BackgroundYield1->SetTitle("");
      BackgroundYield1->GetXaxis()->SetTitle(axis);
      BackgroundYield1->GetYaxis()->SetTitle("Background yield");
      BackgroundYield1->SetMarkerStyle(21);
      BackgroundYield1->SetMarkerColor(2);
      BackgroundYield1->SetLineColor(2);
      BackgroundYield1->Draw("][sames");
       
      // draw axis on the right side of the pad
      TGaxis *Axis1 = new TGaxis(xmax,ymin,xmax,ymax,ymin,ymax,510,"+L");
      Axis1->SetLabelColor(kRed);
      Axis1->SetTitle("Background Yield");
      Axis1->SetTitleOffset(1.2);
      Axis1->SetTitleColor(kRed);
      Axis1->SetTitleSize(0.045);
      Axis1->SetLabelSize(0.045);
      Axis1->Draw();
      
      TLegend *pl = new TLegend(0.57,0.75,0.89,0.89);
      pl->SetTextSize(0.03); 
      pl->SetFillColor(0);
      TLegendEntry *ple = pl->AddEntry(SignalEfficiency1, "Signal Yield",  "LP");
      ple               = pl->AddEntry(BackgroundYield1,  "Background Yield",  "LP");
      pl->Draw();
      if(UP[p]) c4->SaveAs(name+"_cat"+CAT+"_drM"+DRM+"_drE"+DRE+"_tmU"+TMU+"_tmD"+TMD+"_tpt"+TPT+"_zpt"+ZPT+"_bta"+BTA+"_fdj"+FDJ+"_ept"+EPT+"_mpt"+MPT+"_yields_UP.png");
      else      c4->SaveAs(name+"_cat"+CAT+"_drM"+DRM+"_drE"+DRE+"_tmU"+TMU+"_tmD"+TMD+"_tpt"+TPT+"_zpt"+ZPT+"_bta"+BTA+"_fdj"+FDJ+"_ept"+EPT+"_mpt"+MPT+"_yields_DOWN.png");
      //if(UP[p]) c4->SaveAs(name+"_cat"+CAT+"_drM"+DRM+"_drE"+DRE+"_tmU"+TMU+"_tmD"+TMD+"_tpt"+TPT+"_zpt"+ZPT+"_bta"+BTA+"_fdj"+FDJ+"_ept"+EPT+"_mpt"+MPT+"_yields_UP.pdf");
      //else      c4->SaveAs(name+"_cat"+CAT+"_drM"+DRM+"_drE"+DRE+"_tmU"+TMU+"_tmD"+TMD+"_tpt"+TPT+"_zpt"+ZPT+"_bta"+BTA+"_fdj"+FDJ+"_ept"+EPT+"_mpt"+MPT+"_yields_DOWN.pdf");
      delete ROC;
      delete SignalEfficiency1;
      delete BackgroundYield1;
      delete c2;
      delete c4;
    }
  }
}
