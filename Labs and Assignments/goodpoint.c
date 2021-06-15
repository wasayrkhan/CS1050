#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

float* addValues(float*, int);
float* sort(float*, int); 
void calculations(float*, int);

int main(void) {

    int woohoo;
    printf("Please enter the number of values you wish to input: ");
    scanf("%d", &woohoo);

    while (woohoo<=0) {
        printf("\nTry again! Value must be a positive integer: ");
        scanf("%d", &woohoo);
    }

    float tiramisu[woohoo];
    float* ptrWoohoo= tiramisu;

    ptrWoohoo= addValues(ptrWoohoo, woohoo);

    ptrWoohoo= sort(ptrWoohoo, woohoo);

    calculations(ptrWoohoo, woohoo);

    return 0;
}

float* addValues(float* ptrWoohoo, int woohoo) {
    int i; 
    for (i=0; i<woohoo; i++) {
        printf("\nEnter a value: "); 
        scanf("%f", (ptrWoohoo+i));
    }

    return ptrWoohoo; 
}

float* sort(float* ptrWoohoo, int woohoo) {

    int x; 
    for (x=0; x<woohoo; x++) {

        printf("%f", *(ptrWoohoo+x));
    }


    int oranges, i;
    float hold;
    for (oranges=0; oranges<woohoo; oranges++) {
        for (i=oranges+1; i<woohoo; i++) {
            if ( *(ptrWoohoo+oranges) < *(ptrWoohoo+i)) {
                hold= *(ptrWoohoo+oranges);
                *(ptrWoohoo+oranges)= *(ptrWoohoo+i);
                *(ptrWoohoo+i)=hold;
            }
        }
    }

    printf("\nSorted values in descending order:\n");
    int lollapalooza;
    for (lollapalooza=0; lollapalooza<woohoo; lollapalooza++) {
        printf("%f\n", *(ptrWoohoo+lollapalooza));
    }
    return ptrWoohoo;
}

void calculations(float* ptrWoohoo, int woohoo) {

    int i;
    float sum= 0.0;
    for (i=0; i<woohoo; i++) {
        sum+= *(ptrWoohoo+i);
    }
    float mean;
    mean=sum/woohoo;
    printf("\nMean of the data set %f", mean);

    int ratata = woohoo % 2;
    float median;
    switch (ratata) 
    {
        case 1:
            median= *(ptrWoohoo + (woohoo/2));
            break;

        case 2:
            median= ((*(ptrWoohoo + woohoo/2) + *(ptrWoohoo+(woohoo/2 -1)))/2);
            break;
    }

    printf("\nMedian of the data set is %f\n", median);

    float range;
    range = *ptrWoohoo- *(ptrWoohoo + (woohoo -1));
    printf("Range of the data set: %f\n", range);

}

