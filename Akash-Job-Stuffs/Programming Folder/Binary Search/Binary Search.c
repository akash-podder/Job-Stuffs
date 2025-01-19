#include<stdio.h>

int main()
{
    int n,i,num;
    int mid_index, low_index, high_index;

    printf("Enter the size of the array:");

    scanf("%d",&n);

    int ara[n];

    low_index=0;
    high_index=n-1;

    printf("Enter the Numbers:");

    for(i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }

    printf("Enter the Number You want to search in array:");
    scanf("%d",&num);

    while(low_index<=high_index)
    {
        mid_index=(low_index+high_index)/2;

        if(num==ara[mid_index])
        {
            break;
        }

        else if(num<ara[mid_index])
        {
            high_index=mid_index-1;
        }

        else //if(num>ara[mid_index])
        {
            low_index=mid_index+1;
        }
    }

    if(low_index>high_index)
    {
        printf("%d is not in the array.\n",num);
    }

    else
    {
        printf("%d is found in the array.It is the %d th element of the array.\n",num,mid_index+1);
    }


    return 0;
}
