#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

const int Max=1e5;

vector<int>Prime_table;

void Sieve_akash(int n)
{
    int prime[n+1],i,j;  /* Jehetu N porjonto lagbe amader tai  prime[n+1] hobe  */

    for(i=0;i<n+1;i++)
    {
       prime[i]=1;
    }

    prime[0]=0;
    prime[1]=0;

    for(i=2;i<=sqrt(n);i++)
    {
        if(prime[i]==1)
        {
            //Prime_table.push_back(i);  /*  Eita dile sqrt(Max) aer porer sonka gula arr vector aer moddhe dukbe nah  ... tai wrong ans hobe... */
            for(j=2;(i*j)<=n;j++)
            {
                prime[i*j]=0;
            }

        }
    }


    for(int i=2; i<=n; i++)
    {
        if(prime[i]==1)
        {
            Prime_table.push_back(i);
        }
    }

}


vector<int>prime_numbers;
void sieve(int n)
{
    bool isPrime[n+1];
    for(int i=0; i<=n; i++)
    {
        isPrime[i] = true;
    }

    isPrime[0] = false;
    isPrime[1] = false;

    for(int i=2; i<=sqrt(n); i++)
    {
        if(isPrime[i]==true)
        {
            prime_numbers.push_back(i);
            //for(int j = i * i; j <= n ;j += i)
            for(int j=2; j*i<=n; j++)
            {
                isPrime[i*j] = false;  /* Mark all the multiples of i as composite(not prime) numbers */
            }

        }
    }
}



int main()
{
    int n;

    cin>>n;

    sieve(n);
    Sieve_akash(n);

    for(int i=0;i<Prime_table.size();i++)
    {
        cout<<Prime_table[i]<<" ";
    }


    return 0;
}
