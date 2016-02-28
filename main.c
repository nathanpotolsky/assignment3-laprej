/*********************************************************************************/
/* Assignment 3: 2-D/ NxN Matrix Swap and  Multiplication ************************/
/* Name: YOUR NAME GOES HERE *****************************************************/
/*********************************************************************************/

/*********************************************************************************/
/* Usual suspects to include *****************************************************/
/*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

/*********************************************************************************/
/* Function Calls ****************************************************************/
/*********************************************************************************/

void mm_print( int size, double **matrix );

double **mm_transpose( int size, double **matrix );

double **mm_matrix_mult( int size, double **matrix, double **transpose );

double **mm_alloc( int size )
{
    int i = 0;
    double **matrix = (double **)calloc( size, sizeof(double *) );

    if ( matrix == NULL ) {
        printf("mm_alloc: calloc failed \n");
        return( (double **)NULL );
    }

    for ( i = 0; i < size; i++) {
        matrix[i] = (double *)calloc( (size), sizeof(double));
        if ( matrix[i] == NULL ) {
            printf("mm_alloc: calloc failed \n");
            return( (double **)NULL );
        }
    }

    return matrix;
}

void mm_free( int size, double **matrix )
{
    int i=0;

    for ( i = 0; i < size; i++ ) {
        // free does not return a value
        free( matrix[i] );
    }

    // free does not return a value
    free( matrix );
}

double **mm_read( char *filename, int *size )
{
    FILE *matrix_data=NULL;
    double **matrix=NULL;
    char buffer[256];
    int i=0, j=0;

    if ( NULL == (matrix_data = fopen( filename, "r" )) ) {
        printf("Error in main: failed to open file for reason: %s \n",
               strerror( errno ) );
        exit(-1);
    }

    if ( NULL == fgets( buffer, 256, matrix_data ) ) {
        printf("mm_read: fgets failed on stdin for reason %s\n",
               strerror(errno) );
        exit(-1);
    }

    if ( 1 != sscanf( buffer, "%d", size ) ) {
        printf("mm_read: sscanf failed to read size correctly \n");
        exit(-1);
    }

    if ( NULL == (matrix = mm_alloc( *size )) ) {
        printf("mm_read: mm_alloc failed for matrix \n");
        exit(-1);
    }

    // Think of having some number of NxN matrices
    for ( i = 0; i < *size; i++ ) {
        for ( j = 0; j < *size; j++ ) {
            if ( NULL == fgets( buffer, 256, matrix_data ) ) {
                printf("mm_read: fgets failed on stdin for reason %s\n",
                       strerror(errno) );
                exit(-1);
            }
            if ( 1 != sscanf( buffer, "%lf", &(matrix[i][j]) )) {
                printf("mm_read: sscanf failed to read matrix[%d][%d] correctly \n", i, j);
                exit(-1);
            }
        }
    }

    if ( 0 != fclose( matrix_data ) ) {
        printf("mm_read: fclose failed for reasy %s\n", strerror(errno));
    }

    return matrix;
}

int main()
{
    /*
     * you must keep this function AS IS.
     * you cannot modify it!
     */
    char filename[256];
    double **matrix=NULL;
    double **swap_matrix=NULL;
    double **results_matrix=NULL;
    int size=0;

    printf("Please enter the matrix data file name: ");
    scanf( "%s", filename );

    matrix = mm_read( filename, &size );
    swap_matrix = mm_transpose( size, matrix );
    results_matrix = mm_matrix_mult( size, matrix, swap_matrix );

    mm_print( size, results_matrix );
    mm_free( size, matrix );
    mm_free( size, swap_matrix );
    mm_free( size, results_matrix );
    return 0;
}
