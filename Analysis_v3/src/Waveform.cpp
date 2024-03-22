#define Waveform_cxx

#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#include "TMath.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TPaveStats.h"

#include "../include/Waveform.hpp"
#include "../CommonTools.hpp"

using namespace std;

void Waveform::Loop()
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
   TString outputDir = "output/Set1/";

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
      /// ///
      DeclareHistos(num_evt);
 /*     for (int i =0; i < Ch2_ADC->size(); ++i)
      {
         for(int ich = 0; ich < 32; ich++){
         //h_new->Fill(i+1, Ch2_ADC->at(i));
            h_WaveForm[ich]->Fill(i+1, m_ch_adcs[ich]->at(i));
         }
      }
*/
      for(vector<int>::iterator ich = v_chs.begin(); ich != v_chs.end(); ich++){
         for (int ibin = 0; ibin < m_ch_adcs[*ich]->size(); ibin++){
            h_WaveForm[*ich]->Fill(ibin+1, m_ch_adcs[*ich]->at(ibin));
         }
      }
      SaveHistos(num_evt);
      /// close previous files ///
      num_evt++;
   }//event loop

   printf("Total processed number of events: %lld\n", __tot_evt);
    
}//end Loop function

void Waveform::SetChannels(string confName)
{
   if (confName == "none" || confName == ""){
     for(int i = 0; i < 32; ++i){
        v_chs.push_back(i);
     } 
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
   return;



}
void Waveform::Start()
{
   cout << "start Waveform ! " << endl;
}

void Waveform::DeclareHistos(int ievt)
{
   //for(int i = 0; i < 32; ++i){
   for(vector<int>::iterator ich = v_chs.begin(); ich != v_chs.end(); ich++){
      c_W[*ich] = new TCanvas(Form("c1_%d_ch%d",ievt,*ich), Form("cavas_%d_ch%d",*ich,ievt),1200,900);
      c_W[*ich]->cd(); 
      h_WaveForm[*ich]  = new TH1D(Form("_h_WaveForm_Evt%d_Ch%d",ievt,*ich), Form("Avg. time structure Ch%d",*ich), 1023, 0, 1023); h_WaveForm[*ich]->Sumw2(); h_WaveForm[*ich]->SetOption("hist");

   }
}
void Waveform::SaveHistos(int ievt)
{
   //for(int i = 0; i < 32; ++i){
   gSystem->mkdir(Form("./waveformDir/"));
   gSystem->mkdir(Form("./waveformDir/%s/",outfile.c_str()));
   for(vector<int>::iterator ich = v_chs.begin(); ich != v_chs.end(); ich++){
     cout << " !!! : !!! "  << Form("waveformDir/%s/waveform_evt%d_ch%d.pdf",outfile.c_str(),ievt,*ich) << endl;
     c_W[*ich]->cd();
     h_WaveForm[*ich]->SetMaximum(4300);
     h_WaveForm[*ich]->Draw("Hist");
     gPad->Update();
     TPaveStats *st = (TPaveStats*)h_WaveForm[*ich]->FindObject("stats");
     st->SetY1NDC(0.2); //new x start position
     st->SetY2NDC(0.4); //new x end position
     c_W[*ich]->SaveAs(Form("waveformDir/%s/waveform_evt%d_ch%d.pdf",outfile.c_str(),ievt,*ich)); 
   }
}
void Waveform::End()
{
   cout << "End Waveform ! " << endl;
//   fout->Write();
//   fout->Close();
}

void Waveform::SetOutputFileName(string outname)
{   
   outfile = outname;
}

void Waveform::GetVariables()
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


