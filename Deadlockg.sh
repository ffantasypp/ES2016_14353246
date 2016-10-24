#!/bin/bash
for (( c=1;c<=100;c++ ))
do
	echo "$c times"
	java Deadlock
done
	