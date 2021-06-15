#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getInput(void);
int rngMax(void);
void initializeArray(int,int);
int arrayMin(int[],int);
int arrayMax(int[],int);
double arrayAvg(int[],int);


int getInput(void) {
    int x;

    printf("Enter the size of the array to be generated: ");
    scanf("%d", &x);

    while (x<0||x>100) {
        printf("\nInvalid number! Enter a number between 0 and 100: ");
        scanf("%d", &x);
    }

    return x;
}

int rngMax(void) {

    int size;

    printf("\nEnter the maximum random value to be inserted in the array: ");
    scanf("%d", &size);

    while (size<0||size>100) {
        printf("\nInvalid number! Enter a maximum random value between 0 and 100: ");
        scanf("%d", &size);
    }

    return size;
}

void initializeArray(int size, int max) {
    srand(time(NULL));

    int a[100];

    int i, random;
    for (i=0; i<size; i++) {
        random= 1 + rand() % max;
        a[i]=random;  
        printf(" %d\n", random);
    }

    int maximum = arrayMax(a, size);
    int minimum = arrayMin(a, size);
    double avg = arrayAvg(a, size);

    printf("The minimum value is %d and occurs at index %d\n" , a[minimum], minimum);
    printf("The maximum value is %d and occurs at index %d\n" , a[maximum], maximum);
    printf("The mean of the data set is %.7f\n" , avg);

}

int arrayMax(int a[], int size) {

    int i;
    int maxIndex =0;

    for (i=0; i<size; i++) {
        if (a[i] > a[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int arrayMin(int a[], int size) {

    int i;
    int minIndex =0;

    for (i=0; i<size; i++) {
        if (a[i] < a[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

double arrayAvg(int a[], int size) {

    int i;
    int sum=0;
    double average;

    for (i=0; i<size; i++) {
        sum+=a[i];
    }

    average = sum/size; 

    return average;
}

int main(void) {
    int size= getInput();
    int max= rngMax();

    initializeArray(size, max);

    return 0;
}






















