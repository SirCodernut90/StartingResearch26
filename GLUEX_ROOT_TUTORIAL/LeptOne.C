#define LeptOne_cxx
#include "LeptOne.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

const double ElectronMass = 5.109989461e-4;

TLorentzVector p1, p2, BeamP4;

TFile* oFile = TFile::Open("Histograms.root","RECREATE");

TH1F* Hist_W2e = new TH1F("W2e", ";Invariant Mass (Gev/c^2)", 200, 0, 1.4);

TH1F* Hist_t = new TH1F("t", ";Momentum Transfer Squared (GEV/c)^2", 200, 0, 0.14);

void LeptOne::Loop()
{
//   In a ROOT session, you can do:
//      root> .L LeptOne.C
//      root> LeptOne t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      p1.SetXYZM(p1x, p1y, p1z, ElectronMass);
	p2.SetXYZM(p2x, p2y, p2z, ElectronMass);
	BeamP4.SetXYZT(0, 0, 8.78, 8.78);
	
	float W2e = sqrt( (p1 + p2).Mag2() );
	float t = (BeamP4 - p1 - p2).Mag2();

	Hist_W2e->Fill(W2e);
	Hist_t->Fill(-t);
   }

   oFile->Write();
   oFile->Close();
}
