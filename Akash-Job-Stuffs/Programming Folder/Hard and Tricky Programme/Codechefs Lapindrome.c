#include<stdio.h>
#include<string.h>

int main()
{
    int a,i,j,k,l,length,t,count,n;
    char ara[1000];

    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",ara);

        count=0;

        length=strlen(ara);


        if(length%2!=0)
        {
            n=(length-1)/2;

            for(k=0;k<n;k++)
            {
                for(l=n+1;l<length;l++)
                {
                    if(ara[k]==ara[l])
                    {
                      count++;
                      ara[l]=1;  /*Eikane ara[l] ke jekono ekta value te assaign na korle pore 2nd time loop gurar time oi letter taa abr pabe. jemon "abbaab" aer ketre hinta koro*/
                      break;
                    }
                }
            }


            if(count==n)
            {
                printf("YES\n");
            }
            if(count!=n)
            {
                printf("NO\n");
            }
        }



        else if(length%2==0)
        {
            n=length/2;
            for(i=0;i<n;i++)
            {

                for(j=n;j<length;j++)
                {
                    if(ara[i]==ara[j])
                    {
                      count++;
                      ara[j]=2;
                      break;
                    }
                }
            }

            if(count==n)
            {
                printf("YES\n");
            }
            if(count!=n)
            {
                printf("NO\n");
            }
        }
    }

    return 0;
}
