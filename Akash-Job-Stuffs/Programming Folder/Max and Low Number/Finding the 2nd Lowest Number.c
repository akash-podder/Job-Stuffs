#include<stdio.h>

int main()
{
    int i,n,min1,min2,x;

    printf("Enter The Size of The Array:");

    scanf("%d",&n);

    int ara[n];

    printf("Enter the Numbers:");

    for(i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }

    min1=ara[0];
    min2=9999999;

    for(i=0;i<n;i++)
    {
        if(min1>ara[i])
        {
            min1=ara[i];
            x=i;
        }
    }

    for(i=0;i<n && i!=x;i++)
    {
        if(min2>ara[i])
        {
            min2=ara[i];
        }
    }


    printf("The Lowest Number is :%d\n",min1);

    printf("The  2nd Lowest Number is :%d\n",min2);

    return 0;
}
