#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

int main()
{
    int n,i,j;
    string a[]={"zero","one","two","three","four","five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen" ,"fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    string b[]={"twenty", "thirty", "forty", "fifty", "sixty","seventy", "eighty", "ninety"};

    //scanf("%d",&n);
    cin>>n;

    if(n<20)
    {
        //printf("%d",a[n]);
        cout<<a[n];
    }

    else if(n>=20)
    {
        if(n%10==0)
        {
            j=n/10;
            //printf("%d",b[j-2]);
            cout<<b[j-2];
        }

        else
        {
            i=n%10;
            j=n/10;
            //printf("%d-%d",a[i],b[j-2]);
            cout<<b[j-2]<<"-"<<a[i]<<endl;

        }

    }



    return 0;
}
