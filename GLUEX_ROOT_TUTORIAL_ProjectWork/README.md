## Files

### ROOT / C++ analysis

- `readRoryVectors.C` — ROOT macro used to read the input vector data and
  create a ROOT file containing the data in a `TTree`; provided to me.

- `LeptOne.C` — Main ROOT analysis code for the lepton event data. It
  constructs four-momenta for the outgoing electrons and calculates the
  invariant mass and momentum transfer squared.

- `LeptOne.h` — Header file associated with `LeptOne.C`.

- `lepton_v18.dat` — Input lepton event data provided for the tutorial.

- `GetBremDistFromHere.root` — ROOT file provided as part of the tutorial.

### RNG

The `RNG/` directory contains the random-number generation and Monte Carlo
accept/reject work.

- `RandomReal.h` — Header declaring the `RandomReal()` function.

- `RandomReal.cpp` — Implementation of `RandomReal()`, using GSL to generate
  uniform random numbers over an arbitrary range.

- `main.cpp` — 7.3.2 program for generating uniform random numbers and
  storing them in a ROOT histogram.

- `main2.cpp` — 7.3.3 program implementing Monte Carlo accept/reject
  sampling for a distribution proportional to `exp(-x/2)`.

- `results.txt` — Exponential fit parameters and execution-time results from
  the accept/reject simulation.

### Generated files

The files below are generated locally when the programs are run and are
excluded from uploaded files:

- `Histograms.root`: Root file that has the histograms for 'LeptOne.C'
- `lepton_v18.dat.root`: Root file built from lepton .dat file
- `RandomNumbers.root`: Root output from the uniform random-number simulation
- `AcceptReject.root`: Root output form the accept/reject part, has the accepted values in a TTree and a histogram.
- `RNGProgram`: Executable for main.cpp
- `AcceptReject`: Executable for main2.cpp 
