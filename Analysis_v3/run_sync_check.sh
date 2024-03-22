#!/bin/tcsh

set inputlists = ("ttdilep")
set inputlists = ("output_Run859_10" "output_Run885_10" "output_Run896_10" "output_Run897_10" "output_Run898_10" "output_Run900_10")
set inputlists = ("output_Run917_10")
set inputlists = ("output_Run928_10")
set inputlists = ("output_Run929_10")
set inputlists = ("output_Run885_10" "output_Run929_10")
set inputlists = ("output_Run930_10")
set inputlists = ("output_Run931_10")
set inputlists = ("output_Run932_10")
set inputlists = ("output_Run933_10")
set inputlists = ("output_Run934_10")
set inputlists = ("output_Run935_10")
set inputlists = ("output_Run943_10")
set inputlists = ("output_Run946_10")
set inputlists = ("Run5660" "")

#set inputlists = ("dimudataB")

#set dimu_mass_cut_on = ("1")
#set dimu_mass_cut = ("20")

foreach i ( $inputlists )
   
   mkdir -p output

   #./DRCStudy_analysis ${i}.list pedstal_${i}.root 
   ./DRCStudy_analysis input_${i}.list result_${i}.root test.cfg 

end

