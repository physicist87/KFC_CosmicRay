void plot()
{
   //TString inputName = "result_5698_MID11";
   //TString inputConfName = "result_5698_MID11";
   TString inputName = "result_5667_MID7";
   TString inputConfName = "result_5666_MID7";
   void SeletHist(TString RunName, TString Confg);
   SeletHist(inputName, inputConfName);

}
void SeletHist(TString RunName, TString Confg)
{
   TString findChsFromName(TString hname);  
   //void DrawHisto(TH1* h_tmp, TString chs, TString outDir);
   void DrawHisto(TH1* h_tmp, TString chs, TString outDir, TString xtitle, TString ytitle, int rebin, int low_, int up_);

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
   map<TString, TString> m_ch_xtitle;
   map<TString, TString> m_ch_ytitle;
   map<TString, int> m_ch_rebin;
   map<TString, int> m_ch_rangelower;
   map<TString, int> m_ch_rangeupper;

   FILE* chlist; 
   string chlistDir, chlistName, chlistPath;
   chlistDir = "./config/";
   //chlistName = confName;
   chlistName = Form("HistConfig_%s.config",Confg.Data());
   chlistPath = chlistDir + chlistName;
   cout << "chlistPath: " << chlistPath << endl;
   chlist = fopen(chlistPath.c_str(),"r");
   char chname[100];
   char xtitle[100];
   char ytitle[100];
   int rebin_;
   int lower_;
   int upper_;
   char module[100];
   if (chlist != NULL){
   //   cout << "cococo " << endl;
      while (fscanf(chlist, "%s %s %s %d %d %d\n", chname, xtitle, ytitle, &rebin_, &lower_, &upper_ ) != EOF){
         cout << "chname : " << chname << " xtitle : " << xtitle << " ytitle : " << ytitle << " lower_ "<< lower_  << " upper_ : " << upper_ << endl;
         m_ch_xtitle[chname] = xtitle;   
         m_ch_ytitle[chname] = ytitle;   
         m_ch_rebin[chname] = rebin_;   
         m_ch_rangelower[chname] = lower_;   
         m_ch_rangeupper[chname] = upper_;   
      }
   }
   else {
      cout << "check out !!" << chlistPath << endl; return;
   }
   fclose(chlist);
   /// 

   //// Load root files ///
   TString fname = Form("%s",RunName.Data());
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
   TString outputDir = Form("plots/output/%s/",fname.Data());
   cout << "ioutput Dir " << outputDir << endl;
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
         DrawHisto(Hist, channel, outputDir, m_ch_xtitle[hName], m_ch_ytitle[hName], m_ch_rebin[hName], m_ch_rangelower[hName], m_ch_rangeupper[hName]);
         //m_ch_hist[channl] = findChsFromName(Hist->GetName());  
         //m_hn_hist[Hist->GetName()] = Hist;
      }// if
   }// while
   rfile->Close(); 
}

TString findChsFromName(TString hname){
   cout << "befor hname : " << hname << endl;
   char tb = '_';
   hname.Remove(0,hname.Last(tb)+1);
   cout << "after hname : " << hname<< endl;
   return hname;
}

void DrawHisto(TH1* h_tmp, TString chs, TString outDir, TString xtitle, TString ytitle, int rebin, int low_, int up_){
   TString hname = h_tmp->GetName();
   TCanvas* c_ = new TCanvas(Form("c_%s",hname.Data()),Form("canvas %s",hname.Data()), 1200,900);
   c_->cd();
   if (hname.Contains("PeakADC")){h_tmp->GetXaxis()->SetTitle("Ped. ADC");}
   if (hname.Contains("PedADC")){h_tmp->GetXaxis()->SetTitle("Peak. ADC");}
   if (hname.Contains("IntADC")){h_tmp->GetXaxis()->SetTitle("Int. ADC");}
   h_tmp->GetYaxis()->SetTitle("Entries");
   h_tmp->Draw("hist");
   c_->SaveAs(Form("%s/%s.pdf",outDir.Data(), hname.Data()));
   h_tmp->Rebin(rebin);
   //h_tmp->Draw("hist");
   c_->SaveAs(Form("%s/%s_Rebin.pdf",outDir.Data(), hname.Data()));
   h_tmp->GetXaxis()->SetRangeUser(low_,up_);
   c_->SaveAs(Form("%s/%s_SelectRange.pdf",outDir.Data(), hname.Data()));
   return;
}

