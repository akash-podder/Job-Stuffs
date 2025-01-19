#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

#define Max 1e7

int main()
{
    map<int,int>Map;
    map<int,int>::iterator it;

    int test,num,n;

    int coun;

    cin>>test;

    for(int j=1; j<=test; j++)
    {
        cin>>num;

        n=num;

        for(int i=2; i<=sqrt(n); i++)
        {

            if(n%i==0)
            {
                coun=0;

                while(n%i==0)
                {
                    coun++;
                    Map[i]=coun;

                    n=n/i;
                }

            }

        }


        if(n!=1)
        {
            Map[n]=1;
        }


        cout<<"Case "<<j<<": "<<num<<" = ";

        int k;

        for(it=Map.begin(),k=0; it!=Map.end(); it++,k++)
        {
            cout<< it->first <<" ("<< it->second <<") ";          /*   Print out ae bracket ae ja asbe saita huilo oitar power... mane bangla ae ghaat */

            if(k<Map.size()-1)
            {
                cout<<"* ";
            }
        }

        cout<<endl;

        Map.clear();

    }




    return 0;
}
