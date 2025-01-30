#include<stdio.h>

int main()
{
    int number,i=0;
    printf("Enter Any Number:");
    scanf("%d",&number);
    while(number>0)
    {
        number=number/10;
        i++;
    }
    printf("The Digits of Number are:%d",i);

    return 0;
}
