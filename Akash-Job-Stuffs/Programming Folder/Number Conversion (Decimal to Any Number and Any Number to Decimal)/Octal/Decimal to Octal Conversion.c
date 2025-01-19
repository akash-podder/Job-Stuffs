#include<stdio.h>

int main()
{
    int num,ara[1000];

    int i=1,j;

    printf("Decimal :");

    scanf("%d",&num);

    if(num>0)
    {
        while(num!=0)
        {
            ara[i++]=num%8;          /* Eikane i=1 teke start huise tai ara[0] index pura faka. */
            num=num/8;
        }

        printf("Octal :");

        for(j=i-1;j>0;j--)
        {
            printf("%d",ara[j]);
        }
    }

    else if(num<=0)
    {
        printf("Octal :0");
    }

    return 0;
}

