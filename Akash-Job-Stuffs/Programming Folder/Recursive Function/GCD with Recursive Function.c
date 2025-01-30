#include<stdio.h>
#include<math.h>

int gcd_function(int a, int b)
{
	if(a%b==0)
    {
        return b;
    }
	return gcd_function(b,a%b);
}


int main()
{
    int a,b,gcd;

    printf("Enter Two Numbers: ");

    scanf("%d%d",&a,&b);

    gcd=gcd_function(a,b);

    printf("GCD: %d\n",gcd);

}
