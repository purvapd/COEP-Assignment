#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INT 1000000

int main()
{
    srand(time(NULL)); // initialize random number generator

    int counts[] = {10000,100000}; // counts of integers in each file
    int num_files = sizeof(counts) / sizeof(counts[0]); // number of files to generate

    for (int i = 0; i < num_files; i++) {
        int count = counts[i];
        char filename[50];
        sprintf(filename, "data_%d.txt", count); // create filename for current count

        FILE *fp = fopen(filename, "w"); // open file for writing

        if (fp == NULL) {
            printf("Error opening file: %s\n", filename);
            return 1;
        }

        for (int j = 0; j < count; j++) {
            int num = rand() % MAX_INT; // generate random integer between 0 and MAX_INT
            fprintf(fp, "%d ", num); // write integer to file
        }

        fclose(fp); // close file
    }

    printf("Data files generated successfully!\n");

    return 0;
}
