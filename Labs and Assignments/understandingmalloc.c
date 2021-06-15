//Wasay Khan
//wrkgch
//Malloc Practice 
//In this practice, we will be learning what the functions of malloc are. We will be using pointers and function prototypes. This exercise will be similar to the prelab
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void deposit(int*, float*, int);
void summary(int*, float*, int);

int main(void) 
{
    int menu1;
    printf("Hello there! How may I assist you?");
    printf("\nPlease pick an option\n1. Enter account details.\n2. Generate new account number.\n3. View account summary.");
    scanf("%d", &menu1);
    while (menu1<1||menu1>3) 
    {
        printf("Error! Please pick a valid option!");
        scanf("%d", &menu1);
    }

    switch(menu1)

