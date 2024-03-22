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
   if(strcmp(daqtype,"DRC")==0) {cout << "daq type : " <<  daqtype_ << endl; daqtype_ ="Run";}
   else if (strcmp(daqtype,"Cosmic") == 0) {cout << "daq type : " <<  daqtype_ << endl; daqtype_ ="SRun";}
   else {cout << "default daq type is KFC : "<< endl; daqtype_ ="Run";}

   cout << "daqtype_ : " << daqtype_ << endl;

   TFile *fout = new TFile(Form("./output/%s_Run%d_MID%d.root",outputName,runNum,midNum), "recreate");
   TTree* t1= new TTree(Form("DRCNtuple"),"DRC Ntuple tree (only one MID)");
   t1->Branch("EvtNum",&evt,"evt/D");
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
   //sprintf(logfilename,"/pnfs/knu.ac.kr/data/cms/store/user/yeo/HDD/Run_%d/Run_%d_Wave/Run_%d_Wave_log/Run_%d_Wave_MID_%d_buffer.txt",runNum,runNum,runNum,runNum,midNum);

   //for (const auto& file : directory_iterator(logfilename)) cout << file.path() << endl;
   vector<string> v_logfile = DirFileLists(Form("/pnfs/knu.ac.kr/data/cms/store/user/yeo/HDD/Run_%d/Run_%d_Wave/Run_%d_Wave_log/",runNum,runNum,runNum),".txt");
   lfp = fopen(logfilename, "rb");
   times_= 0; 
   tv_= -1; 
   if (lfp == NULL) {cout << "check out input files!!: " << logfilename << endl;}
   while (fscanf(lfp, "%lld %d\n", &times_, &tv_) != EOF){
//      cout << "times_ : " << times_ << " tv_" << tv_ << endl;
      v_times.push_back(times_);
      v_tv.push_back(tv_);
      if (tv_ > 65) {
//         cout << "tv_/64" << tv_/64 << endl;
         for(int idtv_ = 0; idtv_ < (tv_/64)-1; idtv_++){
            v_times.push_back(times_);
            v_tv.push_back(tv_);
         }
      }
   }
   fclose(lfp); 

   // open dat files //
   sprintf(filename,"/pnfs/knu.ac.kr/data/cms/store/user/yeo/HDD/Run_%d/Run_%d_Wave/Run_%d_Wave_MID_%d/Run_%d_Wave_MID_%d_FILE_0.dat",runNum,runNum,runNum,midNum,runNum,midNum);
   cout << "filename : " << filename << endl; 
   fp = fopen(filename, "rb");
   if (fp==NULL) {cout << "No Files! " << filename <<endl; return 0;}
   fseek(fp, 0L, SEEK_END);
   file_size = ftell(fp);
   fclose(fp);
   nevt = file_size / 65536;

   printf("-----------------------------------------------------------------------\n");
   cout << " nevt : " << nevt << " size of v_times: " << v_times.size() << endl;
   fp = fopen(filename, "rb");
   if (fp == NULL) {cout << "something wrong " << filename << endl;}
   for (evt = 0; evt < nevt; evt++) {
      fread(data, 1, 64, fp);
      fread(adc, 2, 32736, fp);
      //v_adc.clear(); // vector for write ADC
      //m_ch_ADCs[ich].clear();
      //for (int idx = 0; idx < 1023; idx++){
      for (int ich = 0; ich < 32; ++ich)
      {
         m_ch_ADCs[ich]= GetADCs(adc,ich);
         //m_ch_ADCs[ich].push_back(adc[idx * 32 + ich]);
      }
      //} // channel loop //
      t_times_ = v_times[evt]; 
      t_tv_ = v_tv[evt]; 
      t1->Fill();
   } /// event loop ///
   cout << "End processing..." << endl << endl; 
    
   fout->Write();
   fout->Close();
 
   fclose(fp);
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
      while ((diread = readdir(dir)) != nullptr) {
        cout << "diread->d_name " << diread->d_name << endl;
        string fname=diread->d_name;
        cout << "file type : " << fname.find(type_.Data())<< endl;;
        files.push_back(diread->d_name);
      }
      closedir(dir);
   } else {
     perror("opendir");
     //return EXIT_FAILURE;
   }


  for (auto file : files) cout << file << "| ";
  cout << endl;
  return files;
  //return EXIT_SUCCESS;
}
