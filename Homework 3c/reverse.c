/*
Andrew Gates
TCES201
Autumn 2014
This program prompts for a number and then reverses that number and displays it to the user
*/
#include <stdio.h>
#include <stdlib.h>

int Reverse(int);

int main()
{
    int x=0,reverse=0,n=0;
    printf("Enter a number: \n");
    scanf("%d", &n);
    Reverse(n);
    return 0;
}

int Reverse(int n)
{
    int x=0,reverse=0;
    do
    {
        x=n%10;
        reverse=reverse*10+x;
        n=n/10;
    }while (n!=0);
    printf("The reverse number is: \n%d",reverse);
}
