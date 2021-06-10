#!/bin/bash
gcc task9.c -o rez
source test_data
check_exit_status () {
if [ "$READ" -ne "0" ]
        then
                echo "Error"
        else
                echo "Passed"
        fi
}

for test in "$test_data1"
do
        ./rez $test1 $exp1
        READ=$?
        echo $test1 $exp1
        check_exit_status READ
        ./rez $test2 $exp2
        READ=$?
        echo $test2 $exp2
        check_exit_status READ
	./rez $test3 $exp3
	READ=$?
        echo $test3 $exp3
        check_exit_status READ
        ./rez $test4 $exp4
	READ=$?
        echo $test4 $exp4
        check_exit_status READ
		        
done
exit 0
