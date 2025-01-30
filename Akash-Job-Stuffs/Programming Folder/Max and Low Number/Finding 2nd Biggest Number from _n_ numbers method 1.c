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

    max1=a[0];
    max2=-999999;

    for(i=0;i<n;i++)
    {
        if(max1<a[i])
        {
            max1=a[i];

            x=i;
        }

    }

    for(i=0; i<n && i!=x ;i++)  /* Eikane "x" variable ae 1st Biggest Number ase tai oi "x" baade baki sob index ae dekte hobe */
    {
        if(max2<a[i])
        {
            max2=a[i];
        }
    }

    printf("The 2nd Biggest Number is: %d",max2);


    return 0;
}
