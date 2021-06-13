#!/bin/bash
for file in `ls *.fin`
do
name=`echo $file | cut -c1-5`
echo $name
mv -- "${name}.dat" "${name%}.success"
rm $file
done
