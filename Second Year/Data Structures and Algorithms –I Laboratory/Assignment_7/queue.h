#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue_t {
    char data;
    struct queue_t* next;
} queue_t;

queue_t* queue_create();
void queue_destroy(queue_t* q);
int queue_enqueue(queue_t* q, char c);
int queue_dequeue(queue_t* q, char* c);

#endif /* QUEUE_H */
