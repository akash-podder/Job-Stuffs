#include<stdio.h>

int main()
{
    int i,j,n;
    printf("Enter Number of Triangle:");
    scanf("%d",&n);
    for(i=n;i>=1;i--)
    {
        for(j=i;j>=1;j--)
        {
            printf("%d ",i);
        }
        printf("\n");
    }


    return 0;
}
