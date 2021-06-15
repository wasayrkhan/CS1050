//Wasay Khan
//wrkgch
//Lab 7

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 25

int length(char[]);
int replace(char[], int);
void concatenate(char[], char[]);
void sort(char[]);

int main(void) {
    char string[MAX];

    printf("Enter the first string: ");
    scanf("%s", string);

    int stringSize=length(string);
    printf("\nLength of the first string: %d", stringSize);

    int repPosition;
    printf("\nEnter a position for the replacement operation between 1-5: ");
    scanf("%d", &repPosition);

    replace(string, repPosition); 


    while (replace(string, repPosition)==0) {
        printf("Invalid position! Enter a position between 1 and %d: " ,stringSize);
        scanf("%d", &repPosition);
    } 
    printf("First string after replacement operation is %s",string);


    char string2[MAX];

    printf("\nEnter the second string: ");
    scanf("%s", string2);

    concatenate(string, string2);

    printf("The first string after concatnation with the second is: %s", string);

    printf("\nFirst string before sorting is %s", string);
    sort(string);
    printf("\nFirst string after sorting: %s\n", string);


    return 0;
}

int length(char string[]) {
    int i, apples=0;
    for(i=0; string[i]!='\0'; i++) {
        apples+=1;
    }
    return apples;
}

int replace(char string[], int repPosition) {   

    int something=length(string);

    if (repPosition>something||repPosition<0) {
        return 0;
    }
    else {
        string[repPosition-1]='#';        
        return 1;
    }   
}

void concatenate(char string[], char string2[]) {
    int i;
    int j=0;
    int length1= length(string);
    int length2= length(string2);

    for (i=length1; i< length1+length2; i++) {
        string[i] = string2[j];
        j++;
    }
    string[i]='\0';
}

void sort(char string[]) {
    int bananas, i, hold;
    int stringLength= length(string);
    for (bananas=1; bananas <stringLength; bananas++) {
        for (i=0; i< stringLength-1; i++) {
            if(string[i] > string[i+1]) {
                hold=string[i];
                string[i]=string[i+1];
                string[i+1]=hold;
            }
        }
    }
}

