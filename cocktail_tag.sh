#!/bin/bash

## This macro is written to combine cocktail MC
## Written by Neeraj Kumar 
## Date 20/12/22

## Locating root files 
dpath1=`pwd`            ## Change it accordingly
rootFiles=("QCMC/combined_root_files/QCMC_2010_1"
    "QCMC/combined_root_files/QCMC_2010_2"
    "QCMC/combined_root_files/QCMC_2011_1"
    "QCMC/combined_root_files/QCMC_2011_2"

	"DpDm/combined_root_files/DpDm_2010"
	"DpDm/combined_root_files/DpDm_2011"
	"RR1S/combined_root_files/RR1S_2010"
	"RR1S/combined_root_files/RR1S_2011"
	"RR2S/combined_root_files/RR2S_2010"
	"RR2S/combined_root_files/RR2S_2011"
	"nonDDbar/combined_root_files/nonDDbar_2010"
	"nonDDbar/combined_root_files/nonDDbar_2011"
	"qqbar/combined_root_files/kkmc_2010"
	"qqbar/combined_root_files/kkmc_2011"
	"ditau/combined_root_files/ditau_2010"
	"ditau/combined_root_files/ditau_2011")

tag=("d0tag")           ##Change it accordingly 

for str in ${rootFiles[@]}; do
    combine+=" $dpath1/$str$tag.root"
    #echo $str$tag".root"
done

echo $combine

echo `hadd $tag"_combine.root" $combine`