#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAMEMAX 60

int load_array(char*);
int find_string(char*,char*,int);

int main()
{
    FILE *searchlist = fopen("search_list.txt","r");
    char namelist[NAMEMAX][NAMEMAX],name[NAMEMAX];
    int file_len = load_array(namelist);
    char answer='y';
    do
    {
        printf("Enter a name to search: ");
        scanf("%s",name);
        printf("\n");
        int index =find_string(namelist,name,file_len);
        printf("Your name was found at position %d\n\n",index);
        printf("Do you want to search for another name? (y/n) ");
        scanf(" %c",&answer);
        printf("\n\n");
    }
    while(answer=='y');
    return 0;
}

load_array(char*namelist)
{
    int file_len=0, i=0;
    FILE *searchlist = fopen("search_list.txt","r");
    while (file_len<19)
    {
        fgets(namelist,NAMEMAX,searchlist);
        i++;
        file_len++;
    }
    puts(namelist);
    return file_len;
}

find_string(char*namelist,char*name,int file_len)
{
    int n=strlen(name);
    int found=0;
    while (found<file_len)
    {
        int value=strncmp(namelist,name,n);
        if (value==0)
        {
            printf("Found name in file\n\n");
            break;
        }
        found++;
    }
    if (found<file_len)
    {
        return found;
    }
    else
    {
        printf("Didn't find name in file\n\n");
        return -1;
    }

}

