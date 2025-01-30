#include<stdio.h>

int main()
{
    int i,m;
    int n=5;

    m=0;
    for(i=1;i<=10;i=i+1)
    {
        m=m+n;
        printf("%d*%d=%d\n",n,i,m);
    }

    return 0;


}
