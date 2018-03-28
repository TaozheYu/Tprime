#include "CondFormats/BTauObjects/interface/BTagCalibration.h"
#include "CondFormats/BTauObjects/interface/BTagCalibrationReader.h"
#include "TBranch.h"
#include "TTree.h"
#include "TFile.h"
#include "TStyle.h"
#include "TH1F.h"
#include "TMath.h"
#include <iostream>

void branch(bool data, TTree *NewTree,TTree *NewTreeSB, string fileName);
void SelectElectrons(vector<TLorentzVector> & SelectedElectrons, vector<int> & SelectedElectronsIndex, bool data);
void SelectMuons(vector<TLorentzVector> & SelectedMuons, vector<int> & SelectedMuonsIndex);
void SelectZBoson(bool electrons,bool &SelectedZBoson,TLorentzVector &ZBoson,TLorentzVector &Lep1,TLorentzVector &Lep2,vector<TLorentzVector> SelectedLeptons,vector<int> SelectedLeptonsIndex,float dRLep1Lep2,float Zpt,float leadLepPt);
void SelectJets(int jetType,vector<TLorentzVector> & SelectedJets, vector<float> & SelectedJetsCSV, vector<TLorentzVector> SelectedElectrons, vector<TLorentzVector> SelectedMuons, 
		int SysJes, int SysJer, bool data);
void SelectCA8Jets(int CA8jetType, vector<TLorentzVector> & SelectedWJets, vector<TLorentzVector> SelectedElectrons, vector<TLorentzVector> SelectedMuons, vector<int> & CA8Indices, 
		int SysJes, int SysJer, bool data);
void ResolvedRegionSelection(bool &ResolvedEvent,vector<TLorentzVector> SelectedJets,vector<float> SelectedJetsCSV,TLorentzVector &TopQuark,
			     TLorentzVector &Jet1,TLorentzVector &Jet2,TLorentzVector &Jet3,bool TopMassCut,bool btag);
void PartiallyMergedSelection(bool &PartiallyMerged,vector<TLorentzVector> SelectedWJets,vector<TLorentzVector> SelectedJets,vector<float> SelectedJetsCSV,TLorentzVector &TopQuark,
			      TLorentzVector &Jet1,TLorentzVector &Jet2,bool TopMassCut,bool btag,vector<int> CA8Indices,int & CA8Index,float &WMass_,float &WSubjet_, bool data);
void FullyMergedSelection(bool & FullyMerged, vector<TLorentzVector> SelectedTopJets, TLorentzVector &TopQuark,vector<int> CA8Indices,float &TopSoftMass_,float &TopSubjet_, bool data);
void BprimeSelection(bool & Bprime, vector<TLorentzVector> SelectedJets, vector<float> SelectedBJetsCSV, TLorentzVector &Jet, float &BQuarkCSV);
void BTagSF(float JetPt, float JetEta, int flav, float &SF, float &SFerr);
void get_weight_btag(int selection, float &w_Btag, float &w_BtagUp, float &w_BtagDown, float &w_Btag1Up, float &w_Btag1Down, float &w_Btag2Up, float &w_Btag2Down, float &w_BtagLoose, float &w_BtagLooseUp, float &w_BtagLooseDown, string fileName);
void WSF(TLorentzVector WJet, bool PartiallyMerged, float &w_WJet_, float &w_WJetUp_, float &w_WJetDown_, int CA8Index, int SysJes, int SysJer);
void TopSF(TLorentzVector SelectedTopJets, bool FullyMerged, float &w_topJet_, float &w_topJetUp_, float &w_topJetDown_);
void ForwardJetSF(vector<TLorentzVector> SelectedForwardJets, float &w_for_, float &w_forUp_, float &w_forDown_);
void MuonSF(bool SelectedZBosonMuons, float pt, float eta, float &w_Muon_, float &w_MuonUp_, float &w_MuonDown_);
void ElectronSF(bool SelectedZBosonElectrons, float pt, float eta, float &w_Electron_, float &w_ElectronUp_, float &w_ElectronDown_);
void MuonTriggerSF(float pt, float eta);
void ElectronTriggerSF(float pt, float eta);
float DeltaR(float eta1, float eta2, float phi1, float phi2);
float DeltaPhi(float phi1, float phi2);
float HTcalculator(vector<TLorentzVector> SelectedJets);
void branchGetEntry(bool data, Long64_t tentry=0, string fileName="");
void HistoFill(float pileupReweight,TTree *NewTree);
void writeFile(TTree *NewTree,TTree *NewTreeSB);
void initializeVar();
void resetHistos();
void fillgenWeights();
void GenClassifier(float &pt);
void GenWBoson(bool &matched, TLorentzVector Wjet);
void GenWeight(string fileName, float pt);
void newPUWeight(float &puweight,float &puweightUP,float &puweightDOWN);
void FillBranches(bool ResolvedEvent,bool PartiallyMerged,bool FullyMerged,TLorentzVector TopQuark,bool SelectedZBosonElectrons,bool SelectedZBosonMuons,TLorentzVector ZBoson,TLorentzVector Tprime,TLorentzVector TopQuarkResolved,TLorentzVector Jet1Resolved,TLorentzVector Jet2Resolved,TLorentzVector Jet3Resolved,TLorentzVector TprimeResolved,TLorentzVector TopQuarkPartial,TLorentzVector Jet1Partial,TLorentzVector Jet2Partial,TLorentzVector TprimePartial,float WMass_,float WSubjet_,TLorentzVector TopQuarkMerged,TLorentzVector TprimeMerged,float TopSoftMass_,float TopSubjet_,TLorentzVector Electron1,TLorentzVector Electron2,TLorentzVector Muon1,TLorentzVector Muon2,vector<TLorentzVector> SelectedForwardJets,vector<TLorentzVector> SelectedBJets);
//BTAG SF
BTagCalibration calib("CSVv2", "SF_2017/CSVv2_94XSF_V1_B_F.csv");
BTagCalibrationReader readerTIncl(&calib,      BTagEntry::OP_TIGHT, "incl",   "central");
BTagCalibrationReader readerTIncl_up(&calib,   BTagEntry::OP_TIGHT, "incl",   "up");
BTagCalibrationReader readerTIncl_do(&calib,   BTagEntry::OP_TIGHT, "incl",   "down");
BTagCalibrationReader readerTComb(&calib,    BTagEntry::OP_TIGHT, "comb", "central");
BTagCalibrationReader readerTComb_up(&calib, BTagEntry::OP_TIGHT, "comb", "up");
BTagCalibrationReader readerTComb_do(&calib, BTagEntry::OP_TIGHT, "comb", "down");
BTagCalibrationReader readerMIncl(&calib,      BTagEntry::OP_MEDIUM, "incl",   "central");
BTagCalibrationReader readerMIncl_up(&calib,   BTagEntry::OP_MEDIUM, "incl",   "up");
BTagCalibrationReader readerMIncl_do(&calib,   BTagEntry::OP_MEDIUM, "incl",   "down");
BTagCalibrationReader readerMComb(&calib,    BTagEntry::OP_MEDIUM, "comb", "central");
BTagCalibrationReader readerMComb_up(&calib, BTagEntry::OP_MEDIUM, "comb", "up");
BTagCalibrationReader readerMComb_do(&calib, BTagEntry::OP_MEDIUM, "comb", "down");
BTagCalibrationReader readerLIncl(&calib,      BTagEntry::OP_LOOSE,  "incl",   "central");
BTagCalibrationReader readerLIncl_up(&calib,   BTagEntry::OP_LOOSE,  "incl",   "up");
BTagCalibrationReader readerLIncl_do(&calib,   BTagEntry::OP_LOOSE,  "incl",   "down");
BTagCalibrationReader readerLComb(&calib,    BTagEntry::OP_LOOSE,  "comb", "central");
BTagCalibrationReader readerLComb_up(&calib, BTagEntry::OP_LOOSE,  "comb", "up");
BTagCalibrationReader readerLComb_do(&calib, BTagEntry::OP_LOOSE,  "comb", "down");

//Lepton SF

TFile *fileForwardJet    = new TFile("SF_2017/ForwardJetSFFinal.root");
TFile *fileMuonTrig      = new TFile("SF_2017/EfficienciesAndSF_RunBtoF_Nov17Nov2017.root");
TFile *fileElectron1     = new TFile("SF_2017/egammaEffi.txt_EGM2D_runBCDEF_passingRECO.root");
TFile *fileElectron2     = new TFile("SF_2017/egammaEffi.txt_EGM2D_runBCDEF_passingTight94X.root");
TFile *fileElectronTrig  = new TFile("SF_2017/ElectronTriggerSF.root");
TFile *fileOldPU         = new TFile("SF_2017/PileUpReweighting2017.root");
TFile *fileNewPU         = new TFile("SF_2017/PileUpReweighting2017_v1.root");
TFile *fileNewPUUp       = new TFile("SF_2017/PileUpReweighting2017Up.root");
TFile *fileNewPUDo       = new TFile("SF_2017/PileUpReweighting2017Do.root");
TFile *fileZPt           = new TFile("SF_2017/scalefactors_v4.root");
TH2F  *histoForwardJet   = (TH2F*)fileForwardJet->Get("histo");
TH2F  *histoMuonTrig     = (TH2F*)fileMuonTrig->Get("Mu50_PtEtaBins/abseta_pt_ratio");
TH2F  *histoElectron1    = (TH2F*)fileElectron1->Get("EGamma_SF2D");
TH2F  *histoElectron2    = (TH2F*)fileElectron2->Get("EGamma_SF2D");
TH2F  *histoElectronTrig = (TH2F*)fileElectronTrig->Get("eta_pt");
TH1F  *histoOldPU        = (TH1F*)fileOldPU  ->Get("pileup");
TH1F  *histoNewPU        = (TH1F*)fileNewPU  ->Get("pileup");
TH1F  *histoNewPUUp      = (TH1F*)fileNewPUUp->Get("pileup");
TH1F  *histoNewPUDo      = (TH1F*)fileNewPUDo->Get("pileup");
TF1   *functZPt          = (TF1*) fileZPt->Get("z_ewkcorr/z_ewkcorr_func");

TTree *Tree;

TLorentzVector Electron1SC; 
TLorentzVector Electron2SC; 

//RECO INFO
vector <double> * Jet_pt_;   TBranch *b_Jet_pt;
vector <double> * Jet_eta_;  TBranch *b_Jet_eta;
vector <double> * Jet_phi_;  TBranch *b_Jet_phi;
vector <double> * Jet_mass_; TBranch *b_Jet_mass;
vector <double> * Jet_JesSF_;TBranch *b_Jet_JesSF;
vector <double> * Jet_JesSFup_;TBranch *b_Jet_JesSFup;
vector <double> * Jet_JesSFdown_;TBranch *b_Jet_JesSFdown;
vector <double> * Jet_JerSF_;TBranch *b_Jet_JerSF;
vector <double> * Jet_JerSFup_;TBranch *b_Jet_JerSFup;
vector <double> * Jet_JerSFdown_;TBranch *b_Jet_JerSFdown;
vector <double> * Jet_Uncorr_pt_; TBranch *b_Jet_Uncorr_pt;
vector <double> * Jet_pfCombinedInclusiveSecondaryVertexV2BJetTags_;              TBranch *b_Jet_pfCombinedInclusiveSecondaryVertexV2BJetTags;
vector <double> * Jet_neutralHadEnergyFraction_;    TBranch *b_Jet_neutralHadEnergyFraction;
vector <double> * Jet_chargedEmEnergyFraction_;     TBranch *b_Jet_chargedEmEnergyFraction;
vector <double> * Jet_neutralEmEnergyFraction_;   TBranch *b_Jet_neutralEmEnergyFraction;
vector <double> * Jet_numberOfConstituents_;        TBranch *b_Jet_numberOfConstituents;
vector <double> * Jet_chargedHadronEnergyFraction_; TBranch *b_Jet_chargedHadronEnergyFraction;
vector <double> * Jet_chargedMultiplicity_;         TBranch *b_Jet_chargedMultiplicity;
vector <double> * Jet_hadronFlavour_; TBranch *b_Jet_hadronFlavour;
vector <double> * BoostedJet_pt_;        TBranch *b_BoostedJet_pt;
vector <double> * BoostedJet_Uncorr_pt_; TBranch *b_BoostedJet_Uncorr_pt;
vector <double> * BoostedJet_softdrop_mass_; TBranch *b_BoostedJet_softdrop_mass;
vector <double> * BoostedJet_JesSF_;TBranch *b_BoostedJet_JesSF;
vector <double> * BoostedJet_JesSFup_;TBranch *b_BoostedJet_JesSFup;
vector <double> * BoostedJet_JesSFdown_;TBranch *b_BoostedJet_JesSFdown;
vector <double> * BoostedJet_JerSF_;TBranch *b_BoostedJet_JerSF;
vector <double> * BoostedJet_JerSFup_;TBranch *b_BoostedJet_JerSFup;
vector <double> * BoostedJet_JerSFdown_;TBranch *b_BoostedJet_JerSFdown;
vector <double> * BoostedJet_eta_;  TBranch *b_BoostedJet_eta;
vector <double> * BoostedJet_phi_;  TBranch *b_BoostedJet_phi;
vector <double> * BoostedJet_mass_; TBranch *b_BoostedJet_mass;
vector <double> * BoostedJet_tau1_; TBranch *b_BoostedJet_tau1;
vector <double> * BoostedJet_tau2_; TBranch *b_BoostedJet_tau2;
vector <double> * BoostedJet_tau3_; TBranch *b_BoostedJet_tau3;

vector<double> * BoostedJet_puppi_pt_;     TBranch *b_BoostedJet_puppi_pt; 
vector<double> * BoostedJet_puppi_mass_;   TBranch *b_BoostedJet_puppi_mass;
vector<double> * BoostedJet_puppi_eta_;    TBranch *b_BoostedJet_puppi_eta;
vector<double> * BoostedJet_puppi_phi_;    TBranch *b_BoostedJet_puppi_phi;
vector<double> * BoostedJet_puppi_tau1_;   TBranch *b_BoostedJet_puppi_tau1; 
vector<double> * BoostedJet_puppi_tau2_;   TBranch *b_BoostedJet_puppi_tau2;
vector<double> * BoostedJet_puppi_tau3_;   TBranch *b_BoostedJet_puppi_tau3; 
vector<double> * BoostedJet_puppi_softdrop_masscorr_;  TBranch *b_BoostedJet_puppi_softdrop_masscorr;

vector <double> * BoostedJet_pruned_mass_;  TBranch *b_BoostedJet_pruned_mass;
vector <double> * BoostedJet_neutralHadEnergyFraction_;    TBranch *b_BoostedJet_neutralHadEnergyFraction;
vector <double> * BoostedJet_chargedEmEnergyFraction_;     TBranch *b_BoostedJet_chargedEmEnergyFraction;
vector <double> * BoostedJet_neutralEmEmEnergyFraction_;     TBranch *b_BoostedJet_neutralEmEmEnergyFraction;
vector <double> * BoostedJet_numberOfConstituents_;        TBranch *b_BoostedJet_numberOfConstituents;
vector <double> * BoostedJet_chargedHadronEnergyFraction_; TBranch *b_BoostedJet_chargedHadronEnergyFraction;
vector <double> * BoostedJet_chargedMultiplicity_;         TBranch *b_BoostedJet_chargedMultiplicity;
vector <double> * TopTagging_topMass_;  TBranch *b_TopTagging_topMass;
vector <double> * TopTagging_minMass_;  TBranch *b_TopTagging_minMass;
vector <double> * TopTagging_wMass_; TBranch *b_TopTagging_wMass;
vector <double> * TopTagging_nSubJets_; TBranch *b_TopTagging_nSubJets;
vector <double> * patElectron_pt_; TBranch *b_patElectron_pt;
vector <double> * patElectron_eta_; TBranch *b_patElectron_eta;
vector <double> * patElectron_phi_; TBranch *b_patElectron_phi;
vector <double> * patElectron_energy_; TBranch *b_patElectron_energy; 
vector <double> * patElectron_energyCorr_; TBranch *b_patElectron_energyCorr;  
vector <double> * patElectron_SCeta_; TBranch *b_patElectron_SCeta;
vector <int> * patElectron_charge_; TBranch *b_patElectron_charge;
vector <int> * patElectron_isPassVeto_; TBranch *b_patElectron_isPassVeto;
vector <int> * patElectron_isPassLoose_; TBranch *b_patElectron_isPassLoose;
vector <int> * patElectron_isPassMedium_; TBranch *b_patElectron_isPassMedium;
vector <int> * patElectron_isPassTight_; TBranch *b_patElectron_isPassTight;
vector <int> * patElectron_isPassHEEPId_; TBranch *b_patElectron_isPassHEEPId;
vector <double> * patElectron_d0_; TBranch *b_patElectron_d0;
vector <double> * patElectron_gsfTrack_dz_pv_; TBranch *b_patElectron_gsfTrack_dz_pv;
vector <int> * patElectron_expectedMissingInnerHits_; TBranch *b_patElectron_expectedMissingInnerHits;
vector <int> * patElectron_passConversionVeto_; TBranch *b_patElectron_passConversionVeto;
vector <double> * patElectron_isoChargedHadrons_; TBranch *b_patElectron_isoChargedHadrons;
vector <double> * patElectron_isoNeutralHadrons_; TBranch *b_patElectron_isoNeutralHadrons;
vector <double> * patElectron_isoPhotons_; TBranch *b_patElectron_isoPhotons;
vector <double> * patElectron_isoPU_; TBranch *b_patElectron_isoPU;
vector <double> * patElectron_dEtaIn_; TBranch *b_patElectron_dEtaIn;
vector <double> * patElectron_dPhiIn_; TBranch *b_patElectron_dPhiIn;
vector <double> * patElectron_full5x5_sigmaIetaIeta_; TBranch *b_patElectron_full5x5_sigmaIetaIeta;
vector <double> * patElectron_hOverE_; TBranch *b_patElectron_hOverE;
vector <double> * patElectron_ooEmooP_; TBranch *b_patElectron_ooEmooP;
vector <double> * patElectron_relIsoRhoEA_; TBranch *b_patElectron_relIsoRhoEA;
vector <double> * patElectron_inCrack_; TBranch *b_patElectron_inCrack;
vector <int> * patElectron_pdgId_; TBranch *b_patElectron_pdgId;
vector <int> * patElectron_isMatchedToTrigger_; TBranch *b_patElectron_isMatchedToTrigger;
vector <double> * Muon_pt_; TBranch *b_Muon_pt;
vector <double> * Muon_eta_; TBranch *b_Muon_eta;
vector <double> * Muon_phi_; TBranch *b_Muon_phi;
vector <double> * Muon_energy_; TBranch *b_Muon_energy;  
vector <int> * Muon_charge_; TBranch *b_Muon_charge;
vector <int> * Muon_tight_; TBranch *b_Muon_tight;
vector <int> * Muon_loose_; TBranch *b_Muon_loose;
vector <int> * Muon_soft_; TBranch *b_Muon_soft;
vector <int> * Muon_isHighPt_; TBranch *b_Muon_isHighPt;
vector <int> * Muon_pf_; TBranch *b_Muon_pf;
vector <double> * Muon_dxy_pv_; TBranch *b_Muon_dxy_pv;
vector <double> * Muon_dz_pv_; TBranch *b_Muon_dz_pv;
vector <int> * Muon_isGlobal_; TBranch *b_Muon_isGlobal;
vector <double> * Muon_isoCharged_; TBranch *b_Muon_isoCharged;
vector <double> * Muon_isoSum_; TBranch *b_Muon_isoSum;
vector <double> * Muon_isoCharParPt_; TBranch *b_Muon_isoCharParPt;
vector <double> * Muon_relIsoDeltaBetaR04_; TBranch *b_Muon_relIsoDeltaBetaR04;
vector <int> * Muon_isMatchedToTrigger_; TBranch *b_Muon_isMatchedToTrigger;
vector <int> * Muon_pdgId_; TBranch *b_Muon_pdgId;
int HLT_Ele115_CaloIdVT_GsfTrkIdT_; TBranch *b_HLT_Ele115_CaloIdVT_GsfTrkIdT;
int HLT_DoubleEle33_CaloIdL_MW_; TBranch *b_HLT_DoubleEle33_CaloIdL_MW;
int HLT_Ele27_eta2p1_WP75_Gsf_; TBranch *b_HLT_Ele27_eta2p1_WP75_Gsf;
int HLT_Ele27_eta2p1_WPLoose_Gsf_; TBranch *b_HLT_Ele27_eta2p1_WPLoose_Gsf;
int HLT_Mu50_; TBranch *b_HLT_Mu50;
int HLT_TkMu50_; TBranch *b_HLT_TkMu50;
int HLT_IsoMu24_; TBranch *b_HLT_IsoMu24;
int HLT_IsoTkMu24_; TBranch *b_HLT_IsoTkMu24;
int Flag_goodVertices_; TBranch *b_Flag_goodVertices;
int Flag_CSCTightHalo2015Filter_; TBranch *b_Flag_CSCTightHalo2015Filter;
int Flag_HBHENoiseFilter_; TBranch *b_Flag_HBHENoiseFilter;
int Flag_HBHENoiseIsoFilter_; TBranch *b_Flag_HBHENoiseIsoFilter;
int Flag_EcalDeadCellTriggerPrimitiveFilter_; TBranch *b_Flag_EcalDeadCellTriggerPrimitiveFilter;
int Flag_eeBadScFilter_; TBranch *b_Flag_eeBadScFilter;
int nBestVtx_; TBranch *b_nBestVtx;
double PUWeight_; TBranch *b_PUWeight;
double PUWeightUP_; TBranch *b_PUWeightUP;
double PUWeightDOWN_; TBranch *b_PUWeightDOWN;
vector<double> * genWeights_ = new std::vector<double>; TBranch *b_genWeights;
double genWeight_; TBranch *b_genWeight;
double bWeight_; TBranch *b_bWeight;
vector <double> * Gen_pt_; TBranch *b_Gen_pt;
vector <double> * Gen_eta_; TBranch *b_Gen_eta;
vector <double> * Gen_phi_; TBranch *b_Gen_phi;
vector <double> * Gen_pdg_id_; TBranch *b_Gen_pdg_id;
vector <double> * Gen_motherpdg_id_; TBranch *b_Gen_motherpdg_id;
int EVENT_event_; TBranch *b_EVENT_event;
int EVENT_run_; TBranch *b_EVENT_run;
int EVENT_lumiBlock_; TBranch *b_EVENT_lumiBlock;
double EVENT_genHT_; TBranch *b_EVENT_genHT;

int category0=0;
int category1=0;
int category2=0;
int category3=0;
int category4=0;
int category5=0;
int category6=0;
int category7=0;
float TopMass=-99;
float TopMassMerged=-99;
float TopMassPartial=-99;
float TopMassResolved=-99;
float TopPt=-99;
float TopPtMerged=-99;
float TopPtPartial=-99;
float TopPtResolved=-99;
float TopEta=-99;
float TopEtaMerged=-99;
float TopEtaPartial=-99;
float TopEtaResolved=-99;
float TopPhi=-99;
float TopPhiMerged=-99;
float TopPhiPartial=-99;
float TopPhiResolved=-99;
float WMassResolved1=-99;
float WMassResolved2=-99;
float WMassResolved3=-99;
float BMass=-99;
float BCSV=-99;
float BPt=-99;
float BEta=-99;
float BPhi=-99;
float ZMass=-99;
float ZPt=-99;
float ZEta=-99;
float ZPhi=-99;
float BprimeMass=-99;
float BprimePt=-99;
float BprimeEta=-99;
float BprimePhi=-99;
float TprimeMass=-99;
float TprimePt=-99;
float TprimeEta=-99;
float TprimePhi=-99;
float TprimeResolvedMass=-99;
float TprimeResolvedPt=-99;
float TprimeResolvedEta=-99;
float TprimeResolvedPhi=-99;
float TprimePartialMass=-99;
float TprimePartialPt=-99;
float TprimePartialEta=-99;
float TprimePartialPhi=-99;
float TprimeMergedMass=-99;
float TprimeMergedPt=-99;
float TprimeMergedEta=-99;
float TprimeMergedPhi=-99;
float Electron1Pt=-99;
float Electron2Pt=-99;
float Electron1E=-99;
float Electron2E=-99;
float Muon1Iso=-99;
float Muon2Iso=-99;
float Muon1Pt=-99;
float Muon2Pt=-99;
float Jet1ForwardPt=-99;
float Jet2ForwardPt=-99;
float Jet3ForwardPt=-99;
float Jet1ResolvedPt=-99;
float Jet2ResolvedPt=-99;
float Jet3ResolvedPt=-99;
float Jet1PartialPt=-99;
float Jet2PartialPt=-99;
float Jet1MergedPt=-99;
float Electron1Eta=-99;
float Electron2Eta=-99;
float Muon1Eta=-99;
float Muon2Eta=-99;
float Jet1ForwardEta=-99;
float Jet2ForwardEta=-99;
float Jet3ForwardEta=-99;
float Jet1ResolvedEta=-99;
float Jet2ResolvedEta=-99;
float Jet3ResolvedEta=-99;
float Jet1PartialEta=-99;
float Jet2PartialEta=-99;
float Jet1MergedEta=-99;
float Electron1Phi=-99;
float Electron2Phi=-99;
float Muon1Phi=-99;
float Muon2Phi=-99;
float deltaPhiZB=-99;
float deltaRZB=-99;
float deltaPhiZTop=-99;
float deltaRZTop=-99;
float deltaPhiZTopResolved=-99;
float deltaRZTopResolved=-99;
float deltaPhiZTopPartial=-99;
float deltaRZTopPartial=-99;
float deltaPhiZTopMerged=-99;
float deltaRZTopMerged=-99;
float deltaRTwoJetsFromW=-99;
float deltaRbTop=-99;
float deltaREle1Ele2=-99;
float deltaRMuo1Muo2=-99;
float deltaREle1Ele2M=-99;
float deltaRMuo1Muo2M=-99;
float Massb1b2=-99;
float deltaRb1b2=-99;
float deltaRb1Lep1=-99;
float deltaRb1Lep2=-99;
float deltaRb2Lep1=-99;
float deltaRb2Lep2=-99;
int   NumSelLeps=-99;
int   NumSelJets=-99;
int   NumSelForwardJets=-99;
int   NumSelBJetsL=-99;
int   NumSelBJetsM=-99;
int   NumSelBJetsT=-99;
int   NumSelWJets=-99;
int   NumSelTopJets=-99;
int   NVertices=-99;
float HT=-99;
float PUWeight=1; 
float PUWeightUP=1; 
float PUWeightDOWN=1; 
int EVENT_event=-99;
int EVENT_run=-99;
int EVENT_lumiBlock=-99;
float EVENT_genHT=-99;
int getTrueNumInteractions=-99;
float w_for = 1;
float w_forUp = 1;
float w_forDown = 1;
float w_topJet = 1;
float w_topJetUp = 1;
float w_topJetDown = 1;
float w_WJet   = 1;
float w_WJetUp = 1;
float w_WJetDown = 1;
float w_Muon1  = 1;
float w_Muon2  = 1;
float w_Muon1Up  = 1;
float w_Muon2Up  = 1;
float w_Muon1Down  = 1;
float w_Muon2Down  = 1;
float w_Electron1  = 1;
float w_Electron2  = 1;
float w_Electron1Up  = 1;
float w_Electron2Up  = 1;
float w_Electron1Down  = 1;
float w_Electron2Down  = 1;
float w_TrigMuon=1;
float w_TrigMuonUp=1;
float w_TrigMuonDown=1;
float w_TrigElec=1;
float w_TrigElecUp=1;
float w_TrigElecDown=1;
float WMass = -99;
float WSubjet = -99;
float TopSoftMass = -99;
float TopSubjet = -99;
float w_Btag=1;
float w_BtagUp=1;
float w_BtagDown=1;
float w_Btag1Up=1;
float w_Btag1Down=1;
float w_Btag2Up=1;
float w_Btag2Down=1;
float w_BtagLoose=1;
float w_BtagLooseUp=1;
float w_BtagLooseDown=1;
float genWeight=1;
float GenZPt=-99.;
int dQuark=0;
int uQuark=0;
int sQuark=0;
int cQuark=0;
int bQuark=0;
int tQuark=0;
float TriggeringElePt  = -1.;
float TriggeringMuoPt  = -1.;
float TriggeringEleEta = -1.;
float TriggeringMuoEta = -1.;
