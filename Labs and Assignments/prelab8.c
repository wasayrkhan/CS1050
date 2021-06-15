//Wasay Khan
//wrkgch
//Pre-Lab 8

#include <stdio.h>
#define MAX 100

char* getInput(void);
char* changeString(char*);

char* getInput(void) {
    char a[MAX];
    printf("Please enter a character string: ");
    scanf("%s", a);

    char *pA= a;
    printf("\n%d", *pA);
    return pA;
}

char* changeString(char* fish) {
    char b[MAX];
    printf("\nPlease enter a replacement string: ");
    scanf("%s", b);

    fish=b;
    return fish;

}

int main(void) {

    char* fish=getInput();
    printf("\nString %s is stored at memory address %p", fish, fish);

    fish=changeString(fish);

    printf("\nString %s is stored at memory address %p\n", fish, fish);

    return 0;
}

