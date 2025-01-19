#include<stdio.h>

double add(double x, double y);   /*Function Prototype.....eikane Prototype aer variable add function aer Parameter aer name aer naam ae na huile oo hobe */

int main()
{
    double a,b,c;
    printf("Enter Two Numbers:");

    scanf("%lf %lf",&a,&b);

    c=add(a,b);

    printf("The Summation of %0.3lf and %0.3lf is: %0.3lf",a,b,c);


    return 0;
}

double add(double x, double y)   /*Eikane double x, double y hochhe function Parameter*/
{
    double sum;
    sum=x+y;
    return sum;
}
