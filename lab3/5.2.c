#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>


int readMatrix(char* fileName){

        // M = ROW, N = COLUMNS
    int M, N, i, j, max = 0; 

        // OPEN READ FILE FOR INPUT.DAT 
    FILE* inputFile;
    inputFile = fopen(fileName, "r");
    if (inputFile == NULL) {
        printf("Error Reading File\n");
        exit(0); 
    }

        // SAVES ROWS AND COLUMNS
    fscanf(inputFile, "%d %d", &M, &N);
    printf("Rows (M): %d\nColumns (N): %d\n", M, N);

        // ALLOCATES MEMORY FOR MATRIX A
    int **a;
    a = (int **) malloc(M * sizeof(int *));
    for ( i = 0; i < M; i++)
        a[i] = (int *) malloc(N * sizeof(int));


        // STORES MATRIX TO a AND PRINTS TO SCREEN
    for ( i = 0; i < M; i++)
    {
        for ( j = 0; j < N; j++){
                // Read the remaining elements of the input file and assign to 'a'
            fscanf(inputFile, "%d", &a[i][j]);
            
                // Print matrix 'a' into screen
            printf("%d ", a[i][j]);

                // Find the maximum number in matrix 'a'
            if (a[i][j] > max)
                max = a[i][j];
            
        }
        printf("\n");
    }
    
    printf("\nMaximum number in matrix: %d\n", max);


/*       
        // **WRITTEN INTO STORING LOOP
        // WRITES THE STORED DATA 
    for ( i = 0; i < M; i++)
    {
        for ( j = 0; j < N; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
*/

        // DEALLOCATES MEMORY
    free(a);
    fclose(inputFile);
}

int main(int argc, char const *argv[])
{
    readMatrix("input.dat");

    return 0;
}
