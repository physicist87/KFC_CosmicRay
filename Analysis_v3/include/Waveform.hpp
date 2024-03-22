#ifndef _Waveform_

#define _Waveform_
  
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

class Waveform : public DRCTree 
{
   public:
      //declare functions
      Waveform(TTree *tree=0);
      virtual ~Waveform();

      //basic frame
      virtual void Loop();
      void Start();
      void End();

      //user define functions
      //void SetChannels(vector<int> v_chs);
      void SetChannels(string confName);
      //void SetOutputFileName(char *outname);
      void SetOutputFileName(string outname);
      void DeclareHistos(int ievt);
      void SaveHistos(int ievt);
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
      TCanvas* c_W[32];
      TH1D* h_WaveForm[32];
};

#endif

#ifdef Waveform_cxx

Waveform::Waveform(TTree *tree)
{
   if (tree == 0)
   {
      printf("ERROR: Can't find any input tree.\n");
   }
   Init(tree);
}

Waveform::~Waveform()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

#endif
   

