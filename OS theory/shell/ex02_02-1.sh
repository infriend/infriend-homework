#!/bin/bash
#filename
while [ 1 -lt 2 ]
	do
		read filename
		echo ${filename%.*}
	done
