#include<stdio.h>

int main()
{
    int i,n,max;
    printf("Enter The size of the array:");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("Enter Number %d:\n",i+1);   //because here i=0 and we want to print number 1. So we have to write i+1.


        scanf("%d",&a[i]);
    }

    max=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }

    }

    printf("The Biggest Number is : %d",max);


    return 0;
}

