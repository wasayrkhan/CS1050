#include <stdio.h>

int main (void)
{
    int integer1, integer2;

    printf("Enter first number\n");
    scanf("%d", &integer1);
    if (integer1<0 || integer1>10){
        printf("The number must be between 0 and 10!\n");
        printf("Re-enter the first number\n");
        scanf("%d", &integer1);
    }

    printf("Enter second number\n");
    scanf("%d", &integer2);
    if (integer2<0 || integer2>10){
        printf("The number must be between 0 and 10!\n");
        printf("Re-enter the second number\n");
        scanf("%d", &integer2);
    }


    printf("\nSum of the two numbers is %d", integer1+integer2);
    printf("\nDifference between the two numbers is %d", integer1-integer2);
    printf("\nProduct of the two numbers is %d\n", integer1*integer2);

    int product = integer1*integer2;
    if (product%2 ==0) {
        printf("The product of the two numbers is even\n");
    }
    else {
        printf("The product of the two numbers is odd\n");
    }

    if (integer1 == integer2) {
        printf("The first number and the second number are equal to each other\n");
    } 
    else 
        if (integer1 > integer2) {
            printf("The first number is greater than the second number\n");
        } 
        else {
            printf("The second number is greater than the first number\n");
        }

    return 0;
}
