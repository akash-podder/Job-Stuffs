#include<stdio.h>

int FIBO(int n)
{
    if(n==0)
    {
        return 0;
    }

    else if(n==1)
    {
        return 1;
    }

    return (FIBO(n-1)+FIBO(n-2));

}

int main()
{
    int n,ans;

    scanf("%d",&n);

    ans=FIBO(n+1);    /*   Jehetu n th finonacci chawa hochhe tai (n+1) call korte hobe nahile ans asbe nah  */

    printf("%d\n",ans);

    return 0;
}
