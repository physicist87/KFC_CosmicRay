#!/bin/bash

#for (( c=5660; c<=5660; c++ ))
mkdir -p output
for (( i=5698; i<5699; i++ ))
do
   #./DRC_Study -studyType Waveform -inputList input_Run${i}_MID11.list -outputName waveform_${i}_MID11 -config Run5695-Run5699.config 
   #./DRC_Study -studyType Waveform -inputList input_Run${i}_MID11.list -outputName waveform_${i}_MID11 
   #./DRC_Study -studyType IntADC -inputList input_Run${i}_MID11.list -outputName result_${i}_MID11.root -config Run5695-Run5699.config 
   #./Asym_Calc -channel MuMu -studyName SystematicStudy_v13 -obs O1 -outputDir SystematicStudy_v13/MuMu/ -inputDAT SystematicStudy_v13/MuMu/Asymmetry_dimu_SystematicStudy_v13.dat -config SystematicStudy_v13/MuMu/CP_Inputs_dimu_SystematicStudy_v13.config -systName none  
   ./DRC_Study -studyType AvgTimeStr -inputList input_Run${i}_MID11.list -outputName result_${i}_MID11.root -config Run5695-Run5699.config 
done
