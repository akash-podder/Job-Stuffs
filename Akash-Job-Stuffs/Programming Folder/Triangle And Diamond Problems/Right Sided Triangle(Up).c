#include<stdio.h>

int main()
{
    int i,j,n;
    printf("Enter Number of Triangle:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i>(n-j))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }

        }
        printf("\n");
    }


    return 0;
}
