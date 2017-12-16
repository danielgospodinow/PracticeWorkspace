#!/bin/bash

destinationFolder=$1

for f in ${destinationFolder}*.cpp; do
    echo '' > $f
	(echo ; cat cppComment.txt) > $f
	sed -i '1d' $f
	echo $'\n\n' >> $f
done
