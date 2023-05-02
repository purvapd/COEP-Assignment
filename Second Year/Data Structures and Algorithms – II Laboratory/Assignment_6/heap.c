#include <stdio.h>
#include <stdlib.h>

typedef struct max_heap {
    int* data;
    int size;
    int capacity;
} max_heap;

max_heap* create_max_heap() {
    max_heap* heap = malloc(sizeof(max_heap));
    heap->data = malloc(sizeof(int));
    heap->size = 0;
    heap->capacity = 1;
    return heap;
}

void destroy_max_heap(max_heap* heap) {
    free(heap->data);
    free(heap);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(max_heap* heap, int value) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->data = realloc(heap->data, heap->capacity * sizeof(int));
    }

    heap->data[heap->size] = value;
    int index = heap->size;
    heap->size++;

    while (index > 0 && heap->data[index] > heap->data[(index - 1) / 2]) {
        swap(&heap->data[index], &heap->data[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

int delete_max(max_heap* heap) {
    if (heap->size == 0) {
        printf("Error: Cannot delete from an empty heap.\n");
        return -1;
    }

    int value = heap->data[0];
    heap->size--;

    if (heap->size > 0) {
        heap->data[0] = heap->data[heap->size];
        int index = 0;

        while (1) {
            int left_child = 2 * index + 1;
            int right_child = 2 * index + 2;
            int max_child = index;

            if (left_child < heap->size && heap->data[left_child] > heap->data[max_child]) {
                max_child = left_child;
            }

            if (right_child < heap->size && heap->data[right_child] > heap->data[max_child]) {
                max_child = right_child;
            }

            if (max_child != index) {
                swap(&heap->data[index], &heap->data[max_child]);
                index = max_child;
            } else {
                break;
            }
        }
    }

    return value;
}

int main() {
    max_heap* heap = create_max_heap();

    printf("Insert the 10 in to the heap.\n");
    insert(heap, 10);

    printf("Insert the 5 in to the heap.\n");
    insert(heap, 5);

    printf("Insert the 20 in to the heap.\n");
    insert(heap, 20);

    printf("Insert the 30 in to the heap.\n");
    insert(heap, 30);

    printf("\n");

    printf("Delete the max element from heap:-\n");
    printf("Deleted %d from heap. \n", delete_max(heap));

    printf("Delete the max element from heap:-\n");
    printf("Deleted %d  from heap. \n", delete_max(heap));

    printf("Delete the max element from heap:-\n");
    printf("Deleted %d  from heap. \n", delete_max(heap));

    printf("Delete the max element from heap:-\n");
    printf("Deleted %d  from heap. \n", delete_max(heap));

    printf("Delete the max element from heap:-\n");
    printf("Deleted %d  from heap.\n", delete_max(heap));

    destroy_max_heap(heap);
    return 0;
}
