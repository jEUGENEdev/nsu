#!/bin/bash

#args
echo "$0 $1 $2 $3 ok"

#cycle
for id in {1..5}
do
	echo hello $id
done

#values
WHAT=`cat /home/administrator/nsu/TMP/file.txt`
echo $WHAT

#condition
if [1 = 1]
then
	echo this 1
else
	echo this not 1
fi
