
#include <stdio.h>
int main(){

int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int i = 0;
for (i = 0; i < 10; i++){
      printf("The value of A[%d] is %d\n", i, A[i]);
      printf("It is stored at the address %p\n\n", &A[i]);
}
printf("The address of Array A is %p\n", A);
printf("That is the address of the first element in the array A\n");
return 0;
}