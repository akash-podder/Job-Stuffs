#include<stdio.h>

int main()
{
    int i,n,max1,max2,x;

    printf("Enter the Size of the array:");
    scanf("%d",&n);
    int a[n];

    printf("Enter the numbers :");

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    max1=-999999;
    max2=-999999;

    for(i=0;i<n;i++)
    {
        if(a[i]>max1)
        {
            max2=max1;

            max1=a[i];
        }

        else if(a[i]>max2)
        {
            max2=a[i];
        }

    }

    printf("The 2nd Biggest Number is: %d",max2);


    return 0;
}

