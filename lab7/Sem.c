#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <pthread.h>
#include <semaphore.h>

/*
Output:
    Ostfold University College !

    Department o f Computer S c i e n c e and Communication
    Faculty of Computer Science , Engineering and Economics

    Department o f Computer S c i e n c e and Communication
    Faculty of Computer Science , Engineering and Economics

    Department o f Computer S c i e n c e and Communication
    Faculty of Computer Science , Engineering and Economics

    Department o f Computer S c i e n c e and Communication
    Faculty of Computer Science , Engineering and Economics

    Department o f Computer S c i e n c e and Communication
    Faculty of Computer Science , Engineering and Economics

Functions you may need include:
    int sem_init(sem_t *sem, int pshared, unsigned int value);
    int sem_destroy(sem_t *sem);
    int sem_wait(sem_t *sem);
    int sem_post(sem_t *sem);
    int pthread_join(pthread_t thread, void **retval);
 */
//Your code for global variables (if any)
sem_t semaphore, semaphore1, semaphore2;
void* print_Department () {
    //Your code for Thread 1
    sem_wait(&semaphore2); // to make sure that Ostfold prints.
    for (int i = 0; i < 5; ++i) {
        if (i==0){
            printf("Department of Computer Science and Communication\n");
            sem_post(&semaphore);
        } else {
            sem_wait(&semaphore1);
            printf("Department of Computer Science and Communication\n");
            sem_post(&semaphore);
        }
    }
}

void* print_Faculty () {
    //Your code for Thread 2
    for (int i = 0; i < 5; ++i) {
        if (i<4){
            sem_wait(&semaphore);
            printf("Faculty of Computer Science, Engineering and Economics\n\n");
            sem_post(&semaphore1);

        } else {
            sem_wait(&semaphore);
            printf("Faculty of Computer Science, Engineering and Economics\n");
        }
    }
}

int main(int argc, char** argv) {
    //Your code for initializing any local or global variables and other
    int err = 0;
    pthread_t t1 , t2 ;

    err = pthread_create(&t1 , NULL, print_Department , NULL) ;
    if (err != 0) {
        perror("pthread_create1 encountered an error");
        exit(1); } else {
        err = 0;
    }
    err = pthread_create(&t2 , NULL, print_Faculty , NULL) ;
    if (err != 0) {
        perror("pthread_create2 encountered an error");
        exit(1); } else {
        err = 0;
    }
    err =  sem_init(&semaphore, 0, 0);
    if (err != 0) {
        perror("sem_init encountered an error");
    } else {
        err = 0;
    }
    err =  sem_init(&semaphore1, 0, 0);
    if (err != 0) {
        perror("sem_init encountered an error");
    } else {
        err = 0;
    }

    //Your code for the rest of the program
    printf("Ostfold University College!\n\n");
    sem_post(&semaphore2); // to make sure that Ostfold prints first
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    err = sem_destroy(&semaphore);
    if (err != 0) {
        perror("sem_destroy encountered an error");
    } else {
        err = 0; }

}