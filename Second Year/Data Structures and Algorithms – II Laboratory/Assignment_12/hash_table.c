#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct node {
    char key[50];
    int value;
    struct node *next;
} Node;

Node *table[TABLE_SIZE];

// Hash function to determine index in the hash table
int hash(char *key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}

// Insert a new key-value pair into the hash table
void insert(char *key, int value) {
    int index = hash(key);

    Node *new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->key, key);
    new_node->value = value;
    new_node->next = NULL;

    if (table[index] == NULL) {
        table[index] = new_node;
    } else {
        Node *current = table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Search for a value in the hash table by key
int search(char *key) {
    int index = hash(key);
    Node *current = table[index];

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    return -1;
}

int main() {
    // Read records from file and insert into hash table
    FILE *fp = fopen("records.txt", "r");
    char key[50];
    int value;
    while (fscanf(fp, "%s %d", key, &value) != EOF) {
        insert(key, value);
    }
    fclose(fp);

    // Perform searches on user-supplied data
    char search_key[50];
    printf("Enter a key to search for: ");
    scanf("%s", search_key);
    int result = search(search_key);
    if (result != -1) {
        printf("Value for key '%s' is %d\n", search_key, result);
    } else {
        printf("Key '%s' not found in table\n", search_key);
    }

    return 0;
}
