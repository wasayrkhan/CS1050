#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getInput (void);
int menu (void);
int checkPrime (int);
int addDigits (int);
int rngLoop (int);

int main (void)
{
    int x = getInput();

    int choice =1;
    while(choice!=0){
        choice=menu();

        int prime, sum, even, odd; 

        switch (choice) {
            case 1: 
                prime=checkPrime(x);
                if (prime ==1)
                {
                    printf("%d is a prime number.", x);
                }
                else 
                {
                    printf("%d is not a prime number.", prime);
                }
                break;

            case 2: 
                sum=addDigits(x);

                printf("\nThe sum of the digits %d is %d", x, sum);
                break;


            case 3:
                even=rngLoop(x);
                odd = x- even;
                printf("\n%d even values and %d odd values generated", even, odd); 
                break;

            case 4:
                return 0;
                break;


            default:
                printf("\nInvalid selection! Returning to main menu...");
                break;
        }
    }
    printf("\n");
    return 0;
}
int getInput(void) {
    int x;

    printf("Please enter an integer between 0 and 1000:");
    scanf("%d", &x);

    while (x<0||x>1000) {
        printf("\nError! Please enter an integer such that 0 < int < 1000:");
        scanf("%d", &x);
    }
    return x;
}


int menu(void) {
    int choice; 

    printf("\n***** MAIN MENU *****\n");
    printf("\n1) Check prime number");
    printf("\n2) Add up individual digits");
    printf("\n3) Generate random values");
    printf("\n4) Exit\n");

    scanf("%d", &choice);

    while (choice<0||choice>4) {
        printf("Invalid selection! Returning to menu...\n");
        printf("\n***** MAIN MENU *****\n");
        printf("\n1) Check prime number");
        printf("\n2) Add up individual digits");
        printf("\n3) Generate random values");
        printf("\n4) Exit\n");

        scanf("%d", &choice);
    }

    return choice;
}


int checkPrime (int x)
{
    int y;
    int prime = 1;

    for (y=2; y<=x; y++)
    {
        if (x%y==0 && x!=y)
        {
            prime =0;

        }
        else {
            prime=1;
        }

    }

    return prime;        
}


int addDigits (int x)
{
    int sum = 0, t, remainder;

    t = x;
    while (t != 0)
    {
        remainder = t % 10;
        sum = sum + remainder; 
        t = t/10; 
    }

    return sum;
}

int rngLoop (int input) {
    srand(time(NULL));

    int i, random, even = 0;
    for (i=0; i<input; i++) {
        random= 1 + rand() % 999;

        printf("%4d", random);

        if (random%2 == 0) {
            even= even + 1;
        }
    }
    return even;
}


