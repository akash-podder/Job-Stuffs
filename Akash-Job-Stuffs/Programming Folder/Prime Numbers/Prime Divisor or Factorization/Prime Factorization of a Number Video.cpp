#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

//const int Max= 1e7;
#define Max 1e7

vector<long long int>prime;
vector<long long int>v;

void sieve()
{
    for(long long int i=0; i<=Max; i++)
    {
        v.push_back(1);
    }

    v[0]=0;
    v[1]=0;

    for(long long int i=2; i<=sqrt(Max); i++)
    {
        if(v[i]==1)
        {
            for(long long int j=2; (j*i)<=Max; j++)
            {
                v[i*j]=0;
            }
        }
    }

    for(long long int i=2; i<=Max; i++)
    {
        if(v[i]==1)
        {
            prime.push_back(i);
        }
    }


}



int main()
{
    sieve();

    map<int,int>Map;
    map<int,int>::iterator it;

    long long int n,coun;

    cin>>n;

    //for(long long int i=2;i<=sqrt(n);i++) eita korbo tokon jokon sieve diya amra prime number store kori nai... but ette time lagge besi... karon i aer maan matro 1 kore bartase... tai sieve diya nicher method appply korbo  */


    for(long long int i=0; prime[i]<=sqrt(n); i++)   /*  Kono sonka ke vaag korte korte jai ovoshisto takhe sai ovosisto hui "1" hobe or kono "prime number"... sai ta prime kina ta jante huile amra oi sonka aer sqrt() porjonto gele ei bujte parbo... jodi sqrt() aer modhhe kono sonka diya oita vaag nah jai... taile oi vaag korte korte jai ovosisto sonka takbe saita prime hobe... tai prime[i]<=N nah diya prime[i]<=sqrt(N)  dile ei buje jabo  */
    {
        if(n%prime[i]==0)      /*  Video te i=2 theke sqrt(n) chalaise... arr amra sieve ae rakhe only prime number gula diya vaag disi... eita arro besi efficient  */
        {
            coun=0;     /*  By dividing "n"... when n is reduced to a prime number... the only way is to do a loop from 2 to sqrt(n)... tai oi sonka aer sqrt(n) porjonto chala lei hobe  */

            while(n%prime[i]==0)  /*  Olpo kota ae... sqrt(n) porjonto loop chalaiya amra n ke vaag korte takbo... then loop sesh ae "n" aer value 2 ta hote pare...  1 or kono prime number... ( prime hobe karon oi sonka ta agge ei vaag jeto sqrt(n) porjonto chalale)  */
            {
                coun++;
                n=n/prime[i];
            }

            Map[prime[i]]=coun;
        }
    }


    if(n!=1)     /*  Jodi sonka ta ke vaag korte korte saita 1 nah hui... taile obbosshoi sai ovosisto sonka ekta prime number  */
    {
        Map[n]++;
    }





    int c=0;
    for(it=Map.begin(); it!=Map.end(); it++)
    {
        c++;
        if(c==1)
        {
            cout<< it->first <<" ("<< it->second <<") ";
        }

        else
        {
            cout<<" * "<<it->first<<" ("<<it->second<<")";
        }

    }




    return 0;
}
