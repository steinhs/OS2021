#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "message.h"

static const char* message[] = {
    "Hello!",
    "Goodbye!",
    "See you again!",
    "This is Lab4 assignment!",
    "This course is Introduction to Operating Systems course!"
};

void print_message() {
    int index;
    srand(time(NULL));
    index = rand()%5;
    printf("%s\n", message[index]);
}
