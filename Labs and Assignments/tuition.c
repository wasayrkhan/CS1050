//Wasay Khan
//wrkgch
//Homework 1
//
#include <stdio.h>
#include <math.h>

int StudentNumber, CreditHrs, InNOutState, EngHrs;
float tuition, aid;

int main (void)
  {   
    printf("Enter a student ID number(8 digits beginning with '1'):");
    scanf("%d", &StudentNumber);

  while(StudentNumber >= 20000000||StudentNumber < 10000000)
  {
    printf("\nPlease enter a valid student ID number:");
    scanf("%d", &StudentNumber);
  }

    printf("\nHow many credit hours is the student enrolled in? ");
    scanf("%d", &CreditHrs);

    printf("\nIs this student an out-of-state resident? '1' if yes, any other value if no: ");
    scanf("%d", &InNOutState);

    printf("\nHow many credit hours are within the College of Engineering? ");
    scanf("%d", &EngHrs);

  while(EngHrs > CreditHrs)
  {
    printf("\nCredit Hours within the College of Engineering cannot exceed total credit hours.");
    printf("\nHow many credit hours are within the College of Engineering? ");
    scanf("%d", &EngHrs);
  }

  if(InNOutState != 1)
  {
    tuition = 282.00*CreditHrs;
  }
  else
  {
    tuition = 839.30*CreditHrs;
  }

  tuition = tuition + (90.00*EngHrs);

    printf("\nTotal grant or scholarship funds for this student(dollars): ");
    scanf("%f", &aid);

  while(aid>tuition)
  {
    printf("\nThe scholarship cannot exceed the tuition total.");
    printf("\nTotal grant or scholarship funds for this student(dollars): ");
    scanf("%f", &aid);
  }

    printf("\n ***** TUITION STATEMENT *****");
    printf("\n Student ID Number : %d", StudentNumber);
    printf("\n Credit Hours : %d", CreditHrs);

    printf("\n ******");
    printf("\n Base Tuition : %.2f", tuition);
    printf("\n Scholarships and grants : %.2f", aid);

    printf("\n *****");
    printf("\n TUITION GRAND TOTAL : %.2f\n", tuition - aid);

return 0;
  
  }

