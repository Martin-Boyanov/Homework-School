#include &lt;stdio.h&gt;
#if defined(_WIN32)
    void bubble_sort(int arr[], int n) {
        int i, j, temp;
        for (i = 0; i &lt; n - 1; i++)
            for (j = 0; j &lt; n - i - 1; j++)
                if (arr[j] &gt; arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
    }
#elif defined(__linux__)
    void selection_sort(int arr[], int n) {
        int i, j, min_idx, temp;
        for (i = 0; i &lt; n - 1; i++) {

            min_idx = i;
            for (j = i + 1; j &lt; n; j++)
                if (arr[j] &lt; arr[min_idx])
                    min_idx = j;
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
#elif defined(__APPLE__)
    void insertion_sort(int arr[], int n) {
        int i, key, j;
        for (i = 1; i &lt; n; i++) {
            key = arr[i];
            j = i - 1;
            while (j &gt;= 0 &amp;&amp; arr[j] &gt; key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
#else
    void reverse_array(int arr[], int n) {
        int temp, start = 0, end = n - 1;
        while (start &lt; end) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
#endif
int main() {
    int arr[] = {5, 3, 8, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    #if defined(_WIN32)
        bubble_sort(arr, n);
    #elif defined(__linux__)
        selection_sort(arr, n);
    #elif defined(__APPLE__)
        insertion_sort(arr, n);
    #else
        reverse_array(arr, n);
    #endif
printf(&quot;Your sorted array is: \n&quot;);
    for (int i = 0; i &lt; n; i++)
    {
        printf(&quot;%d \n&quot;, arr[i]);
    }
   
    return 0;
}