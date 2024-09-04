/*Q1. Write a menu driven program for Date in a C. Declare a structure Date having data members
day, month, year. Implement the following functions.
void initDate(struct Date* ptrDate);
void printDateOnConsole(struct Date* ptrDate);
void acceptDateFromConsole(struct Date* ptrDate);*/

#include <stdio.h>

struct Date
{
    int day, month, year;
};

void initDate(struct Date *ptrDate)
{
    ptrDate->day = 0;
    ptrDate->month = 0;
    ptrDate->year = 0;
}

void printDateOnConsole(struct Date *ptrDate)
{
    printf("%d/%d/%d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}

void acceptDateFromConsole(struct Date *ptrDate)
{
    printf("Enter the Date :\n");
    scanf("%d", &ptrDate->day);
    scanf("%d", &ptrDate->month);
    scanf("%d", &ptrDate->year);
}

void main()
{
    int choice=4;
    struct Date d1;
    initDate(&d1);
   
    while (choice)
    {
        printf("Enter your choice : \n\n1.Accept date\n2.Print date\n3.Exit\n\n");
        scanf("%d", &choice);
        if (choice == 3)
        {
            break;
        }
        switch(choice)
        {
            case 1:
                acceptDateFromConsole(&d1);
                break;

            case 2:
                printDateOnConsole(&d1);
                break;

            default:
                printf("Invalid choice.\n");
        
        }
    }
}
