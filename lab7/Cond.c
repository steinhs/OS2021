#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//Your code for global variables (if any)
int condition = 0;
pthread_cond_t generic_condition;
pthread_mutex_t lock;

void* print_Pfizer () {
    //Your code for Thread 1
    pthread_mutex_lock(&lock);

    while (condition == 0)
        pthread_cond_wait(&generic_condition, &lock);
    printf("Pfizer\n");
    pthread_cond_signal(&generic_condition);
    condition = 2;

    while (condition == 2)
        pthread_cond_wait(&generic_condition, &lock);
    printf("Pfizer\n");
    pthread_cond_signal(&generic_condition);
    condition = 4;

    while (condition == 4)
        pthread_cond_wait(&generic_condition, &lock);
    printf("Pfizer\n");
    pthread_cond_signal(&generic_condition);
    condition = 6;

    while (condition == 6)
        pthread_cond_wait(&generic_condition, &lock);
    printf("Pfizer\n");
    pthread_cond_signal(&generic_condition);
    condition = 8;

    while (condition == 8)
        pthread_cond_wait(&generic_condition, &lock);
    printf("Pfizer\n");

    pthread_mutex_unlock(&lock);

}

void* print_Moderna() {
    //Your code for Thread 2
    pthread_mutex_lock(&lock);

    printf("Moderna\n");
    pthread_cond_signal(&generic_condition);
    condition = 1;

    while (condition == 1)
        pthread_cond_wait(&generic_condition, &lock);
    printf("Moderna\n");
    pthread_cond_signal(&generic_condition);
    condition = 3;

    while (condition == 3)
        pthread_cond_wait(&generic_condition, &lock);
    printf("Moderna\n");
    pthread_cond_signal(&generic_condition);
    condition = 5;

    while (condition == 5)
        pthread_cond_wait(&generic_condition, &lock);
    printf("Moderna\n");
    pthread_cond_signal(&generic_condition);
    condition = 7;

    while (condition == 7)
        pthread_cond_wait(&generic_condition, &lock);
    printf("Moderna\n");
    pthread_cond_signal(&generic_condition);
    condition = 9;

    pthread_mutex_unlock(&lock);
}

int main(int argc, char** argv) {
    //Your code for initializing any local or global variables
    int err = 0;
    pthread_t t1 , t2 ;

    err = pthread_mutex_init(&lock, NULL);	// mutex unitialization
    if (err != 0) {
        perror("pthread_mutex_init encountered an error");
    } else {
        err = 0;
    }
    err = pthread_cond_init(&generic_condition, NULL);
    if (err != 0) {
        perror("pthread_cond_init encountered an error");
    } else {
        err = 0;
    }
    err = pthread_create(&t1 , NULL, print_Pfizer , NULL) ;
    if (err != 0) {
        perror("pthread_create1 encountered an error");
        exit(1); } else {
        err = 0;
    }
    err = pthread_create(&t2 , NULL, print_Moderna , NULL) ;
    if (err != 0) {
        perror("pthread_create2 encountered an error");
        exit(1); } else {
        err = 0;
    }

    //Your code for the rest of the program
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Astrazeneca !\n");

    err = pthread_mutex_destroy(&lock);
    if (err != 0) {
        perror("pthread_mutex_destroy encountered an error");
    } else {
        err = 0; }
    pthread_cond_destroy(&generic_condition);
    if (err != 0) {
        perror("pthread_cond_destroy encountered an error");
    } else {
        err = 0; }
    return 0;

}