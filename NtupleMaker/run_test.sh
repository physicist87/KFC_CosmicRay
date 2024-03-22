#!/bin/bash
mkdir -p output
#for (( c=5660; c<=5685; c++ ))
#for (( c=5696; c<=5697; c++ ))
#for (( c=5698; c<=5698; c++ ))
#for (( c=5659; c<=5685; c++ ))
#do
#	echo "./Produce_Ntuple $c 7 output..."
#	./Produce_Ntuple $c 7 v1_CosmicTest_Ntuple KFC 
#done

for (( c=5686; c<=5698; c++ ))
do
	echo "./Produce_Ntuple $c 11 output..."
	./Produce_Ntuple $c 11 v1_CosmicTest_Ntuple KFC 
done 
for (( c=105; c<=105; c++ ))
do
	
	echo "./Produce_Ntuple $c 7 output..."
	./Produce_Ntuple $c 7 v2_CosmicTest_Ntuple Cosmic 
	#./Produce_Ntuple $c 11 v1_output Cosmic 
	#echo "Welcome $c times..."
done
