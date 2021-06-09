#!/usr/bin/bash
if [ -z $1 ]
then
    	echo NO argument on command line provide arguments
        read FILENAMES
else
    	FILENAMES="$@"
        touch $FILENAMES
fi
