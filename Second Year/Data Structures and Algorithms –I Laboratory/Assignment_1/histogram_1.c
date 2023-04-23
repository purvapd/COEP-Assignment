#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 128

// Hash table node structure
typedef struct node {
    int key;
    int value;
    struct node* next;
} node_t;

// Hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Create a new node with the given key and value
node_t* create_node(int key, int value) {
    node_t* node = (node_t*) malloc(sizeof(node_t));
    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;
}

// Insert a new key-value pair into the hash table
void insert(node_t** table, int key, int value) {
    int index = hash(key);
    node_t* node = create_node(key, value);
    node->next = table[index];
    table[index] = node;
}

// Lookup the value associated with the given key in the hash table
int lookup(node_t** table, int key) {
    int index = hash(key);
    node_t* node = table[index];
    while (node != NULL) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    return 0;
}

// Increment the frequency of the given key in the hash table
void increment(node_t** table, int key) {
    int index = hash(key);
    node_t* node = table[index];
    while (node != NULL) {
        if (node->key == key) {
            node->value++;
            return;
        }
        node = node->next;
    }
    insert(table, key, 1);
}

int main() {
    node_t* table[TABLE_SIZE] = {NULL};

    // read input and count the frequency of each character
    int c;
    while ((c = getchar()) != EOF) {
        increment(table, c);
    }

    // print the histogram
    printf("Histogram of character frequencies:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != NULL) {
            printf("%c: ", i);
            for (int j = 0; j < table[i]->value; j++) {
                putchar('*');
            }
            putchar('\n');
        }
    }

    // free memory allocated for hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        node_t* node = table[i];
        while (node != NULL) {
            node_t* next = node->next;
            free(node);
            node = next;
        }
    }

    return 0;
}


