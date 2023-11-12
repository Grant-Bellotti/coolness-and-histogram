#!/usr/bin/bash #
#
#testing.sh - test script for histogram.c
#
#input: c file
#output: output of file
#
#usage: bash -v testing.sh >& testing.out
#
#Grant Bellotti, 1939767, gbellott@ucsc.edu
make 

echo 3 -4 5 1 7 0 8 0 15 12 3 5 3 3 3 3 3 | ./histogram

echo 3 -4 5 1 7 0 8 0 15 12 3 5 18 19 20 30 7 12 50 34 32 19 44 | ./histogram

echo 150 | ./histogram

echo 1 2 3 4 5 6 7 8 9 10 17 18 20 34 37 50 80 90 100 129 200 230 | ./histogram

echo 255 | ./histogram

echo {1..255} | ./histogram

echo {1..16} 150 | ./histogram

echo | ./histogram

echo -4 -5 6 | ./histogram

make clean