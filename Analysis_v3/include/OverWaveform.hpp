#ifndef _OverWaveform_

#define _OverWaveform_
  
#include <set>
#include <string>
#include <cassert>
#include <map>
#include <vector>
#include <string>
#include <TH1.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TH3F.h>
#include <TGraphErrors.h>
#include "TLorentzVector.h"
  
#include "../analysis/DRCTree.h"

using namespace std;

class OverWaveform : public DRCTree 
{
   public:
      //declare functions
      OverWaveform(TTree *tree=0);
      virtual ~OverWaveform();

      //basic frame
      virtual void Loop();
      void Start();
      void End();

      //user define functions
      //void SetChannels(vector<int> v_chs);
      void SetChannels(string confName);
      void SetOutputFileName(string outname);
      void DeclareHistos();
      void GetVariables();
      
   private:
      //put variables that you want
      string outfile;
      TFile *fout;

      // Declare user variables
      vector<int> v_chs;
      map<int, vector<int>* > m_ch_adcs;

   public:
      //declare histograms

      TH1D *_h_ADC_ped;
      TH1D *_h_peak;
      TH2D* h_OverlayWaveform[32];
};

#endif

#ifdef OverWaveform_cxx

OverWaveform::OverWaveform(TTree *tree)
{
   if (tree == 0)
   {
      printf("ERROR: Can't find any input tree.\n");
   }
   Init(tree);
}

OverWaveform::~OverWaveform()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

#endif
   

