#include<stdio.h>

int main()
{
    int number,remainder;
    printf("Enter Any Number:");
    scanf("%d",&number);
    while(number>0)
        {
            remainder=number%10;
            printf("%d",remainder);
            number=number/10;


        }


    return 0;
}
