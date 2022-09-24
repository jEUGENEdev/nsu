#!/bin/bash

suffix=$1

shift 1

for i in "$@"
do
	mv "$i" "$i$suffix"
done
