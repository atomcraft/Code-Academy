#!/bin/bash
#read path from file
while read DIR
do
	echo $DIR
	#cd $DIR
#`find $DIR -name *.DAT`
	for file in `ls ${DIR}/*.fin`
	do
		name=`echo $file | cut -f 1 -d'.'`
		echo $name
		mv "${name}.dat" "${name%}.SUCCESS"
		rm $file
	done
done
