#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>

#define NUM_THREADS 8


/*
void *Funct(){
    printf("Henlo\n");
}
 */

void *MatrixCalculator(void *a_void_ptr, void *b_void_ptr){
    int *a_ptr = (int *)a_void_ptr;

}

int main(int argc, char** argv) {
    int S = 0;

    FILE* inputFile;

        // MATRIX A
    inputFile = fopen("A.dat", "r");
    if (inputFile==NULL){
        printf("ERROR READING FILE");
        exit(-1);
    }

    fscanf(inputFile, "%d", &S); // MATRIX SIZE

        // ALLOCATES MEMORY FOR MATRIX A
    int **matrix1;
    matrix1 = (int **) malloc(S*sizeof(int *));
    for (int i = 0; i < S; ++i)
        matrix1[i] = (int *) malloc(S*sizeof (int));

        //STORES MATRIX A TO matrix1
    for (int i
    = 0; i < S; ++i) {
        for (int j = 0; j < S; ++j) {
            fscanf(inputFile, "%d", &matrix1[i][j]);
        }
        printf("\n");
    }

    // MATRIX B
    inputFile = fopen("B.dat", "r");
    if (inputFile==NULL){
        printf("ERROR READING FILE");
        exit(-1);
    }

    fscanf(inputFile, "%d", &S); // MATRIX SIZE

    // ALLOCATES MEMORY FOR MATRIX B
    int **matrix2;
    matrix2 = (int **) malloc(S*sizeof(int *));
    for (int i = 0; i < S; ++i)
        matrix2[i] = (int *) malloc(S*sizeof (int));

    //STORES MATRIX A TO matrix1
    for (int i = 0; i < S; ++i) {
        for (int j = 0; j < S; ++j) {
            fscanf(inputFile, "%d", &matrix2[i][j]);
        }
        printf("\n");
    }
    fclose(inputFile);

    // ALLOCATES MEMORY FOR OUTPUT MATRIX 3
    int **matrix3;
    matrix3 = (int **) malloc(S*sizeof(int *));
    for (int i = 0; i < S; ++i)
        matrix3[i] = (int *) malloc(S*sizeof (int));








    /*
    int i, errorThread;
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        errorThread = pthread_create(&threads[i], NULL, Funct, NULL);
        if (errorThread){
            printf("ERROR CREATING THREAD [%d]. RETURN ERROR code %d\n", i, errorThread);
            exit(-1);
        }

        pthread_join(threads[i], NULL);
    }
     */



    free(matrix1);
    free(matrix2);
    free(matrix3);

}