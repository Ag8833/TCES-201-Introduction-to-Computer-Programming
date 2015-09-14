/*
Andrew Gates
TCES201
Autumn 2014
This program lists all of the perfect numbers from 1 to 10000
*/
#include <stdio.h>
int perfect(int);
void list_perfect(int);

int main()
{
    int i;
    printf("Here are the perfect numbers between 1 and 10000\n");
    for (i=2; i<10000; i++)
    {
        if (perfect(i))
        {
            list_perfect(i);
        }
    }
    return 0;
}

/*
Returns whether a given number is perfect
*/
int perfect(int i)
{
    int n=1,sum=0;
    while(n<i)
    {
        if(i%n==0)
        {
            sum=sum+n;
        }
        if(sum==i)
        {
            printf("%d = ",i);
            return i;
        }
        n++;
    }
}

/*
Lists the perfect number's factors
Example: 6 = 1 + 2 + 3
*/
void list_perfect(int i)
{
    int n=0;
    while(n<i)
    {
        if(i%n==0)
        {
            printf("%d+ ",n);
        }
        n++;
    }
}
