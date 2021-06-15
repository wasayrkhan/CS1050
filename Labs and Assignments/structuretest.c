//Wasay Khan
//wrkgch
//Structure Practice 

#include <stdio.h>
#include <stdlib.h>

struct something {
    int userID;
    char firstName[25];
    char lastName[25];
    int age;
    float weight;
}

int main(void) {
    struct user Becky;
    struct user Sam;

    Becky.userID=1;
    Sam.userID=2;

    puts("Enter the first name of user 1");
    gets(Becky.firstName);

    puts("Enter the first namw of user 2");
    gets(Sam.firstName);

    printf("User 1 ID is %d\n", Becky.firstName);
    printf("User 2 ID is %d\n", Sam.firstName);

    return 0;
}

