#include<stdio.h>
#include<conio.h>

int main()
{
    int i,j,k,n,m;

    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        k=1;
        for(j=1;j<=(i+n);j++)
        {
            if(j>=((n+1)-i) && j<=((n+1)+i) && k)
            {
                printf("*");
                k=0;
            }
            else
            {
                printf(" ");
                k=1;
            }

            printf("\n");

        }

    }

    return 0;
}
