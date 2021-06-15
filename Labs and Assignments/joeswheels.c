#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void getCars(int*, float*, int*, char*);
float reserve(int*, float*, int, int);
void printInventory(int*, float*, int*, int);
void writeToFile(int*, float*, int*, char*, int);


int main(int argc, char** argv)
{
    int carNumber=atoi(argv[2]);
    char* input= argv[1];
    char* reservation= argv[3];
    char* output= argv[4];

    int* ptrID;
    ptrID = (int*) malloc(sizeof(int)* carNumber);
    if (ptrID==NULL) 
    {
        printf("\nERROR! Out of memory!");
        return 1;
    }

    int* ptrMile; 
    ptrMile = (int*) malloc(sizeof(int)* carNumber);
    if (ptrMile==NULL)
    {
        printf("\nERROR! Out of memory!");
        return 1;
    }

    float* ptrPrice;
    ptrPrice = (float*) malloc(sizeof(float)* carNumber);
    if (ptrPrice==NULL)
    {
        printf("\nERROR! Out of memory!");
        return 1;
    }

    getCars(ptrID, ptrPrice, ptrMile, input);

    float totalrev=0;
    FILE *fPtrCarRes = fopen(reservation, "r");
    if (fPtrCarRes == NULL) 
    {
        printf("There was an error opening the file %s\nReturning NULL to main...", input);
    }

    int reserveID;
    while (!feof(fPtrCarRes)) 
    {
        fscanf(fPtrCarRes, "%d", &reserveID);       
        totalrev+=reserve(ptrID, ptrPrice, reserveID, carNumber);
    }

    printf("\nProcessing reservations...\n");
    printInventory(ptrID, ptrPrice, ptrMile, carNumber);

    int vehicleID;
    float r;

    do
    {
        printf("\nEnter the vehicle ID for the desired rental (0 to exit): ");
        scanf("%d", &vehicleID); 
        r = reserve(ptrID, ptrPrice, vehicleID, carNumber);
        printInventory(ptrID, ptrPrice, ptrMile, carNumber);
        //r=reserve(ptrID, ptrPrice, vehicleID, carNumber);
        totalrev+=r;
        if (r==0)
        {
            printf("\nReservation unsuccessful! The vehicle is not in our inventory");
        }

    }while (vehicleID!=0);

    printf("\nTotal profits: $%.2f", totalrev);

    printf("\nWriting remaining inventory to %s\n", output); 
    writeToFile(ptrID, ptrPrice, ptrMile, output, carNumber);

    printf("Freeing memory and exiting...\n");
    fclose(fPtrCarRes);
    free(ptrID);
    free(ptrPrice);
    free(ptrMile);

    return 0;
}

void getCars(int* ptrID, float* ptrPrice, int* ptrMile, char* input) 
{
    int i=0;
    FILE* fPtr = fopen(input, "r");
    if (fPtr == NULL)
    {
        printf("There was an error opening the file %s\nReturning NULL to main...", input);
    }

    printf("*** Current inventory ***\n");
    while (!feof(fPtr))
    {
        fscanf(fPtr, "%d    %f  %d\n", (ptrID+i), (ptrPrice+i), (ptrMile+i));
        printf("%d  %.2f  %d\n", *(ptrID+i), *(ptrPrice+i), *(ptrMile+i));
        i++;
    }

    fclose(fPtr);
}

float reserve(int* ptrID, float* ptrPrice, int reserveID, int carNumber)
{
    int i;
    float crap=0;

    if (reserveID==0)
    {
        return 0;
    }

    for(i=0; i<carNumber; i++)
    {
        if (*(ptrID+i)==reserveID)
        {
            *(ptrID+i)=0;
            crap=*(ptrPrice+i);
        }
    }
    return crap;
}

void printInventory(int* ptrID, float* ptrPrice, int* ptrMile, int carNumber)
{
    int i=0;
    printf("\n*** Current inventory ***\n");
    for(i=0; i<carNumber; i++)
    {
        if (*(ptrID+i)==0)
        {
            continue;
        }
        printf("%d  %.2f  %d\n", *(ptrID+i), *(ptrPrice+i), *(ptrMile+i));
    }
}

void writeToFile(int* ptrID, float* ptrPrice, int* ptrMile, char* output, int carNumber) 
{
    FILE* fCars = fopen(output, "w");
    if (ptrID != 0)
    {
        fprintf(fCars, "%d", *(ptrID)); 
    }
    fclose(fCars);
}

