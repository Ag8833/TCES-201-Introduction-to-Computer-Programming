/*
Andrew Gates
TCES201
Autumn 2014
This program counts the number of Fibonacci numbers the user enters and then displays the sum until that amount of numbers
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ftotal,fx=0,fy=1,fz=1,count,num=1;
    printf("Enter the number of Fibonacci numbers: ");
    scanf("%d",&ftotal);
    for (count=1;count<=ftotal;count++)
    {
        if (count>1)
        {
            fz=fx+fy;
            fx=fy;
            fy=fz;
        }
        printf("%d: %d\n",num,fz);
        num++;
    }
    return 0;
}
