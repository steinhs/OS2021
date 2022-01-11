/**
 * @brief     This file contains a broken program to be debugged with GDB.
 * @detail    This program reads a line from stdin, generates random numbers
 *			  that is then used to pull characters from random
 *			  parts of the read string
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int arg, char** argv)
{
    char string[32];
    char *str = string;
    int rand_array[9]; // 9 random numbers
    int i, n;
    int length = 10;
    size_t j = 32;

    printf("Enter a line: ");
    n = getline(&str, &j, stdin);
    printf("You entered the %d character line: %s", n-1, string);

<<<<<<< HEAD
    // generate an array of random indexes
    for(i = 0; i < length; i++)
    {
        rand_array[i] = rand() % (n-1);
    }
=======
	// generate an array of random indexes
	for(i=0; i<=length; i++)
	{
		rand_array[i] = rand() % (n-1);
	}
	
	printf("The randomized string is \n");
	for(i=0; i<length; i++)
	{
		putchar(string[rand_array[i]]);
	}
	printf("\"\n");
>>>>>>> 45517e48c9fdc16c5c00acb74ef4f2ebb845c188

    printf("The randomized string is \"");
    for(i = 0; i < length; i++)
    {
        putchar(string[rand_array[i]]);
    }
    printf("\"\n");

    return 0;
}
