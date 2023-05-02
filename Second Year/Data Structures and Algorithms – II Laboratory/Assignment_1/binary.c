#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Node definition
typedef struct node {
    int data;
    char str[100];
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node
Node* createNode(int data, char* str) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    strcpy(newNode->str, str);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the tree
Node* insert(Node* root, int data, char* str) {
    if (root == NULL) {
        return createNode(data, str);
    }
    if (data < root->data) {
        root->left = insert(root->left, data, str);
    }
    else {
        root->right = insert(root->right, data, str);
    }
    return root;
}

// Function to search for the maximum value in the tree
int findMax(Node* root) {
    if (root == NULL) {
        printf("The tree is empty.\n");
        return -1;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

// Function to search for a string in the tree and return a pointer to the node
Node* search(Node* root, char* str) {
    if (root == NULL) {
        printf("The tree is empty.\n");
        return NULL;
    }
    while (root != NULL) {
        if (strcmp(str, root->str) < 0) {
            root = root->left;
        }
        else if (strcmp(str, root->str) > 0) {
            root = root->right;
        }
        else {
            return root;
        }
    }
    printf("The string %s is not in the tree.\n", str);
    return NULL;
}

// Function to print the binary tree in a tree-like structure
void printTree(Node* root, int space) {
    if (root == NULL) {
        return;
    }
    space += 5;
    printTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d %s\n", root->data, root->str);
    printTree(root->left, space);
}

// Function to perform preorder traversal without using recursion
void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    Node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        Node* current = stack[top--];
        printf("%d %s ", current->data, current->str);
        if (current->right != NULL) {
            stack[++top] = current->right;
        }
        if (current->left != NULL) {
            stack[++top] = current->left;
        }
    }
    printf("\n");
}

// Main function for testing
int main() {
    Node* root = NULL;
    root = insert(root, 20, "twenty");
    insert(root, 10, "ten");
    insert(root, 30, "thirty");
    insert(root, 5, "five");
    insert(root, 15, "fifteen");
    insert(root, 25, "twenty-five");
    insert(root, 35, "thirty-five");

    printf("The binary search tree:\n");
    printTree(root, 0);
    printf("\n");

    printf("The maximum value in the tree is %d.\n", findMax(root));

    Node* searchResult = search(root, "thirty");
    if (searchResult != NULL) {
        printf("The string %s is found in the tree.\n", searchResult->str);
    }

    printf("Preorder of the Tree is :- \n");
    preorder(root);
    return 0;
}