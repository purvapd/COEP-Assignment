#include <stdio.h>

void squeeze(char *s, char c);

int main() {
    char str[] = "Hello, world!";
    printf("Original string: %s\n", str);
    squeeze(str, 'o');
    printf("Squeezed string: %s\n", str);
    return 0;
}

void squeeze(char *s, char c) {
    char *p = s;  // pointer to current position in s
    while (*s != '\0') {
        if (*s != c) {
            *p++ = *s;  // copy non-c characters to the left
        }
        s++;  // move to next character in s
    }
    *p = '\0';  // terminate the squeezed string
}
