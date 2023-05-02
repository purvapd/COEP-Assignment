#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a node in the AVL tree
struct node {
    char key[20];
    int height;
    struct node* left;
    struct node* right;
};

// Function to get the height of a node
int height(struct node* n) {
    if (n == NULL) {
        return 0;
    }
    return n->height;
}

// Function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to create a new node with a given key
struct node* newNode(char key[20]) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    strcpy(n->key, key);
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

// Function to perform a right rotation on a node
struct node* rightRotate(struct node* y) {
    struct node* x = y->left;
    struct node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Function to perform a left rotation on a node
struct node* leftRotate(struct node* x) {
    struct node* y = x->right;
    struct node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Function to get the balance factor of a node
int getBalance(struct node* n) {
    if (n == NULL) {
        return 0;
    }
    return height(n->left) - height(n->right);
}

// Function to insert a node into the AVL tree
struct node* insert(struct node* node, char* key, int len) {
    // Perform the normal BST insertion
    if (node == NULL) {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        strncpy(new_node->key, key, len);
        new_node->height = 1;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    if (strcmp(key, node->key) < 0)
        node->left = insert(node->left, key, len);
    else if (strcmp(key, node->key) > 0)
        node->right = insert(node->right, key, len);
    else // key already exists
        return node;

    // Update the height of the current node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor of the current node
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && strcmp(key, node->left->key) < 0)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && strcmp(key, node->right->key) > 0)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && strcmp(key, node->left->key) > 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && strcmp(key, node->right->key) < 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}


// Function to print the AVL tree in inorder traversal
void inorder(struct node* node) {
if (node != NULL) {
inorder(node->left);
printf("%s ", node->key);
inorder(node->right);
}
}

// Driver program to test the AVL tree implementation
int main() {
    struct node* root = NULL;

    // Perform a series of insertions
    root = insert(root, "December", 8);
    root = insert(root, "January", 7);
    root = insert(root, "April", 5);
    root = insert(root, "March", 5);
    root = insert(root, "July", 5);
    root = insert(root, "August", 7);
    root = insert(root, "October", 7);
    root = insert(root, "February", 8);
    root = insert(root, "November", 8);
    root = insert(root, "May", 4);
    root = insert(root, "June", 4);

    // Print the resulting tree
    printf("Inorder traversal of the AVL tree: ");
    inorder(root);

    return 0;
}
