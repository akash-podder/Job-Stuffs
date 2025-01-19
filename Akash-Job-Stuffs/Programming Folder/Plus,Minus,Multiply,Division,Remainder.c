#include<stdio.h>

int main()
{
    int a,b,c,d,e,g;
    double f;
    printf("Enter First Number=");
    scanf("%d",&a);
    printf("Enter Second Number=");
    scanf("%d",&b);
    c=a+b;
    d=a-b;
    e=a*b;
    f=a/b;
    g=a%b;
    printf("Summation of %d and %d is=%d\n",a,b,c);
    printf("Deduction of %d and %d is=%d\n",a,b,d);
    printf("Multiplication of %d and %d is=%d\n",a,b,e);
    printf("Division of %d and %d is=%d\n",a,b,f);
    printf("Remainder of %d and %d is=%d\n",a,b,g);
    return 0;
}
