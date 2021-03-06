/**
 * @brief     This file contains a broken program to be debugged with GDB.
 * @detail    This program allocates a buffer, reads upto 512 characters from
 *			  STDIN and then prints the buffer to STDOUT.
 */

/// Include standard i/o and standard library
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	char *buffer; // pointer to the buffer

	buffer = malloc(1<<30); // allocate a new buffer

	fgets(buffer, 512, stdin); // get upto 512 characters from STDIN
	printf("%s\n", buffer); // print the buffer to STDOUT

	return 0;
}
