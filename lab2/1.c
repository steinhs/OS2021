#include <stdio.h>
#include <math.h>

int calc_product(int A, int B){
    int PROD_calc = 0;
    int PROD = A*B;
    return PROD;
}

int main(int argc, char const *argv[])
{
    int A, B;
    int PROD = 0;

    printf("Enter first decimal: ");
    scanf("%d", &A);
    printf("You entered: %d\n", A);

    printf("Enter second decimal: ");
    scanf("%d", &B);
    printf("You entered: %d\n", B);

    PROD = calc_product(A, B);
    printf("Product of two decimals is: %d\n", PROD);


    return 0;
}
