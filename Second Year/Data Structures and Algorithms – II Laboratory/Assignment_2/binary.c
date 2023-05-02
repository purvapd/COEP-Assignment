#include <stdio.h>
#include <stdlib.h>

/* Binary tree node */
struct node {
    int data;
    struct node* left;
    struct node* right;
};

/* Function to create a new binary tree node */
struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

/* Function to print leaf nodes */
void print_leaf_nodes(struct node* root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
    }
    print_leaf_nodes(root->left);
    print_leaf_nodes(root->right);
}

/* Function to print non-leaf nodes */
void print_non_leaf_nodes(struct node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return;
    }
    printf("%d ", root->data);
    print_non_leaf_nodes(root->left);
    print_non_leaf_nodes(root->right);
}

/* Function to get the level of a node */
int get_node_level(struct node* root, int data, int level) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == data) {
        return level;
    }
    int l = get_node_level(root->left, data, level+1);
    if (l != 0) {
        return l;
    }
    return get_node_level(root->right, data, level+1);
}

/* Function to print the level of all nodes */
void print_node_levels(struct node* root, int level) {
    if (root == NULL) {
        return;
    }
    printf("%d : %d\n", root->data, level);
    print_node_levels(root->left, level+1);
    print_node_levels(root->right, level+1);
}

/* Driver function */
int main() {
    /* Constructing the binary tree */
    struct node* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    root->right->left = create_node(6);
    root->right->right = create_node(7);

    /* Printing leaf nodes */
    printf("Leaf Nodes: ");
    print_leaf_nodes(root);
    printf("\n");

    /* Printing non-leaf nodes */
    printf("Non-Leaf Nodes: ");
    print_non_leaf_nodes(root);
    printf("\n");

    /* Printing node levels */
    printf("Node Levels:\n");
    print_node_levels(root, 1);

    return 0;
}
