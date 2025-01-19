#include<stdio.h>
#include<math.h>
#include<conio.h>


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    long long int a,b,c,x=999999999999999999;
    scanf("%lld",&a);
    for(b=1;b<=sqrt(a);b++)
    {
        if(a%b==0 && x>(abs(b-a/b)))
        {
            x=abs(b-a/b);
        }
    }
    printf("%lld\n",x);

    }
    return 0;

}
