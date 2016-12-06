// ZdZdPlotting includes
#include "ZdZdPlottingAlg.h"

#include "AnalysisCamEvent/CamEvent.h"


//uncomment the line below to use the HistSvc for outputting trees and histograms
#include "GaudiKernel/ITHistSvc.h"
#include "TTree.h"
#include "TH1D.h"
#include <TStyle.h>
#include <TCanvas.h>

bool CamObject::AutoSetTLV = true; //automatically fills the TLorentzVector properties of objects if it can


ZdZdPlottingAlg::ZdZdPlottingAlg( const std::string& name, ISvcLocator* pSvcLocator ) : CamAlgorithm( name, pSvcLocator ),
  chanInfo("ChannelInfoTool/channelInfo") {
  

}


ZdZdPlottingAlg::~ZdZdPlottingAlg() {}


StatusCode ZdZdPlottingAlg::initialize() {
  ATH_MSG_INFO ("Initializing " << name() << "...");
  //
  //This is called once, before the start of the event loop
  //Retrieves of tools you have configured in the joboptions go here
  //

  //HERE IS AN EXAMPLE
  //We will create a histogram and a ttree and register them to the histsvc
  //Remember to uncomment the configuration of the histsvc stream in the joboptions
  //
  ServiceHandle<ITHistSvc> histSvc("THistSvc",name());
  myHist = new TH1D("myHist","myHist",12,0.5,12.5);
  CHECK( histSvc->regHist("/MYSTREAM/myHist", myHist) ); //registers histogram to output stream (like SetDirectory in EventLoop)
  //deltaR12 4e
  myHist_DeltaR12_4e_channel = new TH1D("myHist_DeltaR12_4e_channel","myHist_DeltaR12_4e_channel",60,0,6);
  CHECK(histSvc->regHist("/MYSTREAM/myHist_DeltaR12_4e_channel", myHist_DeltaR12_4e_channel) );
  //deltaR12 2e2m
  myHist_DeltaR12_2e2m_channel = new TH1D("myHist_DeltaR12_2e2m_channel","myHist_DeltaR12_2e2m_channel",60,0,6);
  CHECK(histSvc->regHist("/MYSTREAM/myHist_DeltaR12_2e2m_channel", myHist_DeltaR12_2e2m_channel) );
  //deltaR12 4m
  myHist_DeltaR12_4m_channel = new TH1D("myHist_DeltaR12_4m_channel","myHist_DeltaR12_4m_channel",60,0,6);
  CHECK(histSvc->regHist("/MYSTREAM/myHist_DeltaR12_4m_channel", myHist_DeltaR12_4m_channel) );
  //deltaR34 4e
  myHist_DeltaR34_4e_channel = new TH1D("myHist_DeltaR34_4e_channel","myHist_DeltaR34_4e_channel",60,0,6);
  CHECK(histSvc->regHist("/MYSTREAM/myHist_DeltaR34_4e_channel", myHist_DeltaR34_4e_channel) );
  //deltaR34 2e2m
  myHist_DeltaR34_2e2m_channel = new TH1D("myHist_DeltaR34_2e2m_channel","myHist_DeltaR34_2e2m_channel",60,0,6);
  CHECK(histSvc->regHist("/MYSTREAM/myHist_DeltaR34_2e2m_channel", myHist_DeltaR34_2e2m_channel) );
  //deltaR34 4m
  myHist_DeltaR34_4m_channel = new TH1D("myHist_DeltaR34_4m_channel","myHist_DeltaR34_4m_channel",60,0,6);
  CHECK(histSvc->regHist("/MYSTREAM/myHist_DeltaR34_4m_channel", myHist_DeltaR34_4m_channel) );

  //myTree = new TTree("myTree","myTree");
  // CHECK( histSvc->regTree("/MYSTREAM/myTree", myTree) ); //registers tree to output stream (like SetDirectory in EventLoop) inside a sub-directory
  
 myHist->GetXaxis()->SetBinLabel(1,"total Events");
 myHist->GetXaxis()->SetBinLabel(2,"Cleaning");
 myHist->GetXaxis()->SetBinLabel(3,"Primary Vertex");
 myHist->GetXaxis()->SetBinLabel(4,"Trigger");
 myHist->GetXaxis()->SetBinLabel(5,"SFO");
 //myHist->GetXaxis()->SetBinLabel(6,"NotOverlaps");
 myHist->GetXaxis()->SetBinLabel(6,"Kinematic");
 // myHist->GetXaxis()->SetBinLabel(8,"Trigger Matched");
 //myHist->GetXaxis()->SetBinLabel(9,"e Quality (12)");
 //myHist->GetXaxis()->SetBinLabel(10,"Muon Quality");
 myHist->GetXaxis()->SetBinLabel(7,"Delta R");
 //myHist->GetXaxis()->SetBinLabel(12,"Isolation");
 // myHist->GetXaxis()->SetBinLabel(13,"Electron ID");
 //myHist->GetXaxis()->SetBinLabel(14,"Impact Parameter");
 myHist->GetXaxis()->SetBinLabel(8,"QVeto ");
 myHist->GetXaxis()->SetBinLabel(9,"Z Veto");
 myHist->GetXaxis()->SetBinLabel(10,"Loose SR");
 myHist->GetXaxis()->SetBinLabel(11,"Medium SR");
 myHist->GetXaxis()->SetBinLabel(12,"TightSR");

 m_massPoints[302073] = 0.5;//my.output.29.3.root
 m_massPoints[302074] = 1.0;//my.output.29.14.root
 m_massPoints[302075] = 2.0;//my.output.29.4.root
 m_massPoints[302076] = 5.;//my.output.29.13.root
 m_massPoints[302077] = 10.;//my.output.29.8.root
 m_massPoints[302078] = 15.;//my.output.29.5.root
 m_massPoints[302079] = 20.;//my.output.29.11.root
 m_massPoints[302080] = 25.;//my.output.29.6.root
 m_massPoints[302081] = 30.;//my.output.29.7.root
 m_massPoints[302082] = 35.;//my.output.29.0.root
 m_massPoints[302083] = 40.;
 m_massPoints[302084] = 45.;//my.output.29.1.root
 m_massPoints[302085] = 55.;//my.output.29.2.root
 m_massPoints[302086] = 55.;//my.output.29.9.root
 m_massPoints[302087] = 60.;//my.output.29.12.root

  return StatusCode::SUCCESS;
}

StatusCode ZdZdPlottingAlg::finalize() {
  ATH_MSG_INFO ("Finalizing " << name() << "...");
  //
  //Things that happen once at the end of the event loop go here
  //

  return StatusCode::SUCCESS;
}

StatusCode ZdZdPlottingAlg::execute() {  
  ATH_MSG_DEBUG ("Executing " << name() << "...");

  static const StatusCode NEXTEVENT = StatusCode::SUCCESS; //we return this to move to next event

  //here we implement the reconstruction-level cutflow ...

  CamEvent evt;
  
  double evtWeight = evt.get<double>("evtWeight");
  int mc_channel_number = evt.get<unsigned int>("mc_channel_number");
  
  chanInfo->Fill(mc_channel_number,"All",evtWeight);
  myHist->Fill(1,evtWeight); 
  
  
  
  
  ///***** Event Preselections ******
  
  ///EventCleaning
  if(!evt.get<bool>("passCleaning")) return NEXTEVENT;
  chanInfo->Fill(mc_channel_number,"Cleaning",evtWeight);
  myHist->Fill(2,evtWeight);
 
  
  ///NPV
  if(!evt.get<bool>("passNPV")) return NEXTEVENT; chanInfo->Fill(mc_channel_number,"PrimaryVertex",evtWeight); 
myHist->Fill(3,evtWeight); 
  int RunNumber = evt.get<int>("RunNumber");
  int passTriggers = evt.get<int>("passTriggers"); //bitmask of triggers that have passed, see: llllTree->GetUserInfo()->Print() for the list of triggers
  //form a bitmask for the triggers that we will look at, based on the run number
  int triggerMask = (RunNumber<=284484)*435 + (RunNumber<=300287)*76 + (RunNumber>=296639)*44032 + (RunNumber>=296639&&RunNumber<=302393)*65536 + 20992;
 
  ///Trigger
  if(!(passTriggers&triggerMask)) return NEXTEVENT;  chanInfo->Fill(mc_channel_number,"Trigger",evtWeight);
  myHist->Fill(4,evtWeight); 
  
  ///***** Quadruplet level cuts ******
  
  CamVector* ls = evt.getVector("truth_l"); //the leptons
  CamVector* lls = evt.getVector("truth_ll"); //the dileptons
  CamVector* lllls = evt.getVector("truth_llll"); //the quadruplets

  // for(auto llll: *lllls){ if(!llll.get<bool>("truePair")) continue;}
  CamObject* selected_truth_llll = 0; //will point this at our selected quadruplet, if we find one
  
  int cfCount=0; //used so that each event only contributes once
  for(auto& truth_llll : *lllls) {
   
    ///SFOS
    if(truth_llll.get<int>("charge")!=0 || truth_llll.get<int>("dCharge")!=0) continue;
    // if(cfCount<1) {cfCount++;  myHist->Fill(5,evtWeight);}
     if(cfCount<1) {cfCount++; chanInfo->Fill(mc_channel_number,"SFOS",evtWeight); myHist->Fill(5,evtWeight);}
    ///Not Overlap removed leptons by other leptons
    //bits are: (m=muon, e=electron, j=jet. b=out-of-volume jet cleaning jet) (xy = x removed by y)
    //1 = mj
    //2 = mm
    //4 = me
    //8 = ej
    //16 = em
    //32 = ee
    //64 = mb
    //128 = eb
    //so we want 2+4+16+32 = 54
    //if(truth_llll.get<char>("overlaps")&54) continue;  if(cfCount<2) {cfCount++; chanInfo->Fill(mc_channel_number,"NotOverlaps",evtWeight);myHist->Fill(6,evtWeight);}
    
    ///kinematic cuts
    if(ls->at(truth_llll.get<int>("l1")).Pt()<20000. || 
        ls->at(truth_llll.get<int>("l2")).Pt()<15000. || 
       ls->at(truth_llll.get<int>("l3")).Pt()<10000.) continue; if(cfCount<2) {cfCount++; chanInfo->Fill(mc_channel_number,"Kinematic",evtWeight);myHist->Fill(6,evtWeight);}
    
    ///trigger matching
    // if(!(truth_llll.get<int>("triggerMatched")&triggerMask)) continue; if(cfCount<4) {cfCount++; chanInfo->Fill(mc_channel_number,"TriggerMatched",evtWeight); myHist->Fill(8,evtWeight);}
  
    ///leading pair *not* worse than loose
    // if( ls->at( lls->at(truth_llll.get<int>("truth_ll1")).get<int>("truth_l1") ).get<int>("quality") >=3 ) continue;
    // if( ls->at( lls->at(truth_llll.get<int>("truth_ll1")).get<int>("truth_l2") ).get<int>("quality") >=3 ) continue; 
    // if(cfCount<5) {cfCount++; chanInfo->Fill(mc_channel_number,"ElQuality",evtWeight);myHist->Fill(9,evtWeight);}
    
    ///not more than 1 CT or SA muon
    // if(truth_llll.get<int>("nCTorSA")>=2) continue; if(cfCount<6) {cfCount++; chanInfo->Fill(mc_channel_number,"MuQuality",evtWeight);myHist->Fill(10,evtWeight);}
  
    ///delta R > 0.1 (0.2) for same (opposite) flavour leptons in quadruplet
    if(truth_llll.get<double>("min_sf_dR")<=0.1 || truth_llll.get<double>("min_of_dR")<=0.2) continue; 
    if(cfCount<3) {cfCount++; chanInfo->Fill(mc_channel_number,"DeltaR",evtWeight);myHist->Fill(7,evtWeight);}
    
    selected_truth_llll = &truth_llll;
    break; //stop looking for quadruplets
  }
  
  if(!selected_truth_llll) return NEXTEVENT; 
  
  ///***** Event level cuts ******
 
  ///FixedCutLoose isolation
  //4 bits, each are for the leading,subleading,subsubleading,last lepton (leading=most significant)
  //all must be '1': 1111 = 15
  // if(selected_truth_llll->get<char>("truth_l_isIsolFixedCutLoose")!=15) return NEXTEVENT; chanInfo->Fill(mc_channel_number,"Isolation",evtWeight);
  // myHist->Fill(8,evtWeight);



  ///Electron quality (All leptons loose ID or better)
  // if(ls->at(selected_truth_llll->get<int>("truth_l1")).get<int>("quality")>=3 ||
  // ls->at(selected_truth_llll->get<int>("truth_l2")).get<int>("quality")>=3 ||
  // ls->at(selected_truth_llll->get<int>("truth_l3")).get<int>("quality")>=3 ||
  // ls->at(selected_truth_llll->get<int>("truth_l4")).get<int>("quality")>=3)  return NEXTEVENT; chanInfo->Fill(mc_channel_number,"ElectronID",evtWeight); myHist->Fill(13,evtWeight);
     
     
  ///Impact Parameter
  // if(selected_truth_llll->get<double>("max_el_d0Sig")>=5)  return NEXTEVENT; 
  // if(selected_truth_llll->get<double>("max_mu_d0Sig")>=3)  return NEXTEVENT; chanInfo->Fill(mc_channel_number,"ImpactParameter",evtWeight);myHist->Fill(14,evtWeight);

  double m12 = lls->at(selected_truth_llll->get<int>("ll1")).M();
  double m34 = lls->at(selected_truth_llll->get<int>("ll2")).M();
  double m32 = lls->at(selected_truth_llll->get<int>("alt_ll1")).M();
  double m14 = lls->at(selected_truth_llll->get<int>("alt_ll2")).M();

  ///Quarkonia Veto
  if( fabs(m12 - 10000.)<1000. ||
      fabs(m34 - 10000.)<1000. ||
      fabs(m32 - 10000.)<1000. ||
      fabs(m14 - 10000.)<1000. ||
      fabs(m12 - 3000.)<1000. ||
      fabs(m34 - 3000.)<1000. ||
      fabs(m32 - 3000.)<1000. ||
      fabs(m14 - 3000.)<1000. )  return NEXTEVENT; chanInfo->Fill(mc_channel_number,"QVeto",evtWeight);myHist->Fill(8,evtWeight);

  ///H Window
  if( selected_truth_llll->M()<115000. || selected_truth_llll->M()>130000. ) return NEXTEVENT;
  //myHist->Fill(m12,evtWeight);
  // chanInfo->Fill(mc_channel_number,"HWindow",evtWeight);
  
  ///Z Veto
  
  if( m12 > 64000. || m34 > 64000. || m32 > 75000. || m14 > 75000. ) return NEXTEVENT; chanInfo->Fill(mc_channel_number,"ZVeto",evtWeight);myHist->Fill(9,evtWeight);

  ///Loose SR
  if( m12 <10000.  || m34 < 10000. ) return NEXTEVENT;  chanInfo->Fill(mc_channel_number,"LooseSR",evtWeight);myHist->Fill(10,evtWeight);


  ///Medium SR
  if( fabs( m12 - m34 ) > 10000. ) return NEXTEVENT; chanInfo->Fill(mc_channel_number,"MediumSR",evtWeight);myHist->Fill(11,evtWeight);
  
  ///Tight SR 

  if( fabs( m12 - m_massPoints[mc_channel_number]*1000. ) > 5000. ||
      fabs( m34 - m_massPoints[mc_channel_number]*1000. ) > 5000. ) return NEXTEVENT; chanInfo->Fill(mc_channel_number,"TightSR",evtWeight);myHist->Fill(12,evtWeight);

   int truth_llll_pdgIdSum = selected_truth_llll->get<int>("pdgIdSum");

   //deltaR12
    double deltaR12 = lls->at(selected_truth_llll->get<int>("ll1")).get<double>("dR");
 
   if(truth_llll_pdgIdSum==44) myHist_DeltaR12_4e_channel->Fill(deltaR12,evtWeight);
  if(truth_llll_pdgIdSum==48) myHist_DeltaR12_2e2m_channel->Fill(deltaR12,evtWeight);
  if(truth_llll_pdgIdSum==52) myHist_DeltaR12_4m_channel->Fill(deltaR12,evtWeight);
//deltaR34
  double deltaR34 = lls->at(selected_truth_llll->get<int>("ll2")).get<double>("dR");
  if(truth_llll_pdgIdSum==44) myHist_DeltaR34_4e_channel->Fill(deltaR34,evtWeight);
  if(truth_llll_pdgIdSum==48) myHist_DeltaR34_2e2m_channel->Fill(deltaR34,evtWeight);
  if(truth_llll_pdgIdSum==52) myHist_DeltaR34_4m_channel->Fill(deltaR34,evtWeight);

  return StatusCode::SUCCESS;
}



StatusCode ZdZdPlottingAlg::beginInputFile() { 
  ATH_MSG_INFO("Processing " << currentFile()->GetName() << "...");
  return StatusCode::SUCCESS;
}


