#include<stdio.h>

int main()
{
    int i,n;

    for(i=1;i<=20;i=i+1)
    {
        for(n=1;n<=10;n=n+1)
        {
            printf("%d*%d=%d\n",n,i,n*i);
        }
    }

    return 0;

}
