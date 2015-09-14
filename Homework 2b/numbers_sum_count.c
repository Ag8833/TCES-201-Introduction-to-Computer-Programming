/*
Andrew Gates
TCES201
Autumn 2014
This program prompts the user to enter a number, then either adds it to the sum positive total or the sum negative total,
then displays the amount of each type of number entered as well as the sum for each type of number
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int neg=0, pos=0, negsum=0, possum=0, number=0;
    char response;
    do
    {
        printf("Enter a number: ");
        scanf("%d",&number);
        if (number>0)
        {
            possum+=number;
            pos++;
        }
        else
        {
            negsum+=number;
            neg++;
        }
        getchar();
        printf("Do you want to enter another number? \n");
        scanf("%c",&response);
    }while(response=='y');
    printf("You entered %d positive numbers and their sum is %d\n",pos,possum);
    printf("You entered %d negative numbers and their sum is %d",neg,negsum);
    return 0;
}
