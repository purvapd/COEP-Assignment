#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 1000

typedef struct {
    int digits[MAX_DIGITS];
    int size;
} Integer;

void init(Integer *num) {
    memset(num->digits, 0, sizeof(num->digits));
    num->size = 0;
}

void set(Integer *num, char *str) {
    init(num);
    int len = strlen(str);
    for (int i = len - 1, j = 0; i >= 0; i--, j++) {
        num->digits[j] = str[i] - '0';
        num->size++;
    }
}

void print(Integer *num) {
    for (int i = num->size - 1; i >= 0; i--) {
        printf("%d", num->digits[i]);
    }
    printf("\n");
}

void add(Integer *num1, Integer *num2, Integer *result) {
    init(result);
    int carry = 0;
    for (int i = 0; i < num1->size || i < num2->size; i++) {
        int sum = num1->digits[i] + num2->digits[i] + carry;
        result->digits[i] = sum % 10;
        carry = sum / 10;
        result->size++;
    }
    if (carry) {
        result->digits[result->size++] = carry;
    }
}

int main() {
    Integer num1, num2, result;
    char str1[MAX_DIGITS], str2[MAX_DIGITS];

    printf("Enter the first number: ");
    scanf("%s", str1);
    set(&num1, str1);

    printf("Enter the second number: ");
    scanf("%s", str2);
    set(&num2, str2);

    add(&num1, &num2, &result);

    printf("Sum of the numbers: ");
    print(&result);

    return 0;
}
