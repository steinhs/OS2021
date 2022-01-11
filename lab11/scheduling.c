#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct process{
    /* Values initialized for each process */
    int id;
    int arrivaltime;  /* Time process arrives and wishes to start */
    int runtime;      /* Time process requires to complete job */

    /* Values algorithm may use to track processes */
    int starttime;
    int endtime;
}process;
struct process proc[100];



void first_come_first_served(){
    /* Your code for FCFS algorithm here */
    int x = 1, y = 0, previousEndtime = 0;
    while (x!=0){

        if (previousEndtime > proc[y].arrivaltime){
            proc[y].starttime = previousEndtime;
            proc[y].endtime = previousEndtime + proc[y].runtime;
        } else {
            proc[y].starttime = proc[y].arrivaltime;
            proc[y].endtime = proc[y].arrivaltime + proc[y].runtime;
        }

        printf("Process %d started at time %d and finished at time %d\n", proc[y].id, proc[y].starttime, proc[y].endtime);

        previousEndtime = proc[y].endtime;

        y++;
        x = proc[y].id;
    }
}

// cmp function taken from @Mitch Wheat
// https://stackoverflow.com/questions/6105513/need-help-using-qsort-with-an-array-of-structs
int cmp(const void *p1, const void *p2)
{
    const struct process *el1 = p1;
    const struct process *el2 = p2;

    if (el1->runtime < el2->runtime)
        return -1;
    else if (el1->runtime > el2->runtime)
        return 1;
    else
        return 0;
}

void shortest_job_first(){
    /* Your code for SJF algorithm here */
    qsort (proc, 100, sizeof(process), cmp);
    int x = 1, y = 0, previousEndtime = 0;
    for (y = 0; y < 100; ++y) {

        if (proc[y].id != 0) {
            if (previousEndtime > proc[y].arrivaltime){
                proc[y].starttime = previousEndtime;
                proc[y].endtime = previousEndtime + proc[y].runtime;
            } else {
                proc[y].starttime = proc[y].arrivaltime;
                proc[y].endtime = proc[y].arrivaltime + proc[y].runtime;
            }
            printf("Process %d started at time %d and finished at time %d\n", proc[y].id, proc[y].starttime, proc[y].endtime);

            previousEndtime = proc[y].endtime;
        }
    }
}


int main(){

    FILE *pFile= fopen("Testcase.txt", "r");
    if (pFile == NULL) {
        printf("Error! Could not open file\n");
        exit(-1);
    }
    int i = 0;
    printf("Process\tarrival\truntime\n");
    while (fscanf(pFile, "%d%d%d", &proc[i].id, &proc[i].arrivaltime, &proc[i].runtime) != EOF){
        printf("%d\t%d\t%d\n", proc[i].id, proc[i].arrivaltime, proc[i].runtime);
        i++;
    }

    /* Run scheduling algorithms */
    printf("First come first served...\n");
    first_come_first_served();

    printf("Shortest job first...\n");
    shortest_job_first();
    return 0;
}