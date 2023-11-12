/*
histogram.c - creates a histogram based on inputs

input: int
output: list with * for amount

usage: ./histogram [list on nums seperated by space] (ctrl d to stop)

Grant Bellotti, 1939767, gbellott@ucsc.edu
*/

#include <stdio.h>
#include <stdlib.h>

#define NUM_BINS 16

void print_histogram(int bins[], int bin_size, int range) {
    for (int i = 0; i < NUM_BINS; i++) { // all the bins
        printf("[%3d:%3d] ", i * bin_size, (i + 1) * bin_size - 1);
        for (int j = 0; j < bins[i]; j++) { // all the * in each bin
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int bins[NUM_BINS] = {0};  // bin counts
    int bin_size = 1;
    int range = bin_size * NUM_BINS;

    printf("16 bins of size %d for range [0,%d)\n", bin_size, range);

    int num;
    while (scanf("%d", &num) != EOF) {

        if (num < 0) { // checks if negative
            continue;
        }

        while (num >= range) { //check if in range, if it is, doubles bin size
            bin_size *= 2; 
            range = bin_size * NUM_BINS;
            for (int i = 0; i < NUM_BINS / 2; i++) { // compresses bins
                int replace_num = bins[2 * i] + bins[2 * i + 1];
                bins[2 * i] = 0;    
                bins[2 * i + 1] = 0;
                bins[i] = replace_num;     

            }
            printf("16 bins of size %d for range [0,%d)\n", bin_size, range);
        }

        // determine the bin for the current number
        int bin = num / bin_size;

        // increase corresponding bin
        bins[bin]++;
        
    }
    
    // print the histogram
    print_histogram(bins, bin_size, range);

    return 0;
}
