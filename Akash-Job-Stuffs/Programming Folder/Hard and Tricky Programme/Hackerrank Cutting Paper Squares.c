#include<stdio.h>

int main()
{
    long long int m,n;
    long long int a,count,i,ans;

    scanf("%lld %lld",&n,&m);

    ans=(n*m-1);  /*She can only cut one piece of paper at a time, meaning she cannot fold the paper or layer already-cut pieces on top of one another.
                    Each cut is a straight line from one side of the paper to the other side of the paper. For example, the diagram below depicts the three possible ways to cut a (3*2) piece of paper: */


    printf("%lld",ans);

    return 0;
}

