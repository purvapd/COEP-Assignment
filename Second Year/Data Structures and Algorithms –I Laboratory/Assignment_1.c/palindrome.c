#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char data[MAX_LENGTH];
    int top;
} Stack;

// Function to add an item to the top of the stack
void push(Stack *stack, char item) {
    if (stack->top == MAX_LENGTH - 1) { // check for stack overflow
        printf("Stack overflow!\n");
        return;
    }
    stack->top++;
    stack->data[stack->top] = item; // add item to the top of the stack
}

// Function to remove and return the top item from the stack
char pop(Stack *stack) {
    if (stack->top == -1) { // check for stack underflow
        printf("Stack underflow!\n");
        return '\0';
    }
    char item = stack->data[stack->top]; // get top item from stack
    stack->top--;
    return item; // return top item
}

// Function to determine whether a string is a palindrome or not
int isPalindrome(char *str) {
    Stack stack; // create a stack
    stack.top = -1; // initialize stack top to -1
    int len = strlen(str); // get length of string
    int mid = len / 2; // find the middle index of the string

    // push first half of string onto the stack
    for (int i = 0; i < mid; i++) {
        push(&stack, str[i]);
    }

    // compare second half of string with elements popped from stack
    int j = len % 2 == 0 ? mid : mid + 1; // start index of second half of string
    while (j < len) {
        char item = pop(&stack);
        if (item != str[j]) {
            return 0; // not a palindrome
        }
        j++;
    }

    return 1; // palindrome
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}
