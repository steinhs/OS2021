#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int *pageSize;

struct PageFrame{
     int Id; /* Page ID */
     int ArrivalTime; /* Time that the page arrives */
     int LastRefTime; /* the Last time that the page was refered in the past */
     int Rbit; /* Referenced(R) bit */
     int Mbit; /* Modified(M) bit */
}PageFrame;
struct PageFrame page[100];

int arrival_cmp(const void *p1, const void *p2)
{
    const struct PageFrame *el1 = p1;
    const struct PageFrame *el2 = p2;

    if (el1->ArrivalTime < el2->ArrivalTime)
        return -1;
    else if (el1->ArrivalTime > el2->ArrivalTime)
        return 1;
    else
        return 0;
}

int last_refered_cmp(const void *p1, const void *p2)
{
    const struct PageFrame *el1 = p1;
    const struct PageFrame *el2 = p2;

    if (el1->LastRefTime < el2->LastRefTime)
        return -1;
    else if (el1->LastRefTime > el2->LastRefTime)
        return 1;
    else
        return 0;
}

void first_in_first_out(){
    /* Your code for FIFO algorithm here */

    struct PageFrame fifoPage[*pageSize];
    for (int i = 0; i < *pageSize; ++i) {
        fifoPage[i].Id = page[i].Id;
        fifoPage[i].ArrivalTime = page[i].ArrivalTime;
        fifoPage[i].LastRefTime = page[i].LastRefTime;
        fifoPage[i].Rbit = page[i].Rbit;
        fifoPage[i].Mbit = page[i].Mbit;
    }
        // Sorting struct based on ArrivalTime
    qsort (fifoPage, *pageSize, sizeof(PageFrame), arrival_cmp);

        // Print sorted struct
    for (int i = 0; i < *pageSize; ++i) {
        printf("Page selected: Page %d, Loaded at time %d, Last Refered at time %d, Rbit %d, Mbit %d.\n", fifoPage[i].Id, fifoPage[i].ArrivalTime, fifoPage[i].LastRefTime, fifoPage[i].Rbit, fifoPage[i].Mbit);
    }
}

void least_recently_used(){
    /* Your code for LRU algorithm here */

    struct PageFrame lruPage[*pageSize];
    for (int i = 0; i < *pageSize; ++i) {
        lruPage[i].Id = page[i].Id;
        lruPage[i].ArrivalTime = page[i].ArrivalTime;
        lruPage[i].LastRefTime = page[i].LastRefTime;
        lruPage[i].Rbit = page[i].Rbit;
        lruPage[i].Mbit = page[i].Mbit;
    }
    // Sorting struct based on LastRefTime
    qsort (lruPage, *pageSize, sizeof(PageFrame), last_refered_cmp);

    // Print sorted struct
    for (int i = 0; i < *pageSize; ++i) {
        printf("Page selected: Page %d, Loaded at time %d, Last Refered at time %d, Rbit %d, Mbit %d.\n", lruPage[i].Id, lruPage[i].ArrivalTime, lruPage[i].LastRefTime, lruPage[i].Rbit, lruPage[i].Mbit);
    }
}

int main(){
   
     FILE *pFile= fopen("Testcase0.txt", "r");
     if (pFile == NULL) { 
        printf("Error! Could not open file\n"); 
        exit(-1);
    } 
    int i = 0;
    printf("Page\tArrival\tLastRef\tRbit\tMbit\n");
    while (fscanf(pFile, "%d%d%d%d%d", &page[i].Id, &page[i].ArrivalTime, &page[i].LastRefTime, &page[i].Rbit, &page[i].Mbit) != EOF){ 
        printf("%d\t%d\t%d\t%d\t%d\n", page[i].Id, page[i].ArrivalTime, page[i].LastRefTime, page[i].Rbit, page[i].Mbit);       
        i++;  
     }

    pageSize = &i;
    /* Run page replacement algorithms */
  printf("First-in-First-out...\n");
  first_in_first_out();

  printf("Least-Recently-Used...\n");
  least_recently_used();

  return 0;
}