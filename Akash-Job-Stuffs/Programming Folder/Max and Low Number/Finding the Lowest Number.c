#include<stdio.h>

int main()
{
    int i,n,min;

    printf("Enter The Size of The Array:");

    scanf("%d",&n);

    int ara[n];

    printf("Enter the Numbers:");

    for(i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }

    min=ara[0];

    for(i=0;i<n;i++)
    {
        if(min>ara[i])
        {
            min=ara[i];
        }
    }

    printf("The Lowest Number is : %d\n",min);

    return 0;
}
