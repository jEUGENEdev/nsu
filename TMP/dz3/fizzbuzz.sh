#!/bin/bash

for i in {1..100}
do
	if [[ $(($i % 3)) = 0 && $(($i % 5)) = 0 ]]
	then
		echo FizzBazz
	elif [[ $(($i % 5)) = 0 ]]
	then
		echo Bazz
	elif [[ $(($i % 3)) = 0 ]]
	then
		echo Fizz
	fi
done
