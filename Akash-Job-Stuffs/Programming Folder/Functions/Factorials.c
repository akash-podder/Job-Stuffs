#include<stdio.h>

long long int fact(int x);

int main()
{
    int n;
    long long factorial;

    printf("Enter a Number:");

    scanf("%d",&n);

    factorial=fact(n);

    printf("The Factorial of %d is :%lld",n,factorial);

    return 0;
}

long long int fact(int x)
{
    int i;
    long long int fact=1;  /*Jehetu eikane fact=1 agge dhorsi tai abr long long fact=1 likhte huise. Ta na hol.e likte hoto nah.*/

    for(i=1;i<=x;i++)
    {
        fact=fact*i;
    }

    return fact;

}
