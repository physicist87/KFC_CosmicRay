//////////////////////////////////////////////
//                                          //
//                                          //
//  Author: Sehwook Lee, merciful@fnal.gov  //
//                                          //
//                                          //
//////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include <TROOT.h>
#include <TUnixSystem.h>
#include <TChain.h>
#include <TStyle.h>
#include <TApplication.h>
#include <TString.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TTree.h>

#include "analysis/DRCTree.h"
#include "include/IntADC.hpp"

using namespace std;

TROOT root ("Plots", "Program for CMS Analysis");

//argc: # of arguments, argv:array for arguments
int main(int argc, char **argv)
{
   printf("The number of options is: %i\n",argc-1);

   if(argc<2)
   {
      printf("At least, you have to set 1, 2\n");
      printf("1. Input filelist\n");
      printf("2. Output file\n");
      return 1;
   }

   for (int iopt=0; iopt<argc; iopt++)
   {
      printf("Option %i = %s\n",iopt,argv[iopt]);
   }

   ///read input options

   //cout << "argc: " << argc << endl;

   char *flist = argv[1];
   printf("Input filelist = %s\n",flist);

   char *outname = argv[2];
   printf("Output file name = %s\n",outname);

   char *channellist = argv[3];
   printf("Channel List file name = %s\n",channellist);

   //merge files
   FILE *filelist;
   char filename[1000];
   string filelistDir, filelistName, filelistPath;

   filelistDir = "./input/";
 
   cout << endl;
   filelistName = argv[1];
   filelistPath = filelistDir + filelistName;
   filelist = fopen(filelistPath.c_str(),"r");
  
   std::vector<double> entries_pertree;

   entries_pertree.clear();
   if (filelist==NULL) {cout << "No files! " << filelist << endl; return 0;}
/*
   while(filelist==NULL)
   {
      cout << "File not found, please try again." << endl;
      cout << "Filelist you want to use: " << filelistDir;
      cin >> filelistName;      
      filelistPath = filelistDir + filelistName;
      filelist=fopen(filelistPath.c_str(),"r");
   }
*/
   //TChain *ch = new TChain("Ch_7");
   TChain *ch = new TChain(Form("DRCNtuple"));

   cout << endl;
   cout << "start merging file(s)" << endl;
   
   while (fscanf(filelist, "%s", filename) != EOF)
   {
      cout << "adding: " << filename << endl;
      ch->Add(filename, 0);
      entries_pertree.push_back(ch->GetEntries());
   }
   cout << "Total number of events after merging root files: " << ch->GetEntries() << endl;

   IntADC *topmass = new IntADC(ch);
  
   // Setup cuts. 
   topmass->SetOutputFileName(outname);
   //topmass->SetChannels(v_chs);
   topmass->SetChannels(argv[3]);
   

   // Run event loop
   topmass->Start();
   topmass->Loop();
   topmass->End();
   
   cout << "End processing..." << endl << endl; 
    
   return 0;
}

