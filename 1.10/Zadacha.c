#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Функция за проверка дали дадено число е просто
bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Намиране на сумата на простите числа в масив
int sum_of_primes(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (is_prime(arr[i])) {
            sum += arr[i];
        }
    }
    return sum;
}

// Произведение на цифрите на число
int product_of_digits(int num) {
    int product = 1;
    while (num > 0) {
        product *= num % 10;
        num /= 10;
    }
    return product;
}

// Функция за сортиране на масив (Bubble Sort)
void sort_array(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Намиране на сумата на елементите умножени по индекса им
int weighted_sum(int arr[], int size) {
    sort_array(arr, size);
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i] * i;
    }
    return sum;
}

// Бинарно търсене
int binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Намиране на символа с най-висок ASCII код
char max_ascii_char(const char *str) {
    char max_char = str[0];
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] > max_char) max_char = str[i];
    }
    return max_char;
}

// Рекурсивно преобразуване на число в двоично
long decimal_to_binary(int num) {
    if (num == 0) return 0;
    return num % 2 + 10 * decimal_to_binary(num / 2);
}

// Структура student
struct student {
    char name[20];
    int class_number;
    float avg_grade;
};

int main() {
    // Тест на задачите
    int arr[] = {1, 7, 10, 15, 16, 13, 23, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Sum of primes: %d\n", sum_of_primes(arr, size));
    
    int num = 417;
    printf("Product of digits: %d\n", product_of_digits(num));
    
    int arr2[] = {1, 7, 3, 4, 9, 2};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Weighted sum: %d\n", weighted_sum(arr2, size2));
    
    int sorted_arr[] = {1, 2, 5, 7, 8, 10};
    printf("Binary search (5): %d\n", binary_search(sorted_arr, 6, 5));
    printf("Binary search (6): %d\n", binary_search(sorted_arr, 6, 6));
    
    printf("Max ASCII char in 'Ivan': %c\n", max_ascii_char("Ivan"));
    
    int decimal = 10;
    printf("Binary of %d: %ld\n", decimal, decimal_to_binary(decimal));
    
    struct student s = {"Ivan Petrov", 12, 5.45};
    printf("Student: %s, Class Number: %d, Avg Grade: %.2f\n", s.name, s.class_number, s.avg_grade);
    
    return 0;
}