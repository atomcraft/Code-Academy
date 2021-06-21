#!/bin/bash
function bubblesort(){
l=${#data[@]}
for i in `seq 0 $l`
do
  for (( j=l; j > i; j-- ))
  do
    if [[ ${data[j-1]} > ${data[j]} ]]
    then
    temp=${data[j]}
    data[j]=${data[j-1]}
    data[j-1]=$temp
  fi
  done
done
}
