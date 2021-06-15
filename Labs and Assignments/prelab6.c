//Wasay Khan
//wrkgch
//PreLab 6

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getInput(void);
int rngMax(void);
double initializeArray(int,int);

int main (void)
{
    int input = getInput();
    int maxInput = rngMax();

    double total = initializeArray(input,maxInput); 

    printf("The sum of all the values is %lf." ,total);

    printf("\n");


    return 0;
}

int getInput (void) {
    int x;

    printf("Enter the size of the array to be generated: ");
    scanf("%d", &x);

    while (x<0||x>100) {
        printf("\nInvalid number! Enter a number between 0 and 100: ");
        scanf("%d", &x);
    }

    return x;
}

int rngMax (void) {

    int size;

    printf("\nEnter the maximum random value to be inserted in the array: ");
    scanf("%d", &size);

    while (size<0||size>100) {
        printf("\nInvalid number! Enter a maximum random value between 0 and 100: ");
        scanf("%d", &size);
    }

    return size;
}

double initializeArray (size, max) {
    srand(time(NULL));

    int a[100];

    int i, random;
    double sum=0;
    for (i=0; i<size; i++) {
        random= 1 + rand() % max;
        a[i]=random;
        sum+=a[i];
    }

    return sum;
}














