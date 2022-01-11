#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b;

    printf("Enter one integer: ");
    scanf("%d",&a);
    printf("Enter another integer: ");
    scanf("%d",&b);

        // pointer locations
    int *ap = &a, *bp = &b;

    printf("First integer is stored at %p\n", ap);
    printf("First integer is stored at %p\n", bp);

    int sum = *ap + *bp;
    int multi = *ap * *bp;
    float div = (float)*ap/(float)*bp;
    int diff = 0;
    if (*ap > *bp)
        diff = *ap - *bp;
    else
        diff = *bp-*ap;

    printf("Summation: %d\n", sum);
    printf("Difference: %d\n", diff);
    printf("Multiplication: %d\n", multi);
    printf("Division: %f\n", div);

    

    return 0;
}
