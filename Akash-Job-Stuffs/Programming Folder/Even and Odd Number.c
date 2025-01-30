#include<stdio.h>
#include<conio.h>

int main()
{
    int number,remainder;
    printf("Enter First Number:");
    scanf("%d",&number);
    remainder=number%2;

    if(remainder==0)
    {
        printf("The Number is Even\n");
    }

    else if(remainder!=0)
    {
        printf("The Number is Odd\n");

    }

    return 0;

}
