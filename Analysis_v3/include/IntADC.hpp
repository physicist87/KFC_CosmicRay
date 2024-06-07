#ifndef _IntADC_

#define _IntADC_
  
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

class IntADC : public DRCTree 
{
   public:
      //declare functions
      IntADC(TTree *tree=0);
      virtual ~IntADC();

      //basic frame
      virtual void Loop();
      void Start();
      void End();

      //user define functions
      //void SetChannels(vector<int> v_chs);
      void SetChannels(string confName);
      //void SetOutputFileName(char *outname);
      void SetOutputFileName(string outname);
      void DeclareHistos();
      void DeclareOptHistos();
      //void DeclareOptHistos(TH1D* h_tmp,TString hName, TString hTitle, int NumBins, double xlow_, double xup_);
      void DeclareOptHistos(int idx,TString hName, TString hTitle, int NumBins, double xlow_, double xup_);
      //void DeclareOptHistos(TH1D* h_tmp,TString hName, TString hTitle, int NumBins, double xlow_, double xup_);
      TH1D* DeclareOptHistos(TString hName, TString hTitle, int NumBins, double xlow_, double xup_);
      TH1D* DeclareOptHistos(TString hName, TString hTitle, vector<double> v_entries);
      void SelectedWaveFormHistos(TString hName, TString hTitle, vector<int>* v_entries);
      void GetVariables();
      
   private:
      //put variables that you want
      string outfile;
      string outfile_sel;
      TFile *fout;
      TFile *fout_sel;

      // Declare user variables
      vector<int> v_chs;
      vector<int> v_lb;
      vector<int> v_rb;
      vector<int> v_re;
      vector<int> v_width;
      map<int, vector<int>* > m_ch_adcs;
      map<int, vector<double> > m_ch_intADC;
      map<int, vector<double> > m_ch_peakADC;

   public:
      //declare histograms

      TH1D *_h_ADC_ped;
      TH1D *_h_peak;
      TH2D* h_Min_vs_ADC[32];
      TH2D* h_Min_vs_SubPedADC[32];
      TH1D* h_IntADC_FixedRange[32];
      TH1D* h_PeakADC_FixedRange[32];
      TH1D* h_PeakADC_Only[32];
      TH1D* h_IntADC_FixedRange_NonNorm[32];
      TH1D* h_PeakADC_FixedRange_NonNorm[32];
      TH1D* h_PeakADC_Only_NonNorm[32];
      TH1D* h_IntADC[32];
      TH1D* h_PedADC[32];
      TH1D* h_PedADC_Sel[32];
      TH1D* h_PeakADC[32];
};

#endif

#ifdef IntADC_cxx

IntADC::IntADC(TTree *tree)
{
   if (tree == 0)
   {
      printf("ERROR: Can't find any input tree.\n");
   }
   Init(tree);
}

IntADC::~IntADC()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

#endif
   

