#include<stdio.h>

int main()
{
    int num,swap,i,j;
    scanf("%d",&num);
    int a[num];
    for(i=0;i<num;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0;i<num;i++)
    {
        for(j=i+1;j<num;j++)  /*Eikane eita ke bole Bubble Sorting. That means pasa pasi 2 ti number aer moddhe swap kore sorting kora. Eikane j holo i aer paser index. Mane a[i] and a[j] holo pasapasi index*/        {
            if(a[i]>a[j])
            {
                swap=a[i];
                a[i]=a[j];
                a[j]=swap;

            }
        }
    }
    for(i=0;i<num;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}
