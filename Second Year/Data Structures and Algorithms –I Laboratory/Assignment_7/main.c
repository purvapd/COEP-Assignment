#include <stdio.h>
#include "queue.h"

int main() {
    queue_t* q = queue_create();

    queue_enqueue(q, 'a');
    queue_enqueue(q, 'b');
    queue_enqueue(q, 'c');

    char c;
    while (queue_dequeue(q, &c)) {
        printf("%c ", c);
    }
    printf("\n");

    queue_destroy(q);

    return 0;
}
