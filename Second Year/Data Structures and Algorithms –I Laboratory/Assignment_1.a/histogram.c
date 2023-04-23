#include <stdio.h>

#define MAX_CHAR 128  // maximum number of characters

int main() {
    int char_freq[MAX_CHAR] = {0};  // array to store the frequency of each character
    int c;

    // read input and count the frequency of each character
    while ((c = getchar()) != EOF) {
        if (c < MAX_CHAR) {
            char_freq[c]++;
        }
    }

    // print the histogram
    printf("Histogram of character frequencies:\n");
    for (int i = 0; i < MAX_CHAR; i++) {
        if (char_freq[i] > 0) {
            printf("%c: ", i);
            for (int j = 0; j < char_freq[i]; j++) {
                putchar('*');
            }
            putchar('\n');
        }
    }

    return 0;
}


