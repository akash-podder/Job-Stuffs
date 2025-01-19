#include<stdio.h>

int main()
{
    int num,bin,dec,power,i,rem;

    i=0;

    dec=0;

    scanf("%d",&num);

    bin=num;

    while(num!=0)        /*  Eikane while(num)  dile oo eki kaaj kore   */
    {
        rem=num%10;
        dec=dec+(pow(2,i)*rem);
        num=num/10;
        i++;
    }

    printf("The Binary Number is =%d\n",bin);

    printf("The Decimal equivalent is =%d\n",dec);

    return 0;
}
