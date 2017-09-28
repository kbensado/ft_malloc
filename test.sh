#!/bin/bash

seed=$1

if [ $seed = 1 ]
	then
		gcc -o test/test0 test/test0.c
		gcc -o test/test1 test/test1.c
		gcc -o test/test2 test/test2.c
		gcc -o test/test3 test/test3.c
		gcc -o test/test3_5 test/test3_5.c
		gcc -o test/test4 test/test4.c
		gcc -o test/test5 test/test5.c -L . -lft_malloc
fi

if [ $seed = 2 ]
	then
		rm -f test/test0
		rm -f test/test1
		rm -f test/test2
		rm -f test/test3
		rm -f test/test3_5
		rm -f test/test4
		rm -f test/test5
fi