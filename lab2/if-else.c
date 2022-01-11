#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int A, B, MAX;

    printf("Enter first decimal: ");
    scanf("%d", &A);
    printf("You entered: %d\n\n", A);

    printf("Enter second decimal: ");
    scanf("%d", &B);
    printf("You entered: %d\n ", B);

    if (A > B)
        MAX = A;
    else 
        MAX = B;
    
    printf("Max is %d\n", MAX);

    return 0;
}
