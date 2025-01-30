#include<stdio.h>

int main()
{
    int i,n;
    printf("Enter the Number for which You want Multiplication Table:");
    scanf("%d",&n);

    for(i=1;i<=10;i=i+1)
    {
        printf("%d*%d=%d\n",i,n,i*n);
    }

    return 0;

}
