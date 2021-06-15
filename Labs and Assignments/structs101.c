// Jacob Zimmer
// jlz6w7
// CS1050 Lab 11 (FS17)

#include <stdio.h>
#include <stdlib.h>

typedef struct vehicle {    // The "struct" keyword allows us to link related information together under one abstract data type
    char make[20];
    char model[20];
    int miles;
    float price;
} Car;  /*  The string that follows a "typedef" is what that variable will be known as within your program
            This means that "Car" is a new abstract data of type "struct vehicle"
            This does NOT mean that "Car" is a variable instance of type "struct vehicle"
            You will have to individually declare and initialize variables of type "Car" as you would with a primitive data type
            */

Car* getInfo(int);
void printInfo(int, Car*);

// All necessary variables have been included for you. Do not add additional variable declarations
int main(void)
{
    int count;      // The number of vehicles for which information is to be entered, provided by the user
    Car* inventory; // A pointer to an empty list of "Cars" (remember to use an index!)

    do {
        printf("How many vehicles are you entering data for: ");
        scanf("%d", &count);
    } while (count <= 0);

    inventory = getInfo(count);
    printInfo(count, inventory);

    printf("\n");
    free(inventory);    // Because array notation was used for the character strings inside the struct, only one free() is necessary
    return 0;
}

/*  Accepts an integer that contains the user-given number of vehicles
    Malloc for a Car pointer whose length is based on this integer then use a for loop to fill the data fields of each index
    Think of each index as a single car that has all of the properties from the typedef and the pointer as an inventory listing
    Once every index has been filled, return the pointer that you allocated memory for to main
    */
Car* getInfo(int size)
{
    // YOUR CODE GOES HER
    Car* inventory=malloc(sizeof(Car)*size);

    int i;

    for(i=0;i<size;i++) {
        printf("\nEnter the vehicle make: ");
        scanf("%s", (inventory+i)->make);
    }

    int j;
    for(j=0;j<size;j++) {
        printf("\nEnter the vehicle model: ");
        scanf("%s", (inventory+j)->model);
    }

    int k; 
    for(k=0;k<size;k++) {
        printf("\nEnter the total mileage: ");
        scanf("%d", (inventory+k)->miles);
    }

    int p;
    for(p=0;p<size;p++) {
        printf("\nEnter the price of the vehicle: ");
        scanf("%f", (inventory+p)->price);
    }
    return inventory;
}

/*  Accepts an integer that contains the user-given number of vehicles and a pointer to the list of Cars
    Use a for loop to iterate through each index of the pointer and printf information about each vehicle
    Refer to the sample output on the TA's screen for formatting help
    */
void printInfo(int size, Car* inventory)
{
    // YOUR CODE GOES HERE
    int i;
    for(i=0;i<size;i++) {
        printf("\nMake: %s", (inventory+i)->make);
        printf("\nModel: %s", (inventory+i)->model);
        printf("\nMiles: %s", (inventory+i)->miles);
        printf("\nPrice: %d", (inventory+i)->price);
    }

}

/*  NOTES ON ACCESSING STRUCT MEMBERS

    There are two ways you can get or set information with struct members:

    Dot operator:           Arrow operator:
    struct.info             struct->info

    So when are you supposed to use each method?
    Short (oversimplified) answer: dot is for array notation, arrow is for pointer notation.
    This is because the arrow operator implies that a dereference needs to occur (think about how this will affect the syntax of printf and scanf).
    The following three examples are theoretically the same:

    (Car + i)->miles
    (*(Car + i)).miles
    Car[i].miles

    When using pointers and dynamically allocated memory, dereferencing using an index is a necessity.
    Therefore, the arrow operator should be used because it indicates that the struct is a pointer (or part of a pointer list).
    The necessity of having two distinct operators becomes more evident when implementing things like nested structs and linked lists.
    But for the purposes of this lab, use pointer notation and the arrow operator.
    */
