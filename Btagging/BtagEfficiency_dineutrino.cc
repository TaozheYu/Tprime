#include "BtagEfficiency_dineutrino.h" 

void BtagEfficiency_dineutrino(const char * Input = ""){
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
  /*fileName.push_back("Tprime_0700.root");
  fileName.push_back("Tprime_0800.root");
  fileName.push_back("Tprime_0900.root");
  fileName.push_back("Tprime_1000.root");
  fileName.push_back("Tprime_1100.root");
  fileName.push_back("Tprime_1200.root");
  fileName.push_back("Tprime_1300.root");
  fileName.push_back("Tprime_1400.root");
  fileName.push_back("Tprime_1500.root");
  fileName.push_back("Tprime_1600.root");
  fileName.push_back("Tprime_1700.root");
  fileName.push_back("Tprime_1800.root");
  fileName.push_back("ZToNuNu_HT100to200.root");
  fileName.push_back("ZToNuNu_HT200to400.root");
  fileName.push_back("ZToNuNu_HT400to600.root");
  fileName.push_back("ZToNuNu_HT600to800.root");
  fileName.push_back("ZToNuNu_HT800to1200.root");
  fileName.push_back("ZToNuNu_HT1200to2500.root");
  fileName.push_back("ZToNuNu_HT2500toInf.root");
  fileName.push_back("QCD_HT200to300.root");
  fileName.push_back("QCD_HT300to500.root");
  fileName.push_back("QCD_HT500to700.root");
  fileName.push_back("QCD_HT700to1000.root");
  fileName.push_back("QCD_HT1000to1500.root");
  fileName.push_back("QCD_HT1500to2000.root");
  fileName.push_back("QCD_HT2000toInf.root");
  fileName.push_back("WToLNu_HT100to200.root");
  fileName.push_back("WToLNu_HT200to400.root");
  fileName.push_back("WToLNu_HT400to600.root");
  fileName.push_back("WToLNu_HT600to800.root");
  fileName.push_back("WToLNu_HT800to1200.root");
  fileName.push_back("WToLNu_HT1200to2500.root");
  fileName.push_back("WToLNu_HT2500toInf.root");
  fileName.push_back("TTTo2L2Nu.root");
  fileName.push_back("TTToSemiLeptonic.root");*/
  /*fileName.push_back("ST_t-channel_antitop.root");
  fileName.push_back("ST_t-channel_top.root");
  fileName.push_back("ST_tW_antitop.root");
  fileName.push_back("ST_tW_top.root");
  fileName.push_back("ZZTo4L.root");
  fileName.push_back("ZZTo2L2Q.root");
  fileName.push_back("ZZTo2L2Nu.root");
  fileName.push_back("WWTo2L2Nu.root");
  fileName.push_back("WWToLNuQQ.root");
  fileName.push_back("WZTo1L1Nu2Q.root");
  fileName.push_back("WZTo2L2Q.root");
  fileName.push_back("WZTo3LNu.root");
  fileName.push_back("WToLNu.root");*/
  fileName.push_back(Input);

  for(unsigned int Nfiles=0; Nfiles<fileName.size(); Nfiles++){
    string NewFileprov;
    NewFileprov = "/publicfs/cms/user/yutz/Tprime/2017_dineutrino/BtagEfficiency_v3/"+fileName[Nfiles];
	//NewFileprov = fileName[Nfiles];
    //const char *NewFileName = fileName[Nfiles].c_str();
	const char *NewFileName = NewFileprov.c_str();
    TFile f(NewFileName,"new");
    TTree *NewTree = new TTree("tree","tree");
    TTree *NewTreeSB = new TTree("treeSB","treeSB");
     
    string FILEprov = "/publicfs/cms/user/yutz/Tprime/2017_dineutrino/data_and_sample/"+fileName[Nfiles];
    const char *FILE = FILEprov.c_str();
    TFile *file = TFile::Open(FILE);
    Tree = (TTree*)file->Get(openTree);
    bool data = true;
    if(!(fileName[Nfiles].find("May18V1_MET")!=string::npos )) data = false;
    branch(data, NewTree,NewTreeSB,fileName[Nfiles]);
    Int_t nentries = (Int_t)Tree->GetEntries();
    for(int selection=0; selection<3; selection++){
      //selection = 0 -> preselection
      //selection = 1 -> signal selection
      //selection = 2 -> sideband
      if(!((preselection  && selection==0) || (!preselection && sideband && (selection==1 || selection==2)) || (!preselection && !sideband && selection==1))) continue;
      for (Int_t i=0; i<nentries; i++) {
	Long64_t tentry = Tree->LoadTree(i);
	branchGetEntry(data, tentry,fileName[Nfiles]);
	initializeVar();
	if (!(Flag_goodVertices_==1))  continue;
	if (!(Flag_HBHENoiseFilter_==1))  continue;
	if (!(Flag_HBHENoiseIsoFilter_==1))  continue;
	if (!(Flag_EcalDeadCellTriggerPrimitiveFilter_==1))  continue;
	if (data) {if (!(Flag_eeBadScFilter_==1))  continue;}
	//if (!(HLT_PFMET120_PFMHT120_IDTight_==1))  continue;
	if (!(HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_==1))  continue;
	//if (!(HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight_==1))  continue;

	if(!data) GenClassifier(GenZPt);
	
	//large met
	bool SelectedMet = false;
	SelectMet(SelectedMet);
	
	//Leptonic reject
	vector<TLorentzVector> SelectedElectrons; vector<int> SelectedElectronsIndex;
	vector<TLorentzVector> SelectedMuons;     vector<int> SelectedMuonsIndex;
	TLorentzVector ZBoson;    ZBoson.SetPtEtaPhiE(0,0,0,0);
	TLorentzVector Electron1; Electron1.SetPtEtaPhiE(0,0,0,0); float Ele1Iso_=0;
	TLorentzVector Electron2; Electron2.SetPtEtaPhiE(0,0,0,0); float Ele2Iso_=0;
	TLorentzVector Muon1;     Muon1.SetPtEtaPhiE(0,0,0,0);     float Muo1Iso_=0;
	TLorentzVector Muon2;     Muon2.SetPtEtaPhiE(0,0,0,0);     float Muo2Iso_=0;
	bool SelectedZBosonElectrons = false;
	bool SelectedZBosonMuons = false;
	SelectElectrons(SelectedElectrons, SelectedElectronsIndex, data);
	SelectMuons(SelectedMuons, SelectedMuonsIndex);

	if (SelectedElectrons.size()>0) continue;
	if (SelectedMuons.size()>0)     continue;

	//Hadronic Top selection
	vector<float> SelectedJetsCSV; 
	vector<float> SelectedBJetsMCSV, SelectedBJetsLCSV, SelectedBJetsTCSV,SelectedForwardJetsCSV; 
	vector<int>   CA8Indices;
	int CA8Index = -1;
	bool deltaPhiJetMet=true;
	vector<TLorentzVector> SelectedWJets;       SelectCA8Jets(0,SelectedWJets,  SelectedElectrons,SelectedMuons,CA8Indices, SysJes, SysJer, data, deltaPhiJetMet);   if(!deltaPhiJetMet)  continue;
	vector<TLorentzVector> SelectedTopJets;     SelectCA8Jets(1,SelectedTopJets,SelectedElectrons,SelectedMuons,CA8Indices, SysJes, SysJer, data, deltaPhiJetMet);   if(!deltaPhiJetMet)  continue;
	vector<TLorentzVector> SelectedJets;        SelectJets(0,SelectedJets       ,SelectedJetsCSV       ,SelectedElectrons,SelectedMuons, SysJes, SysJer, data, deltaPhiJetMet);  if(!deltaPhiJetMet)  continue;
	vector<TLorentzVector> SelectedBJetsL;      SelectJets(11,SelectedBJetsL    ,SelectedBJetsLCSV     ,SelectedElectrons,SelectedMuons, SysJes, SysJer, data, deltaPhiJetMet);  if(!deltaPhiJetMet)  continue;
	vector<TLorentzVector> SelectedBJetsM;      SelectJets(12,SelectedBJetsM    ,SelectedBJetsMCSV     ,SelectedElectrons,SelectedMuons, SysJes, SysJer, data, deltaPhiJetMet);  if(!deltaPhiJetMet)  continue;
	vector<TLorentzVector> SelectedBJetsT;      SelectJets(13,SelectedBJetsT    ,SelectedBJetsTCSV     ,SelectedElectrons,SelectedMuons, SysJes, SysJer, data, deltaPhiJetMet);  if(!deltaPhiJetMet)  continue;
	vector<TLorentzVector> SelectedForwardJets; SelectJets(2,SelectedForwardJets,SelectedForwardJetsCSV,SelectedElectrons,SelectedMuons, SysJes, SysJer, data, deltaPhiJetMet);  if(!deltaPhiJetMet)  continue;
	TLorentzVector Jet1Resolved;     Jet1Resolved.SetPtEtaPhiE(0, 0, 0, 0);
	TLorentzVector Jet2Resolved;     Jet2Resolved.SetPtEtaPhiE(0, 0, 0, 0);
	TLorentzVector Jet3Resolved;     Jet3Resolved.SetPtEtaPhiE(0, 0, 0, 0);
	TLorentzVector Jet1Partial;      Jet1Partial.SetPtEtaPhiE(0, 0, 0, 0);
	TLorentzVector Jet2Partial;      Jet2Partial.SetPtEtaPhiE(0, 0, 0, 0);
	TLorentzVector TopQuark;         TopQuark.SetPtEtaPhiE(0, 0, 0, 0);
	TLorentzVector TopQuarkResolved; TopQuarkResolved.SetPtEtaPhiE(0, 0, 0, 0);
	TLorentzVector TopQuarkPartial;  TopQuarkPartial.SetPtEtaPhiE(0, 0, 0, 0);
	TLorentzVector TopQuarkMerged;   TopQuarkMerged.SetPtEtaPhiE(0, 0, 0, 0);
	bool ResolvedEvent   = false;
	bool PartiallyMerged = false;
	bool FullyMerged     = false;
	bool TprimeEvent     = false;
	float WMass_, WSubjet_, TopSoftMass_, TopSubjet_;
	if(selection==0) ResolvedRegionSelection(ResolvedEvent, SelectedJets, SelectedJetsCSV, TopQuarkResolved, Jet1Resolved, Jet2Resolved, Jet3Resolved, false, false);
	if(selection==1) ResolvedRegionSelection(ResolvedEvent, SelectedJets, SelectedJetsCSV, TopQuarkResolved, Jet1Resolved, Jet2Resolved, Jet3Resolved, false, true );
	if(selection==2) ResolvedRegionSelection(ResolvedEvent, SelectedJets, SelectedJetsCSV, TopQuarkResolved, Jet1Resolved, Jet2Resolved, Jet3Resolved, false, false);
	if(selection==0) PartiallyMergedSelection(PartiallyMerged,SelectedWJets,SelectedJets,SelectedJetsCSV,TopQuarkPartial,Jet1Partial,Jet2Partial,false,false,CA8Indices,CA8Index,WMass_,WSubjet_, data);
	if(selection==1) PartiallyMergedSelection(PartiallyMerged,SelectedWJets,SelectedJets,SelectedJetsCSV,TopQuarkPartial,Jet1Partial,Jet2Partial,false,true, CA8Indices,CA8Index,WMass_,WSubjet_, data);
	if(selection==2) PartiallyMergedSelection(PartiallyMerged,SelectedWJets,SelectedJets,SelectedJetsCSV,TopQuarkPartial,Jet1Partial,Jet2Partial,false,false,CA8Indices,CA8Index,WMass_,WSubjet_, data);
	if(selection==0) FullyMergedSelection(FullyMerged, SelectedTopJets, TopQuarkMerged, CA8Indices, TopSoftMass_, TopSubjet_, data);
	if(selection==1) FullyMergedSelection(FullyMerged, SelectedTopJets, TopQuarkMerged, CA8Indices, TopSoftMass_, TopSubjet_, data);
	if(selection==2) FullyMergedSelection(FullyMerged, SelectedTopJets, TopQuarkMerged, CA8Indices, TopSoftMass_, TopSubjet_, data);
	if(FullyMerged)     {PartiallyMerged=false; ResolvedEvent=false;  }
	if(PartiallyMerged) {ResolvedEvent=false;   FullyMerged=false;    }
	if(ResolvedEvent)   {FullyMerged=false;     PartiallyMerged=false;}
	if(FullyMerged)     TopQuark = TopQuarkMerged;
	if(PartiallyMerged) TopQuark = TopQuarkPartial;
	if(ResolvedEvent)   TopQuark = TopQuarkResolved;
	if(!(ResolvedEvent || PartiallyMerged || FullyMerged)) continue;
	NumSelLeps        = SelectedElectrons.size()+SelectedMuons.size();
	NumSelJets        = SelectedJets.size();
	NumSelForwardJets = SelectedForwardJets.size();
	NumSelBJetsL      = SelectedBJetsL.size();
	NumSelBJetsM      = SelectedBJetsM.size();
	NumSelBJetsT      = SelectedBJetsT.size();
	NumSelWJets       = SelectedWJets.size();
	NumSelTopJets     = SelectedTopJets.size();
	Met_pt            = Met_type1PF_pt_;
	Met_phi           = Met_type1PF_phi_;
	NVertices         = nBestVtx_;
	EVENT_run         = EVENT_run_;
	EVENT_event       = EVENT_event_;
	EVENT_lumiBlock   = EVENT_lumiBlock_;
	EVENT_genHT       = EVENT_genHT_;
	HT                = HTcalculator(SelectedJets);
	if(!(HT>200)) continue;

	//categorization
	if(selection==0){ //PRESELECTION
	  if(ResolvedEvent   && SelectedMet)     category0=1;
	  if(PartiallyMerged && SelectedMet)     category1=1;  
	  if(FullyMerged     && SelectedMet)     category2=1;
	  
	} else if(selection==1){ //SELECTION
	  if(ResolvedEvent   && NumSelBJetsM>0 && SelectedMet)     category0=1;
	  if(PartiallyMerged && NumSelBJetsM>0 && SelectedMet)     category1=1;
	  if(FullyMerged     && NumSelBJetsM>0 && SelectedMet)     category2=1;

	  if(category2==1) {category0=0;category1=0;category2=1;}
	  if(category1==1) {category0=0;category1=1;category2=0;}
	  if(category0==1) {category1=1;category1=0;category2=0;}
	  
	} else if(selection==2){ //CONTROL REGION
	  if(ResolvedEvent   && NumSelBJetsL==0 )     category0=1;
	  if(PartiallyMerged && NumSelBJetsL==0 )     category1=1;
	  if(FullyMerged     && NumSelBJetsL==0 )     category2=1; 
	}

	if(!(category0==1 || category1==1 || category2==1)) continue;

	//Tprime
	TLorentzVector Tprime;        Tprime.SetPtEtaPhiE((ZBoson+TopQuark).Pt(),(ZBoson+TopQuark).Eta(),(ZBoson+TopQuark).Phi(),(ZBoson+TopQuark).E());
	TLorentzVector TprimeMerged;  TprimeMerged.SetPtEtaPhiE((ZBoson+TopQuarkMerged).Pt(),(ZBoson+TopQuarkMerged).Eta(),(ZBoson+TopQuarkMerged).Phi(),(ZBoson+TopQuarkMerged).E());
	TLorentzVector TprimePartial; TprimePartial.SetPtEtaPhiE((ZBoson+TopQuarkPartial).Pt(),(ZBoson+TopQuarkPartial).Eta(),(ZBoson+TopQuarkPartial).Phi(),(ZBoson+TopQuarkPartial).E());
	TLorentzVector TprimeResolved;TprimeResolved.SetPtEtaPhiE((ZBoson+TopQuarkResolved).Pt(),(ZBoson+TopQuarkResolved).Eta(),(ZBoson+TopQuarkResolved).Phi(),
								  (ZBoson+TopQuarkResolved).E());

	//TREE
	FillBranches(ResolvedEvent,PartiallyMerged,FullyMerged,TopQuark,SelectedZBosonElectrons,SelectedZBosonMuons,SelectedMet,ZBoson,Tprime,
		     TopQuarkResolved,Jet1Resolved,Jet2Resolved,Jet3Resolved,TprimeResolved,TopQuarkPartial,Jet1Partial,Jet2Partial,TprimePartial,WMass_,WSubjet_,TopQuarkMerged,
		     TprimeMerged,TopSoftMass_,TopSubjet_,Electron1,Electron2,Muon1,Muon2,SelectedForwardJets,SelectedBJetsM);

	//WEIGHT
	if(!data){
	  //get_weight_btag(selection,w_Btag, w_BtagUp, w_BtagDown,w_Btag1Up, w_Btag1Down,w_Btag2Up, w_Btag2Down,w_BtagLoose, w_BtagLooseUp, w_BtagLooseDown, fileName[Nfiles]);
	  TopSF(TopQuarkMerged, FullyMerged, w_topJet, w_topJetUp, w_topJetDown);
	  WSF(Jet1Partial, PartiallyMerged, w_WJet, w_WJetUp, w_WJetDown, CA8Index, SysJes, SysJer);
	  ForwardJetSF(SelectedForwardJets, w_for, w_forUp, w_forDown);
	  //newPUWeight(PUWeight, PUWeightUP, PUWeightDOWN);
	  //GenWeight(fileName[Nfiles], GenZPt);
	}
	
	if(selection==0 || selection==1) BTagEff();
	else if(selection==2)            BTagEff();
      }
    }
    f.cd();
    writeFile(NewTree,NewTreeSB);
    f.Close();
    cout<<"File "<<fileName[Nfiles]<<" ready!"<<endl;
  }
}


void SelectMet(bool &SelectedMet){ 
    if( Met_type1PF_pt_ > 200)  SelectedMet = true;
}

void BTagEff(){
  for (UInt_t j = 0; j < Jet_pt_->size(); ++j){
    if(!(Jet_neutralHadEnergyFraction_->at(j)<0.90))                      continue;
    if(!(Jet_neutralEmEnergyFraction_->at(j)<0.90))                       continue;
    if(!(Jet_numberOfConstituents_->at(j)>1))                             continue;
    if(!(Jet_chargedHadronEnergyFraction_->at(j)>0.0))                    continue;
    if(!(Jet_chargedMultiplicity_->at(j)>0.0))                            continue;
    //if(!(Jet_chargedEmEnergyFraction_->at(j)<0.99))                       continue;
    int flav = Jet_hadronFlavour_->at(j);
    bool is_taggedT = (Jet_pfDeepCSVBJetTags_->at(j)>0.8001);
    bool is_taggedM = (Jet_pfDeepCSVBJetTags_->at(j)>0.4941);
    bool is_taggedL = (Jet_pfDeepCSVBJetTags_->at(j)>0.1522);
    float pt = Jet_pt_->at(j);
    float eta = fabs(Jet_eta_->at(j));
    if(flav == 5) {
      histT_b_total_->Fill(pt, eta);
      histM_b_total_->Fill(pt, eta);
      histL_b_total_->Fill(pt, eta);
      if(is_taggedT) histT_b_passing_->Fill(pt, eta);
      if(is_taggedM) histM_b_passing_->Fill(pt, eta);
      if(is_taggedL) histL_b_passing_->Fill(pt, eta);
    } else if(flav == 4) {
      histT_c_total_->Fill(pt, eta);
      histM_c_total_->Fill(pt, eta);
      histL_c_total_->Fill(pt, eta);
      if(is_taggedT) histT_c_passing_->Fill(pt, eta);
      if(is_taggedM) histM_c_passing_->Fill(pt, eta);
      if(is_taggedL) histL_c_passing_->Fill(pt, eta);
    } else {
      histT_udsg_total_->Fill(pt, eta);
      histM_udsg_total_->Fill(pt, eta);
      histL_udsg_total_->Fill(pt, eta);
      if(is_taggedT) histT_udsg_passing_->Fill(pt, eta);
      if(is_taggedM) histM_udsg_passing_->Fill(pt, eta);
      if(is_taggedL) histL_udsg_passing_->Fill(pt, eta);
    }
  }
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
    if(!(Muon_relIsoDeltaBetaR04_->at(j)<0.25))   continue;
    TLorentzVector muon; muon.SetPtEtaPhiE(Muon_pt_->at(j),Muon_eta_->at(j),Muon_phi_->at(j),Muon_energy_->at(j));
    SelectedMuons.push_back(muon);
    SelectedMuonsIndex.push_back(j);
  }
}

void SelectZBoson(bool electrons,bool muons,bool &SelectedZBoson,TLorentzVector &ZBoson,TLorentzVector &Lep1,TLorentzVector &Lep2,vector<TLorentzVector> SelectedLeptons,vector<int> SelectedLeptonsIndex,float dRLep1Lep2,float Zpt,float leadLepPt){
  float ZPtMin=-99;
  for (unsigned int i=0; i<SelectedLeptons.size(); i++){
    for (unsigned int j=i+1; j<SelectedLeptons.size(); j++){
      if(!((SelectedLeptons[i]+SelectedLeptons[j]).Pt()>Zpt))                                                                       continue;
      if(!(SelectedLeptons[i].Pt()>leadLepPt || SelectedLeptons[j].Pt()>leadLepPt))                                                 continue;
      if(!((SelectedLeptons[i]+SelectedLeptons[j]).M()>70 && (SelectedLeptons[i]+SelectedLeptons[j]).M()<110))                      continue;
      if(!(DeltaR(SelectedLeptons[i].Eta(),SelectedLeptons[j].Eta(),SelectedLeptons[i].Phi(),SelectedLeptons[j].Phi())<dRLep1Lep2)) continue;
      if(muons)         {if(!(Muon_charge_->at(SelectedLeptonsIndex[i])*Muon_charge_->at(SelectedLeptonsIndex[j])<0))               continue;}
      if( electrons)    {if(!(patElectron_charge_->at(SelectedLeptonsIndex[i])*patElectron_charge_->at(SelectedLeptonsIndex[j])<0)) continue;}
      if((SelectedLeptons[i]+SelectedLeptons[j]).Pt()>ZPtMin){
	if(electrons){
	  if(patElectron_isMatchedToTrigger_->at(SelectedLeptonsIndex[j])) {TriggeringElePt = SelectedLeptons[j].Pt();TriggeringEleEta = SelectedLeptons[j].Eta();}
	  if(patElectron_isMatchedToTrigger_->at(SelectedLeptonsIndex[i])) {TriggeringElePt = SelectedLeptons[i].Pt();TriggeringEleEta = SelectedLeptons[i].Eta();}
	} 
	if(muons) {
	  if(Muon_isMatchedToTrigger_->at(SelectedLeptonsIndex[j])) {TriggeringMuoPt = SelectedLeptons[j].Pt();TriggeringMuoEta = SelectedLeptons[j].Eta();}
	  if(Muon_isMatchedToTrigger_->at(SelectedLeptonsIndex[i])) {TriggeringMuoPt = SelectedLeptons[i].Pt();TriggeringMuoEta = SelectedLeptons[i].Eta();}
	}
	ZBoson.SetPtEtaPhiE((SelectedLeptons[i]+SelectedLeptons[j]).Pt(),(SelectedLeptons[i]+SelectedLeptons[j]).Eta(),
			    (SelectedLeptons[i]+SelectedLeptons[j]).Phi(),(SelectedLeptons[i]+SelectedLeptons[j]).E());
	if(electrons){
	  Lep1.SetPtEtaPhiE(SelectedLeptons[i].Pt(),patElectron_SCeta_->at(SelectedLeptonsIndex[i]),SelectedLeptons[i].Phi(),SelectedLeptons[i].E());
	  Lep2.SetPtEtaPhiE(SelectedLeptons[j].Pt(),patElectron_SCeta_->at(SelectedLeptonsIndex[j]),SelectedLeptons[j].Phi(),SelectedLeptons[j].E());
	} 
	if(muons){
	  Lep1.SetPtEtaPhiE(SelectedLeptons[i].Pt(),SelectedLeptons[i].Eta(),SelectedLeptons[i].Phi(),SelectedLeptons[i].E());
	  Lep2.SetPtEtaPhiE(SelectedLeptons[j].Pt(),SelectedLeptons[j].Eta(),SelectedLeptons[j].Phi(),SelectedLeptons[j].E());
	}
	ZPtMin=(SelectedLeptons[i]+SelectedLeptons[j]).Pt();
	SelectedZBoson = true;
      }
    }
  }
}

void SelectJets(int jetType, vector<TLorentzVector> & SelectedJets, vector<float> & SelectedJetsCSV, vector<TLorentzVector> SelectedElectrons, vector<TLorentzVector> SelectedMuons, int SysJes, int SysJer, bool data, bool &deltaPhiJetMet){
  //jetType=0  -> usual jets
  //jetType=11 -> b-jets L
  //jetType=12 -> b-jets M
  //jetType=13 -> b-jets T
  //jetType=2  -> forward jets
  for (UInt_t j = 0; j < Jet_pt_->size(); ++j){
    float jetpt = 0.;
    if(SysJes==0){jetpt = Jet_Uncorr_pt_->at(j)*Jet_JesSF_->at(j)    *Jet_JerSF_->at(j)    ;}
    if(SysJes==1){jetpt = Jet_Uncorr_pt_->at(j)*Jet_JesSFup_->at(j)  *Jet_JerSF_->at(j)    ;}
    if(SysJes==2){jetpt = Jet_Uncorr_pt_->at(j)*Jet_JesSFdown_->at(j)*Jet_JerSF_->at(j)    ;}
    if(SysJer==0){jetpt = Jet_Uncorr_pt_->at(j)*Jet_JesSF_->at(j)    *Jet_JerSF_->at(j)    ;}
    if(SysJer==1){jetpt = Jet_Uncorr_pt_->at(j)*Jet_JesSF_->at(j)    *Jet_JerSFup_->at(j)  ;}
    if(SysJer==2){jetpt = Jet_Uncorr_pt_->at(j)*Jet_JesSF_->at(j)    *Jet_JerSFdown_->at(j);}
    if(!(jetpt>20))                                                         continue;
    if(!(fabs(Jet_eta_->at(j))<5.0))                                        continue;
    if(jetType==2) {if(!(fabs(Jet_eta_->at(j))>=2.4))                       continue;if(!(jetpt>30))                                                         continue;}
    else {if(!(fabs(Jet_eta_->at(j))<2.4))		                            continue;}
    if(fabs(Jet_eta_->at(j))<2.4){
      if(!(Jet_neutralHadEnergyFraction_->at(j)<0.90))                      continue;
      if(!(Jet_neutralEmEnergyFraction_->at(j)<0.90))                       continue;
      if(!(Jet_numberOfConstituents_->at(j)>1))                             continue;
      if(!(Jet_chargedHadronEnergyFraction_->at(j)>0.0))                    continue;
      if(!(Jet_chargedMultiplicity_->at(j)>0.0))                            continue;
      //if(!(Jet_chargedEmEnergyFraction_->at(j)<0.99))                       continue;
    } else if(fabs(Jet_eta_->at(j))>2.4 && fabs(Jet_eta_->at(j))<2.7){
      if(!(Jet_neutralHadEnergyFraction_->at(j)<0.90))                      continue;
      if(!(Jet_neutralEmEnergyFraction_->at(j)<0.90))                       continue;
      if(!(Jet_numberOfConstituents_->at(j)>1))                             continue;
    } else if(fabs(Jet_eta_->at(j))>2.7 && fabs(Jet_eta_->at(j))<3.0){
      if(!(Jet_neutralEmEnergyFraction_->at(j)>0.02))                       continue;
      if(!(Jet_neutralEmEnergyFraction_->at(j)<0.99))                       continue;
      if(!((Jet_numberOfConstituents_->at(j) -Jet_chargedMultiplicity_->at(j)) >2)) continue;
    } else if(fabs(Jet_eta_->at(j))>3.0){
      if(!(Jet_neutralEmEnergyFraction_->at(j)<0.90))                       continue;
      if(!(Jet_neutralHadEnergyFraction_->at(j)>0.02))                      continue;
      if(!((Jet_numberOfConstituents_->at(j) -Jet_chargedMultiplicity_->at(j)) >10)) continue;
    }
    if(jetType==11){if(!(Jet_pfDeepCSVBJetTags_->at(j)>0.1522)) continue;}
    if(jetType==12){if(!(Jet_pfDeepCSVBJetTags_->at(j)>0.4941)) continue;}
    if(jetType==13){if(!(Jet_pfDeepCSVBJetTags_->at(j)>0.8001)) continue;}
	if(DeltaPhi(Jet_phi_->at(j),Met_type1PF_phi_)<0.6) deltaPhiJetMet=false;
	if(!deltaPhiJetMet) break;
    if(deltaPhiJetMet){
      float SF = jetpt/Jet_pt_->at(j);
      TLorentzVector jet_prov; jet_prov.SetPtEtaPhiM(Jet_pt_->at(j),Jet_eta_->at(j),Jet_phi_->at(j),Jet_mass_->at(j));
      TLorentzVector jet; jet.SetPxPyPzE(SF*jet_prov.Px(),SF*jet_prov.Py(),SF*jet_prov.Pz(),SF*jet_prov.E());
      SelectedJets.push_back(jet);
      SelectedJetsCSV.push_back(Jet_pfDeepCSVBJetTags_->at(j));
    }
  }
}

void SelectCA8Jets(int CA8jetType,vector<TLorentzVector> & SelectedCA8Jets,vector<TLorentzVector> SelectedElectrons,vector<TLorentzVector> SelectedMuons, vector<int> & CA8Indices, 
		   int SysJes, int SysJer, bool data, bool &deltaPhiJetMet){
  //CA8jetType=0 -> W-jets
  //CA8jetType=1 -> top-jets
  for (UInt_t j = 0; j < BoostedJet_pt_->size(); ++j){
    float jetpt = 0.;
    if(SysJes==0){jetpt = BoostedJet_Uncorr_pt_->at(j)*BoostedJet_JesSF_->at(j)    *BoostedJet_JerSF_->at(j)    ;}
    if(SysJes==1){jetpt = BoostedJet_Uncorr_pt_->at(j)*BoostedJet_JesSFup_->at(j)  *BoostedJet_JerSF_->at(j)    ;}
    if(SysJes==2){jetpt = BoostedJet_Uncorr_pt_->at(j)*BoostedJet_JesSFdown_->at(j)*BoostedJet_JerSF_->at(j)    ;}
    if(SysJer==0){jetpt = BoostedJet_Uncorr_pt_->at(j)*BoostedJet_JesSF_->at(j)    *BoostedJet_JerSF_->at(j)    ;}
    if(SysJer==1){jetpt = BoostedJet_Uncorr_pt_->at(j)*BoostedJet_JesSF_->at(j)    *BoostedJet_JerSFup_->at(j)  ;}
    if(SysJer==2){jetpt = BoostedJet_Uncorr_pt_->at(j)*BoostedJet_JesSF_->at(j)    *BoostedJet_JerSFdown_->at(j);}
    float SF = jetpt/BoostedJet_pt_->at(j);
    if(!(jetpt>180))                                          continue;
    if(!(fabs(BoostedJet_eta_->at(j))<2.4))		              continue;
    if(!(BoostedJet_neutralHadEnergyFraction_->at(j)<0.90))   continue;
    //if(!(BoostedJet_neutralEmEnergyFraction_->at(j)<0.90))  continue;
    if(!(BoostedJet_numberOfConstituents_->at(j)>1))          continue;
    if(!(BoostedJet_chargedHadronEnergyFraction_->at(j)>0.0)) continue;
    if(!(BoostedJet_chargedMultiplicity_->at(j)>0.0))         continue;
    //if(!(BoostedJet_chargedEmEnergyFraction_->at(j)<0.99))  continue;
    if(CA8jetType==0){
      if(!(SF*BoostedJet_pruned_mass_->at(j)>65 && SF*BoostedJet_pruned_mass_->at(j)<105)) continue;
      if(!(BoostedJet_tau2_->at(j)/BoostedJet_tau1_->at(j)<0.60))                          continue;
    } else if(CA8jetType==1) {
      if(!(jetpt>400))                                                                           continue;
      if(!(SF*BoostedJet_softdrop_mass_->at(j)>105 && SF*BoostedJet_softdrop_mass_->at(j)<220))  continue;
      if(!(BoostedJet_tau3_->at(j)/BoostedJet_tau2_->at(j)<0.81))                                continue;
    }

	if(DeltaPhi(Jet_phi_->at(j),Met_type1PF_phi_)<0.6) deltaPhiJetMet=false;
	if(!deltaPhiJetMet) break;
    if(deltaPhiJetMet){
      TLorentzVector jet_prov; jet_prov.SetPtEtaPhiM(BoostedJet_pt_->at(j),BoostedJet_eta_->at(j),BoostedJet_phi_->at(j),BoostedJet_mass_->at(j));
      TLorentzVector jet; jet.SetPxPyPzE(SF*jet_prov.Px(),SF*jet_prov.Py(),SF*jet_prov.Pz(),SF*jet_prov.E());
      SelectedCA8Jets.push_back(jet);
      CA8Indices.push_back(j);
    }
  }
}

void ResolvedRegionSelection(bool &ResolvedEvent,vector<TLorentzVector> SelectedJets,vector<float> SelectedJetsCSV,TLorentzVector &TopQuark,
			     TLorentzVector &Jet1,TLorentzVector &Jet2,TLorentzVector &Jet3,bool TopMassCut,bool btag){
  float TopPtMin=20;
  float TopMassInitial=99999;
  for(unsigned int i=0; i<SelectedJets.size(); i++){
    for(unsigned int j=i+1; j<SelectedJets.size(); j++){
      for(unsigned int k=j+1; k<SelectedJets.size(); k++){
	if(!((SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).Pt()>TopPtMin))                                                                       continue;
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
	if(btag){if(!((Jet2+Jet3).M()<200)) continue;}
	TopPtMin = (SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).Pt();
	ResolvedEvent=true;
	TopMassInitial=fabs((SelectedJets[i]+SelectedJets[j]+SelectedJets[k]).M()-173.1);
	TopQuark=(SelectedJets[i]+SelectedJets[j]+SelectedJets[k]);
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
      if(btag){if(!(SelectedJetsCSV[k]>0.4941))                                                                       continue;}
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

/*void BTagSF(int selection, float JetPt, float JetEta, int flav, float &SF, float &SFerr){
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
  string FILEprov = "SF_v3/BtagEfficiency/"+fileName;
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
    if(!(Jet_neutralHadEnergyFraction_->at(j)<0.90))                      continue;
    if(!(Jet_neutralEmEnergyFraction_->at(j)<0.90))                       continue;
    if(!(Jet_numberOfConstituents_->at(j)>1))                             continue;
    if(!(Jet_chargedHadronEnergyFraction_->at(j)>0.0))                    continue;
    if(!(Jet_chargedMultiplicity_->at(j)>0.0))                            continue;
    //if(!(Jet_chargedEmEnergyFraction_->at(j)<0.99))                       continue;
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
    if(Jet_pfCombinedInclusiveSecondaryVertexV2BJetTags_->at(j)>0.8838){
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
    if(Jet_pfCombinedInclusiveSecondaryVertexV2BJetTags_->at(j)>0.5803){
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
}*/

void ForwardJetSF(vector<TLorentzVector> SelectedForwardJets, float &w_for_, float &w_forUp_, float &w_forDown_){
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
    w_forUp_   = 1.0;//SF + histoForwardJet->GetBinError(X1,Y1);
    w_forDown_ = 1.0;//SF - histoForwardJet->GetBinError(X1,Y1);
  }
}

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
  Tree->SetBranchAddress("BoostedJet_chargedEmEnergyFraction", &BoostedJet_chargedEmEnergyFraction_, &b_BoostedJet_chargedEmEnergyFraction);
  Tree->SetBranchAddress("BoostedJet_neutralEmEmEnergyFraction", &BoostedJet_neutralEmEmEnergyFraction_, &b_BoostedJet_neutralEmEmEnergyFraction);
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
  Tree->SetBranchAddress("patElectron_energyCorr",&patElectron_energyCorr_,&b_patElectron_energyCorr);
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
  Tree->SetBranchAddress("Flag_CSCTightHalo2015Filter",&Flag_CSCTightHalo2015Filter_,&b_Flag_CSCTightHalo2015Filter);
  Tree->SetBranchAddress("Flag_HBHENoiseFilter",&Flag_HBHENoiseFilter_,&b_Flag_HBHENoiseFilter);
  Tree->SetBranchAddress("Flag_HBHENoiseIsoFilter",&Flag_HBHENoiseIsoFilter_,&b_Flag_HBHENoiseIsoFilter);
  Tree->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter",&Flag_EcalDeadCellTriggerPrimitiveFilter_,&b_Flag_EcalDeadCellTriggerPrimitiveFilter);
  Tree->SetBranchAddress("Flag_eeBadScFilter",&Flag_eeBadScFilter_,&b_Flag_eeBadScFilter);
  Tree->SetBranchAddress("HLT_DoubleEle33_CaloIdL_MW",&HLT_DoubleEle33_CaloIdL_MW_,&b_HLT_DoubleEle33_CaloIdL_MW);
  Tree->SetBranchAddress("HLT_Mu50",&HLT_Mu50_,&b_HLT_Mu50);
  Tree->SetBranchAddress("HLT_TkMu50",&HLT_TkMu50_,&b_HLT_TkMu50);

  Tree->SetBranchAddress("HLT_PFHT500_PFMET100_PFMHT100_IDTight", &HLT_PFHT500_PFMET100_PFMHT100_IDTight_, &b_HLT_PFHT500_PFMET100_PFMHT100_IDTight);
  Tree->SetBranchAddress("HLT_PFHT700_PFMET85_PFMHT85_IDTight", &HLT_PFHT700_PFMET85_PFMHT85_IDTight_, &b_HLT_PFHT700_PFMET85_PFMHT85_IDTight);
  Tree->SetBranchAddress("HLT_PFHT800_PFMET75_PFMHT75_IDTight", &HLT_PFHT800_PFMET75_PFMHT75_IDTight_, &b_HLT_PFHT800_PFMET75_PFMHT75_IDTight);
  Tree->SetBranchAddress("HLT_PFMET120_PFMHT120_IDTight", &HLT_PFMET120_PFMHT120_IDTight_, &b_HLT_PFMET120_PFMHT120_IDTight);
  Tree->SetBranchAddress("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_, &b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight);
  Tree->SetBranchAddress("HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight", &HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight_,  &b_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight);
  Tree->SetBranchAddress("HLT_CaloJet500_NoJetID", &HLT_CaloJet500_NoJetID_, &b_HLT_CaloJet500_NoJetID);
  Tree->SetBranchAddress("HLT_AK8PFJet500", &HLT_AK8PFJet500_,   &b_HLT_AK8PFJet500);
  Tree->SetBranchAddress("HLT_PFJet500", &HLT_PFJet500_,         &b_HLT_PFJet500);
  Tree->SetBranchAddress("HLT_PFHT1050", &HLT_PFHT1050_,         &b_HLT_PFHT1050);

  Tree->SetBranchAddress("nBestVtx",&nBestVtx_,&b_nBestVtx);
  Tree->SetBranchAddress("PUWeight",&PUWeight_,&b_PUWeight);
  //Tree->SetBranchAddress("PUWeightUP",&PUWeightUP_,&b_PUWeightUP);
  //Tree->SetBranchAddress("PUWeightDOWN",&PUWeightDOWN_,&b_PUWeightDOWN);
  Tree->SetBranchAddress("EVENT_event",&EVENT_event_,&b_EVENT_event);
  Tree->SetBranchAddress("EVENT_run",&EVENT_run_,&b_EVENT_run);
  Tree->SetBranchAddress("EVENT_lumiBlock",&EVENT_lumiBlock_,&b_EVENT_lumiBlock);
  Tree->SetBranchAddress("EVENT_genHT",&EVENT_genHT_,&b_EVENT_genHT);
  if(!data) Tree->SetBranchAddress("Gen_pt",&Gen_pt_,&b_Gen_pt);
  if(!data) Tree->SetBranchAddress("Gen_eta",&Gen_eta_,&b_Gen_eta);
  if(!data) Tree->SetBranchAddress("Gen_phi",&Gen_phi_,&b_Gen_phi);
  if(!data) Tree->SetBranchAddress("Gen_pdg_id",&Gen_pdg_id_,&b_Gen_pdg_id);
  if(!data) Tree->SetBranchAddress("Gen_motherpdg_id",&Gen_motherpdg_id_,&b_Gen_motherpdg_id);
  Tree->SetBranchAddress("EVENT_genWeight",&genWeight_,&b_genWeight);

  NewTree->Branch("category0",         &category0,         "category0/I"         );
  NewTree->Branch("category1",         &category1,         "category1/I"         );
  NewTree->Branch("category2",         &category2,         "category2/I"         );
  /*NewTree->Branch("category3",         &category3,         "category3/I"         );
  NewTree->Branch("category4",         &category4,         "category4/I"         );
  NewTree->Branch("category5",         &category5,         "category5/I"         );
  NewTree->Branch("category6",         &category6,         "category6/I"         );
  NewTree->Branch("category7",         &category7,         "category7/I"         );*/
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
  NewTree->Branch("deltaPhiZTopResolved", &deltaPhiZTopResolved, "deltaPhiZTopResolved/F");
  NewTree->Branch("deltaRZTopResolved",   &deltaRZTopResolved,   "deltaRZTopResolved/F"  );
  NewTree->Branch("deltaPhiZTopPartial",  &deltaPhiZTopPartial,  "deltaPhiZTopPartial/F" );
  NewTree->Branch("deltaRZTopPartial",    &deltaRZTopPartial,    "deltaRZTopPartial/F"   );
  NewTree->Branch("deltaPhiZTopMerged",   &deltaPhiZTopMerged,   "deltaPhiZTopMerged/F"  );
  NewTree->Branch("deltaRZTopMerged",     &deltaRZTopMerged,     "deltaRZTopMerged/F"    );
  NewTree->Branch("deltaRbTop",           &deltaRbTop,           "deltaRbTop/F"          );
  NewTree->Branch("deltaPhiMetTop",       &deltaPhiMetTop,       "deltaPhiMetTop/F"      );
  NewTree->Branch("genWeight",            &genWeight,            "genWeight/F"           );
  NewTree->Branch("dQuark",&dQuark,"dQuark/I");
  NewTree->Branch("uQuark",&uQuark,"uQuark/I");
  NewTree->Branch("sQuark",&sQuark,"sQuark/I");
  NewTree->Branch("cQuark",&cQuark,"cQuark/I");
  NewTree->Branch("bQuark",&bQuark,"bQuark/I");
  NewTree->Branch("tQuark",&tQuark,"tQuark/I");
  NewTree->Branch("EVENT_event",&EVENT_event,"EVENT_event/I");
  NewTree->Branch("EVENT_run",&EVENT_run,"EVENT_run/I");
  NewTree->Branch("EVENT_lumiBlock",&EVENT_lumiBlock,"EVENT_lumiBlock/I");
  NewTree->Branch("EVENT_genHT",&EVENT_genHT,"EVENT_genHT/F");
  NewTree->Branch("Met_pt",&Met_pt,"Met_pt/F");
  NewTree->Branch("Met_phi",&Met_phi,"Met_phi/F");

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
  NewTreeSB->Branch("deltaPhiZTopResolved", &deltaPhiZTopResolved, "deltaPhiZTopResolved/F");
  NewTreeSB->Branch("deltaRZTopResolved",   &deltaRZTopResolved,   "deltaRZTopResolved/F"  );
  NewTreeSB->Branch("deltaPhiZTopPartial",  &deltaPhiZTopPartial,  "deltaPhiZTopPartial/F" );
  NewTreeSB->Branch("deltaRZTopPartial",    &deltaRZTopPartial,    "deltaRZTopPartial/F"   );
  NewTreeSB->Branch("deltaPhiZTopMerged",   &deltaPhiZTopMerged,   "deltaPhiZTopMerged/F"  );
  NewTreeSB->Branch("deltaRZTopMerged",     &deltaRZTopMerged,     "deltaRZTopMerged/F"    );
  NewTreeSB->Branch("deltaRbTop",           &deltaRbTop,           "deltaRbTop/F"          );
  NewTreeSB->Branch("deltaPhiMetTop",       &deltaPhiMetTop,       "deltaPhiMetTop/F"      );
  NewTreeSB->Branch("genWeight",            &genWeight,            "genWeight/F"           );
  NewTreeSB->Branch("dQuark",&dQuark,"dQuark/I");
  NewTreeSB->Branch("uQuark",&uQuark,"uQuark/I");
  NewTreeSB->Branch("sQuark",&sQuark,"sQuark/I");
  NewTreeSB->Branch("cQuark",&cQuark,"cQuark/I");
  NewTreeSB->Branch("bQuark",&bQuark,"bQuark/I");
  NewTreeSB->Branch("tQuark",&tQuark,"tQuark/I");
  NewTreeSB->Branch("EVENT_event",&EVENT_event,"EVENT_event/I");
  NewTreeSB->Branch("EVENT_run",&EVENT_run,"EVENT_run/I");
  NewTreeSB->Branch("EVENT_lumiBlock",&EVENT_lumiBlock,"EVENT_lumiBlock/I");
  NewTreeSB->Branch("EVENT_genHT",&EVENT_genHT,"EVENT_genHT/F");
  NewTreeSB->Branch("Met_pt",&Met_pt,"Met_pt/F");
  NewTreeSB->Branch("Met_phi",&Met_phi,"Met_phi/F");
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
  genWeight=1;
  GenZPt=-99.;
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
  b_BoostedJet_chargedEmEnergyFraction->GetEntry(tentry);
  b_BoostedJet_neutralEmEmEnergyFraction->GetEntry(tentry);
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
  b_patElectron_energyCorr->GetEntry(tentry);
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
  b_HLT_PFHT500_PFMET100_PFMHT100_IDTight->GetEntry(tentry);
  b_HLT_PFHT700_PFMET85_PFMHT85_IDTight->GetEntry(tentry);
  b_HLT_PFHT800_PFMET75_PFMHT75_IDTight->GetEntry(tentry);
  b_HLT_PFMET120_PFMHT120_IDTight->GetEntry(tentry);
  b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight->GetEntry(tentry);
  b_HLT_MonoCentralPFJet80_PFMETNoMu120_PFMHTNoMu120_IDTight->GetEntry(tentry);
  b_HLT_CaloJet500_NoJetID->GetEntry(tentry);
  b_HLT_AK8PFJet500->GetEntry(tentry);
  b_HLT_PFJet500->GetEntry(tentry);
  b_HLT_PFHT1050->GetEntry(tentry);
  b_Flag_goodVertices->GetEntry(tentry);
  b_Flag_CSCTightHalo2015Filter->GetEntry(tentry);
  b_Flag_HBHENoiseFilter->GetEntry(tentry);
  b_Flag_HBHENoiseIsoFilter->GetEntry(tentry);
  b_Flag_EcalDeadCellTriggerPrimitiveFilter->GetEntry(tentry);
  b_Flag_eeBadScFilter->GetEntry(tentry);
  b_nBestVtx->GetEntry(tentry);
  b_PUWeight->GetEntry(tentry);
  //b_PUWeightUP->GetEntry(tentry);
  //b_PUWeightDOWN->GetEntry(tentry);
  b_EVENT_run->GetEntry(tentry);
  b_EVENT_event->GetEntry(tentry);
  b_EVENT_lumiBlock->GetEntry(tentry);
  b_EVENT_genHT->GetEntry(tentry);
  b_genWeight->GetEntry(tentry);
  if(!data) b_Gen_pt->GetEntry(tentry);
  if(!data) b_Gen_eta->GetEntry(tentry);
  if(!data) b_Gen_phi->GetEntry(tentry);
  if(!data) b_Gen_pdg_id->GetEntry(tentry);
  if(!data) b_Gen_motherpdg_id->GetEntry(tentry);
}

void HistoFill(float puweight,TTree *NewTree){
  NewTree->Fill();
}

void writeFile(TTree *NewTree,TTree *NewTreeSB){
  histT_b_total_->Write();
  histT_b_passing_->Write();
  histT_c_total_->Write();
  histT_c_passing_->Write();
  histT_udsg_total_->Write();
  histT_udsg_passing_->Write();
  histM_b_total_->Write();
  histM_b_passing_->Write();
  histM_c_total_->Write();
  histM_c_passing_->Write();
  histM_udsg_total_->Write();
  histM_udsg_passing_->Write();
  histL_b_total_->Write();
  histL_b_passing_->Write();
  histL_c_total_->Write();
  histL_c_passing_->Write();
  histL_udsg_total_->Write();
  histL_udsg_passing_->Write();
  //NewTree->Write();
  //NewTreeSB->Write();
}

void fillgenWeights(){
}

void GenClassifier(float &pt){
  for (UInt_t j = 0; j < Gen_pt_->size(); ++j) {
    //cout<<j<<" "<<Gen_pdg_id_->at(j)<<" "<<Gen_motherpdg_id_->at(j)<<" "<<Gen_pt_->at(j)<<endl;
    if(abs(Gen_pdg_id_->at(j))==1 && (abs(Gen_motherpdg_id_->at(j))==2212 || abs(Gen_motherpdg_id_->at(j))==21)) dQuark = dQuark + 1;
    if(abs(Gen_pdg_id_->at(j))==2 && (abs(Gen_motherpdg_id_->at(j))==2212 || abs(Gen_motherpdg_id_->at(j))==21)) uQuark = uQuark + 1;
    if(abs(Gen_pdg_id_->at(j))==3 && (abs(Gen_motherpdg_id_->at(j))==2212 || abs(Gen_motherpdg_id_->at(j))==21)) sQuark = sQuark + 1;
    if(abs(Gen_pdg_id_->at(j))==4 && (abs(Gen_motherpdg_id_->at(j))==2212 || abs(Gen_motherpdg_id_->at(j))==21)) cQuark = cQuark + 1;
    if(abs(Gen_pdg_id_->at(j))==5 && (abs(Gen_motherpdg_id_->at(j))==2212 || abs(Gen_motherpdg_id_->at(j))==21)) bQuark = bQuark + 1;
    if(abs(Gen_pdg_id_->at(j))==6 && (abs(Gen_motherpdg_id_->at(j))==2212 || abs(Gen_motherpdg_id_->at(j))==21)) tQuark = tQuark + 1;
    if(abs(Gen_pdg_id_->at(j))==23) pt = Gen_pt_->at(j);
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

/*void GenWeight(string fileName, float pt){
  if(fileName.find("ZZTo4L")!=string::npos || fileName.find("ZZTo2L2Q")!=string::npos || fileName.find("WZTo1L1Nu2Q")!=string::npos || fileName.find("WZTo2L2Q")!=string::npos || fileName.find("ttZ")!=string::npos || fileName.find("WZTo3LNu")!=string::npos || fileName.find("tZq")!=string::npos || fileName.find("ttW")!=string::npos)  genWeight=(genWeight_)/abs(genWeight_);
  else  genWeight=1;
  if(fileName.find("DY")!=string::npos) {
    if(pt>0) genWeight = functZPt->Eval(pt);
    else genWeight = 1;
  }
}*/

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

void FillBranches(bool ResolvedEvent,bool PartiallyMerged,bool FullyMerged,TLorentzVector TopQuark,bool SelectedZBosonElectrons,bool SelectedZBosonMuons,bool SelectedMet,TLorentzVector ZBoson,TLorentzVector Tprime,TLorentzVector TopQuarkResolved,TLorentzVector Jet1Resolved,TLorentzVector Jet2Resolved,TLorentzVector Jet3Resolved,TLorentzVector TprimeResolved,TLorentzVector TopQuarkPartial,TLorentzVector Jet1Partial,TLorentzVector Jet2Partial,TLorentzVector TprimePartial,float WMass_,float WSubjet_,TLorentzVector TopQuarkMerged,TLorentzVector TprimeMerged,float TopSoftMass_,float TopSubjet_,TLorentzVector Electron1,TLorentzVector Electron2,TLorentzVector Muon1,TLorentzVector Muon2,vector<TLorentzVector> SelectedForwardJets,vector<TLorentzVector> SelectedBJets){
  int NumSelBJets = SelectedBJets.size();
  if(ResolvedEvent || PartiallyMerged || FullyMerged){
    TopMass=TopQuark.M();
    TopPt  =TopQuark.Pt();
    TopEta =TopQuark.Eta();
    TopPhi =TopQuark.Phi();
  }
  if(SelectedZBosonElectrons || SelectedZBosonMuons){
    ZMass=ZBoson.M();
    ZPt  =ZBoson.Pt();
    ZEta =ZBoson.Eta();
    ZPhi =ZBoson.Phi();
  }
  if((SelectedZBosonElectrons || SelectedZBosonMuons) && (ResolvedEvent || PartiallyMerged || FullyMerged)){
    TprimeMass   = Tprime.M();
    TprimePt     = Tprime.Pt();
    TprimeEta    = Tprime.Eta();
    TprimePhi    = Tprime.Phi();
    deltaPhiZTop = DeltaPhi(TopQuark.Phi(),ZBoson.Phi());
    deltaRZTop   = DeltaR(TopQuark.Eta(),ZBoson.Eta(),TopQuark.Phi(),ZBoson.Phi());
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
    TprimeResolvedMass=TprimeResolved.M();
    TprimeResolvedPt=TprimeResolved.Pt();
    TprimeResolvedEta=TprimeResolved.Eta();
    TprimeResolvedPhi=TprimeResolved.Phi();
    deltaPhiZTopResolved = DeltaPhi(TopQuarkResolved.Phi(),ZBoson.Phi());
    deltaRZTopResolved = DeltaR(TopQuarkResolved.Eta(),ZBoson.Eta(),TopQuarkResolved.Phi(),ZBoson.Phi());
    WMassResolved1 = (Jet1Resolved+Jet2Resolved).M();
    WMassResolved2 = (Jet1Resolved+Jet3Resolved).M();
    WMassResolved3 = (Jet2Resolved+Jet3Resolved).M();
  }
  if(PartiallyMerged){
    TopMassPartial=TopQuarkPartial.M();
    TopPtPartial=TopQuarkPartial.Pt();
    TopEtaPartial=TopQuarkPartial.Eta();
    TopPhiPartial=TopQuarkPartial.Phi();
    Jet1PartialPt  = Jet1Partial.Pt();
    Jet2PartialPt  = Jet2Partial.Pt();
    Jet1PartialEta  = Jet1Partial.Eta();
    Jet2PartialEta  = Jet2Partial.Eta();
    TprimePartialMass=TprimePartial.M();
    TprimePartialPt=TprimePartial.Pt();
    TprimePartialEta=TprimePartial.Eta();
    TprimePartialPhi=TprimePartial.Phi();
    deltaPhiZTopPartial = DeltaPhi(TopQuarkPartial.Phi(),ZBoson.Phi());
    deltaRZTopPartial = DeltaR(TopQuarkPartial.Eta(),ZBoson.Eta(),TopQuarkPartial.Phi(),ZBoson.Phi());
    WMass = WMass_; 
    WSubjet = WSubjet_;
  }
  if(FullyMerged){
    TopMassMerged=TopQuarkMerged.M();
    TopPtMerged=TopQuarkMerged.Pt();
    TopEtaMerged=TopQuarkMerged.Eta();
    TopPhiMerged=TopQuarkMerged.Phi();
    Jet1MergedPt   = TopQuarkMerged.Pt();
    Jet1MergedEta  = TopQuarkMerged.Eta();
    TprimeMergedMass=TprimeMerged.M();
    TprimeMergedPt=TprimeMerged.Pt();
    TprimeMergedEta=TprimeMerged.Eta();
    TprimeMergedPhi=TprimeMerged.Phi();
    deltaPhiZTopMerged = DeltaPhi(TopQuarkMerged.Phi(),ZBoson.Phi());
    deltaRZTopMerged = DeltaR(TopQuarkMerged.Eta(),ZBoson.Eta(),TopQuarkMerged.Phi(),ZBoson.Phi());
    TopSoftMass = TopSoftMass_;
    TopSubjet = TopSubjet_;
    if(SelectedBJets.size()==1) deltaRbTop = DeltaR(TopQuarkMerged.Eta(),SelectedBJets[0].Eta(),TopQuarkMerged.Phi(),SelectedBJets[0].Phi());
  }
  if(SelectedZBosonElectrons){
    Electron1Pt=Electron1.Pt();
    Electron2Pt=Electron2.Pt();
    Electron1E=Electron1.E();
    Electron2E=Electron2.E();
    Electron1Eta=Electron1.Eta();
    Electron2Eta=Electron2.Eta();
    Electron1Phi=Electron1.Phi();
    Electron2Phi=Electron2.Phi();
    deltaREle1Ele2 = DeltaR(Electron1.Eta(),Electron2.Eta(),Electron1.Phi(),Electron2.Phi());
  }
  if(SelectedZBosonMuons){
    //Muon1Iso=Muo1Iso_;
    //Muon2Iso=Muo2Iso_;
    Muon1Pt=Muon1.Pt();
    Muon2Pt=Muon2.Pt();
    Muon1Eta=Muon1.Eta();
    Muon2Eta=Muon2.Eta();
    Muon1Phi=Muon1.Phi();
    Muon2Phi=Muon2.Phi();
    deltaRMuo1Muo2 = DeltaR(Muon1.Eta(),Muon2.Eta(),Muon1.Phi(),Muon2.Phi());
  }
  if(SelectedForwardJets.size()>0) Jet1ForwardPt=SelectedForwardJets[0].Pt();
  if(SelectedForwardJets.size()>1) Jet2ForwardPt=SelectedForwardJets[1].Pt();
  if(SelectedForwardJets.size()>2) Jet3ForwardPt=SelectedForwardJets[2].Pt();
  if(SelectedForwardJets.size()>0) Jet1ForwardEta=SelectedForwardJets[0].Eta();
  if(SelectedForwardJets.size()>1) Jet2ForwardEta=SelectedForwardJets[1].Eta();
  if(SelectedForwardJets.size()>2) Jet3ForwardEta=SelectedForwardJets[2].Eta();
  if(NumSelBJets>0 && SelectedZBosonMuons) {
    deltaRb1Lep1 = DeltaR(SelectedBJets[0].Eta(),Muon1.Eta(),SelectedBJets[0].Phi(),Muon1.Phi());
    deltaRb1Lep2 = DeltaR(SelectedBJets[0].Eta(),Muon2.Eta(),SelectedBJets[0].Phi(),Muon2.Phi());
  }
  if(NumSelBJets>0 && SelectedZBosonElectrons) {
    deltaRb1Lep1 = DeltaR(SelectedBJets[0].Eta(),Electron1.Eta(),SelectedBJets[0].Phi(),Electron1.Phi());
    deltaRb1Lep2 = DeltaR(SelectedBJets[0].Eta(),Electron2.Eta(),SelectedBJets[0].Phi(),Electron2.Phi());
  }
  if(NumSelBJets>1 && SelectedZBosonMuons) {
    deltaRb1b2   = DeltaR(SelectedBJets[0].Eta(),SelectedBJets[1].Eta(),SelectedBJets[0].Phi(),SelectedBJets[1].Phi());
    deltaRb1Lep1 = DeltaR(SelectedBJets[0].Eta(),Muon1.Eta(),SelectedBJets[0].Phi(),Muon1.Phi());
    deltaRb1Lep2 = DeltaR(SelectedBJets[0].Eta(),Muon2.Eta(),SelectedBJets[0].Phi(),Muon2.Phi());
    deltaRb2Lep1 = DeltaR(SelectedBJets[1].Eta(),Muon1.Eta(),SelectedBJets[1].Phi(),Muon1.Phi());
    deltaRb2Lep2 = DeltaR(SelectedBJets[1].Eta(),Muon2.Eta(),SelectedBJets[1].Phi(),Muon2.Phi());
    Massb1b2     = (SelectedBJets[0]+SelectedBJets[1]).M();
  }
  if(NumSelBJets>1 && SelectedZBosonElectrons) {
    deltaRb1b2   = DeltaR(SelectedBJets[0].Eta(),SelectedBJets[1].Eta(),SelectedBJets[0].Phi(),SelectedBJets[1].Phi());
    deltaRb1Lep1 = DeltaR(SelectedBJets[0].Eta(),Electron1.Eta(),SelectedBJets[0].Phi(),Electron1.Phi());
    deltaRb1Lep2 = DeltaR(SelectedBJets[0].Eta(),Electron2.Eta(),SelectedBJets[0].Phi(),Electron2.Phi());
    deltaRb2Lep1 = DeltaR(SelectedBJets[1].Eta(),Electron1.Eta(),SelectedBJets[1].Phi(),Electron1.Phi());
    deltaRb2Lep2 = DeltaR(SelectedBJets[1].Eta(),Electron2.Eta(),SelectedBJets[1].Phi(),Electron2.Phi());
    Massb1b2     = (SelectedBJets[0]+SelectedBJets[1]).M();
  }
  if(SelectedMet){
    deltaPhiMetTop = DeltaPhi(TopQuark.Phi(),Met_phi);
  }
}
