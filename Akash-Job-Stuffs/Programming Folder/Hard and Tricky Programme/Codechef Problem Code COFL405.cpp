#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;


int main()
{
    int i,j,n,test,k,uncle_john;
    long long int a[100000];

    scanf("%d",&test);

    for(i=1;i<=test;i++)
    {
     scanf("%d",&n);

     for(j=0;j<n;j++)
     {
         scanf("%lld",&a[j]);
     }

     scanf("%d",&k);

     uncle_john=a[k-1];  /*Jehetu amra counting start kori 1 tika and array te 0 theke start hui.Tai (j-1) holo sesh pod......(k-1) na dile jokon K and J soman hobe tokon program run korbe nah*/

     sort(a,a+n);

     for(j=0;j<n;j++)
     {
         if(uncle_john==a[j])
         {
             printf("%d\n",j+1);
         }
     }

    }

    return 0;
}
