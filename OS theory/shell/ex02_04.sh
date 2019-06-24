#!/bin/bash
read bline
read aline
echo $bline
while [ $bline -lt $aline ]
	do 
		bline=`expr $bline + 1`
		echo "$bline"
	done
