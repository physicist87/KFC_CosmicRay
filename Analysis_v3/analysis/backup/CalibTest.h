//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Nov  1 18:26:42 2022 by ROOT version 5.34/36
// from TTree Ch_10/a simple Tree with simple variables
// found on file: output_Run900_10.root
//////////////////////////////////////////////////////////

#ifndef CalibTest_h
#define CalibTest_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

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

class CalibTest {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Double_t        EvtNum;
   vector<short>   *ADC;

   // List of branches
   TBranch        *b_evt;   //!
   TBranch        *b_ADC;   //!

   CalibTest(TTree *tree=0);
   virtual ~CalibTest();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef CalibTest_cxx
CalibTest::CalibTest(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
/*   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("output_Run900_10.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("output_Run900_10.root");
      }
      f->GetObject("Ch_10",tree);

   }*/
   Init(tree);
}

CalibTest::~CalibTest()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t CalibTest::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t CalibTest::LoadTree(Long64_t entry)
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

void CalibTest::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   ADC = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("EvtNum", &EvtNum, &b_evt);
   fChain->SetBranchAddress("ADC", &ADC, &b_ADC);
   Notify();
}

Bool_t CalibTest::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void CalibTest::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t CalibTest::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef CalibTest_cxx
