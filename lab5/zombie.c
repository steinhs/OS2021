#include "stdlib.h"
#include "stdio.h"
#include <unistd.h>

int main(){
    int status = 0;
    pid_t child = fork();

    if (child > 0)
        exit(0);
    else if (child == 0)
        sleep(20);

    exit(0);


}