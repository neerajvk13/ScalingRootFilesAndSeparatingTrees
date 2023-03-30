 void cocktailMC()
 {
 /* // This segment gives the general idea of the code

   TFile *f1 = new TFile("/home/krishnakumar/Desktop/Bes3/Analysis/Singletags/DpDm1.root");
   TTree *t1 = (TTree*)f1->Get("SingletagKPi");
   
   TFile *F = new TFile("DpDm.root","RECREATE"); 
   TTree *T = t1->CloneTree(0);
   
   Long64_t nentries = t1->GetEntries();
   TRandom *r0 = new TRandom();
   
   for (Int_t iEvent = 0; iEvent < nentries; iEvent++) {
	Double_t ran = r0->Uniform(1);//(0,1)
	Double_t num = 1./10.88;
	//cout<<ran<<endl;
	if(ran>num)continue;
	t1->GetEntry(iEvent);      
	T->Fill();
     }
     
   T->Write();
   F->Close();
   f1->Close();
   
     	
}   
 */

         vector<TString> MCNAME;        	
	MCNAME.push_back("QCMC/combined_root_files/QCMC_2010_1");
    MCNAME.push_back("QCMC/combined_root_files/QCMC_2010_2");
    MCNAME.push_back("QCMC/combined_root_files/QCMC_2011_1");
    MCNAME.push_back("QCMC/combined_root_files/QCMC_2011_2");

	MCNAME.push_back("DpDm/combined_root_files/DpDm_2010");
	MCNAME.push_back("DpDm/combined_root_files/DpDm_2011");
	MCNAME.push_back("RR1S/combined_root_files/RR1S_2010");    //  gammaJpsi");
	MCNAME.push_back("RR1S/combined_root_files/RR1S_2011");    //  gammaJpsi");
	MCNAME.push_back("RR2S/combined_root_files/RR2S_2010");    //  gammaPsi");
	MCNAME.push_back("RR2S/combined_root_files/RR2S_2011");    //  gammaPsi");
	MCNAME.push_back("nonDDbar/combined_root_files/nonDDbar_2010");
	MCNAME.push_back("nonDDbar/combined_root_files/nonDDbar_2011");
	MCNAME.push_back("qqbar/combined_root_files/kkmc_2010");
	MCNAME.push_back("qqbar/combined_root_files/kkmc_2011");
	MCNAME.push_back("ditau/combined_root_files/ditau_2010");
	MCNAME.push_back("ditau/combined_root_files/ditau_2011");


	//tag modes
	vector<TString> Tag;
	Tag.push_back("d0tag");
	Tag.push_back("d2kpi");
	Tag.push_back("d2kpi2");
	Tag.push_back("d2k3pi");
	Tag.push_back("d2k3pi2");
	Tag.push_back("d2kpipi0");
	Tag.push_back("d2kpipi02");
	Tag.push_back("d2kspipi");
	Tag.push_back("d2kskk");
	Tag.push_back("d2kk");
	Tag.push_back("d2pipi");
    Tag.push_back("d2kspi0pi0");
    Tag.push_back("d2kspi0");
    Tag.push_back("d2kseta");
    Tag.push_back("d2kseta2");
    Tag.push_back("d2ksomg");
    Tag.push_back("d2ksetp");
    Tag.push_back("d2kskmpp");
    Tag.push_back("d2pipipi0");
    Tag.push_back("d2pipipipi");
    Tag.push_back("d2ksetp2");
    Tag.push_back("dbklpi0");
    Tag.push_back("dbklpi0pi0");
    Tag.push_back("dbkskpi");
    




	vector<double> scale;
	scale.push_back(10.8);
    scale.push_back(10.8);
    scale.push_back(10.8);
    scale.push_back(10.8);

	scale.push_back(10.9);  //DpDm
	scale.push_back(10.8);  //DpDm
	scale.push_back(10.8);  //RR1S
	scale.push_back(10.1);  //RR1S
	scale.push_back(10.8);  //RR2S
	scale.push_back(10.1);  //RR2S
	scale.push_back(10.8);  //nonDDbar
	scale.push_back(10.1);  //nonDDbar
	scale.push_back(7.8);   //qqbar(KKMC)
	scale.push_back(7.3);   //qqbar(KKMC)
	scale.push_back(10.8);  //ditau
	scale.push_back(10.1);  //ditau


    for(Int_t i=0; i<MCNAME.size(); i++){
    
	       //cout<<"Tag :"<<Tag.at(j)<<endl;
	       
	       for(Int_t j = 0; j < Tag.size(); j++){
		cout << " ------ Start filter mc " << MCNAME[i] << endl;
	
		TString  FILENAME_I = "/scratchfs/bes/ph21d012/run/DKsKpi/"; //"/home/krishnakumar/Desktop/Bes3/Analysis/Singletags/Background/"
		FILENAME_I += MCNAME[i];		
		FILENAME_I += ".root";
		TFile *FILE_I = new TFile(FILENAME_I);
		TString TREENAME_I = Tag.at(j);		
		TTree *TREE_I = (TTree*)FILE_I->Get(TREENAME_I);
	
		TString FILENAME_O = "/scratchfs/bes/ph21d012/run/DKsKpi/"; //"/home/krishnakumar/Desktop/Bes3/Analysis/Singletags/Background/" ;
		FILENAME_O  += MCNAME[i];		
		FILENAME_O += Tag.at(j);
		FILENAME_O += ".root";
		TFile *FILE_O = new TFile(FILENAME_O, "recreate");
	
			        	
		TTree *TREE_O = TREE_I->CloneTree(0);
		Long64_t nentries = TREE_I->GetEntries();
		TRandom *r0 = new TRandom();	

		cout << " Total event : " << nentries << endl;	
		cout << " Start filter " << TREENAME_I << "..." << endl;
	        
		for (Int_t iEvent = 0; iEvent < nentries; iEvent++) {
	               Double_t ran = r0->Uniform(1);//(0,1)
	               Double_t num = 1./scale[i];  //Scaling MCNAME
	               //cout<<ran<<endl;
	               if(ran>num)continue;
	               TREE_I->GetEntry(iEvent);      
	               TREE_O->Fill();
                }
	        
		TREE_O->Write();

		delete FILE_I;
		delete FILE_O;
	     }//i

        }//j	

 }