#include<stdio.h>
#include<math.h>

int main()
{
    int num,i,j,flag,prime[10000],x;

    printf("Enter N th prime Number:");

    scanf("%d",&x);

    prime[0]=2;

    j=1;

    for(num=3;num<=10000;num++)
    {
        flag=0;            /*Eikane Flag=0 ta 1st for loop ae vitor dite hobe. Declare aer time ae intialization korle kaaj korbe nah...Beacuse tokon arr flag aer maan 0 hochhe nah*/

        for(i=2;i<=sqrt(num);i++)
        {
            if(num%i==0)
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
            prime[j++]=num;
        }
    }

    printf("%d",prime[x-1]);   /* Because array te 0 element hocche no.1 prime.... temon koira 1 element hochhe no.2 prime  */

    return 0;
}
