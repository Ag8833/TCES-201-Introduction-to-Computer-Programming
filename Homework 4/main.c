#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define TOTAL_SEATS 10
#define FIRST_CLASS_MAX 5
#define ECONOMY_MAX 10
/*Maximum number of characters
that a name can have*/
#define NAME_MAX 80

typedef enum
{
    FIRST=1,
    ECONOMY=2
} seat_type;

void init_seats(int[]);
void print_seat_chart(int seats[]);
int flight_menu();
int check_full(int seats[], seat_type type);
void assign(seat_type, int seats[]);
int assign_seat(char *,int seats[], seat_type type);
void print_boarding_pass(char *,int seat, seat_type);

int main()
{
    int seats[TOTAL_SEATS];
    int type;

    init_seats(seats);
    do
    {
        type = flight_menu();

        switch(type)
        {
        case FIRST:
            assign(FIRST, seats);
            break;
        case ECONOMY:
            assign(ECONOMY, seats);
            break;
        case 3:
            print_seat_chart(seats);
            break;
        case 4:
            puts("Goodbye!");
        }
    }
    while(type <4);
    return 0;
}

/**
Assigns a seat for FIRST or ECONOMY.
*/
void assign(seat_type type, int seats[])
{
    int first_full = FALSE, economy_full = FALSE;
    int seat;
    char name[NAME_MAX];
    char response = 'y';

    //Check if the first class and economy
    //seats are full
    if (!check_full(seats, FIRST))
    {
        first_full = TRUE;
    }
    if (!check_full(seats, ECONOMY))
    {
        economy_full = TRUE;
    }

    //If both are full, display message and exit.
    if (first_full && economy_full)
    {
        puts("Next flight leaves in 3 hours.");
    }
    else
    {
        if (type == FIRST && first_full)
        {
            puts("Sorry, first class is full.");
            printf("Would you like to be placed in the economy section? (y/n) ");
            scanf(" %c", &response);
            type = ECONOMY;
        }
        if (type == ECONOMY && economy_full)
        {
            puts("Sorry, economy class is full.");
            printf("Would you like to be placed in the first class section? (y/n) ");
            scanf(" %c", &response);
            type = FIRST;
        }
        if (response != 'n' && response != 'N')
        {
            seat = assign_seat(name, seats, type);
            printf("Congratulations, printing your boarding pass....\n");
            print_boarding_pass(name, seat, type);
        }
        else
        {
            puts("Next flight leaves in 3 hours.");
        }
    }
}

/**
Initializes all the seats to 0 to show that they are available.
*/
void init_seats(int seats[])
{
    int i;
    for(i = 0; i < 10; i++)
    {
        seats[i]=0;
    }
}

/**
Prints the seat chart (0 if available, 1 if taken).
See executable for format.
*/
void print_seat_chart(int seats[])
{
    int i;
    printf("SEATING CHART <0-Available, 1-Taken>\n");
    printf("1  2  3  4  5  6  7  8  9  10\n");
    for(i = 0; i < 10; i++)
    {
        printf("%d  ", seats[i]);
    }
    printf("\n\n");
}

/**
Displays the flight menu and returns the choice made.
Validates to make sure that only 1-4 are entered.
*/
int flight_menu()
{
    int answer, type;
    do
    {
        printf("\t-------------------------\n");
        printf("\tWelcome to CES Airline!\n");
        printf("\t\tPlease type 1 for first class\n");
        printf("\t\tPlease type 2 for economy\n");
        printf("\t\tPlease type 3 for seat chart\n");
        printf("\t\tPlease type 4 to quit\n\n");
        printf("\t\tYour choice: ");
        scanf("%d",&answer);
        if (answer>0&&answer<5)
        {
            return answer;
        }
        else
        {
            printf("Invalid option. Please try again.\n");
        }
    }
    while(answer>4||answer<1);
}

/**
Find a seat in first or economy and assign to the user
and return the seat number.
*/
int assign_seat(char *name, int seats[], seat_type type)
{
    int seat;
    if (type==FIRST)
    {
        printf("Enter your name: ");
        scanf("%s",name);
        do
        {
            printf("Enter a seat number <1-5>: ");
            scanf("%d",&seat);
            if(seats[seat-1]==1)
            {
                printf("That seat is already taken. Please choose another.\n");
            }
        }
        while(seat<1||seat>5||seats[seat-1]==1);
        seats[seat-1]=1;
    }
    else
    {
        printf("Enter your name: ");
        scanf("%s",name);
        do
        {
            printf("Enter a seat number <6-10>: ");
            scanf("%d",&seat);
            if(seats[seat-1]==1)
            {
                printf("That seat is already taken. Please choose another.\n");
            }
        }
        while(seat<6||seat>10||seats[seat]==1);
        seats[seat-1]=1;
    }
    return name,seat;
}

/**
Checks if the seats are full for first or
economy class.
*/
int check_full(int seats[], seat_type type)
{
    int i, sum1=0, sum2=0;
    if (type==FIRST)
    {
        for(i = 0; i < 5; i++)
        {
            if (seats[i]==1)
            {
                sum1++;
            }
        }
        if (sum1==5)
        {
            return 0;
        }
    }
    else
    {
        for(i = 5; i < 10; i++)
        {
            if (seats[i]==1)
            {
                sum2++;
            }
        }
        if (sum2==5)
        {
            return 0;
        }
    }
    return 1;
}

/**
Print the boarding pass in the format
            CES Airlines Boarding Pass
Passenger Name          SEAT : 1
                        FIRST CLASS | ECONOMY

Example:
           CES Airlines Boarding Pass
Menaka Abraham          SEAT : 1
                        FIRST CLASS

*/
void print_boarding_pass(char *name, int seat, seat_type type)
{
    printf("\n\n");
    printf("\tCES Airline Boarding Pass\n");
    printf("%s",name);
    printf("\t\tSEAT : %d",seat);
    if(type==1)
    {
        printf("\n\t\t\tFIRST CLASS");
    }
    if(type==2)
    {
        printf("\n\t\t\tECONOMY");
    }
    printf("\n");
}
