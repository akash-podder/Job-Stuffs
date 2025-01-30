#include<stdio.h>

int main()
{
    int num,octal,dec,power,rem,i,base;

    i=0;

    dec=0;

    scanf("%d",&num);

    octal=num;

    while(num)
    {
        dec=dec+pow(8,i)*(num%10);
        num=num/10;
        i++;
    }

    printf("The Octal Number is =%d\n",octal);

    printf("The decimal equivalent is =%d\n",dec);

    return 0;
}

