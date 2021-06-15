//Wasay Khan
//wrkgch
//Pre-Lab4

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getInput (void);
void rngLoop(int);

int main (void)
{ 
    int x = getInput();
    rngLoop(x);
    return 0;
}

int getInput(void) {

    int x;

    printf("Please enter an integer between 0 and 100:");
    scanf("%d",&x);

    while (x<1|| x>=100) {
        printf("Error! Valid numbers are from 1-99!");
        printf("Please enter an integer between 0 and 100:");
        scanf("%d", &x);
    }


    return x;
}

void rngLoop(int input) {
    srand(time(NULL));

    int i, random;
    for (i=0; i<input; i++) {
        random= 1+ rand() % 99;
        printf("%4d", random);
    }
    printf("\n");
}

