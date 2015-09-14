/*
Andrew Gates
TCES201
Autumn 2014
This program prompts the user to enter a binary number up to 5 numbers and then using mod and division by 10 it calculates each
number in the binary number's decimal value, then sums them to get the total decimal value
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
int b0=0, b1=0, b2=0, b3=0, b4=0, total=0, binary=0, decimal=0;
printf("Enter the binary number: ");
scanf("%d", &total);
binary=total;
b0=total%2;
total/=10;
b1=total%2;
total/=10;
b2=total%2;
total/=10;
b3=total%2;
total/=10;
b4=total%2;
total/=10;
decimal=b0+b1*2+b2*4+b3*8+b4*16;
printf("Decimal equivalent of %d is %d",binary,decimal);
return 0;
}
