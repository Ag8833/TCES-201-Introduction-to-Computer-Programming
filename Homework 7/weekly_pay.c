/**
Andrew Gates
Professor Menaka Abraham
TCES 201
This program goes through 10 different employee information lists prompting the user for their id, name, hours and rate. If the hours are
over 40 it will calculate the gross pay calculating 40 hours of normal rate and then the leftover hours at 1.5x normal rate. If the hours
are less than 40 then it will calculate the gross pay based on those hours and the rate they worked at. Once the code captures the
information for all 10 employees it will go through each employee and print their id, name, hours, rate and gross pay.
*/
#include <stdio.h>
#define ID_LEN 7
#define NAME_LEN 21
#define EMP_LEN 10

typedef struct employee
{
   char id[ID_LEN];
   char name[NAME_LEN];
   int hours;
   float rate;
   float gross_pay;
} EMPLOYEE;


void input_employee(EMPLOYEE *);
void print_employee(const EMPLOYEE *);

int main()
{
    EMPLOYEE emps[EMP_LEN];
    int i;
    for (i=0; i<EMP_LEN; i++)
    {
        printf("\nEmployee %d: \n\n\n", (i+1));
        input_employee(&emps[i]);
    }
    puts("\n\nEmployees information:");
    for (i=0; i<EMP_LEN; i++)
    {
        printf("\nEmployee %d: \n\n\n", (i+1));
        print_employee(&emps[i]);
    }
    return 0;
}

/**
Gets input and initializes the structure members.
Calculates the gross pay and initializes it.
*/
void input_employee(EMPLOYEE *e)
{
    float overtime=0, temphours=0;
    printf("Enter id: ");
    scanf("%s", e->id);
    printf("Enter name: ");
    scanf("%s", e->name);
    printf("Enter hours: ");
    scanf("%d", &e->hours);
    printf("Enter rate: ");
    scanf("%f", &e->rate);
    /// If hours are over 40 then this section will calculate the gross pay based on rate and overtime rate.
    if(e->hours>40)
    {
        overtime=e->hours%40;
        temphours=e->hours-overtime;
        overtime=overtime*(e->rate*1.5);
        e->gross_pay=(temphours*e->rate)+overtime;
    }
    /// If hours are less than 40 then this section will calculate the gross pay based on rate.
    else
    {
        e->gross_pay=e->hours*e->rate;
    }
}

/**
Prints the employee information.
*/
void print_employee(const EMPLOYEE *e)
{
    printf("ID: %s\n",e->id);
    printf("Name: %s\n",e->name);
    printf("Hours: %d\n",e->hours);
    printf("Rate: %.2f\n",e->rate);
    printf("Gross Pay: %.2f\n",e->gross_pay);
}
