#include<stdio.h>
#include<stdlib.h>

typedef struct polynomial
{
    float coeff;
    int exp;
}poly;

poly term[100];

int main()
{
    int i=0, j=0, k, m, numOfPoly, numOfTerms;
    printf("How many polynomials you want to add: ");
    scanf("%d",&numOfPoly);
    printf("\n");
    while(numOfPoly)
    {
        printf("how many terms: ");
        scanf("%d",&numOfTerms);
        printf("\nEnter the coeff and exps\n");
        k=0;
        while(numOfTerms)
        {
            scanf("%f %d",&term[i].coeff, &term[i].exp); 
            i++;
            k++;
            numOfTerms--;
        }
        j++;
        k--;
        printf("%d polynomial terms is : ",j);
        for(m=i-1; m>=i-k-1; m--)
        {
            if(term[m].coeff > 0)
            {
                if(term[m].exp == 0)
                {
                    printf("+ %.2f",term[m].coeff);
                }
                else
                {
                    printf("+ %.2fx^%d ",term[m].coeff, term[m].exp);
                }
            }
            if(term[m].coeff < 0)
            {
                if(term[m].exp == 0)
                {
                    printf("%.2f ",term[m].coeff);
                }
                else
                {
                    printf("%.2fx^%d ",term[m].coeff, term[m].exp);
                }
            }
            
            
        }
        printf("\n");
        numOfPoly--;
    }
    i--;
    for(j=0; j<i; j++)
    {
        for(k=j+1; k<=i; k++)
        {
            if((term[j].coeff > 0) && (term[k].coeff > 0)&&(term[j].exp == term[k].exp))
            {
                term[j].coeff += term[k].coeff;
                term[k].coeff = 0;
            }
            if((term[j].coeff < 0) && (term[k].coeff < 0)&&(term[j].exp == term[k].exp))
            {
                term[j].coeff += term[k].coeff;
                term[k].coeff = 0;
            }
        }
    }
    printf("\nThe added polynomial is: ");
    for(j=0; j<i; j++)
    {
        if(term[j].coeff > 0)
            {
                if(term[j].exp == 0)
                {
                    printf("+ %.2f",term[j].coeff);
                }
                else
                {
                    printf("+ %.2fx^%d ",term[j].coeff, term[j].exp);
                }
            }
            if(term[j].coeff < 0)
            {
                if(term[j].exp == 0)
                {
                    printf("%.2f ",term[j].coeff);
                }
                else
                {
                    printf("%.2fx^%d ",term[j].coeff, term[j].exp);
                }
            }
    }
    printf("\nThis code is created by Udit Kumar Tiwari, Roll-2351109 \n");
    return 0;
}