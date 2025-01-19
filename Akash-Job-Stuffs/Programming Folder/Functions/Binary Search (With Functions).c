#include<stdio.h>

int Bsearch(int A[],int T,int n)
{
    int mid,low=1,high=n;

    while(low<=high)
    {
        int mid=(low+high)/2;

        if(A[mid]==T)
        {
            return mid;
        }
        else if(A[mid]<T)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }

    }

    return -1;
}



int main()
{
    int i,n,x;
    int a[1000];

    printf("Enter How Many Numbers You want in Array:");

    while(scanf("%d",&n))
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }

        printf("Enter The Number You want to Find:");

        scanf("%d",&x);

        n=Bsearch(a,x,n);

        if(n==-1)
        {
            printf("Not Found\n");
        }
        else
        {
            printf("Yes,It is Found at %d\n",n);
        }
    }

    return 0;
}
