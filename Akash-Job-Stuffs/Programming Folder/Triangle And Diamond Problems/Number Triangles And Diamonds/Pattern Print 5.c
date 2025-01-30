#include<stdio.h>

int main()
{
    int row,column,n,value=1;
    printf("Enter Number of Triangle:");
    scanf("%d",&n);
    for(row=1;row<=n;row++)
    {
        for(column=1;column<=row;column++)
        {
            printf("%d ",value);
            value++;
        }
        printf("\n");
    }


    return 0;
}


