#include<stdio.h>

int main()
{
    int i=0,number,remainder;
    printf("Enter Any Number:");
    scanf("%d",&number);
    while(remainder>0)
    {
        remainder=number%10;
        number=number/10;
        if(remainder==0)
        {
            printf("The Digits of the Number are:%d",i);
        }
        else
        {
            i++;
        }

    }



    return 0;
}
