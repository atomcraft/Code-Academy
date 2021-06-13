#!/bin/bash
check_exit_status () {
	if [ "$READ" -ne "0" ]
	then
		if [ "$READ" -eq "1" ]
      		then	
        	       	echo "Error reading file"
        	else
        	        echo "Unknown Error"
        	fi
	else
        	echo "Passed"
	fi
}
TEST=$1
gcc task_11.c -o rez
./rez $TEST
READ=$?
echo $TEST
check_exit_status READ


