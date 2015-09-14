#include <stdio.h>
#include <stdlib.h>
#define NUMBERCAP 256
#define RANDMAX 100

int random_number_file_generator(void);
int hex_and_binary_file_generator(int);
int convert_decimal_to_hex(int);
int convert_decimal_to_binary(int);

int main()
{
    srand (time(NULL));
    fclose(fopen("randomNumbers.txt","w"));
    int random_number = random_number_file_generator();
    hex_and_binary_file_generator(random_number);
    return 0;
}

int random_number_file_generator()
{
    int i;
    int random_number = rand()%RANDMAX;
    printf("random number in function is %d\n",random_number);
    FILE *rn = fopen("randomNumbers.txt", "w");
    if (rn!=NULL)
    {
        for(i=0; i<random_number; i++)
        {
            int number = rand()%NUMBERCAP;
            fprintf(rn, "%d\n", number);
        }
        fclose(rn);
    }
    else
    {
        printf("Unable to open file");
        return 1;
    }
    return random_number;
}

hex_and_binary_file_generator(random_number)
{
    int i,decimal[100];
    FILE *rn = fopen("randomNumbers.txt", "r");
    FILE *hab = fopen("hexAndBinary.txt", "w");
    for(i=0;i<random_number;i++)
    {
        fgets(decimal,5,rn);
        atoi(decimal);
        printf("%d converted number is %s", i+1, decimal);
        //convert_decimal_to_hex(decimal)
        int binary = convert_decimal_to_binary(decimal);
        fprintf(hab,"0x %d (%s",binary,decimal);
    }
    fclose(rn);
    fclose(hab);
}

/*convert_decimal_to_hex()
{
    print
}*/

convert_decimal_to_binary(dectobin)
{
    int binary[100]={0}, i=1, j=0;
    printf("dectobin number is %s",dectobin);
    while(dectobin!=0&&i<9)
    {
        binary[i++]=dectobin%2;
        dectobin=dectobin/2;
    }
    printf("binary number is ");
    for(j=i-1;j>0;j--)
    {
        printf("%d",binary[j]);
    }
    printf("\n");
    return binary;
}
