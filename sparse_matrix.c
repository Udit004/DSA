// sparse matrix representation in triple format

#include<stdio.h>
#include<stdlib.h>

int **allocate(int **mat, int r, int c)  //allocation of matrix
{
    int i;
    mat = (int **)malloc(r*sizeof(int*));
    for(i=0; i<r; i++)
    {
        mat[i] = (int*)malloc(c*sizeof(int));
    }
    return mat;
}

void insert(int** mat, int r, int c)   //inserting data in matrix
{
    int i, j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
}

void display(int **mat, int r, int c)   //for display content of matrix
{
    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    int i,j,r,c,trows=0,row[100],col[100],tval[100];   //Declare row for triple format
    int u=1;
    int **matrix;

    printf("enter the row and column of matrix: ");  //taking input of rows and column
    scanf("%d%d",&r,&c);
    matrix = allocate(matrix,r,c);


    printf("enter the element of matrix\n");   //inserting data in matrix
    insert(matrix ,r,c);


    printf("element of the matrix is\n");  //display element 
    display(matrix,r,c);



    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(matrix[i][j] != 0)       //checking for non zero element in matrix
            {
                row[u] = i;
                col[u] = j;                       //putting value of non zero element to tiple format
                tval[u] = matrix[i][j];
                u++;
            }  
             
        }
    }

    row[0] = r;
    col[0] = c;                                      // first row of triple format
    tval[0] = u-1;

    printf("triplet form of spare matrix\n");    //display triple format

    for(i=0; i<u; i++)
    {
        printf("%d\t",row[i]);
        printf("%d\t",col[i]); 
        printf("%d\n",tval[i]);
    }
    printf("\n");

    return 0;
}
