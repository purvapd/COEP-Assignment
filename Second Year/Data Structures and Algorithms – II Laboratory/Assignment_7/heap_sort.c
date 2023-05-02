#include <stdio.h>
#include <stdlib.h>

typedef struct record {
    int key;
    /* other data fields as needed */
} Record;

void heapify(Record arr[], int n, int i, int keyIndex) {
    int largest = i;    // Initialize largest as root
    int left = 2*i + 1; // left child
    int right = 2*i + 2; // right child

    // If left child is larger than root
    if (left < n && arr[left].key > arr[largest].key)
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right].key > arr[largest].key)
        largest = right;

    // If largest is not root
    if (largest != i) {
        // swap root with largest
        Record temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // recursively heapify the affected sub-tree
        heapify(arr, n, largest, keyIndex);
    }
}

void heapSort(Record arr[], int n, int keyIndex) {
    // build max heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i, keyIndex);

    // extract elements from heap one by one
    for (int i = n-1; i >= 0; i--) {
        // move root (maximum element) to end
        Record temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call max heapify on the reduced heap
        heapify(arr, i, 0, keyIndex);
    }
}

int main() {
    // example usage
    Record arr[] = {{10}, {7}, {8}, {9}, {1}, {5}};
    int n = sizeof(arr)/sizeof(arr[0]);
    int keyIndex = 0; // assuming key is in the first field

    printf("Input array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i].key);
    printf("\n");

    heapSort(arr, n, keyIndex);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i].key);
    printf("\n");

    return 0;
}
