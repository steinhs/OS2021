#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

// NOTE: CHANGED 

int fileToArrayAndSum(char* fileName){

    int size, i, sum = 0; 

        //Open file
    FILE* theFile;
    theFile = fopen(fileName, "r");

    if (theFile == NULL || theFile == NULL){
        printf("Error reading file\n");
        exit(0);
        }

        //Get size from the first int in file
    fscanf(theFile, "%d", &size);
    printf("\nSize %d\n", size);

        //Create array
    int numbersArray[size];

        //Add numbers from file to array
    for ( i = 0; i < size; i++)
    {
        fscanf(theFile, "%d", &numbersArray[i]);
    }

        //Add together all numbers from array to "sum"
    for ( i = 0; i < size; i++)
        sum = sum + numbersArray[i];
        
    printf("Sum of numbers: %d\n", sum);

    fclose(theFile);
}

int main()
{

    fileToArrayAndSum("testcase0.txt");

    printf("\nRunning the program with testcase1.txt results in segmentation fault. \nThis because when declaring the array we get a stack overflow as the \narray of that size can't fit in our programs stack address space.");
    fileToArrayAndSum("testcase1.txt");
    /*
    Running the program with testcase1.txt results in segmentation fault. 
    This because when declaring the array we get a stack overflow as the 
    array of that size can't fit in our programs stack address space.
    */
        

    return 0;
}
