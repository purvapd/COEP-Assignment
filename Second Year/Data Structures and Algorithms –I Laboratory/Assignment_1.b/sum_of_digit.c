#include <stdio.h>

int main() {
   int num, digit, sum = 0;

   printf("Enter a number: ");
   scanf("%d", &num);

   while (num > 0) {
      digit = num % 10;    // Get the last digit of the number
      sum += digit;        // Add the digit to the sum
      num /= 10;           // Remove the last digit from the number
   }

   printf("The sum of the digits of the number is %d", sum);
   return 0;
}
