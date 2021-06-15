//Wasay Khan
//wrkgch
//Prelab 9


#include <stdio.h>
#include <stdlib.h>

void deposit(int*, float*, int);
void summary(int*, float*, int);

int main(void)
{
    int accts;

    printf("How many accounts are to be created? ");
    scanf("%d", &accts);

    while (accts<=0) 
    {
        printf("\nError! Please enter an integer more than one!");
        scanf("%d", &accts);
    }

    int* ptrAccts;
    ptrAccts = (int*) malloc(sizeof(int)* accts);
    if (ptrAccts==NULL)
    {
        printf("\nERROR: Out of Memory!");
        return 1;
    }
    float* pAccts;                                                  //dataType varName=malloc(sizeof(dataType)* size//
    pAccts = (float*) malloc(sizeof(float)* accts);
    if (ptrAccts==NULL)
    {
        printf("\nERROR: Out of Memory!");
        return 1;
    }

    deposit(ptrAccts, pAccts, accts);
    summary(ptrAccts, pAccts, accts);

    return 0;
}


void deposit(int* ptrAccts, float* pAccts, int accts)
{
    int i;
    for (i=0; i<accts; i++) 
    {
        printf("\nAccount %d PIN: ", i+1);
        scanf("%d", (ptrAccts+i));

        while (*(ptrAccts+i)<=999||*(ptrAccts+i)>9999)
        {
            printf("\nError! Please enter a 4 digit PIN: ");
            scanf("%d" ,(ptrAccts+i));
        }


        printf("\nAccount %d initial balance: ", i+1);
        scanf("%f", (pAccts+i));

        while (*(pAccts+i)<1)
        {
            printf("\nError! Initial deposit has to be at least $1!");
            printf("\nAccount %d initial balance: ",i+1);
            scanf("%f", (pAccts+i));
        }

    }
}


void summary(int* ptrAccts, float* pAccts , int accts) 
{
    int i;
    printf("\n*********************************");
    printf("\nActive Account Summary:");
    printf("\n*********************************");
    for (i=0; i<accts; i++) 
    {
        printf("\n%d   $%f\n", *(ptrAccts+i), *(pAccts+i));
    }
}

