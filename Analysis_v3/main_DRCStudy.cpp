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
#include "include/Waveform.hpp"
#include "include/AvgTimeStr.hpp"
#include "include/IntADC.hpp"

using namespace std;

TROOT root ("Plots", "Program for CMS Analysis");

//argc: # of arguments, argv:array for arguments
int main(int argc, char **argv)
{
   printf("The number of options is: %i\n",argc-1);

   string studyType     = "none";
   string flist         = "none";
   string outname       = "none";
   string confFile      = "none";

   for (int iopt = 0; iopt<argc; ++iopt)
   {
      char *argch = argv[iopt];

      if(strcmp(argch,"-inputList")==0) 
      {
         flist = argv[iopt+1];
         iopt = iopt+1;
      }

      if(strcmp(argch,"-studyType")==0) // Output Directory //
      {
         studyType = argv[iopt+1];
         iopt = iopt+1;
      }
      if(strcmp(argch,"-outputName")==0) // Output Directory //
      {
         outname = argv[iopt+1];
         iopt = iopt+1;
      }

      if(strcmp(argch,"-config")==0)
      {
         confFile = argv[iopt+1];
         iopt = iopt+1;
      }
   }
   cout << 
   " inputList : " << flist << 
   " studyType : " << studyType << 
   " outputName : " << outname << 
   " config : " << confFile << 
   endl;
/*   ///read input options

   //cout << "argc: " << argc << endl;

   char *flist = argv[1];
   printf("Input filelist = %s\n",flist);

   char *outname = argv[2];
   printf("Output file name = %s\n",outname);

   char *channellist = argv[3];
   printf("Channel List file name = %s\n",channellist);
*/
   //merge files
   FILE *filelist;
   char filename[1000];
   string filelistDir, filelistName, filelistPath;

   filelistDir = "./input/";
 
   cout << endl;
   filelistName = flist;
   filelistPath = filelistDir + filelistName;
   filelist = fopen(filelistPath.c_str(),"r");
  
   std::vector<double> entries_pertree;

   entries_pertree.clear();

   if (filelist==NULL) {cout << "No files! " << filelist << endl; return 0;}

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

   if (studyType == "Waveform"){
    
      Waveform *drcstudy = new Waveform(ch);
     
      // Setup cuts. 
      drcstudy->SetOutputFileName(outname);
      drcstudy->SetChannels(confFile);
      
   
      // Run event loop
      drcstudy->Loop();
      drcstudy->End();
 
      delete drcstudy;


   }
   else if (studyType == "AvgTimeStr"){

      AvgTimeStr *drcstudy = new AvgTimeStr(ch);
     
      // Setup cuts. 
      drcstudy->SetOutputFileName(outname);
      //drcstudy->SetChannels(argv[3]);
      drcstudy->SetChannels(confFile);
      
      
      // Run event loop
      drcstudy->Start();
      drcstudy->Loop();
      drcstudy->End();
      delete drcstudy;
   }
   else if (studyType == "IntADC"){
  
      IntADC *drcstudy = new IntADC(ch);
     
      // Setup cuts. 
      drcstudy->SetOutputFileName(outname);
      //drcstudy->SetChannels(argv[3]);
      drcstudy->SetChannels(confFile);
      
      
      // Run event loop
      drcstudy->Start();
      drcstudy->Loop();
      drcstudy->End();
      delete drcstudy;
   }
   cout << "End processing..." << endl << endl; 
    
   return 0;
}

