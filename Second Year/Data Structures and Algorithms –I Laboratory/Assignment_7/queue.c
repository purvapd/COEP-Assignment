#include <stdlib.h>
#include "queue.h"

queue_t* queue_create() {
    queue_t* q = malloc(sizeof(queue_t));
    if (q == NULL) {
        return NULL;
    }
    q->next = NULL;
    return q;
}

void queue_destroy(queue_t* q) {
    while (q != NULL) {
        queue_t* temp = q;
        q = q->next;
        free(temp);
    }
}

int queue_enqueue(queue_t* q, char c) {
    while (q->next != NULL) {
        q = q->next;
    }
    queue_t* new_node = malloc(sizeof(queue_t));
    if (new_node == NULL) {
        return 0;
    }
    new_node->data = c;
    new_node->next = NULL;
    q->next = new_node;
    return 1;
}

int queue_dequeue(queue_t* q, char* c) {
    if (q->next == NULL) {
        return 0;
    }
    queue_t* temp = q->next;
    *c = temp->data;
    q->next = temp->next;
    free(temp);
    return 1;
}
