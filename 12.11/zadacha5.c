#include <stdio.h>
#include "maths.h"

int main() {
    int number = 5;
    long result = factorial(number);
    printf("Factorial of %d is: %ld\n", number, result);
    return 0;
}