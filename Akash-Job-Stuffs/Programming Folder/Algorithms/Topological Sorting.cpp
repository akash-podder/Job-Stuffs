#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

/*  Source Geeks for Geeks video  */

map<int,vector<int> >Map;
stack<int>s;
int color[110];

void TopologicalSort(int current)
{
    color[current]=1;
    for(__typeof(Map[current].begin()) it=Map[current].begin();it!=Map[current].end();it++)   /*  DFS apply kore stack ae dukabo... arr "jokon kono node aer arr kono adjacent node" takbe nah... tokon sai node ta ke "stack" aer vitor dukabo... then stack ta thika pop out korle ei amra "Topological Sorting" aer order peye jabo */
    {
        if(color[*it]==0)    /*  Unvisited adjacent node gula check korbo sudhu tai  color[*it]==0 hote hobe  */
        {
            TopologicalSort(*it);
        }
    }

    s.push(current);
}

int main()
{
    int n,m;

    while(cin>>n>>m)
    {
        if(n==0 && m==0)
        {
            return 0;
        }

        int a,b;
        for(int i=1; i<=m; i++)
        {
            cin>>a>>b;
            Map[a].push_back(b);
        }

        memset(color,0,sizeof(color));

        for(int i=1;i<=n;i++)
        {
            if(color[i]==0)
            {
                TopologicalSort(i);
            }
        }


        cout<<s.top();
        s.pop();
        while(!s.empty())
        {
            cout<<" "<<s.top();
            s.pop();
        }

        cout<<endl;

        Map.clear();

    }

    return 0;
}
