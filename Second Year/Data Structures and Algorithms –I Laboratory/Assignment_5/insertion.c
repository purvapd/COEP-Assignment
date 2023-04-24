#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

int main()
{
    int counts[] = {10000,100000}; // counts of integers in each file
    int num_files = sizeof(counts) / sizeof(counts[0]); // number of files to sort

    for (int i = 0; i < num_files; i++) {
        int count = counts[i];
        char filename[50];
        sprintf(filename, "data_%d.txt", count); // create filename for current count

        FILE *fp = fopen(filename, "r"); // open file for reading

        if (fp == NULL) {
            printf("Error opening file: %s\n", filename);
            return 1;
        }

        int *arr = malloc(count * sizeof(int)); // allocate memory for array

        for (int j = 0; j < count; j++) {
            fscanf(fp, "%d", &arr[j]); // read integer from file into array
        }

        fclose(fp); // close file

        clock_t start = clock(); // start timer

        insertion_sort(arr, count); // sort the array

        clock_t end = clock(); // end timer

        double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC; // calculate time taken

        printf("Time taken to sort %d integers using Insertion Sort: %lf seconds\n", count, time_taken);

        free(arr); // free memory allocated for array
    }

    return 0;
}
