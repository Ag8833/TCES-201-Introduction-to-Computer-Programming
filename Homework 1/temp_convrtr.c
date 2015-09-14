/*  Andrew Gates
    TCES201
    Autumn 2014
    This program converts temperature from Fahrenheit into Celsius and then displays both values to the user.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float f, c;
    printf("Enter temperature in Fahrenheit:");
    scanf("%f",&f);
    c=5*(f-32)/9;
    printf("Temperature %.1f F",f);
    printf(" is equivalent to %.1f C",c);
    return 0;
}
