#include "RandomReal.h"
#include <TH1F.h>
#include <TFile.h>

int main() {
	int n = 10000;
	
	TFile *oFile = TFile::Open("RandomNumbers.root", "RECREATE");

	TH1F *Hist = new TH1F("RandomNumbers", ";Random Number", 1000, 0, 10);

	for (int i = 0; i < n; i++) {
		double number = RandomReal(0, 10);
		Hist->Fill(number);		
	}

	oFile->Write();
	oFile->Close();

	return 0;
}
