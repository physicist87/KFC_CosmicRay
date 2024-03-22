//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Mar 22 01:32:50 2024 by ROOT version 6.26/04
// from TTree DRCNtuple/DRC Ntuple tree (only one MID)
// found on file: /storage/palgongsan/sha/Analysis/KFC_DREAM/Cosmiclay/Analysis/Ntuples/v2p3/v2_CosmicTest_Ntuple_Run105_MID7.root
//////////////////////////////////////////////////////////

#ifndef DRCTree_h
#define DRCTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
using namespace std;

class DRCTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxtimes = 1;
   static constexpr Int_t kMaxtimeV = 1;

   // Declaration of leaf types
   Int_t           EvtNum;
   Long64_t        Times;
   Int_t           TimeV;
   vector<int>     *Ch0_ADC;
   vector<int>     *Ch1_ADC;
   vector<int>     *Ch2_ADC;
   vector<int>     *Ch3_ADC;
   vector<int>     *Ch4_ADC;
   vector<int>     *Ch5_ADC;
   vector<int>     *Ch6_ADC;
   vector<int>     *Ch7_ADC;
   vector<int>     *Ch8_ADC;
   vector<int>     *Ch9_ADC;
   vector<int>     *Ch10_ADC;
   vector<int>     *Ch11_ADC;
   vector<int>     *Ch12_ADC;
   vector<int>     *Ch13_ADC;
   vector<int>     *Ch14_ADC;
   vector<int>     *Ch15_ADC;
   vector<int>     *Ch16_ADC;
   vector<int>     *Ch17_ADC;
   vector<int>     *Ch18_ADC;
   vector<int>     *Ch19_ADC;
   vector<int>     *Ch20_ADC;
   vector<int>     *Ch21_ADC;
   vector<int>     *Ch22_ADC;
   vector<int>     *Ch23_ADC;
   vector<int>     *Ch24_ADC;
   vector<int>     *Ch25_ADC;
   vector<int>     *Ch26_ADC;
   vector<int>     *Ch27_ADC;
   vector<int>     *Ch28_ADC;
   vector<int>     *Ch29_ADC;
   vector<int>     *Ch30_ADC;
   vector<int>     *Ch31_ADC;

   // List of branches
   TBranch        *b_evtNum;   //!
   TBranch        *b_times_;   //!
   TBranch        *b_timeV_;   //!
   TBranch        *b_Ch0_ADC;   //!
   TBranch        *b_Ch1_ADC;   //!
   TBranch        *b_Ch2_ADC;   //!
   TBranch        *b_Ch3_ADC;   //!
   TBranch        *b_Ch4_ADC;   //!
   TBranch        *b_Ch5_ADC;   //!
   TBranch        *b_Ch6_ADC;   //!
   TBranch        *b_Ch7_ADC;   //!
   TBranch        *b_Ch8_ADC;   //!
   TBranch        *b_Ch9_ADC;   //!
   TBranch        *b_Ch10_ADC;   //!
   TBranch        *b_Ch11_ADC;   //!
   TBranch        *b_Ch12_ADC;   //!
   TBranch        *b_Ch13_ADC;   //!
   TBranch        *b_Ch14_ADC;   //!
   TBranch        *b_Ch15_ADC;   //!
   TBranch        *b_Ch16_ADC;   //!
   TBranch        *b_Ch17_ADC;   //!
   TBranch        *b_Ch18_ADC;   //!
   TBranch        *b_Ch19_ADC;   //!
   TBranch        *b_Ch20_ADC;   //!
   TBranch        *b_Ch21_ADC;   //!
   TBranch        *b_Ch22_ADC;   //!
   TBranch        *b_Ch23_ADC;   //!
   TBranch        *b_Ch24_ADC;   //!
   TBranch        *b_Ch25_ADC;   //!
   TBranch        *b_Ch26_ADC;   //!
   TBranch        *b_Ch27_ADC;   //!
   TBranch        *b_Ch28_ADC;   //!
   TBranch        *b_Ch29_ADC;   //!
   TBranch        *b_Ch30_ADC;   //!
   TBranch        *b_Ch31_ADC;   //!

   DRCTree(TTree *tree=0);
   virtual ~DRCTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef DRCTree_cxx
DRCTree::DRCTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
/*
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/storage/palgongsan/sha/Analysis/KFC_DREAM/Cosmiclay/Analysis/Ntuples/v2p3/v2_CosmicTest_Ntuple_Run105_MID7.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/storage/palgongsan/sha/Analysis/KFC_DREAM/Cosmiclay/Analysis/Ntuples/v2p3/v2_CosmicTest_Ntuple_Run105_MID7.root");
      }
      f->GetObject("DRCNtuple",tree);
*/
   }
   Init(tree);
}

DRCTree::~DRCTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t DRCTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t DRCTree::LoadTree(Long64_t entry)
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

void DRCTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   Ch0_ADC = 0;
   Ch1_ADC = 0;
   Ch2_ADC = 0;
   Ch3_ADC = 0;
   Ch4_ADC = 0;
   Ch5_ADC = 0;
   Ch6_ADC = 0;
   Ch7_ADC = 0;
   Ch8_ADC = 0;
   Ch9_ADC = 0;
   Ch10_ADC = 0;
   Ch11_ADC = 0;
   Ch12_ADC = 0;
   Ch13_ADC = 0;
   Ch14_ADC = 0;
   Ch15_ADC = 0;
   Ch16_ADC = 0;
   Ch17_ADC = 0;
   Ch18_ADC = 0;
   Ch19_ADC = 0;
   Ch20_ADC = 0;
   Ch21_ADC = 0;
   Ch22_ADC = 0;
   Ch23_ADC = 0;
   Ch24_ADC = 0;
   Ch25_ADC = 0;
   Ch26_ADC = 0;
   Ch27_ADC = 0;
   Ch28_ADC = 0;
   Ch29_ADC = 0;
   Ch30_ADC = 0;
   Ch31_ADC = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("EvtNum", &EvtNum, &b_evtNum);
   fChain->SetBranchAddress("Times", &Times, &b_times_);
   fChain->SetBranchAddress("TimeV", &TimeV, &b_timeV_);
   fChain->SetBranchAddress("Ch0_ADC", &Ch0_ADC, &b_Ch0_ADC);
   fChain->SetBranchAddress("Ch1_ADC", &Ch1_ADC, &b_Ch1_ADC);
   fChain->SetBranchAddress("Ch2_ADC", &Ch2_ADC, &b_Ch2_ADC);
   fChain->SetBranchAddress("Ch3_ADC", &Ch3_ADC, &b_Ch3_ADC);
   fChain->SetBranchAddress("Ch4_ADC", &Ch4_ADC, &b_Ch4_ADC);
   fChain->SetBranchAddress("Ch5_ADC", &Ch5_ADC, &b_Ch5_ADC);
   fChain->SetBranchAddress("Ch6_ADC", &Ch6_ADC, &b_Ch6_ADC);
   fChain->SetBranchAddress("Ch7_ADC", &Ch7_ADC, &b_Ch7_ADC);
   fChain->SetBranchAddress("Ch8_ADC", &Ch8_ADC, &b_Ch8_ADC);
   fChain->SetBranchAddress("Ch9_ADC", &Ch9_ADC, &b_Ch9_ADC);
   fChain->SetBranchAddress("Ch10_ADC", &Ch10_ADC, &b_Ch10_ADC);
   fChain->SetBranchAddress("Ch11_ADC", &Ch11_ADC, &b_Ch11_ADC);
   fChain->SetBranchAddress("Ch12_ADC", &Ch12_ADC, &b_Ch12_ADC);
   fChain->SetBranchAddress("Ch13_ADC", &Ch13_ADC, &b_Ch13_ADC);
   fChain->SetBranchAddress("Ch14_ADC", &Ch14_ADC, &b_Ch14_ADC);
   fChain->SetBranchAddress("Ch15_ADC", &Ch15_ADC, &b_Ch15_ADC);
   fChain->SetBranchAddress("Ch16_ADC", &Ch16_ADC, &b_Ch16_ADC);
   fChain->SetBranchAddress("Ch17_ADC", &Ch17_ADC, &b_Ch17_ADC);
   fChain->SetBranchAddress("Ch18_ADC", &Ch18_ADC, &b_Ch18_ADC);
   fChain->SetBranchAddress("Ch19_ADC", &Ch19_ADC, &b_Ch19_ADC);
   fChain->SetBranchAddress("Ch20_ADC", &Ch20_ADC, &b_Ch20_ADC);
   fChain->SetBranchAddress("Ch21_ADC", &Ch21_ADC, &b_Ch21_ADC);
   fChain->SetBranchAddress("Ch22_ADC", &Ch22_ADC, &b_Ch22_ADC);
   fChain->SetBranchAddress("Ch23_ADC", &Ch23_ADC, &b_Ch23_ADC);
   fChain->SetBranchAddress("Ch24_ADC", &Ch24_ADC, &b_Ch24_ADC);
   fChain->SetBranchAddress("Ch25_ADC", &Ch25_ADC, &b_Ch25_ADC);
   fChain->SetBranchAddress("Ch26_ADC", &Ch26_ADC, &b_Ch26_ADC);
   fChain->SetBranchAddress("Ch27_ADC", &Ch27_ADC, &b_Ch27_ADC);
   fChain->SetBranchAddress("Ch28_ADC", &Ch28_ADC, &b_Ch28_ADC);
   fChain->SetBranchAddress("Ch29_ADC", &Ch29_ADC, &b_Ch29_ADC);
   fChain->SetBranchAddress("Ch30_ADC", &Ch30_ADC, &b_Ch30_ADC);
   fChain->SetBranchAddress("Ch31_ADC", &Ch31_ADC, &b_Ch31_ADC);
   Notify();
}

Bool_t DRCTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void DRCTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t DRCTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef DRCTree_cxx
