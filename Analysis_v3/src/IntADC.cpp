#define IntADC_cxx

#include <iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

#include <numeric>
#include <string>
#include <functional>

#include "TMath.h"
#include "TH2.h"
#include "TStyle.h"
#include "TCanvas.h"

#include "../include/IntADC.hpp"
#include "../CommonTools.hpp"

using namespace std;

void IntADC::Loop()
{
   //////////
   if (fChain == 0) return;
   //////////
   cout << "start Loop " << endl; 

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
   TH1D* h_new;
   vector<double> v_test;
   v_test.clear();
   Long64_t finTime = -999;

   m_ch_intADC.clear();
   m_ch_peakADC.clear(); 
   for(vector<int>::iterator ich = v_chs.begin(); ich != v_chs.end(); ich++){
      vector<double> v_intADCtmp;
      vector<double> v_peakADCtmp;
      m_ch_intADC[*ich] = v_intADCtmp;
      m_ch_peakADC[*ich] = v_peakADCtmp;
   }

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
       
      ///Run  5665, Mid 7, Ch 27, RE 80, Range 160,1 // 
      int RE = -999;
      int Interval = -999;  
      int min_idx = -999;  
      float intADC = -999;
      float intpedADC = -999;
      float peakADC = -999;
      for(vector<int>::iterator ich = v_chs.begin(); ich != v_chs.end(); ich++){
         int index = distance(v_chs.begin(), ich);
         int LeftBin = v_lb.at(index);
         int RightBin = v_rb.at(index);
         RE = v_re.at(index);
         Interval = v_width.at(index);
         //cout << *ich << "" <<" RE " << RE << " Interval : " << Interval << endl;
         min_idx = std::min_element(m_ch_adcs[*ich]->begin()+LeftBin, m_ch_adcs[*ich]->begin()+RightBin) - m_ch_adcs[*ich]->begin();
         h_Min_vs_ADC[*ich]->Fill(min_idx,m_ch_adcs[*ich]->at(min_idx));
         peakADC = m_ch_adcs[*ich]->at(min_idx);
         int min_re = min_idx - RE;
         //cout << "min_re : " << min_re << endl;
         intADC = std::accumulate(m_ch_adcs[*ich]->begin() + min_re, m_ch_adcs[*ich]->begin() + min_re + Interval, 0.0);
         float ped_ =0;
         for (int iadc =1; iadc < 101; iadc++){
            ped_ +=m_ch_adcs[*ich]->at(iadc);
         }
         //cout << "ped values : " << ped_/100 << endl;
         double ped_avg = ped_/100;
         h_Min_vs_SubPedADC[*ich]->Fill(min_idx,ped_avg-m_ch_adcs[*ich]->at(min_idx));
         h_PedADC[*ich]->Fill(ped_avg);
         intpedADC = (ped_avg)*Interval;
         //cout << "intADC :" << intADC << " intpedADC : " << intpedADC  << endl;
         h_IntADC_FixedRange[*ich]->Fill(intpedADC-intADC);
         h_PeakADC_FixedRange[*ich]->Fill(ped_avg-peakADC);
         m_ch_intADC[*ich].push_back(intpedADC-intADC);
         m_ch_peakADC[*ich].push_back(ped_avg-peakADC);
      }

      num_evt++;
      if (jentry == nentries-1){finTime = Times;}
   }//event loop

   for(vector<int>::iterator ich = v_chs.begin(); ich != v_chs.end(); ich++){
      double min_;
      int nBins_;
      double max_;
      int min_idx_ = std::min_element(m_ch_intADC[*ich].begin(), m_ch_intADC[*ich].end())-m_ch_intADC[*ich].begin();
      min_ = m_ch_intADC[*ich].at(min_idx_);
      min_ = floor(min_)-100;
      int max_idx_ = std::max_element(m_ch_intADC[*ich].begin(), m_ch_intADC[*ich].end())-m_ch_intADC[*ich].begin();
      max_ = m_ch_intADC[*ich].at(max_idx_);
      max_ = ceil(max_)+100;
      //cout << "min_ " << min_ << " max_ " << max_ << endl;
      //DeclareOptHistos(h_IntADC[*ich], Form("h_IntADC_Ch%d",*ich), Form("Int. ADC Ch %d",*ich), abs(min_)+abs(max_), min_, max_);
      //DeclareOptHistos(*ich, Form("h_IntADC_Ch%d",*ich), Form("Int. ADC Ch %d",*ich), abs(min_)+abs(max_), min_, max_);
      //DeclareOptHistos(h_IntADC[*ich], Form("h_IntADC_Ch%d",*ich), Form("Int. ADC Ch %d",*ich), abs(min_)+abs(max_), min_, max_);
      //struct histInfo hinfotmp;
      //hinfotmp = 
      //h_PeakADC[*ich] = DeclareOptHistos(Form("h_PeakADC_Ch%d",*ich), Form("Peak ADC Ch %d",*ich), abs(min_)+abs(max_), min_, max_);
      h_IntADC[*ich] = DeclareOptHistos(Form("h_IntADC_Ch%d",*ich), Form("Int. ADC Ch %d",*ich), m_ch_intADC[*ich]);
      h_PeakADC[*ich] = DeclareOptHistos(Form("h_PeakADC_Ch%d",*ich), Form("Peak ADC Ch %d",*ich), m_ch_peakADC[*ich]);
      //cout << " h_IntADC Name : " << h_IntADC[*ich]->GetName() << endl;
   }
/*   for(map<int,vector<double> >::iterator imap = m_ch_intADC.begin(); imap != m_ch_intADC.end(); imap++){
      cout << "imap first " << imap->first << "imap size : " << imap->second.size() << endl;
      for (vector<double>::iterator iADC = imap->second.begin(); iADC != imap->second.end(); iADC++)
      {     
      //   cout << "*iADC : " << *iADC << endl;
         h_IntADC[imap->first]->Fill(*iADC);
         h_PeakADC[imap->first]->Fill(-100);
      }
   //   h_IntADC[imap->first]->Scale( 1. / finTime );
   //   cout << " integral ? " << h_IntADC[imap->first]->Integral() << endl;
   }
 */
   // time divied //
   printf("Total processed number of events: %lld\n", __tot_evt);
    
}//end Loop function

/*void IntADC::SetChannels(vector<int> v_chs)
{


}*/
//void IntADC::SetChannels(vector<int> v_chs)
/*//histInfo IntADC::SetHistInfos(TString hName, TString hTitle, vector<double> v_entries)
{
   struct histInfo tmp ={"","",0,0,0}; 

   double min_;
   int nBins_;
   double max_;
   int min_idx_ = std::min_element(v_entries.begin(), v_entries.end())-v_entries.begin();
   min_ = v_entries.at(min_idx_);
   min_ = floor(min_)-100;
   int max_idx_ = std::max_element(v_entries.begin(), v_entries.end())-v_entries.begin();
   max_ = v_entries.at(max_idx_);
   max_ = ceil(max_)+100;
}*/

void IntADC::SetChannels(string confName)
{
   cout << "SetChannels : " << confName << endl;

   if (confName == "none"){
     for(int i = 0; i < 32; ++i){
        v_chs.push_back(i);
        v_lb.push_back(1);
        v_rb.push_back(1020);
        v_re.push_back(1);
        v_width.push_back(100);
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
            v_lb.push_back(leftbin_);
            v_rb.push_back(rightbin_);
            v_re.push_back(riseEdge_);
            v_width.push_back(Width_);
         }
      }
      else {
         cout << "check out !!" << chlistPath << endl; return;
      }
      fclose(chlist);
   }
   return;
}
void IntADC::Start()
{
   cout << "sk start function " << endl;
   gSystem->mkdir(Form("./intADCDir"));
   fout = new TFile(Form("intADCDir/%s",outfile.c_str()),"RECREATE");
   fout->cd("");

   TDirectory *dir = gDirectory;
   dir->cd();

   DeclareHistos();
}

void IntADC::DeclareHistos()
{
   //cout << "sk start DeclareHistos " << endl;
   for(vector<int>::iterator ich = v_chs.begin(); ich != v_chs.end(); ich++){
      h_Min_vs_ADC[*ich]  = new TH2D(Form("_h_Min_vs_ADC_Ch%d",*ich), Form("Max value vs ADC Ch%d",*ich),  1023, 0,1023, 4500,0,4500); h_Min_vs_ADC[*ich]->Sumw2(); h_Min_vs_ADC[*ich]->SetOption("hist");
      h_Min_vs_SubPedADC[*ich]  = new TH2D(Form("_h_Min_vs_SubPedADC_Ch%d",*ich), Form("Max value vs Ped - ADC Ch%d",*ich),  1023, 0,1023, 5000,-500,4500); h_Min_vs_SubPedADC[*ich]->Sumw2(); h_Min_vs_SubPedADC[*ich]->SetOption("hist");
      h_IntADC_FixedRange[*ich]  = new TH1D(Form("_h_IntADC_FixedRange_Ch%d",*ich), Form("Int. ADC Ch%d",*ich),  101000, -1000, 100000); h_IntADC_FixedRange[*ich]->Sumw2(); h_IntADC_FixedRange[*ich]->SetOption("hist");
      h_PeakADC_FixedRange[*ich]  = new TH1D(Form("_h_PeakADC_FixedRange_Ch%d",*ich), Form("Peak. ADC Ch%d",*ich),  11000, -1000, 10000); h_PeakADC_FixedRange[*ich]->Sumw2(); h_PeakADC_FixedRange[*ich]->SetOption("hist");
      h_PedADC[*ich]  = new TH1D(Form("_h_PedADC_Ch%d",*ich), Form("Ped. ADC Ch%d",*ich),  5000, 0, 5000); h_PedADC[*ich]->Sumw2(); h_PedADC[*ich]->SetOption("hist");
   }
   //cout << "end DeclareHistos " << endl;
}
void IntADC::DeclareOptHistos(int idx, TString hName, TString hTitle, int NumBins, double xlow_, double xup_)
{
   //cout << "sk start DeclareOptHistos : " << hName << " hTitle : " << hTitle << " NumBins : " << NumBins << " xlow_ : " << xlow_ << " xup_ : " << xup_ << endl;
   h_IntADC[idx] = new TH1D(Form("%s",hName.Data()), Form("%s",hTitle.Data()), NumBins, xlow_, xup_);
}

TH1D* IntADC::DeclareOptHistos( TString hName, TString hTitle, int NumBins, double xlow_, double xup_)
{
   //cout << "sk start DeclareOptHistos : " << hName << " hTitle : " << hTitle << " NumBins : " << NumBins << " xlow_ : " << xlow_ << " xup_ : " << xup_ << endl;
   TH1D* h_tmp;
   h_tmp = new TH1D(Form("%s",hName.Data()), Form("%s",hTitle.Data()), NumBins, xlow_, xup_);
   return h_tmp;
}

TH1D* IntADC::DeclareOptHistos( TString hName, TString hTitle,  vector<double> v_entries)
{
   double min_  = -999.;
   int nBins_   = -999;
   double max_  = -999.;
   int min_idx_ = std::min_element(v_entries.begin(), v_entries.end())-v_entries.begin();
   min_ = v_entries.at(min_idx_);
   //cout << "1min_ " << min_  << endl;
   //min_ = floor(min_) -100;
   min_ = floor(min_);
   min_ = min_-((int)min_%100)-100;
   //cout << "2min_ " << min_  << endl;
   int max_idx_ = std::max_element(v_entries.begin(), v_entries.end())-v_entries.begin();
   max_ = v_entries.at(max_idx_);
   //max_ = ceil(max_)+100;
   //cout << "1max_ " << max_  << endl;
   max_ = ceil(max_);
   max_ = max_+(100-(int)max_%100)+100;
   //cout << "2max_ " << max_  << endl;
   //cout << "abs(min_)+abs(max_) : " << abs(min_)+abs(max_) << endl;   
   TH1D* h_tmp;
   h_tmp = new TH1D(Form("%s",hName.Data()), Form("%s",hTitle.Data()), abs(min_)+abs(max_), min_, max_);
   h_tmp->Sumw2();
   h_tmp->GetYaxis()->SetTitle("Entries");
   h_tmp->GetXaxis()->SetTitle(Form(hTitle.Data()));
   for (vector<double>::iterator it = v_entries.begin(); it !=  v_entries.end(); ++it)
   {
      FillHisto(h_tmp, *it);
   }
   return h_tmp;
}
void IntADC::End()
{
   fout->Write();
   fout->Close();
}

void IntADC::SetOutputFileName(string outname)
{   
   outfile = outname;
}

void IntADC::GetVariables()
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


