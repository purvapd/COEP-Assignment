#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to determine whether a string is a palindrome or not
int isPalindrome(char *str) {
    int len = strlen(str); // get length of string
    for (int i = 0; i < len / 2; i++) { // iterate through first half of string
        if (str[i] != str[len - i - 1]) { // compare with corresponding element in second half of string
            return 0; // not a palindrome
        }
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
