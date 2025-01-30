#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int>v;
    int n;

    cin>>n;
    v.push_back(1);

    int a=0,b=0,c=0;
    int two=2,three=3,five=5;

    while(v.size()!=n)   /*  Joto khon nah porjonto  "vector" aer size "n" aer soman hui totokhon loop cholbe  */
    {
        if(two<=three && two<=five)
        {
            if(v[v.size()-1]!=two)   /*  Ei shorto ta dewa karon maje maje eki sonka 2 bar dukhe jai... tai... */
            {
                v.push_back(two);
            }
            //v.push_back(two);
            a++;
            two=v[a]*2;
        }
        else if(three<=two && three<=five)
        {
            if(v[v.size()-1]!=three)
            {
                v.push_back(three);
            }
            //v.push_back(three);
            b++;
            three=v[b]*3;
        }
        else if(five<=two && five<=three)
        {
            if(v[v.size()-1]!=five)
            {
                v.push_back(five);
            }
            //v.push_back(five);
            c++;
            five=v[c]*5;
        }
    }

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }



    return 0;
}
