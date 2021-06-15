#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

char getCounter(void);
char game(char, char);
void printBoard(void);
int turn(char, int);
int victory(char,int);

char board [6][7] = {{'-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-'},
    {'-','-','-','-','-','-','-'}};

char getCounter(void) {
    char letter;

    printf("enter your letter (A-Z): " );
    scanf(" %c", &letter);

    while (letter<65||letter>90) {
        printf("\nInvalid letter! Please enter a letter between 'A' and 'Z': ");
        scanf(" %c", &letter);
    }

    return letter; 
}

char game(char letter1, char letter2) {

    int victoryStatus1=0;
    int victoryStatus2=0;
    while (victoryStatus1!=1 && victoryStatus2!=1) {

        int column;

        printf("\n%c, your turn. Enter a column to drop into: ", letter1);
        scanf("%d", &column);

        while (column<0||column>6){
            printf("\nError! That column does not exist! %c, re-enter a column: ", letter1);
            scanf("%d", &column);
        }

        while (board[0][column] != '-'){
            printf("\nError! That position is already taken! Please re-enter a column: ");
            scanf("%d", &column);
        }

        int itsherturn=turn(letter1, column);

        if (itsherturn==1) {
            victoryStatus1=victoryStatus1 +1;
            printBoard();
            return letter1;
        }
        printBoard();

        printf("\n%c, your turn. Enter a column to drop into: ", letter2);
        scanf("%d", &column); 

        while (column<0||column>6) {
            printf("\nError! That column does not exist! %c, re-enter a column: ", letter2);
            scanf("%d", &column);
        }

        while (board[0][column] != '-') {
            printf("\nError! That position is already taken! Please re-enter a column: ");
            scanf("%d", &column);
        }


        int itshisturn=turn(letter2, column);

        if (itshisturn==1) {
            victoryStatus2=victoryStatus2 + 1;
            printBoard();
            return letter2;
        }
        printBoard();
    }
    return letter1;
}



void printBoard(void) {
    int i,j;

    for (i=0; i<6; i++) {
        for (j=0; j<7; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}



int turn(char letter, int column) {
    int i;

    //Error on next line. Missed the '=' sign. 
    for (i=5; i>=0; i--) {
        if (board[i][column]=='-') {
            board[i][column]=letter;
            i=0; 
        }
    }
    return victory(letter, column);
}


int victory(char letter, int column) 
{
    int checker=0;
    int i, j;
    for (i=0; i<6; i++) {
        checker=0;
        for (j=0; j<7; j++) {
            if (board[i][j]==letter) {
                checker++;
            }
            else {
                checker=0;
            }

            if (checker>=4) {
                return 1;
            }
        }


    }

    for (j=0; j<7; j++) {
        checker=0;
        for (i=0; i<6; i++) {
            if (board[i][j]==letter) {
                checker++;
            }
            else { 
                checker=0;
            }

            if (checker>=4) {
                return 1;
            }
        }
    }   
    return 0;
}



int main(void) {
    char letter1, letter2;

    printf("Player 1,");
    letter1=getCounter();
    printf("Player 2, ");
    letter2=getCounter(); 

    char winner = game(letter1, letter2);
    printf("\nPlayer %c wins the game!\n", winner);

    return 0;
}


