#include <stdio.h>
#include <stdlib.h>

/* Structure of a tree node */
struct node {
    int data;
    struct node* left;
    struct node* right;
};

/* Function to create a new node */
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Function to traverse a tree in level order without using stack */
void levelOrderTraversalWithoutStack(struct node* root) {
    if (root == NULL) {
        return;
    }

    /* Create a queue for level order traversal */
    struct node** queue = (struct node**)malloc(sizeof(struct node*) * 100);
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct node* temp = queue[front++];
        printf("%d ", temp->data);

        /* Enqueue left child */
        if (temp->left != NULL) {
            queue[rear++] = temp->left;
        }

        /* Enqueue right child */
        if (temp->right != NULL) {
            queue[rear++] = temp->right;
        }
    }
}

/* Function to traverse a tree in level order using stack */
void levelOrderTraversalWithStack(struct node* root) {
    if (root == NULL) {
        return;
    }

    /* Create two stacks for level order traversal */
    struct node** stack1 = (struct node**)malloc(sizeof(struct node*) * 100);
    struct node** stack2 = (struct node**)malloc(sizeof(struct node*) * 100);
    int top1 = -1, top2 = -1;

    /* Push the root node into stack1 */
    stack1[++top1] = root;

    while (top1 >= 0 || top2 >= 0) {
        while (top1 >= 0) {
            struct node* temp = stack1[top1--];
            printf("%d ", temp->data);

            /* Push right child into stack2 */
            if (temp->right != NULL) {
                stack2[++top2] = temp->right;
            }

            /* Push left child into stack2 */
            if (temp->left != NULL) {
                stack2[++top2] = temp->left;
            }
        }

        while (top2 >= 0) {
            struct node* temp = stack2[top2--];
            printf("%d ", temp->data);

            /* Push left child into stack1 */
            if (temp->left != NULL) {
                stack1[++top1] = temp->left;
            }

            /* Push right child into stack1 */
            if (temp->right != NULL) {
                stack1[++top1] = temp->right;
            }
        }
    }
}

/* Main function */
int main() {
    /* Create a binary tree */
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    /* Traverse the binary tree in level order without using stack */
    printf("Level order traversal without stack: ");
    levelOrderTraversalWithoutStack(root);
    printf("\n");

    /* Traverse the binary tree in level order using stack */
    printf("Level order traversal with stack: ");
    levelOrderTraversalWithStack(root);
    printf("\n");
    return 0;
}