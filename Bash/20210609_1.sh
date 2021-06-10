#!/bin/bash
read -p “What file do you want to test? “ filename
if [ ! -e “$filename” ]; then
echo “The file does not exist.”fi
ls -ld “$filename”
if [ -r “$filename” ]; then
echo “$filename is readable.”
fi
if [ -w “$filename” ]; then
echo “$filename is writeable”
fi
if [ -x “$filename” ]; then
echo “$filename is executable”
fi
