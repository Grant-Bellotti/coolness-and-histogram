/*
coolness.c - calculates coolness based on inputs

input: int or double
output: calculations

usage: ./coolness [temperature] [wind speed]

Grant Bellotti, 1939767, gbellott@ucsc.edu
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_input_error() {
    printf("Error: Coolness. Acceptable input values are -99<=T<=50 and 0.5<=V.\n");
    exit(1);
}

void print_usage_error() {
    printf("Usage: ./coolness [temperature] [wind speed]\n");
    exit(1);
}

double calculate_coolness(double t, double v) {
    return (35.74 + (0.6215 * t) - (35.75 * pow(v, 0.16)) + ((0.4275 * t) * pow(v, 0.16)));
}

int main(int argc, char *argv[]) {
    if (argc == 1) { // no arguement provided
        printf("Temp\tWind\tCoolness\n");
        for (double temperature = -10.0; temperature <= 40.0; temperature += 10.0) {         
            for (double windspeed = 5.0; windspeed <= 15.0; windspeed += 5.0) {
                double coolness = calculate_coolness(temperature, windspeed);
                printf("%.1lf\t%.1lf\t%.1lf\n", temperature, windspeed, round(coolness * 10.0) / 10.0);
            }
            if (temperature != 40.0) {
                printf("\n");
            }  
        }
        
    } else if (argc == 2) { // one arguement provided
        double temperature = atof(argv[1]);
        if (temperature < -99 || temperature > 50)
            print_input_error();

        printf("Temp\tWind\tCoolness\n");
        for (double windspeed = 5.0; windspeed <= 15.0; windspeed += 5.0) {
            double coolness = calculate_coolness(temperature, windspeed);
            printf("%.1lf\t%.1lf\t%.1lf\n", temperature, windspeed, round(coolness * 10.0) / 10.0);
        }
    } else if (argc == 3) { // two arguements provided
        double temperature = atof(argv[1]);
        double windspeed = atof(argv[2]);

        if (temperature < -99 || temperature > 50 || windspeed < 0.5)
            print_input_error();

        printf("Temp\tWind\tCoolness\n");
        double coolness = calculate_coolness(temperature, windspeed);
        printf("%.1lf\t%.1lf\t%.1lf\n", temperature, windspeed, round(coolness * 10.0) / 10.0);
    } else { // more than two arguements provided
        print_usage_error();
    }
    
    return 0;
}