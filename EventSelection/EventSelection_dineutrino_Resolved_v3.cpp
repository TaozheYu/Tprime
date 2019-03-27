#include "EventSelection_dineutrino_Resolved_v3.h" 
#include "math.h"

void EventSelection_dineutrino_Resolved_v3(const char * Input = ""){
  gStyle->SetCanvasColor(0);
  gStyle->SetFrameBorderMode(0);
  gStyle->SetOptStat("rme");
  gStyle->SetPalette(1,0);
  gStyle->SetTitleX(0.50);
  gStyle->SetTitleY(0.96);
  gStyle->SetPaintTextFormat(".2f");

  bool preselection = true;
  bool sideband     = false;
  bool signal       = false;

  //SYSTEMATICS: 0 is standard, 1 is UP, 2 is down
  int SysJes = 0;
  int SysJer = 0;
  
  using namespace std;
  char openTree[500];   sprintf(openTree, "TNT/BOOM"); 
  vector<string> fileName;
  /*fileName.push_back("May18V1_METB.root");//1
  fileName.push_back("May18V1_METC.root");  //2
  fileName.push_back("May18V1_METD.root");  //3
  fileName.push_back("May18V1_METE.root");  //4
  fileName.push_back("May18V1_METF.root");  //5
  fileName.push_back("Tprime_0700.root");   //6
  fileName.push_back("Tprime_0800.root");   //7
  fileName.push_back("Tprime_0900.root");   //8
  fileName.push_back("Tprime_1000.root");   //9
  fileName.push_back("Tprime_1100.root");   //10
  fileName.push_back("Tprime_1200.root");   //11
  fileName.push_back("Tprime_1300.root");   //12
  fileName.push_back("Tprime_1400.root");   //13
  fileName.push_back("Tprime_1500.root");   //14
  fileName.push_back("Tprime_1600.root");   //15
  fileName.push_back("Tprime_1700.root");   //16
  fileName.push_back("Tprime_1800.root");   //17
  fileName.push_back("ZToNuNu_HT100to200.root"); //18
  fileName.push_back("ZToNuNu_HT200to400.root"); //19
  fileName.push_back("ZToNuNu_HT400to600.root"); //20
  fileName.push_back("ZToNuNu_HT600to800.root"); //21
  fileName.push_back("ZToNuNu_HT800to1200.root");//22
  fileName.push_back("ZToNuNu_HT1200to2500.root");//23
  fileName.push_back("ZToNuNu_HT2500toInf.root"); //24
  fileName.push_back("QCD_HT200to300.root");  //25
  fileName.push_back("QCD_HT300to500.root");  //26
  fileName.push_back("QCD_HT500to700.root");  //27
  fileName.push_back("QCD_HT700to1000.root"); //28
  fileName.push_back("QCD_HT1000to1500.root");//29
  fileName.push_back("QCD_HT1500to2000.root");//30
  fileName.push_back("QCD_HT2000toInf.root"); //31
  fileName.push_back("WToLNu_HT100to200.root");  //32
  fileName.push_back("WToLNu_HT200to400.root");  //33
  fileName.push_back("WToLNu_HT400to600.root");  //34
  fileName.push_back("WToLNu_HT600to800.root");  //35
  fileName.push_back("WToLNu_HT800to1200.root"); //36
  fileName.push_back("WToLNu_HT1200to2500.root");//37
  fileName.push_back("WToLNu_HT2500toInf.root"); //38
  fileName.push_back("TTTo2L2Nu.root");  //39
  fileName.push_back("TTToSemiLeptonic.root");  //40
  fileName.push_back("ST_t-channel_antitop.root");  //41
  fileName.push_back("ST_t-channel_top.root");  //42
  fileName.push_back("ST_tW_antitop.root");  //43
  fileName.push_back("ST_tW_top.root");  //44
  fileName.push_back("ZZTo4L.root");   //45
  fileName.push_back("ZZTo2L2Q.root"); //46
  fileName.push_back("ZZTo2L2Nu.root");  //47
  fileName.push_back("ZZTo2Q2Nu.root");//48
  fileName.push_back("WWTo2L2Nu.root");//49
  fileName.push_back("WWToLNuQQ.root");//50
  fileName.push_back("WZTo1L1Nu2Q.root");//51
  fileName.push_back("WZTo1L3Nu.root");//52
  fileName.push_back("WZTo2L2Q.root"); //53
  fileName.push_back("WZTo3LNu.root"); //54
  fileName.push_back("TTWToLNu.root");
  fileName.push_back("TTZToLLNuNu.root");
  fileName.push_back("tZq.root");*/
  fileName.push_back(Input);
  
  for(unsigned int Nfiles=0; Nfiles<fileName.size(); Nfiles++){
    string NewFileprov;
    if ((SysJes==0)&&(SysJer==0)) NewFileprov = "/publicfs/cms/user/yutz/Tprime/2016_dineutrino/Preselection_v6/"+fileName[Nfiles];
    if ((SysJes==1)&&(SysJer==0)) NewFileprov = "/publicfs/cms/user/yutz/Tprime/2016_dineutrino/Preselection_v6/JESup/"+fileName[Nfiles];
    if ((SysJes==2)&&(SysJer==0)) NewFileprov = "/publicfs/cms/user/yutz/Tprime/2016_dineutrino/Preselection_v6/JESdo/"+fileName[Nfiles];
    if ((SysJes==0)&&(SysJer==1)) NewFileprov = "/publicfs/cms/user/yutz/Tprime/2016_dineutrino/Preselection_v6/JERup/"+fileName[Nfiles];
    if ((SysJes==0)&&(SysJer==2)) NewFileprov = "/publicfs/cms/user/yutz/Tprime/2016_dineutrino/Preselection_v6/JERdo/"+fileName[Nfiles];
	//NewFileprov = fileName[Nfiles];
    //const char *NewFileName = fileName[Nfiles].c_str();
	const char *NewFileName = NewFileprov.c_str();
    TFile f(NewFileName,"new");
    TTree *NewTree = new TTree("tree","tree");
    TTree *NewTreeSB = new TTree("treeSB","treeSB");
     
    string FILEprov = "/publicfs/cms/user/yutz/Tprime/2016_dineutrino/data_and_sample_2016_v3/"+fileName[Nfiles];
    const char *FILE = FILEprov.c_str();
    TFile *file = TFile::Open(FILE);
    Tree = (TTree*)file->Get(openTree);
    bool data = true;
    if(!(fileName[Nfiles].find("Aug17V1_MET")!=string::npos )) data = false;
    //if(!(fileName[Nfiles].find("data")!=string::npos )) data = false;
    branch(data,NewTree,NewTreeSB,fileName[Nfiles]);
    Int_t nentries = (Int_t)Tree->GetEntries();
    for(int selection=0; selection<3; selection++){
      //selection = 0 -> preselection
      //selection = 1 -> signal selection
      //selection = 2 -> sideband
      if(!((preselection  && selection==0) || (!preselection && sideband && (selection==1 || selection==2)) || (!preselection && !sideband && selection==1))) continue;
        for (Int_t i=0; i<nentries; i++) { 
	Long64_t tentry = Tree->LoadTree(i);
	branchGetEntry(data, tentry,fileName[Nfiles]);
	initializeVar();                                                                                  //162277
	if(!(HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_==1 || HLT_PFMET120_PFMHT120_IDTight_==1))  continue;  //133383
        if(!(Flag_goodVertices_==1))  continue;                                                           //133324
        if(!(Flag_globalSuperTightHalo2016Filter_==1))  continue;                                         //123761
        if(!(Flag_HBHENoiseFilter_==1))  continue;                                                        //119952
        if(!(Flag_HBHENoiseIsoFilter_==1))  continue;                                                     //119304
        if(!(Flag_EcalDeadCellTriggerPrimitiveFilter_==1))  continue;                                     //118787
        //if(!(Flag_BadPFMuonFilter_==1))  continue;
        //if(!(Flag_BadChargedCandidateFilter_==1))  continue;
        //if(!(Flag_ecalBadCalibReducedMINIAODFilter_==1))  continue;
        if(data) {if (!(Flag_eeBadScFilter_==1))  continue;}                                              //118787
	if(!data) GenClassifier(GenZPt,GenWPt);
	//large met
	bool SelectedMet = false;
	SelectMet(SelectedMet);
	Met_pt            = Met_type1PF_pt_;
	Met_phi           = Met_type1PF_phi_;
	//if(!SelectedMet) continue;
	//Leptonic reject
	vector<TLorentzVector> SelectedElectrons; vector<int> SelectedElectronsIndex;
	vector<TLorentzVector> SelectedMuons;     vector<int> SelectedMuonsIndex;
	SelectElectrons(SelectedElectrons, SelectedElectronsIndex, data);
	SelectMuons(SelectedMuons, SelectedMuonsIndex);
	
	//Hadronic Top selection
	vector<float> SelectedJetsCSV; 
	vector<float> SelectedBJetsMCSV, SelectedBJetsLCSV, SelectedBJetsTCSV,SelectedForwardJetsCSV; 
	vector<int>   CA8Indices;
	int CA8Index = -1;
	bool deltaPhiJetMet=true;
        //vector<TLorentzVector> SelectedWJets;       SelectCA8Jets(0,SelectedWJets,  SelectedElectrons,SelectedMuons,CA8Indices, SysJes, SysJer, data, deltaPhiJetMet);   //if(!deltaPhiJetMet)  continue;
	//vector<TLorentzVector> SelectedTopJets;     SelectCA8Jets(1,SelectedTopJets,SelectedElectrons,SelectedMuons,CA8Indices, SysJes, SysJer, data, deltaPhiJetMet);   //if(!deltaPhiJetMet)  continue;
        //if (SelectedWJets.size()>0) continue;
        //if (SelectedTopJets.size()>0) continue;
	vector<TLorentzVector> SelectedJets;        SelectJets(0,SelectedJets       ,SelectedJetsCSV       ,SelectedElectrons,SelectedMuons, SysJes, SysJer, data, deltaPhiJetMet);  //if(!deltaPhiJetMet)  continue;
	vector<TLorentzVector> SelectedBJetsL;      SelectJets(11,SelectedBJetsL    ,SelectedBJetsLCSV     ,SelectedElectrons,SelectedMuons, SysJes, SysJer, data, deltaPhiJetMet);  //if(!deltaPhiJetMet)  continue;
	vector<TLorentzVector> SelectedBJetsM;      SelectJets(12,SelectedBJetsM    ,SelectedBJetsMCSV     ,SelectedElectrons,SelectedMuons, SysJes, SysJer, data, deltaPhiJetMet);  //if(!deltaPhiJetMet)  continue;
	vector<TLorentzVector> SelectedBJetsT;      SelectJets(13,SelectedBJetsT    ,SelectedBJetsTCSV     ,SelectedElectrons,SelectedMuons, SysJes, SysJer, data, deltaPhiJetMet);  //if(!deltaPhiJetMet)  continue;
	vector<TLorentzVector> SelectedForwardJets; SelectJets(2,SelectedForwardJets,SelectedForwardJetsCSV,SelectedElectrons,SelectedMuons, SysJes, SysJer, data, deltaPhiJetMet);  //if(!deltaPhiJetMet)  continue;
	TLorentzVector Jet1Resolved;     Jet1Resolved.SetPtEtaPhiE(0, 0, 0, 0);
	TLorentzVector Jet2Resolved;     Jet2Resolved.SetPtEtaPhiE(0, 0, 0, 0);
	TLorentzVector Jet3Resolved;     Jet3Resolved.SetPtEtaPhiE(0, 0, 0, 0);
	TLorentzVector TopQuark;         TopQuark.SetPtEtaPhiE(0, 0, 0, 0);
	TLorentzVector TopQuarkResolved; TopQuarkResolved.SetPtEtaPhiE(0, 0, 0, 0);
	bool ResolvedEvent   = false;
	if(selection==0) ResolvedRegionSelection(ResolvedEvent, SelectedJets, SelectedJetsCSV, TopQuarkResolved, Jet1Resolved, Jet2Resolved, Jet3Resolved, false, false);
	if(selection==1) ResolvedRegionSelection(ResolvedEvent, SelectedJets, SelectedJetsCSV, TopQuarkResolved, Jet1Resolved, Jet2Resolved, Jet3Resolved, false, true );
	if(selection==2) ResolvedRegionSelection(ResolvedEvent, SelectedJets, SelectedJetsCSV, TopQuarkResolved, Jet1Resolved, Jet2Resolved, Jet3Resolved, false, false);
	if(ResolvedEvent)   TopQuark = TopQuarkResolved;
	if(!ResolvedEvent) continue;                                                                      //4068
	NumSelLeps        = SelectedElectrons.size()+SelectedMuons.size();
	NumSelJets        = SelectedJets.size();
	NumSelForwardJets = SelectedForwardJets.size();
	NumSelBJetsL      = SelectedBJetsL.size();
	NumSelBJetsM      = SelectedBJetsM.size();
	NumSelBJetsT      = SelectedBJetsT.size();
	NVertices         = nBestVtx_;
	EVENT_run         = EVENT_run_;
	//EVENT_event       = EVENT_event_;
	EVENT_lumiBlock   = EVENT_lumiBlock_;
	EVENT_genHT       = EVENT_genHT_;
        prefiringweight   = EVENT_prefiringweight_;
        prefiringweightup = EVENT_prefiringweightup_;
        prefiringweightdown = EVENT_prefiringweightdown_;
	HT                = HTcalculator(SelectedJets);
	if(!(HT>200)) continue;                                                                          //2641
	//categorization
	if(selection==0){ //PRESELECTION
	  if(ResolvedEvent  && SelectedMet)  category0=1;  
	} else if(selection==1){ //SELECTION
	  if(ResolvedEvent && NumSelBJetsM>0 && SelectedMet)     category0=1; 
	} 

	if(!(category0==1)) continue;
         
	//TREE
	FillBranches(ResolvedEvent,TopQuark,SelectedMet,
    TopQuarkResolved,Jet1Resolved,Jet2Resolved,Jet3Resolved,SelectedForwardJets,SelectedBJetsM);
	//WEIGHT
	if(!data){
	  get_weight_btag(selection,w_Btag, w_BtagUp, w_BtagDown,w_Btag1Up, w_Btag1Down,w_Btag2Up, w_Btag2Down,w_BtagLoose, w_BtagLooseUp, w_BtagLooseDown, fileName[Nfiles]);
	  //ForwardJetSF(SelectedForwardJets, w_for, w_forUp, w_forDown);
	  newPUWeight(PUWeight, PUWeightUP, PUWeightDOWN);
	  GenWeight(fileName[Nfiles], GenZPt, GenWPt);
	  HTSF(fileName[Nfiles],HT,w_ZToNuNu,w_ZToNuNuUp,w_ZToNuNuDown,w_WToLNu,w_WToLNuUp,w_WToLNuDown,w_ttbar,w_ttbarUp,w_ttbarDown);
	  if(!(fileName[Nfiles].find("ST_tW")!=string::npos )){ 
            fillgenWeights();
            QCDWeight(0,8,w_QCDUp,w_QCDDown);
            if(fileName[Nfiles].find("Tprime")==string::npos) PDFWeight(9,99,w_PDFUp,w_PDFDown);
            if(fileName[Nfiles].find("Tprime")!=string::npos) PDFWeight(110,210,w_PDFUp,w_PDFDown);
          }
          //PDFWeight()
	}
	
	if(selection==0 || selection==1) HistoFill(PUWeight,NewTree);
	else if(selection==2)            HistoFill(PUWeight,NewTreeSB);
		} 
    }
    f.cd();
    writeFile(NewTree,NewTreeSB);
    f.Close();
    cout<<"File "<<fileName[Nfiles]<<" ready!"<<endl;
  }
}

void QCDWeight(int imin,int imax,float &w_QCDUp ,float &w_QCDDown){
     TH1F *RMS = new TH1F("", "", 100,-0.5,0.5);
     for(int i=imin; i<imax; i++){
	if(i==5) continue;
	if(i==7) continue;
	int I = 0;
        I=i;
	float ratio = (*genWeights_)[I]/(*genWeights_)[0];
	RMS->Fill(ratio-1);
	w_QCDUp = 1+RMS->GetRMS();
	w_QCDDown = TMath::Max(0.,(1 - RMS->GetRMS()));
     }
     delete RMS;
}

void PDFWeight(int imin,int imax,float &w_PDFUp ,float &w_PDFDown){
     TH1F *RMS = new TH1F("", "", 100,-0.5,0.5);
     for(int i=imin; i<imax; i++){
	int I = 0;
	if(i==9||i==110) I=0;
	else       I=i;
	float ratio = (*genWeights_)[I]/(*genWeights_)[0];
	RMS->Fill(ratio-1);
	w_PDFUp = 1+RMS->GetRMS();
	w_PDFDown = TMath::Max(0.,(1 - RMS->GetRMS()));
     }
     delete RMS;
}

void SelectMet(bool &SelectedMet){ 
    if( Met_type1PF_pt_ > 200)  SelectedMet = true;
}

void SelectElectrons(vector<TLorentzVector> & SelectedElectrons, vector<int> & SelectedElectronsIndex, bool data){
  for (UInt_t j = 0; j < patElectron_pt_->size(); ++j){
    if(!(patElectron_pt_->at(j)>20))                 continue;
    if(!(fabs(patElectron_eta_->at(j))<2.4))	     continue;
    if(!(fabs(patElectron_SCeta_->at(j))<2.5))	     continue;
    if(!(patElectron_inCrack_->at(j)==0))	         continue;
    if(!(patElectron_isPassLoose_->at(j)==1))	     continue;
    if(!(patElectron_passConversionVeto_->at(j)==1)) continue;
    //TLorentzVector electron; electron.SetPtEtaPhiE(patElectron_pt_->at(j),patElectron_eta_->at(j),patElectron_phi_->at(j),patElectron_energy_->at(j)*patElectron_energyCorr_->at(j));
    TLorentzVector electron; electron.SetPtEtaPhiE(patElectron_pt_->at(j),patElectron_eta_->at(j),patElectron_phi_->at(j),patElectron_energy_->at(j));
    SelectedElectrons.push_back(electron);
    SelectedElectronsIndex.push_back(j);
  }
}

void SelectMuons(vector<TLorentzVector> & SelectedMuons, vector<int> & SelectedMuonsIndex){
  for (UInt_t j = 0; j < Muon_pt_->size(); ++j){
    if(!(Muon_pt_->at(j)>20))                     continue;
    if(!(fabs(Muon_eta_->at(j))<2.4))             continue;
    if(!(Muon_loose_->at(j)==1))                  continue;
    if(!(Muon_relIsoDeltaBetaR04_->at(j)<0.25))   continue;  //loose iso
    TLorentzVector muon; muon.SetPtEtaPhiE(Muon_pt_->at(j),Muon_eta_->at(j),Muon_phi_->at(j),Muon_energy_->at(j));
    SelectedMuons.push_back(muon);
    SelectedMuonsIndex.push_back(j);
  }
}


void SelectJets(int jetType, vector<TLorentzVector> & SelectedJets, vector<float> & SelectedJetsCSV, vector<TLorentzVector> SelectedElectrons, vector<TLorentzVector> SelectedMuons, int SysJes, int SysJer, bool data, bool &deltaPhiJetMet){
  //jetType=0  -> usual jets
  //jetType=11 -> b-jets L
  //jetType=12 -> b-jets M
  //jetType=13 -> b-jets T
  //jetType=2  -> forward jets
  //MinDeltaPhiJetMet = 99.0;
  for (UInt_t j = 0; j < Jet_pt_->size(); ++j){
    float MaxMostForwardJetEta=0;
	//if (fabs(Jet_eta_->at(j))>MaxMostForwardJetEta) {MostForwardJetEta = Jet_eta_->at(j); MostForwardJetPt = Jet_pt_->at(j);}
    float jetpt = 0.;
    if(SysJes==0 && SysJer==0){jetpt = Jet_Uncorr_pt_->at(j)*Jet_JesSF_->at(j)    *Jet_JerSF_->at(j)    ;}
    if(SysJes==1 && SysJer==0){jetpt = Jet_Uncorr_pt_->at(j)*Jet_JesSFup_->at(j)  *Jet_JerSF_->at(j)    ;}
    if(SysJes==2 && SysJer==0){jetpt = Jet_Uncorr_pt_->at(j)*Jet_JesSFdown_->at(j)*Jet_JerSF_->at(j)    ;}
    if(SysJes==0 && SysJer==1){jetpt = Jet_Uncorr_pt_->at(j)*Jet_JesSF_->at(j)    *Jet_JerSFup_->at(j)  ;}
    if(SysJes==0 && SysJer==2){jetpt = Jet_Uncorr_pt_->at(j)*Jet_JesSF_->at(j)    *Jet_JerSFdown_->at(j);}
    if(!(jetpt>30))                 continue;
    if(!(fabs(Jet_eta_->at(j))<5.0))                                        continue;
    //if(jetType==2) {if(!(fabs(Jet_eta_->at(j))>=2.4))                       continue;if(!(jetpt>30)) continue;}
    //else {if(!(fabs(Jet_eta_->at(j))<2.4))		                            continue;}
    if(fabs(Jet_eta_->at(j))<2.4){
      if(!(Jet_neutralHadEnergyFraction_->at(j)<0.99))                      continue;
      if(!(Jet_neutralEmEnergyFraction_->at(j)<0.99))                       continue;
      if(!(Jet_numberOfConstituents_->at(j)>1))                             continue;
      if(!(Jet_chargedHadronEnergyFraction_->at(j)>0.0))                    continue;
      if(!(Jet_chargedMultiplicity_->at(j)>0.0))                            continue;
      if(!(Jet_chargedEmEnergyFraction_->at(j)<0.99))                       continue;
    } else if(fabs(Jet_eta_->at(j))>2.4 && fabs(Jet_eta_->at(j))<2.7){
      if(!(Jet_neutralHadEnergyFraction_->at(j)<0.99))                      continue;
      if(!(Jet_neutralEmEnergyFraction_->at(j)<0.99))                       continue;
      if(!(Jet_numberOfConstituents_->at(j)>1))                             continue;
    } else if(fabs(Jet_eta_->at(j))>2.7 && fabs(Jet_eta_->at(j))<3.0){
      if(!(Jet_neutralEmEnergyFraction_->at(j)>0.01))                       continue;
      if(!(Jet_neutralHadEnergyFraction_->at(j)<0.98))                      continue;
      if(!((Jet_numberOfConstituents_->at(j) -Jet_chargedMultiplicity_->at(j)) >2)) continue;
    } else if(fabs(Jet_eta_->at(j))>3.0){
      if(!(Jet_neutralEmEnergyFraction_->at(j)<0.90))                       continue;
      if(!((Jet_numberOfConstituents_->at(j) -Jet_chargedMultiplicity_->at(j)) >10)) continue;
    }
    if(jetType==11){if(!(Jet_pfDeepCSVBJetTags_->at(j)>0.2219)) continue;}
    if(jetType==12){if(!(Jet_pfDeepCSVBJetTags_->at(j)>0.6324)) continue;}
    if(jetType==13){if(!(Jet_pfDeepCSVBJetTags_->at(j)>0.8958)) continue;}
	if (fabs(Jet_eta_->at(j))>MaxMostForwardJetEta) {MostForwardJetEta = Jet_eta_->at(j); MostForwardJetPt = jetpt;}
	if(jetType==2) {if(!(fabs(Jet_eta_->at(j))>=2.4))                       continue;if(!(jetpt>30)) continue;}
    else {if(!(fabs(Jet_eta_->at(j))<2.4))		                            continue;}
	if(DeltaPhi(Jet_phi_->at(j),Met_type1PF_phi_)<MinDeltaPhiJetMet) MinDeltaPhiJetMet = DeltaPhi(Jet_phi_->at(j),Met_type1PF_phi_);
    float SF = jetpt/Jet_pt_->at(j);
    TLorentzVector jet_prov; jet_prov.SetPtEtaPhiM(Jet_pt_->at(j),Jet_eta_->at(j),Jet_phi_->at(j),Jet_mass_->at(j));
    TLorentzVector jet; jet.SetPxPyPzE(SF*jet_prov.Px(),SF*jet_prov.Py(),SF*jet_prov.Pz(),SF*jet_prov.E());
    SelectedJets.push_back(jet);
    SelectedJetsCSV.push_back(Jet_pfDeepCSVBJetTags_->at(j));
  }
  if(!(MinDeltaPhiJetMet>0.6)) deltaPhiJetMet=false;
}

void SelectCA8Jets(int CA8jetType,vector<TLorentzVector> & SelectedCA8Jets,vector<TLorentzVector> SelectedElectrons,vector<TLorentzVector> SelectedMuons, vector<int> & CA8Indices, 
		   int SysJes, int SysJer, bool data, bool &deltaPhiJetMet){
  //CA8jetType=0 -> W-jets
  //CA8jetType=1 -> top-jets
  for (UInt_t j = 0; j < BoostedJet_pt_->size(); ++j){
    float jetpt = 0.;
    if(SysJes==0 && SysJer==0){jetpt = BoostedJet_Uncorr_pt_->at(j)*BoostedJet_JesSF_->at(j)    *BoostedJet_JerSF_->at(j)    ;}
    if(SysJes==1 && SysJer==0){jetpt = BoostedJet_Uncorr_pt_->at(j)*BoostedJet_JesSFup_->at(j)  *BoostedJet_JerSF_->at(j)    ;}
    if(SysJes==2 && SysJer==0){jetpt = BoostedJet_Uncorr_pt_->at(j)*BoostedJet_JesSFdown_->at(j)*BoostedJet_JerSF_->at(j)    ;}
    if(SysJes==0 && SysJer==1){jetpt = BoostedJet_Uncorr_pt_->at(j)*BoostedJet_JesSF_->at(j)    *BoostedJet_JerSFup_->at(j)  ;}
    if(SysJes==0 && SysJer==2){jetpt = BoostedJet_Uncorr_pt_->at(j)*BoostedJet_JesSF_->at(j)    *BoostedJet_JerSFdown_->at(j);}
    float SF = jetpt/BoostedJet_pt_->at(j);
    if(!(jetpt>200)) continue;
    if(!(fabs(BoostedJet_eta_->at(j))<2.4))               continue;
    if(!(BoostedJet_neutralHadEnergyFraction_->at(j)<0.90)) continue;
    if(!(BoostedJet_neutralEmEnergyFraction_->at(j)<0.90)) continue;
    if(!(BoostedJet_numberOfConstituents_->at(j)>1)) continue;
    if(!(BoostedJet_chargedHadronEnergyFraction_->at(j)>0.0)) continue;
    if(!(BoostedJet_chargedMultiplicity_->at(j)>0.0)) continue;
    if(!(BoostedJet_chargedEmEnergyFraction_->at(j)<0.99)) continue;
    if(CA8jetType==0){
      if(!(SF*BoostedJet_pruned_mass_->at(j)>65 && SF*BoostedJet_pruned_mass_->at(j)<105)) continue;
      if(!(BoostedJet_tau2_->at(j)/BoostedJet_tau1_->at(j)<0.45))                          continue;
    } else if(CA8jetType==1) {
      if(!(jetpt>400))                                                                           continue;
      if(!(SF*BoostedJet_softdrop_mass_->at(j)>105 && SF*BoostedJet_softdrop_mass_->at(j)<220))  continue;
      if(!(BoostedJet_tau3_->at(j)/BoostedJet_tau2_->at(j)<0.80))                                continue;
    }

    TLorentzVector jet_prov; jet_prov.SetPtEtaPhiM(BoostedJet_pt_->at(j),BoostedJet_eta_->at(j),BoostedJet_phi_->at(j),BoostedJet_mass_->at(j));
    TLorentzVector jet; jet.SetPxPyPzE(SF*jet_prov.Px(),SF*jet_prov.Py(),SF*jet_prov.Pz(),SF*jet_prov.E());
    SelectedCA8Jets.push_back(jet);
    CA8Indices.push_back(j);
  }
}

/*void ResolvedRegionSelection(bool &ResolvedEvent,vector<TLorentzVector> SelectedJets,vector<float> SelectedJetsCSV,TLorentzVector &TopQuark,
			     TLorentzVector &Jet1,TLorentzVector &Jet2,TLorentzVector &Jet3,bool TopMassCut,bool btag){
  float TopPtMin=250;
  float TopMassInitial=99999;
  for(unsigned int i=0; i<SelectedJets.size(); i++){
    for(unsigned int j=i+1; j<SelectedJets.size(); j++){
      for(unsigned int k=j+1; k<SelectedJets.size(); k++){
		  if(!((SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).Pt()>TopPtMin))   continue;
	//if(!(fabs((SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).M()-173.1)<TopMassInitial))                                                    continue;
	if(TopMassCut){if(!((SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).M()>100 && (SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).M()<300)) continue;}
	if(btag){if(!(SelectedJetsCSV[i]>0.4941 || SelectedJetsCSV[j]>0.4941 || SelectedJetsCSV[k]>0.4941))                                          continue;}
	if(SelectedJetsCSV[i]>SelectedJetsCSV[j] && SelectedJetsCSV[i]>SelectedJetsCSV[k]){
	  Jet1.SetPtEtaPhiE(SelectedJets[i].Pt(),SelectedJets[i].Eta(),SelectedJets[i].Phi(),SelectedJets[i].E());
	  Jet2.SetPtEtaPhiE(SelectedJets[j].Pt(),SelectedJets[j].Eta(),SelectedJets[j].Phi(),SelectedJets[j].E());
	  Jet3.SetPtEtaPhiE(SelectedJets[k].Pt(),SelectedJets[k].Eta(),SelectedJets[k].Phi(),SelectedJets[k].E());
	}
	if(SelectedJetsCSV[j]>SelectedJetsCSV[i] && SelectedJetsCSV[j]>SelectedJetsCSV[k]){
	  Jet1.SetPtEtaPhiE(SelectedJets[j].Pt(),SelectedJets[j].Eta(),SelectedJets[j].Phi(),SelectedJets[j].E());
	  Jet2.SetPtEtaPhiE(SelectedJets[i].Pt(),SelectedJets[i].Eta(),SelectedJets[i].Phi(),SelectedJets[i].E());
	  Jet3.SetPtEtaPhiE(SelectedJets[k].Pt(),SelectedJets[k].Eta(),SelectedJets[k].Phi(),SelectedJets[k].E());
	}
	if(SelectedJetsCSV[k]>SelectedJetsCSV[i] && SelectedJetsCSV[k]>SelectedJetsCSV[j]){
	  Jet1.SetPtEtaPhiE(SelectedJets[k].Pt(),SelectedJets[k].Eta(),SelectedJets[k].Phi(),SelectedJets[k].E());
	  Jet2.SetPtEtaPhiE(SelectedJets[i].Pt(),SelectedJets[i].Eta(),SelectedJets[i].Phi(),SelectedJets[i].E());
	  Jet3.SetPtEtaPhiE(SelectedJets[j].Pt(),SelectedJets[j].Eta(),SelectedJets[j].Phi(),SelectedJets[j].E());
	}
	TopPtMin = (SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).Pt();
	TopMassInitial=fabs((SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).M()-173.1);
	TopQuark=(SelectedJets[i]+SelectedJets[j]+SelectedJets[k]);
	deltaPhiMetTop = DeltaPhi(TopQuark.Phi(),Met_phi);
	TransverseMassMetTop = sqrt(2*TopQuark.Pt()*Met_pt*(1-cos(deltaPhiMetTop)));
	if(!(TransverseMassMetTop>500)) continue;
	ResolvedEvent=true;
      }
    }
  }
}*/

void ResolvedRegionSelection(bool &ResolvedEvent,vector<TLorentzVector> SelectedJets,vector<float> SelectedJetsCSV,TLorentzVector &TopQuark,
                            TLorentzVector &Jet1,TLorentzVector &Jet2,TLorentzVector &Jet3,bool TopMassCut,bool btag){
  float TopPtMin=250;
  float TopMassInitial=99999;
  for(unsigned int i=0; i<SelectedJets.size(); i++){
    for(unsigned int j=i+1; j<SelectedJets.size(); j++){
      for(unsigned int k=j+1; k<SelectedJets.size(); k++){
         if(!((SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).Pt()>TopPtMin)) continue;
         //if(!(fabs((SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).M()-173.1)<TopMassInitial)) continue;
         if(TopMassCut){if(!((SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).M()>100 && (SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).M()<300)) continue;}
         if(btag){if(!(SelectedJetsCSV[i]>0.8484 || SelectedJetsCSV[j]>0.8484 || SelectedJetsCSV[k]>0.8484)) continue;}
         float TM = sqrt(2*(SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).Pt()*Met_pt*(1-cos(DeltaPhi((SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).Phi(),Met_phi))));
         if(!(TM>500)) continue;
         Jet1.SetPtEtaPhiE(SelectedJets[i].Pt(),SelectedJets[i].Eta(),SelectedJets[i].Phi(),SelectedJets[i].E());
         Jet2.SetPtEtaPhiE(SelectedJets[j].Pt(),SelectedJets[j].Eta(),SelectedJets[j].Phi(),SelectedJets[j].E());
         Jet3.SetPtEtaPhiE(SelectedJets[k].Pt(),SelectedJets[k].Eta(),SelectedJets[k].Phi(),SelectedJets[k].E());
         TopPtMin = (SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).Pt();
         TopMassInitial=fabs((SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).M()-173.1);
         TopQuark=(SelectedJets[i]+SelectedJets[j]+SelectedJets[k]);
         deltaPhiMetTop = DeltaPhi(TopQuark.Phi(),Met_phi);
         TransverseMassMetTop = sqrt(2*TopQuark.Pt()*Met_pt*(1-cos(deltaPhiMetTop)));
         ResolvedEvent=true;
      }
    }
  }
}

void PartiallyMergedSelection(bool &PartiallyMerged,vector<TLorentzVector> SelectedWJets,vector<TLorentzVector> SelectedJets,vector<float> SelectedJetsCSV,TLorentzVector &TopQuark,TLorentzVector &Jet1,TLorentzVector &Jet2,bool TopMassCut,bool btag,vector<int> CA8Indices,int & CA8Index,float &WMass_,float &WSubjet_, bool data){
  float TopPtMin=20;
  float TopMassInitial=99999;
  for(unsigned int i=0; i<SelectedWJets.size(); i++){
    for(unsigned int k=0; k<SelectedJets.size(); k++){
      if(!((SelectedWJets[i]+SelectedJets[k]).Pt()>TopPtMin))                                                        continue;
      //if(!(fabs((SelectedWJets[i]+SelectedJets[k]).M()-173.1)<TopMassInitial))                                     continue;
      if(!(DeltaR(SelectedWJets[i].Eta(),SelectedJets[k].Eta(),SelectedWJets[i].Phi(),SelectedJets[k].Phi())>0.8))   continue;
      if(btag){if(!(SelectedJetsCSV[k]>0.8484))                                                                       continue;}
      if(TopMassCut){if(!((SelectedWJets[i]+SelectedJets[k]).M()>100 && (SelectedWJets[i]+SelectedJets[k]).M()<300)) continue;}
      Jet1.SetPtEtaPhiE(SelectedWJets[i].Pt(),SelectedWJets[i].Eta(),SelectedWJets[i].Phi(),SelectedWJets[i].E());
      Jet2.SetPtEtaPhiE(SelectedJets[k].Pt(),SelectedJets[k].Eta(),SelectedJets[k].Phi(),SelectedJets[k].E());
      TopPtMin = (SelectedWJets[i]+SelectedJets[k]).Pt();
      PartiallyMerged=true;
      TopMassInitial=fabs((SelectedWJets[i]+SelectedJets[k]).M()-173.1);
      TopQuark=(SelectedWJets[i]+SelectedJets[k]);
      CA8Index=CA8Indices[i];
      float SF = (BoostedJet_Uncorr_pt_->at(CA8Indices[i])/BoostedJet_pt_->at(CA8Indices[i]))*BoostedJet_JesSF_->at(CA8Indices[i])*BoostedJet_JerSF_->at(CA8Indices[i]);
      WMass_   = SF*BoostedJet_pruned_mass_->at(CA8Indices[i]);
      WSubjet_ = BoostedJet_tau2_->at(CA8Indices[i])/BoostedJet_tau1_->at(CA8Indices[i]);
    }
  }
}

void FullyMergedSelection(bool & FullyMerged, vector<TLorentzVector> SelectedTopJets, TLorentzVector &TopQuark,vector<int> CA8Indices,float &TopSoftMass_,float &TopSubjet_, bool data){
  float TopPtMin=400;
  for(unsigned int i=0; i<SelectedTopJets.size(); i++){
    if(!(SelectedTopJets[i].Pt()>TopPtMin)) continue;
    FullyMerged=true;
    TopPtMin=SelectedTopJets[i].Pt();
    TopQuark=SelectedTopJets[i];
    float SF = (BoostedJet_Uncorr_pt_->at(CA8Indices[i])/BoostedJet_pt_->at(CA8Indices[i]))*BoostedJet_JesSF_->at(CA8Indices[i])*BoostedJet_JerSF_->at(CA8Indices[i]);
    TopSoftMass_  = SF*BoostedJet_softdrop_mass_->at(CA8Indices[i]);
    TopSubjet_    = BoostedJet_tau3_->at(CA8Indices[i])/BoostedJet_tau2_->at(CA8Indices[i]);
  }
}

void BTagSF(int selection, float JetPt, float JetEta, int flav, float &SF, float &SFerr){
  bool DoubleUncertainty = false;
  float MinBJetPt = 20.;
  float MaxBJetPt = 1000.;
  float MaxLJetPt = 1000.;
  if((flav==5 || flav==4) && JetPt<=MinBJetPt){
    JetPt = MinBJetPt+0.1; 
    DoubleUncertainty = true;
  }  
  if((flav==5 || flav==4) && JetPt>=MaxBJetPt){
    JetPt = MaxBJetPt-0.1; 
    DoubleUncertainty = true;
  }  
  if(flav==0 && JetPt>=MaxLJetPt){
    JetPt = MaxLJetPt-0.1; 
    DoubleUncertainty = true;
  }
  auto btagentry_flav = flav == 5 ? BTagEntry::FLAV_B : (flav == 4 ? BTagEntry::FLAV_C : BTagEntry::FLAV_UDSG);
  double jet_scalefactor = 1;
  double jet_scalefactor_up = 0;
  double jet_scalefactor_do = 0;
  if(selection==0 || selection==1){
    if(flav==5 || flav==4){
      jet_scalefactor    = readerMComb.eval(btagentry_flav, JetEta, JetPt);
      jet_scalefactor_up = readerMComb_up.eval(btagentry_flav, JetEta, JetPt); 
      jet_scalefactor_do = readerMComb_do.eval(btagentry_flav, JetEta, JetPt);
    } else {
      jet_scalefactor    = readerMIncl.eval(btagentry_flav, JetEta, JetPt);
      jet_scalefactor_up = readerMIncl_up.eval(btagentry_flav, JetEta, JetPt); 
      jet_scalefactor_do = readerMIncl_do.eval(btagentry_flav, JetEta, JetPt);
    }
  } else if(selection==2){
    if(flav==5 || flav==4){
      jet_scalefactor    = readerLComb.eval(btagentry_flav, JetEta, JetPt);
      jet_scalefactor_up = readerLComb_up.eval(btagentry_flav, JetEta, JetPt); 
      jet_scalefactor_do = readerLComb_do.eval(btagentry_flav, JetEta, JetPt);
    } else {
      jet_scalefactor    = readerLIncl.eval(btagentry_flav, JetEta, JetPt);
      jet_scalefactor_up = readerLIncl_up.eval(btagentry_flav, JetEta, JetPt); 
      jet_scalefactor_do = readerLIncl_do.eval(btagentry_flav, JetEta, JetPt);
    }
  }
  if(DoubleUncertainty) {
    jet_scalefactor_up = 2*(jet_scalefactor_up - jet_scalefactor) + jet_scalefactor; 
    jet_scalefactor_do = 2*(jet_scalefactor_do - jet_scalefactor) + jet_scalefactor; 
  }
  if(jet_scalefactor==0){
    jet_scalefactor=1;
    jet_scalefactor_up=1;
    jet_scalefactor_do=1;
  }
  SF=jet_scalefactor;
  SFerr=max(fabs(jet_scalefactor-jet_scalefactor_up),fabs(jet_scalefactor-jet_scalefactor_do));
  //cout<<JetPt<<" "<<JetEta<<" "<<flav<<" ("<<btagentry_flav<<") "<<jet_scalefactor<<" "<<jet_scalefactor_up<<" "<<jet_scalefactor_do<<endl;
}

void get_weight_btag(int selection, float &w_Btag, float &w_BtagUp, float &w_BtagDown, float &w_Btag1Up, float &w_Btag1Down, float &w_Btag2Up, float &w_Btag2Down, float &w_BtagLoose, float &w_BtagLooseUp, float &w_BtagLooseDown, string fileName){
  string FILEprov = "/publicfs/cms/user/yutz/Tprime/2016_dineutrino/BtagEfficiency_v3/"+fileName;
  const char *FILE = FILEprov.c_str();
  TFile *fileBTagEfficiency = TFile::Open(FILE);
  float mcTagMedium = 1.;     float mcTagLoose = 1.;
  float mcNoTagMedium = 1.;   float mcNoTagLoose = 1.;
  float dataTagMedium = 1.;   float dataTagLoose = 1.;
  float dataNoTagMedium = 1.; float dataNoTagLoose = 1.;
  float err1Medium = 0.;      float err1Loose = 0.;
  float err2Medium = 0.;      float err2Loose = 0.;
  float err3Medium = 0.;      float err3Loose = 0.;
  float err4Medium = 0.;      float err4Loose = 0.;
  for (UInt_t j = 0; j < Jet_pt_->size(); ++j){
    if(!((Jet_Uncorr_pt_->at(j)*Jet_JesSF_->at(j)*Jet_JerSF_->at(j))>20)) continue;
    if(!(fabs(Jet_eta_->at(j))<2.4))                                      continue;
    if(!(Jet_neutralHadEnergyFraction_->at(j)<0.99))                      continue;
    if(!(Jet_neutralEmEnergyFraction_->at(j)<0.99))                       continue;
    if(!(Jet_numberOfConstituents_->at(j)>1))                             continue;
    if(!(Jet_chargedHadronEnergyFraction_->at(j)>0.0))                    continue;
    if(!(Jet_chargedMultiplicity_->at(j)>0.0))                            continue;
    if(!(Jet_chargedEmEnergyFraction_->at(j)<0.99))                       continue;
    float JetPt  = (Jet_Uncorr_pt_->at(j)*Jet_JesSF_->at(j)*Jet_JerSF_->at(j)); 
    float JetEta = fabs(Jet_eta_->at(j)); 
    int flav = Jet_hadronFlavour_->at(j);
    float MinBJetPt = 20.;
    float MaxBJetPt = 1000.;
    float MaxLJetPt = 1000.;
    if((flav==5 || flav==4) && JetPt<MinBJetPt){
      JetPt = MinBJetPt; 
    }  
    if((flav==5 || flav==4) && JetPt>MaxBJetPt){
      JetPt = MaxBJetPt; 
    }  
    if(flav==0 && JetPt>MaxLJetPt){
      JetPt = MaxLJetPt; 
    }  
    TH2F *NUM = (TH2F*)fileBTagEfficiency->Get("histM_b_passing_"); 
    TH2F *DEN = (TH2F*)fileBTagEfficiency->Get("histM_b_total_");
    if(selection==0 || selection==1){
      if(flav == 5) {
	NUM = (TH2F*)fileBTagEfficiency->Get("histM_b_passing_");
	DEN = (TH2F*)fileBTagEfficiency->Get("histM_b_total_");
      }else if( flav==4){
	NUM = (TH2F*)fileBTagEfficiency->Get("histM_c_passing_");
	DEN = (TH2F*)fileBTagEfficiency->Get("histM_c_total_");
      }else{
	NUM = (TH2F*)fileBTagEfficiency->Get("histM_udsg_passing_");
	DEN = (TH2F*)fileBTagEfficiency->Get("histM_udsg_total_");
      }
    } else if(selection==2){
      if(flav == 5) {
	NUM = (TH2F*)fileBTagEfficiency->Get("histL_b_passing_");
	DEN = (TH2F*)fileBTagEfficiency->Get("histL_b_total_");
      }else if( flav==4){
	NUM = (TH2F*)fileBTagEfficiency->Get("histL_c_passing_");
	DEN = (TH2F*)fileBTagEfficiency->Get("histL_c_total_");
      }else{
	NUM = (TH2F*)fileBTagEfficiency->Get("histL_udsg_passing_");
	DEN = (TH2F*)fileBTagEfficiency->Get("histL_udsg_total_");
      }
    }
    NUM->Divide(DEN);
    int etaBin = 1;
    int ptBin = 1;
    if(JetPt>19  && JetPt<=30)   ptBin = 1;
    if(JetPt>30  && JetPt<=50)   ptBin = 2;
    if(JetPt>50  && JetPt<=70)   ptBin = 3;
    if(JetPt>70  && JetPt<=100)  ptBin = 4;
    if(JetPt>100 && JetPt<=140)  ptBin = 5;
    if(JetPt>140 && JetPt<=200)  ptBin = 6;
    if(JetPt>200 && JetPt<=300)  ptBin = 7;
    if(JetPt>300 && JetPt<=600)  ptBin = 8;
    if(JetPt>600 && JetPt<=1000) ptBin = 9;
    if(flav!=5 && flav!=4)       ptBin = 1;
    float eff   = NUM->GetBinContent(ptBin,etaBin);
    float SF    = 1.0;
    float SFerr = 0.0;
    BTagSF(selection, JetPt, JetEta, flav, SF, SFerr);
    if(Jet_pfDeepCSVBJetTags_->at(j)>0.6324){
      mcTagMedium *= eff;
      dataTagMedium *= eff*SF;
      if(flav==5 || flav ==4)  err1Medium += SFerr/SF; //correlated for b/c
      else err3Medium += SFerr/SF;                     //correlated for light
    }else{
      mcNoTagMedium *= (1- eff);
      dataNoTagMedium *= (1- eff*SF);
      if(flav==5 || flav ==4 ) err2Medium += (-eff*SFerr)/(1-eff*SF); //correlated for b/c
      else err4Medium +=  (-eff*SFerr)/(1-eff*SF);                    //correlated for light
    }
    if(Jet_pfDeepCSVBJetTags_->at(j)>0.2219){
      mcTagLoose *= eff;
      dataTagLoose *= eff*SF;
      if(flav==5 || flav ==4)  err1Loose += SFerr/SF;
      else err3Loose += SFerr/SF;
    }else{
      mcNoTagLoose *= (1- eff);
      dataNoTagLoose *= (1- eff*SF);
      if(flav==5 || flav ==4 ) err2Loose += (-eff*SFerr)/(1-eff*SF);
      else err4Loose +=  (-eff*SFerr)/(1-eff*SF);
    }
    delete NUM; delete DEN;
    //cout<<JetPt<<" "<<flav<<" "<<ptBin<<" "<<etaBin<<" "<<eff<<" "<<SF<<" "<<SFerr<<endl;
  }
  float wtbtagMedium        = 1; float wtbtagLoose        = 1;
  float wtbtagErrBCMedium   = 0; float wtbtagErrBCLoose   = 0;
  float wtbtagErrUDSGMedium = 0; float wtbtagErrUDSGLoose = 0;
  if((mcNoTagMedium*mcTagMedium)!=0) wtbtagMedium        = (dataNoTagMedium * dataTagMedium ) / ( mcNoTagMedium * mcTagMedium ); 
  if((mcNoTagMedium*mcTagMedium)!=0) wtbtagErrBCMedium   = fabs(err1Medium+err2Medium) * wtbtagMedium;
  if((mcNoTagMedium*mcTagMedium)!=0) wtbtagErrUDSGMedium = fabs(err3Medium+err4Medium) * wtbtagMedium;
  if((mcNoTagLoose*mcTagLoose)!=0) wtbtagLoose        = (dataNoTagLoose * dataTagLoose ) / ( mcNoTagLoose * mcTagLoose ); 
  if((mcNoTagLoose*mcTagLoose)!=0) wtbtagErrBCLoose   = fabs(err1Loose+err2Loose) * wtbtagLoose;
  if((mcNoTagLoose*mcTagLoose)!=0) wtbtagErrUDSGLoose = fabs(err3Loose+err4Loose) * wtbtagLoose;
  w_Btag     = wtbtagMedium; 
  w_BtagUp   = wtbtagMedium+sqrt(wtbtagErrBCMedium*wtbtagErrBCMedium+wtbtagErrUDSGMedium*wtbtagErrUDSGMedium);
  w_BtagDown = wtbtagMedium-sqrt(wtbtagErrBCMedium*wtbtagErrBCMedium+wtbtagErrUDSGMedium*wtbtagErrUDSGMedium);
  w_Btag1Up   = wtbtagMedium+sqrt(wtbtagErrBCMedium*wtbtagErrBCMedium);
  w_Btag1Down = wtbtagMedium-sqrt(wtbtagErrBCMedium*wtbtagErrBCMedium);
  w_Btag2Up   = wtbtagMedium+sqrt(wtbtagErrUDSGMedium*wtbtagErrUDSGMedium);
  w_Btag2Down = wtbtagMedium-sqrt(wtbtagErrUDSGMedium*wtbtagErrUDSGMedium);
  w_BtagLoose     = wtbtagLoose; 
  w_BtagLooseUp   = wtbtagLoose+sqrt(wtbtagErrBCLoose*wtbtagErrBCLoose+wtbtagErrUDSGLoose*wtbtagErrUDSGLoose);
  w_BtagLooseDown = wtbtagLoose-sqrt(wtbtagErrBCLoose*wtbtagErrBCLoose+wtbtagErrUDSGLoose*wtbtagErrUDSGLoose);
  if(selection==2){
    w_Btag     = wtbtagLoose; 
    w_BtagUp   = wtbtagLoose+sqrt(wtbtagErrBCLoose*wtbtagErrBCLoose+wtbtagErrUDSGLoose*wtbtagErrUDSGLoose);
    w_BtagDown = wtbtagLoose-sqrt(wtbtagErrBCLoose*wtbtagErrBCLoose+wtbtagErrUDSGLoose*wtbtagErrUDSGLoose);
    w_Btag1Up   = wtbtagLoose+sqrt(wtbtagErrBCLoose*wtbtagErrBCLoose);
    w_Btag1Down = wtbtagLoose-sqrt(wtbtagErrBCLoose*wtbtagErrBCLoose);
    w_Btag2Up   = wtbtagLoose+sqrt(wtbtagErrUDSGLoose*wtbtagErrUDSGLoose);
    w_Btag2Down = wtbtagLoose-sqrt(wtbtagErrUDSGLoose*wtbtagErrUDSGLoose);
  }
  //cout<<"BTAG WEIGHT  "<<wtbtagErrBC<<" "<<wtbtagErrUDSG<<" "<<w_Btag<<" "<<w_BtagUp<<" "<<endl;
  delete fileBTagEfficiency;
}

/*void ForwardJetSF(vector<TLorentzVector> SelectedForwardJets, float &w_for_, float &w_forUp_, float &w_forDown_){
  if(SelectedForwardJets.size()>0){
    float eta = eta = SelectedForwardJets[0].Eta(); float pt = SelectedForwardJets[0].Pt();
    int X1=-99; int Y1=-99;
    for(int i=1; i<histoForwardJet->GetXaxis()->GetNbins()+2; i++){
      if(eta<histoForwardJet->GetXaxis()->GetBinLowEdge(i)){ X1=i-1; break; }
    }
    for(int i=1; i<histoForwardJet->GetYaxis()->GetNbins()+2; i++){
      if(pt <histoForwardJet->GetYaxis()->GetBinLowEdge(i)){ Y1=i-1; break; }
    }
    if(pt>=histoForwardJet->GetYaxis()->GetBinLowEdge(histoForwardJet->GetYaxis()->GetNbins()+1)) {Y1=(histoForwardJet->GetYaxis()->GetNbins()+1)-1;}
    float SF = histoForwardJet->GetBinContent(X1,Y1);
    w_for_     = SF;
    w_forUp_   = SF + histoForwardJet->GetBinError(X1,Y1); //w_forUp_   = 1.0;
    w_forDown_ = SF - histoForwardJet->GetBinError(X1,Y1); //w_forDown_ = 1.0;
  }
}*/

void TopSF(TLorentzVector SelectedTopJets, bool FullyMerged, float &w_topJet_, float &w_topJetUp_, float &w_topJetDown_){
  if(FullyMerged){
    if(SelectedTopJets.Pt()< 550) w_topJet_     = 1.06;
    if(SelectedTopJets.Pt()>=550) w_topJet_     = 1.06;
    if(SelectedTopJets.Pt()< 550) w_topJetUp_   = 1.06+0.09;
    if(SelectedTopJets.Pt()>=550) w_topJetUp_   = 1.06+0.09;
    if(SelectedTopJets.Pt()< 550) w_topJetDown_ = 1.06-0.04;
    if(SelectedTopJets.Pt()>=550) w_topJetDown_ = 1.06-0.04;
  }
}

void WSF(TLorentzVector WJet, bool PartiallyMerged, float &w_WJet_, float &w_WJetUp_, float &w_WJetDown_, int CA8Index, int SysJes, int SysJer){
  if(PartiallyMerged){
    bool matched = false;
    GenWBoson(matched, WJet);
    if(matched){
      w_WJet_     = 1.00*1.23*1.11;
      if(SysJes==1) w_WJet_ = 1.00*1.23*1.11 + sqrt(pow(Jet_JesSFup_->at(CA8Index)/Jet_JesSF_->at(CA8Index)-1  ,2) + 0.023*0.023);
      if(SysJes==2) w_WJet_ = 1.00*1.23*1.11 - sqrt(pow(1-Jet_JesSFdown_->at(CA8Index)/Jet_JesSF_->at(CA8Index),2) + 0.023*0.023);
      if(SysJer==1) w_WJet_ = 1.00*1.23*1.11 + sqrt(pow(Jet_JerSFup_->at(CA8Index)/Jet_JerSF_->at(CA8Index)-1  ,2) + 0.018*0.018);
      if(SysJer==2) w_WJet_ = 1.00*1.23*1.11 - sqrt(pow(1-Jet_JerSFdown_->at(CA8Index)/Jet_JerSF_->at(CA8Index),2) + 0.018*0.018);
      w_WJetUp_   = 1.00*1.23*1.11 + (0.08);
      w_WJetDown_ = 1.00*1.23*1.11 - (0.08);
      if(WJet.Pt()>200){
        w_WJetUp_   = 1.00*1.23*1.11 + (0.08 + 0.054*log(WJet.Pt()/200));
        w_WJetDown_ = 1.00*1.23*1.11 - (0.08 + 0.054*log(WJet.Pt()/200));
      }
    }
  }
}

void HTSF(string fileName, float HT, float &w_SF1, float &w_SF1Up, float &w_SF1Down, float &w_SF2, float &w_SF2Up, float &w_SF2Down, float &w_SF3, float &w_SF3Up, float &w_SF3Down){
  if(fileName.find("ZToNuNu")!=string::npos ){	
	if(200<HT&&HT<300)  {w_SF1 = histoSF1->GetBinContent(1); w_SF1Up = histoSF1->GetBinContent(1)+ histoSF1->GetBinError(1); w_SF1Down = TMath::Max(0.,histoSF1->GetBinContent(1)- histoSF1->GetBinError(1));}
	if(300<HT&&HT<400)  {w_SF1 = histoSF1->GetBinContent(2); w_SF1Up = histoSF1->GetBinContent(2)+ histoSF1->GetBinError(2); w_SF1Down = TMath::Max(0.,histoSF1->GetBinContent(2)- histoSF1->GetBinError(2));}
	if(400<HT&&HT<500)  {w_SF1 = histoSF1->GetBinContent(3); w_SF1Up = histoSF1->GetBinContent(3)+ histoSF1->GetBinError(3); w_SF1Down = TMath::Max(0.,histoSF1->GetBinContent(3)- histoSF1->GetBinError(3));}
	if(500<HT&&HT<600)  {w_SF1 = histoSF1->GetBinContent(4); w_SF1Up = histoSF1->GetBinContent(4)+ histoSF1->GetBinError(4); w_SF1Down = TMath::Max(0.,histoSF1->GetBinContent(4)- histoSF1->GetBinError(4));}
	if(600<HT&&HT<700)  {w_SF1 = histoSF1->GetBinContent(5); w_SF1Up = histoSF1->GetBinContent(5)+ histoSF1->GetBinError(5); w_SF1Down = TMath::Max(0.,histoSF1->GetBinContent(5)- histoSF1->GetBinError(5));}
	if(700<HT&&HT<800)  {w_SF1 = histoSF1->GetBinContent(6); w_SF1Up = histoSF1->GetBinContent(6)+ histoSF1->GetBinError(6); w_SF1Down = TMath::Max(0.,histoSF1->GetBinContent(6)- histoSF1->GetBinError(6));}
	if(800<HT&&HT<1000) {w_SF1 = histoSF1->GetBinContent(7); w_SF1Up = histoSF1->GetBinContent(7)+ histoSF1->GetBinError(7); w_SF1Down = TMath::Max(0.,histoSF1->GetBinContent(7)- histoSF1->GetBinError(7));}
	if(1000<HT&&HT<1200){w_SF1 = histoSF1->GetBinContent(8); w_SF1Up = histoSF1->GetBinContent(8)+ histoSF1->GetBinError(8); w_SF1Down = TMath::Max(0.,histoSF1->GetBinContent(8)- histoSF1->GetBinError(8));}
	if(1200<HT&&HT<1400){w_SF1 = histoSF1->GetBinContent(9); w_SF1Up = histoSF1->GetBinContent(9)+ histoSF1->GetBinError(9); w_SF1Down = TMath::Max(0.,histoSF1->GetBinContent(9)- histoSF1->GetBinError(9));}
	if(1400<HT&&HT<1700){w_SF1 = histoSF1->GetBinContent(10); w_SF1Up = histoSF1->GetBinContent(10)+ histoSF1->GetBinError(10); w_SF1Down = TMath::Max(0.,histoSF1->GetBinContent(10)- histoSF1->GetBinError(10));}
	if(1700<HT&&HT<2500){w_SF1 = histoSF1->GetBinContent(11); w_SF1Up = histoSF1->GetBinContent(11)+ histoSF1->GetBinError(11); w_SF1Down = TMath::Max(0.,histoSF1->GetBinContent(11)- histoSF1->GetBinError(11));}
  }
  if(fileName.find("WToLNu")!=string::npos ){	
	if(200<HT&&HT<300)  {w_SF2 = histoSF2->GetBinContent(1); w_SF2Up = histoSF2->GetBinContent(1)+ histoSF2->GetBinError(1); w_SF2Down = TMath::Max(0.,histoSF2->GetBinContent(1)- histoSF2->GetBinError(1));}
	if(300<HT&&HT<400)  {w_SF2 = histoSF2->GetBinContent(2); w_SF2Up = histoSF2->GetBinContent(2)+ histoSF2->GetBinError(2); w_SF2Down = TMath::Max(0.,histoSF2->GetBinContent(2)- histoSF2->GetBinError(2));}
	if(400<HT&&HT<500)  {w_SF2 = histoSF2->GetBinContent(3); w_SF2Up = histoSF2->GetBinContent(3)+ histoSF2->GetBinError(3); w_SF2Down = TMath::Max(0.,histoSF2->GetBinContent(3)- histoSF2->GetBinError(3));}
	if(500<HT&&HT<600)  {w_SF2 = histoSF2->GetBinContent(4); w_SF2Up = histoSF2->GetBinContent(4)+ histoSF2->GetBinError(4); w_SF2Down = TMath::Max(0.,histoSF2->GetBinContent(4)- histoSF2->GetBinError(4));}
	if(600<HT&&HT<700)  {w_SF2 = histoSF2->GetBinContent(5); w_SF2Up = histoSF2->GetBinContent(5)+ histoSF2->GetBinError(5); w_SF2Down = TMath::Max(0.,histoSF2->GetBinContent(5)- histoSF2->GetBinError(5));}
	if(700<HT&&HT<800)  {w_SF2 = histoSF2->GetBinContent(6); w_SF2Up = histoSF2->GetBinContent(6)+ histoSF2->GetBinError(6); w_SF2Down = TMath::Max(0.,histoSF2->GetBinContent(6)- histoSF2->GetBinError(6));}
	if(800<HT&&HT<1000) {w_SF2 = histoSF2->GetBinContent(7); w_SF2Up = histoSF2->GetBinContent(7)+ histoSF2->GetBinError(7); w_SF2Down = TMath::Max(0.,histoSF2->GetBinContent(7)- histoSF2->GetBinError(7));}
	if(1000<HT&&HT<1200){w_SF2 = histoSF2->GetBinContent(8); w_SF2Up = histoSF2->GetBinContent(8)+ histoSF2->GetBinError(8); w_SF2Down = TMath::Max(0.,histoSF2->GetBinContent(8)- histoSF2->GetBinError(8));}
	if(1200<HT&&HT<1400){w_SF2 = histoSF2->GetBinContent(9); w_SF2Up = histoSF2->GetBinContent(9)+ histoSF2->GetBinError(9); w_SF2Down = TMath::Max(0.,histoSF2->GetBinContent(9)- histoSF2->GetBinError(9));}
	if(1400<HT&&HT<1700){w_SF2 = histoSF2->GetBinContent(10); w_SF2Up = histoSF2->GetBinContent(10)+ histoSF2->GetBinError(10); w_SF2Down = TMath::Max(0.,histoSF2->GetBinContent(10)- histoSF2->GetBinError(10));}
	if(1700<HT&&HT<2500){w_SF2 = histoSF2->GetBinContent(11); w_SF2Up = histoSF2->GetBinContent(11)+ histoSF2->GetBinError(11); w_SF2Down = TMath::Max(0.,histoSF2->GetBinContent(11)- histoSF2->GetBinError(11));}
  }
   if(fileName.find("TT.root")!=string::npos ){	
	if(200<HT&&HT<300)  {w_SF3 = histoSF3->GetBinContent(1); w_SF3Up = histoSF3->GetBinContent(1)+ histoSF3->GetBinError(1); w_SF3Down = TMath::Max(0.,histoSF3->GetBinContent(1)- histoSF3->GetBinError(1));}
	if(300<HT&&HT<400)  {w_SF3 = histoSF3->GetBinContent(2); w_SF3Up = histoSF3->GetBinContent(2)+ histoSF3->GetBinError(2); w_SF3Down = TMath::Max(0.,histoSF3->GetBinContent(2)- histoSF3->GetBinError(2));}
	if(400<HT&&HT<500)  {w_SF3 = histoSF3->GetBinContent(3); w_SF3Up = histoSF3->GetBinContent(3)+ histoSF3->GetBinError(3); w_SF3Down = TMath::Max(0.,histoSF3->GetBinContent(3)- histoSF3->GetBinError(3));}
	if(500<HT&&HT<600)  {w_SF3 = histoSF3->GetBinContent(4); w_SF3Up = histoSF3->GetBinContent(4)+ histoSF3->GetBinError(4); w_SF3Down = TMath::Max(0.,histoSF3->GetBinContent(4)- histoSF3->GetBinError(4));}
	if(600<HT&&HT<700)  {w_SF3 = histoSF3->GetBinContent(5); w_SF3Up = histoSF3->GetBinContent(5)+ histoSF3->GetBinError(5); w_SF3Down = TMath::Max(0.,histoSF3->GetBinContent(5)- histoSF3->GetBinError(5));}
	if(700<HT&&HT<800)  {w_SF3 = histoSF3->GetBinContent(6); w_SF3Up = histoSF3->GetBinContent(6)+ histoSF3->GetBinError(6); w_SF3Down = TMath::Max(0.,histoSF3->GetBinContent(6)- histoSF3->GetBinError(6));}
	if(800<HT&&HT<1000) {w_SF3 = histoSF3->GetBinContent(7); w_SF3Up = histoSF3->GetBinContent(7)+ histoSF3->GetBinError(7); w_SF3Down = TMath::Max(0.,histoSF3->GetBinContent(7)- histoSF3->GetBinError(7));}
	if(1000<HT&&HT<1200){w_SF3 = histoSF3->GetBinContent(8); w_SF3Up = histoSF3->GetBinContent(8)+ histoSF3->GetBinError(8); w_SF3Down = TMath::Max(0.,histoSF3->GetBinContent(8)- histoSF3->GetBinError(8));}
	if(1200<HT&&HT<1400){w_SF3 = histoSF3->GetBinContent(9); w_SF3Up = histoSF3->GetBinContent(9)+ histoSF3->GetBinError(9); w_SF3Down = TMath::Max(0.,histoSF3->GetBinContent(9)- histoSF3->GetBinError(9));}
	if(1400<HT&&HT<1700){w_SF3 = histoSF3->GetBinContent(10); w_SF3Up = histoSF3->GetBinContent(10)+ histoSF3->GetBinError(10); w_SF3Down = TMath::Max(0.,histoSF3->GetBinContent(10)- histoSF3->GetBinError(10));}
	if(1700<HT&&HT<2500){w_SF3 = histoSF3->GetBinContent(11); w_SF3Up = histoSF3->GetBinContent(11)+ histoSF3->GetBinError(11); w_SF3Down = TMath::Max(0.,histoSF3->GetBinContent(11)- histoSF3->GetBinError(11));}
  }

}

float DeltaR(float eta1, float eta2, float phi1, float phi2){
  float deltaPhi = TMath::Abs(phi1-phi2);
  float deltaEta = eta1-eta2;
  if(deltaPhi > TMath::Pi()) deltaPhi = TMath::TwoPi() - deltaPhi;
  return TMath::Sqrt(deltaEta*deltaEta + deltaPhi*deltaPhi);
}

float DeltaPhi(float phi1, float phi2){
  float deltaPhi = TMath::Abs(phi1-phi2);
  if(deltaPhi > TMath::Pi()) deltaPhi = TMath::TwoPi() - deltaPhi;
  return deltaPhi;
}

float HTcalculator(vector<TLorentzVector> SelectedJets){
  float HTprov=0;
  for (UInt_t j = 0; j < SelectedJets.size(); ++j){
    HTprov=HTprov+SelectedJets[j].Pt();
  }
  return HTprov;
}

void branch(bool data, TTree *NewTree,TTree *NewTreeSB, string fileName){
  Tree->SetBranchAddress("Jet_pt",   &Jet_pt_,   &b_Jet_pt);
  Tree->SetBranchAddress("Jet_eta",  &Jet_eta_,  &b_Jet_eta);
  Tree->SetBranchAddress("Jet_phi",  &Jet_phi_,  &b_Jet_phi);
  Tree->SetBranchAddress("Jet_mass", &Jet_mass_, &b_Jet_mass);
  Tree->SetBranchAddress("Jet_JesSF",&Jet_JesSF_,&b_Jet_JesSF);
  Tree->SetBranchAddress("Jet_JesSFup",&Jet_JesSFup_,&b_Jet_JesSFup);
  Tree->SetBranchAddress("Jet_JesSFdown",&Jet_JesSFdown_,&b_Jet_JesSFdown);
  Tree->SetBranchAddress("Jet_JerSF",&Jet_JerSF_,&b_Jet_JerSF);
  Tree->SetBranchAddress("Jet_JerSFup",&Jet_JerSFup_,&b_Jet_JerSFup);
  Tree->SetBranchAddress("Jet_JerSFdown",&Jet_JerSFdown_,&b_Jet_JerSFdown);
  Tree->SetBranchAddress("Jet_Uncorr_pt",   &Jet_Uncorr_pt_,   &b_Jet_Uncorr_pt);
  Tree->SetBranchAddress("Jet_pfCombinedInclusiveSecondaryVertexV2BJetTags", &Jet_pfCombinedInclusiveSecondaryVertexV2BJetTags_, &b_Jet_pfCombinedInclusiveSecondaryVertexV2BJetTags);
  Tree->SetBranchAddress("Jet_pfDeepCSVBJetTags", &Jet_pfDeepCSVBJetTags_, &b_Jet_pfDeepCSVBJetTags);
  Tree->SetBranchAddress("Jet_neutralHadEnergyFraction", &Jet_neutralHadEnergyFraction_, &b_Jet_neutralHadEnergyFraction);
  Tree->SetBranchAddress("Jet_chargedEmEnergyFraction", &Jet_chargedEmEnergyFraction_, &b_Jet_chargedEmEnergyFraction);
  Tree->SetBranchAddress("Jet_neutralEmEnergyFraction", &Jet_neutralEmEnergyFraction_, &b_Jet_neutralEmEnergyFraction);
  Tree->SetBranchAddress("Jet_numberOfConstituents", &Jet_numberOfConstituents_, &b_Jet_numberOfConstituents);
  Tree->SetBranchAddress("Jet_chargedHadronEnergyFraction", &Jet_chargedHadronEnergyFraction_, &b_Jet_chargedHadronEnergyFraction);
  Tree->SetBranchAddress("Jet_chargedMultiplicity", &Jet_chargedMultiplicity_, &b_Jet_chargedMultiplicity);
  if(!data) Tree->SetBranchAddress("Jet_hadronFlavour", &Jet_hadronFlavour_, &b_Jet_hadronFlavour);
  Tree->SetBranchAddress("BoostedJet_pt",   &BoostedJet_pt_,   &b_BoostedJet_pt);
  Tree->SetBranchAddress("BoostedJet_Uncorr_pt",   &BoostedJet_Uncorr_pt_,   &b_BoostedJet_Uncorr_pt);
  Tree->SetBranchAddress("BoostedJet_softdrop_mass",   &BoostedJet_softdrop_mass_,   &b_BoostedJet_softdrop_mass);
  Tree->SetBranchAddress("BoostedJet_JesSF",&BoostedJet_JesSF_,&b_BoostedJet_JesSF);
  Tree->SetBranchAddress("BoostedJet_JesSFup",&BoostedJet_JesSFup_,&b_BoostedJet_JesSFup);
  Tree->SetBranchAddress("BoostedJet_JesSFdown",&BoostedJet_JesSFdown_,&b_BoostedJet_JesSFdown);
  Tree->SetBranchAddress("BoostedJet_JerSF",&BoostedJet_JerSF_,&b_BoostedJet_JerSF);
  Tree->SetBranchAddress("BoostedJet_JerSFup",&BoostedJet_JerSFup_,&b_BoostedJet_JerSFup);
  Tree->SetBranchAddress("BoostedJet_JerSFdown",&BoostedJet_JerSFdown_,&b_BoostedJet_JerSFdown);
  Tree->SetBranchAddress("BoostedJet_eta",  &BoostedJet_eta_,  &b_BoostedJet_eta);
  Tree->SetBranchAddress("BoostedJet_phi",  &BoostedJet_phi_,  &b_BoostedJet_phi);
  Tree->SetBranchAddress("BoostedJet_mass", &BoostedJet_mass_, &b_BoostedJet_mass);
  Tree->SetBranchAddress("BoostedJet_neutralHadEnergyFraction", &BoostedJet_neutralHadEnergyFraction_, &b_BoostedJet_neutralHadEnergyFraction);
  Tree->SetBranchAddress("BoostedJet_neutralEmEnergyFraction", &BoostedJet_neutralEmEnergyFraction_, &b_BoostedJet_neutralEmEnergyFraction);
  Tree->SetBranchAddress("BoostedJet_chargedEmEnergyFraction", &BoostedJet_chargedEmEnergyFraction_, &b_BoostedJet_chargedEmEnergyFraction);
  //Tree->SetBranchAddress("BoostedJet_neutralEmEmEnergyFraction", &BoostedJet_neutralEmEmEnergyFraction_, &b_BoostedJet_neutralEmEmEnergyFraction);
  Tree->SetBranchAddress("BoostedJet_numberOfConstituents", &BoostedJet_numberOfConstituents_, &b_BoostedJet_numberOfConstituents);
  Tree->SetBranchAddress("BoostedJet_chargedHadronEnergyFraction", &BoostedJet_chargedHadronEnergyFraction_, &b_BoostedJet_chargedHadronEnergyFraction);
  Tree->SetBranchAddress("BoostedJet_chargedMultiplicity", &BoostedJet_chargedMultiplicity_, &b_BoostedJet_chargedMultiplicity);
  Tree->SetBranchAddress("BoostedJet_tau1",         &BoostedJet_tau1_,         &b_BoostedJet_tau1);
  Tree->SetBranchAddress("BoostedJet_tau2",         &BoostedJet_tau2_,         &b_BoostedJet_tau2);
  Tree->SetBranchAddress("BoostedJet_tau3",         &BoostedJet_tau3_,         &b_BoostedJet_tau3);
  Tree->SetBranchAddress("BoostedJet_pruned_mass",  &BoostedJet_pruned_mass_,  &b_BoostedJet_pruned_mass);
  //Tree->SetBranchAddress("TopTagging_topMass",      &TopTagging_topMass_,      &b_TopTagging_topMass);
  //Tree->SetBranchAddress("TopTagging_minMass",      &TopTagging_minMass_,      &b_TopTagging_minMass);
  //Tree->SetBranchAddress("TopTagging_nSubJets",     &TopTagging_nSubJets_,     &b_TopTagging_nSubJets); 
  Tree->SetBranchAddress("patElectron_pt",&patElectron_pt_,&b_patElectron_pt);
  Tree->SetBranchAddress("patElectron_eta",&patElectron_eta_,&b_patElectron_eta);
  Tree->SetBranchAddress("patElectron_phi",&patElectron_phi_,&b_patElectron_phi);
  Tree->SetBranchAddress("patElectron_energy",&patElectron_energy_,&b_patElectron_energy);
  //Tree->SetBranchAddress("patElectron_energyCorr",&patElectron_energyCorr_,&b_patElectron_energyCorr);
  Tree->SetBranchAddress("patElectron_SCeta",&patElectron_SCeta_,&b_patElectron_SCeta);
  Tree->SetBranchAddress("patElectron_charge",&patElectron_charge_,&b_patElectron_charge);
  Tree->SetBranchAddress("patElectron_isPassVeto",&patElectron_isPassVeto_,&b_patElectron_isPassVeto);          
  Tree->SetBranchAddress("patElectron_isPassLoose",&patElectron_isPassLoose_,&b_patElectron_isPassLoose);
  Tree->SetBranchAddress("patElectron_isPassMedium",&patElectron_isPassMedium_,&b_patElectron_isPassMedium);
  Tree->SetBranchAddress("patElectron_isPassTight",&patElectron_isPassTight_,&b_patElectron_isPassTight);
  Tree->SetBranchAddress("patElectron_isPassHEEPId",&patElectron_isPassHEEPId_,&b_patElectron_isPassHEEPId);
  Tree->SetBranchAddress("patElectron_passConversionVeto",&patElectron_passConversionVeto_,&b_patElectron_passConversionVeto); 
  Tree->SetBranchAddress("patElectron_inCrack",&patElectron_inCrack_,&b_patElectron_inCrack);
  Tree->SetBranchAddress("patElectron_isMatchedToTrigger",&patElectron_isMatchedToTrigger_,&b_patElectron_isMatchedToTrigger);
  Tree->SetBranchAddress("Muon_pt",&Muon_pt_,&b_Muon_pt);
  Tree->SetBranchAddress("Muon_eta",&Muon_eta_,&b_Muon_eta);
  Tree->SetBranchAddress("Muon_phi",&Muon_phi_,&b_Muon_phi);
  Tree->SetBranchAddress("Muon_energy",&Muon_energy_,&b_Muon_energy);
  Tree->SetBranchAddress("Muon_charge",&Muon_charge_,&b_Muon_charge);
  Tree->SetBranchAddress("Muon_tight",&Muon_tight_,&b_Muon_tight);
  Tree->SetBranchAddress("Muon_medium",&Muon_medium_,&b_Muon_medium);
  Tree->SetBranchAddress("Muon_loose",&Muon_loose_,&b_Muon_loose);
  Tree->SetBranchAddress("Met_type1PF_pt",          &Met_type1PF_pt_,          &b_Met_type1PF_pt);
  Tree->SetBranchAddress("Met_type1PF_phi",         &Met_type1PF_phi_,         &b_Met_type1PF_phi);
  Tree->SetBranchAddress("Met_type1PF_sumEt",         &Met_type1PF_sumEt_,         &b_Met_type1PF_sumEt);
  Tree->SetBranchAddress("Muon_relIsoDeltaBetaR04",&Muon_relIsoDeltaBetaR04_,&b_Muon_relIsoDeltaBetaR04);
  Tree->SetBranchAddress("Muon_isMatchedToTrigger",&Muon_isMatchedToTrigger_,&b_Muon_isMatchedToTrigger);
  Tree->SetBranchAddress("Flag_goodVertices",&Flag_goodVertices_,&b_Flag_goodVertices);
  Tree->SetBranchAddress("Flag_globalSuperTightHalo2016Filter",&Flag_globalSuperTightHalo2016Filter_,&b_Flag_globalSuperTightHalo2016Filter);
  //Tree->SetBranchAddress("Flag_CSCTightHalo2015Filter",&Flag_CSCTightHalo2015Filter_,&b_Flag_CSCTightHalo2015Filter);
  Tree->SetBranchAddress("Flag_HBHENoiseFilter",&Flag_HBHENoiseFilter_,&b_Flag_HBHENoiseFilter);
  Tree->SetBranchAddress("Flag_HBHENoiseIsoFilter",&Flag_HBHENoiseIsoFilter_,&b_Flag_HBHENoiseIsoFilter);
  Tree->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter",&Flag_EcalDeadCellTriggerPrimitiveFilter_,&b_Flag_EcalDeadCellTriggerPrimitiveFilter);
  Tree->SetBranchAddress("Flag_BadPFMuonFilter",&Flag_BadPFMuonFilter_,&b_Flag_BadPFMuonFilter);
  Tree->SetBranchAddress("Flag_BadChargedCandidateFilter",&Flag_BadChargedCandidateFilter_,&b_Flag_BadChargedCandidateFilter);
  //Tree->SetBranchAddress("Flag_ecalBadCalibReducedMINIAODFilter",&Flag_ecalBadCalibReducedMINIAODFilter_,&b_Flag_ecalBadCalibReducedMINIAODFilter);
  Tree->SetBranchAddress("Flag_eeBadScFilter",&Flag_eeBadScFilter_,&b_Flag_eeBadScFilter);
  Tree->SetBranchAddress("HLT_DoubleEle33_CaloIdL_MW",&HLT_DoubleEle33_CaloIdL_MW_,&b_HLT_DoubleEle33_CaloIdL_MW);
  Tree->SetBranchAddress("HLT_Mu50",&HLT_Mu50_,&b_HLT_Mu50);
  Tree->SetBranchAddress("HLT_TkMu50",&HLT_TkMu50_,&b_HLT_TkMu50);
  //Tree->SetBranchAddress("HLT_PFHT500_PFMET100_PFMHT100_IDTight", &HLT_PFHT500_PFMET100_PFMHT100_IDTight_, &b_HLT_PFHT500_PFMET100_PFMHT100_IDTight);
  //Tree->SetBranchAddress("HLT_PFHT700_PFMET85_PFMHT85_IDTight", &HLT_PFHT700_PFMET85_PFMHT85_IDTight_, &b_HLT_PFHT700_PFMET85_PFMHT85_IDTight);
  //Tree->SetBranchAddress("HLT_PFHT800_PFMET75_PFMHT75_IDTight", &HLT_PFHT800_PFMET75_PFMHT75_IDTight_, &b_HLT_PFHT800_PFMET75_PFMHT75_IDTight);
  Tree->SetBranchAddress("HLT_PFMET120_PFMHT120_IDTight", &HLT_PFMET120_PFMHT120_IDTight_, &b_HLT_PFMET120_PFMHT120_IDTight);
  Tree->SetBranchAddress("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_, &b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight);
  //Tree->SetBranchAddress("HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight", &HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight_,  &b_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight);
  //Tree->SetBranchAddress("HLT_CaloJet500_NoJetID", &HLT_CaloJet500_NoJetID_, &b_HLT_CaloJet500_NoJetID);
  //Tree->SetBranchAddress("HLT_AK8PFJet500", &HLT_AK8PFJet500_,   &b_HLT_AK8PFJet500);
  //Tree->SetBranchAddress("HLT_PFJet500", &HLT_PFJet500_,         &b_HLT_PFJet500);
  //Tree->SetBranchAddress("HLT_PFHT1050", &HLT_PFHT1050_,         &b_HLT_PFHT1050);
  Tree->SetBranchAddress("nBestVtx",&nBestVtx_,&b_nBestVtx);
  Tree->SetBranchAddress("PUWeight",&PUWeight_,&b_PUWeight);
  //Tree->SetBranchAddress("PUWeightUP",&PUWeightUP_,&b_PUWeightUP);
  //Tree->SetBranchAddress("PUWeightDOWN",&PUWeightDOWN_,&b_PUWeightDOWN);
  //Tree->SetBranchAddress("EVENT_event",&EVENT_event_,&b_EVENT_event);
  Tree->SetBranchAddress("EVENT_run",&EVENT_run_,&b_EVENT_run);
  Tree->SetBranchAddress("EVENT_lumiBlock",&EVENT_lumiBlock_,&b_EVENT_lumiBlock);
  Tree->SetBranchAddress("EVENT_genHT",&EVENT_genHT_,&b_EVENT_genHT);
  if(!data) Tree->SetBranchAddress("Gen_pt",&Gen_pt_,&b_Gen_pt);
  if(!data) Tree->SetBranchAddress("Gen_eta",&Gen_eta_,&b_Gen_eta);
  if(!data) Tree->SetBranchAddress("Gen_phi",&Gen_phi_,&b_Gen_phi);
  if(!data) Tree->SetBranchAddress("Gen_pdg_id",&Gen_pdg_id_,&b_Gen_pdg_id);
  if(!data) Tree->SetBranchAddress("Gen_motherpdg_id",&Gen_motherpdg_id_,&b_Gen_motherpdg_id);
  Tree->SetBranchAddress("EVENT_genWeight",&genWeight_,&b_genWeight);
  Tree->SetBranchAddress("EVENT_genWeights",&genWeights_,&b_genWeights);
  Tree->SetBranchAddress("EVENT_prefiringweight",&EVENT_prefiringweight_,&b_EVENT_prefiringweight);
  Tree->SetBranchAddress("EVENT_prefiringweightup",&EVENT_prefiringweightup_,&b_EVENT_prefiringweightup);
  Tree->SetBranchAddress("EVENT_prefiringweightdown",&EVENT_prefiringweightdown_,&b_EVENT_prefiringweightdown);

  NewTree->Branch("category0",         &category0,         "category0/I"         );
  NewTree->Branch("category1",         &category1,         "category1/I"         );
  NewTree->Branch("category2",         &category2,         "category2/I"         );
  NewTree->Branch("TopMass",           &TopMass,           "TopMass/F"           );
  NewTree->Branch("TopMassMerged",     &TopMassMerged,     "TopMassMerged/F"     );
  NewTree->Branch("TopMassPartial",    &TopMassPartial,    "TopMassPartial/F"    );
  NewTree->Branch("TopMassResolved",   &TopMassResolved,   "TopMassResolved/F"   );
  NewTree->Branch("TopPt",             &TopPt,             "TopPt/F"             );
  NewTree->Branch("TopPtMerged",       &TopPtMerged,       "TopPtMerged/F"       );
  NewTree->Branch("TopPtPartial",      &TopPtPartial,      "TopPtPartial/F"      );
  NewTree->Branch("TopPtResolved",     &TopPtResolved,     "TopPtResolved/F"     );
  NewTree->Branch("TopEta",            &TopEta,            "TopEta/F"            );
  NewTree->Branch("TopEtaMerged",      &TopEtaMerged,      "TopEtaMerged/F"      );
  NewTree->Branch("TopEtaPartial",     &TopEtaPartial,     "TopEtaPartial/F"     );
  NewTree->Branch("TopEtaResolved",    &TopEtaResolved,    "TopEtaResolved/F"    );
  NewTree->Branch("TopPhi",            &TopPhi,            "TopPhi/F"            );
  NewTree->Branch("TopPhiMerged",      &TopPhiMerged,      "TopPhiMerged/F"      );
  NewTree->Branch("TopPhiPartial",     &TopPhiPartial,     "TopPhiPartial/F"     );
  NewTree->Branch("TopPhiResolved",    &TopPhiResolved,    "TopPhiResolved/F"    );
  NewTree->Branch("WMassResolved1",    &WMassResolved1,    "WMassResolved1/F"    );
  NewTree->Branch("WMassResolved2",    &WMassResolved2,    "WMassResolved2/F"    );
  NewTree->Branch("WMassResolved3",    &WMassResolved3,    "WMassResolved3/F"    );
  NewTree->Branch("BMass",             &BMass,             "BMass/F"             );
  NewTree->Branch("BCSV",              &BCSV,              "BCSV/F"              );
  NewTree->Branch("BPt",               &BPt,               "BPt/F"               );
  NewTree->Branch("BEta",              &BEta,              "BEta/F"              );
  NewTree->Branch("BPhi",              &BPhi,              "BPhi/F"              );
  NewTree->Branch("ZMass",             &ZMass,             "ZMass/F"             );
  NewTree->Branch("ZPt",               &ZPt,               "ZPt/F"               );
  NewTree->Branch("ZEta",              &ZEta,              "ZEta/F"              );
  NewTree->Branch("ZPhi",              &ZPhi,              "ZPhi/F"              );
  NewTree->Branch("TprimeMass",        &TprimeMass,        "TprimeMass/F"        );
  NewTree->Branch("TprimePt",          &TprimePt,          "TprimePt/F"          );
  NewTree->Branch("TprimeEta",         &TprimeEta,         "TprimeEta/F"         );
  NewTree->Branch("TprimePhi",         &TprimePhi,         "TprimePhi/F"         );
  NewTree->Branch("TprimeResolvedMass",&TprimeResolvedMass,"TprimeResolvedMass/F");
  NewTree->Branch("TprimeResolvedPt",  &TprimeResolvedPt,  "TprimeResolvedPt/F"  );
  NewTree->Branch("TprimeResolvedEta", &TprimeResolvedEta, "TprimeResolvedEta/F" );
  NewTree->Branch("TprimeResolvedPhi", &TprimeResolvedPhi, "TprimeResolvedPhi/F" );
  NewTree->Branch("TprimePartialMass", &TprimePartialMass, "TprimePartialMass/F" );
  NewTree->Branch("TprimePartialPt",   &TprimePartialPt,   "TprimePartialPt/F"   );
  NewTree->Branch("TprimePartialEta",  &TprimePartialEta,  "TprimePartialEta/F"  );
  NewTree->Branch("TprimePartialPhi",  &TprimePartialPhi,  "TprimePartialPhi/F"  );
  NewTree->Branch("TprimeMergedMass",  &TprimeMergedMass,  "TprimeMergedMass/F"  );
  NewTree->Branch("TprimeMergedPt",    &TprimeMergedPt,    "TprimeMergedPt/F"    );
  NewTree->Branch("TprimeMergedEta",   &TprimeMergedEta,   "TprimeMergedEta/F"   );
  NewTree->Branch("TprimeMergedPhi",   &TprimeMergedPhi,   "TprimeMergedPhi/F"   );
  NewTree->Branch("Electron1Pt",       &Electron1Pt,       "Electron1Pt/F"       );
  NewTree->Branch("Electron2Pt",       &Electron2Pt,       "Electron2Pt/F"       );
  NewTree->Branch("Electron1E",        &Electron1E,        "Electron1E/F"        );
  NewTree->Branch("Electron2E",        &Electron2E,        "Electron2E/F"        );
  NewTree->Branch("Muon1Iso",          &Muon1Iso,          "Muon1Iso/F"          );
  NewTree->Branch("Muon2Iso",          &Muon2Iso,          "Muon2Iso/F"          );
  NewTree->Branch("Muon1Pt",           &Muon1Pt,           "Muon1Pt/F"           );
  NewTree->Branch("Muon2Pt",           &Muon2Pt,           "Muon2Pt/F"           );
  NewTree->Branch("Jet1ForwardEta",    &Jet1ForwardEta,    "Jet1ForwardEta/F"    );
  NewTree->Branch("Jet2ForwardEta",    &Jet2ForwardEta,    "Jet2ForwardEta/F"    );
  NewTree->Branch("Jet3ForwardEta",    &Jet3ForwardEta,    "Jet3ForwardEta/F"    );
  NewTree->Branch("Jet1ForwardPt",     &Jet1ForwardPt,     "Jet1ForwardPt/F"     );
  NewTree->Branch("Jet2ForwardPt",     &Jet2ForwardPt,     "Jet2ForwardPt/F"     );
  NewTree->Branch("Jet3ForwardPt",     &Jet3ForwardPt,     "Jet3ForwardPt/F"     );
  NewTree->Branch("Jet1ResolvedPt",    &Jet1ResolvedPt,    "Jet1ResolvedPt/F"    );
  NewTree->Branch("Jet2ResolvedPt",    &Jet2ResolvedPt,    "Jet2ResolvedPt/F"    );
  NewTree->Branch("Jet3ResolvedPt",    &Jet3ResolvedPt,    "Jet3ResolvedPt/F"    );
  NewTree->Branch("Jet1PartialPt",     &Jet1PartialPt,     "Jet1PartialPt/F"     );
  NewTree->Branch("Jet2PartialPt",     &Jet2PartialPt,     "Jet2PartialPt/F"     );
  NewTree->Branch("Jet1MergedPt",      &Jet1MergedPt,      "Jet1MergedPt/F"      );
  NewTree->Branch("Electron1Eta",      &Electron1Eta,      "Electron1Eta/F"      );
  NewTree->Branch("Electron2Eta",      &Electron2Eta,      "Electron2Eta/F"      );
  NewTree->Branch("Muon1Eta",          &Muon1Eta,          "Muon1Eta/F"          );
  NewTree->Branch("Muon2Eta",          &Muon2Eta,          "Muon2Eta/F"          );
  NewTree->Branch("Jet1ResolvedEta",   &Jet1ResolvedEta,   "Jet1ResolvedEta/F"   );
  NewTree->Branch("Jet2ResolvedEta",   &Jet2ResolvedEta,   "Jet2ResolvedEta/F"   );
  NewTree->Branch("Jet3ResolvedEta",   &Jet3ResolvedEta,   "Jet3ResolvedEta/F"   );
  NewTree->Branch("Jet1PartialEta",    &Jet1PartialEta,    "Jet1PartialEta/F"    );
  NewTree->Branch("Jet2PartialEta",    &Jet2PartialEta,    "Jet2PartialEta/F"    );
  NewTree->Branch("Jet1MergedEta",     &Jet1MergedEta,     "Jet1MergedEta/F"     );
  NewTree->Branch("MostForwardJetEta", &MostForwardJetEta, "MostForwardJetEta/F" );
  NewTree->Branch("MostForwardJetPt",  &MostForwardJetPt,  "MostForwardJetPt/F"  );
  NewTree->Branch("Electron1Phi",      &Electron1Phi,      "Electron1Phi/F"      );
  NewTree->Branch("Electron2Phi",      &Electron2Phi,      "Electron2Phi/F"      );
  NewTree->Branch("Muon1Phi",          &Muon1Phi,          "Muon1Phi/F"          );
  NewTree->Branch("Muon2Phi",          &Muon2Phi,          "Muon2Phi/F"          );
  NewTree->Branch("deltaPhiZTop",      &deltaPhiZTop,      "deltaPhiZTop/F"      );
  NewTree->Branch("deltaRZTop",        &deltaRZTop,        "deltaRZTop/F"        );
  NewTree->Branch("deltaPhiZB",        &deltaPhiZB,        "deltaPhiZB/F"        );
  NewTree->Branch("deltaRZB",          &deltaRZB,          "deltaRZB/F"          );
  NewTree->Branch("deltaREle1Ele2",    &deltaREle1Ele2,    "deltaREle1Ele2/F"    );
  NewTree->Branch("deltaRMuo1Muo2",    &deltaRMuo1Muo2,    "deltaRMuo1Muo2/F"    );
  NewTree->Branch("Massb1b2",          &Massb1b2,          "Massb1b2/F"          );
  NewTree->Branch("MinDeltaPhiJetMet", &MinDeltaPhiJetMet, "MinDeltaPhiJetMet/F" );
  NewTree->Branch("MinDeltaPhiBoostedJetMet", &MinDeltaPhiBoostedJetMet, "MinDeltaPhiBoostedJetMet/F" );
  NewTree->Branch("deltaRb1b2",        &deltaRb1b2,        "deltaRb1b2/F"        );
  NewTree->Branch("deltaRb1Lep1",      &deltaRb1Lep1,      "deltaRb1Lep1/F"      );
  NewTree->Branch("deltaRb1Lep2",      &deltaRb1Lep2,      "deltaRb1Lep2/F"      );
  NewTree->Branch("deltaRb2Lep1",      &deltaRb2Lep1,      "deltaRb2Lep1/F"      );
  NewTree->Branch("deltaRb2Lep2",      &deltaRb2Lep2,      "deltaRb2Lep2/F"      );
  NewTree->Branch("NumSelLeps",        &NumSelLeps,        "NumSelLeps/I"        );
  NewTree->Branch("NumSelJets",        &NumSelJets,        "NumSelJets/I"        );
  NewTree->Branch("NumSelForwardJets", &NumSelForwardJets, "NumSelForwardJets/I" );
  NewTree->Branch("NumSelBJetsL",      &NumSelBJetsL,      "NumSelBJetsL/I"      );
  NewTree->Branch("NumSelBJetsM",      &NumSelBJetsM,      "NumSelBJetsM/I"      );
  NewTree->Branch("NumSelBJetsT",      &NumSelBJetsT,      "NumSelBJetsT/I"      );
  NewTree->Branch("NumSelWJets",       &NumSelWJets,       "NumSelWJets/I"       );
  NewTree->Branch("NumSelTopJets",     &NumSelTopJets,     "NumSelTopJets/I"     );
  NewTree->Branch("NVertices",         &NVertices,         "NVertices/I"         );
  NewTree->Branch("HT",                &HT,                "HT/F"                );
  NewTree->Branch("PUWeight",          &PUWeight,          "PUWeight/F"          );
  NewTree->Branch("PUWeightUP",        &PUWeightUP,        "PUWeightUP/F"        );
  NewTree->Branch("PUWeightDOWN",      &PUWeightDOWN,      "PUWeightDOWN/F"      );
  NewTree->Branch("getTrueNumInteractions",&getTrueNumInteractions,"getTrueNumInteractions/I");
  NewTree->Branch("w_for",             &w_for,             "w_for/F"             );
  NewTree->Branch("w_forUp",           &w_forUp,           "w_forUp/F"           );
  NewTree->Branch("w_forDown",         &w_forDown,         "w_forDown/F"         );
  NewTree->Branch("w_topJet",          &w_topJet,          "w_topJet/F"          );
  NewTree->Branch("w_topJetUp",        &w_topJetUp,        "w_topJetUp/F"        );
  NewTree->Branch("w_topJetDown",      &w_topJetDown,      "w_topJetDown/F"      );
  NewTree->Branch("w_WJet",            &w_WJet,            "w_WJet/F"            );
  NewTree->Branch("w_WJetUp",          &w_WJetUp,          "w_WJetUp/F"          );
  NewTree->Branch("w_WJetDown",        &w_WJetDown,        "w_WJetDown/F"        );
  NewTree->Branch("w_Muon1",           &w_Muon1,           "w_Muon1/F"           );
  NewTree->Branch("w_Muon2",           &w_Muon2,           "w_Muon2/F"           );
  NewTree->Branch("w_Muon1Up",         &w_Muon1Up,         "w_Muon1Up/F"         );
  NewTree->Branch("w_Muon2Up",         &w_Muon2Up,         "w_Muon2Up/F"         );
  NewTree->Branch("w_Muon1Down",       &w_Muon1Down,       "w_Muon1Down/F"       );
  NewTree->Branch("w_Muon2Down",       &w_Muon2Down,       "w_Muon2Down/F"       );
  NewTree->Branch("w_TrigMuon",        &w_TrigMuon,        "w_TrigMuon/F"        );
  NewTree->Branch("w_TrigMuonUp",      &w_TrigMuonUp,      "w_TrigMuonUp/F"      );
  NewTree->Branch("w_TrigMuonDown",    &w_TrigMuonDown,    "w_TrigMuonDown/F"    );
  NewTree->Branch("w_Electron1",       &w_Electron1,       "w_Electron1/F"       );
  NewTree->Branch("w_Electron2",       &w_Electron2,       "w_Electron2/F"       );
  NewTree->Branch("w_Electron1Up",     &w_Electron1Up,     "w_Electron1Up/F"     );
  NewTree->Branch("w_Electron2Up",     &w_Electron2Up,     "w_Electron2Up/F"     );
  NewTree->Branch("w_Electron1Down",   &w_Electron1Down,   "w_Electron1Down/F"   );
  NewTree->Branch("w_Electron2Down",   &w_Electron2Down,   "w_Electron2Down/F"   );
  NewTree->Branch("w_TrigElec",        &w_TrigElec,        "w_TrigElec/F"        );
  NewTree->Branch("w_TrigElecUp",      &w_TrigElecUp,      "w_TrigElecUp/F"      );
  NewTree->Branch("w_TrigElecDown",    &w_TrigElecDown,    "w_TrigElecDown/F"    );
  NewTree->Branch("w_ZToNuNu",         &w_ZToNuNu,         "w_ZToNuNu/F"         );
  NewTree->Branch("w_ZToNuNuUp",       &w_ZToNuNuUp,       "w_ZToNuNuUp/F"       );
  NewTree->Branch("w_ZToNuNuDown",     &w_ZToNuNuDown,     "w_ZToNuNuDown/F"     );
  NewTree->Branch("w_WToLNu",          &w_WToLNu,          "w_WToLNu/F"          );
  NewTree->Branch("w_WToLNuUp",        &w_WToLNuUp,        "w_WToLNuUp/F"        );
  NewTree->Branch("w_WToLNuDown",      &w_WToLNuDown,      "w_WToLNuDown/F"      );
  NewTree->Branch("w_ttbar",           &w_ttbar,           "w_ttbar/F"           );
  NewTree->Branch("w_ttbarUp",         &w_ttbarUp,         "w_ttbarUp/F"         );
  NewTree->Branch("w_ttbarDown",       &w_ttbarDown,       "w_ttbarDown/F"       );
  NewTree->Branch("WMass",             &WMass,             "WMass/F"             );
  NewTree->Branch("WSubjet",           &WSubjet,           "WSubjet/F"           );
  NewTree->Branch("TopSoftMass",       &TopSoftMass,       "TopSoftMass/F"       );
  NewTree->Branch("TopSubjet",         &TopSubjet,         "TopSubjet/F"         );
  NewTree->Branch("w_Btag",            &w_Btag,            "w_Btag/F"            );
  NewTree->Branch("w_BtagUp",          &w_BtagUp,          "w_BtagUp/F"          );
  NewTree->Branch("w_BtagDown",        &w_BtagDown,        "w_BtagDown/F"        );
  NewTree->Branch("w_Btag1Up",         &w_Btag1Up,         "w_Btag1Up/F"         );
  NewTree->Branch("w_Btag1Down",       &w_Btag1Down,       "w_Btag1Down/F"       );
  NewTree->Branch("w_Btag2Up",         &w_Btag2Up,         "w_Btag2Up/F"         );
  NewTree->Branch("w_Btag2Down",       &w_Btag2Down,       "w_Btag2Down/F"       );
  NewTree->Branch("w_BtagLoose",       &w_BtagLoose,       "w_BtagLoose/F"       );
  NewTree->Branch("w_BtagLooseUp",     &w_BtagLooseUp,     "w_BtagLooseUp/F"     );
  NewTree->Branch("w_BtagLooseDown",   &w_BtagLooseDown,   "w_BtagLooseDown/F"   );
  NewTree->Branch("w_QCDUp",           &w_QCDUp,           "w_QCDUp/F"   );
  NewTree->Branch("w_QCDDown",         &w_QCDDown,         "w_QCDDown/F"   );
  NewTree->Branch("w_PDFUp",           &w_PDFUp,           "w_PDFUp/F"   );
  NewTree->Branch("w_PDFDown",         &w_PDFDown,         "w_PDFDown/F"   );
  NewTree->Branch("deltaPhiZTopResolved", &deltaPhiZTopResolved, "deltaPhiZTopResolved/F");
  NewTree->Branch("deltaRZTopResolved",   &deltaRZTopResolved,   "deltaRZTopResolved/F"  );
  NewTree->Branch("deltaPhiZTopPartial",  &deltaPhiZTopPartial,  "deltaPhiZTopPartial/F" );
  NewTree->Branch("deltaRZTopPartial",    &deltaRZTopPartial,    "deltaRZTopPartial/F"   );
  NewTree->Branch("deltaPhiZTopMerged",   &deltaPhiZTopMerged,   "deltaPhiZTopMerged/F"  );
  NewTree->Branch("deltaRZTopMerged",     &deltaRZTopMerged,     "deltaRZTopMerged/F"    );
  NewTree->Branch("deltaRbTop",           &deltaRbTop,           "deltaRbTop/F"          );
  NewTree->Branch("deltaPhiMetTop",       &deltaPhiMetTop,       "deltaPhiMetTop/F"      );
  NewTree->Branch("genWeight",            &genWeight,            "genWeight/F"           );
  NewTree->Branch("genWeights0",          &genWeights0,          "genWeights0/F"         );
  NewTree->Branch("genWeights1",          &genWeights1,          "genWeights1/F"         );
  NewTree->Branch("genWeights2",          &genWeights2,          "genWeights2/F"         );
  NewTree->Branch("genWeights3",          &genWeights3,          "genWeights3/F"         );
  NewTree->Branch("genWeights4",          &genWeights4,          "genWeights4/F"         );
  NewTree->Branch("genWeights5",          &genWeights5,          "genWeights5/F"         );
  NewTree->Branch("genWeights6",          &genWeights6,          "genWeights6/F"         );
  NewTree->Branch("genWeights7",          &genWeights7,          "genWeights7/F"         );
  NewTree->Branch("genWeights8",          &genWeights8,          "genWeights8/F"         );
  NewTree->Branch("genWeights9",          &genWeights9,          "genWeights9/F"         );
  NewTree->Branch("genWeights10",         &genWeights10,         "genWeights10/F"        );
  NewTree->Branch("genWeights11",         &genWeights11,         "genWeights11/F"        );
  NewTree->Branch("genWeights12",         &genWeights12,         "genWeights12/F"        );
  NewTree->Branch("genWeights13",         &genWeights13,         "genWeights13/F"        );
  NewTree->Branch("genWeights14",         &genWeights14,         "genWeights14/F"        );
  NewTree->Branch("genWeights15",         &genWeights15,         "genWeights15/F"        );
  NewTree->Branch("genWeights16",         &genWeights16,         "genWeights16/F"        );
  NewTree->Branch("genWeights17",         &genWeights17,         "genWeights17/F"        );
  NewTree->Branch("genWeights18",         &genWeights18,         "genWeights18/F"        );
  NewTree->Branch("genWeights19",         &genWeights19,         "genWeights19/F"        );
  NewTree->Branch("genWeights20",         &genWeights20,         "genWeights20/F"        );
  NewTree->Branch("genWeights21",         &genWeights21,         "genWeights21/F"        );
  NewTree->Branch("genWeights22",         &genWeights22,         "genWeights22/F"        );
  NewTree->Branch("genWeights23",         &genWeights23,         "genWeights23/F"        );
  NewTree->Branch("genWeights24",         &genWeights24,         "genWeights24/F"        );
  NewTree->Branch("genWeights25",         &genWeights25,         "genWeights25/F"        );
  NewTree->Branch("genWeights26",         &genWeights26,         "genWeights26/F"        );
  NewTree->Branch("genWeights27",         &genWeights27,         "genWeights27/F"        );
  NewTree->Branch("genWeights28",         &genWeights28,         "genWeights28/F"        );
  NewTree->Branch("genWeights29",         &genWeights29,         "genWeights29/F"        );
  NewTree->Branch("genWeights30",         &genWeights30,         "genWeights30/F"        );
  NewTree->Branch("genWeights31",         &genWeights31,         "genWeights31/F"        );
  NewTree->Branch("genWeights32",         &genWeights32,         "genWeights32/F"        );
  NewTree->Branch("genWeights33",         &genWeights33,         "genWeights33/F"        );
  NewTree->Branch("genWeights34",         &genWeights34,         "genWeights34/F"        );
  NewTree->Branch("genWeights35",         &genWeights35,         "genWeights35/F"        );
  NewTree->Branch("genWeights36",         &genWeights36,         "genWeights36/F"        );
  NewTree->Branch("genWeights37",         &genWeights37,         "genWeights37/F"        );
  NewTree->Branch("genWeights38",         &genWeights38,         "genWeights38/F"        );
  NewTree->Branch("genWeights39",         &genWeights39,         "genWeights39/F"        );
  NewTree->Branch("genWeights40",         &genWeights40,         "genWeights40/F"        );
  NewTree->Branch("genWeights41",         &genWeights41,         "genWeights41/F"        );
  NewTree->Branch("genWeights42",         &genWeights42,         "genWeights42/F"        );
  NewTree->Branch("genWeights43",         &genWeights43,         "genWeights43/F"        );
  NewTree->Branch("genWeights44",         &genWeights44,         "genWeights44/F"        );
  NewTree->Branch("genWeights45",         &genWeights45,         "genWeights45/F"        );
  NewTree->Branch("genWeights46",         &genWeights46,         "genWeights46/F"        );
  NewTree->Branch("genWeights47",         &genWeights47,         "genWeights47/F"        );
  NewTree->Branch("genWeights48",         &genWeights48,         "genWeights48/F"        );
  NewTree->Branch("genWeights49",         &genWeights49,         "genWeights49/F"        );
  NewTree->Branch("genWeights50",         &genWeights50,         "genWeights50/F"        );
  NewTree->Branch("genWeights51",         &genWeights51,         "genWeights51/F"        );
  NewTree->Branch("genWeights52",         &genWeights52,         "genWeights52/F"        );
  NewTree->Branch("genWeights53",         &genWeights53,         "genWeights53/F"        );
  NewTree->Branch("genWeights54",         &genWeights54,         "genWeights54/F"        );
  NewTree->Branch("genWeights55",         &genWeights55,         "genWeights55/F"        );
  NewTree->Branch("genWeights56",         &genWeights56,         "genWeights56/F"        );
  NewTree->Branch("genWeights57",         &genWeights57,         "genWeights57/F"        );
  NewTree->Branch("genWeights58",         &genWeights58,         "genWeights58/F"        );
  NewTree->Branch("genWeights59",         &genWeights59,         "genWeights59/F"        );
  NewTree->Branch("genWeights60",         &genWeights60,         "genWeights60/F"        );
  NewTree->Branch("genWeights61",         &genWeights61,         "genWeights61/F"        );
  NewTree->Branch("genWeights62",         &genWeights62,         "genWeights62/F"        );
  NewTree->Branch("genWeights63",         &genWeights63,         "genWeights63/F"        );
  NewTree->Branch("genWeights64",         &genWeights64,         "genWeights64/F"        );
  NewTree->Branch("genWeights65",         &genWeights65,         "genWeights65/F"        );
  NewTree->Branch("genWeights66",         &genWeights66,         "genWeights66/F"        );
  NewTree->Branch("genWeights67",         &genWeights67,         "genWeights67/F"        );
  NewTree->Branch("genWeights68",         &genWeights68,         "genWeights68/F"        );
  NewTree->Branch("genWeights69",         &genWeights69,         "genWeights69/F"        );
  NewTree->Branch("genWeights70",         &genWeights70,         "genWeights70/F"        );
  NewTree->Branch("genWeights71",         &genWeights71,         "genWeights71/F"        );
  NewTree->Branch("genWeights72",         &genWeights72,         "genWeights72/F"        );
  NewTree->Branch("genWeights73",         &genWeights73,         "genWeights73/F"        );
  NewTree->Branch("genWeights74",         &genWeights74,         "genWeights74/F"        );
  NewTree->Branch("genWeights75",         &genWeights75,         "genWeights75/F"        );
  NewTree->Branch("genWeights76",         &genWeights76,         "genWeights76/F"        );
  NewTree->Branch("genWeights77",         &genWeights77,         "genWeights77/F"        );
  NewTree->Branch("genWeights78",         &genWeights78,         "genWeights78/F"        );
  NewTree->Branch("genWeights79",         &genWeights79,         "genWeights79/F"        );
  NewTree->Branch("genWeights80",         &genWeights80,         "genWeights80/F"        );
  NewTree->Branch("genWeights81",         &genWeights81,         "genWeights81/F"        );
  NewTree->Branch("genWeights82",         &genWeights82,         "genWeights82/F"        );
  NewTree->Branch("genWeights83",         &genWeights83,         "genWeights83/F"        );
  NewTree->Branch("genWeights84",         &genWeights84,         "genWeights84/F"        );
  NewTree->Branch("genWeights85",         &genWeights85,         "genWeights85/F"        );
  NewTree->Branch("genWeights86",         &genWeights86,         "genWeights86/F"        );
  NewTree->Branch("genWeights87",         &genWeights87,         "genWeights87/F"        );
  NewTree->Branch("genWeights88",         &genWeights88,         "genWeights88/F"        );
  NewTree->Branch("genWeights89",         &genWeights89,         "genWeights89/F"        );
  NewTree->Branch("genWeights90",         &genWeights90,         "genWeights90/F"        );
  NewTree->Branch("genWeights91",         &genWeights91,         "genWeights91/F"        );
  NewTree->Branch("genWeights92",         &genWeights92,         "genWeights92/F"        );
  NewTree->Branch("genWeights93",         &genWeights93,         "genWeights93/F"        );
  NewTree->Branch("genWeights94",         &genWeights94,         "genWeights94/F"        );
  NewTree->Branch("genWeights95",         &genWeights95,         "genWeights95/F"        );
  NewTree->Branch("genWeights96",         &genWeights96,         "genWeights96/F"        );
  NewTree->Branch("genWeights97",         &genWeights97,         "genWeights97/F"        );
  NewTree->Branch("genWeights98",         &genWeights98,         "genWeights98/F"        );
  NewTree->Branch("genWeights99",         &genWeights99,         "genWeights99/F"        );
  NewTree->Branch("genWeights100",        &genWeights100,        "genWeights100/F"       );
  NewTree->Branch("genWeights101",        &genWeights101,        "genWeights101/F"       );
  NewTree->Branch("genWeights102",        &genWeights102,        "genWeights102/F"       );
  NewTree->Branch("genWeights103",        &genWeights103,        "genWeights103/F"       );
  NewTree->Branch("genWeights104",        &genWeights104,        "genWeights104/F"       );
  NewTree->Branch("genWeights105",        &genWeights105,        "genWeights105/F"       );
  NewTree->Branch("genWeights106",        &genWeights106,        "genWeights106/F"       );
  NewTree->Branch("genWeights107",        &genWeights107,        "genWeights107/F"       );
  NewTree->Branch("genWeights108",        &genWeights108,        "genWeights108/F"       );
  NewTree->Branch("genWeights109",        &genWeights109,        "genWeights109/F"       );
  NewTree->Branch("genWeights110",        &genWeights110,        "genWeights110/F"       );
  NewTree->Branch("genWeights111",        &genWeights111,        "genWeights111/F"       );
  NewTree->Branch("genWeights112",        &genWeights112,        "genWeights112/F"       );
  NewTree->Branch("genWeights113",        &genWeights113,        "genWeights113/F"       );
  NewTree->Branch("genWeights114",        &genWeights114,        "genWeights114/F"       );
  NewTree->Branch("genWeights115",        &genWeights115,        "genWeights115/F"       );
  NewTree->Branch("genWeights116",        &genWeights116,        "genWeights116/F"       );
  NewTree->Branch("genWeights117",        &genWeights117,        "genWeights117/F"       );
  NewTree->Branch("genWeights118",        &genWeights118,        "genWeights118/F"       );
  NewTree->Branch("genWeights119",        &genWeights119,        "genWeights119/F"       );
  NewTree->Branch("genWeights120",        &genWeights120,        "genWeights120/F"       );
  NewTree->Branch("genWeights121",        &genWeights121,        "genWeights121/F"       );
  NewTree->Branch("genWeights122",        &genWeights122,        "genWeights122/F"       );
  NewTree->Branch("genWeights123",        &genWeights123,        "genWeights123/F"       );
  NewTree->Branch("genWeights124",        &genWeights124,        "genWeights124/F"       );
  NewTree->Branch("genWeights125",        &genWeights125,        "genWeights125/F"       );
  NewTree->Branch("genWeights126",        &genWeights126,        "genWeights126/F"       );
  NewTree->Branch("genWeights127",        &genWeights127,        "genWeights127/F"       );
  NewTree->Branch("genWeights128",        &genWeights128,        "genWeights128/F"       );
  NewTree->Branch("genWeights129",        &genWeights129,        "genWeights129/F"       );
  NewTree->Branch("genWeights130",        &genWeights130,        "genWeights130/F"       );
  NewTree->Branch("genWeights131",        &genWeights131,        "genWeights131/F"       );
  NewTree->Branch("genWeights132",        &genWeights132,        "genWeights132/F"       );
  NewTree->Branch("genWeights133",        &genWeights133,        "genWeights133/F"       );
  NewTree->Branch("genWeights134",        &genWeights134,        "genWeights134/F"       );
  NewTree->Branch("genWeights135",        &genWeights135,        "genWeights135/F"       );
  NewTree->Branch("genWeights136",        &genWeights136,        "genWeights136/F"       );
  NewTree->Branch("genWeights137",        &genWeights137,        "genWeights137/F"       );
  NewTree->Branch("genWeights138",        &genWeights138,        "genWeights138/F"       );
  NewTree->Branch("genWeights139",        &genWeights139,        "genWeights139/F"       );
  NewTree->Branch("genWeights140",        &genWeights140,        "genWeights140/F"       );
  NewTree->Branch("genWeights141",        &genWeights141,        "genWeights141/F"       );
  NewTree->Branch("genWeights142",        &genWeights142,        "genWeights142/F"       );
  NewTree->Branch("genWeights143",        &genWeights143,        "genWeights143/F"       );
  NewTree->Branch("genWeights144",        &genWeights144,        "genWeights144/F"       );
  NewTree->Branch("genWeights145",        &genWeights145,        "genWeights145/F"       );
  NewTree->Branch("genWeights146",        &genWeights146,        "genWeights146/F"       );
  NewTree->Branch("genWeights147",        &genWeights147,        "genWeights147/F"       );
  NewTree->Branch("genWeights148",        &genWeights148,        "genWeights148/F"       );
  NewTree->Branch("genWeights149",        &genWeights149,        "genWeights149/F"       );
  NewTree->Branch("genWeights150",        &genWeights150,        "genWeights150/F"       );
  NewTree->Branch("genWeights151",        &genWeights151,        "genWeights151/F"       );
  NewTree->Branch("genWeights152",        &genWeights152,        "genWeights152/F"       );
  NewTree->Branch("genWeights153",        &genWeights153,        "genWeights153/F"       );
  NewTree->Branch("genWeights154",        &genWeights154,        "genWeights154/F"       );
  NewTree->Branch("genWeights155",        &genWeights155,        "genWeights155/F"       );
  NewTree->Branch("genWeights156",        &genWeights156,        "genWeights156/F"       );
  NewTree->Branch("genWeights157",        &genWeights157,        "genWeights157/F"       );
  NewTree->Branch("genWeights158",        &genWeights158,        "genWeights158/F"       );
  NewTree->Branch("genWeights159",        &genWeights159,        "genWeights159/F"       );
  NewTree->Branch("genWeights160",        &genWeights160,        "genWeights160/F"       );
  NewTree->Branch("genWeights161",        &genWeights161,        "genWeights161/F"       );
  NewTree->Branch("genWeights162",        &genWeights162,        "genWeights162/F"       );
  NewTree->Branch("genWeights163",        &genWeights163,        "genWeights163/F"       );
  NewTree->Branch("genWeights164",        &genWeights164,        "genWeights164/F"       );
  NewTree->Branch("genWeights165",        &genWeights165,        "genWeights165/F"       );
  NewTree->Branch("genWeights166",        &genWeights166,        "genWeights166/F"       );
  NewTree->Branch("genWeights167",        &genWeights167,        "genWeights167/F"       );
  NewTree->Branch("genWeights168",        &genWeights168,        "genWeights168/F"       );
  NewTree->Branch("genWeights169",        &genWeights169,        "genWeights169/F"       );
  NewTree->Branch("genWeights170",        &genWeights170,        "genWeights170/F"       );
  NewTree->Branch("genWeights171",        &genWeights171,        "genWeights171/F"       );
  NewTree->Branch("genWeights172",        &genWeights172,        "genWeights172/F"       );
  NewTree->Branch("genWeights173",        &genWeights173,        "genWeights173/F"       );
  NewTree->Branch("genWeights174",        &genWeights174,        "genWeights174/F"       );
  NewTree->Branch("genWeights175",        &genWeights175,        "genWeights175/F"       );
  NewTree->Branch("genWeights176",        &genWeights176,        "genWeights176/F"       );
  NewTree->Branch("genWeights177",        &genWeights177,        "genWeights177/F"       );
  NewTree->Branch("genWeights178",        &genWeights178,        "genWeights178/F"       );
  NewTree->Branch("genWeights179",        &genWeights179,        "genWeights179/F"       );
  NewTree->Branch("genWeights180",        &genWeights180,        "genWeights180/F"       );
  NewTree->Branch("genWeights181",        &genWeights181,        "genWeights181/F"       );
  NewTree->Branch("genWeights182",        &genWeights182,        "genWeights182/F"       );
  NewTree->Branch("genWeights183",        &genWeights183,        "genWeights183/F"       );
  NewTree->Branch("genWeights184",        &genWeights184,        "genWeights184/F"       );
  NewTree->Branch("genWeights185",        &genWeights185,        "genWeights185/F"       );
  NewTree->Branch("genWeights186",        &genWeights186,        "genWeights186/F"       );
  NewTree->Branch("genWeights187",        &genWeights187,        "genWeights187/F"       );
  NewTree->Branch("genWeights188",        &genWeights188,        "genWeights188/F"       );
  NewTree->Branch("genWeights189",        &genWeights189,        "genWeights189/F"       );
  NewTree->Branch("genWeights190",        &genWeights190,        "genWeights190/F"       );
  NewTree->Branch("genWeights191",        &genWeights191,        "genWeights191/F"       );
  NewTree->Branch("genWeights192",        &genWeights192,        "genWeights192/F"       );
  NewTree->Branch("genWeights193",        &genWeights193,        "genWeights193/F"       );
  NewTree->Branch("genWeights194",        &genWeights194,        "genWeights194/F"       );
  NewTree->Branch("genWeights195",        &genWeights195,        "genWeights195/F"       );
  NewTree->Branch("genWeights196",        &genWeights196,        "genWeights196/F"       );
  NewTree->Branch("genWeights197",        &genWeights197,        "genWeights197/F"       );
  NewTree->Branch("genWeights198",        &genWeights198,        "genWeights198/F"       );
  NewTree->Branch("genWeights199",        &genWeights199,        "genWeights199/F"       );
  NewTree->Branch("genWeights200",        &genWeights200,        "genWeights200/F"       );
  NewTree->Branch("genWeights201",        &genWeights201,        "genWeights201/F"       );
  NewTree->Branch("genWeights202",        &genWeights202,        "genWeights202/F"       );
  NewTree->Branch("genWeights203",        &genWeights203,        "genWeights203/F"       );
  NewTree->Branch("genWeights204",        &genWeights204,        "genWeights204/F"       );
  NewTree->Branch("genWeights205",        &genWeights205,        "genWeights205/F"       );
  NewTree->Branch("genWeights206",        &genWeights206,        "genWeights206/F"       );
  NewTree->Branch("genWeights207",        &genWeights207,        "genWeights207/F"       );
  NewTree->Branch("genWeights208",        &genWeights208,        "genWeights208/F"       );
  NewTree->Branch("genWeights209",        &genWeights209,        "genWeights209/F"       );
  NewTree->Branch("genWeights210",        &genWeights210,        "genWeights210/F"       );
  NewTree->Branch("genWeights211",        &genWeights211,        "genWeights211/F"       );
  NewTree->Branch("genWeights212",        &genWeights212,        "genWeights212/F"       );
  NewTree->Branch("genWeights1001",          &genWeights1001,          "genWeights1001/F"         );
  NewTree->Branch("genWeights1002",          &genWeights1002,          "genWeights1002/F"         );
  NewTree->Branch("genWeights1003",          &genWeights1003,          "genWeights1003/F"         );
  NewTree->Branch("genWeights1004",          &genWeights1004,          "genWeights1004/F"         );
  NewTree->Branch("genWeights1005",          &genWeights1005,          "genWeights1005/F"         );
  NewTree->Branch("genWeights1006",          &genWeights1006,          "genWeights1006/F"         );
  NewTree->Branch("genWeights1007",          &genWeights1007,          "genWeights1007/F"         );
  NewTree->Branch("genWeights1008",          &genWeights1008,          "genWeights1008/F"         );
  NewTree->Branch("genWeights1009",          &genWeights1009,          "genWeights1009/F"         );
  NewTree->Branch("genWeights2000",          &genWeights2000,          "genWeights2000/F"         );
  NewTree->Branch("genWeights2001",          &genWeights2001,          "genWeights2001/F"         );
  NewTree->Branch("genWeights2002",          &genWeights2002,          "genWeights2002/F"         );
  NewTree->Branch("genWeights2003",          &genWeights2003,          "genWeights2003/F"         );
  NewTree->Branch("genWeights2004",          &genWeights2004,          "genWeights2004/F"         );
  NewTree->Branch("genWeights2005",          &genWeights2005,          "genWeights2005/F"         );
  NewTree->Branch("genWeights2006",          &genWeights2006,          "genWeights2006/F"         );
  NewTree->Branch("genWeights2007",          &genWeights2007,          "genWeights2007/F"         );
  NewTree->Branch("genWeights2008",          &genWeights2008,          "genWeights2008/F"         );
  NewTree->Branch("genWeights2009",          &genWeights2009,          "genWeights2009/F"         );
  NewTree->Branch("genWeights2010",         &genWeights2010,         "genWeights2010/F"        );
  NewTree->Branch("genWeights2011",         &genWeights2011,         "genWeights2011/F"        );
  NewTree->Branch("genWeights2012",         &genWeights2012,         "genWeights2012/F"        );
  NewTree->Branch("genWeights2013",         &genWeights2013,         "genWeights2013/F"        );
  NewTree->Branch("genWeights2014",         &genWeights2014,         "genWeights2014/F"        );
  NewTree->Branch("genWeights2015",         &genWeights2015,         "genWeights2015/F"        );
  NewTree->Branch("genWeights2016",         &genWeights2016,         "genWeights2016/F"        );
  NewTree->Branch("genWeights2017",         &genWeights2017,         "genWeights2017/F"        );
  NewTree->Branch("genWeights2018",         &genWeights2018,         "genWeights2018/F"        );
  NewTree->Branch("genWeights2019",         &genWeights2019,         "genWeights2019/F"        );
  NewTree->Branch("genWeights2020",         &genWeights2020,         "genWeights2020/F"        );
  NewTree->Branch("genWeights2021",         &genWeights2021,         "genWeights2021/F"        );
  NewTree->Branch("genWeights2022",         &genWeights2022,         "genWeights2022/F"        );
  NewTree->Branch("genWeights2023",         &genWeights2023,         "genWeights2023/F"        );
  NewTree->Branch("genWeights2024",         &genWeights2024,         "genWeights2024/F"        );
  NewTree->Branch("genWeights2025",         &genWeights2025,         "genWeights2025/F"        );
  NewTree->Branch("genWeights2026",         &genWeights2026,         "genWeights2026/F"        );
  NewTree->Branch("genWeights2027",         &genWeights2027,         "genWeights2027/F"        );
  NewTree->Branch("genWeights2028",         &genWeights2028,         "genWeights2028/F"        );
  NewTree->Branch("genWeights2029",         &genWeights2029,         "genWeights2029/F"        );
  NewTree->Branch("genWeights2030",         &genWeights2030,         "genWeights2030/F"        );
  NewTree->Branch("genWeights2031",         &genWeights2031,         "genWeights2031/F"        );
  NewTree->Branch("genWeights2032",         &genWeights2032,         "genWeights2032/F"        );
  NewTree->Branch("genWeights2033",         &genWeights2033,         "genWeights2033/F"        );
  NewTree->Branch("genWeights2034",         &genWeights2034,         "genWeights2034/F"        );
  NewTree->Branch("genWeights2035",         &genWeights2035,         "genWeights2035/F"        );
  NewTree->Branch("genWeights2036",         &genWeights2036,         "genWeights2036/F"        );
  NewTree->Branch("genWeights2037",         &genWeights2037,         "genWeights2037/F"        );
  NewTree->Branch("genWeights2038",         &genWeights2038,         "genWeights2038/F"        );
  NewTree->Branch("genWeights2039",         &genWeights2039,         "genWeights2039/F"        );
  NewTree->Branch("genWeights2040",         &genWeights2040,         "genWeights2040/F"        );
  NewTree->Branch("genWeights2041",         &genWeights2041,         "genWeights2041/F"        );
  NewTree->Branch("genWeights2042",         &genWeights2042,         "genWeights2042/F"        );
  NewTree->Branch("genWeights2043",         &genWeights2043,         "genWeights2043/F"        );
  NewTree->Branch("genWeights2044",         &genWeights2044,         "genWeights2044/F"        );
  NewTree->Branch("genWeights2045",         &genWeights2045,         "genWeights2045/F"        );
  NewTree->Branch("genWeights2046",         &genWeights2046,         "genWeights2046/F"        );
  NewTree->Branch("genWeights2047",         &genWeights2047,         "genWeights2047/F"        );
  NewTree->Branch("genWeights2048",         &genWeights2048,         "genWeights2048/F"        );
  NewTree->Branch("genWeights2049",         &genWeights2049,         "genWeights2049/F"        );
  NewTree->Branch("genWeights2050",         &genWeights2050,         "genWeights2050/F"        );
  NewTree->Branch("genWeights2051",         &genWeights2051,         "genWeights2051/F"        );
  NewTree->Branch("genWeights2052",         &genWeights2052,         "genWeights2052/F"        );
  NewTree->Branch("genWeights2053",         &genWeights2053,         "genWeights2053/F"        );
  NewTree->Branch("genWeights2054",         &genWeights2054,         "genWeights2054/F"        );
  NewTree->Branch("genWeights2055",         &genWeights2055,         "genWeights2055/F"        );
  NewTree->Branch("genWeights2056",         &genWeights2056,         "genWeights2056/F"        );
  NewTree->Branch("genWeights2057",         &genWeights2057,         "genWeights2057/F"        );
  NewTree->Branch("genWeights2058",         &genWeights2058,         "genWeights2058/F"        );
  NewTree->Branch("genWeights2059",         &genWeights2059,         "genWeights2059/F"        );
  NewTree->Branch("genWeights2060",         &genWeights2060,         "genWeights2060/F"        );
  NewTree->Branch("genWeights2061",         &genWeights2061,         "genWeights2061/F"        );
  NewTree->Branch("genWeights2062",         &genWeights2062,         "genWeights2062/F"        );
  NewTree->Branch("genWeights2063",         &genWeights2063,         "genWeights2063/F"        );
  NewTree->Branch("genWeights2064",         &genWeights2064,         "genWeights2064/F"        );
  NewTree->Branch("genWeights2065",         &genWeights2065,         "genWeights2065/F"        );
  NewTree->Branch("genWeights2066",         &genWeights2066,         "genWeights2066/F"        );
  NewTree->Branch("genWeights2067",         &genWeights2067,         "genWeights2067/F"        );
  NewTree->Branch("genWeights2068",         &genWeights2068,         "genWeights2068/F"        );
  NewTree->Branch("genWeights2069",         &genWeights2069,         "genWeights2069/F"        );
  NewTree->Branch("genWeights2070",         &genWeights2070,         "genWeights2070/F"        );
  NewTree->Branch("genWeights2071",         &genWeights2071,         "genWeights2071/F"        );
  NewTree->Branch("genWeights2072",         &genWeights2072,         "genWeights2072/F"        );
  NewTree->Branch("genWeights2073",         &genWeights2073,         "genWeights2073/F"        );
  NewTree->Branch("genWeights2074",         &genWeights2074,         "genWeights2074/F"        );
  NewTree->Branch("genWeights2075",         &genWeights2075,         "genWeights2075/F"        );
  NewTree->Branch("genWeights2076",         &genWeights2076,         "genWeights2076/F"        );
  NewTree->Branch("genWeights2077",         &genWeights2077,         "genWeights2077/F"        );
  NewTree->Branch("genWeights2078",         &genWeights2078,         "genWeights2078/F"        );
  NewTree->Branch("genWeights2079",         &genWeights2079,         "genWeights2079/F"        );
  NewTree->Branch("genWeights2080",         &genWeights2080,         "genWeights2080/F"        );
  NewTree->Branch("genWeights2081",         &genWeights2081,         "genWeights2081/F"        );
  NewTree->Branch("genWeights2082",         &genWeights2082,         "genWeights2082/F"        );
  NewTree->Branch("genWeights2083",         &genWeights2083,         "genWeights2083/F"        );
  NewTree->Branch("genWeights2084",         &genWeights2084,         "genWeights2084/F"        );
  NewTree->Branch("genWeights2085",         &genWeights2085,         "genWeights2085/F"        );
  NewTree->Branch("genWeights2086",         &genWeights2086,         "genWeights2086/F"        );
  NewTree->Branch("genWeights2087",         &genWeights2087,         "genWeights2087/F"        );
  NewTree->Branch("genWeights2088",         &genWeights2088,         "genWeights2088/F"        );
  NewTree->Branch("genWeights2089",         &genWeights2089,         "genWeights2089/F"        );
  NewTree->Branch("genWeights2090",         &genWeights2090,         "genWeights2090/F"        );
  NewTree->Branch("genWeights2091",         &genWeights2091,         "genWeights2091/F"        );
  NewTree->Branch("genWeights2092",         &genWeights2092,         "genWeights2092/F"        );
  NewTree->Branch("genWeights2093",         &genWeights2093,         "genWeights2093/F"        );
  NewTree->Branch("genWeights2094",         &genWeights2094,         "genWeights2094/F"        );
  NewTree->Branch("genWeights2095",         &genWeights2095,         "genWeights2095/F"        );
  NewTree->Branch("genWeights2096",         &genWeights2096,         "genWeights2096/F"        );
  NewTree->Branch("genWeights2097",         &genWeights2097,         "genWeights2097/F"        );
  NewTree->Branch("genWeights2098",         &genWeights2098,         "genWeights2098/F"        );
  NewTree->Branch("genWeights2099",         &genWeights2099,         "genWeights2099/F"        );
  NewTree->Branch("genWeights2100",        &genWeights2100,        "genWeights2100/F"       );
  NewTree->Branch("dQuark",&dQuark,"dQuark/I");
  NewTree->Branch("uQuark",&uQuark,"uQuark/I");
  NewTree->Branch("sQuark",&sQuark,"sQuark/I");
  NewTree->Branch("cQuark",&cQuark,"cQuark/I");
  NewTree->Branch("bQuark",&bQuark,"bQuark/I");
  NewTree->Branch("tQuark",&tQuark,"tQuark/I");
  //NewTree->Branch("EVENT_event",&EVENT_event,"EVENT_event/I");
  NewTree->Branch("EVENT_run",&EVENT_run,"EVENT_run/I");
  NewTree->Branch("EVENT_lumiBlock",&EVENT_lumiBlock,"EVENT_lumiBlock/I");
  NewTree->Branch("EVENT_genHT",&EVENT_genHT,"EVENT_genHT/F");
  NewTree->Branch("prefiringweight",&prefiringweight,"prefiringweight/F");
  NewTree->Branch("prefiringweightup",&prefiringweightup,"prefiringweightup/F");
  NewTree->Branch("prefiringweightdown",&prefiringweightdown,"prefiringweightdown/F");
  NewTree->Branch("Met_pt",&Met_pt,"Met_pt/F");
  NewTree->Branch("Met_phi",&Met_phi,"Met_phi/F");
  NewTree->Branch("TransverseMassMetTop",&TransverseMassMetTop,"TransverseMassMetTop/F");

  
  NewTreeSB->Branch("category0",         &category0,         "category0/I"         );
  NewTreeSB->Branch("category1",         &category1,         "category1/I"         );
  NewTreeSB->Branch("category2",         &category2,         "category2/I"         );
  /*NewTreeSB->Branch("category3",         &category3,         "category3/I"         );
  NewTreeSB->Branch("category4",         &category4,         "category4/I"         );
  NewTreeSB->Branch("category5",         &category5,         "category5/I"         );
  NewTreeSB->Branch("category6",         &category6,         "category6/I"         );
  NewTreeSB->Branch("category7",         &category7,         "category7/I"         );*/
  NewTreeSB->Branch("TopMass",           &TopMass,           "TopMass/F"           );
  NewTreeSB->Branch("TopMassMerged",     &TopMassMerged,     "TopMassMerged/F"     );
  NewTreeSB->Branch("TopMassPartial",    &TopMassPartial,    "TopMassPartial/F"    );
  NewTreeSB->Branch("TopMassResolved",   &TopMassResolved,   "TopMassResolved/F"   );
  NewTreeSB->Branch("TopPt",             &TopPt,             "TopPt/F"             );
  NewTreeSB->Branch("TopPtMerged",       &TopPtMerged,       "TopPtMerged/F"       );
  NewTreeSB->Branch("TopPtPartial",      &TopPtPartial,      "TopPtPartial/F"      );
  NewTreeSB->Branch("TopPtResolved",     &TopPtResolved,     "TopPtResolved/F"     );
  NewTreeSB->Branch("TopEta",            &TopEta,            "TopEta/F"            );
  NewTreeSB->Branch("TopEtaMerged",      &TopEtaMerged,      "TopEtaMerged/F"      );
  NewTreeSB->Branch("TopEtaPartial",     &TopEtaPartial,     "TopEtaPartial/F"     );
  NewTreeSB->Branch("TopEtaResolved",    &TopEtaResolved,    "TopEtaResolved/F"    );
  NewTreeSB->Branch("TopPhi",            &TopPhi,            "TopPhi/F"            );
  NewTreeSB->Branch("TopPhiMerged",      &TopPhiMerged,      "TopPhiMerged/F"      );
  NewTreeSB->Branch("TopPhiPartial",     &TopPhiPartial,     "TopPhiPartial/F"     );
  NewTreeSB->Branch("TopPhiResolved",    &TopPhiResolved,    "TopPhiResolved/F"    );
  NewTreeSB->Branch("WMassResolved1",    &WMassResolved1,    "WMassResolved1/F"    );
  NewTreeSB->Branch("WMassResolved2",    &WMassResolved2,    "WMassResolved2/F"    );
  NewTreeSB->Branch("WMassResolved3",    &WMassResolved3,    "WMassResolved3/F"    );
  NewTreeSB->Branch("BMass",             &BMass,             "BMass/F"             );
  NewTreeSB->Branch("BCSV",              &BCSV,              "BCSV/F"              );
  NewTreeSB->Branch("BPt",               &BPt,               "BPt/F"               );
  NewTreeSB->Branch("BEta",              &BEta,              "BEta/F"              );
  NewTreeSB->Branch("BPhi",              &BPhi,              "BPhi/F"              );
  NewTreeSB->Branch("ZMass",             &ZMass,             "ZMass/F"             );
  NewTreeSB->Branch("ZPt",               &ZPt,               "ZPt/F"               );
  NewTreeSB->Branch("ZEta",              &ZEta,              "ZEta/F"              );
  NewTreeSB->Branch("ZPhi",              &ZPhi,              "ZPhi/F"              );
  NewTreeSB->Branch("TprimeMass",        &TprimeMass,        "TprimeMass/F"        );
  NewTreeSB->Branch("TprimePt",          &TprimePt,          "TprimePt/F"          );
  NewTreeSB->Branch("TprimeEta",         &TprimeEta,         "TprimeEta/F"         );
  NewTreeSB->Branch("TprimePhi",         &TprimePhi,         "TprimePhi/F"         );
  NewTreeSB->Branch("TprimeResolvedMass",&TprimeResolvedMass,"TprimeResolvedMass/F");
  NewTreeSB->Branch("TprimeResolvedPt",  &TprimeResolvedPt,  "TprimeResolvedPt/F"  );
  NewTreeSB->Branch("TprimeResolvedEta", &TprimeResolvedEta, "TprimeResolvedEta/F" );
  NewTreeSB->Branch("TprimeResolvedPhi", &TprimeResolvedPhi, "TprimeResolvedPhi/F" );
  NewTreeSB->Branch("TprimePartialMass", &TprimePartialMass, "TprimePartialMass/F" );
  NewTreeSB->Branch("TprimePartialPt",   &TprimePartialPt,   "TprimePartialPt/F"   );
  NewTreeSB->Branch("TprimePartialEta",  &TprimePartialEta,  "TprimePartialEta/F"  );
  NewTreeSB->Branch("TprimePartialPhi",  &TprimePartialPhi,  "TprimePartialPhi/F"  );
  NewTreeSB->Branch("TprimeMergedMass",  &TprimeMergedMass,  "TprimeMergedMass/F"  );
  NewTreeSB->Branch("TprimeMergedPt",    &TprimeMergedPt,    "TprimeMergedPt/F"    );
  NewTreeSB->Branch("TprimeMergedEta",   &TprimeMergedEta,   "TprimeMergedEta/F"   );
  NewTreeSB->Branch("TprimeMergedPhi",   &TprimeMergedPhi,   "TprimeMergedPhi/F"   );
  NewTreeSB->Branch("Electron1Pt",       &Electron1Pt,       "Electron1Pt/F"       );
  NewTreeSB->Branch("Electron2Pt",       &Electron2Pt,       "Electron2Pt/F"       );
  NewTreeSB->Branch("Electron1E",        &Electron1E,        "Electron1E/F"        );
  NewTreeSB->Branch("Electron2E",        &Electron2E,        "Electron2E/F"        );
  NewTreeSB->Branch("Muon1Iso",          &Muon1Iso,          "Muon1Iso/F"          );
  NewTreeSB->Branch("Muon2Iso",          &Muon2Iso,          "Muon2Iso/F"          );
  NewTreeSB->Branch("Muon1Pt",           &Muon1Pt,           "Muon1Pt/F"           );
  NewTreeSB->Branch("Muon2Pt",           &Muon2Pt,           "Muon2Pt/F"           );
  NewTreeSB->Branch("Jet1ForwardEta",    &Jet1ForwardEta,    "Jet1ForwardEta/F"    );
  NewTreeSB->Branch("Jet2ForwardEta",    &Jet2ForwardEta,    "Jet2ForwardEta/F"    );
  NewTreeSB->Branch("Jet3ForwardEta",    &Jet3ForwardEta,    "Jet3ForwardEta/F"    );
  NewTreeSB->Branch("Jet1ForwardPt",     &Jet1ForwardPt,     "Jet1ForwardPt/F"     );
  NewTreeSB->Branch("Jet2ForwardPt",     &Jet2ForwardPt,     "Jet2ForwardPt/F"     );
  NewTreeSB->Branch("Jet3ForwardPt",     &Jet3ForwardPt,     "Jet3ForwardPt/F"     );
  NewTreeSB->Branch("Jet1ResolvedPt",    &Jet1ResolvedPt,    "Jet1ResolvedPt/F"    );
  NewTreeSB->Branch("Jet2ResolvedPt",    &Jet2ResolvedPt,    "Jet2ResolvedPt/F"    );
  NewTreeSB->Branch("Jet3ResolvedPt",    &Jet3ResolvedPt,    "Jet3ResolvedPt/F"    );
  NewTreeSB->Branch("Jet1PartialPt",     &Jet1PartialPt,     "Jet1PartialPt/F"     );
  NewTreeSB->Branch("Jet2PartialPt",     &Jet2PartialPt,     "Jet2PartialPt/F"     );
  NewTreeSB->Branch("Jet1MergedPt",      &Jet1MergedPt,      "Jet1MergedPt/F"      );
  NewTreeSB->Branch("MostForwardJetEta", &MostForwardJetEta, "MostForwardJetEta/F" );
  NewTreeSB->Branch("MostForwardJetPt",  &MostForwardJetPt,  "MostForwardJetPt/F"  );
  NewTreeSB->Branch("Electron1Eta",      &Electron1Eta,      "Electron1Eta/F"      );
  NewTreeSB->Branch("Electron2Eta",      &Electron2Eta,      "Electron2Eta/F"      );
  NewTreeSB->Branch("Muon1Eta",          &Muon1Eta,          "Muon1Eta/F"          );
  NewTreeSB->Branch("Muon2Eta",          &Muon2Eta,          "Muon2Eta/F"          );
  NewTreeSB->Branch("Jet1ResolvedEta",   &Jet1ResolvedEta,   "Jet1ResolvedEta/F"   );
  NewTreeSB->Branch("Jet2ResolvedEta",   &Jet2ResolvedEta,   "Jet2ResolvedEta/F"   );
  NewTreeSB->Branch("Jet3ResolvedEta",   &Jet3ResolvedEta,   "Jet3ResolvedEta/F"   );
  NewTreeSB->Branch("Jet1PartialEta",    &Jet1PartialEta,    "Jet1PartialEta/F"    );
  NewTreeSB->Branch("Jet2PartialEta",    &Jet2PartialEta,    "Jet2PartialEta/F"    );
  NewTreeSB->Branch("Jet1MergedEta",     &Jet1MergedEta,     "Jet1MergedEta/F"     );
  NewTreeSB->Branch("Electron1Phi",      &Electron1Phi,      "Electron1Phi/F"      );
  NewTreeSB->Branch("Electron2Phi",      &Electron2Phi,      "Electron2Phi/F"      );
  NewTreeSB->Branch("Muon1Phi",          &Muon1Phi,          "Muon1Phi/F"          );
  NewTreeSB->Branch("Muon2Phi",          &Muon2Phi,          "Muon2Phi/F"          );
  NewTreeSB->Branch("deltaPhiZTop",      &deltaPhiZTop,      "deltaPhiZTop/F"      );
  NewTreeSB->Branch("deltaRZTop",        &deltaRZTop,        "deltaRZTop/F"        );
  NewTreeSB->Branch("deltaREle1Ele2",    &deltaREle1Ele2,    "deltaREle1Ele2/F"    );
  NewTreeSB->Branch("deltaRMuo1Muo2",    &deltaRMuo1Muo2,    "deltaRMuo1Muo2/F"    );
  NewTreeSB->Branch("Massb1b2",          &Massb1b2,          "Massb1b2/F"          );
  NewTreeSB->Branch("MinDeltaPhiJetMet", &MinDeltaPhiJetMet, "MinDeltaPhiJetMet/F" );
  NewTreeSB->Branch("MinDeltaPhiBoostedJetMet", &MinDeltaPhiBoostedJetMet, "MinDeltaPhiBoostedJetMet/F" );
  NewTreeSB->Branch("deltaRb1b2",        &deltaRb1b2,        "deltaRb1b2/F"        );
  NewTreeSB->Branch("deltaRb1Lep1",      &deltaRb1Lep1,      "deltaRb1Lep1/F"      );
  NewTreeSB->Branch("deltaRb1Lep2",      &deltaRb1Lep2,      "deltaRb1Lep2/F"      );
  NewTreeSB->Branch("deltaRb2Lep1",      &deltaRb2Lep1,      "deltaRb2Lep1/F"      );
  NewTreeSB->Branch("deltaRb2Lep2",      &deltaRb2Lep2,      "deltaRb2Lep2/F"      );
  NewTreeSB->Branch("NumSelLeps",        &NumSelLeps,        "NumSelLeps/I"        );
  NewTreeSB->Branch("NumSelJets",        &NumSelJets,        "NumSelJets/I"        );
  NewTreeSB->Branch("NumSelForwardJets", &NumSelForwardJets, "NumSelForwardJets/I" );
  NewTreeSB->Branch("NumSelBJetsL",      &NumSelBJetsL,      "NumSelBJetsL/I"      );
  NewTreeSB->Branch("NumSelBJetsM",      &NumSelBJetsM,      "NumSelBJetsM/I"      );
  NewTreeSB->Branch("NumSelBJetsT",      &NumSelBJetsT,      "NumSelBJetsT/I"      );
  NewTreeSB->Branch("NumSelWJets",       &NumSelWJets,       "NumSelWJets/I"       );
  NewTreeSB->Branch("NumSelTopJets",     &NumSelTopJets,     "NumSelTopJets/I"     );
  NewTreeSB->Branch("NVertices",         &NVertices,         "NVertices/I"         );
  NewTreeSB->Branch("HT",                &HT,                "HT/F"                );
  NewTreeSB->Branch("PUWeight",          &PUWeight,          "PUWeight/F"          );
  NewTreeSB->Branch("PUWeightUP",        &PUWeightUP,        "PUWeightUP/F"        );
  NewTreeSB->Branch("PUWeightDOWN",      &PUWeightDOWN,      "PUWeightDOWN/F"      );
  NewTreeSB->Branch("getTrueNumInteractions",&getTrueNumInteractions,"getTrueNumInteractions/I");
  NewTreeSB->Branch("w_for",             &w_for,             "w_for/F"             );
  NewTreeSB->Branch("w_forUp",           &w_forUp,           "w_forUp/F"           );
  NewTreeSB->Branch("w_forDown",         &w_forDown,         "w_forDown/F"         );
  NewTreeSB->Branch("w_topJet",          &w_topJet,          "w_topJet/F"          );
  NewTreeSB->Branch("w_topJetUp",        &w_topJetUp,        "w_topJetUp/F"        );
  NewTreeSB->Branch("w_topJetDown",      &w_topJetDown,      "w_topJetDown/F"      );
  NewTreeSB->Branch("w_WJet",            &w_WJet,            "w_WJet/F"            );
  NewTreeSB->Branch("w_WJetUp",          &w_WJetUp,          "w_WJetUp/F"          );
  NewTreeSB->Branch("w_WJetDown",        &w_WJetDown,        "w_WJetDown/F"        );
  NewTreeSB->Branch("w_Muon1",           &w_Muon1,           "w_Muon1/F"           );
  NewTreeSB->Branch("w_Muon2",           &w_Muon2,           "w_Muon2/F"           );
  NewTreeSB->Branch("w_Muon1Up",         &w_Muon1Up,         "w_Muon1Up/F"         );
  NewTreeSB->Branch("w_Muon2Up",         &w_Muon2Up,         "w_Muon2Up/F"         );
  NewTreeSB->Branch("w_Muon1Down",       &w_Muon1Down,       "w_Muon1Down/F"       );
  NewTreeSB->Branch("w_Muon2Down",       &w_Muon2Down,       "w_Muon2Down/F"       );
  NewTreeSB->Branch("w_TrigMuon",        &w_TrigMuon,        "w_TrigMuon/F"        );
  NewTreeSB->Branch("w_TrigMuonUp",      &w_TrigMuonUp,      "w_TrigMuonUp/F"      );
  NewTreeSB->Branch("w_TrigMuonDown",    &w_TrigMuonDown,    "w_TrigMuonDown/F"    );
  NewTreeSB->Branch("w_Electron1",       &w_Electron1,       "w_Electron1/F"       );
  NewTreeSB->Branch("w_Electron2",       &w_Electron2,       "w_Electron2/F"       );
  NewTreeSB->Branch("w_Electron1Up",     &w_Electron1Up,     "w_Electron1Up/F"     );
  NewTreeSB->Branch("w_Electron2Up",     &w_Electron2Up,     "w_Electron2Up/F"     );
  NewTreeSB->Branch("w_Electron1Down",   &w_Electron1Down,   "w_Electron1Down/F"   );
  NewTreeSB->Branch("w_Electron2Down",   &w_Electron2Down,   "w_Electron2Down/F"   );
  NewTreeSB->Branch("w_TrigElec",        &w_TrigElec,        "w_TrigElec/F"        );
  NewTreeSB->Branch("w_TrigElecUp",      &w_TrigElecUp,      "w_TrigElecUp/F"      );
  NewTreeSB->Branch("w_TrigElecDown",    &w_TrigElecDown,    "w_TrigElecDown/F"    );
  NewTreeSB->Branch("w_ZToNuNu",         &w_ZToNuNu,         "w_ZToNuNu/F"         );
  NewTreeSB->Branch("w_ZToNuNuUp",       &w_ZToNuNuUp,       "w_ZToNuNuUp/F"       );
  NewTreeSB->Branch("w_ZToNuNuDown",     &w_ZToNuNuDown,     "w_ZToNuNuDown/F"     );
  NewTreeSB->Branch("w_WToLNu",          &w_WToLNu,          "w_WToLNu/F"          );
  NewTreeSB->Branch("w_WToLNuUp",        &w_WToLNuUp,        "w_WToLNuUp/F"        );
  NewTreeSB->Branch("w_WToLNuDown",      &w_WToLNuDown,      "w_WToLNuDown/F"      );
  NewTreeSB->Branch("w_ttbar",           &w_ttbar,           "w_ttbar/F"           );
  NewTreeSB->Branch("w_ttbarUp",         &w_ttbarUp,         "w_ttbarUp/F"         );
  NewTreeSB->Branch("w_ttbarDown",       &w_ttbarDown,       "w_ttbarDown/F"       );
  NewTreeSB->Branch("WMass",             &WMass,             "WMass/F"             );
  NewTreeSB->Branch("WSubjet",           &WSubjet,           "WSubjet/F"           );
  NewTreeSB->Branch("TopSoftMass",       &TopSoftMass,       "TopSoftMass/F"       );
  NewTreeSB->Branch("TopSubjet",         &TopSubjet,         "TopSubjet/F"         );
  NewTreeSB->Branch("w_Btag",            &w_Btag,            "w_Btag/F"            );
  NewTreeSB->Branch("w_BtagUp",          &w_BtagUp,          "w_BtagUp/F"          );
  NewTreeSB->Branch("w_BtagDown",        &w_BtagDown,        "w_BtagDown/F"        );
  NewTreeSB->Branch("w_Btag1Up",         &w_Btag1Up,         "w_Btag1Up/F"         );
  NewTreeSB->Branch("w_Btag1Down",       &w_Btag1Down,       "w_Btag1Down/F"       );
  NewTreeSB->Branch("w_Btag2Up",         &w_Btag2Up,         "w_Btag2Up/F"         );
  NewTreeSB->Branch("w_Btag2Down",       &w_Btag2Down,       "w_Btag2Down/F"       );
  NewTreeSB->Branch("w_BtagLoose",       &w_BtagLoose,       "w_BtagLoose/F"       );
  NewTreeSB->Branch("w_BtagLooseUp",     &w_BtagLooseUp,     "w_BtagLooseUp/F"     );
  NewTreeSB->Branch("w_BtagLooseDown",   &w_BtagLooseDown,   "w_BtagLooseDown/F"   );
  NewTreeSB->Branch("w_QCDUp",           &w_QCDUp,           "w_QCDUp/F"   );
  NewTreeSB->Branch("w_QCDDown",         &w_QCDDown,         "w_QCDDown/F"   );
  NewTreeSB->Branch("w_PDFUp",           &w_PDFUp,           "w_PDFUp/F"   );
  NewTreeSB->Branch("w_PDFDown",         &w_PDFDown,         "w_PDFDown/F"   );
  NewTreeSB->Branch("deltaPhiZTopResolved", &deltaPhiZTopResolved, "deltaPhiZTopResolved/F");
  NewTreeSB->Branch("deltaRZTopResolved",   &deltaRZTopResolved,   "deltaRZTopResolved/F"  );
  NewTreeSB->Branch("deltaPhiZTopPartial",  &deltaPhiZTopPartial,  "deltaPhiZTopPartial/F" );
  NewTreeSB->Branch("deltaRZTopPartial",    &deltaRZTopPartial,    "deltaRZTopPartial/F"   );
  NewTreeSB->Branch("deltaPhiZTopMerged",   &deltaPhiZTopMerged,   "deltaPhiZTopMerged/F"  );
  NewTreeSB->Branch("deltaRZTopMerged",     &deltaRZTopMerged,     "deltaRZTopMerged/F"    );
  NewTreeSB->Branch("deltaRbTop",           &deltaRbTop,           "deltaRbTop/F"          );
  NewTreeSB->Branch("deltaPhiMetTop",       &deltaPhiMetTop,       "deltaPhiMetTop/F"      );
  NewTreeSB->Branch("genWeight",            &genWeight,            "genWeight/F"           );
  NewTreeSB->Branch("genWeights0",          &genWeights0,          "genWeights0/F"         );
  NewTreeSB->Branch("genWeights1",          &genWeights1,          "genWeights1/F"         );
  NewTreeSB->Branch("genWeights2",          &genWeights2,          "genWeights2/F"         );
  NewTreeSB->Branch("genWeights3",          &genWeights3,          "genWeights3/F"         );
  NewTreeSB->Branch("genWeights4",          &genWeights4,          "genWeights4/F"         );
  NewTreeSB->Branch("genWeights5",          &genWeights5,          "genWeights5/F"         );
  NewTreeSB->Branch("genWeights6",          &genWeights6,          "genWeights6/F"         );
  NewTreeSB->Branch("genWeights7",          &genWeights7,          "genWeights7/F"         );
  NewTreeSB->Branch("genWeights8",          &genWeights8,          "genWeights8/F"         );
  NewTreeSB->Branch("genWeights9",          &genWeights9,          "genWeights9/F"         );
  NewTreeSB->Branch("genWeights10",         &genWeights10,         "genWeights10/F"        );
  NewTreeSB->Branch("genWeights11",         &genWeights11,         "genWeights11/F"        );
  NewTreeSB->Branch("genWeights12",         &genWeights12,         "genWeights12/F"        );
  NewTreeSB->Branch("genWeights13",         &genWeights13,         "genWeights13/F"        );
  NewTreeSB->Branch("genWeights14",         &genWeights14,         "genWeights14/F"        );
  NewTreeSB->Branch("genWeights15",         &genWeights15,         "genWeights15/F"        );
  NewTreeSB->Branch("genWeights16",         &genWeights16,         "genWeights16/F"        );
  NewTreeSB->Branch("genWeights17",         &genWeights17,         "genWeights17/F"        );
  NewTreeSB->Branch("genWeights18",         &genWeights18,         "genWeights18/F"        );
  NewTreeSB->Branch("genWeights19",         &genWeights19,         "genWeights19/F"        );
  NewTreeSB->Branch("genWeights20",         &genWeights20,         "genWeights20/F"        );
  NewTreeSB->Branch("genWeights21",         &genWeights21,         "genWeights21/F"        );
  NewTreeSB->Branch("genWeights22",         &genWeights22,         "genWeights22/F"        );
  NewTreeSB->Branch("genWeights23",         &genWeights23,         "genWeights23/F"        );
  NewTreeSB->Branch("genWeights24",         &genWeights24,         "genWeights24/F"        );
  NewTreeSB->Branch("genWeights25",         &genWeights25,         "genWeights25/F"        );
  NewTreeSB->Branch("genWeights26",         &genWeights26,         "genWeights26/F"        );
  NewTreeSB->Branch("genWeights27",         &genWeights27,         "genWeights27/F"        );
  NewTreeSB->Branch("genWeights28",         &genWeights28,         "genWeights28/F"        );
  NewTreeSB->Branch("genWeights29",         &genWeights29,         "genWeights29/F"        );
  NewTreeSB->Branch("genWeights30",         &genWeights30,         "genWeights30/F"        );
  NewTreeSB->Branch("genWeights31",         &genWeights31,         "genWeights31/F"        );
  NewTreeSB->Branch("genWeights32",         &genWeights32,         "genWeights32/F"        );
  NewTreeSB->Branch("genWeights33",         &genWeights33,         "genWeights33/F"        );
  NewTreeSB->Branch("genWeights34",         &genWeights34,         "genWeights34/F"        );
  NewTreeSB->Branch("genWeights35",         &genWeights35,         "genWeights35/F"        );
  NewTreeSB->Branch("genWeights36",         &genWeights36,         "genWeights36/F"        );
  NewTreeSB->Branch("genWeights37",         &genWeights37,         "genWeights37/F"        );
  NewTreeSB->Branch("genWeights38",         &genWeights38,         "genWeights38/F"        );
  NewTreeSB->Branch("genWeights39",         &genWeights39,         "genWeights39/F"        );
  NewTreeSB->Branch("genWeights40",         &genWeights40,         "genWeights40/F"        );
  NewTreeSB->Branch("genWeights41",         &genWeights41,         "genWeights41/F"        );
  NewTreeSB->Branch("genWeights42",         &genWeights42,         "genWeights42/F"        );
  NewTreeSB->Branch("genWeights43",         &genWeights43,         "genWeights43/F"        );
  NewTreeSB->Branch("genWeights44",         &genWeights44,         "genWeights44/F"        );
  NewTreeSB->Branch("genWeights45",         &genWeights45,         "genWeights45/F"        );
  NewTreeSB->Branch("genWeights46",         &genWeights46,         "genWeights46/F"        );
  NewTreeSB->Branch("genWeights47",         &genWeights47,         "genWeights47/F"        );
  NewTreeSB->Branch("genWeights48",         &genWeights48,         "genWeights48/F"        );
  NewTreeSB->Branch("genWeights49",         &genWeights49,         "genWeights49/F"        );
  NewTreeSB->Branch("genWeights50",         &genWeights50,         "genWeights50/F"        );
  NewTreeSB->Branch("genWeights51",         &genWeights51,         "genWeights51/F"        );
  NewTreeSB->Branch("genWeights52",         &genWeights52,         "genWeights52/F"        );
  NewTreeSB->Branch("genWeights53",         &genWeights53,         "genWeights53/F"        );
  NewTreeSB->Branch("genWeights54",         &genWeights54,         "genWeights54/F"        );
  NewTreeSB->Branch("genWeights55",         &genWeights55,         "genWeights55/F"        );
  NewTreeSB->Branch("genWeights56",         &genWeights56,         "genWeights56/F"        );
  NewTreeSB->Branch("genWeights57",         &genWeights57,         "genWeights57/F"        );
  NewTreeSB->Branch("genWeights58",         &genWeights58,         "genWeights58/F"        );
  NewTreeSB->Branch("genWeights59",         &genWeights59,         "genWeights59/F"        );
  NewTreeSB->Branch("genWeights60",         &genWeights60,         "genWeights60/F"        );
  NewTreeSB->Branch("genWeights61",         &genWeights61,         "genWeights61/F"        );
  NewTreeSB->Branch("genWeights62",         &genWeights62,         "genWeights62/F"        );
  NewTreeSB->Branch("genWeights63",         &genWeights63,         "genWeights63/F"        );
  NewTreeSB->Branch("genWeights64",         &genWeights64,         "genWeights64/F"        );
  NewTreeSB->Branch("genWeights65",         &genWeights65,         "genWeights65/F"        );
  NewTreeSB->Branch("genWeights66",         &genWeights66,         "genWeights66/F"        );
  NewTreeSB->Branch("genWeights67",         &genWeights67,         "genWeights67/F"        );
  NewTreeSB->Branch("genWeights68",         &genWeights68,         "genWeights68/F"        );
  NewTreeSB->Branch("genWeights69",         &genWeights69,         "genWeights69/F"        );
  NewTreeSB->Branch("genWeights70",         &genWeights70,         "genWeights70/F"        );
  NewTreeSB->Branch("genWeights71",         &genWeights71,         "genWeights71/F"        );
  NewTreeSB->Branch("genWeights72",         &genWeights72,         "genWeights72/F"        );
  NewTreeSB->Branch("genWeights73",         &genWeights73,         "genWeights73/F"        );
  NewTreeSB->Branch("genWeights74",         &genWeights74,         "genWeights74/F"        );
  NewTreeSB->Branch("genWeights75",         &genWeights75,         "genWeights75/F"        );
  NewTreeSB->Branch("genWeights76",         &genWeights76,         "genWeights76/F"        );
  NewTreeSB->Branch("genWeights77",         &genWeights77,         "genWeights77/F"        );
  NewTreeSB->Branch("genWeights78",         &genWeights78,         "genWeights78/F"        );
  NewTreeSB->Branch("genWeights79",         &genWeights79,         "genWeights79/F"        );
  NewTreeSB->Branch("genWeights80",         &genWeights80,         "genWeights80/F"        );
  NewTreeSB->Branch("genWeights81",         &genWeights81,         "genWeights81/F"        );
  NewTreeSB->Branch("genWeights82",         &genWeights82,         "genWeights82/F"        );
  NewTreeSB->Branch("genWeights83",         &genWeights83,         "genWeights83/F"        );
  NewTreeSB->Branch("genWeights84",         &genWeights84,         "genWeights84/F"        );
  NewTreeSB->Branch("genWeights85",         &genWeights85,         "genWeights85/F"        );
  NewTreeSB->Branch("genWeights86",         &genWeights86,         "genWeights86/F"        );
  NewTreeSB->Branch("genWeights87",         &genWeights87,         "genWeights87/F"        );
  NewTreeSB->Branch("genWeights88",         &genWeights88,         "genWeights88/F"        );
  NewTreeSB->Branch("genWeights89",         &genWeights89,         "genWeights89/F"        );
  NewTreeSB->Branch("genWeights90",         &genWeights90,         "genWeights90/F"        );
  NewTreeSB->Branch("genWeights91",         &genWeights91,         "genWeights91/F"        );
  NewTreeSB->Branch("genWeights92",         &genWeights92,         "genWeights92/F"        );
  NewTreeSB->Branch("genWeights93",         &genWeights93,         "genWeights93/F"        );
  NewTreeSB->Branch("genWeights94",         &genWeights94,         "genWeights94/F"        );
  NewTreeSB->Branch("genWeights95",         &genWeights95,         "genWeights95/F"        );
  NewTreeSB->Branch("genWeights96",         &genWeights96,         "genWeights96/F"        );
  NewTreeSB->Branch("genWeights97",         &genWeights97,         "genWeights97/F"        );
  NewTreeSB->Branch("genWeights98",         &genWeights98,         "genWeights98/F"        );
  NewTreeSB->Branch("genWeights99",         &genWeights99,         "genWeights99/F"        );
  NewTreeSB->Branch("genWeights100",        &genWeights100,        "genWeights100/F"       );
  NewTreeSB->Branch("genWeights101",        &genWeights101,        "genWeights101/F"       );
  NewTreeSB->Branch("genWeights102",        &genWeights102,        "genWeights102/F"       );
  NewTreeSB->Branch("genWeights103",        &genWeights103,        "genWeights103/F"       );
  NewTreeSB->Branch("genWeights104",        &genWeights104,        "genWeights104/F"       );
  NewTreeSB->Branch("genWeights105",        &genWeights105,        "genWeights105/F"       );
  NewTreeSB->Branch("genWeights106",        &genWeights106,        "genWeights106/F"       );
  NewTreeSB->Branch("genWeights107",        &genWeights107,        "genWeights107/F"       );
  NewTreeSB->Branch("genWeights108",        &genWeights108,        "genWeights108/F"       );
  NewTreeSB->Branch("genWeights109",        &genWeights109,        "genWeights109/F"       );
  NewTreeSB->Branch("genWeights110",        &genWeights110,        "genWeights110/F"       );
  NewTreeSB->Branch("genWeights111",        &genWeights111,        "genWeights111/F"       );
  NewTreeSB->Branch("genWeights112",        &genWeights112,        "genWeights112/F"       );
  NewTreeSB->Branch("genWeights113",        &genWeights113,        "genWeights113/F"       );
  NewTreeSB->Branch("genWeights114",        &genWeights114,        "genWeights114/F"       );
  NewTreeSB->Branch("genWeights115",        &genWeights115,        "genWeights115/F"       );
  NewTreeSB->Branch("genWeights116",        &genWeights116,        "genWeights116/F"       );
  NewTreeSB->Branch("genWeights117",        &genWeights117,        "genWeights117/F"       );
  NewTreeSB->Branch("genWeights118",        &genWeights118,        "genWeights118/F"       );
  NewTreeSB->Branch("genWeights119",        &genWeights119,        "genWeights119/F"       );
  NewTreeSB->Branch("genWeights120",        &genWeights120,        "genWeights120/F"       );
  NewTreeSB->Branch("genWeights121",        &genWeights121,        "genWeights121/F"       );
  NewTreeSB->Branch("genWeights122",        &genWeights122,        "genWeights122/F"       );
  NewTreeSB->Branch("genWeights123",        &genWeights123,        "genWeights123/F"       );
  NewTreeSB->Branch("genWeights124",        &genWeights124,        "genWeights124/F"       );
  NewTreeSB->Branch("genWeights125",        &genWeights125,        "genWeights125/F"       );
  NewTreeSB->Branch("genWeights126",        &genWeights126,        "genWeights126/F"       );
  NewTreeSB->Branch("genWeights127",        &genWeights127,        "genWeights127/F"       );
  NewTreeSB->Branch("genWeights128",        &genWeights128,        "genWeights128/F"       );
  NewTreeSB->Branch("genWeights129",        &genWeights129,        "genWeights129/F"       );
  NewTreeSB->Branch("genWeights130",        &genWeights130,        "genWeights130/F"       );
  NewTreeSB->Branch("genWeights131",        &genWeights131,        "genWeights131/F"       );
  NewTreeSB->Branch("genWeights132",        &genWeights132,        "genWeights132/F"       );
  NewTreeSB->Branch("genWeights133",        &genWeights133,        "genWeights133/F"       );
  NewTreeSB->Branch("genWeights134",        &genWeights134,        "genWeights134/F"       );
  NewTreeSB->Branch("genWeights135",        &genWeights135,        "genWeights135/F"       );
  NewTreeSB->Branch("genWeights136",        &genWeights136,        "genWeights136/F"       );
  NewTreeSB->Branch("genWeights137",        &genWeights137,        "genWeights137/F"       );
  NewTreeSB->Branch("genWeights138",        &genWeights138,        "genWeights138/F"       );
  NewTreeSB->Branch("genWeights139",        &genWeights139,        "genWeights139/F"       );
  NewTreeSB->Branch("genWeights140",        &genWeights140,        "genWeights140/F"       );
  NewTreeSB->Branch("genWeights141",        &genWeights141,        "genWeights141/F"       );
  NewTreeSB->Branch("genWeights142",        &genWeights142,        "genWeights142/F"       );
  NewTreeSB->Branch("genWeights143",        &genWeights143,        "genWeights143/F"       );
  NewTreeSB->Branch("genWeights144",        &genWeights144,        "genWeights144/F"       );
  NewTreeSB->Branch("genWeights145",        &genWeights145,        "genWeights145/F"       );
  NewTreeSB->Branch("genWeights146",        &genWeights146,        "genWeights146/F"       );
  NewTreeSB->Branch("genWeights147",        &genWeights147,        "genWeights147/F"       );
  NewTreeSB->Branch("genWeights148",        &genWeights148,        "genWeights148/F"       );
  NewTreeSB->Branch("genWeights149",        &genWeights149,        "genWeights149/F"       );
  NewTreeSB->Branch("genWeights150",        &genWeights150,        "genWeights150/F"       );
  NewTreeSB->Branch("genWeights151",        &genWeights151,        "genWeights151/F"       );
  NewTreeSB->Branch("genWeights152",        &genWeights152,        "genWeights152/F"       );
  NewTreeSB->Branch("genWeights153",        &genWeights153,        "genWeights153/F"       );
  NewTreeSB->Branch("genWeights154",        &genWeights154,        "genWeights154/F"       );
  NewTreeSB->Branch("genWeights155",        &genWeights155,        "genWeights155/F"       );
  NewTreeSB->Branch("genWeights156",        &genWeights156,        "genWeights156/F"       );
  NewTreeSB->Branch("genWeights157",        &genWeights157,        "genWeights157/F"       );
  NewTreeSB->Branch("genWeights158",        &genWeights158,        "genWeights158/F"       );
  NewTreeSB->Branch("genWeights159",        &genWeights159,        "genWeights159/F"       );
  NewTreeSB->Branch("genWeights160",        &genWeights160,        "genWeights160/F"       );
  NewTreeSB->Branch("genWeights161",        &genWeights161,        "genWeights161/F"       );
  NewTreeSB->Branch("genWeights162",        &genWeights162,        "genWeights162/F"       );
  NewTreeSB->Branch("genWeights163",        &genWeights163,        "genWeights163/F"       );
  NewTreeSB->Branch("genWeights164",        &genWeights164,        "genWeights164/F"       );
  NewTreeSB->Branch("genWeights165",        &genWeights165,        "genWeights165/F"       );
  NewTreeSB->Branch("genWeights166",        &genWeights166,        "genWeights166/F"       );
  NewTreeSB->Branch("genWeights167",        &genWeights167,        "genWeights167/F"       );
  NewTreeSB->Branch("genWeights168",        &genWeights168,        "genWeights168/F"       );
  NewTreeSB->Branch("genWeights169",        &genWeights169,        "genWeights169/F"       );
  NewTreeSB->Branch("genWeights170",        &genWeights170,        "genWeights170/F"       );
  NewTreeSB->Branch("genWeights171",        &genWeights171,        "genWeights171/F"       );
  NewTreeSB->Branch("genWeights172",        &genWeights172,        "genWeights172/F"       );
  NewTreeSB->Branch("genWeights173",        &genWeights173,        "genWeights173/F"       );
  NewTreeSB->Branch("genWeights174",        &genWeights174,        "genWeights174/F"       );
  NewTreeSB->Branch("genWeights175",        &genWeights175,        "genWeights175/F"       );
  NewTreeSB->Branch("genWeights176",        &genWeights176,        "genWeights176/F"       );
  NewTreeSB->Branch("genWeights177",        &genWeights177,        "genWeights177/F"       );
  NewTreeSB->Branch("genWeights178",        &genWeights178,        "genWeights178/F"       );
  NewTreeSB->Branch("genWeights179",        &genWeights179,        "genWeights179/F"       );
  NewTreeSB->Branch("genWeights180",        &genWeights180,        "genWeights180/F"       );
  NewTreeSB->Branch("genWeights181",        &genWeights181,        "genWeights181/F"       );
  NewTreeSB->Branch("genWeights182",        &genWeights182,        "genWeights182/F"       );
  NewTreeSB->Branch("genWeights183",        &genWeights183,        "genWeights183/F"       );
  NewTreeSB->Branch("genWeights184",        &genWeights184,        "genWeights184/F"       );
  NewTreeSB->Branch("genWeights185",        &genWeights185,        "genWeights185/F"       );
  NewTreeSB->Branch("genWeights186",        &genWeights186,        "genWeights186/F"       );
  NewTreeSB->Branch("genWeights187",        &genWeights187,        "genWeights187/F"       );
  NewTreeSB->Branch("genWeights188",        &genWeights188,        "genWeights188/F"       );
  NewTreeSB->Branch("genWeights189",        &genWeights189,        "genWeights189/F"       );
  NewTreeSB->Branch("genWeights190",        &genWeights190,        "genWeights190/F"       );
  NewTreeSB->Branch("genWeights191",        &genWeights191,        "genWeights191/F"       );
  NewTreeSB->Branch("genWeights192",        &genWeights192,        "genWeights192/F"       );
  NewTreeSB->Branch("genWeights193",        &genWeights193,        "genWeights193/F"       );
  NewTreeSB->Branch("genWeights194",        &genWeights194,        "genWeights194/F"       );
  NewTreeSB->Branch("genWeights195",        &genWeights195,        "genWeights195/F"       );
  NewTreeSB->Branch("genWeights196",        &genWeights196,        "genWeights196/F"       );
  NewTreeSB->Branch("genWeights197",        &genWeights197,        "genWeights197/F"       );
  NewTreeSB->Branch("genWeights198",        &genWeights198,        "genWeights198/F"       );
  NewTreeSB->Branch("genWeights199",        &genWeights199,        "genWeights199/F"       );
  NewTreeSB->Branch("genWeights200",        &genWeights200,        "genWeights200/F"       );
  NewTreeSB->Branch("genWeights201",        &genWeights201,        "genWeights201/F"       );
  NewTreeSB->Branch("genWeights202",        &genWeights202,        "genWeights202/F"       );
  NewTreeSB->Branch("genWeights203",        &genWeights203,        "genWeights203/F"       );
  NewTreeSB->Branch("genWeights204",        &genWeights204,        "genWeights204/F"       );
  NewTreeSB->Branch("genWeights205",        &genWeights205,        "genWeights205/F"       );
  NewTreeSB->Branch("genWeights206",        &genWeights206,        "genWeights206/F"       );
  NewTreeSB->Branch("genWeights207",        &genWeights207,        "genWeights207/F"       );
  NewTreeSB->Branch("genWeights208",        &genWeights208,        "genWeights208/F"       );
  NewTreeSB->Branch("genWeights209",        &genWeights209,        "genWeights209/F"       );
  NewTreeSB->Branch("genWeights210",        &genWeights210,        "genWeights210/F"       );
  NewTreeSB->Branch("genWeights211",        &genWeights211,        "genWeights211/F"       );
  NewTreeSB->Branch("genWeights212",        &genWeights212,        "genWeights212/F"       );
  NewTreeSB->Branch("genWeights1001",          &genWeights1001,          "genWeights1001/F"         );
  NewTreeSB->Branch("genWeights1002",          &genWeights1002,          "genWeights1002/F"         );
  NewTreeSB->Branch("genWeights1003",          &genWeights1003,          "genWeights1003/F"         );
  NewTreeSB->Branch("genWeights1004",          &genWeights1004,          "genWeights1004/F"         );
  NewTreeSB->Branch("genWeights1005",          &genWeights1005,          "genWeights1005/F"         );
  NewTreeSB->Branch("genWeights1006",          &genWeights1006,          "genWeights1006/F"         );
  NewTreeSB->Branch("genWeights1007",          &genWeights1007,          "genWeights1007/F"         );
  NewTreeSB->Branch("genWeights1008",          &genWeights1008,          "genWeights1008/F"         );
  NewTreeSB->Branch("genWeights1009",          &genWeights1009,          "genWeights1009/F"         );
  NewTreeSB->Branch("genWeights2000",          &genWeights2000,          "genWeights2000/F"         );
  NewTreeSB->Branch("genWeights2001",          &genWeights2001,          "genWeights2001/F"         );
  NewTreeSB->Branch("genWeights2002",          &genWeights2002,          "genWeights2002/F"         );
  NewTreeSB->Branch("genWeights2003",          &genWeights2003,          "genWeights2003/F"         );
  NewTreeSB->Branch("genWeights2004",          &genWeights2004,          "genWeights2004/F"         );
  NewTreeSB->Branch("genWeights2005",          &genWeights2005,          "genWeights2005/F"         );
  NewTreeSB->Branch("genWeights2006",          &genWeights2006,          "genWeights2006/F"         );
  NewTreeSB->Branch("genWeights2007",          &genWeights2007,          "genWeights2007/F"         );
  NewTreeSB->Branch("genWeights2008",          &genWeights2008,          "genWeights2008/F"         );
  NewTreeSB->Branch("genWeights2009",          &genWeights2009,          "genWeights2009/F"         );
  NewTreeSB->Branch("genWeights2010",         &genWeights2010,         "genWeights2010/F"        );
  NewTreeSB->Branch("genWeights2011",         &genWeights2011,         "genWeights2011/F"        );
  NewTreeSB->Branch("genWeights2012",         &genWeights2012,         "genWeights2012/F"        );
  NewTreeSB->Branch("genWeights2013",         &genWeights2013,         "genWeights2013/F"        );
  NewTreeSB->Branch("genWeights2014",         &genWeights2014,         "genWeights2014/F"        );
  NewTreeSB->Branch("genWeights2015",         &genWeights2015,         "genWeights2015/F"        );
  NewTreeSB->Branch("genWeights2016",         &genWeights2016,         "genWeights2016/F"        );
  NewTreeSB->Branch("genWeights2017",         &genWeights2017,         "genWeights2017/F"        );
  NewTreeSB->Branch("genWeights2018",         &genWeights2018,         "genWeights2018/F"        );
  NewTreeSB->Branch("genWeights2019",         &genWeights2019,         "genWeights2019/F"        );
  NewTreeSB->Branch("genWeights2020",         &genWeights2020,         "genWeights2020/F"        );
  NewTreeSB->Branch("genWeights2021",         &genWeights2021,         "genWeights2021/F"        );
  NewTreeSB->Branch("genWeights2022",         &genWeights2022,         "genWeights2022/F"        );
  NewTreeSB->Branch("genWeights2023",         &genWeights2023,         "genWeights2023/F"        );
  NewTreeSB->Branch("genWeights2024",         &genWeights2024,         "genWeights2024/F"        );
  NewTreeSB->Branch("genWeights2025",         &genWeights2025,         "genWeights2025/F"        );
  NewTreeSB->Branch("genWeights2026",         &genWeights2026,         "genWeights2026/F"        );
  NewTreeSB->Branch("genWeights2027",         &genWeights2027,         "genWeights2027/F"        );
  NewTreeSB->Branch("genWeights2028",         &genWeights2028,         "genWeights2028/F"        );
  NewTreeSB->Branch("genWeights2029",         &genWeights2029,         "genWeights2029/F"        );
  NewTreeSB->Branch("genWeights2030",         &genWeights2030,         "genWeights2030/F"        );
  NewTreeSB->Branch("genWeights2031",         &genWeights2031,         "genWeights2031/F"        );
  NewTreeSB->Branch("genWeights2032",         &genWeights2032,         "genWeights2032/F"        );
  NewTreeSB->Branch("genWeights2033",         &genWeights2033,         "genWeights2033/F"        );
  NewTreeSB->Branch("genWeights2034",         &genWeights2034,         "genWeights2034/F"        );
  NewTreeSB->Branch("genWeights2035",         &genWeights2035,         "genWeights2035/F"        );
  NewTreeSB->Branch("genWeights2036",         &genWeights2036,         "genWeights2036/F"        );
  NewTreeSB->Branch("genWeights2037",         &genWeights2037,         "genWeights2037/F"        );
  NewTreeSB->Branch("genWeights2038",         &genWeights2038,         "genWeights2038/F"        );
  NewTreeSB->Branch("genWeights2039",         &genWeights2039,         "genWeights2039/F"        );
  NewTreeSB->Branch("genWeights2040",         &genWeights2040,         "genWeights2040/F"        );
  NewTreeSB->Branch("genWeights2041",         &genWeights2041,         "genWeights2041/F"        );
  NewTreeSB->Branch("genWeights2042",         &genWeights2042,         "genWeights2042/F"        );
  NewTreeSB->Branch("genWeights2043",         &genWeights2043,         "genWeights2043/F"        );
  NewTreeSB->Branch("genWeights2044",         &genWeights2044,         "genWeights2044/F"        );
  NewTreeSB->Branch("genWeights2045",         &genWeights2045,         "genWeights2045/F"        );
  NewTreeSB->Branch("genWeights2046",         &genWeights2046,         "genWeights2046/F"        );
  NewTreeSB->Branch("genWeights2047",         &genWeights2047,         "genWeights2047/F"        );
  NewTreeSB->Branch("genWeights2048",         &genWeights2048,         "genWeights2048/F"        );
  NewTreeSB->Branch("genWeights2049",         &genWeights2049,         "genWeights2049/F"        );
  NewTreeSB->Branch("genWeights2050",         &genWeights2050,         "genWeights2050/F"        );
  NewTreeSB->Branch("genWeights2051",         &genWeights2051,         "genWeights2051/F"        );
  NewTreeSB->Branch("genWeights2052",         &genWeights2052,         "genWeights2052/F"        );
  NewTreeSB->Branch("genWeights2053",         &genWeights2053,         "genWeights2053/F"        );
  NewTreeSB->Branch("genWeights2054",         &genWeights2054,         "genWeights2054/F"        );
  NewTreeSB->Branch("genWeights2055",         &genWeights2055,         "genWeights2055/F"        );
  NewTreeSB->Branch("genWeights2056",         &genWeights2056,         "genWeights2056/F"        );
  NewTreeSB->Branch("genWeights2057",         &genWeights2057,         "genWeights2057/F"        );
  NewTreeSB->Branch("genWeights2058",         &genWeights2058,         "genWeights2058/F"        );
  NewTreeSB->Branch("genWeights2059",         &genWeights2059,         "genWeights2059/F"        );
  NewTreeSB->Branch("genWeights2060",         &genWeights2060,         "genWeights2060/F"        );
  NewTreeSB->Branch("genWeights2061",         &genWeights2061,         "genWeights2061/F"        );
  NewTreeSB->Branch("genWeights2062",         &genWeights2062,         "genWeights2062/F"        );
  NewTreeSB->Branch("genWeights2063",         &genWeights2063,         "genWeights2063/F"        );
  NewTreeSB->Branch("genWeights2064",         &genWeights2064,         "genWeights2064/F"        );
  NewTreeSB->Branch("genWeights2065",         &genWeights2065,         "genWeights2065/F"        );
  NewTreeSB->Branch("genWeights2066",         &genWeights2066,         "genWeights2066/F"        );
  NewTreeSB->Branch("genWeights2067",         &genWeights2067,         "genWeights2067/F"        );
  NewTreeSB->Branch("genWeights2068",         &genWeights2068,         "genWeights2068/F"        );
  NewTreeSB->Branch("genWeights2069",         &genWeights2069,         "genWeights2069/F"        );
  NewTreeSB->Branch("genWeights2070",         &genWeights2070,         "genWeights2070/F"        );
  NewTreeSB->Branch("genWeights2071",         &genWeights2071,         "genWeights2071/F"        );
  NewTreeSB->Branch("genWeights2072",         &genWeights2072,         "genWeights2072/F"        );
  NewTreeSB->Branch("genWeights2073",         &genWeights2073,         "genWeights2073/F"        );
  NewTreeSB->Branch("genWeights2074",         &genWeights2074,         "genWeights2074/F"        );
  NewTreeSB->Branch("genWeights2075",         &genWeights2075,         "genWeights2075/F"        );
  NewTreeSB->Branch("genWeights2076",         &genWeights2076,         "genWeights2076/F"        );
  NewTreeSB->Branch("genWeights2077",         &genWeights2077,         "genWeights2077/F"        );
  NewTreeSB->Branch("genWeights2078",         &genWeights2078,         "genWeights2078/F"        );
  NewTreeSB->Branch("genWeights2079",         &genWeights2079,         "genWeights2079/F"        );
  NewTreeSB->Branch("genWeights2080",         &genWeights2080,         "genWeights2080/F"        );
  NewTreeSB->Branch("genWeights2081",         &genWeights2081,         "genWeights2081/F"        );
  NewTreeSB->Branch("genWeights2082",         &genWeights2082,         "genWeights2082/F"        );
  NewTreeSB->Branch("genWeights2083",         &genWeights2083,         "genWeights2083/F"        );
  NewTreeSB->Branch("genWeights2084",         &genWeights2084,         "genWeights2084/F"        );
  NewTreeSB->Branch("genWeights2085",         &genWeights2085,         "genWeights2085/F"        );
  NewTreeSB->Branch("genWeights2086",         &genWeights2086,         "genWeights2086/F"        );
  NewTreeSB->Branch("genWeights2087",         &genWeights2087,         "genWeights2087/F"        );
  NewTreeSB->Branch("genWeights2088",         &genWeights2088,         "genWeights2088/F"        );
  NewTreeSB->Branch("genWeights2089",         &genWeights2089,         "genWeights2089/F"        );
  NewTreeSB->Branch("genWeights2090",         &genWeights2090,         "genWeights2090/F"        );
  NewTreeSB->Branch("genWeights2091",         &genWeights2091,         "genWeights2091/F"        );
  NewTreeSB->Branch("genWeights2092",         &genWeights2092,         "genWeights2092/F"        );
  NewTreeSB->Branch("genWeights2093",         &genWeights2093,         "genWeights2093/F"        );
  NewTreeSB->Branch("genWeights2094",         &genWeights2094,         "genWeights2094/F"        );
  NewTreeSB->Branch("genWeights2095",         &genWeights2095,         "genWeights2095/F"        );
  NewTreeSB->Branch("genWeights2096",         &genWeights2096,         "genWeights2096/F"        );
  NewTreeSB->Branch("genWeights2097",         &genWeights2097,         "genWeights2097/F"        );
  NewTreeSB->Branch("genWeights2098",         &genWeights2098,         "genWeights2098/F"        );
  NewTreeSB->Branch("genWeights2099",         &genWeights2099,         "genWeights2099/F"        );
  NewTreeSB->Branch("genWeights2100",        &genWeights2100,        "genWeights2100/F"       );
  NewTreeSB->Branch("dQuark",&dQuark,"dQuark/I");
  NewTreeSB->Branch("uQuark",&uQuark,"uQuark/I");
  NewTreeSB->Branch("sQuark",&sQuark,"sQuark/I");
  NewTreeSB->Branch("cQuark",&cQuark,"cQuark/I");
  NewTreeSB->Branch("bQuark",&bQuark,"bQuark/I");
  NewTreeSB->Branch("tQuark",&tQuark,"tQuark/I");
  //NewTreeSB->Branch("EVENT_event",&EVENT_event,"EVENT_event/I");
  NewTreeSB->Branch("EVENT_run",&EVENT_run,"EVENT_run/I");
  NewTreeSB->Branch("EVENT_lumiBlock",&EVENT_lumiBlock,"EVENT_lumiBlock/I");
  NewTreeSB->Branch("EVENT_genHT",&EVENT_genHT,"EVENT_genHT/F");
  NewTreeSB->Branch("prefiringweight",&prefiringweight,"prefiringweight/F");
  NewTreeSB->Branch("prefiringweightup",&prefiringweightup,"prefiringweightup/F");
  NewTreeSB->Branch("prefiringweightdown",&prefiringweightdown,"prefiringweightdown/F");
  NewTreeSB->Branch("Met_pt",&Met_pt,"Met_pt/F");
  NewTreeSB->Branch("Met_phi",&Met_phi,"Met_phi/F");
  NewTreeSB->Branch("TransverseMassMetTop",&TransverseMassMetTop,"TransverseMassMetTop/F");
}

void initializeVar(){
  category0=0;
  category1=0;
  category2=0;
  category3=0;
  category4=0;
  category5=0;
  category6=0;
  category7=0;
  BMass=-99;
  BCSV=-99;
  BPt=-99;
  BEta=-99;
  BPhi=-99;
  TopMass=-99;
  TopMassMerged=-99;
  TopMassPartial=-99;
  TopMassResolved=-99;
  TopPt=-99;
  TopPtMerged=-99;
  TopPtPartial=-99;
  TopPtResolved=-99;
  TopEta=-99;
  TopEtaMerged=-99;
  TopEtaPartial=-99;
  TopEtaResolved=-99;
  TopPhi=-99;
  TopPhiMerged=-99;
  TopPhiPartial=-99;
  TopPhiResolved=-99;
  WMassResolved1=-99;
  WMassResolved2=-99;
  WMassResolved3=-99;
  ZMass=-99;
  ZPt=-99;
  ZEta=-99;
  ZPhi=-99;
  TprimeMass=-99;
  TprimePt=-99;
  TprimeEta=-99;
  TprimePhi=-99;
  TprimeResolvedMass=-99;
  TprimeResolvedPt=-99;
  TprimeResolvedEta=-99;
  TprimeResolvedPhi=-99;
  TprimePartialMass=-99;
  TprimePartialPt=-99;
  TprimePartialEta=-99;
  TprimePartialPhi=-99;
  TprimeMergedMass=-99;
  TprimeMergedPt=-99;
  TprimeMergedEta=-99;
  TprimeMergedPhi=-99;
  Electron1Pt=-99;
  Electron2Pt=-99;
  Electron1E=-99;
  Electron2E=-99;
  Muon1Iso=-99;
  Muon2Iso=-99;
  Muon1Pt=-99;
  Muon2Pt=-99;
  Electron1Eta=-99;
  Electron2Eta=-99;
  Muon1Eta=-99;
  Muon2Eta=-99;
  Electron1Phi=-99;
  Electron2Phi=-99;
  Muon1Phi=-99;
  Muon2Phi=-99;
  deltaPhiZTop=-99;
  deltaRZTop=-99;
  deltaPhiZTopResolved=-99;
  deltaRZTopResolved=-99;
  deltaPhiZTopPartial=-99;
  deltaRZTopPartial=-99;
  deltaPhiZTopMerged=-99;
  deltaRZTopMerged=-99;
  deltaRbTop=-99;
  deltaREle1Ele2=-99;
  deltaRMuo1Muo2=-99;
  deltaPhiMetTop=-99.;
  Massb1b2=-99;
  MinDeltaPhiJetMet=99.;
  MinDeltaPhiBoostedJetMet=99.;
  deltaRb1b2=-99;
  deltaRb1Lep1=-99;
  deltaRb1Lep2=-99;
  deltaRb2Lep1=-99;
  deltaRb2Lep2=-99;
  Jet1ForwardEta=-99;
  Jet2ForwardEta=-99;
  Jet3ForwardEta=-99;
  Jet1ForwardPt=-99;
  Jet2ForwardPt=-99;
  Jet3ForwardPt=-99;
  Jet1ResolvedPt=-99;
  Jet2ResolvedPt=-99;
  Jet3ResolvedPt=-99;
  Jet1PartialPt=-99;
  Jet2PartialPt=-99;
  Jet1MergedPt=-99;
  Jet1ResolvedEta=-99;
  Jet2ResolvedEta=-99;
  Jet3ResolvedEta=-99;
  Jet1PartialEta=-99;
  Jet2PartialEta=-99;
  Jet1MergedEta=-99;
  MostForwardJetEta=-99;
  MostForwardJetPt=-99;
  NumSelLeps=-99;
  NumSelJets=-99;
  NumSelForwardJets=-99;
  NumSelBJetsL=-99;
  NumSelBJetsM=-99;
  NumSelBJetsT=-99;
  NumSelWJets=-99;
  NumSelTopJets=-99;
  NVertices=-99;
  HT=-99;
  PUWeight=1;
  PUWeightUP=1;
  PUWeightDOWN=1;
  EVENT_event=-99;
  EVENT_run=-99;
  EVENT_lumiBlock=-99;
  EVENT_genHT=-99;
  prefiringweight = 1;
  prefiringweightup = 1;
  prefiringweightdown = 1;
  Met_pt = -99.;
  Met_phi = -99.;
  getTrueNumInteractions=-99;
  w_for = 1;
  w_forUp = 1;
  w_forDown = 1;
  w_topJet = 1;
  w_topJetUp = 1;
  w_topJetDown = 1;
  w_WJet   = 1;
  w_WJetUp   = 1;
  w_WJetDown   = 1;
  w_Muon1  = 1;
  w_Muon2  = 1;
  w_Muon1Up  = 1;
  w_Muon2Up  = 1;
  w_Muon1Down  = 1;
  w_Muon2Down  = 1;
  w_TrigMuon  = 1;
  w_TrigMuonUp  = 1;
  w_TrigMuonDown  = 1;
  w_Electron1  = 1;
  w_Electron2  = 1;
  w_Electron1Up  = 1;
  w_Electron2Up  = 1;
  w_Electron1Down  = 1;
  w_Electron2Down  = 1;
  w_TrigElec  = 1;
  w_TrigElecUp  = 1;
  w_TrigElecDown  = 1;
  w_ZToNuNu=1;
  w_ZToNuNuUp=1;
  w_ZToNuNuDown=1;
  w_WToLNu=1;
  w_WToLNuUp=1;
  w_WToLNuDown=1;
  w_ttbar=1;
  w_ttbarUp=1;
  w_ttbarDown=1;
  WMass = -99;
  WSubjet = -99;
  TopSoftMass = -99;
  TopSubjet = -99;
  w_Btag=1;
  w_BtagUp=1;
  w_BtagDown=1;
  w_Btag1Up=1;
  w_Btag1Down=1;
  w_Btag2Up=1;
  w_Btag2Down=1;
  w_BtagLoose=1;
  w_BtagLooseUp=1;
  w_BtagLooseDown=1;
  w_QCDUp=1;
  w_QCDDown=1;
  w_PDFUp=1;
  w_PDFDown=1;
  genWeight=1;
  genWeights0=1;
  genWeights1=1;
  genWeights2=1;
  genWeights3=1;
  genWeights4=1;
  genWeights5=1;
  genWeights6=1;
  genWeights7=1;
  genWeights8=1;
  genWeights9=1;
  genWeights10=1;
  genWeights11=1;
  genWeights12=1;
  genWeights13=1;
  genWeights14=1;
  genWeights15=1;
  genWeights16=1;
  genWeights17=1;
  genWeights18=1;
  genWeights19=1;
  genWeights20=1;
  genWeights21=1;
  genWeights22=1;
  genWeights23=1;
  genWeights24=1;
  genWeights25=1;
  genWeights26=1;
  genWeights27=1;
  genWeights28=1;
  genWeights29=1;
  genWeights30=1;
  genWeights31=1;
  genWeights32=1;
  genWeights33=1;
  genWeights34=1;
  genWeights35=1;
  genWeights36=1;
  genWeights37=1;
  genWeights38=1;
  genWeights39=1;
  genWeights40=1;
  genWeights41=1;
  genWeights42=1;
  genWeights43=1;
  genWeights44=1;
  genWeights45=1;
  genWeights46=1;
  genWeights47=1;
  genWeights48=1;
  genWeights49=1;
  genWeights50=1;
  genWeights51=1;
  genWeights52=1;
  genWeights53=1;
  genWeights54=1;
  genWeights55=1;
  genWeights56=1;
  genWeights57=1;
  genWeights58=1;
  genWeights59=1;
  genWeights60=1;
  genWeights61=1;
  genWeights62=1;
  genWeights63=1;
  genWeights64=1;
  genWeights65=1;
  genWeights66=1;
  genWeights67=1;
  genWeights68=1;
  genWeights69=1;
  genWeights70=1;
  genWeights71=1;
  genWeights72=1;
  genWeights73=1;
  genWeights74=1;
  genWeights75=1;
  genWeights76=1;
  genWeights77=1;
  genWeights78=1;
  genWeights79=1;
  genWeights80=1;
  genWeights81=1;
  genWeights82=1;
  genWeights83=1;
  genWeights84=1;
  genWeights85=1;
  genWeights86=1;
  genWeights87=1;
  genWeights88=1;
  genWeights89=1;
  genWeights90=1;
  genWeights91=1;
  genWeights92=1;
  genWeights93=1;
  genWeights94=1;
  genWeights95=1;
  genWeights96=1;
  genWeights97=1;
  genWeights98=1;
  genWeights99=1;
  genWeights100=1;
  genWeights101=1;
  genWeights102=1;
  genWeights103=1;
  genWeights104=1;
  genWeights105=1;
  genWeights106=1;
  genWeights107=1;
  genWeights108=1;
  genWeights109=1;
  genWeights110=1;
  genWeights111=1;
  genWeights112=1;
  genWeights113=1;
  genWeights114=1;
  genWeights115=1;
  genWeights116=1;
  genWeights117=1;
  genWeights118=1;
  genWeights119=1;
  genWeights120=1;
  genWeights121=1;
  genWeights122=1;
  genWeights123=1;
  genWeights124=1;
  genWeights125=1;
  genWeights126=1;
  genWeights127=1;
  genWeights128=1;
  genWeights129=1;
  genWeights130=1;
  genWeights131=1;
  genWeights132=1;
  genWeights133=1;
  genWeights134=1;
  genWeights135=1;
  genWeights136=1;
  genWeights137=1;
  genWeights138=1;
  genWeights139=1;
  genWeights140=1;
  genWeights141=1;
  genWeights142=1;
  genWeights143=1;
  genWeights144=1;
  genWeights145=1;
  genWeights146=1;
  genWeights147=1;
  genWeights148=1;
  genWeights149=1;
  genWeights150=1;
  genWeights151=1;
  genWeights152=1;
  genWeights153=1;
  genWeights154=1;
  genWeights155=1;
  genWeights156=1;
  genWeights157=1;
  genWeights158=1;
  genWeights159=1;
  genWeights160=1;
  genWeights161=1;
  genWeights162=1;
  genWeights163=1;
  genWeights164=1;
  genWeights165=1;
  genWeights166=1;
  genWeights167=1;
  genWeights168=1;
  genWeights169=1;
  genWeights170=1;
  genWeights171=1;
  genWeights172=1;
  genWeights173=1;
  genWeights174=1;
  genWeights175=1;
  genWeights176=1;
  genWeights177=1;
  genWeights178=1;
  genWeights179=1;
  genWeights180=1;
  genWeights181=1;
  genWeights182=1;
  genWeights183=1;
  genWeights184=1;
  genWeights185=1;
  genWeights186=1;
  genWeights187=1;
  genWeights188=1;
  genWeights189=1;
  genWeights190=1;
  genWeights191=1;
  genWeights192=1;
  genWeights193=1;
  genWeights194=1;
  genWeights195=1;
  genWeights196=1;
  genWeights197=1;
  genWeights198=1;
  genWeights199=1;
  genWeights200=1;
  genWeights201=1;
  genWeights202=1;
  genWeights203=1;
  genWeights204=1;
  genWeights205=1;
  genWeights206=1;
  genWeights207=1;
  genWeights208=1;
  genWeights209=1;
  genWeights210=1;
  genWeights211=1;
  genWeights212=1;
  genWeights1001=1;
  genWeights1002=1;
  genWeights1003=1;
  genWeights1004=1;
  genWeights1005=1;
  genWeights1006=1;
  genWeights1007=1;
  genWeights1008=1;
  genWeights1009=1;
  genWeights2000=1;
  genWeights2001=1;
  genWeights2002=1;
  genWeights2003=1;
  genWeights2004=1;
  genWeights2005=1;
  genWeights2006=1;
  genWeights2007=1;
  genWeights2008=1;
  genWeights2009=1;
  genWeights2010=1;
  genWeights2011=1;
  genWeights2012=1;
  genWeights2013=1;
  genWeights2014=1;
  genWeights2015=1;
  genWeights2016=1;
  genWeights2017=1;
  genWeights2018=1;
  genWeights2019=1;
  genWeights2020=1;
  genWeights2021=1;
  genWeights2022=1;
  genWeights2023=1;
  genWeights2024=1;
  genWeights2025=1;
  genWeights2026=1;
  genWeights2027=1;
  genWeights2028=1;
  genWeights2029=1;
  genWeights2030=1;
  genWeights2031=1;
  genWeights2032=1;
  genWeights2033=1;
  genWeights2034=1;
  genWeights2035=1;
  genWeights2036=1;
  genWeights2037=1;
  genWeights2038=1;
  genWeights2039=1;
  genWeights2040=1;
  genWeights2041=1;
  genWeights2042=1;
  genWeights2043=1;
  genWeights2044=1;
  genWeights2045=1;
  genWeights2046=1;
  genWeights2047=1;
  genWeights2048=1;
  genWeights2049=1;
  genWeights2050=1;
  genWeights2051=1;
  genWeights2052=1;
  genWeights2053=1;
  genWeights2054=1;
  genWeights2055=1;
  genWeights2056=1;
  genWeights2057=1;
  genWeights2058=1;
  genWeights2059=1;
  genWeights2060=1;
  genWeights2061=1;
  genWeights2062=1;
  genWeights2063=1;
  genWeights2064=1;
  genWeights2065=1;
  genWeights2066=1;
  genWeights2067=1;
  genWeights2068=1;
  genWeights2069=1;
  genWeights2070=1;
  genWeights2071=1;
  genWeights2072=1;
  genWeights2073=1;
  genWeights2074=1;
  genWeights2075=1;
  genWeights2076=1;
  genWeights2077=1;
  genWeights2078=1;
  genWeights2079=1;
  genWeights2080=1;
  genWeights2081=1;
  genWeights2082=1;
  genWeights2083=1;
  genWeights2084=1;
  genWeights2085=1;
  genWeights2086=1;
  genWeights2087=1;
  genWeights2088=1;
  genWeights2089=1;
  genWeights2090=1;
  genWeights2091=1;
  genWeights2092=1;
  genWeights2093=1;
  genWeights2094=1;
  genWeights2095=1;
  genWeights2096=1;
  genWeights2097=1;
  genWeights2098=1;
  genWeights2099=1;
  genWeights2100=1;
  GenZPt=-99.;
  GenWPt=-99.;
  dQuark=0;
  uQuark=0;
  sQuark=0;
  cQuark=0;
  bQuark=0;
  tQuark=0;
  TriggeringElePt  = -1.;
  TriggeringMuoPt  = -1.;
  TriggeringEleEta = -1.;
  TriggeringMuoEta = -1.;
  TransverseMassMetTop = -99;
}

void branchGetEntry(bool data, Long64_t tentry, string fileName){
  b_Jet_pt->GetEntry(tentry);
  b_Jet_eta->GetEntry(tentry);
  b_Jet_phi->GetEntry(tentry);
  b_Jet_mass->GetEntry(tentry);
  b_Jet_JesSF->GetEntry(tentry);
  b_Jet_JesSFup->GetEntry(tentry);
  b_Jet_JesSFdown->GetEntry(tentry);
  b_Jet_JerSF->GetEntry(tentry);
  b_Jet_JerSFup->GetEntry(tentry);
  b_Jet_JerSFdown->GetEntry(tentry);
  b_Jet_Uncorr_pt->GetEntry(tentry);
  b_Jet_pfCombinedInclusiveSecondaryVertexV2BJetTags->GetEntry(tentry);
  b_Jet_pfDeepCSVBJetTags->GetEntry(tentry);
  b_Jet_neutralHadEnergyFraction->GetEntry(tentry);
  b_Jet_chargedEmEnergyFraction->GetEntry(tentry);
  b_Jet_neutralEmEnergyFraction->GetEntry(tentry);
  b_Jet_numberOfConstituents->GetEntry(tentry);
  b_Jet_chargedHadronEnergyFraction->GetEntry(tentry);
  b_Jet_chargedMultiplicity->GetEntry(tentry);
  if(!data) b_Jet_hadronFlavour->GetEntry(tentry);
  b_BoostedJet_pt->GetEntry(tentry);
  b_BoostedJet_Uncorr_pt->GetEntry(tentry);
  b_BoostedJet_softdrop_mass->GetEntry(tentry);
  b_BoostedJet_JesSF->GetEntry(tentry);
  b_BoostedJet_JesSFup->GetEntry(tentry);
  b_BoostedJet_JesSFdown->GetEntry(tentry);
  b_BoostedJet_JerSF->GetEntry(tentry);
  b_BoostedJet_JerSFup->GetEntry(tentry);
  b_BoostedJet_JerSFdown->GetEntry(tentry);
  b_BoostedJet_eta->GetEntry(tentry);
  b_BoostedJet_phi->GetEntry(tentry);
  b_BoostedJet_mass->GetEntry(tentry);
  b_BoostedJet_tau1->GetEntry(tentry);
  b_BoostedJet_tau2->GetEntry(tentry);
  b_BoostedJet_tau3->GetEntry(tentry);
  b_BoostedJet_pruned_mass->GetEntry(tentry);
  b_BoostedJet_neutralHadEnergyFraction->GetEntry(tentry);
  b_BoostedJet_neutralEmEnergyFraction->GetEntry(tentry);
  b_BoostedJet_chargedEmEnergyFraction->GetEntry(tentry);
  //b_BoostedJet_neutralEmEmEnergyFraction->GetEntry(tentry);
  b_BoostedJet_numberOfConstituents->GetEntry(tentry);
  b_BoostedJet_chargedHadronEnergyFraction->GetEntry(tentry);
  b_BoostedJet_chargedMultiplicity->GetEntry(tentry);
  //b_TopTagging_topMass->GetEntry(tentry);
  //b_TopTagging_minMass->GetEntry(tentry);
  //b_TopTagging_nSubJets->GetEntry(tentry);
  b_patElectron_pt->GetEntry(tentry);
  b_patElectron_eta->GetEntry(tentry);
  b_patElectron_phi->GetEntry(tentry);
  b_patElectron_energy->GetEntry(tentry);
  //b_patElectron_energyCorr->GetEntry(tentry);
  b_patElectron_SCeta->GetEntry(tentry);
  b_patElectron_charge->GetEntry(tentry);
  b_patElectron_isPassVeto->GetEntry(tentry);          
  b_patElectron_isPassLoose->GetEntry(tentry);
  b_patElectron_isPassMedium->GetEntry(tentry);
  b_patElectron_isPassTight->GetEntry(tentry);
  b_patElectron_isPassHEEPId->GetEntry(tentry);
  b_patElectron_passConversionVeto->GetEntry(tentry); 
  b_patElectron_inCrack->GetEntry(tentry);
  b_patElectron_isMatchedToTrigger->GetEntry(tentry);
  b_Muon_pt->GetEntry(tentry);
  b_Muon_eta->GetEntry(tentry);
  b_Muon_phi->GetEntry(tentry);
  b_Muon_energy->GetEntry(tentry);
  b_Muon_charge->GetEntry(tentry);
  b_Muon_tight->GetEntry(tentry);
  b_Muon_loose->GetEntry(tentry);
  b_Muon_medium->GetEntry(tentry);       
  b_Muon_relIsoDeltaBetaR04->GetEntry(tentry);
  b_Muon_isMatchedToTrigger->GetEntry(tentry);
  b_Met_type1PF_pt->GetEntry(tentry);
  b_Met_type1PF_phi->GetEntry(tentry);
  b_Met_type1PF_sumEt->GetEntry(tentry);
  b_HLT_DoubleEle33_CaloIdL_MW->GetEntry(tentry);
  b_HLT_Mu50->GetEntry(tentry);
  b_HLT_TkMu50->GetEntry(tentry);
  //b_HLT_PFHT500_PFMET100_PFMHT100_IDTight->GetEntry(tentry);
  //b_HLT_PFHT700_PFMET85_PFMHT85_IDTight->GetEntry(tentry);
  //b_HLT_PFHT800_PFMET75_PFMHT75_IDTight->GetEntry(tentry);
  b_HLT_PFMET120_PFMHT120_IDTight->GetEntry(tentry);
  b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight->GetEntry(tentry);
  //b_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight->GetEntry(tentry);
  //b_HLT_CaloJet500_NoJetID->GetEntry(tentry);
  //b_HLT_AK8PFJet500->GetEntry(tentry);
  //b_HLT_PFJet500->GetEntry(tentry);
  //b_HLT_PFHT1050->GetEntry(tentry);
  b_Flag_goodVertices->GetEntry(tentry);
  //b_Flag_CSCTightHalo2015Filter->GetEntry(tentry);
  b_Flag_HBHENoiseFilter->GetEntry(tentry);
  b_Flag_HBHENoiseIsoFilter->GetEntry(tentry);
  b_Flag_EcalDeadCellTriggerPrimitiveFilter->GetEntry(tentry);
  b_Flag_BadPFMuonFilter->GetEntry(tentry);
  b_Flag_BadChargedCandidateFilter->GetEntry(tentry);
  //b_Flag_ecalBadCalibReducedMINIAODFilter->GetEntry(tentry);
  b_Flag_eeBadScFilter->GetEntry(tentry);
  b_Flag_globalSuperTightHalo2016Filter->GetEntry(tentry);
  b_nBestVtx->GetEntry(tentry);
  b_PUWeight->GetEntry(tentry);
  //b_PUWeightUP->GetEntry(tentry);
  //b_PUWeightDOWN->GetEntry(tentry);
  b_EVENT_run->GetEntry(tentry);
  //b_EVENT_event->GetEntry(tentry);
  b_EVENT_lumiBlock->GetEntry(tentry);
  b_EVENT_genHT->GetEntry(tentry);
  b_genWeight->GetEntry(tentry);
  b_EVENT_prefiringweight->GetEntry(tentry);
  b_EVENT_prefiringweightup->GetEntry(tentry);
  b_EVENT_prefiringweightdown->GetEntry(tentry);
  if(!data) b_Gen_pt->GetEntry(tentry);
  if(!data) b_Gen_eta->GetEntry(tentry);
  if(!data) b_Gen_phi->GetEntry(tentry);
  if(!data) b_Gen_pdg_id->GetEntry(tentry);
  if(!data) b_Gen_motherpdg_id->GetEntry(tentry);
  b_genWeights->GetEntry(tentry);
}

void HistoFill(float puweight,TTree *NewTree){
  NewTree->Fill();
}

void writeFile(TTree *NewTree,TTree *NewTreeSB){
  NewTree->Write();
  NewTreeSB->Write();
}

void fillgenWeights(){
  genWeights0       = (*genWeights_)[0];
  genWeights1       = (*genWeights_)[1];
  genWeights2       = (*genWeights_)[2];
  genWeights3       = (*genWeights_)[3];
  genWeights4       = (*genWeights_)[4];
  genWeights5       = (*genWeights_)[5];
  genWeights6       = (*genWeights_)[6];
  genWeights7       = (*genWeights_)[7];
  genWeights8       = (*genWeights_)[8];
  genWeights9       = (*genWeights_)[9];
  genWeights10      = (*genWeights_)[10];
  genWeights11      = (*genWeights_)[11];
  genWeights12      = (*genWeights_)[12];
  genWeights13      = (*genWeights_)[13];
  genWeights14      = (*genWeights_)[14];
  genWeights15      = (*genWeights_)[15];
  genWeights16      = (*genWeights_)[16];
  genWeights17      = (*genWeights_)[17];
  genWeights18      = (*genWeights_)[18];
  genWeights19      = (*genWeights_)[19];
  genWeights20      = (*genWeights_)[20];
  genWeights21      = (*genWeights_)[21];
  genWeights22      = (*genWeights_)[22];
  genWeights23      = (*genWeights_)[23];
  genWeights24      = (*genWeights_)[24];
  genWeights25      = (*genWeights_)[25];
  genWeights26      = (*genWeights_)[26];
  genWeights27      = (*genWeights_)[27];
  genWeights28      = (*genWeights_)[28];
  genWeights29      = (*genWeights_)[29];
  genWeights30      = (*genWeights_)[30];
  genWeights31      = (*genWeights_)[31];
  genWeights32      = (*genWeights_)[32];
  genWeights33      = (*genWeights_)[33];
  genWeights34      = (*genWeights_)[34];
  genWeights35      = (*genWeights_)[35];
  genWeights36      = (*genWeights_)[36];
  genWeights37      = (*genWeights_)[37];
  genWeights38      = (*genWeights_)[38];
  genWeights39      = (*genWeights_)[39];
  genWeights40      = (*genWeights_)[40];
  genWeights41      = (*genWeights_)[41];
  genWeights42      = (*genWeights_)[42];
  genWeights43      = (*genWeights_)[43];
  genWeights44      = (*genWeights_)[44];
  genWeights45      = (*genWeights_)[45];
  genWeights46      = (*genWeights_)[46];
  genWeights47      = (*genWeights_)[47];
  genWeights48      = (*genWeights_)[48];
  genWeights49      = (*genWeights_)[49];
  genWeights50      = (*genWeights_)[50];
  genWeights51      = (*genWeights_)[51];
  genWeights52      = (*genWeights_)[52];
  genWeights53      = (*genWeights_)[53];
  genWeights54      = (*genWeights_)[54];
  genWeights55      = (*genWeights_)[55];
  genWeights56      = (*genWeights_)[56];
  genWeights57      = (*genWeights_)[57];
  genWeights58      = (*genWeights_)[58];
  genWeights59      = (*genWeights_)[59];
  genWeights60      = (*genWeights_)[60];
  genWeights61      = (*genWeights_)[61];
  genWeights62      = (*genWeights_)[62];
  genWeights63      = (*genWeights_)[63];
  genWeights64      = (*genWeights_)[64];
  genWeights65      = (*genWeights_)[65];
  genWeights66      = (*genWeights_)[66];
  genWeights67      = (*genWeights_)[67];
  genWeights68      = (*genWeights_)[68];
  genWeights69      = (*genWeights_)[69];
  genWeights70      = (*genWeights_)[70];
  genWeights71      = (*genWeights_)[71];
  genWeights72      = (*genWeights_)[72];
  genWeights73      = (*genWeights_)[73];
  genWeights74      = (*genWeights_)[74];
  genWeights75      = (*genWeights_)[75];
  genWeights76      = (*genWeights_)[76];
  genWeights77      = (*genWeights_)[77];
  genWeights78      = (*genWeights_)[78];
  genWeights79      = (*genWeights_)[79];
  genWeights80      = (*genWeights_)[80];
  genWeights81      = (*genWeights_)[81];
  genWeights82      = (*genWeights_)[82];
  genWeights83      = (*genWeights_)[83];
  genWeights84      = (*genWeights_)[84];
  genWeights85      = (*genWeights_)[85];
  genWeights86      = (*genWeights_)[86];
  genWeights87      = (*genWeights_)[87];
  genWeights88      = (*genWeights_)[88];
  genWeights89      = (*genWeights_)[89];
  genWeights90      = (*genWeights_)[90];
  genWeights91      = (*genWeights_)[91];
  genWeights92      = (*genWeights_)[92];
  genWeights93      = (*genWeights_)[93];
  genWeights94      = (*genWeights_)[94];
  genWeights95      = (*genWeights_)[95];
  genWeights96      = (*genWeights_)[96];
  genWeights97      = (*genWeights_)[97];
  genWeights98      = (*genWeights_)[98];
  genWeights99      = (*genWeights_)[99];
  genWeights100     = (*genWeights_)[100];
  genWeights101     = (*genWeights_)[101];
  genWeights102     = (*genWeights_)[102];
  genWeights103     = (*genWeights_)[103];
  genWeights104     = (*genWeights_)[104];
  genWeights105     = (*genWeights_)[105];
  genWeights106     = (*genWeights_)[106];
  genWeights107     = (*genWeights_)[107];
  genWeights108     = (*genWeights_)[108];
  genWeights109     = (*genWeights_)[109];
  genWeights110     = (*genWeights_)[110];
  genWeights111     = (*genWeights_)[111];
  genWeights112     = (*genWeights_)[112];
  genWeights113     = (*genWeights_)[113];
  genWeights114     = (*genWeights_)[114];
  genWeights115     = (*genWeights_)[115];
  genWeights116     = (*genWeights_)[116];
  genWeights117     = (*genWeights_)[117];
  genWeights118     = (*genWeights_)[118];
  genWeights119     = (*genWeights_)[119];
  genWeights120     = (*genWeights_)[120];
  genWeights121     = (*genWeights_)[121];
  genWeights122     = (*genWeights_)[122];
  genWeights123     = (*genWeights_)[123];
  genWeights124     = (*genWeights_)[124];
  genWeights125     = (*genWeights_)[125];
  genWeights126     = (*genWeights_)[126];
  genWeights127     = (*genWeights_)[127];
  genWeights128     = (*genWeights_)[128];
  genWeights129     = (*genWeights_)[129];
  genWeights130     = (*genWeights_)[130];
  genWeights131     = (*genWeights_)[131];
  genWeights132     = (*genWeights_)[132];
  genWeights133     = (*genWeights_)[133];
  genWeights134     = (*genWeights_)[134];
  genWeights135     = (*genWeights_)[135];
  genWeights136     = (*genWeights_)[136];
  genWeights137     = (*genWeights_)[137];
  genWeights138     = (*genWeights_)[138];
  genWeights139     = (*genWeights_)[139];
  genWeights140     = (*genWeights_)[140];
  genWeights141     = (*genWeights_)[141];
  genWeights142     = (*genWeights_)[142];
  genWeights143     = (*genWeights_)[143];
  genWeights144     = (*genWeights_)[144];
  genWeights145     = (*genWeights_)[145];
  genWeights146     = (*genWeights_)[146];
  genWeights147     = (*genWeights_)[147];
  genWeights148     = (*genWeights_)[148];
  genWeights149     = (*genWeights_)[149];
  genWeights150     = (*genWeights_)[150];
  genWeights151     = (*genWeights_)[151];
  genWeights152     = (*genWeights_)[152];
  genWeights153     = (*genWeights_)[153];
  genWeights154     = (*genWeights_)[154];
  genWeights155     = (*genWeights_)[155];
  genWeights156     = (*genWeights_)[156];
  genWeights157     = (*genWeights_)[157];
  genWeights158     = (*genWeights_)[158];
  genWeights159     = (*genWeights_)[159];
  genWeights160     = (*genWeights_)[160];
  genWeights161     = (*genWeights_)[161];
  genWeights162     = (*genWeights_)[162];
  genWeights163     = (*genWeights_)[163];
  genWeights164     = (*genWeights_)[164];
  genWeights165     = (*genWeights_)[165];
  genWeights166     = (*genWeights_)[166];
  genWeights167     = (*genWeights_)[167];
  genWeights168     = (*genWeights_)[168];
  genWeights169     = (*genWeights_)[169];
  genWeights170     = (*genWeights_)[170];
  genWeights171     = (*genWeights_)[171];
  genWeights172     = (*genWeights_)[172];
  genWeights173     = (*genWeights_)[173];
  genWeights174     = (*genWeights_)[174];
  genWeights175     = (*genWeights_)[175];
  genWeights176     = (*genWeights_)[176];
  genWeights177     = (*genWeights_)[177];
  genWeights178     = (*genWeights_)[178];
  genWeights179     = (*genWeights_)[179];
  genWeights180     = (*genWeights_)[180];
  genWeights181     = (*genWeights_)[181];
  genWeights182     = (*genWeights_)[182];
  genWeights183     = (*genWeights_)[183];
  genWeights184     = (*genWeights_)[184];
  genWeights185     = (*genWeights_)[185];
  genWeights186     = (*genWeights_)[186];
  genWeights187     = (*genWeights_)[187];
  genWeights188     = (*genWeights_)[188];
  genWeights189     = (*genWeights_)[189];
  genWeights190     = (*genWeights_)[190];
  genWeights191     = (*genWeights_)[191];
  genWeights192     = (*genWeights_)[192];
  genWeights193     = (*genWeights_)[193];
  genWeights194     = (*genWeights_)[194];
  genWeights195     = (*genWeights_)[195];
  genWeights196     = (*genWeights_)[196];
  genWeights197     = (*genWeights_)[197];
  genWeights198     = (*genWeights_)[198];
  genWeights199     = (*genWeights_)[199];
  genWeights200     = (*genWeights_)[200];
  genWeights201     = (*genWeights_)[201];
  genWeights202     = (*genWeights_)[202];
  genWeights203     = (*genWeights_)[203];
  genWeights204     = (*genWeights_)[204];
  genWeights205     = (*genWeights_)[205];
  genWeights206     = (*genWeights_)[206];
  genWeights207     = (*genWeights_)[207];
  genWeights208     = (*genWeights_)[208];
  genWeights209     = (*genWeights_)[209];
  genWeights210     = (*genWeights_)[210];
  genWeights211     = (*genWeights_)[211];
  genWeights212     = (*genWeights_)[212];
   
  genWeights1001    = (*genWeights_)[1001];
  genWeights1002    = (*genWeights_)[1002];
  genWeights1003    = (*genWeights_)[1003];
  genWeights1004    = (*genWeights_)[1004];
  genWeights1005    = (*genWeights_)[1005];
  genWeights1006    = (*genWeights_)[1006];
  genWeights1007    = (*genWeights_)[1007];
  genWeights1008    = (*genWeights_)[1008];
  genWeights1009    = (*genWeights_)[1009];

  genWeights2000       = (*genWeights_)[2000];
  genWeights2001       = (*genWeights_)[2001];
  genWeights2002       = (*genWeights_)[2002];
  genWeights2003       = (*genWeights_)[2003];
  genWeights2004       = (*genWeights_)[2004];
  genWeights2005       = (*genWeights_)[2005];
  genWeights2006       = (*genWeights_)[2006];
  genWeights2007       = (*genWeights_)[2007];
  genWeights2008       = (*genWeights_)[2008];
  genWeights2009       = (*genWeights_)[2009];
  genWeights2010      = (*genWeights_)[2010];
  genWeights2011      = (*genWeights_)[2011];
  genWeights2012      = (*genWeights_)[2012];
  genWeights2013      = (*genWeights_)[2013];
  genWeights2014      = (*genWeights_)[2014];
  genWeights2015      = (*genWeights_)[2015];
  genWeights2016      = (*genWeights_)[2016];
  genWeights2017      = (*genWeights_)[2017];
  genWeights2018      = (*genWeights_)[2018];
  genWeights2019      = (*genWeights_)[2019];
  genWeights2020      = (*genWeights_)[2020];
  genWeights2021      = (*genWeights_)[2021];
  genWeights2022      = (*genWeights_)[2022];
  genWeights2023      = (*genWeights_)[2023];
  genWeights2024      = (*genWeights_)[2024];
  genWeights2025      = (*genWeights_)[2025];
  genWeights2026      = (*genWeights_)[2026];
  genWeights2027      = (*genWeights_)[2027];
  genWeights2028      = (*genWeights_)[2028];
  genWeights2029      = (*genWeights_)[2029];
  genWeights2030      = (*genWeights_)[2030];
  genWeights2031      = (*genWeights_)[2031];
  genWeights2032      = (*genWeights_)[2032];
  genWeights2033      = (*genWeights_)[2033];
  genWeights2034      = (*genWeights_)[2034];
  genWeights2035      = (*genWeights_)[2035];
  genWeights2036      = (*genWeights_)[2036];
  genWeights2037      = (*genWeights_)[2037];
  genWeights2038      = (*genWeights_)[2038];
  genWeights2039      = (*genWeights_)[2039];
  genWeights2040      = (*genWeights_)[2040];
  genWeights2041      = (*genWeights_)[2041];
  genWeights2042      = (*genWeights_)[2042];
  genWeights2043      = (*genWeights_)[2043];
  genWeights2044      = (*genWeights_)[2044];
  genWeights2045      = (*genWeights_)[2045];
  genWeights2046      = (*genWeights_)[2046];
  genWeights2047      = (*genWeights_)[2047];
  genWeights2048      = (*genWeights_)[2048];
  genWeights2049      = (*genWeights_)[2049];
  genWeights2050      = (*genWeights_)[2050];
  genWeights2051      = (*genWeights_)[2051];
  genWeights2052      = (*genWeights_)[2052];
  genWeights2053      = (*genWeights_)[2053];
  genWeights2054      = (*genWeights_)[2054];
  genWeights2055      = (*genWeights_)[2055];
  genWeights2056      = (*genWeights_)[2056];
  genWeights2057      = (*genWeights_)[2057];
  genWeights2058      = (*genWeights_)[2058];
  genWeights2059      = (*genWeights_)[2059];
  genWeights2060      = (*genWeights_)[2060];
  genWeights2061      = (*genWeights_)[2061];
  genWeights2062      = (*genWeights_)[2062];
  genWeights2063      = (*genWeights_)[2063];
  genWeights2064      = (*genWeights_)[2064];
  genWeights2065      = (*genWeights_)[2065];
  genWeights2066      = (*genWeights_)[2066];
  genWeights2067      = (*genWeights_)[2067];
  genWeights2068      = (*genWeights_)[2068];
  genWeights2069      = (*genWeights_)[2069];
  genWeights2070      = (*genWeights_)[2070];
  genWeights2071      = (*genWeights_)[2071];
  genWeights2072      = (*genWeights_)[2072];
  genWeights2073      = (*genWeights_)[2073];
  genWeights2074      = (*genWeights_)[2074];
  genWeights2075      = (*genWeights_)[2075];
  genWeights2076      = (*genWeights_)[2076];
  genWeights2077      = (*genWeights_)[2077];
  genWeights2078      = (*genWeights_)[2078];
  genWeights2079      = (*genWeights_)[2079];
  genWeights2080      = (*genWeights_)[2080];
  genWeights2081      = (*genWeights_)[2081];
  genWeights2082      = (*genWeights_)[2082];
  genWeights2083      = (*genWeights_)[2083];
  genWeights2084      = (*genWeights_)[2084];
  genWeights2085      = (*genWeights_)[2085];
  genWeights2086      = (*genWeights_)[2086];
  genWeights2087      = (*genWeights_)[2087];
  genWeights2088      = (*genWeights_)[2088];
  genWeights2089      = (*genWeights_)[2089];
  genWeights2090      = (*genWeights_)[2090];
  genWeights2091      = (*genWeights_)[2091];
  genWeights2092      = (*genWeights_)[2092];
  genWeights2093      = (*genWeights_)[2093];
  genWeights2094      = (*genWeights_)[2094];
  genWeights2095      = (*genWeights_)[2095];
  genWeights2096      = (*genWeights_)[2096];
  genWeights2097      = (*genWeights_)[2097];
  genWeights2098      = (*genWeights_)[2098];
  genWeights2099      = (*genWeights_)[2099];
  genWeights2100      = (*genWeights_)[2100];
}

void GenClassifier(float &GenZPt_,float &GenWPt_){
  for (UInt_t j = 0; j < Gen_pt_->size(); ++j) {
    //cout<<j<<" "<<Gen_pdg_id_->at(j)<<" "<<Gen_motherpdg_id_->at(j)<<" "<<Gen_pt_->at(j)<<endl;
    if(abs(Gen_pdg_id_->at(j))==1 && (abs(Gen_motherpdg_id_->at(j))==2212 || abs(Gen_motherpdg_id_->at(j))==21)) dQuark = dQuark + 1;
    if(abs(Gen_pdg_id_->at(j))==2 && (abs(Gen_motherpdg_id_->at(j))==2212 || abs(Gen_motherpdg_id_->at(j))==21)) uQuark = uQuark + 1;
    if(abs(Gen_pdg_id_->at(j))==3 && (abs(Gen_motherpdg_id_->at(j))==2212 || abs(Gen_motherpdg_id_->at(j))==21)) sQuark = sQuark + 1;
    if(abs(Gen_pdg_id_->at(j))==4 && (abs(Gen_motherpdg_id_->at(j))==2212 || abs(Gen_motherpdg_id_->at(j))==21)) cQuark = cQuark + 1;
    if(abs(Gen_pdg_id_->at(j))==5 && (abs(Gen_motherpdg_id_->at(j))==2212 || abs(Gen_motherpdg_id_->at(j))==21)) bQuark = bQuark + 1;
    if(abs(Gen_pdg_id_->at(j))==6 && (abs(Gen_motherpdg_id_->at(j))==2212 || abs(Gen_motherpdg_id_->at(j))==21)) tQuark = tQuark + 1;
	if(abs(Gen_pdg_id_->at(j))==23) GenZPt_ = Gen_pt_->at(j);
	if(abs(Gen_pdg_id_->at(j))==24) GenWPt_ = Gen_pt_->at(j);
  }
}


void GenWBoson(bool &matched, TLorentzVector Wjet){
  double dr1=99;  double dr2=99;  double dr3=99;  double dr4=99;  double dr5=99;  double dr6=99; 
  double dr7=99;  double dr8=99;  double dr9=99;  double dr10=99; double dr11=99; double dr12=99; 
  double dr13=99; double dr14=99; double dr15=99; double dr16=99; double dr17=99; double dr18=99; 
  for (UInt_t j = 0; j < Gen_pt_->size(); ++j) {
    //cout<<j<<" "<<Gen_pdg_id_->at(j)<<" "<<Gen_motherpdg_id_->at(j)<<" "<<Gen_pt_->at(j)<<endl;
    if(abs(Gen_pdg_id_->at(j))==1 && abs(Gen_motherpdg_id_->at(j))==24) dr1 = DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(abs(Gen_pdg_id_->at(j))==2 && abs(Gen_motherpdg_id_->at(j))==24) dr2 = DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(abs(Gen_pdg_id_->at(j))==3 && abs(Gen_motherpdg_id_->at(j))==24) dr3 = DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(abs(Gen_pdg_id_->at(j))==4 && abs(Gen_motherpdg_id_->at(j))==24) dr4 = DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(abs(Gen_pdg_id_->at(j))==5 && abs(Gen_motherpdg_id_->at(j))==24) dr5 = DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(abs(Gen_pdg_id_->at(j))==6 && abs(Gen_motherpdg_id_->at(j))==24) dr6 = DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==1 && abs(Gen_motherpdg_id_->at(j))==23) dr7 = DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==2 && abs(Gen_motherpdg_id_->at(j))==23) dr8 = DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==3 && abs(Gen_motherpdg_id_->at(j))==23) dr9 = DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==4 && abs(Gen_motherpdg_id_->at(j))==23) dr10= DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==5 && abs(Gen_motherpdg_id_->at(j))==23) dr11= DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==6 && abs(Gen_motherpdg_id_->at(j))==23) dr12= DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==-1&& abs(Gen_motherpdg_id_->at(j))==23) dr13= DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==-2&& abs(Gen_motherpdg_id_->at(j))==23) dr14= DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==-3&& abs(Gen_motherpdg_id_->at(j))==23) dr15= DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==-4&& abs(Gen_motherpdg_id_->at(j))==23) dr16= DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==-5&& abs(Gen_motherpdg_id_->at(j))==23) dr17= DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
    if(   (Gen_pdg_id_->at(j))==-6&& abs(Gen_motherpdg_id_->at(j))==23) dr18= DeltaR(Wjet.Eta(),Gen_eta_->at(j),Wjet.Phi(),Gen_phi_->at(j));
  }
  if((dr2 <0.8 && dr1 <0.8) || (dr2 <0.8 && dr3 <0.8) || (dr2 <0.8 && dr5 <0.8)) matched=true; //W -> ud/us/ub
  if((dr4 <0.8 && dr1 <0.8) || (dr4 <0.8 && dr3 <0.8) || (dr4 <0.8 && dr5 <0.8)) matched=true; //W -> cd/cs/cb
  //if((dr7 <0.8 && dr13<0.8) || (dr8 <0.8 && dr14<0.8) || (dr9 <0.8 && dr15<0.8)) matched=true; //Z -> dd/uu/ss
  //if((dr10<0.8 && dr16<0.8) || (dr11<0.8 && dr17<0.8) || (dr12<0.8 && dr18<0.8)) matched=true; //Z -> cc/bb/tt
}

void GenWeight(string fileName, float GenZPt_,float GenWPt_){
  //if(fileName.find("ZZTo4L")!=string::npos || fileName.find("ZZTo2L2Q")!=string::npos || fileName.find("WZTo1L1Nu2Q")!=string::npos || fileName.find("WZTo2L2Q")!=string::npos || fileName.find("ttZ")!=string::npos || fileName.find("WZTo3LNu")!=string::npos || fileName.find("tZq")!=string::npos || fileName.find("ttW")!=string::npos)  genWeight=(genWeight_)/abs(genWeight_);
  //else  genWeight=1;
  genWeight=(genWeight_)/abs(genWeight_);
  if(fileName.find("DY")!=string::npos || fileName.find("ZToNuNu")!=string::npos) {
    if(GenZPt_>0) genWeight = functZPt->Eval(GenZPt_);
    else genWeight = 1;
    }
  if(fileName.find("WToLNu")!=string::npos) {
    if(GenWPt_>0) genWeight = functWPt->Eval(GenWPt_);
    else genWeight = 1;
    }

}

/*void newPUWeight(float &puweight,float &puweightUP,float &puweightDOWN){
  double *npuProbs = 0;
  double *npuProbsNEW = 0;
  unsigned int nPUMax = 99;
  double npu_Moriond18Scenario[99] =  {3.39597497605e-05,6.63688402133e-06,1.39533611284e-05,3.64963078209e-05,6.00872171664e-05,9.33932578027e-05,0.000120591524486,0.000128694546198,0.000361697233219,0.000361796847553,0.000702474896113,0.00133766053707,0.00237817050805,0.00389825605651,0.00594546732588,0.00856825906255,0.0116627396044,0.0148793350787,0.0179897368379,0.0208723871946,0.0232564170641,0.0249826433945,0.0262245860346,0.0272704617569,0.0283301107549,0.0294006137386,0.0303026836965,0.0309692426278,0.0308818046328,0.0310566806228,0.0309692426278,0.0310566806228,0.0310566806228,0.0310566806228,0.0307696426944,0.0300103336052,0.0288355370103,0.0273233309106,0.0264343533951,0.0255453758796,0.0235877272306,0.0215627588047,0.0195825559393,0.0177296309658,0.0160560731931,0.0146022004183,0.0134080690078,0.0129586991411,0.0125093292745,0.0124360740539,0.0123547104433,0.0123953922486,0.0124360740539,0.0124360740539,0.0123547104433,0.0124360740539,0.0123387597772,0.0122414455005,0.011705203844,0.0108187105305,0.00963985508986,0.00827210065136,0.00683770076341,0.00545237697118,0.00420456901556,0.00367513566191,0.00314570230825,0.0022917978982,0.00163221454973,0.00114065309494,0.000784838366118,0.000533204105387,0.000358474034915,0.000238881117601,0.0001984254989,0.000157969880198,0.00010375646169,6.77366175538e-05,4.39850477645e-05,2.84298066026e-05,1.83041729561e-05,1.17473542058e-05,7.51982735129e-06,6.16160108867e-06,4.80337482605e-06,3.06235473369e-06,1.94863396999e-06,1.23726800704e-06,7.83538083774e-07,4.94602064224e-07,3.10989480331e-07,1.94628487765e-07,1.57888581037e-07,1.2114867431e-07,7.49518929908e-08,4.6060444984e-08,2.81008884326e-08,1.70121486128e-08,1.02159894812e-08};
  double npu_Moriond18ScenarioNEW[99] =  {0.0164731,0.000829522,0.000939881,0.000589732,0.000665918,0.00111637,0.00125813,0.000933965,0.00145441,0.00184519,0.00159332,0.00242139,0.00314767,0.00548591,0.00684822,0.010836,0.0130551,0.0144512,0.0182305,0.0212894,0.0216204,0.0229435,0.0243586,0.0243769,0.0249553,0.0269723,0.0255303,0.0269896,0.0277803,0.0279493,0.0271844,0.0273721,0.0293261,0.0282731,0.0287164,0.0283037,0.0265103,0.0255473,0.0240064,0.0233137,0.0232938,0.0224567,0.0196284,0.0156212,0.0137627,0.0136596,0.0128352,0.0120469,0.0128242,0.0121217,0.0136477,0.0136083,0.0134189,0.0129351,0.0141632,0.0136156,0.0141845,0.0124658,0.0128498,0.0125589,0.0102669,0.0092894,0.00807026,0.00702602,0.0047661,0.00401915,0.00351898,0.00288564,0.00166122,0.0015046,0.000773104,0.000499557,0.000796673,0.0006105,0.000630528,0.000145819,0.000191135,0.000340493,0.000193567,0.000678164,0.000393724,0.000442431,0.000641926,0.000615461,0.000139089,0.000793345,0.000240982,0.00049623,0.00010741,0.000147015,0.0002128,1.14866e-05,1.75821e-05,9.66776e-05,3.37481e-05,0.000457706,2.37272e-07,4.74544e-07,9.06185e-05};
  npuProbs = npu_Moriond18Scenario;
  npuProbsNEW = npu_Moriond18ScenarioNEW;
  std::vector<double> result(nPUMax,0.);
  std::vector<double> resultNEW(nPUMax,0.);
  std::vector<double> resultNEWUp(nPUMax,0.);
  std::vector<double> resultNEWDo(nPUMax,0.);
  double s = 0.;
  double sNEW   = 0.;
  double sNEWUp = 0.;
  double sNEWDo = 0.;
  for(unsigned int npu = 0; npu < nPUMax; ++npu) {
    const double npu_estimated = histoOldPU->GetBinContent(histoOldPU->GetXaxis()->FindBin(npu));
    result[npu] = npu_estimated / npuProbs[npu];
    s += npu_estimated;
    const double npu_estimatedNEW   = histoNewPU  ->GetBinContent(histoNewPU  ->GetXaxis()->FindBin(npu));
    const double npu_estimatedNEWUp = histoNewPUUp->GetBinContent(histoNewPUUp->GetXaxis()->FindBin(npu));
    const double npu_estimatedNEWDo = histoNewPUDo->GetBinContent(histoNewPUDo->GetXaxis()->FindBin(npu));
    resultNEW[npu]   = npu_estimatedNEW   / npuProbsNEW[npu];
    resultNEWUp[npu] = npu_estimatedNEWUp / npuProbsNEW[npu];
    resultNEWDo[npu] = npu_estimatedNEWDo / npuProbsNEW[npu];
    sNEW   += npu_estimatedNEW;
    sNEWUp += npu_estimatedNEWUp;
    sNEWDo += npu_estimatedNEWDo;
  }
  unsigned int NPU = -1;              
  for(unsigned int npu = 0; npu < nPUMax; ++npu) {
    result[npu] /= s;
    resultNEW[npu]   /= sNEW;
    resultNEWUp[npu] /= sNEWUp;
    resultNEWDo[npu] /= sNEWDo;
    //if(result[npu]==PUWeight_) NPU = npu;
	if(result[npu]<PUWeight_*1.0001 && result[npu]>PUWeight_*0.9999) NPU = npu;
  }
  //cout<<NPU<<" "<<PUWeight_<<" "<<resultNEW[NPU]<<" "<<resultNEWUp[NPU]<<endl;
  if(resultNEW[NPU]<9999)   puweight     = resultNEW[NPU];
  if(resultNEWUp[NPU]<9999) puweightUP   = resultNEWUp[NPU];
  if(resultNEWDo[NPU]<9999) puweightDOWN = resultNEWDo[NPU];
  getTrueNumInteractions=NPU;
}*/

/*void newPUWeight(float &puweight,float &puweightUP,float &puweightDOWN){
  double *npuProbs = 0;
  double *npuProbsNEW = 0;
  unsigned int nPUMax = 75;
  double npu_Moriond17Scenario[75] = {1.78653e-05,2.56602e-05,5.27857e-05,8.88954e-05,0.000109362,0.000140973,0.000240998,0.00071209,0.00130121,0.00245255,0.00502589,0.00919534,0.0146697,0.0204126,0.0267586,0.0337697,0.0401478,0.0450159,0.0490577,0.0524855,0.0548159,0.0559937,0.0554468,0.0537687,0.0512055,0.0476713,0.0435312,0.0393107,0.0349812,0.0307413,0.0272425,0.0237115,0.0208329,0.0182459,0.0160712,0.0142498,0.012804,0.011571,0.010547,0.00959489,0.00891718,0.00829292,0.0076195,0.0069806,0.0062025,0.00546581,0.00484127,0.00407168,0.00337681,0.00269893,0.00212473,0.00160208,0.00117884,0.000859662,0.000569085,0.000365431,0.000243565,0.00015688,9.88128e-05,6.53783e-05,3.73924e-05,2.61382e-05,2.0307e-05,1.73032e-05,1.435e-05,1.36486e-05,1.35555e-05,1.37491e-05,1.34255e-05,1.33987e-05,1.34061e-05,1.34211e-05,1.34177e-05,1.32959e-05,1.33287e-05};
  npuProbs = npu_Moriond17Scenario;
  std::vector<double> result(nPUMax,0.);
  std::vector<double> resultNEW(nPUMax,0.);
  std::vector<double> resultNEWUp(nPUMax,0.);
  std::vector<double> resultNEWDo(nPUMax,0.);
  double s = 0.;
  double sNEW   = 0.;
  double sNEWUp = 0.;
  double sNEWDo = 0.;
  for(unsigned int npu = 0; npu < nPUMax; ++npu) {
    const double npu_estimated = histoOldPU->GetBinContent(histoOldPU->GetXaxis()->FindBin(npu));
    result[npu] = npu_estimated / npuProbs[npu];
    s += npu_estimated;
    const double npu_estimatedNEW   = histoNewPU  ->GetBinContent(histoNewPU  ->GetXaxis()->FindBin(npu));
    const double npu_estimatedNEWUp = histoNewPUUp->GetBinContent(histoNewPUUp->GetXaxis()->FindBin(npu));
    const double npu_estimatedNEWDo = histoNewPUDo->GetBinContent(histoNewPUDo->GetXaxis()->FindBin(npu));
    resultNEW[npu]   = npu_estimatedNEW   / npuProbs[npu];
    resultNEWUp[npu] = npu_estimatedNEWUp / npuProbs[npu];
    resultNEWDo[npu] = npu_estimatedNEWDo / npuProbs[npu];
    sNEW   += npu_estimatedNEW;
    sNEWUp += npu_estimatedNEWUp;
    sNEWDo += npu_estimatedNEWDo;
  }
  unsigned int NPU = -1;       
  for(unsigned int npu = 0; npu < nPUMax; ++npu) {
    result[npu] /= s;
    resultNEW[npu]   /= sNEW;
    resultNEWUp[npu] /= sNEWUp;
    resultNEWDo[npu] /= sNEWDo;
    if(result[npu]<PUWeight_*1.0001 && result[npu]>PUWeight_*0.9999) NPU = npu;
   //if(result[npu]==PUWeight_) NPU = npu;
  }
  if (NPU==-1) return;
  //cout<<NPU<<" "<<PUWeight_<<" "<<resultNEW[NPU]<<" "<<resultNEWUp[NPU]<<endl;
  if(resultNEW[NPU]<9999)   puweight     = resultNEW[NPU];
  if(resultNEWUp[NPU]<9999) puweightUP   = resultNEWUp[NPU];
  if(resultNEWDo[NPU]<9999) puweightDOWN = resultNEWDo[NPU];
}*/
void newPUWeight(float &puweight,float &puweightUP,float &puweightDOWN){
   double *npuProbs = 0;
   double *npuProbsNEW = 0;
   unsigned int nPUMax = 75;
   double npu_mix_2016_25ns_SpringMC_PUScenarioV1[75] =  {1.78653e-05 
,2.56602e-05 ,5.27857e-05 ,8.88954e-05 ,0.000109362 ,0.000140973 
,0.000240998 ,0.00071209 ,0.00130121 ,0.00245255 ,0.00502589 ,0.00919534 
,0.0146697 ,0.0204126 ,0.0267586 ,0.0337697 ,0.0401478 ,0.0450159 
,0.0490577 ,0.0524855 ,0.0548159 ,0.0559937 ,0.0554468 ,0.0537687 
,0.0512055 ,0.0476713 ,0.0435312 ,0.0393107 ,0.0349812 ,0.0307413 
,0.0272425 ,0.0237115 ,0.0208329 ,0.0182459 ,0.0160712 ,0.0142498 
,0.012804 ,0.011571 ,0.010547 ,0.00959489 ,0.00891718 ,0.00829292 
,0.0076195 ,0.0069806 ,0.0062025 ,0.00546581 ,0.00484127 ,0.00407168 
,0.00337681 ,0.00269893 ,0.00212473 ,0.00160208 ,0.00117884 ,0.000859662 
,0.000569085 ,0.000365431 ,0.000243565 ,0.00015688 ,9.88128e-05 
,6.53783e-05 ,3.73924e-05 ,2.61382e-05 ,2.0307e-05 ,1.73032e-05 
,1.435e-05 ,1.36486e-05 ,1.35555e-05 ,1.37491e-05 ,1.34255e-05 
,1.33987e-05 ,1.34061e-05 ,1.34211e-05 ,1.34177e-05 ,1.32959e-05 
,1.33287e-05};
   npuProbs = npu_mix_2016_25ns_SpringMC_PUScenarioV1;
   std::vector<double> result(nPUMax,0.);
   std::vector<double> resultNEW(nPUMax,0.);
   std::vector<double> resultNEWUp(nPUMax,0.);
   std::vector<double> resultNEWDo(nPUMax,0.);
   double s = 0.;
   double sNEW   = 0.;
   double sNEWUp = 0.;
   double sNEWDo = 0.;
   for(unsigned int npu = 0; npu < nPUMax; ++npu) {
     const double npu_estimated = 
histoOldPU->GetBinContent(histoOldPU->GetXaxis()->FindBin(npu));
     result[npu] = npu_estimated / npuProbs[npu];
     s += npu_estimated;
     const double npu_estimatedNEW   = histoNewPU 
->GetBinContent(histoNewPU  ->GetXaxis()->FindBin(npu));
     const double npu_estimatedNEWUp = 
histoNewPUUp->GetBinContent(histoNewPUUp->GetXaxis()->FindBin(npu));
     const double npu_estimatedNEWDo = 
histoNewPUDo->GetBinContent(histoNewPUDo->GetXaxis()->FindBin(npu));
     resultNEW[npu]   = npu_estimatedNEW   / npuProbs[npu];
     resultNEWUp[npu] = npu_estimatedNEWUp / npuProbs[npu];
     resultNEWDo[npu] = npu_estimatedNEWDo / npuProbs[npu];
     sNEW   += npu_estimatedNEW;
     sNEWUp += npu_estimatedNEWUp;
     sNEWDo += npu_estimatedNEWDo;
   }
   unsigned int NPU = -1;
   for(unsigned int npu = 0; npu < nPUMax; ++npu) {
     result[npu] /= s;
     resultNEW[npu]   /= sNEW;
     resultNEWUp[npu] /= sNEWUp;
     resultNEWDo[npu] /= sNEWDo;
     if(result[npu]==PUWeight_) NPU = npu;
     //if(result[npu]<PUWeight_*1.01 && result[npu]>PUWeight_*0.99) NPU = npu;
   }
   if(NPU==-1) return;
   //cout<<NPU<<" "<<PUWeight_<<" "<<resultNEW[NPU]<<" "<<resultNEWUp[NPU]<<endl;
   if(resultNEW[NPU]<9999)   puweight     = resultNEW[NPU];
   if(resultNEWUp[NPU]<9999) puweightUP   = resultNEWUp[NPU];
   if(resultNEWDo[NPU]<9999) puweightDOWN = resultNEWDo[NPU];
}

void FillBranches(bool ResolvedEvent,TLorentzVector TopQuark,bool SelectedMet,TLorentzVector TopQuarkResolved,TLorentzVector Jet1Resolved,TLorentzVector Jet2Resolved,TLorentzVector Jet3Resolved,vector<TLorentzVector> SelectedForwardJets,vector<TLorentzVector> SelectedBJets){
  int NumSelBJets = SelectedBJets.size();
  if(ResolvedEvent){
    TopMass=TopQuark.M();
    TopPt  =TopQuark.Pt();
    TopEta =TopQuark.Eta();
    TopPhi =TopQuark.Phi();
  }
  if(ResolvedEvent){
    TopMassResolved=TopQuarkResolved.M();
    TopPtResolved=TopQuarkResolved.Pt();
    TopEtaResolved=TopQuarkResolved.Eta();
    TopPhiResolved=TopQuarkResolved.Phi();
    Jet1ResolvedPt = Jet1Resolved.Pt();
    Jet2ResolvedPt = Jet2Resolved.Pt(); 
    Jet3ResolvedPt = Jet3Resolved.Pt();
    Jet1ResolvedEta = Jet1Resolved.Eta();
    Jet2ResolvedEta = Jet2Resolved.Eta(); 
    Jet3ResolvedEta = Jet3Resolved.Eta();
    WMassResolved1 = (Jet1Resolved+Jet2Resolved).M();
    WMassResolved2 = (Jet1Resolved+Jet3Resolved).M();
    WMassResolved3 = (Jet2Resolved+Jet3Resolved).M();
  }
  if(SelectedForwardJets.size()>0) Jet1ForwardPt=SelectedForwardJets[0].Pt();
  if(SelectedForwardJets.size()>1) Jet2ForwardPt=SelectedForwardJets[1].Pt();
  if(SelectedForwardJets.size()>2) Jet3ForwardPt=SelectedForwardJets[2].Pt();
  if(SelectedForwardJets.size()>0) Jet1ForwardEta=SelectedForwardJets[0].Eta();
  if(SelectedForwardJets.size()>1) Jet2ForwardEta=SelectedForwardJets[1].Eta();
  if(SelectedForwardJets.size()>2) Jet3ForwardEta=SelectedForwardJets[2].Eta();
}
