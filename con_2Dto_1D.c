#include<stdio.h>
#include<stdlib.h>

int main()
{
    int r,c,i,j;

    printf("enter the row and colume of matrix\n"); 
    scanf("%d%d",&r,&c);


    int **matrix = (int**)malloc(r*sizeof(int*));
    for(i=0;i<r;i++)                                       //allocation of matrix
    {
        matrix[i] = (int*)malloc(c*sizeof(int));
    }

    printf("enter element of matrix\n");                  //inserting data in matirx
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }

    
    int *arr = (int *)malloc(r*c*sizeof(int));  // allocation and inserting data to 1D array

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            arr[i*r+j] = matrix[i][j];
        }
    }

    printf("element in 1D array\n");           //display element of 1D array
    for(i=0; i<r*c;i++)
    {
        printf("%d  ",arr[i]);
    }


    for(i=0;i<r;i++)
    {
        free(matrix[i]);                      // free memory
    }
    free(matrix);
    free(arr);

    
}