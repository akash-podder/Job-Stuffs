#include<stdio.h>
#include<stdlib.h>


void For(int i, int n, int a[])
{
    if(n==i)
    {
        return;
    }

    scanf("%d",&a[i]);

    printf("%d\n",a[i]);    /* Agge Print hobe then i aer man 1 kore barabe..... printf pore dile ulta printf hobe */

    For(i+1,n,a);

}

int main()
{
    int n,i=0,a[100];

    scanf("%d",&n);

    For(i,n,a);


    return 0;
}
