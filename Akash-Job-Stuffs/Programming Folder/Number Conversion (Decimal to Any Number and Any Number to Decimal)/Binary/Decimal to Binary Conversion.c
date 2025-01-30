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
            ara[i++]=num%2;          /* Eikane i=1 teke start huise tai ara[0] index pura faka. */   /*  Eikane ara[i++]= num%2 agge likte hobe then num=num/2 pore likte hobe....because nahile num aer value change huia jai     */
            num=num/2;
        }

        printf("Binary :");

        for(j=i-1;j>0;j--)
        {
            printf("%d",ara[j]);
        }
    }

    else if(num<=0)
    {
        printf("Binary :0");
    }

    return 0;
}
