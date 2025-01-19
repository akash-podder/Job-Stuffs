#include<stdio.h>

int main()
{
    char ch;
    printf("Enter any Character:");
    scanf("%c",&ch);
    if(ch>='A' && ch<='Z')
        printf("The Character %c is Uppercase",ch);
    else if(ch>='a' && ch<='z')
        printf("The Character %c is Lowercase ",ch);
    return 0;

}
