#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}

// Function to perform arithmetic operations
int performOperation(int operand1, int operand2, char operator) {
    switch(operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            printf("Error: Invalid operator\n");
            exit(EXIT_FAILURE);
    }
}

// Function to evaluate infix expression
int evaluateInfixExpression(char* expression) {
    int i;
    int len = strlen(expression);

    // Stacks to hold operands and operators
    int operandStack[len];
    int operandTop = -1;
    char operatorStack[len];
    int operatorTop = -1;

    for (i = 0; i < len; i++) {
        // Ignore spaces
        if (expression[i] == ' ') {
            continue;
        }
        // If character is an operand, push it to operand stack
        else if (isdigit(expression[i])) {
            int operand = 0;
            while (i < len && isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            operandStack[++operandTop] = operand;
        }
        // If character is an operator, push it to operator stack after
        // popping operators with higher precedence and evaluating them
        else if (isOperator(expression[i])) {
            while (operatorTop >= 0 && getPrecedence(operatorStack[operatorTop]) >= getPrecedence(expression[i])) {
                int operand2 = operandStack[operandTop--];
                int operand1 = operandStack[operandTop--];
                char operator = operatorStack[operatorTop--];
                int result = performOperation(operand1, operand2, operator);
                operandStack[++operandTop] = result;
            }
            operatorStack[++operatorTop] = expression[i];
        }
        // If character is an opening parenthesis, push it to operator stack
        else if (expression[i] == '(') {
            operatorStack[++operatorTop] = expression[i];
        }
        // If character is a closing parenthesis, pop operators from operator
        // stack and evaluate them until an opening parenthesis is encountered
        else if (expression[i] == ')') {
            while (operatorTop >= 0 && operatorStack[operatorTop] != '(') {
                int operand2 = operandStack[operandTop--];
                int operand1 = operandStack[operandTop--];
                char operator = operatorStack[operatorTop--];
                int result = performOperation(operand1, operand2, operator);
                operandStack[++operandTop] = result;
            }
            if (operatorTop < 0 || operatorStack[operatorTop] != '(') {
                printf("Error: Mismatched parentheses\n");
                exit(EXIT_FAILURE);
            }
            operatorTop--; //
                }
    }

    // Pop any remaining operators and evaluate them
    while (operatorTop >= 0) {
        int operand2 = operandStack[operandTop--];
        int operand1 = operandStack[operandTop--];
        char operator = operatorStack[operatorTop--];
        int result = performOperation(operand1, operand2, operator);
        operandStack[++operandTop] = result;
    }

    // The final result should be at the top of the operand stack
    return operandStack[operandTop];
}

int main() {
    char expression[100];

    printf("Enter an infix expression: ");
    fgets(expression, sizeof(expression), stdin);

    // Remove trailing newline character from input
    expression[strcspn(expression, "\n")] = '\0';

    int result = evaluateInfixExpression(expression);
    printf("Result: %d\n", result);

    return 0;
}

