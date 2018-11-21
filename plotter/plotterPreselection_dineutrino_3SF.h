/*void MakeHistos(char CUTPre[1000],const char *plot, int BIN,double MIN,double MAX,int JETSyst,
		TH1F* &data_func,TH1F* &background_func,
		TH1F* &ZToNuNu_func,TH1F* &QCD_func,TH1F* &WToLNu_func,TH1F* &TT_func,TH1F* &ST_func,TH1F* &VV_func,
		TH1F* &tptzm0700lh_func,TH1F* &tptzm0900lh_func,TH1F* &tptzm1400lh_func,TH1F* &tptzm1700lh_func);*/

//void CalculateSF(char CUTCS1[1000],char CUTCS2[1000],char CUTCS3[1000],const char *plot_CR, int BIN_CR,double MIN_CR,double MAX_CR);

void CalculateSF(char CUTCS1[1000],char CUTCS2[1000],char CUTCS3[1000],const char *plot_CR, int BIN_CR,double MIN_CR,double MAX_CR,
	             double &SF1,double &SF2,double &SF3,double &SF1_err, double &SF2_err, double &SF3_err, double &SF_den);

void MakeHistos(char CUTPre[1000],const char *plot, int BIN,double MIN,double MAX,int JETSyst,
	    double &SF1,double &SF2,double &SF3,double &SF1_err, double &SF2_err, double &SF3_err,
		TH1F* &data_func,TH1F* &background_func,
		TH1F* &ZToNuNu_func,TH1F* &QCD_func,TH1F* &WToLNu_func,TH1F* &TT_func,TH1F* &ST_func,TH1F* &VV_func,
		TH1F* &tptzm0700lh_func,TH1F* &tptzm0900lh_func,TH1F* &tptzm1400lh_func,TH1F* &tptzm1700lh_func);

void CloneHistos(TH1F* &data_func,TH1F* &background_func,
		TH1F* &ZToNuNu_func,TH1F* &QCD_func,TH1F* &WToLNu_func,TH1F* &TT_func,TH1F* &ST_func,TH1F* &VV_func,
		TH1F* &tptzm0700lh_func,TH1F* &tptzm0900lh_func,TH1F* &tptzm1400lh_func,TH1F* &tptzm1700lh_func);

//MakePlot(int &j,TH1F* &SF1_h,TH1F* &SF2_h,TH1F* &SF3_h,double &SF1,double &SF2,double &SF3,double &SF1_err,double &SF2_err,double &SF3_err);

int SigSF = 1;
double LUMI  = 41100.0; 
double w0700 = SigSF*(0.5*0.5*5.820 *0.25*LUMI/388056); //SIG1
double w0800 = SigSF*(0.5*0.5*3.860 *0.25*LUMI/400000.0); //SIG2
double w0900 = SigSF*(0.5*0.5*2.720 *0.25*LUMI/400000.0); //SIG3
double w1000 = SigSF*(0.5*0.5*1.952 *0.25*LUMI/396804); //SIG4
double w1100 = SigSF*(0.5*0.5*1.352 *0.25*LUMI/400000.0); //SIG5
double w1200 = SigSF*(0.5*0.5*0.984 *0.25*LUMI/400000.0); //SIG6
double w1300 = SigSF*(0.5*0.5*0.716 *0.25*LUMI/400000.0); //SIG7
double w1400 = SigSF*(0.5*0.5*0.540 *0.25*LUMI/400000.0); //SIG8
double w1500 = SigSF*(0.5*0.5*0.408 *0.25*LUMI/364210.); //SIG9
double w1600 = SigSF*(0.5*0.5*0.304 *0.25*LUMI/386506.0); //SIG10
double w1700 = SigSF*(0.5*0.5*0.232 *0.25*LUMI/400000.0); //SIG11
double w1800 = SigSF*(0.5*0.5*0.174 *0.25*LUMI/122350.0); //SIG12
double w01 = (384.1*LUMI/(22719867-17399));    //ZToNuNu_HT100to200    
double w02 = (118.1*LUMI/(21641038-28710));     //ZToNuNu_HT200to400    
double w03 = (14.7*LUMI/(9763364-20994));  //ZToNuNu_HT400to600  
double w04 = (3.35*LUMI/(5681118-16476));     //ZToNuNu_HT600to800        
//double w05 = (1.68*LUMI/(1956431-7779));     //ZToNuNu_HT800to1200 
double w05 = (1.41*LUMI/(1956431-7779));     //ZToNuNu_HT800to1200
double w06 = (0.316*LUMI/(361396-2478));      //ZToNuNu_HT1200to2500      
double w07 = (0.00722*LUMI/(6590-144));      //ZToNuNu_HT2500toInf       
double w08 = (1559000*LUMI/(58563078-33131));       //QCD_HT200to300            
double w09 = (315900*LUMI/(5472388-4307));       //QCD_HT300to500           
double w10 = (29070*LUMI/(53716622-79830));     //QCD_HT500to700            
double w11 = (5962*LUMI/(47621862-102938));    //QCD_HT700to1000           
double w12 = (1005*LUMI/(16427124-54782));   //QCD_HT1000to1500      
double w13 = (101.8*LUMI/(10983547-59784));   //QCD_HT1500to2000      
double w14 = (20.54*LUMI/(5368775-52758));  //QCD_HT2000toInf 
double w15 = (1695.*LUMI/(34362020-28016));    //WToLNu_HT100to200
double w16 = (532.4*LUMI/(21112938-28991));    //WToLNu_HT200to400
double w17 = (61.6*LUMI/(14112725-31248));    //WToLNu_HT400to600
double w18 = (12.4*LUMI/(21484173-62923));    //WToLNu_HT600to800
double w19 = (5.77*LUMI/(20135179-78933));    //WToLNu_HT800to1200
double w20 = (1.023*LUMI/(20087191-133115));    //WToLNu_HT1200to2500
double w21 = (0.0248*LUMI/(20811788-427668));    //WToLNu_HT2500toInf
double w22 = (88.290*LUMI/(66320355-269431));     //TTbar1 2L2Nu
double w23 = (365.34*LUMI/(110386711-448329));    //TTbar2 semileptonic               
double w24 = (80.95*LUMI/3939990);   //ST_t-channel_antitop  
double w25 = (136.02*LUMI/5724387);   //ST_t-channel_top      
double w26 = (38.06*LUMI/(7492417-28713));  //ST_tW_antitop.root     
double w27 = (38.06*LUMI/(7552459-29165));     //ST_tW_top     
double w28 = (1.204*LUMI/(6838439-34646)); //ZZTo4L
double w29 = (3.222*LUMI/(22476050-4964013)); //ZZTo2L2Q
double w30 = (0.5644*LUMI/(8244645-5269)); //ZZTo2L2Nu
double w31 = (10.48*LUMI/(1734206-3229)); //WWTo2L2Nu
double w32 = (43.53*LUMI/(8664079-16346)); //WWToLNuQQ
double w33 = (10.73*LUMI/(14998726-3814091)); //WZTo1L1Nu2Q
double w34 = (5.606*LUMI/(21970347-5421061)); //WZTo2L2Q
double w35 = (4.43*LUMI/(8639924-1982578)); //WZTo3LNu   
double w36 = (377.96*LUMI/(129706664-525366)); //TTbar3 Hadronic 

/*double w01 = (280.35*LUMI/(22719867-17399));    //ZToNuNu_HT100to200    
double w02 = (77.67*LUMI/(21641038-28710));     //ZToNuNu_HT200to400    
double w03 = (10.73*LUMI/(9763364-20994));  //ZToNuNu_HT400to600  
double w04 = (0.853*LUMI/(5681118-16476));     //ZToNuNu_HT600to800        
double w05 = (0.3942*LUMI/(1956431-7779));     //ZToNuNu_HT800to1200      
double w06 = (0.0974*LUMI/(361396-2478));      //ZToNuNu_HT1200to2500      
double w07 = (0.002308*LUMI/(6590-144));*/      //ZToNuNu_HT2500toInf    
const char openTree[5]= "tree";
const char openTreeB[6]= "treeB";
const char openTreeC[6]= "treeC";
const char openTreeD[6]= "treeD";
TFile *file01 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/data.root");
TFile *file02 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/Tprime_0700.root");
TFile *file03 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/Tprime_0800.root");
TFile *file04 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/Tprime_0900.root");
TFile *file05 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/Tprime_1000.root");
TFile *file06 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/Tprime_1100.root");
TFile *file07 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/Tprime_1200.root");
TFile *file08 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/Tprime_1300.root");
TFile *file09 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/Tprime_1400.root");
TFile *file10 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/Tprime_1500.root");
TFile *file11 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/Tprime_1600.root");
TFile *file12 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/Tprime_1700.root");
TFile *file13 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/Tprime_1800.root");
TFile *file14 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/ZToNuNu_HT100to200.root");
TFile *file15 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/ZToNuNu_HT200to400.root");
TFile *file16 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/ZToNuNu_HT400to600.root");
TFile *file17 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/ZToNuNu_HT600to800.root");
TFile *file18 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/ZToNuNu_HT800to1200.root");
TFile *file19 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/ZToNuNu_HT1200to2500.root");
TFile *file20 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/ZToNuNu_HT2500toInf.root");
TFile *file21 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/QCD_HT200to300.root");
TFile *file22 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/QCD_HT300to500.root");
TFile *file23 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/QCD_HT500to700.root");
TFile *file24 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/QCD_HT700to1000.root");
TFile *file25 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/QCD_HT1000to1500.root");
TFile *file26 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/QCD_HT1500to2000.root");
TFile *file27 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/QCD_HT2000toInf.root");
TFile *file28 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/WToLNu_HT100to200.root");
TFile *file29 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/WToLNu_HT200to400.root");
TFile *file30 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/WToLNu_HT400to600.root");
TFile *file31 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/WToLNu_HT600to800.root");
TFile *file32 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/WToLNu_HT800to1200.root");
TFile *file33 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/WToLNu_HT1200to2500.root");
TFile *file34 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/WToLNu_HT2500toInf.root");
TFile *file35 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/TTTo2L2Nu.root  ");
TFile *file36 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/TTToSemiLeptonic.root");
TFile *file37 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/ST_t-channel_antitop.root");
TFile *file38 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/ST_t-channel_top.root");
TFile *file39 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/ST_tW_antitop.root");
TFile *file40 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/ST_tW_top.root");
TFile *file41 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/ZZTo4L.root");
TFile *file42 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/ZZTo2L2Q.root");
TFile *file43 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/ZZTo2L2Nu.root");
TFile *file44 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/WWTo2L2Nu.root");
TFile *file45 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/WWToLNuQQ.root");
TFile *file46 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/WZTo1L1Nu2Q.root ");
TFile *file47 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/WZTo2L2Q.root");
TFile *file48 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v15/WZTo3LNu.root");
TTree *Tree01 = (TTree*)file01->Get(openTree);     //TTree *Tree01_B = (TTree*)file01->Get(openTreeB);   TTree *Tree01_C = (TTree*)file01->Get(openTreeC);   TTree *Tree01_D = (TTree*)file01->Get(openTreeD);
TTree *Tree02 = (TTree*)file02->Get(openTree);     //TTree *Tree02_B = (TTree*)file02->Get(openTreeB);   TTree *Tree02_C = (TTree*)file02->Get(openTreeC);   TTree *Tree02_D = (TTree*)file02->Get(openTreeD);
TTree *Tree03 = (TTree*)file03->Get(openTree);     //TTree *Tree03_B = (TTree*)file03->Get(openTreeB);   TTree *Tree03_C = (TTree*)file03->Get(openTreeC);   TTree *Tree03_D = (TTree*)file03->Get(openTreeD);
TTree *Tree04 = (TTree*)file04->Get(openTree);     //TTree *Tree04_B = (TTree*)file04->Get(openTreeB);   TTree *Tree04_C = (TTree*)file04->Get(openTreeC);   TTree *Tree04_D = (TTree*)file04->Get(openTreeD);
TTree *Tree05 = (TTree*)file05->Get(openTree);     //TTree *Tree05_B = (TTree*)file05->Get(openTreeB);   TTree *Tree05_C = (TTree*)file05->Get(openTreeC);   TTree *Tree05_D = (TTree*)file05->Get(openTreeD);
TTree *Tree06 = (TTree*)file06->Get(openTree);     //TTree *Tree06_B = (TTree*)file06->Get(openTreeB);   TTree *Tree06_C = (TTree*)file06->Get(openTreeC);   TTree *Tree06_D = (TTree*)file06->Get(openTreeD);
TTree *Tree07 = (TTree*)file07->Get(openTree);     //TTree *Tree07_B = (TTree*)file07->Get(openTreeB);   TTree *Tree07_C = (TTree*)file07->Get(openTreeC);   TTree *Tree07_D = (TTree*)file07->Get(openTreeD);
TTree *Tree08 = (TTree*)file08->Get(openTree);     //TTree *Tree08_B = (TTree*)file08->Get(openTreeB);   TTree *Tree08_C = (TTree*)file08->Get(openTreeC);   TTree *Tree08_D = (TTree*)file08->Get(openTreeD);
TTree *Tree09 = (TTree*)file09->Get(openTree);     //TTree *Tree09_B = (TTree*)file09->Get(openTreeB);   TTree *Tree09_C = (TTree*)file09->Get(openTreeC);   TTree *Tree09_D = (TTree*)file09->Get(openTreeD);
TTree *Tree10 = (TTree*)file10->Get(openTree);     //TTree *Tree10_B = (TTree*)file10->Get(openTreeB);   TTree *Tree10_C = (TTree*)file10->Get(openTreeC);   TTree *Tree10_D = (TTree*)file10->Get(openTreeD);
TTree *Tree11 = (TTree*)file11->Get(openTree);     //TTree *Tree11_B = (TTree*)file11->Get(openTreeB);   TTree *Tree11_C = (TTree*)file11->Get(openTreeC);   TTree *Tree11_D = (TTree*)file11->Get(openTreeD);
TTree *Tree12 = (TTree*)file12->Get(openTree);     //TTree *Tree12_B = (TTree*)file12->Get(openTreeB);   TTree *Tree12_C = (TTree*)file12->Get(openTreeC);   TTree *Tree12_D = (TTree*)file12->Get(openTreeD);
TTree *Tree13 = (TTree*)file13->Get(openTree);     //TTree *Tree13_B = (TTree*)file13->Get(openTreeB);   TTree *Tree13_C = (TTree*)file13->Get(openTreeC);   TTree *Tree13_D = (TTree*)file13->Get(openTreeD);
TTree *Tree14 = (TTree*)file14->Get(openTree);     //TTree *Tree14_B = (TTree*)file14->Get(openTreeB);   TTree *Tree14_C = (TTree*)file14->Get(openTreeC);   TTree *Tree14_D = (TTree*)file14->Get(openTreeD);
TTree *Tree15 = (TTree*)file15->Get(openTree);     //TTree *Tree15_B = (TTree*)file15->Get(openTreeB);   TTree *Tree15_C = (TTree*)file15->Get(openTreeC);   TTree *Tree15_D = (TTree*)file15->Get(openTreeD);
TTree *Tree16 = (TTree*)file16->Get(openTree);     //TTree *Tree16_B = (TTree*)file16->Get(openTreeB);   TTree *Tree16_C = (TTree*)file16->Get(openTreeC);   TTree *Tree16_D = (TTree*)file16->Get(openTreeD);
TTree *Tree17 = (TTree*)file17->Get(openTree);     //TTree *Tree17_B = (TTree*)file17->Get(openTreeB);   TTree *Tree17_C = (TTree*)file17->Get(openTreeC);   TTree *Tree17_D = (TTree*)file17->Get(openTreeD);
TTree *Tree18 = (TTree*)file18->Get(openTree);     //TTree *Tree18_B = (TTree*)file18->Get(openTreeB);   TTree *Tree18_C = (TTree*)file18->Get(openTreeC);   TTree *Tree18_D = (TTree*)file18->Get(openTreeD);
TTree *Tree19 = (TTree*)file19->Get(openTree);     //TTree *Tree19_B = (TTree*)file19->Get(openTreeB);   TTree *Tree19_C = (TTree*)file19->Get(openTreeC);   TTree *Tree19_D = (TTree*)file19->Get(openTreeD);
TTree *Tree20 = (TTree*)file20->Get(openTree);     //TTree *Tree20_B = (TTree*)file20->Get(openTreeB);   TTree *Tree20_C = (TTree*)file20->Get(openTreeC);   TTree *Tree20_D = (TTree*)file20->Get(openTreeD);
TTree *Tree21 = (TTree*)file21->Get(openTree);     //TTree *Tree21_B = (TTree*)file21->Get(openTreeB);   TTree *Tree21_C = (TTree*)file21->Get(openTreeC);   TTree *Tree21_D = (TTree*)file21->Get(openTreeD);
TTree *Tree22 = (TTree*)file22->Get(openTree);     //TTree *Tree22_B = (TTree*)file22->Get(openTreeB);   TTree *Tree22_C = (TTree*)file22->Get(openTreeC);   TTree *Tree22_D = (TTree*)file22->Get(openTreeD);
TTree *Tree23 = (TTree*)file23->Get(openTree);     //TTree *Tree23_B = (TTree*)file23->Get(openTreeB);   TTree *Tree23_C = (TTree*)file23->Get(openTreeC);   TTree *Tree23_D = (TTree*)file23->Get(openTreeD);
TTree *Tree24 = (TTree*)file24->Get(openTree);     //TTree *Tree24_B = (TTree*)file24->Get(openTreeB);   TTree *Tree24_C = (TTree*)file24->Get(openTreeC);   TTree *Tree24_D = (TTree*)file24->Get(openTreeD);
TTree *Tree25 = (TTree*)file25->Get(openTree);     //TTree *Tree25_B = (TTree*)file25->Get(openTreeB);   TTree *Tree25_C = (TTree*)file25->Get(openTreeC);   TTree *Tree25_D = (TTree*)file25->Get(openTreeD);
TTree *Tree26 = (TTree*)file26->Get(openTree);     //TTree *Tree26_B = (TTree*)file26->Get(openTreeB);   TTree *Tree26_C = (TTree*)file26->Get(openTreeC);   TTree *Tree26_D = (TTree*)file26->Get(openTreeD);
TTree *Tree27 = (TTree*)file27->Get(openTree);     //TTree *Tree27_B = (TTree*)file27->Get(openTreeB);   TTree *Tree27_C = (TTree*)file27->Get(openTreeC);   TTree *Tree27_D = (TTree*)file27->Get(openTreeD);
TTree *Tree28 = (TTree*)file28->Get(openTree);     //TTree *Tree28_B = (TTree*)file28->Get(openTreeB);   TTree *Tree28_C = (TTree*)file28->Get(openTreeC);   TTree *Tree28_D = (TTree*)file28->Get(openTreeD);
TTree *Tree29 = (TTree*)file29->Get(openTree);     //TTree *Tree29_B = (TTree*)file29->Get(openTreeB);   TTree *Tree29_C = (TTree*)file29->Get(openTreeC);   TTree *Tree29_D = (TTree*)file29->Get(openTreeD);
TTree *Tree30 = (TTree*)file30->Get(openTree);     //TTree *Tree30_B = (TTree*)file30->Get(openTreeB);   TTree *Tree30_C = (TTree*)file30->Get(openTreeC);   TTree *Tree30_D = (TTree*)file30->Get(openTreeD);
TTree *Tree31 = (TTree*)file31->Get(openTree);     //TTree *Tree31_B = (TTree*)file31->Get(openTreeB);   TTree *Tree31_C = (TTree*)file31->Get(openTreeC);   TTree *Tree31_D = (TTree*)file31->Get(openTreeD);
TTree *Tree32 = (TTree*)file32->Get(openTree);     //TTree *Tree32_B = (TTree*)file32->Get(openTreeB);   TTree *Tree32_C = (TTree*)file32->Get(openTreeC);   TTree *Tree32_D = (TTree*)file32->Get(openTreeD);
TTree *Tree33 = (TTree*)file33->Get(openTree);     //TTree *Tree33_B = (TTree*)file33->Get(openTreeB);   TTree *Tree33_C = (TTree*)file33->Get(openTreeC);   TTree *Tree33_D = (TTree*)file33->Get(openTreeD);
TTree *Tree34 = (TTree*)file34->Get(openTree);     //TTree *Tree34_B = (TTree*)file34->Get(openTreeB);   TTree *Tree34_C = (TTree*)file34->Get(openTreeC);   TTree *Tree34_D = (TTree*)file34->Get(openTreeD);
TTree *Tree35 = (TTree*)file35->Get(openTree);     //TTree *Tree35_B = (TTree*)file35->Get(openTreeB);   TTree *Tree35_C = (TTree*)file35->Get(openTreeC);   TTree *Tree35_D = (TTree*)file35->Get(openTreeD);
TTree *Tree36 = (TTree*)file36->Get(openTree);     //TTree *Tree36_B = (TTree*)file36->Get(openTreeB);   TTree *Tree36_C = (TTree*)file36->Get(openTreeC);   TTree *Tree36_D = (TTree*)file36->Get(openTreeD);
TTree *Tree37 = (TTree*)file37->Get(openTree);     //TTree *Tree37_B = (TTree*)file37->Get(openTreeB);   TTree *Tree37_C = (TTree*)file37->Get(openTreeC);   TTree *Tree37_D = (TTree*)file37->Get(openTreeD);
TTree *Tree38 = (TTree*)file38->Get(openTree);     //TTree *Tree38_B = (TTree*)file38->Get(openTreeB);   TTree *Tree38_C = (TTree*)file38->Get(openTreeC);   TTree *Tree38_D = (TTree*)file38->Get(openTreeD);
TTree *Tree39 = (TTree*)file39->Get(openTree);     //TTree *Tree39_B = (TTree*)file39->Get(openTreeB);   TTree *Tree39_C = (TTree*)file39->Get(openTreeC);   TTree *Tree39_D = (TTree*)file39->Get(openTreeD);
TTree *Tree40 = (TTree*)file40->Get(openTree);     //TTree *Tree40_B = (TTree*)file40->Get(openTreeB);   TTree *Tree40_C = (TTree*)file40->Get(openTreeC);   TTree *Tree40_D = (TTree*)file40->Get(openTreeD);
TTree *Tree41 = (TTree*)file41->Get(openTree);     //TTree *Tree41_B = (TTree*)file41->Get(openTreeB);   TTree *Tree41_C = (TTree*)file41->Get(openTreeC);   TTree *Tree41_D = (TTree*)file41->Get(openTreeD);
TTree *Tree42 = (TTree*)file42->Get(openTree);     //TTree *Tree42_B = (TTree*)file42->Get(openTreeB);   TTree *Tree42_C = (TTree*)file42->Get(openTreeC);   TTree *Tree42_D = (TTree*)file42->Get(openTreeD);
TTree *Tree43 = (TTree*)file43->Get(openTree);     //TTree *Tree43_B = (TTree*)file43->Get(openTreeB);   TTree *Tree43_C = (TTree*)file43->Get(openTreeC);   TTree *Tree43_D = (TTree*)file43->Get(openTreeD);
TTree *Tree44 = (TTree*)file44->Get(openTree);     //TTree *Tree44_B = (TTree*)file44->Get(openTreeB);   TTree *Tree44_C = (TTree*)file44->Get(openTreeC);   TTree *Tree44_D = (TTree*)file44->Get(openTreeD);
TTree *Tree45 = (TTree*)file45->Get(openTree);     //TTree *Tree45_B = (TTree*)file45->Get(openTreeB);   TTree *Tree45_C = (TTree*)file45->Get(openTreeC);   TTree *Tree45_D = (TTree*)file45->Get(openTreeD);
TTree *Tree46 = (TTree*)file46->Get(openTree);     //TTree *Tree46_B = (TTree*)file46->Get(openTreeB);   TTree *Tree46_C = (TTree*)file46->Get(openTreeC);   TTree *Tree46_D = (TTree*)file46->Get(openTreeD);
TTree *Tree47 = (TTree*)file47->Get(openTree);     //TTree *Tree47_B = (TTree*)file47->Get(openTreeB);   TTree *Tree47_C = (TTree*)file47->Get(openTreeC);   TTree *Tree47_D = (TTree*)file47->Get(openTreeD);
TTree *Tree48 = (TTree*)file48->Get(openTree);     //TTree *Tree48_B = (TTree*)file48->Get(openTreeB);   TTree *Tree48_C = (TTree*)file48->Get(openTreeC);   TTree *Tree48_D = (TTree*)file48->Get(openTreeD);


TH1F *data_PRE; 
TH1F *ZToNuNu_PRE;  
TH1F *QCD_PRE; 
TH1F *WToLNu_PRE;  
TH1F *TT_PRE; 
TH1F *ST_PRE;  
TH1F *VV_PRE; 
TH1F *background_PRE;
TH1F *tptzm0700lh_PRE;
TH1F *tptzm0900lh_PRE;
TH1F *tptzm1400lh_PRE;
TH1F *tptzm1700lh_PRE;

const int N = 12;  Double_t xbins[N] = {200,300,400,500,600,700,800,1000,1200,1400,1700,2500};

TH1F *SF1_h   = new TH1F("SF1_h",  "SF1_h",  N-1,xbins);
TH1F *SF2_h   = new TH1F("SF2_h",  "SF2_h",  N-1,xbins);
TH1F *SF3_h   = new TH1F("SF3_h",  "SF3_h",  N-1,xbins);

double SF1; double SF2; double SF3;
double SF1_err; double SF2_err; double SF3_err;
double SF_den;
double SF_den_err;
double SF1_num_err;
double SF2_num_err;
double SF3_num_err;

