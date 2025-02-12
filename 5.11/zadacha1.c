#include <stdio.h>;
#define DEBUGvoid bubble_sort(int arr[], int size) {
    for (int i = 0; i &lt; size - 1; i++) {
        for (int j = 0; j &lt; size - i - 1; j++) {
            if (arr[j] &gt; arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sort_and_sum_div3(int arr[], int size) {
    bubble_sort(arr, size);
#ifdef DEBUG
    printf(&quot;Sorted array: &quot;);
    for (int i = 0; i &lt; size; i++) {
        printf(&quot;%d &quot;, arr[i]);
    }
    printf(&quot;\n&quot;);
#endif
    int sum = 0;
    for (int i = 0; i &lt; size; i++) {
        if (i % 3 == 0) {
            sum += arr[i];
#ifdef DEBUG
            printf(&quot;Element at index %d (divisible by 3): %d\n&quot;, i, arr[i]);
#endif
        }
    }
    printf(&quot;Sum of elements at indices divisible by 3: %d\n&quot;, sum);
}
int main()
{
    int array[] = {12, 3, 5, 7, 19, 20, 0, 15, 4};
    int n = sizeof(array) / sizeof(array[0]);
    sort_and_sum_div3(array, n);
    return 0;
}