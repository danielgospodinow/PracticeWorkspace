#!/bin/bash

#Parameter 1- dir
#Parameter 2- number of tasks
#Parameter 3- faculty number

destinationFolder=$1
numberOfTasks=$2
fn=81531

for i in `seq 1 $numberOfTasks`;
do
	touch ${destinationFolder}fn${fn}_prob${i}_CC.cpp
done   
