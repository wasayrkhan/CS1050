//Wasay Khan
//wrkgch
//Pre-Lab X

#define MAX 25
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* getPass(char*);
int checkPass(char*);

int main(int argc, char **argv) {

    if (argc!=2) {
        printf("Command line usage ./a.out <input_filename>");
        return 0; 
    }

    char* input = *(argv +1); 
    char* pass = getPass(input);

    if (pass ==NULL)
    {
        printf("Exiting program. Check your input file. \n\n");
        exit(0);
    }

    while (checkPass(pass) == 0)
    {
        printf("Please enter a valid password.\n8-12characters in length, one uppercase, one lowercase and one special character...\n...");
        scanf("%s", pass);
    }

    printf("%s is a valid password!\nFreeing memory and exiting...\n\n", pass);
    free(pass);
    return 0;
}

char* getPass(char* input) 
{
    FILE* fPtr = fopen(input, "r");
    if (fPtr == NULL)
    {
        printf("There was an error opening the file %s\n Returning NULL to main...", input);
        return NULL;
    }
    char* pass = malloc(sizeof(char) * MAX);
    fscanf(fPtr, "%s", pass);
    fclose(fPtr);
    return pass;
}

int checkPass(char *pass)
{
    int i;
    int counter =0;
    for (i=0; i<=12;i++) {
        if (*(pass+i)>0) {
            counter++;
        }
    }

    if (counter > 12 || counter < 0) {
        return 0;
    }

    counter =0;

    for (i=0; i<12; i++) {
        int x = isalpha(*(pass+i));
        if (x>0) {
            counter++;
        }

    }
    if (counter==0) {
        return 0;
    }

    counter =0;

    for (i=0; i<12; i++) {
        int y = isalnum(*(pass+i));
        if (y>0) 
        {
            counter++;
        }
    }

    if (counter==0) 
    {
        return 0;
    }

    counter  =0;

    for (i=0; i<12; i++)
    {
        int z= ispunct(*(pass+i));
        if (z>0)
        {
            counter++;
        }
    }

    if (counter ==0) {
        return 0;
    }

    else 
        return 1;
}

