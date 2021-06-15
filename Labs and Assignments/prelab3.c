//Wasay Khan
//wrkgch
//Pre-Lab 3
//
#include <stdio.h>

int number; 

int main (void)
{
    int x;

    printf("Please enter an integer between 1-99:");
    scanf("%d", &number);

    while (number < 1||number >99) {
        printf("Invalid number! Re-enter a valid integer between 1-99:");
        scanf("%d", &number);
    }

    for (x = 1  ; x<= number; x++) {
        printf(" %d ", x);
    }

    if (number % 2 == 0){
        printf("\nThe integer is even.\n");
    }
    else {
        printf("\nThe integer is odd.\n");
    }

    return 0;
}
