#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void createAccounts(int*, float*, int);
int deposit(int*, float*, int);
int withdraw(int*, float*, int);
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
        printf("\nERROR! Out of memory!");
        return 1;
    }

    float* pAccts;
    pAccts = (float*) malloc(sizeof(float)* accts);
    if (pAccts==NULL)
    {
        printf("\nERROR! Out of Memory!");
        return 1;
    }

    createAccounts(ptrAccts, pAccts, accts);

    int choice;

    printf("\n***MENU***\n");
    printf("\n1)Deposit funds");
    printf("\n2)Withdraw funds");
    printf("\n3)Print active amount summary");
    printf("\n4)Exit\n");
    scanf("%d", &choice);

    while(choice!=5) {
        switch (choice) {
            case 1: 
                deposit(ptrAccts, pAccts, accts);
                break;

            case 2:
                withdraw(ptrAccts, pAccts, accts);
                break;

            case 3:
                summary(ptrAccts, pAccts, accts);
                break;

            case 4:
                summary(ptrAccts, pAccts, accts);
                return 0;
                break;

            default:
                printf("\nInvalid selection! Returning to main menu...");
                break;
        }

        printf("\n***MENU***\n");
        printf("\n1)Deposit funds");
        printf("\n2)Withdraw funds");
        printf("\n3)Print active amount summary");
        printf("\n4)Exit\n");
        scanf("%d", &choice);
    }
    return 0;
}

void createAccounts(int* ptrAccts, float* pAccts, int accts)
{
    int i;
    for (i=0; i<accts; i++)
    {
        printf("\nAccount %d PIN: ", i+1);
        scanf("%d", (ptrAccts+i));

        while (*(ptrAccts+i)<=999||*(ptrAccts+i)>9999)
        {
            printf("\nError! Please enter a 4 digit PIN: ");
            scanf("%d", (ptrAccts+i));
        }

        printf("\nAccount %d initial balance: ", i+1);
        scanf("%f", (pAccts+i));

        while (*(pAccts+i)<1)
        {
            printf("\nError! Initial deposit has to be at least $1!"); 
            printf("\nAccount %d initial balance: ", i+1);
            scanf("%f", (pAccts+i));
        }
    }
}


int deposit(int* ptrAccts, float* pAccts, int accts) {

    int pin; 
    printf("\nAccount PIN: ");
    scanf("%d", &pin);

    while (pin<=999||pin>9999) 
    {
        printf("ERROR! Please enter a 4 digit PIN: ");
        scanf("%d", &pin);
    }

    int i;
    float deposit; 
    for(i=0; i<accts; i++) {       
        if (pin==*(ptrAccts+i)) { 
            printf("\nDeposit amount: $");
            scanf("%f", &deposit);
            while (deposit<1){
                printf("\nError! Please enter a deposit amount great than $1!");
                printf("\nDeposit amount: $");
                scanf("%f", &deposit);
            }
            *(pAccts+i)=*(pAccts+i)+deposit;
            printf("\nDeposit successful!");
            return 1;
        }
    }

    return 0;
}


int withdraw(int* ptrAccts, float* pAccts, int accts) {

    int pin; 
    printf("\nAccount PIN:");
    scanf("%d", &pin);

    while (pin<=999||pin>9999) 
    {
        printf("ERROR! Please enter a 4 digit PIN: ");
        scanf("%d", &pin);
    }

    int i;
    float withdraw; 
    for(i=0; i<accts; i++) {       
        if (pin==*(ptrAccts+i)) { 
            printf("\nWithdraw amount: $");
            scanf("%f", &withdraw);

            while (withdraw>*(pAccts+i)){
                printf("\nWithdraw Error! Insufficient funds to make this withdrawal! Please verify PIN and available balance.");
                printf("\nWithdraw amount: $");
                scanf("%f", &withdraw);
            }
            while (withdraw<1){ 
                printf("\nWithdraw Error! Withdrawal amount must be greater than $1");
                scanf("%f", &withdraw);
            }

            *(pAccts+i)=*(pAccts+i)-withdraw;
            printf("\nWithdrawal successful!");
            return 1;
        }
    }

    return 0;
}


void summary(int* ptrAccts, float* pAccts , int accts) 
{
    int i;
    printf("\n*********************************");
    printf("\nActive Account Summary:");
    printf("\n*********************************");
    for (i=0; i<accts; i++) 
    {
        printf("\n%d   $%.2f\n", *(ptrAccts+i), *(pAccts+i));
    }
}


