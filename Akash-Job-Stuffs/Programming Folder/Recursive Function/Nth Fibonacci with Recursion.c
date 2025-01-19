#include<stdio.h>
//#include<bits/stdc++.h>

//sing namespace std;
int fibo(int n)
{
    int x;
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    return (fibo(n-1)+fibo(n-2));

}
int main()
{
    int n,x,i;

    printf("Enter how many Fibonacci Number You want to Print: ");

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        x=fibo(i);
        printf("%d ",x);
    }

    return 0;
}
