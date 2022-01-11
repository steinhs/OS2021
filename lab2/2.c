#include <stdio.h>
#include <math.h>

// F(50)	12586269025

int fibonacci_calc_one(int n){
    int i; 
    long long int n1 = 0, n2 = 0, curr = 0;

    for (i = 0; i <= n; i++)
    {
        if (i > 1)
        {
            curr = (n1)+(n2);
        } else {
            curr = i;
        }

        n2 = n1;
        n1 = curr;
    }
    
        printf("Calculate F(%d): %lld\n", n, curr);

    
}

int fibonacci_calc_sum(int n){
    
    int i; 
    long long int sum = 0, n1 = 0, n2 = 0, curr = 0;

    for (i = 0; i <= n; i++)
    {
        if (i > 1)
        {
            curr = (n1)+(n2);
        } else {
            curr = i;
        }

        sum = sum+curr;
        n2 = n1;
        n1 = curr;
    }
    
    printf("Summation of first F(%d): %lld\n", n, sum);
    
}

int main()
{

    fibonacci_calc_one(50);
    fibonacci_calc_sum(50);

    /* NOTE FOR SUM OF FIBONACCI TERMS
        I can't figure out why I am consistently just above target number for bigger fibonacci numbers. 
        At least according to the result of a fib-calculator I found on the internet.
    */

    return 0;
}
