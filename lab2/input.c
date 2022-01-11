#include <stdio.h>

int main(int argc, char const *argv[])
{
    int A, B;
    int SUM = 0;

    printf("Enter first decimal: ");
    scanf("%d", &A);
    printf("You entered: %d\n\n", A);

    printf("Enter second decimal: ");
    scanf("%d", &B);
    printf("You entered: %d\n ", B);

    SUM = A+B;

    printf("Sum of two decimals is: %d\n ", SUM);

    return 0;
}
