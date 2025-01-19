#include<stdio.h>
#include<math.h>

int main()
{
    int num,i,flag,prime;

    printf("How Many Prime Numbers You want to print:");

    scanf("%d",&prime);

    printf("2\n");

    for(num=3;num<=prime;num++)
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
            printf("%d\n",num);
        }

    }

    return 0;
}
