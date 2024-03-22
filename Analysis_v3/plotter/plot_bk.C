void plot()
{
   TString findChsFromName(TString hname);  
   //void DrawHisto(TH1* h_tmp, TString chs, TString outDir);

   /// Load config files ///
   // Load Channel List file //
   vector<int> v_chs;
   vector<int> v_lb;
   vector<int> v_rb;
   vector<int> v_re;
   vector<int> v_width;
   vector<TString> v_module;
   //map<int, TString> m_ch_module;
   //map<int, TH1> m_ch_hist;
   //map<TString, TH1> m_ch_hist;
/*
   FILE* chlist; 
   string chlistDir, chlistName, chlistPath;
   chlistDir = "./config/";
   //chlistName = confName;
   chlistName = "4chsTest.config";
   chlistPath = chlistDir + chlistName;
   cout << "chlistPath: " << chlistPath << endl;
   chlist = fopen(chlistPath.c_str(),"r");
   int chs_;
   int riseEdge_=-1;
   int Width_=-1;
   int leftbin_=-1;
   int rightbin_ =-1;
   char module[100];
   if (chlist != NULL){
   //   cout << "cococo " << endl;
      while (fscanf(chlist, "%d %d %d %d %d %s\n", &chs_, &leftbin_, &rightbin_, &riseEdge_, &Width_, module ) != EOF){
         cout << "ch "<< chs_ << " leftbin_ : " << leftbin_ << " rightbin_ : " << rightbin_ << " riseEdge_ : " << riseEdge_ << " Width_ : " << Width_<< " module : " << module << endl;
         v_chs.push_back(chs_-1);
         v_lb.push_back(leftbin_);
         v_rb.push_back(rightbin_);
         v_re.push_back(riseEdge_);
         v_width.push_back(Width_);
     //    m_ch_module[chs_-1] = module;
      }
   }
   else {
      cout << "check out !!" << chlistPath << endl; return;
   }
   fclose(chlist);
   /// 

   //// Load root files ///
   TString fname = Form("result_5660_MID7");
   TFile* rfile = TFile::Open(Form("../output/%s.root",fname.Data()),"READ");
   if (rfile ==NULL) {cout << "There is no root file : "<< fname << endl; return;}
   cout << "rfile " << rfile->GetName() << endl;
   //// Load Histograms ////
   rfile->cd();
   TDirectory *current_sourcedir = gDirectory;
   cout << "f name : " << rfile->GetName() << endl;
   TIter nextkey( current_sourcedir->GetListOfKeys() );
   TKey *key;
   TObject *obj;
   string histkey =""; 
   TString HistTitle = "";
   TString outputDir = Form("output/%s/",fname.Data());
   gSystem->Exec(Form("mkdir -p %s",outputDir.Data() ));
   while ( (key= (TKey*)nextkey()))
   {
      rfile->cd();

      obj = key->ReadObj();
      if( TString(obj->ClassName()).Contains("TH1"))
      {
         histkey = key->GetName();
         rfile->cd();
         TH1 *Hist = (TH1*)gDirectory->Get(key->GetName())->Clone(histkey.c_str());
         cout << "Before Erase Hist ->Name : "<< Hist->GetName() << endl;
         TString hName = Hist->GetName();
         TString channel = findChsFromName(Hist->GetName());       cout << "channel " << channel << endl;
         //m_ch_hist[channl] = findChsFromName(Hist->GetName());  
         //m_hn_hist[Hist->GetName()] = Hist;
      }// if
   }// while
   rfile->Close(); */
}

TString findChsFromName(TString hname){
   cout << "befor hname : " << hname << endl;
   char tb = '_';
   hname.Remove(0,hname.Last(tb)+1);
   cout << "after hname : " << hname<< endl;
   return hname;
}
/*
void DrawHisto(TH1* h_tmp, TString chs, TString outDir){
   TString hname = h_tmp->GetName();
   TCanvas* c_ = new TCanvas(Form("c_%s",hname.Data()),Form("canvas %s",hname.Data()), 1200,900);
   c_->cd();
   h_tmp->Draw("hist");
   c_->SaveAs(Form("plots/%s/%s",outDir.Data(), hname.Data()));
   return;
}
*/
