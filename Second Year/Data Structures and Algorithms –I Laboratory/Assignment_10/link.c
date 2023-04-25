#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Set {
    Node* head;
    int size;
} Set;

// Function to create an empty set
Set* create_set() {
    Set* set = (Set*)malloc(sizeof(Set));
    set->head = NULL;
    set->size = 0;
    return set;
}

// Function to check if an element is in the set
int contains(Set* set, int element) {
    Node* current = set->head;
    while (current != NULL) {
        if (current->data == element) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// Function to insert an element into the set
void insert(Set* set, int element) {
    if (!contains(set, element)) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = element;
        new_node->next = set->head;
        set->head = new_node;
        set->size++;
    }
}

// Function to do a union of two sets and return the result as a set
Set* union_set(Set* set1, Set* set2) {
    Set* result = create_set();
    Node* current = set1->head;
    while (current != NULL) {
        insert(result, current->data);
        current = current->next;
    }
    current = set2->head;
    while (current != NULL) {
        insert(result, current->data);
        current = current->next;
    }
    return result;
}

// Function to print the elements of the set
void print_set(Set* set) {
    Node* current = set->head;
    printf("{");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("}\n");
}

// Function to free the memory used by the set
void destroy_set(Set* set) {
    Node* current = set->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(set);
}

int main() {
    Set* set1 = create_set();
    insert(set1, 1);
    insert(set1, 2);
    insert(set1, 3);
    printf("Set 1: ");
    print_set(set1);

    Set* set2 = create_set();
    insert(set2, 2);
    insert(set2, 3);
    insert(set2, 4);
    printf("Set 2: ");
    print_set(set2);

    Set* set3 = union_set(set1, set2);
    printf("Set 3 (union of set 1 and set 2): ");
    print_set(set3);

    destroy_set(set1);
    destroy_set(set2);
    destroy_set(set3);
    return 0;
}
