#include <stdio.h>;
#include &lt;math.h&gt;
#define ARRAY_SIZE 5
int main() {
    #ifndef ARRAY_SIZE
        printf(&quot;An array size that is supported by the application has not
been entered.\n&quot;);
    #elif ARRAY_SIZE &lt; 1 || ARRAY_SIZE &gt; 10
        printf(&quot;The size of the array is not entered properly\n&quot;);
    #else
        int array[ARRAY_SIZE];
       
        for (int i = 0; i &lt; ARRAY_SIZE; i++)
        {
            array[i] = (int)pow(2, i);
        }
       
        for (int i = 0; i &lt; ARRAY_SIZE; i++)
        {
            printf(&quot;%d\n&quot;, array[i]);
        }
    #endif
   
    return 0;
}