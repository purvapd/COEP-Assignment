#include <stdio.h>

void remove_duplicates(double arr[], int size);

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    double arr[size];

    printf("Enter %d double values: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%lf", &arr[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%.2lf ", arr[i]);
    }

    remove_duplicates(arr, size);

    printf("\nArray after removing duplicates: ");
    for (int i = 0; i < size; i++) {
        printf("%.2lf ", arr[i]);
    }
    printf("\n");

    return 0;
}

void remove_duplicates(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < size - 1; k++) {
                    arr[k] = arr[k+1];
                }
                size--;
                j--;
            }
        }
    }
}
