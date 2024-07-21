#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float **allocate(float **mat , int n)
{
    int i;
    mat = (float **)malloc(n*sizeof(float*));
    for (i=0; i<n; i++)
    {
        mat[i] = (float*)malloc(n*sizeof(float));
    }
    return mat;
}


void insert(float **mat, int n)
{
    int i,j;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            mat[i][j] = (float)rand() / RAND_MAX;
        }
    }
}

void display(float **mat, int n)
{
    int i,j;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            printf("%.2f  ",mat[i][j]);
        }
        printf("\n");
    }
}

void freemat(float **mat, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        free(mat[i]);
    }
    free(mat);
}


int main(){

    clock_t start_time, end_time;
    double cpu_time_used;
    start_time = clock();


    int i,j,k,n;
    float sum=0;
    float **matrixOne, **matrixTwo, **resultMatrix;
    printf("enter the size of matrix: ");
    scanf("%d",&n);

    //allocate
    matrixOne = allocate(matrixOne , n);
    matrixTwo = allocate(matrixTwo , n);
    resultMatrix = allocate(resultMatrix , n);


    //insert

    printf("enter the element of matrixOne: ");
    insert(matrixOne, n);

    printf("enter the element of matrixTwo: ");
    insert(matrixTwo, n);

    //matrix multiplication
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            sum = 0;
            for (k=0; k<n; k++)
            {
                sum += matrixOne[i][k]*matrixTwo[k][j];
            }
            resultMatrix[i][j] = sum;
        }
    }

    printf("matrixOne is: \n");
    display(matrixOne,n);
    printf("matrixTwo is: \n");
    display(matrixTwo,n);

    printf("resultant matrix is: \n");
    display(resultMatrix,n);

    // free matrix
    freemat(matrixOne,n);
    freemat(matrixTwo, n);
    freemat(resultMatrix,n);



    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("execution time :%f seconds\n", cpu_time_used);

    printf("This code is created by Udit Kumar Tiwari. Roll-2351109 \n");

    
    return 0;
}
