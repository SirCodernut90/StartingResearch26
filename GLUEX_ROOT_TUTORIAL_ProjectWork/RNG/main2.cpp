#include "RandomReal.h"

#include <TH1F.h>
#include <TFile.h>
#include <TTree.h>
#include <cmath>

int main() {
	int N = 100000;
	TFile *oFile = TFile::Open("AcceptReject.root", "RECREATE");
	TTree *tree = new TTree("tree", "Accept/Reject");
	double x;
	tree->Branch("x", &x);

	TH1F *Hist = new TH1F("AcceptedX", ";x", 100, 0, 8);

	for (int n = 1; n <= N; n++) {
		x = RandomReal(0,8);
		double y = RandomReal(0,1);
		
		while(y > exp(-x/2)) {
			x = RandomReal(0,8);
			y = RandomReal(0,1);
		}
		
		tree->Fill();
		Hist->Fill(x);
	}

	oFile->Write();
	oFile->Close();

	return 0;
}
