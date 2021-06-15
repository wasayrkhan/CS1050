//Wasay Khan
//wrkgch
//Lab X

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 25


int getPass(char*, char*);
int checkPass(char*);

int main(int argc, char** argv) 
{
    char* input = argv[1];
    char* output = argv[2];

    int x = getPass(input, output);

    printf("\nThere were %d valid password(s) written to the output file.\n", x);
    return 0; 
}

int getPass(char* input, char* output)
{
    int saveme;
    FILE* fPtr = fopen(input, "r");
    if (fPtr == NULL) 
    {
        printf("There was an error openeing the file %s\nReturning NULL to main...", input);
        return 0;
    }

    char* pIchangedit= malloc(sizeof(char) * MAX);

    FILE* fPtrOut = fopen(output, "w");
    if (fPtrOut == NULL) 
    {
        printf("There was an error openeing the file %s\nReturning NULL to main...", output);
        return 0;
    }

    while (!feof(fPtr))
    {
        fscanf(fPtr, "%s", pIchangedit);
        if (checkPass(pIchangedit) ==1)
        {
            fprintf(fPtrOut,"%s\n", pIchangedit);
            saveme++;
        }
    }


    return saveme;   
}

int checkPass(char* pIchangedit) 
{
    int i;
    int counter =0;
    int len=strlen(pIchangedit);

    if (len > 12 || len < 8) {
        return 0;
    }

    counter =0;

    for (i=0; i<len; i++) {
        int x = isupper(*(pIchangedit+i));
        if (x>0) {
            counter++;
        }

    }
    if (counter==0) {
        return 0;
    }

    counter =0;

    for (i=0; i<len; i++) {
        int y = islower(*(pIchangedit+i));
        if (y>0) 
        {
            counter++;
        }
    }

    if (counter==0) 
    {
        return 0;
    }

    counter =0;

    for (i=0; i<len; i++) {
        int t = isalnum(*(pIchangedit+i));
        if (t>0) 
        {
            counter++;
        }
    }
    counter  =0;

    for (i=0; i<len; i++)
    {
        int z= ispunct(*(pIchangedit+i));
        if (z>0)
        {
            counter++;
        }
    }
    if (counter==0) {
        return 0;
    }
    else
        return 1;
}

