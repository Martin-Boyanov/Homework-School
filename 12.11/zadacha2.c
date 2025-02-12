#include <stdio.h>

int find_greatest_common_divisor(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int find_least_common_multiple(int a, int b) {
    return (a * b) / find_greatest_common_divisor(a, b);
}

int main() {
    int a = 12;
    int b = 18;
    int result = find_least_common_multiple(a, b);
    printf("The least common multiple of %d and %d is: %d\n", a, b, result);
    return 0;
}