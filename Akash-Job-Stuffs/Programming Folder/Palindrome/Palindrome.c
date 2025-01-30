#include<stdio.h>
#include<string.h>

int main()
{
    char a[1000],b[1000],length,i,j;

    gets(a);

    length=strlen(a);

    for(i=length-1,j=0; i>=0; i--,j++)
    {
        b[j]=a[i];
    }

    b[j]='\0';

    if(strcmp(a,b)==0)
    {
        printf("Palindrome");
    }

    else
    {
        printf("Not Palindrome");
    }


    return 0;
}
