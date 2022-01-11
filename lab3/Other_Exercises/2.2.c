#include<stdio.h>
void change(int *num1, int *num2) {

    printf("num1: %d %p\n", num1);
    printf("num1: %d %p\n", num2);

     int temp = *num1;
     *num1 = *num2;
     *num2 = temp;

}
int main() {
     int num1, num2;
     printf("Enter the first number: ");
     scanf("%d", &num1);
     printf("Enter the second number: ");
     scanf("%d", &num2);

     change(&num1, &num2);
     printf("\nAfter changing two numbers:\n");
     printf("The first number is: %d\n", num1);
     printf("The second number is: %d\n", num2);
     
return 0; }