#include <stdio.h>
#include <math.h>
#include <stdlib.h>


// Function to compute x^y
long long power(int x, int y) {
    int base3_y[32], i;
    long long result = 1;

    // Convert y to base-3
    for (i = 0; y != 0; i++, y /= 3) {
        base3_y[i] = abs(y % 3);
    }

    // Compute x^y in base-3
    for (i = i - 1; i >= 0; i--) {
        if (base3_y[i] == 1) {
            result *= x;
        } else if (base3_y[i] == 2) {
            result *= x * x;
        }
        x *= x * x;
    }

    return result;
}

// Main function
int main() {
    int x, y;

    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of y: ");
    scanf("%d", &y);

    printf("%d ^ %d = %lld\n", x, y, power(x, y));

    return 0;
}
