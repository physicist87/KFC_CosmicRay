# KFC_CosmicRay
first do :
source /cvmfs/sft.cern.ch/lcg/views/LCG_102/x86_64-centos7-gcc11-opt/setup.sh

Second, make Ntuples :
cd NtupleMaker
modify run_test.sh

Third, make List files:
move to NtupleList directory
python filelist.py

Forth, Check Wave form:
in Analysis_v3, there are codes for saving Waveform.

Forth, Check Avg. time structure form:
in Analysis_v3, there are codes for running Avg. time. structure

Fifth, Check int.ADC(or PeakADC).
in Analysis_v3, there are codes for running Int/Peak ADC                                                                
