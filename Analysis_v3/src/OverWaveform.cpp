#define OverWaveform_cxx

#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#include "TMath.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"

#include "../include/OverWaveform.hpp"
#include "../CommonTools.hpp"

using namespace std;

void OverWaveform::Loop()
{
   //////////
   if (fChain == 0) return;
   //////////

   //////////
   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   //////////

   ///My variables
   Long64_t __tot_evt = 0;

   ////////////////////////
   /// start event loop ///
   ////////////////////////
   int num_evt = 0; 
   //TH1F* h_new  = new TH1F(Form("_h_OverWaveform_Ch2"), Form("Avg. time structure Ch2"), 1023, 0, 1023);
   //TH1D* h_new  = new TH1D(Form("_h_OverWaveform_Ch2"), Form("Avg. time structure Ch2"), 1023, 0, 1023);
   //h_new->Sumw2();
   //h_new->SetOption("hist");
   cout << "nentries?  : " << nentries << endl;

   for (Long64_t jentry=0; jentry<nentries;jentry++) 
   {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0)
      {
         printf("ERROR: Could not load tree!!!\n");
         break;
      }

      nb = fChain->GetEntry(jentry);   nbytes += nb;
       
      if (jentry % 10000 == 0) printf("Event %lld\n", jentry); //%lld supports Long64_t

      __tot_evt++;
      GetVariables();
      //cout << "Ch2_ADC->size: " << Ch2_ADC->size() << endl;
      //cout << " Times " << (Times/pow(10,9))/3600 << endl;
       
      for (int i =0; i < Ch2_ADC->size(); ++i)
      {
         for(int ich = 0; ich < 32; ich++){
         //h_new->Fill(i+1, Ch2_ADC->at(i));
            //h_OverlayWaveform[ich]
            FillHisto(h_OverlayWaveform[ich],i+1, m_ch_adcs[ich]->at(i));
         }
      }
      num_evt++;
   }//event loop

   printf("Total processed number of events: %lld\n", __tot_evt);
    
}//end Loop function

/*void OverWaveform::SetChannels(vector<int> v_chs)
{


}*/
void OverWaveform::SetChannels(string confName)
{
   cout << "SetChannels : " << confName << endl;

   if (confName == "none"){
     for(int i = 0; i < 32; ++i){ v_chs.push_back(i);} 
   }
   else {
      // Load Channel List file //
      FILE* chlist; 
      string chlistDir, chlistName, chlistPath;
      chlistDir = "./config/";
      chlistName = confName;
      chlistPath = chlistDir + chlistName;
      cout << "chlistPath: " << chlistPath << endl;
      chlist = fopen(chlistPath.c_str(),"r");
      int chs_;
      int riseEdge_=-1;
      int Width_=-1;
      int leftbin_=-1;
      int rightbin_ =-1;
      if (chlist != NULL){
      //   cout << "cococo " << endl;
         while (fscanf(chlist, "%d %d %d %d %d\n", &chs_, &leftbin_, &rightbin_, &riseEdge_, &Width_) != EOF){
            cout << "ch "<< chs_ << " leftbin_ : " << leftbin_ << " rightbin_ : " << rightbin_ << " riseEdge_ : " << riseEdge_ << " Width_ : " << Width_<<endl;
            v_chs.push_back(chs_-1);
         }
      }
      else {
         cout << "check out !!" << chlistPath << endl; return;
      }
      fclose(chlist);
   }
   for(vector<int>::iterator it = v_chs.begin(); it != v_chs.end(); it++)
   {
      cout << "it " << *it << endl;
   }

   return;
}
void OverWaveform::Start()
{
   cout << "sk start function " << endl;
   gSystem->mkdir(Form("./overwaveformDir"));
   fout = new TFile(Form("overwaveformDir/%s",outfile.c_str()),"RECREATE");
   fout->cd("");

   TDirectory *dir = gDirectory;
   dir->cd();

   DeclareHistos();
}

void OverWaveform::DeclareHistos()
{
//   _h_ADC_ped = new TH1D(Form("_h_Ch2_ADC_ped"), Form("mean of 100 bin"), 100000, 0, 10000);
//   _h_peak = new TH1D(Form("_h_peak"), Form(""), 100000, 0, 10000);
   for(int i = 0; i < 32; ++i){ 
      h_OverlayWaveform[i]  = new TH2D(Form("_h_OverWaveform_Ch%d",i), Form("Overlay Waveform Ch%d",i), 1023, 0, 1023, 4500,0,4500); h_OverlayWaveform[i]->Sumw2(); //h_OverlayWaveform[i]->SetOption("hist");

   }
}

void OverWaveform::End()
{
   fout->Write();
   fout->Close();
}

void OverWaveform::SetOutputFileName(string outname)
{   
   outfile = outname;
}

void OverWaveform::GetVariables()
{
   m_ch_adcs.clear();
   m_ch_adcs[0]=Ch0_ADC; 
   m_ch_adcs[1]=Ch1_ADC; 
   m_ch_adcs[2]=Ch2_ADC; 
   m_ch_adcs[3]=Ch3_ADC; 
   m_ch_adcs[4]=Ch4_ADC; 
   m_ch_adcs[5]=Ch5_ADC; 
   m_ch_adcs[6]=Ch6_ADC; 
   m_ch_adcs[7]=Ch7_ADC; 
   m_ch_adcs[8]=Ch8_ADC; 
   m_ch_adcs[9]=Ch9_ADC; 

   m_ch_adcs[10]=Ch10_ADC; 
   m_ch_adcs[11]=Ch11_ADC; 
   m_ch_adcs[12]=Ch12_ADC; 
   m_ch_adcs[13]=Ch13_ADC; 
   m_ch_adcs[14]=Ch14_ADC; 
   m_ch_adcs[15]=Ch15_ADC; 
   m_ch_adcs[16]=Ch16_ADC; 
   m_ch_adcs[17]=Ch17_ADC; 
   m_ch_adcs[18]=Ch18_ADC; 
   m_ch_adcs[19]=Ch19_ADC; 

   m_ch_adcs[20]=Ch20_ADC; 
   m_ch_adcs[21]=Ch21_ADC; 
   m_ch_adcs[22]=Ch22_ADC; 
   m_ch_adcs[23]=Ch23_ADC; 
   m_ch_adcs[24]=Ch24_ADC; 
   m_ch_adcs[25]=Ch25_ADC; 
   m_ch_adcs[26]=Ch26_ADC; 
   m_ch_adcs[27]=Ch27_ADC; 
   m_ch_adcs[28]=Ch28_ADC; 
   m_ch_adcs[29]=Ch29_ADC; 

   m_ch_adcs[30]=Ch30_ADC; 
   m_ch_adcs[31]=Ch31_ADC; 
}


