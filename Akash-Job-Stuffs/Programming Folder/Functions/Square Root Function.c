#include<stdio.h>
#include<math.h>

double square_root(double x);

int main()
{
    double n,a;

    printf("Enter a Number which you want to square Root:");

    scanf("%lf",&n);

    a=square_root(n);

    printf("The Square Root of the Number %0.3lf is: %0.3lf",n,a);

    return 0;
}

double square_root(double x)  /*Eikane Double x holo Parameter*/
{
    double i;

    i=sqrt(x);

    return i;
}
