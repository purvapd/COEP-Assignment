#include <stdio.h>

int sum_of_digits(int num);

int main() {
   int num;

   printf("Enter a number: ");
   scanf("%d", &num);

   printf("The sum of the digits of the number is %d", sum_of_digits(num));
   return 0;
}

int sum_of_digits(int num) {
   if (num == 0) {
      return 0;
   }
   return (num % 10) + sum_of_digits(num / 10);
}
