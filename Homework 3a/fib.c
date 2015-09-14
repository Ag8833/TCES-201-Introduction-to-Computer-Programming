/*
Andrew Gates
TCES201
Autumn 2014
This program counts the number of Fibonacci numbers the user enters and then displays the sum until that amount of numbers
*/
#include <stdio.h>
#include <stdlib.h>
int Fibonacci(int);
int main()
{
    int ftotal,fx=0,fy=1,fz=1,count,num=1,n=0;
    printf("Enter the number of Fibonacci numbers: ");
    scanf("%d",&n);
    Fibonacci(n);
    return 0;
}
int Fibonacci(int n)
{
    int fz=1,fx=0,fy=1,count,num=1;
    for (count=1;count<=n;count++)
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
}
