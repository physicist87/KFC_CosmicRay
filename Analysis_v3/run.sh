#!/bin/bash

#for (( c=5660; c<=5660; c++ ))
#for (( i=5698; i<5699; i++ ))
#for (( i=107; i<133; i++ ))
#for (( i=107; i<108; i++ ))
#for (( i=110; i<111; i++ ))
#for (( i=111; i<130; i++ ))
#for (( i=185; i<189; i++ ))
#for (( i=190; i<220; i++ ))
#for (( i=226; i<271; i++ ))
#for (( i=220; i<271; i++ ))
for (( i=326; i<327; i++ ))
do
   #./DRC_Study -studyType Waveform -inputList input_Run${i}_MID11.list -outputName waveform_${i}_MID11 -config Run5695-Run5699.config 
   #./DRC_Study -studyType Waveform -inputList input_Run${i}_MID11.list -outputName waveform_${i}_MID11 
   #./DRC_Study -studyType IntADC -inputList input_Run${i}_MID11.list -outputName result_${i}_MID11.root -config Run5695-Run5699.config 
   #./Asym_Calc -channel MuMu -studyName SystematicStudy_v13 -obs O1 -outputDir SystematicStudy_v13/MuMu/ -inputDAT SystematicStudy_v13/MuMu/Asymmetry_dimu_SystematicStudy_v13.dat -config SystematicStudy_v13/MuMu/CP_Inputs_dimu_SystematicStudy_v13.config -systName none  
   #./DRC_Study -studyType AvgTimeStr -inputList input_Run${i}_MID11.list -outputName result_${i}_MID11.root -config Run5695-Run5699.config
                                               # input_v2_CosmicTest_Ntuple_Run105_MID7 
   #./DRC_Study -studyType AvgTimeStr -inputList input_v2_CosmicTest_Ntuple_Run${i}_MID7.list -outputName result_v2_CosmicTest_${i}_MID7.root -config SRun105-106.config 
   #./DRC_Study -studyType AvgTimeStr -inputList input_v2_CosmicTest_Ntuple_Run${i}_MID7.list -outputName result_v2_CosmicTest_${i}_MID7.root 
   #./DRC_Study -studyType IntADC -inputList input_v2_CosmicTest_Ntuple_Run${i}_MID7.list -outputName result_v2_CosmicTest_${i}_MID7.root -config Calib.cfg 
   #./DRC_Study -studyType IntADC -inputList input_v2_CosmicTest_Ntuple_Run${i}_MID7.list -outputName result_v2_CosmicTest_${i}_MID7.root -config Calib_20240326.cfg 
   #./DRC_Study -studyType Waveform -inputList input_v2_CosmicTest_Ntuple_Run${i}_MID7.list -outputName result_v2_CosmicTest_${i}_MID7  -config Calib_20240326.cfg
   ./DRC_Study -studyType AvgTimeStr -inputList input_v2_CosmicTest_Ntuple_Run${i}_MID7.list -outputName result_v2_CosmicTest_${i}_MID7.root 
   #./DRC_Study -studyType OverWaveform -inputList input_v2_CosmicTest_Ntuple_Run${i}_MID7.list -outputName result_v2_CosmicTest_${i}_MID7.root 
   ./DRC_Study -studyType IntADC -inputList input_v2_CosmicTest_Ntuple_Run${i}_MID7.list -outputName result_v2_CosmicTest_${i}_MID7.root -config MuonVetoCalib.cfg 
done
