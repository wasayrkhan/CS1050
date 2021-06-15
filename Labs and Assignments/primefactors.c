//Wasay Khan
//wrkgch
//CS1050 Lab 3 

#include <stdio.h>
#include <math.h>

int main (void)
{
    int number, x, y; 
    int choice=1;
    printf("Enter a number between 0 and 100:");
    scanf("%d", &number);

    while (number <0||number>100)
    {
        printf("\nThe number is outside the acceptable range!\n");
        printf("Enter an number between 0 and 100:");
        scanf("%d",&number);
    }
    while( choice!=0)
    {
        printf("\nPlease select an option from the following choices.\n\n1) List all prime factors\n2) Factorize the integer\n0) Exit\n\n");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                for (x=2; x<=number; x++)
                {
                    int prime = 0;

                    for (y=2; y<=x; y++)
                    {
                        if (x%y==0 && x!=y)
                        {
                            prime =1;
                        }

                    }
                    if (prime==0)
                    {
                        printf("%d ", x);
                    }

                }
                break;

            case 2:
                printf("Factors of %d\n", number);
                int factor;  
                for (factor=1; factor<=number; factor++)
                {
                    if (number%factor == 0) 
                    {
                        printf("%d ", factor);
                    }

                }
                break;

            case 0: 
                {
                    return 0;
                }
                break;

            default:
                printf("This is not a valid option. Returning to menu...\n");
                break;

        }

    }
    return 0; 
}









