#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

int ReverseArray(int array[], int size){
    int tempArray[size];

        // Stores the current integer from array to the place -1 on tempArray, which wil result in a reversed array.
    for (int i = 0; i < size; i++)
    {
        tempArray[size - 1 - i] = array[i];
    }

        // Stores the tempArray on original array, which can be accessed outside of the function.
    for (int i = 0; i < size; i++)
    {
        array[i] = tempArray[i];
    }
}


int main(int argc, char const *argv[])
{
    int size, val, i;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int array[size];


    printf("Enter %d input values for the array: ", size);
    for ( i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

        // ORIGINAL ARRAY
    printf("The input array is: ");
    for ( i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");


        // REVERSE ARRAY
    ReverseArray(array, size);
    printf("Array printed in reserve order: ");
    for ( i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");




    return 0;
}
