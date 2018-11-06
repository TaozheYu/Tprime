void MakeHistos(char CUT[1000],const char *plot,int BIN,float MIN,float MAX,int JETSyst,
		TH1F* &data_func,TH1F* &background_func,TH1F* &ZToNuNu_1_func,TH1F* &ZToNuNu_2_func,TH1F* &ZToNuNu_3_func,TH1F* &ZToNuNu_4_func,TH1F* &ZToNuNu_5_func,TH1F* &ZToNuNu_6_func,TH1F* &ZToNuNu_7_func,
		TH1F* &QCD_1_func,TH1F* &QCD_2_func,TH1F* &QCD_3_func,TH1F* &QCD_4_func,TH1F* &QCD_5_func,TH1F* &QCD_6_func,TH1F* &QCD_7_func,
		TH1F* &WToLNu_1_func,TH1F* &WToLNu_2_func,TH1F* &WToLNu_3_func,TH1F* &WToLNu_4_func,TH1F* &WToLNu_5_func,TH1F* &WToLNu_6_func,TH1F* &WToLNu_7_func,
		TH1F* &TT_1_func,TH1F* &TT_2_func,TH1F* &ST_1_func,TH1F* &ST_2_func,TH1F* &ST_3_func,TH1F* &ST_4_func,
		TH1F* &ZZ1_func,TH1F* &ZZ2_func,TH1F* &ZZ3_func,TH1F* &WW1_func,TH1F* &WW2_func,TH1F* &WZ1_func,TH1F* &WZ2_func,TH1F* &WZ3_func,
		TH1F* &tptzm0700lh_func,TH1F* &tptzm1000lh_func,TH1F* &tptzm1400lh_func,TH1F* &tptzm1700lh_func);
void MakeHistoErrors(int m, TH1F* &histo_SR, TH1F* histo_P1, TH1F* histo_P2, TH1F* histo_F1, TH1F* histo_F2, TH1F* histo_B1, TH1F* histo_B2, TH1F* histo_Z1, TH1F* histo_Z2, TH1F* histo_W1, TH1F* histo_W2, TH1F* histo_T1, TH1F* histo_T2, TH1F* histo_J1, TH1F* histo_J2, TH1F* histo_J3, TH1F* histo_J4);
void CloneHistos();

int SigSF = 1;
float LUMI  = 41100.0; 
float w0700 = SigSF*(0.5*0.5*5.820 *0.25*LUMI/388056); //SIG1
float w0800 = SigSF*(0.5*0.5*3.860 *0.25*LUMI/400000.0); //SIG2
float w0900 = SigSF*(0.5*0.5*2.720 *0.25*LUMI/400000.0); //SIG3
float w1000 = SigSF*(0.5*0.5*1.952 *0.25*LUMI/396804); //SIG4
float w1100 = SigSF*(0.5*0.5*1.352 *0.25*LUMI/400000.0); //SIG5
float w1200 = SigSF*(0.5*0.5*0.984 *0.25*LUMI/400000.0); //SIG6
float w1300 = SigSF*(0.5*0.5*0.716 *0.25*LUMI/400000.0); //SIG7
float w1400 = SigSF*(0.5*0.5*0.540 *0.25*LUMI/400000.0); //SIG8
float w1500 = SigSF*(0.5*0.5*0.408 *0.25*LUMI/364210.); //SIG9
float w1600 = SigSF*(0.5*0.5*0.304 *0.25*LUMI/386506.0); //SIG10
float w1700 = SigSF*(0.5*0.5*0.232 *0.25*LUMI/400000.0); //SIG11
float w1800 = SigSF*(0.5*0.5*0.174 *0.25*LUMI/122350.0); //SIG12
float w01 = (384.1*LUMI/(22719867-17399));    //ZToNuNu_HT100to200    
float w02 = (118.1*LUMI/(21641038-28710));     //ZToNuNu_HT200to400    
float w03 = (14.7*LUMI/(9763364-20994));  //ZToNuNu_HT400to600  
float w04 = (3.35*LUMI/(5681118-16476));     //ZToNuNu_HT600to800        
//float w05 = (1.68*LUMI/(1956431-7779));     //ZToNuNu_HT800to1200 
float w05 = (1.41*LUMI/(1956431-7779));     //ZToNuNu_HT800to1200
float w06 = (0.316*LUMI/(361396-2478));      //ZToNuNu_HT1200to2500      
float w07 = (0.00722*LUMI/(6590-144));      //ZToNuNu_HT2500toInf       
float w08 = (1559000*LUMI/(58563078-33131));       //QCD_HT200to300            
float w09 = (315900*LUMI/(5472388-4307));       //QCD_HT300to500           
float w10 = (29070*LUMI/(53716622-79830));     //QCD_HT500to700            
float w11 = (5962*LUMI/(47621862-102938));    //QCD_HT700to1000           
float w12 = (1005*LUMI/(16427124-54782));   //QCD_HT1000to1500      
float w13 = (101.8*LUMI/(10983547-59784));   //QCD_HT1500to2000      
float w14 = (20.54*LUMI/(5368775-52758));  //QCD_HT2000toInf 
float w15 = (1695.*LUMI/(34362020-28016));    //WToLNu_HT100to200
float w16 = (532.4*LUMI/(21112938-28991));    //WToLNu_HT200to400
float w17 = (61.6*LUMI/(14112725-31248));    //WToLNu_HT400to600
float w18 = (12.4*LUMI/(21484173-62923));    //WToLNu_HT600to800
float w19 = (5.77*LUMI/(20135179-78933));    //WToLNu_HT800to1200
float w20 = (1.023*LUMI/(20087191-133115));    //WToLNu_HT1200to2500
float w21 = (0.0248*LUMI/(20811788-427668));    //WToLNu_HT2500toInf
float w22 = (88.290*LUMI/(66320355-269431));     //TTbar1 2L2Nu
float w23 = (365.34*LUMI/(110386711-448329));    //TTbar2 semileptonic               
float w24 = (80.95*LUMI/3939990);   //ST_t-channel_antitop  
float w25 = (136.02*LUMI/5724387);   //ST_t-channel_top      
float w26 = (38.06*LUMI/(7492417-28713));  //ST_tW_antitop.root     
float w27 = (38.06*LUMI/(7552459-29165));     //ST_tW_top     
float w28 = (1.204*LUMI/(6838439-34646)); //ZZTo4L
float w29 = (3.222*LUMI/(22476050-4964013)); //ZZTo2L2Q
float w30 = (0.5644*LUMI/(8244645-5269)); //ZZTo2L2Nu
float w31 = (10.48*LUMI/(1734206-3229)); //WWTo2L2Nu
float w32 = (43.53*LUMI/(8664079-16346)); //WWToLNuQQ
float w33 = (10.73*LUMI/(14998726-3814091)); //WZTo1L1Nu2Q
float w34 = (5.606*LUMI/(21970347-5421061)); //WZTo2L2Q
float w35 = (4.43*LUMI/(8639924-1982578)); //WZTo3LNu       

TFile *file01 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/data.root");
TFile *file02 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/Tprime_0700.root");
TFile *file03 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/Tprime_0800.root");
TFile *file04 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/Tprime_0900.root");
TFile *file05 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/Tprime_1000.root");
TFile *file06 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/Tprime_1100.root");
TFile *file07 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/Tprime_1200.root");
TFile *file08 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/Tprime_1300.root");
TFile *file09 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/Tprime_1400.root");
TFile *file10 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/Tprime_1500.root");
TFile *file11 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/Tprime_1600.root");
TFile *file12 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/Tprime_1700.root");
TFile *file13 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/Tprime_1800.root");
TFile *file14 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/ZToNuNu_HT100to200.root");
TFile *file15 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/ZToNuNu_HT200to400.root");
TFile *file16 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/ZToNuNu_HT400to600.root");
TFile *file17 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/ZToNuNu_HT600to800.root");
TFile *file18 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/ZToNuNu_HT800to1200.root");
TFile *file19 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/ZToNuNu_HT1200to2500.root");
TFile *file20 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/ZToNuNu_HT2500toInf.root");
TFile *file21 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/QCD_HT200to300.root");
TFile *file22 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/QCD_HT300to500.root");
TFile *file23 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/QCD_HT500to700.root");
TFile *file24 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/QCD_HT700to1000.root");
TFile *file25 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/QCD_HT1000to1500.root");
TFile *file26 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/QCD_HT1500to2000.root");
TFile *file27 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/QCD_HT2000toInf.root");
TFile *file28 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/WToLNu_HT100to200.root");
TFile *file29 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/WToLNu_HT200to400.root");
TFile *file30 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/WToLNu_HT400to600.root");
TFile *file31 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/WToLNu_HT600to800.root");
TFile *file32 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/WToLNu_HT800to1200.root");
TFile *file33 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/WToLNu_HT1200to2500.root");
TFile *file34 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/WToLNu_HT2500toInf.root");
TFile *file35 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/TTTo2L2Nu.root  ");
TFile *file36 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/TTToSemiLeptonic.root");
TFile *file37 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/ST_t-channel_antitop.root");
TFile *file38 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/ST_t-channel_top.root");
TFile *file39 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/ST_tW_antitop.root");
TFile *file40 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/ST_tW_top.root");
TFile *file41 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/ZZTo4L.root");
TFile *file42 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/ZZTo2L2Q.root");
TFile *file43 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/ZZTo2L2Nu.root");
TFile *file44 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/WWTo2L2Nu.root");
TFile *file45 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/WWToLNuQQ.root");
TFile *file46 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/WZTo1L1Nu2Q.root ");
TFile *file47 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/WZTo2L2Q.root");
TFile *file48 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/WZTo3LNu.root");
TTree *Tree01 = (TTree*)file01->Get("tree");
TTree *Tree02 = (TTree*)file02->Get("tree");
TTree *Tree03 = (TTree*)file03->Get("tree");
TTree *Tree04 = (TTree*)file04->Get("tree");
TTree *Tree05 = (TTree*)file05->Get("tree");
TTree *Tree06 = (TTree*)file06->Get("tree");
TTree *Tree07 = (TTree*)file07->Get("tree");
TTree *Tree08 = (TTree*)file08->Get("tree");
TTree *Tree09 = (TTree*)file09->Get("tree");
TTree *Tree10 = (TTree*)file10->Get("tree");
TTree *Tree11 = (TTree*)file11->Get("tree");
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
TTree *Tree35 = (TTree*)file35->Get("tree");
TTree *Tree36 = (TTree*)file36->Get("tree");
TTree *Tree37 = (TTree*)file37->Get("tree");
TTree *Tree38 = (TTree*)file38->Get("tree");
TTree *Tree39 = (TTree*)file39->Get("tree");
TTree *Tree40 = (TTree*)file40->Get("tree");
TTree *Tree41 = (TTree*)file41->Get("tree");
TTree *Tree42 = (TTree*)file42->Get("tree");
TTree *Tree43 = (TTree*)file43->Get("tree");
TTree *Tree44 = (TTree*)file44->Get("tree");
TTree *Tree45 = (TTree*)file45->Get("tree");
TTree *Tree46 = (TTree*)file46->Get("tree");
TTree *Tree47 = (TTree*)file47->Get("tree");
TTree *Tree48 = (TTree*)file48->Get("tree");

/*TFile *file01_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/data.root");
TFile *file02_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/Tprime_0700.root");
TFile *file03_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/Tprime_0800.root");
TFile *file04_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/Tprime_0900.root");
TFile *file05_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/Tprime_1000.root");
TFile *file06_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/Tprime_1100.root");
TFile *file07_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/Tprime_1200.root");
TFile *file08_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/Tprime_1300.root");
TFile *file09_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/Tprime_1400.root");
TFile *file10_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/Tprime_1500.root");
TFile *file11_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/Tprime_1600.root");
TFile *file12_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/Tprime_1700.root");
TFile *file13_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/Tprime_1800.root");
TFile *file14_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/ZToNuNu_HT100to200.root");
TFile *file15_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/ZToNuNu_HT200to400.root");
TFile *file16_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/ZToNuNu_HT400to600.root");
TFile *file17_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/ZToNuNu_HT600to800.root");
TFile *file18_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/ZToNuNu_HT800to1200.root");
TFile *file19_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/ZToNuNu_HT1200to2500.root");
TFile *file20_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/ZToNuNu_HT2500toInf.root");
TFile *file21_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/QCD_HT200to300.root");
TFile *file22_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/QCD_HT300to500.root");
TFile *file23_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/QCD_HT500to700.root");
TFile *file24_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/QCD_HT700to1000.root");
TFile *file25_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/QCD_HT1000to1500.root");
TFile *file26_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/QCD_HT1500to2000.root");
TFile *file27_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/QCD_HT2000toInf.root");
TFile *file28_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/WToLNu_HT100to200.root");
TFile *file29_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/WToLNu_HT200to400.root");
TFile *file30_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/WToLNu_HT400to600.root");
TFile *file31_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/WToLNu_HT600to800.root");
TFile *file32_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/WToLNu_HT800to1200.root");
TFile *file33_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/WToLNu_HT1200to2500.root");
TFile *file34_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/WToLNu_HT2500toInf.root");
TFile *file35_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/TTTo2L2Nu.root  ");
TFile *file36_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/TTToSemiLeptonic.root");
TFile *file37_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/ST_t-channel_antitop.root");
TFile *file38_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/ST_t-channel_top.root");
TFile *file39_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/ST_tW_antitop.root");
TFile *file40_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/ST_tW_top.root");
TFile *file41_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/ZZTo4L.root");
TFile *file42_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/ZZTo2L2Q.root");
TFile *file43_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/ZZTo2L2Nu.root");
TFile *file44_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/WWTo2L2Nu.root");
TFile *file45_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/WWToLNuQQ.root");
TFile *file46_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/WZTo1L1Nu2Q.root ");
TFile *file47_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/WZTo2L2Q.root");
TFile *file48_J1 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESdo/WZTo3LNu.root");
TTree *Tree01_J1 = (TTree*)file01_J1->Get("tree");
TTree *Tree02_J1 = (TTree*)file02_J1->Get("tree");
TTree *Tree03_J1 = (TTree*)file03_J1->Get("tree");
TTree *Tree04_J1 = (TTree*)file04_J1->Get("tree");
TTree *Tree05_J1 = (TTree*)file05_J1->Get("tree");
TTree *Tree06_J1 = (TTree*)file06_J1->Get("tree");
TTree *Tree07_J1 = (TTree*)file07_J1->Get("tree");
TTree *Tree08_J1 = (TTree*)file08_J1->Get("tree");
TTree *Tree09_J1 = (TTree*)file09_J1->Get("tree");
TTree *Tree10_J1 = (TTree*)file10_J1->Get("tree");
TTree *Tree11_J1 = (TTree*)file11_J1->Get("tree");
TTree *Tree12_J1 = (TTree*)file12_J1->Get("tree");
TTree *Tree13_J1 = (TTree*)file13_J1->Get("tree");
TTree *Tree14_J1 = (TTree*)file14_J1->Get("tree");
TTree *Tree15_J1 = (TTree*)file15_J1->Get("tree");
TTree *Tree16_J1 = (TTree*)file16_J1->Get("tree");
TTree *Tree17_J1 = (TTree*)file17_J1->Get("tree");
TTree *Tree18_J1 = (TTree*)file18_J1->Get("tree");
TTree *Tree19_J1 = (TTree*)file19_J1->Get("tree");
TTree *Tree20_J1 = (TTree*)file20_J1->Get("tree");
TTree *Tree21_J1 = (TTree*)file21_J1->Get("tree");
TTree *Tree22_J1 = (TTree*)file22_J1->Get("tree");
TTree *Tree23_J1 = (TTree*)file23_J1->Get("tree");
TTree *Tree24_J1 = (TTree*)file24_J1->Get("tree");
TTree *Tree25_J1 = (TTree*)file25_J1->Get("tree");
TTree *Tree26_J1 = (TTree*)file26_J1->Get("tree");
TTree *Tree27_J1 = (TTree*)file27_J1->Get("tree");
TTree *Tree28_J1 = (TTree*)file28_J1->Get("tree");
TTree *Tree29_J1 = (TTree*)file29_J1->Get("tree");
TTree *Tree30_J1 = (TTree*)file30_J1->Get("tree");
TTree *Tree31_J1 = (TTree*)file31_J1->Get("tree");
TTree *Tree32_J1 = (TTree*)file32_J1->Get("tree");
TTree *Tree33_J1 = (TTree*)file33_J1->Get("tree");
TTree *Tree34_J1 = (TTree*)file34_J1->Get("tree");
TTree *Tree35_J1 = (TTree*)file35_J1->Get("tree");
TTree *Tree36_J1 = (TTree*)file36_J1->Get("tree");
TTree *Tree37_J1 = (TTree*)file37_J1->Get("tree");
TTree *Tree38_J1 = (TTree*)file38_J1->Get("tree");
TTree *Tree39_J1 = (TTree*)file39_J1->Get("tree");
TTree *Tree40_J1 = (TTree*)file40_J1->Get("tree");
TTree *Tree41_J1 = (TTree*)file41_J1->Get("tree");
TTree *Tree42_J1 = (TTree*)file42_J1->Get("tree");
TTree *Tree43_J1 = (TTree*)file43_J1->Get("tree");
TTree *Tree44_J1 = (TTree*)file44_J1->Get("tree");
TTree *Tree45_J1 = (TTree*)file45_J1->Get("tree");
TTree *Tree46_J1 = (TTree*)file46_J1->Get("tree");
TTree *Tree47_J1 = (TTree*)file47_J1->Get("tree");
TTree *Tree48_J1 = (TTree*)file48_J1->Get("tree");

TFile *file01_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/data.root");
TFile *file02_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/Tprime_0700.root");
TFile *file03_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/Tprime_0800.root");
TFile *file04_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/Tprime_0900.root");
TFile *file05_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/Tprime_1000.root");
TFile *file06_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/Tprime_1100.root");
TFile *file07_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/Tprime_1200.root");
TFile *file08_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/Tprime_1300.root");
TFile *file09_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/Tprime_1400.root");
TFile *file10_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/Tprime_1500.root");
TFile *file11_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/Tprime_1600.root");
TFile *file12_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/Tprime_1700.root");
TFile *file13_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/Tprime_1800.root");
TFile *file14_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/ZToNuNu_HT100to200.root");
TFile *file15_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/ZToNuNu_HT200to400.root");
TFile *file16_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/ZToNuNu_HT400to600.root");
TFile *file17_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/ZToNuNu_HT600to800.root");
TFile *file18_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/ZToNuNu_HT800to1200.root");
TFile *file19_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/ZToNuNu_HT1200to2500.root");
TFile *file20_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/ZToNuNu_HT2500toInf.root");
TFile *file21_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/QCD_HT200to300.root");
TFile *file22_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/QCD_HT300to500.root");
TFile *file23_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/QCD_HT500to700.root");
TFile *file24_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/QCD_HT700to1000.root");
TFile *file25_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/QCD_HT1000to1500.root");
TFile *file26_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/QCD_HT1500to2000.root");
TFile *file27_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/QCD_HT2000toInf.root");
TFile *file28_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/WToLNu_HT100to200.root");
TFile *file29_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/WToLNu_HT200to400.root");
TFile *file30_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/WToLNu_HT400to600.root");
TFile *file31_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/WToLNu_HT600to800.root");
TFile *file32_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/WToLNu_HT800to1200.root");
TFile *file33_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/WToLNu_HT1200to2500.root");
TFile *file34_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/WToLNu_HT2500toInf.root");
TFile *file35_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/TTTo2L2Nu.root  ");
TFile *file36_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/TTToSemiLeptonic.root");
TFile *file37_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/ST_t-channel_antitop.root");
TFile *file38_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/ST_t-channel_top.root");
TFile *file39_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/ST_tW_antitop.root");
TFile *file40_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/ST_tW_top.root");
TFile *file41_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/ZZTo4L.root");
TFile *file42_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/ZZTo2L2Q.root");
TFile *file43_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/ZZTo2L2Nu.root");
TFile *file44_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/WWTo2L2Nu.root");
TFile *file45_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/WWToLNuQQ.root");
TFile *file46_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/WZTo1L1Nu2Q.root ");
TFile *file47_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/WZTo2L2Q.root");
TFile *file48_J2 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JESup/WZTo3LNu.root");
TTree *Tree01_J2 = (TTree*)file01_J2->Get("tree");
TTree *Tree02_J2 = (TTree*)file02_J2->Get("tree");
TTree *Tree03_J2 = (TTree*)file03_J2->Get("tree");
TTree *Tree04_J2 = (TTree*)file04_J2->Get("tree");
TTree *Tree05_J2 = (TTree*)file05_J2->Get("tree");
TTree *Tree06_J2 = (TTree*)file06_J2->Get("tree");
TTree *Tree07_J2 = (TTree*)file07_J2->Get("tree");
TTree *Tree08_J2 = (TTree*)file08_J2->Get("tree");
TTree *Tree09_J2 = (TTree*)file09_J2->Get("tree");
TTree *Tree10_J2 = (TTree*)file10_J2->Get("tree");
TTree *Tree11_J2 = (TTree*)file11_J2->Get("tree");
TTree *Tree12_J2 = (TTree*)file12_J2->Get("tree");
TTree *Tree13_J2 = (TTree*)file13_J2->Get("tree");
TTree *Tree14_J2 = (TTree*)file14_J2->Get("tree");
TTree *Tree15_J2 = (TTree*)file15_J2->Get("tree");
TTree *Tree16_J2 = (TTree*)file16_J2->Get("tree");
TTree *Tree17_J2 = (TTree*)file17_J2->Get("tree");
TTree *Tree18_J2 = (TTree*)file18_J2->Get("tree");
TTree *Tree19_J2 = (TTree*)file19_J2->Get("tree");
TTree *Tree20_J2 = (TTree*)file20_J2->Get("tree");
TTree *Tree21_J2 = (TTree*)file21_J2->Get("tree");
TTree *Tree22_J2 = (TTree*)file22_J2->Get("tree");
TTree *Tree23_J2 = (TTree*)file23_J2->Get("tree");
TTree *Tree24_J2 = (TTree*)file24_J2->Get("tree");
TTree *Tree25_J2 = (TTree*)file25_J2->Get("tree");
TTree *Tree26_J2 = (TTree*)file26_J2->Get("tree");
TTree *Tree27_J2 = (TTree*)file27_J2->Get("tree");
TTree *Tree28_J2 = (TTree*)file28_J2->Get("tree");
TTree *Tree29_J2 = (TTree*)file29_J2->Get("tree");
TTree *Tree30_J2 = (TTree*)file30_J2->Get("tree");
TTree *Tree31_J2 = (TTree*)file31_J2->Get("tree");
TTree *Tree32_J2 = (TTree*)file32_J2->Get("tree");
TTree *Tree33_J2 = (TTree*)file33_J2->Get("tree");
TTree *Tree34_J2 = (TTree*)file34_J2->Get("tree");
TTree *Tree35_J2 = (TTree*)file35_J2->Get("tree");
TTree *Tree36_J2 = (TTree*)file36_J2->Get("tree");
TTree *Tree37_J2 = (TTree*)file37_J2->Get("tree");
TTree *Tree38_J2 = (TTree*)file38_J2->Get("tree");
TTree *Tree39_J2 = (TTree*)file39_J2->Get("tree");
TTree *Tree40_J2 = (TTree*)file40_J2->Get("tree");
TTree *Tree41_J2 = (TTree*)file41_J2->Get("tree");
TTree *Tree42_J2 = (TTree*)file42_J2->Get("tree");
TTree *Tree43_J2 = (TTree*)file43_J2->Get("tree");
TTree *Tree44_J2 = (TTree*)file44_J2->Get("tree");
TTree *Tree45_J2 = (TTree*)file45_J2->Get("tree");
TTree *Tree46_J2 = (TTree*)file46_J2->Get("tree");
TTree *Tree47_J2 = (TTree*)file47_J2->Get("tree");
TTree *Tree48_J2 = (TTree*)file48_J2->Get("tree");

TFile *file01_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/data.root");
TFile *file02_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/Tprime_0700.root");
TFile *file03_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/Tprime_0800.root");
TFile *file04_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/Tprime_0900.root");
TFile *file05_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/Tprime_1000.root");
TFile *file06_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/Tprime_1100.root");
TFile *file07_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/Tprime_1200.root");
TFile *file08_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/Tprime_1300.root");
TFile *file09_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/Tprime_1400.root");
TFile *file10_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/Tprime_1500.root");
TFile *file11_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/Tprime_1600.root");
TFile *file12_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/Tprime_1700.root");
TFile *file13_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/Tprime_1800.root");
TFile *file14_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/ZToNuNu_HT100to200.root");
TFile *file15_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/ZToNuNu_HT200to400.root");
TFile *file16_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/ZToNuNu_HT400to600.root");
TFile *file17_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/ZToNuNu_HT600to800.root");
TFile *file18_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/ZToNuNu_HT800to1200.root");
TFile *file19_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/ZToNuNu_HT1200to2500.root");
TFile *file20_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/ZToNuNu_HT2500toInf.root");
TFile *file21_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/QCD_HT200to300.root");
TFile *file22_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/QCD_HT300to500.root");
TFile *file23_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/QCD_HT500to700.root");
TFile *file24_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/QCD_HT700to1000.root");
TFile *file25_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/QCD_HT1000to1500.root");
TFile *file26_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/QCD_HT1500to2000.root");
TFile *file27_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/QCD_HT2000toInf.root");
TFile *file28_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/WToLNu_HT100to200.root");
TFile *file29_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/WToLNu_HT200to400.root");
TFile *file30_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/WToLNu_HT400to600.root");
TFile *file31_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/WToLNu_HT600to800.root");
TFile *file32_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/WToLNu_HT800to1200.root");
TFile *file33_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/WToLNu_HT1200to2500.root");
TFile *file34_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/WToLNu_HT2500toInf.root");
TFile *file35_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/TTTo2L2Nu.root  ");
TFile *file36_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/TTToSemiLeptonic.root");
TFile *file37_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/ST_t-channel_antitop.root");
TFile *file38_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/ST_t-channel_top.root");
TFile *file39_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/ST_tW_antitop.root");
TFile *file40_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/ST_tW_top.root");
TFile *file41_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/ZZTo4L.root");
TFile *file42_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/ZZTo2L2Q.root");
TFile *file43_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/ZZTo2L2Nu.root");
TFile *file44_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/WWTo2L2Nu.root");
TFile *file45_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/WWToLNuQQ.root");
TFile *file46_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/WZTo1L1Nu2Q.root ");
TFile *file47_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/WZTo2L2Q.root");
TFile *file48_J3 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERdo/WZTo3LNu.root");
TTree *Tree01_J3 = (TTree*)file01_J3->Get("tree");
TTree *Tree02_J3 = (TTree*)file02_J3->Get("tree");
TTree *Tree03_J3 = (TTree*)file03_J3->Get("tree");
TTree *Tree04_J3 = (TTree*)file04_J3->Get("tree");
TTree *Tree05_J3 = (TTree*)file05_J3->Get("tree");
TTree *Tree06_J3 = (TTree*)file06_J3->Get("tree");
TTree *Tree07_J3 = (TTree*)file07_J3->Get("tree");
TTree *Tree08_J3 = (TTree*)file08_J3->Get("tree");
TTree *Tree09_J3 = (TTree*)file09_J3->Get("tree");
TTree *Tree10_J3 = (TTree*)file10_J3->Get("tree");
TTree *Tree11_J3 = (TTree*)file11_J3->Get("tree");
TTree *Tree12_J3 = (TTree*)file12_J3->Get("tree");
TTree *Tree13_J3 = (TTree*)file13_J3->Get("tree");
TTree *Tree14_J3 = (TTree*)file14_J3->Get("tree");
TTree *Tree15_J3 = (TTree*)file15_J3->Get("tree");
TTree *Tree16_J3 = (TTree*)file16_J3->Get("tree");
TTree *Tree17_J3 = (TTree*)file17_J3->Get("tree");
TTree *Tree18_J3 = (TTree*)file18_J3->Get("tree");
TTree *Tree19_J3 = (TTree*)file19_J3->Get("tree");
TTree *Tree20_J3 = (TTree*)file20_J3->Get("tree");
TTree *Tree21_J3 = (TTree*)file21_J3->Get("tree");
TTree *Tree22_J3 = (TTree*)file22_J3->Get("tree");
TTree *Tree23_J3 = (TTree*)file23_J3->Get("tree");
TTree *Tree24_J3 = (TTree*)file24_J3->Get("tree");
TTree *Tree25_J3 = (TTree*)file25_J3->Get("tree");
TTree *Tree26_J3 = (TTree*)file26_J3->Get("tree");
TTree *Tree27_J3 = (TTree*)file27_J3->Get("tree");
TTree *Tree28_J3 = (TTree*)file28_J3->Get("tree");
TTree *Tree29_J3 = (TTree*)file29_J3->Get("tree");
TTree *Tree30_J3 = (TTree*)file30_J3->Get("tree");
TTree *Tree31_J3 = (TTree*)file31_J3->Get("tree");
TTree *Tree32_J3 = (TTree*)file32_J3->Get("tree");
TTree *Tree33_J3 = (TTree*)file33_J3->Get("tree");
TTree *Tree34_J3 = (TTree*)file34_J3->Get("tree");
TTree *Tree35_J3 = (TTree*)file35_J3->Get("tree");
TTree *Tree36_J3 = (TTree*)file36_J3->Get("tree");
TTree *Tree37_J3 = (TTree*)file37_J3->Get("tree");
TTree *Tree38_J3 = (TTree*)file38_J3->Get("tree");
TTree *Tree39_J3 = (TTree*)file39_J3->Get("tree");
TTree *Tree40_J3 = (TTree*)file40_J3->Get("tree");
TTree *Tree41_J3 = (TTree*)file41_J3->Get("tree");
TTree *Tree42_J3 = (TTree*)file42_J3->Get("tree");
TTree *Tree43_J3 = (TTree*)file43_J3->Get("tree");
TTree *Tree44_J3 = (TTree*)file44_J3->Get("tree");
TTree *Tree45_J3 = (TTree*)file45_J3->Get("tree");
TTree *Tree46_J3 = (TTree*)file46_J3->Get("tree");
TTree *Tree47_J3 = (TTree*)file47_J3->Get("tree");
TTree *Tree48_J3 = (TTree*)file48_J3->Get("tree");

TFile *file01_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/data.root");
TFile *file02_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/Tprime_0700.root");
TFile *file03_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/Tprime_0800.root");
TFile *file04_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/Tprime_0900.root");
TFile *file05_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/Tprime_1000.root");
TFile *file06_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/Tprime_1100.root");
TFile *file07_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/Tprime_1200.root");
TFile *file08_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/Tprime_1300.root");
TFile *file09_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/Tprime_1400.root");
TFile *file10_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/Tprime_1500.root");
TFile *file11_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/Tprime_1600.root");
TFile *file12_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/Tprime_1700.root");
TFile *file13_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/Tprime_1800.root");
TFile *file14_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/ZToNuNu_HT100to200.root");
TFile *file15_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/ZToNuNu_HT200to400.root");
TFile *file16_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/ZToNuNu_HT400to600.root");
TFile *file17_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/ZToNuNu_HT600to800.root");
TFile *file18_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/ZToNuNu_HT800to1200.root");
TFile *file19_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/ZToNuNu_HT1200to2500.root");
TFile *file20_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/ZToNuNu_HT2500toInf.root");
TFile *file21_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/QCD_HT200to300.root");
TFile *file22_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/QCD_HT300to500.root");
TFile *file23_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/QCD_HT500to700.root");
TFile *file24_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/QCD_HT700to1000.root");
TFile *file25_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/QCD_HT1000to1500.root");
TFile *file26_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/QCD_HT1500to2000.root");
TFile *file27_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/QCD_HT2000toInf.root");
TFile *file28_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/WToLNu_HT100to200.root");
TFile *file29_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/WToLNu_HT200to400.root");
TFile *file30_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/WToLNu_HT400to600.root");
TFile *file31_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/WToLNu_HT600to800.root");
TFile *file32_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/WToLNu_HT800to1200.root");
TFile *file33_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/WToLNu_HT1200to2500.root");
TFile *file34_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/WToLNu_HT2500toInf.root");
TFile *file35_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/TTTo2L2Nu.root  ");
TFile *file36_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/TTToSemiLeptonic.root");
TFile *file37_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/ST_t-channel_antitop.root");
TFile *file38_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/ST_t-channel_top.root");
TFile *file39_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/ST_tW_antitop.root");
TFile *file40_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/ST_tW_top.root");
TFile *file41_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/ZZTo4L.root");
TFile *file42_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/ZZTo2L2Q.root");
TFile *file43_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/ZZTo2L2Nu.root");
TFile *file44_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/WWTo2L2Nu.root");
TFile *file45_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/WWToLNuQQ.root");
TFile *file46_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/WZTo1L1Nu2Q.root ");
TFile *file47_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/WZTo2L2Q.root");
TFile *file48_J4 = TFile::Open("/publicfs/cms/user/yutz/Tprime/2017_dineutrino/Preselection_v16/JERup/WZTo3LNu.root");
TTree *Tree01_J4 = (TTree*)file01_J4->Get("tree");
TTree *Tree02_J4 = (TTree*)file02_J4->Get("tree");
TTree *Tree03_J4 = (TTree*)file03_J4->Get("tree");
TTree *Tree04_J4 = (TTree*)file04_J4->Get("tree");
TTree *Tree05_J4 = (TTree*)file05_J4->Get("tree");
TTree *Tree06_J4 = (TTree*)file06_J4->Get("tree");
TTree *Tree07_J4 = (TTree*)file07_J4->Get("tree");
TTree *Tree08_J4 = (TTree*)file08_J4->Get("tree");
TTree *Tree09_J4 = (TTree*)file09_J4->Get("tree");
TTree *Tree10_J4 = (TTree*)file10_J4->Get("tree");
TTree *Tree11_J4 = (TTree*)file11_J4->Get("tree");
TTree *Tree12_J4 = (TTree*)file12_J4->Get("tree");
TTree *Tree13_J4 = (TTree*)file13_J4->Get("tree");
TTree *Tree14_J4 = (TTree*)file14_J4->Get("tree");
TTree *Tree15_J4 = (TTree*)file15_J4->Get("tree");
TTree *Tree16_J4 = (TTree*)file16_J4->Get("tree");
TTree *Tree17_J4 = (TTree*)file17_J4->Get("tree");
TTree *Tree18_J4 = (TTree*)file18_J4->Get("tree");
TTree *Tree19_J4 = (TTree*)file19_J4->Get("tree");
TTree *Tree20_J4 = (TTree*)file20_J4->Get("tree");
TTree *Tree21_J4 = (TTree*)file21_J4->Get("tree");
TTree *Tree22_J4 = (TTree*)file22_J4->Get("tree");
TTree *Tree23_J4 = (TTree*)file23_J4->Get("tree");
TTree *Tree24_J4 = (TTree*)file24_J4->Get("tree");
TTree *Tree25_J4 = (TTree*)file25_J4->Get("tree");
TTree *Tree26_J4 = (TTree*)file26_J4->Get("tree");
TTree *Tree27_J4 = (TTree*)file27_J4->Get("tree");
TTree *Tree28_J4 = (TTree*)file28_J4->Get("tree");
TTree *Tree29_J4 = (TTree*)file29_J4->Get("tree");
TTree *Tree30_J4 = (TTree*)file30_J4->Get("tree");
TTree *Tree31_J4 = (TTree*)file31_J4->Get("tree");
TTree *Tree32_J4 = (TTree*)file32_J4->Get("tree");
TTree *Tree33_J4 = (TTree*)file33_J4->Get("tree");
TTree *Tree34_J4 = (TTree*)file34_J4->Get("tree");
TTree *Tree35_J4 = (TTree*)file35_J4->Get("tree");
TTree *Tree36_J4 = (TTree*)file36_J4->Get("tree");
TTree *Tree37_J4 = (TTree*)file37_J4->Get("tree");
TTree *Tree38_J4 = (TTree*)file38_J4->Get("tree");
TTree *Tree39_J4 = (TTree*)file39_J4->Get("tree");
TTree *Tree40_J4 = (TTree*)file40_J4->Get("tree");
TTree *Tree41_J4 = (TTree*)file41_J4->Get("tree");
TTree *Tree42_J4 = (TTree*)file42_J4->Get("tree");
TTree *Tree43_J4 = (TTree*)file43_J4->Get("tree");
TTree *Tree44_J4 = (TTree*)file44_J4->Get("tree");
TTree *Tree45_J4 = (TTree*)file45_J4->Get("tree");
TTree *Tree46_J4 = (TTree*)file46_J4->Get("tree");
TTree *Tree47_J4 = (TTree*)file47_J4->Get("tree");
TTree *Tree48_J4 = (TTree*)file48_J4->Get("tree");*/


TH1F *data_SR; TH1F *tptzm0700lh_SR; TH1F *tptzm0900lh_SR; TH1F *tptzm1400lh_SR; TH1F *tptzm1700lh_SR; 
TH1F *ZToNuNu_1_SR; TH1F *ZToNuNu_2_SR; TH1F *ZToNuNu_3_SR; TH1F *ZToNuNu_4_SR; TH1F *ZToNuNu_5_SR; TH1F *ZToNuNu_6_SR; TH1F *ZToNuNu_7_SR; 
TH1F *QCD_1_SR; TH1F *QCD_2_SR; TH1F *QCD_3_SR; TH1F *QCD_4_SR; TH1F *QCD_5_SR; TH1F *QCD_6_SR; TH1F *QCD_7_SR; 
TH1F *WToLNu_1_SR; TH1F *WToLNu_2_SR; TH1F *WToLNu_3_SR; TH1F *WToLNu_4_SR; TH1F *WToLNu_5_SR; TH1F *WToLNu_6_SR; TH1F *WToLNu_7_SR; 
TH1F *TT_1_SR; TH1F *TT_2_SR; TH1F *ST_1_SR; TH1F *ST_2_SR; TH1F *ST_3_SR; TH1F *ST_4_SR; 
TH1F *ZZ1_SR; TH1F *ZZ2_SR; TH1F *ZZ3_SR; TH1F *WW1_SR; TH1F *WW2_SR; TH1F *WZ1_SR; TH1F *WZ2_SR; TH1F *WZ3_SR; TH1F *WToLNu_SR; TH1F *background_SR;

TH1F *data_P1; TH1F *tptzm0700lh_P1; TH1F *tptzm0900lh_P1; TH1F *tptzm1400lh_P1; TH1F *tptzm1700lh_P1; 
TH1F *ZToNuNu_1_P1; TH1F *ZToNuNu_2_P1; TH1F *ZToNuNu_3_P1; TH1F *ZToNuNu_4_P1; TH1F *ZToNuNu_5_P1; TH1F *ZToNuNu_6_P1; TH1F *ZToNuNu_7_P1; 
TH1F *QCD_1_P1; TH1F *QCD_2_P1; TH1F *QCD_3_P1; TH1F *QCD_4_P1; TH1F *QCD_5_P1; TH1F *QCD_6_P1; TH1F *QCD_7_P1; 
TH1F *WToLNu_1_P1; TH1F *WToLNu_2_P1; TH1F *WToLNu_3_P1; TH1F *WToLNu_4_P1; TH1F *WToLNu_5_P1; TH1F *WToLNu_6_P1; TH1F *WToLNu_7_P1; 
TH1F *TT_1_P1; TH1F *TT_2_P1; TH1F *ST_1_P1; TH1F *ST_2_P1; TH1F *ST_3_P1; TH1F *ST_4_P1; 
TH1F *ZZ1_P1; TH1F *ZZ2_P1; TH1F *ZZ3_P1; TH1F *WW1_P1; TH1F *WW2_P1; TH1F *WZ1_P1; TH1F *WZ2_P1; TH1F *WZ3_P1; TH1F *WToLNu_P1; TH1F *background_P1;

TH1F *data_P2; TH1F *tptzm0700lh_P2; TH1F *tptzm0900lh_P2; TH1F *tptzm1400lh_P2; TH1F *tptzm1700lh_P2; 
TH1F *ZToNuNu_1_P2; TH1F *ZToNuNu_2_P2; TH1F *ZToNuNu_3_P2; TH1F *ZToNuNu_4_P2; TH1F *ZToNuNu_5_P2; TH1F *ZToNuNu_6_P2; TH1F *ZToNuNu_7_P2; 
TH1F *QCD_1_P2; TH1F *QCD_2_P2; TH1F *QCD_3_P2; TH1F *QCD_4_P2; TH1F *QCD_5_P2; TH1F *QCD_6_P2; TH1F *QCD_7_P2; 
TH1F *WToLNu_1_P2; TH1F *WToLNu_2_P2; TH1F *WToLNu_3_P2; TH1F *WToLNu_4_P2; TH1F *WToLNu_5_P2; TH1F *WToLNu_6_P2; TH1F *WToLNu_7_P2; 
TH1F *TT_1_P2; TH1F *TT_2_P2; TH1F *ST_1_P2; TH1F *ST_2_P2; TH1F *ST_3_P2; TH1F *ST_4_P2; 
TH1F *ZZ1_P2; TH1F *ZZ2_P2; TH1F *ZZ3_P2; TH1F *WW1_P2; TH1F *WW2_P2; TH1F *WZ1_P2; TH1F *WZ2_P2; TH1F *WZ3_P2; TH1F *WToLNu_P2; TH1F *background_P2;

TH1F *data_F1; TH1F *tptzm0700lh_F1; TH1F *tptzm0900lh_F1; TH1F *tptzm1400lh_F1; TH1F *tptzm1700lh_F1; 
TH1F *ZToNuNu_1_F1; TH1F *ZToNuNu_2_F1; TH1F *ZToNuNu_3_F1; TH1F *ZToNuNu_4_F1; TH1F *ZToNuNu_5_F1; TH1F *ZToNuNu_6_F1; TH1F *ZToNuNu_7_F1; 
TH1F *QCD_1_F1; TH1F *QCD_2_F1; TH1F *QCD_3_F1; TH1F *QCD_4_F1; TH1F *QCD_5_F1; TH1F *QCD_6_F1; TH1F *QCD_7_F1; 
TH1F *WToLNu_1_F1; TH1F *WToLNu_2_F1; TH1F *WToLNu_3_F1; TH1F *WToLNu_4_F1; TH1F *WToLNu_5_F1; TH1F *WToLNu_6_F1; TH1F *WToLNu_7_F1; 
TH1F *TT_1_F1; TH1F *TT_2_F1; TH1F *ST_1_F1; TH1F *ST_2_F1; TH1F *ST_3_F1; TH1F *ST_4_F1; 
TH1F *ZZ1_F1; TH1F *ZZ2_F1; TH1F *ZZ3_F1; TH1F *WW1_F1; TH1F *WW2_F1; TH1F *WZ1_F1; TH1F *WZ2_F1; TH1F *WZ3_F1; TH1F *WToLNu_F1; TH1F *background_F1;

TH1F *data_F2; TH1F *tptzm0700lh_F2; TH1F *tptzm0900lh_F2; TH1F *tptzm1400lh_F2; TH1F *tptzm1700lh_F2; 
TH1F *ZToNuNu_1_F2; TH1F *ZToNuNu_2_F2; TH1F *ZToNuNu_3_F2; TH1F *ZToNuNu_4_F2; TH1F *ZToNuNu_5_F2; TH1F *ZToNuNu_6_F2; TH1F *ZToNuNu_7_F2; 
TH1F *QCD_1_F2; TH1F *QCD_2_F2; TH1F *QCD_3_F2; TH1F *QCD_4_F2; TH1F *QCD_5_F2; TH1F *QCD_6_F2; TH1F *QCD_7_F2; 
TH1F *WToLNu_1_F2; TH1F *WToLNu_2_F2; TH1F *WToLNu_3_F2; TH1F *WToLNu_4_F2; TH1F *WToLNu_5_F2; TH1F *WToLNu_6_F2; TH1F *WToLNu_7_F2; 
TH1F *TT_1_F2; TH1F *TT_2_F2; TH1F *ST_1_F2; TH1F *ST_2_F2; TH1F *ST_3_F2; TH1F *ST_4_F2; 
TH1F *ZZ1_F2; TH1F *ZZ2_F2; TH1F *ZZ3_F2; TH1F *WW1_F2; TH1F *WW2_F2; TH1F *WZ1_F2; TH1F *WZ2_F2; TH1F *WZ3_F2; TH1F *WToLNu_F2; TH1F *background_F2;

TH1F *data_B1; TH1F *tptzm0700lh_B1; TH1F *tptzm0900lh_B1; TH1F *tptzm1400lh_B1; TH1F *tptzm1700lh_B1; 
TH1F *ZToNuNu_1_B1; TH1F *ZToNuNu_2_B1; TH1F *ZToNuNu_3_B1; TH1F *ZToNuNu_4_B1; TH1F *ZToNuNu_5_B1; TH1F *ZToNuNu_6_B1; TH1F *ZToNuNu_7_B1; 
TH1F *QCD_1_B1; TH1F *QCD_2_B1; TH1F *QCD_3_B1; TH1F *QCD_4_B1; TH1F *QCD_5_B1; TH1F *QCD_6_B1; TH1F *QCD_7_B1; 
TH1F *WToLNu_1_B1; TH1F *WToLNu_2_B1; TH1F *WToLNu_3_B1; TH1F *WToLNu_4_B1; TH1F *WToLNu_5_B1; TH1F *WToLNu_6_B1; TH1F *WToLNu_7_B1; 
TH1F *TT_1_B1; TH1F *TT_2_B1; TH1F *ST_1_B1; TH1F *ST_2_B1; TH1F *ST_3_B1; TH1F *ST_4_B1; 
TH1F *ZZ1_B1; TH1F *ZZ2_B1; TH1F *ZZ3_B1; TH1F *WW1_B1; TH1F *WW2_B1; TH1F *WZ1_B1; TH1F *WZ2_B1; TH1F *WZ3_B1; TH1F *WToLNu_B1; TH1F *background_B1;

TH1F *data_B2; TH1F *tptzm0700lh_B2; TH1F *tptzm0900lh_B2; TH1F *tptzm1400lh_B2; TH1F *tptzm1700lh_B2; 
TH1F *ZToNuNu_1_B2; TH1F *ZToNuNu_2_B2; TH1F *ZToNuNu_3_B2; TH1F *ZToNuNu_4_B2; TH1F *ZToNuNu_5_B2; TH1F *ZToNuNu_6_B2; TH1F *ZToNuNu_7_B2; 
TH1F *QCD_1_B2; TH1F *QCD_2_B2; TH1F *QCD_3_B2; TH1F *QCD_4_B2; TH1F *QCD_5_B2; TH1F *QCD_6_B2; TH1F *QCD_7_B2; 
TH1F *WToLNu_1_B2; TH1F *WToLNu_2_B2; TH1F *WToLNu_3_B2; TH1F *WToLNu_4_B2; TH1F *WToLNu_5_B2; TH1F *WToLNu_6_B2; TH1F *WToLNu_7_B2; 
TH1F *TT_1_B2; TH1F *TT_2_B2; TH1F *ST_1_B2; TH1F *ST_2_B2; TH1F *ST_3_B2; TH1F *ST_4_B2; 
TH1F *ZZ1_B2; TH1F *ZZ2_B2; TH1F *ZZ3_B2; TH1F *WW1_B2; TH1F *WW2_B2; TH1F *WZ1_B2; TH1F *WZ2_B2; TH1F *WZ3_B2; TH1F *WToLNu_B2; TH1F *background_B2; 

TH1F *data_Z1; TH1F *tptzm0700lh_Z1; TH1F *tptzm0900lh_Z1; TH1F *tptzm1400lh_Z1; TH1F *tptzm1700lh_Z1; 
TH1F *ZToNuNu_1_Z1; TH1F *ZToNuNu_2_Z1; TH1F *ZToNuNu_3_Z1; TH1F *ZToNuNu_4_Z1; TH1F *ZToNuNu_5_Z1; TH1F *ZToNuNu_6_Z1; TH1F *ZToNuNu_7_Z1; 
TH1F *QCD_1_Z1; TH1F *QCD_2_Z1; TH1F *QCD_3_Z1; TH1F *QCD_4_Z1; TH1F *QCD_5_Z1; TH1F *QCD_6_Z1; TH1F *QCD_7_Z1; 
TH1F *WToLNu_1_Z1; TH1F *WToLNu_2_Z1; TH1F *WToLNu_3_Z1; TH1F *WToLNu_4_Z1; TH1F *WToLNu_5_Z1; TH1F *WToLNu_6_Z1; TH1F *WToLNu_7_Z1; 
TH1F *TT_1_Z1; TH1F *TT_2_Z1; TH1F *ST_1_Z1; TH1F *ST_2_Z1; TH1F *ST_3_Z1; TH1F *ST_4_Z1; 
TH1F *ZZ1_Z1; TH1F *ZZ2_Z1; TH1F *ZZ3_Z1; TH1F *WW1_Z1; TH1F *WW2_Z1; TH1F *WZ1_Z1; TH1F *WZ2_Z1; TH1F *WZ3_Z1; TH1F *WToLNu_Z1; TH1F *background_Z1;

TH1F *data_Z2; TH1F *tptzm0700lh_Z2; TH1F *tptzm0900lh_Z2; TH1F *tptzm1400lh_Z2; TH1F *tptzm1700lh_Z2; 
TH1F *ZToNuNu_1_Z2; TH1F *ZToNuNu_2_Z2; TH1F *ZToNuNu_3_Z2; TH1F *ZToNuNu_4_Z2; TH1F *ZToNuNu_5_Z2; TH1F *ZToNuNu_6_Z2; TH1F *ZToNuNu_7_Z2; 
TH1F *QCD_1_Z2; TH1F *QCD_2_Z2; TH1F *QCD_3_Z2; TH1F *QCD_4_Z2; TH1F *QCD_5_Z2; TH1F *QCD_6_Z2; TH1F *QCD_7_Z2; 
TH1F *WToLNu_1_Z2; TH1F *WToLNu_2_Z2; TH1F *WToLNu_3_Z2; TH1F *WToLNu_4_Z2; TH1F *WToLNu_5_Z2; TH1F *WToLNu_6_Z2; TH1F *WToLNu_7_Z2; 
TH1F *TT_1_Z2; TH1F *TT_2_Z2; TH1F *ST_1_Z2; TH1F *ST_2_Z2; TH1F *ST_3_Z2; TH1F *ST_4_Z2; 
TH1F *ZZ1_Z2; TH1F *ZZ2_Z2; TH1F *ZZ3_Z2; TH1F *WW1_Z2; TH1F *WW2_Z2; TH1F *WZ1_Z2; TH1F *WZ2_Z2; TH1F *WZ3_Z2; TH1F *WToLNu_Z2; TH1F *background_Z2;

TH1F *data_W1; TH1F *tptzm0700lh_W1; TH1F *tptzm0900lh_W1; TH1F *tptzm1400lh_W1; TH1F *tptzm1700lh_W1; 
TH1F *ZToNuNu_1_W1; TH1F *ZToNuNu_2_W1; TH1F *ZToNuNu_3_W1; TH1F *ZToNuNu_4_W1; TH1F *ZToNuNu_5_W1; TH1F *ZToNuNu_6_W1; TH1F *ZToNuNu_7_W1; 
TH1F *QCD_1_W1; TH1F *QCD_2_W1; TH1F *QCD_3_W1; TH1F *QCD_4_W1; TH1F *QCD_5_W1; TH1F *QCD_6_W1; TH1F *QCD_7_W1; 
TH1F *WToLNu_1_W1; TH1F *WToLNu_2_W1; TH1F *WToLNu_3_W1; TH1F *WToLNu_4_W1; TH1F *WToLNu_5_W1; TH1F *WToLNu_6_W1; TH1F *WToLNu_7_W1; 
TH1F *TT_1_W1; TH1F *TT_2_W1; TH1F *ST_1_W1; TH1F *ST_2_W1; TH1F *ST_3_W1; TH1F *ST_4_W1; 
TH1F *ZZ1_W1; TH1F *ZZ2_W1; TH1F *ZZ3_W1; TH1F *WW1_W1; TH1F *WW2_W1; TH1F *WZ1_W1; TH1F *WZ2_W1; TH1F *WZ3_W1; TH1F *WToLNu_W1; TH1F *background_W1;

TH1F *data_W2; TH1F *tptzm0700lh_W2; TH1F *tptzm0900lh_W2; TH1F *tptzm1400lh_W2; TH1F *tptzm1700lh_W2; 
TH1F *ZToNuNu_1_W2; TH1F *ZToNuNu_2_W2; TH1F *ZToNuNu_3_W2; TH1F *ZToNuNu_4_W2; TH1F *ZToNuNu_5_W2; TH1F *ZToNuNu_6_W2; TH1F *ZToNuNu_7_W2; 
TH1F *QCD_1_W2; TH1F *QCD_2_W2; TH1F *QCD_3_W2; TH1F *QCD_4_W2; TH1F *QCD_5_W2; TH1F *QCD_6_W2; TH1F *QCD_7_W2; 
TH1F *WToLNu_1_W2; TH1F *WToLNu_2_W2; TH1F *WToLNu_3_W2; TH1F *WToLNu_4_W2; TH1F *WToLNu_5_W2; TH1F *WToLNu_6_W2; TH1F *WToLNu_7_W2; 
TH1F *TT_1_W2; TH1F *TT_2_W2; TH1F *ST_1_W2; TH1F *ST_2_W2; TH1F *ST_3_W2; TH1F *ST_4_W2; 
TH1F *ZZ1_W2; TH1F *ZZ2_W2; TH1F *ZZ3_W2; TH1F *WW1_W2; TH1F *WW2_W2; TH1F *WZ1_W2; TH1F *WZ2_W2; TH1F *WZ3_W2; TH1F *WToLNu_W2; TH1F *background_W2;

TH1F *data_T1; TH1F *tptzm0700lh_T1; TH1F *tptzm0900lh_T1; TH1F *tptzm1400lh_T1; TH1F *tptzm1700lh_T1; 
TH1F *ZToNuNu_1_T1; TH1F *ZToNuNu_2_T1; TH1F *ZToNuNu_3_T1; TH1F *ZToNuNu_4_T1; TH1F *ZToNuNu_5_T1; TH1F *ZToNuNu_6_T1; TH1F *ZToNuNu_7_T1; 
TH1F *QCD_1_T1; TH1F *QCD_2_T1; TH1F *QCD_3_T1; TH1F *QCD_4_T1; TH1F *QCD_5_T1; TH1F *QCD_6_T1; TH1F *QCD_7_T1; 
TH1F *WToLNu_1_T1; TH1F *WToLNu_2_T1; TH1F *WToLNu_3_T1; TH1F *WToLNu_4_T1; TH1F *WToLNu_5_T1; TH1F *WToLNu_6_T1; TH1F *WToLNu_7_T1; 
TH1F *TT_1_T1; TH1F *TT_2_T1; TH1F *ST_1_T1; TH1F *ST_2_T1; TH1F *ST_3_T1; TH1F *ST_4_T1; 
TH1F *ZZ1_T1; TH1F *ZZ2_T1; TH1F *ZZ3_T1; TH1F *WW1_T1; TH1F *WW2_T1; TH1F *WZ1_T1; TH1F *WZ2_T1; TH1F *WZ3_T1; TH1F *WToLNu_T1; TH1F *background_T1;

TH1F *data_T2; TH1F *tptzm0700lh_T2; TH1F *tptzm0900lh_T2; TH1F *tptzm1400lh_T2; TH1F *tptzm1700lh_T2; 
TH1F *ZToNuNu_1_T2; TH1F *ZToNuNu_2_T2; TH1F *ZToNuNu_3_T2; TH1F *ZToNuNu_4_T2; TH1F *ZToNuNu_5_T2; TH1F *ZToNuNu_6_T2; TH1F *ZToNuNu_7_T2; 
TH1F *QCD_1_T2; TH1F *QCD_2_T2; TH1F *QCD_3_T2; TH1F *QCD_4_T2; TH1F *QCD_5_T2; TH1F *QCD_6_T2; TH1F *QCD_7_T2; 
TH1F *WToLNu_1_T2; TH1F *WToLNu_2_T2; TH1F *WToLNu_3_T2; TH1F *WToLNu_4_T2; TH1F *WToLNu_5_T2; TH1F *WToLNu_6_T2; TH1F *WToLNu_7_T2; 
TH1F *TT_1_T2; TH1F *TT_2_T2; TH1F *ST_1_T2; TH1F *ST_2_T2; TH1F *ST_3_T2; TH1F *ST_4_T2; 
TH1F *ZZ1_T2; TH1F *ZZ2_T2; TH1F *ZZ3_T2; TH1F *WW1_T2; TH1F *WW2_T2; TH1F *WZ1_T2; TH1F *WZ2_T2; TH1F *WZ3_T2; TH1F *WToLNu_T2; TH1F *background_T2;

TH1F *data_J1; TH1F *tptzm0700lh_J1; TH1F *tptzm0900lh_J1; TH1F *tptzm1400lh_J1; TH1F *tptzm1700lh_J1; 
TH1F *ZToNuNu_1_J1; TH1F *ZToNuNu_2_J1; TH1F *ZToNuNu_3_J1; TH1F *ZToNuNu_4_J1; TH1F *ZToNuNu_5_J1; TH1F *ZToNuNu_6_J1; TH1F *ZToNuNu_7_J1; 
TH1F *QCD_1_J1; TH1F *QCD_2_J1; TH1F *QCD_3_J1; TH1F *QCD_4_J1; TH1F *QCD_5_J1; TH1F *QCD_6_J1; TH1F *QCD_7_J1; 
TH1F *WToLNu_1_J1; TH1F *WToLNu_2_J1; TH1F *WToLNu_3_J1; TH1F *WToLNu_4_J1; TH1F *WToLNu_5_J1; TH1F *WToLNu_6_J1; TH1F *WToLNu_7_J1; 
TH1F *TT_1_J1; TH1F *TT_2_J1; TH1F *ST_1_J1; TH1F *ST_2_J1; TH1F *ST_3_J1; TH1F *ST_4_J1; 
TH1F *ZZ1_J1; TH1F *ZZ2_J1; TH1F *ZZ3_J1; TH1F *WW1_J1; TH1F *WW2_J1; TH1F *WZ1_J1; TH1F *WZ2_J1; TH1F *WZ3_J1; TH1F *WToLNu_J1; TH1F *background_J1;

TH1F *data_J2; TH1F *tptzm0700lh_J2; TH1F *tptzm0900lh_J2; TH1F *tptzm1400lh_J2; TH1F *tptzm1700lh_J2; 
TH1F *ZToNuNu_1_J2; TH1F *ZToNuNu_2_J2; TH1F *ZToNuNu_3_J2; TH1F *ZToNuNu_4_J2; TH1F *ZToNuNu_5_J2; TH1F *ZToNuNu_6_J2; TH1F *ZToNuNu_7_J2; 
TH1F *QCD_1_J2; TH1F *QCD_2_J2; TH1F *QCD_3_J2; TH1F *QCD_4_J2; TH1F *QCD_5_J2; TH1F *QCD_6_J2; TH1F *QCD_7_J2; 
TH1F *WToLNu_1_J2; TH1F *WToLNu_2_J2; TH1F *WToLNu_3_J2; TH1F *WToLNu_4_J2; TH1F *WToLNu_5_J2; TH1F *WToLNu_6_J2; TH1F *WToLNu_7_J2; 
TH1F *TT_1_J2; TH1F *TT_2_J2; TH1F *ST_1_J2; TH1F *ST_2_J2; TH1F *ST_3_J2; TH1F *ST_4_J2; 
TH1F *ZZ1_J2; TH1F *ZZ2_J2; TH1F *ZZ3_J2; TH1F *WW1_J2; TH1F *WW2_J2; TH1F *WZ1_J2; TH1F *WZ2_J2; TH1F *WZ3_J2; TH1F *WToLNu_J2; TH1F *background_J2;

TH1F *data_J3; TH1F *tptzm0700lh_J3; TH1F *tptzm0900lh_J3; TH1F *tptzm1400lh_J3; TH1F *tptzm1700lh_J3; 
TH1F *ZToNuNu_1_J3; TH1F *ZToNuNu_2_J3; TH1F *ZToNuNu_3_J3; TH1F *ZToNuNu_4_J3; TH1F *ZToNuNu_5_J3; TH1F *ZToNuNu_6_J3; TH1F *ZToNuNu_7_J3; 
TH1F *QCD_1_J3; TH1F *QCD_2_J3; TH1F *QCD_3_J3; TH1F *QCD_4_J3; TH1F *QCD_5_J3; TH1F *QCD_6_J3; TH1F *QCD_7_J3; 
TH1F *WToLNu_1_J3; TH1F *WToLNu_2_J3; TH1F *WToLNu_3_J3; TH1F *WToLNu_4_J3; TH1F *WToLNu_5_J3; TH1F *WToLNu_6_J3; TH1F *WToLNu_7_J3; 
TH1F *TT_1_J3; TH1F *TT_2_J3; TH1F *ST_1_J3; TH1F *ST_2_J3; TH1F *ST_3_J3; TH1F *ST_4_J3; 
TH1F *ZZ1_J3; TH1F *ZZ2_J3; TH1F *ZZ3_J3; TH1F *WW1_J3; TH1F *WW2_J3; TH1F *WZ1_J3; TH1F *WZ2_J3; TH1F *WZ3_J3; TH1F *WToLNu_J3; TH1F *background_J3;

TH1F *data_J4; TH1F *tptzm0700lh_J4; TH1F *tptzm0900lh_J4; TH1F *tptzm1400lh_J4; TH1F *tptzm1700lh_J4; 
TH1F *ZToNuNu_1_J4; TH1F *ZToNuNu_2_J4; TH1F *ZToNuNu_3_J4; TH1F *ZToNuNu_4_J4; TH1F *ZToNuNu_5_J4; TH1F *ZToNuNu_6_J4; TH1F *ZToNuNu_7_J4; 
TH1F *QCD_1_J4; TH1F *QCD_2_J4; TH1F *QCD_3_J4; TH1F *QCD_4_J4; TH1F *QCD_5_J4; TH1F *QCD_6_J4; TH1F *QCD_7_J4; 
TH1F *WToLNu_1_J4; TH1F *WToLNu_2_J4; TH1F *WToLNu_3_J4; TH1F *WToLNu_4_J4; TH1F *WToLNu_5_J4; TH1F *WToLNu_6_J4; TH1F *WToLNu_7_J4; 
TH1F *TT_1_J4; TH1F *TT_2_J4; TH1F *ST_1_J4; TH1F *ST_2_J4; TH1F *ST_3_J4; TH1F *ST_4_J4; 
TH1F *ZZ1_J4; TH1F *ZZ2_J4; TH1F *ZZ3_J4; TH1F *WW1_J4; TH1F *WW2_J4; TH1F *WZ1_J4; TH1F *WZ2_J4; TH1F *WZ3_J4; TH1F *WToLNu_J4; TH1F *background_J4;

