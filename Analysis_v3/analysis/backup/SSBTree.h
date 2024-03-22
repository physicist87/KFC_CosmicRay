//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jan 28 01:02:52 2015 by ROOT version 5.34/23
// from TTree SSBTree/Tree for Physics Analyses at CMS
// found on file: /beh/physicist87/SSBNtuple_File/Run11_Analysis/MC/Di_Mu_old/TTJet_Full/SSBTree_1_1_iGj.root
//////////////////////////////////////////////////////////

#ifndef SSBTree_h
#define SSBTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>
#include <TClonesArray.h>
#include <vector>
#include <vector>
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.
using namespace std;

class SSBTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           Event;
   Int_t           Run;
   Int_t           Lumi;
   Char_t          isData;
   Double_t        id1;
   Double_t        id2;
   Double_t        Bjorkenx1;
   Double_t        Bjorkenx2;
   Double_t        Q;
   vector<double>  *pdfweightUp;
   vector<double>  *pdfweightDown;
   Int_t           N_genPars;
   vector<int>     *genPar_pdgId;
   vector<int>     *genPar_status;
   vector<int>     *genPar_mom1pdgId;
   vector<int>     *genPar_mom2pdgId;
   vector<int>     *genPar_Nmother;
   vector<double>  *genPar_pt;
   TClonesArray    *TLgenPars;
   vector<int>     *genPar_idx;
   vector<int>     *genPar_mom1_idx;
   vector<int>     *genPar_mom2_idx;
   vector<int>     *genPar_dau1_idx;
   vector<int>     *genPar_dau2_idx;
   Int_t           N_genJets;
   TClonesArray    *TLgenJets;
   Int_t           N_genMet;
   vector<double>  *genMet_px;
   vector<double>  *genMet_py;
   vector<double>  *genMet_pt;
   vector<double>  *genMet_px_py;
   TClonesArray    *TLgenMET;
   vector<bool>    *greedy_mu_flt;
   vector<bool>    *incons_mu_pt_flt;
   vector<bool>    *pfreco_mu_flt;
   Int_t           NPV;
   vector<double>  *vtx_sumptsquare;
   vector<double>  *PV_Filter;
   vector<double>  *vtx_x;
   vector<double>  *vtx_y;
   vector<double>  *vtx_z;
   vector<double>  *vtx_x_error;
   vector<double>  *vtx_y_error;
   vector<double>  *vtx_z_error;
   Int_t           N_muons;
   vector<double>  *muons_pdgid;
   vector<double>  *muons_charge;
   vector<bool>    *muons_isLoose;
   vector<bool>    *muons_isSoft;
   vector<bool>    *muons_isTight;
   vector<bool>    *muons_isHighPt;
   vector<double>  *muons_relIso03;
   vector<double>  *muons_relIso04;
   vector<double>  *muons_PFIsodbeta03;
   vector<double>  *muons_PFIsodbeta04;
   TClonesArray    *TLMuons;
   Int_t           NJets;
   vector<double>  *jets_charge;
   vector<double>  *jets_pdgid;
   vector<double>  *jets_isJet;
   vector<int>     *PFJetId;
   vector<int>     *PuJetId;
   vector<float>   *jets_PuMva;
   vector<float>   *jets_bDisc;
   TClonesArray    *TLJets;
   Int_t           N_Met;
   TClonesArray    *TLMET;
   Int_t           Neles;
   vector<double>  *elecs_pdgid;
   vector<double>  *elecs_charge;
   vector<bool>    *elec_charId_gsfctfpx;
   vector<bool>    *elec_charId_gsfctf;
   vector<bool>    *elec_charId_gsfpx;
   vector<int>     *elecs_eidLoose;
   vector<int>     *elecs_eidRobustHighEnergy;
   vector<int>     *elecs_eidRobustLoose;
   vector<int>     *elecs_eidRobustTight;
   vector<int>     *elecs_eidTight;
   vector<double>  *elecs_gsfTrcharge;
   vector<double>  *elecs_ctfTrcharge;
   vector<double>  *elecs_scPixcharge;
   vector<double>  *elecs_relIso03;
   vector<double>  *elecs_relIso04;
   vector<double>  *elecs_PFIsodbeta03;
   vector<double>  *elecs_PFIsodbeta04;
   vector<double>  *elecs_PFIsoRho03;
   vector<double>  *elecs_PFIsoRho04;
   vector<float>   *elecs_mvaNonTrigV0;
   vector<float>   *elecs_mvaTrigNoIPV0;
   vector<float>   *elecs_mvaTrigV0;
   vector<int>     *elecs_Nhit;
   vector<bool>    *elecs_Conversion_1;
   vector<bool>    *elecs_Conversion_2;
   vector<bool>    *elecs_Conversion_3;
   TClonesArray    *TLElecs;
   vector<double>  *Gsfdxy;
   vector<double>  *Gsfdz;
   vector<double>  *Ctfdxy;
   vector<double>  *Ctfdz;
   vector<double>  *Supercluster_Eta;
   Double_t        NPU;
   Int_t           NPUin;
   vector<double>  *PU_wgt;
   Int_t           Nphos;
   TClonesArray    *TLPhotons;
   vector<bool>    *photons_pidLoose;
   vector<bool>    *photons_pidTight;
   vector<string>  *TriggerName;
   vector<bool>    *TriggerPass;
   vector<bool>    *TriggerError;
   vector<bool>    *TriggerRun;
   vector<unsigned int> *TriggerPreScale;

   // List of branches
   TBranch        *b_Event;   //!
   TBranch        *b_Run;   //!
   TBranch        *b_Lumi;   //!
   TBranch        *b_isData;   //!
   TBranch        *b_id1;   //!
   TBranch        *b_id2;   //!
   TBranch        *b_Bjorkenx1;   //!
   TBranch        *b_Bjorkenx2;   //!
   TBranch        *b_Q;   //!
   TBranch        *b_pdfweightUp;   //!
   TBranch        *b_pdfweightDown;   //!
   TBranch        *b_N_genPars;   //!
   TBranch        *b_genPar_pdgId;   //!
   TBranch        *b_genPar_status;   //!
   TBranch        *b_genPar_mom1pdgId;   //!
   TBranch        *b_genPar_mom2pdgId;   //!
   TBranch        *b_genPar_Nmother;   //!
   TBranch        *b_genPar_pt;   //!
   TBranch        *b_TLgenPars;   //!
   TBranch        *b_genPar_idx;   //!
   TBranch        *b_genPar_mom1_idx;   //!
   TBranch        *b_genPar_mom2_idx;   //!
   TBranch        *b_genPar_dau1_idx;   //!
   TBranch        *b_genPar_dau2_idx;   //!
   TBranch        *b_N_genJets;   //!
   TBranch        *b_TLgenJets;   //!
   TBranch        *b_N_genMet;   //!
   TBranch        *b_genMet_px;   //!
   TBranch        *b_genMet_py;   //!
   TBranch        *b_genMet_pt;   //!
   TBranch        *b_genMet_px_py;   //!
   TBranch        *b_TLgenMET;   //!
   TBranch        *b_greedy_mu_flt;   //!
   TBranch        *b_incons_mu_pt_flt;   //!
   TBranch        *b_pfreco_mu_flt;   //!
   TBranch        *b_NPV;   //!
   TBranch        *b_vtx_sumptsquare;   //!
   TBranch        *b_PV_Filter;   //!
   TBranch        *b_vtx_x;   //!
   TBranch        *b_vtx_y;   //!
   TBranch        *b_vtx_z;   //!
   TBranch        *b_vtx_x_error;   //!
   TBranch        *b_vtx_y_error;   //!
   TBranch        *b_vtx_z_error;   //!
   TBranch        *b_N_muons;   //!
   TBranch        *b_muons_pdgid;   //!
   TBranch        *b_muons_charge;   //!
   TBranch        *b_muons_isLoose;   //!
   TBranch        *b_muons_isSoft;   //!
   TBranch        *b_muons_isTight;   //!
   TBranch        *b_muons_isHighPt;   //!
   TBranch        *b_muons_relIso03;   //!
   TBranch        *b_muons_relIso04;   //!
   TBranch        *b_muons_PFIsodbeta03;   //!
   TBranch        *b_muons_PFIsodbeta04;   //!
   TBranch        *b_TLMuons;   //!
   TBranch        *b_NJets;   //!
   TBranch        *b_jets_charge;   //!
   TBranch        *b_jets_pdgid;   //!
   TBranch        *b_jets_isJet;   //!
   TBranch        *b_PFJetId;   //!
   TBranch        *b_PuJetId;   //!
   TBranch        *b_jets_PuMva;   //!
   TBranch        *b_jets_bDisc;   //!
   TBranch        *b_TLJets;   //!
   TBranch        *b_N_Met;   //!
   TBranch        *b_TLMET;   //!
   TBranch        *b_Neles;   //!
   TBranch        *b_elecs_pdgid;   //!
   TBranch        *b_elecs_charge;   //!
   TBranch        *b_elec_charId_gsfctfpx;   //!
   TBranch        *b_elec_charId_gsfctf;   //!
   TBranch        *b_elec_charId_gsfpx;   //!
   TBranch        *b_elecs_eidLoose;   //!
   TBranch        *b_elecs_eidRobustHighEnergy;   //!
   TBranch        *b_elecs_eidRobustLoose;   //!
   TBranch        *b_elecs_eidRobustTight;   //!
   TBranch        *b_elecs_eidTight;   //!
   TBranch        *b_elecs_gsfTrcharge;   //!
   TBranch        *b_elecs_ctfTrcharge;   //!
   TBranch        *b_elecs_scPixcharge;   //!
   TBranch        *b_elecs_relIso03;   //!
   TBranch        *b_elecs_relIso04;   //!
   TBranch        *b_elecs_PFIsodbeta03;   //!
   TBranch        *b_elecs_PFIsodbeta04;   //!
   TBranch        *b_elecs_PFIsoRho03;   //!
   TBranch        *b_elecs_PFIsoRho04;   //!
   TBranch        *b_elecs_mvaNonTrigV0;   //!
   TBranch        *b_elecs_mvaTrigNoIPV0;   //!
   TBranch        *b_elecs_mvaTrigV0;   //!
   TBranch        *b_elecs_Nhit;   //!
   TBranch        *b_elecs_Conversion_1;   //!
   TBranch        *b_elecs_Conversion_2;   //!
   TBranch        *b_elecs_Conversion_3;   //!
   TBranch        *b_TLElecs;   //!
   TBranch        *b_Gsfdxy;   //!
   TBranch        *b_Gsfdz;   //!
   TBranch        *b_Ctfdxy;   //!
   TBranch        *b_Ctfdz;   //!
   TBranch        *b_Supercluster_Eta;   //!
   TBranch        *b_NPU;   //!
   TBranch        *b_NPUin;   //!
   TBranch        *b_PU_wgt;   //!
   TBranch        *b_Nphos;   //!
   TBranch        *b_TLPhotons;   //!
   TBranch        *b_photons_pidLoose;   //!
   TBranch        *b_photons_pidTight;   //!
   TBranch        *b_TriggerName;   //!
   TBranch        *b_TriggerPass;   //!
   TBranch        *b_TriggerError;   //!
   TBranch        *b_TriggerRun;   //!
   TBranch        *b_TriggerPreScale;   //!

   SSBTree(TTree *tree=0);
   virtual ~SSBTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef SSBTree_cxx
SSBTree::SSBTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
/*   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/beh/physicist87/SSBNtuple_File/Run11_Analysis/MC/Di_Mu_old/TTJet_Full/SSBTree_1_1_iGj.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/beh/physicist87/SSBNtuple_File/Run11_Analysis/MC/Di_Mu_old/TTJet_Full/SSBTree_1_1_iGj.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("/beh/physicist87/SSBNtuple_File/Run11_Analysis/MC/Di_Mu_old/TTJet_Full/SSBTree_1_1_iGj.root:/ssbanalyzer");
      dir->GetObject("SSBTree",tree);

   }*/
   Init(tree);
}

SSBTree::~SSBTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t SSBTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t SSBTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void SSBTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   pdfweightUp = 0;
   pdfweightDown = 0;
   genPar_pdgId = 0;
   genPar_status = 0;
   genPar_mom1pdgId = 0;
   genPar_mom2pdgId = 0;
   genPar_Nmother = 0;
   genPar_pt = 0;
   TLgenPars = 0;
   genPar_idx = 0;
   genPar_mom1_idx = 0;
   genPar_mom2_idx = 0;
   genPar_dau1_idx = 0;
   genPar_dau2_idx = 0;
   TLgenJets = 0;
   genMet_px = 0;
   genMet_py = 0;
   genMet_pt = 0;
   genMet_px_py = 0;
   TLgenMET = 0;
   greedy_mu_flt = 0;
   incons_mu_pt_flt = 0;
   pfreco_mu_flt = 0;
   vtx_sumptsquare = 0;
   PV_Filter = 0;
   vtx_x = 0;
   vtx_y = 0;
   vtx_z = 0;
   vtx_x_error = 0;
   vtx_y_error = 0;
   vtx_z_error = 0;
   muons_pdgid = 0;
   muons_charge = 0;
   muons_isLoose = 0;
   muons_isSoft = 0;
   muons_isTight = 0;
   muons_isHighPt = 0;
   muons_relIso03 = 0;
   muons_relIso04 = 0;
   muons_PFIsodbeta03 = 0;
   muons_PFIsodbeta04 = 0;
   TLMuons = 0;
   jets_charge = 0;
   jets_pdgid = 0;
   jets_isJet = 0;
   PFJetId = 0;
   PuJetId = 0;
   jets_PuMva = 0;
   jets_bDisc = 0;
   TLJets = 0;
   TLMET = 0;
   elecs_pdgid = 0;
   elecs_charge = 0;
   elec_charId_gsfctfpx = 0;
   elec_charId_gsfctf = 0;
   elec_charId_gsfpx = 0;
   elecs_eidLoose = 0;
   elecs_eidRobustHighEnergy = 0;
   elecs_eidRobustLoose = 0;
   elecs_eidRobustTight = 0;
   elecs_eidTight = 0;
   elecs_gsfTrcharge = 0;
   elecs_ctfTrcharge = 0;
   elecs_scPixcharge = 0;
   elecs_relIso03 = 0;
   elecs_relIso04 = 0;
   elecs_PFIsodbeta03 = 0;
   elecs_PFIsodbeta04 = 0;
   elecs_PFIsoRho03 = 0;
   elecs_PFIsoRho04 = 0;
   elecs_mvaNonTrigV0 = 0;
   elecs_mvaTrigNoIPV0 = 0;
   elecs_mvaTrigV0 = 0;
   elecs_Nhit = 0;
   elecs_Conversion_1 = 0;
   elecs_Conversion_2 = 0;
   elecs_Conversion_3 = 0;
   TLElecs = 0;
   Gsfdxy = 0;
   Gsfdz = 0;
   Ctfdxy = 0;
   Ctfdz = 0;
   Supercluster_Eta = 0;
   PU_wgt = 0;
   TLPhotons = 0;
   photons_pidLoose = 0;
   photons_pidTight = 0;
   TriggerName = 0;
   TriggerPass = 0;
   TriggerError = 0;
   TriggerRun = 0;
   TriggerPreScale = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Event", &Event, &b_Event);
   fChain->SetBranchAddress("Run", &Run, &b_Run);
   fChain->SetBranchAddress("Lumi", &Lumi, &b_Lumi);
   fChain->SetBranchAddress("isData", &isData, &b_isData);
   fChain->SetBranchAddress("id1", &id1, &b_id1);
   fChain->SetBranchAddress("id2", &id2, &b_id2);
   fChain->SetBranchAddress("Bjorkenx1", &Bjorkenx1, &b_Bjorkenx1);
   fChain->SetBranchAddress("Bjorkenx2", &Bjorkenx2, &b_Bjorkenx2);
   fChain->SetBranchAddress("Q", &Q, &b_Q);
   fChain->SetBranchAddress("pdfweightUp", &pdfweightUp, &b_pdfweightUp);
   fChain->SetBranchAddress("pdfweightDown", &pdfweightDown, &b_pdfweightDown);
   fChain->SetBranchAddress("N_genPars", &N_genPars, &b_N_genPars);
   fChain->SetBranchAddress("genPar_pdgId", &genPar_pdgId, &b_genPar_pdgId);
   fChain->SetBranchAddress("genPar_status", &genPar_status, &b_genPar_status);
   fChain->SetBranchAddress("genPar_mom1pdgId", &genPar_mom1pdgId, &b_genPar_mom1pdgId);
   fChain->SetBranchAddress("genPar_mom2pdgId", &genPar_mom2pdgId, &b_genPar_mom2pdgId);
   fChain->SetBranchAddress("genPar_Nmother", &genPar_Nmother, &b_genPar_Nmother);
   fChain->SetBranchAddress("genPar_pt", &genPar_pt, &b_genPar_pt);
   fChain->SetBranchAddress("TLgenPars", &TLgenPars, &b_TLgenPars);
   fChain->SetBranchAddress("genPar_idx", &genPar_idx, &b_genPar_idx);
   fChain->SetBranchAddress("genPar_mom1_idx", &genPar_mom1_idx, &b_genPar_mom1_idx);
   fChain->SetBranchAddress("genPar_mom2_idx", &genPar_mom2_idx, &b_genPar_mom2_idx);
   fChain->SetBranchAddress("genPar_dau1_idx", &genPar_dau1_idx, &b_genPar_dau1_idx);
   fChain->SetBranchAddress("genPar_dau2_idx", &genPar_dau2_idx, &b_genPar_dau2_idx);
   fChain->SetBranchAddress("N_genJets", &N_genJets, &b_N_genJets);
   fChain->SetBranchAddress("TLgenJets", &TLgenJets, &b_TLgenJets);
   fChain->SetBranchAddress("N_genMet", &N_genMet, &b_N_genMet);
   fChain->SetBranchAddress("genMet_px", &genMet_px, &b_genMet_px);
   fChain->SetBranchAddress("genMet_py", &genMet_py, &b_genMet_py);
   fChain->SetBranchAddress("genMet_pt", &genMet_pt, &b_genMet_pt);
   fChain->SetBranchAddress("genMet_px_py", &genMet_px_py, &b_genMet_px_py);
   fChain->SetBranchAddress("TLgenMET", &TLgenMET, &b_TLgenMET);
   fChain->SetBranchAddress("greedy_mu_flt", &greedy_mu_flt, &b_greedy_mu_flt);
   fChain->SetBranchAddress("incons_mu_pt_flt", &incons_mu_pt_flt, &b_incons_mu_pt_flt);
   fChain->SetBranchAddress("pfreco_mu_flt", &pfreco_mu_flt, &b_pfreco_mu_flt);
   fChain->SetBranchAddress("NPV", &NPV, &b_NPV);
   fChain->SetBranchAddress("vtx_sumptsquare", &vtx_sumptsquare, &b_vtx_sumptsquare);
   fChain->SetBranchAddress("PV_Filter", &PV_Filter, &b_PV_Filter);
   fChain->SetBranchAddress("vtx_x", &vtx_x, &b_vtx_x);
   fChain->SetBranchAddress("vtx_y", &vtx_y, &b_vtx_y);
   fChain->SetBranchAddress("vtx_z", &vtx_z, &b_vtx_z);
   fChain->SetBranchAddress("vtx_x_error", &vtx_x_error, &b_vtx_x_error);
   fChain->SetBranchAddress("vtx_y_error", &vtx_y_error, &b_vtx_y_error);
   fChain->SetBranchAddress("vtx_z_error", &vtx_z_error, &b_vtx_z_error);
   fChain->SetBranchAddress("N_muons", &N_muons, &b_N_muons);
   fChain->SetBranchAddress("muons_pdgid", &muons_pdgid, &b_muons_pdgid);
   fChain->SetBranchAddress("muons_charge", &muons_charge, &b_muons_charge);
   fChain->SetBranchAddress("muons_isLoose", &muons_isLoose, &b_muons_isLoose);
   fChain->SetBranchAddress("muons_isSoft", &muons_isSoft, &b_muons_isSoft);
   fChain->SetBranchAddress("muons_isTight", &muons_isTight, &b_muons_isTight);
   fChain->SetBranchAddress("muons_isHighPt", &muons_isHighPt, &b_muons_isHighPt);
   fChain->SetBranchAddress("muons_relIso03", &muons_relIso03, &b_muons_relIso03);
   fChain->SetBranchAddress("muons_relIso04", &muons_relIso04, &b_muons_relIso04);
   fChain->SetBranchAddress("muons_PFIsodbeta03", &muons_PFIsodbeta03, &b_muons_PFIsodbeta03);
   fChain->SetBranchAddress("muons_PFIsodbeta04", &muons_PFIsodbeta04, &b_muons_PFIsodbeta04);
   fChain->SetBranchAddress("TLMuons", &TLMuons, &b_TLMuons);
   fChain->SetBranchAddress("NJets", &NJets, &b_NJets);
   fChain->SetBranchAddress("jets_charge", &jets_charge, &b_jets_charge);
   fChain->SetBranchAddress("jets_pdgid", &jets_pdgid, &b_jets_pdgid);
   fChain->SetBranchAddress("jets_isJet", &jets_isJet, &b_jets_isJet);
   fChain->SetBranchAddress("PFJetId", &PFJetId, &b_PFJetId);
   fChain->SetBranchAddress("PuJetId", &PuJetId, &b_PuJetId);
   fChain->SetBranchAddress("jets_PuMva", &jets_PuMva, &b_jets_PuMva);
   fChain->SetBranchAddress("jets_bDisc", &jets_bDisc, &b_jets_bDisc);
   fChain->SetBranchAddress("TLJets", &TLJets, &b_TLJets);
   fChain->SetBranchAddress("N_Met", &N_Met, &b_N_Met);
   fChain->SetBranchAddress("TLMET", &TLMET, &b_TLMET);
   fChain->SetBranchAddress("Neles", &Neles, &b_Neles);
   fChain->SetBranchAddress("elecs_pdgid", &elecs_pdgid, &b_elecs_pdgid);
   fChain->SetBranchAddress("elecs_charge", &elecs_charge, &b_elecs_charge);
   fChain->SetBranchAddress("elec_charId_gsfctfpx", &elec_charId_gsfctfpx, &b_elec_charId_gsfctfpx);
   fChain->SetBranchAddress("elec_charId_gsfctf", &elec_charId_gsfctf, &b_elec_charId_gsfctf);
   fChain->SetBranchAddress("elec_charId_gsfpx", &elec_charId_gsfpx, &b_elec_charId_gsfpx);
   fChain->SetBranchAddress("elecs_eidLoose", &elecs_eidLoose, &b_elecs_eidLoose);
   fChain->SetBranchAddress("elecs_eidRobustHighEnergy", &elecs_eidRobustHighEnergy, &b_elecs_eidRobustHighEnergy);
   fChain->SetBranchAddress("elecs_eidRobustLoose", &elecs_eidRobustLoose, &b_elecs_eidRobustLoose);
   fChain->SetBranchAddress("elecs_eidRobustTight", &elecs_eidRobustTight, &b_elecs_eidRobustTight);
   fChain->SetBranchAddress("elecs_eidTight", &elecs_eidTight, &b_elecs_eidTight);
   fChain->SetBranchAddress("elecs_gsfTrcharge", &elecs_gsfTrcharge, &b_elecs_gsfTrcharge);
   fChain->SetBranchAddress("elecs_ctfTrcharge", &elecs_ctfTrcharge, &b_elecs_ctfTrcharge);
   fChain->SetBranchAddress("elecs_scPixcharge", &elecs_scPixcharge, &b_elecs_scPixcharge);
   fChain->SetBranchAddress("elecs_relIso03", &elecs_relIso03, &b_elecs_relIso03);
   fChain->SetBranchAddress("elecs_relIso04", &elecs_relIso04, &b_elecs_relIso04);
   fChain->SetBranchAddress("elecs_PFIsodbeta03", &elecs_PFIsodbeta03, &b_elecs_PFIsodbeta03);
   fChain->SetBranchAddress("elecs_PFIsodbeta04", &elecs_PFIsodbeta04, &b_elecs_PFIsodbeta04);
   fChain->SetBranchAddress("elecs_PFIsoRho03", &elecs_PFIsoRho03, &b_elecs_PFIsoRho03);
   fChain->SetBranchAddress("elecs_PFIsoRho04", &elecs_PFIsoRho04, &b_elecs_PFIsoRho04);
   fChain->SetBranchAddress("elecs_mvaNonTrigV0", &elecs_mvaNonTrigV0, &b_elecs_mvaNonTrigV0);
   fChain->SetBranchAddress("elecs_mvaTrigNoIPV0", &elecs_mvaTrigNoIPV0, &b_elecs_mvaTrigNoIPV0);
   fChain->SetBranchAddress("elecs_mvaTrigV0", &elecs_mvaTrigV0, &b_elecs_mvaTrigV0);
   fChain->SetBranchAddress("elecs_Nhit", &elecs_Nhit, &b_elecs_Nhit);
   fChain->SetBranchAddress("elecs_Conversion_1", &elecs_Conversion_1, &b_elecs_Conversion_1);
   fChain->SetBranchAddress("elecs_Conversion_2", &elecs_Conversion_2, &b_elecs_Conversion_2);
   fChain->SetBranchAddress("elecs_Conversion_3", &elecs_Conversion_3, &b_elecs_Conversion_3);
   fChain->SetBranchAddress("TLElecs", &TLElecs, &b_TLElecs);
   fChain->SetBranchAddress("Gsfdxy", &Gsfdxy, &b_Gsfdxy);
   fChain->SetBranchAddress("Gsfdz", &Gsfdz, &b_Gsfdz);
   fChain->SetBranchAddress("Ctfdxy", &Ctfdxy, &b_Ctfdxy);
   fChain->SetBranchAddress("Ctfdz", &Ctfdz, &b_Ctfdz);
   fChain->SetBranchAddress("Supercluster_Eta", &Supercluster_Eta, &b_Supercluster_Eta);
   fChain->SetBranchAddress("NPU", &NPU, &b_NPU);
   fChain->SetBranchAddress("NPUin", &NPUin, &b_NPUin);
   fChain->SetBranchAddress("PU_wgt", &PU_wgt, &b_PU_wgt);
   fChain->SetBranchAddress("Nphos", &Nphos, &b_Nphos);
   fChain->SetBranchAddress("TLPhotons", &TLPhotons, &b_TLPhotons);
   fChain->SetBranchAddress("photons_pidLoose", &photons_pidLoose, &b_photons_pidLoose);
   fChain->SetBranchAddress("photons_pidTight", &photons_pidTight, &b_photons_pidTight);
   fChain->SetBranchAddress("TriggerName", &TriggerName, &b_TriggerName);
   fChain->SetBranchAddress("TriggerPass", &TriggerPass, &b_TriggerPass);
   fChain->SetBranchAddress("TriggerError", &TriggerError, &b_TriggerError);
   fChain->SetBranchAddress("TriggerRun", &TriggerRun, &b_TriggerRun);
   fChain->SetBranchAddress("TriggerPreScale", &TriggerPreScale, &b_TriggerPreScale);
   Notify();
}

Bool_t SSBTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void SSBTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t SSBTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef SSBTree_cxx
