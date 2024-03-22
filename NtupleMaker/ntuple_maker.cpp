//////////////////////////////////////////////
//                                          //
//                                          //
//  Author: Sehwook Lee, merciful@fnal.gov  //
//                                          //
//                                          //
//////////////////////////////////////////////

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <map>

#include <TROOT.h>
#include <TUnixSystem.h>
#include <TChain.h>
#include <TStyle.h>
#include <TApplication.h>
#include <TString.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TTree.h>
#include <filesystem>
#include <dirent.h>


using namespace std;

TROOT root ("Plots", "Program for CMS Analysis");

//argc: # of arguments, argv:array for arguments
int main(int argc, char **argv)
{

   FILE *fp;
   FILE *lfp;
   long long file_size;
   int nevt;
   char data[64];
   short adc[32736];
   int evt;
   int totalevt;
   //string filename;// dat file name // 
   //string logfilename;// dat file name // 
   char filename[100];// dat file name // 
   char logfilename[100];// dat file name // 
   long long times_; 
   long long t_times_; 
   int tv_; 
   int t_tv_; 
   vector<short> v_adc;
   vector<long long> v_times;
   vector<int> v_tv;

   int channelCheck(int channel);
   vector<int> GetADCs(short* arr_,int channel);
   vector<string> DirFileLists(TString path, TString type_);

   printf("The number of options is: %i\n",argc-1);

   if(argc<2)
   {
      printf("At least, you have to set 1, 2\n");
      printf("1. RunNumber filelist\n");
      printf("2. MidNumber\n");
      printf("3. outputName\n");
      printf("4. DAQType\n"); // Comsmic or KFC

      return 1;
   }

   for (int iopt=0; iopt<argc; iopt++)
   {
      printf("Option %i = %s\n",iopt,argv[iopt]);
   }

   ///read input options

   //cout << "argc: " << argc << endl;

   //char *flist = argv[1];
   int runNum = atoi(argv[1]);
   printf("RunNumber ! = %d\n",runNum);

   //char *outname = argv[2];
   int midNum = atoi(argv[2]);
   printf("Mid Number = %d\n",midNum);

   char *outputName = argv[3];
   printf("Output file name = %s\n",outputName);

   char *daqtype = argv[4];
   printf("DAQ type = %s\n", daqtype);
   
   string daqtype_ = ""; 
   string daqSEtype_ = ""; 
   if(strcmp(daqtype,"DRC")==0) {cout << "daq type : " <<  daqtype_ << endl; daqtype_ ="Run"; daqSEtype_ = "HDD";}
   else if (strcmp(daqtype,"Cosmic") == 0) {cout << "daq type : " <<  daqtype_ << endl; daqtype_ ="SRun";daqSEtype_ = "SHECRO";}
   else {cout << "default daq type is KFC : "<< endl; daqtype_ ="Run"; daqSEtype_ = "HDD";}

   cout << "daqtype_ : " << daqtype_ << endl;

   TFile *fout = new TFile(Form("./output/%s_Run%d_MID%d.root",outputName,runNum,midNum), "recreate");
   TTree* t1= new TTree(Form("DRCNtuple"),"DRC Ntuple tree (only one MID)");
   t1->Branch("EvtNum",&totalevt,"evtNum/I");
   t1->Branch("Times",&t_times_,"times_/L");
   t1->Branch("TimeV",&t_tv_,"timeV_/I");
   map<int,std::vector<int> > m_ch_ADCs;
   for (int ich = 0; ich < 32; ++ich)
   {
      vector<int> v_tmp;
      m_ch_ADCs[ich] = v_tmp; 
   }
   cout << "m_ch_ADCs size : "<< m_ch_ADCs.size() << endl;
   for(std::map<int, vector<int> >::iterator it=m_ch_ADCs.begin(); it!=m_ch_ADCs.end(); ++it){
      cout<< "it first : " << it->first << endl;   
      t1->Branch(Form("Ch%d_ADC", it->first), &it->second);
   }
//   t1->Branch("ADC",&v_adc);

   // open log files //
   //                /pnfs/knu.ac.kr/data/cms/store/user/yeo/HDD/Run_5660/Run_5660_Wave/Run_5660_Wave_log/Run_5660_Wave_MID_7_buffer.txt  // DRC DAQ
   //                /pnfs/knu.ac.kr/data/cms/store/user/yeo/HDD/SRun_5660/SRun_5660_Wave/SRun_5660_Wave_log/SRun_5660_Wave_MID_7_buffer.txt  // CosmicRay DAQ

   //for (const auto& file : directory_iterator(logfilename)) cout << file.path() << endl;
   cout << "Open Log file ! " << endl;
   vector<string> v_logfile = DirFileLists(Form("/pnfs/knu.ac.kr/data/cms/store/user/yeo/%s/%s_%d/%s_%d_Wave/%s_%d_Wave_log/",daqSEtype_.c_str(),daqtype_.c_str(),runNum, daqtype_.c_str(),runNum, daqtype_.c_str(), runNum),".txt");
   lfp = fopen(v_logfile[0].c_str(), "rb");

   totalevt = 0; 
   times_= 0; 
   tv_= -1; 
   if (lfp == NULL) {cout << "check out input files!!: " << logfilename << endl;}
   while (fscanf(lfp, "%lld %d\n", &times_, &tv_) != EOF){
//      cout << "times_ : " << times_ << " tv_" << tv_ << endl;
      v_times.push_back(times_);
      v_tv.push_back(tv_);
      if (tv_ != 65) {
//         cout << "tv_/64" << tv_/64 << endl;
         for(int idtv_ = 0; idtv_ < (tv_/64)-1; idtv_++){
            v_times.push_back(times_);
            v_tv.push_back(tv_);
         }
      }
   }
   fclose(lfp); 

   // open dat files //
   cout << Form("/pnfs/knu.ac.kr/data/cms/store/user/yeo/%s/%s_%d/%s_%d_Wave/%s_%d_Wave_MID_%d/",daqSEtype_.c_str(),daqtype_.c_str(),runNum, daqtype_.c_str(),runNum, daqtype_.c_str(), runNum,midNum) << endl;
   vector<string> v_datfile = DirFileLists(Form("/pnfs/knu.ac.kr/data/cms/store/user/yeo/%s/%s_%d/%s_%d_Wave/%s_%d_Wave_MID_%d/",daqSEtype_.c_str(),daqtype_.c_str(),runNum, daqtype_.c_str(),runNum, daqtype_.c_str(), runNum,midNum),".dat");
   cout << "v_datfile : " << v_datfile.size() << endl;
   evt=0;
   for (auto file : v_datfile) {
      cout << "file :" << file << endl;
      //cout << "filename : " << filename << endl; 
      fp = fopen(file.c_str(), "rb");

      if (fp==NULL) {cout << "No Files! " << filename <<endl; return 0;}

      fseek(fp, 0L, SEEK_END);
      file_size = ftell(fp);
      fclose(fp);

      nevt = file_size / 65536;
      printf("-----------------------------------------------------------------------\n");

      cout << " nevt : " << nevt << " size of v_times: " << v_times.size() << endl;
      fp = fopen(file.c_str(), "rb");
      if (fp == NULL) {cout << "something wrong " << file << endl;}
      cout << "nevt : " << nevt << endl;
      for (int ievt =0; ievt < nevt; ievt++) {
         if (evt%1000 ==0)cout << "evt : " << evt<< endl;

         fread(data, 1, 64, fp);
         fread(adc, 2, 32736, fp);

         for (int ich = 0; ich < 32; ++ich){ m_ch_ADCs[ich]= GetADCs(adc,ich);}

         t_times_ = v_times[evt]; 
         t_tv_ = v_tv[evt]; 
         totalevt = evt;
         t1->Fill();
         
         evt++;
      } /// event loop ///
      fclose(fp);
      cout << " loop" << endl;
   }
   cout << "evt : " << evt << endl;
   cout << "End processing..." << endl << endl; 
    
   fout->Write();
   fout->Close();
 
   return 0;
}

int channelCheck(int channel){
  
   int ch_ = -999;
   if (channel < 1)
      ch_ = 0;
   else if (channel > 32)
     ch_ = 31;
   else
     ch_ = channel - 1;
   return ch_;
}
vector<int> GetADCs(short* arr_,int channel){
   std::vector<int> v_tmp;
   for (int i = 0; i< 1023; ++i){
      v_tmp.push_back(arr_[i*32 + channel]);
   }
   return v_tmp;
}
vector<string> DirFileLists(TString path, TString type_){
   DIR *dir;
   struct dirent *diread;
   vector<string> files;
   if ((dir = opendir(Form("%s",path.Data()))) != nullptr){
      files.clear();
      while ((diread = readdir(dir)) != nullptr) {
         TString fname=Form("%s",diread->d_name);
         if (fname.Contains(type_.Data()) !=0){
           files.push_back(Form("%s/%s",path.Data(),fname.Data()));
         };
      }
      closedir(dir);
   } else {
     perror("opendir");
     //return EXIT_FAILURE;
   }


//  for (auto file : files) cout << file << "| ";
  cout << endl;
  return files;
  //return EXIT_SUCCESS;
}
