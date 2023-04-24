#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quick_sort(int arr[], int low, int high)
{
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main()
{
    int counts[] = { 10000, 100000}; // counts of integers in each file
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

        quick_sort(arr, 0, count - 1); // sort the array

        clock_t end = clock(); // end timer

        double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC; // calculate time taken

        printf("Time taken to sort %d integers using Quick Sort: %lf seconds\n", count, time_taken);

        free(arr); // free memory allocated for array
    }

    return 0;
}
