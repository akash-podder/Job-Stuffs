#include<stdio.h>

void sort(int a[],int n)
{
    int i,j,swap;

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                swap=a[i];
                a[i]=a[j];
                a[j]=swap;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}

int main()
{
    int n,x[1000],i;

    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
        }
        sort(x,n);
    }

    return 0;
}
