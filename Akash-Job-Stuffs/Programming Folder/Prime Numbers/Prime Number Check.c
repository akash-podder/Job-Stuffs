#include<stdio.h>
#include<math.h>

int main()
{
    long long int num,i,prime=0;

    printf("Enter A Number which You want to check Prime or Not:");

    scanf("%lld",&num);

    if(num>2)
    {
        for(i=2;i<=sqrt(num);i++)
        {
            if(num%i==0)
            {
                prime=1;  /*Jodi eikane printf ditam tahole eirokom asto- 9 is not prime,9 is prime,9 is not prime.... eirokom. Eijonno for loop aer vahir ae dite hobe printf*/
            }

        }

        if(prime==0)
        {
            printf("The Number: %lld is Prime.\n",num);
        }
        else if(prime==1)
        {
            printf("The Number: %lld is Not Prime.\n",num);
        }

    }

    else if(num==2)
    {
        printf("The Number: 2 is Prime.\n",num);
    }

    else if(num<2)
    {
        printf("The Number: %lld is Not Prime.\n",num);
    }

    return 0;
}
