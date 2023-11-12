#!/usr/bin/bash #
#
#testing.sh - test script for coolness.c
#
#input: c file
#output: output of file
#
#usage: bash -v testing.sh >& testing.out
#
#Grant Bellotti, 1939767, gbellott@ucsc.edu
make 

./coolness

./coolness 32.0

./coolness -50.0

./coolness 100

./coolness -25.5 10.0

./coolness 32.5 5.0

./coolness 17.5 0.0

./coolness hello 0.0

./coolness -80.5 10.0 

./coolness -85.5 -10.0 

./coolness 32.5 15.0

./coolness 32.5 10.0 3

./coolness 32.5 10.0 3 5

make clean