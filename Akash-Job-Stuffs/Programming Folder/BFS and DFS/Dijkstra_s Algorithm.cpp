#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int cost[10001][10001];
int color[10001]; //Visit
int dis[10001];
int parent[10001];
map<int,int>nodes;
map<int,vector<int> > Map;


void Dijkstra()
{
    int current;

    for(__typeof(nodes.begin()) it=nodes.begin(); it!=nodes.end(); it++)
    {
        color[it->first]=-1;
        dis[it->first]=0;

        if(it==nodes.begin())
        {
            current=it->first;
        }
    }

    //cout<<current<<endl;

    priority_queue<int>q;

    //queue<int>q;

    q.push(current);
    parent[current]=current;  /*  Karon source aer parent sai nije ei  */

    while(!q.empty())
    {
        current=q.top();
        q.pop();

        for( __typeof(Map[current].begin()) it=Map[current].begin(); it!=Map[current].end(); it++)
        {
            if(color[*it]==-1)
            {
                color[*it]=1;

                dis[*it]=dis[current]+cost[current][*it];

                parent[*it]=current;

                //cout<<*it<<":"<<dis[*it]<<endl;

                q.push(*it);
            }

            else
            {
                if(dis[current]+cost[current][*it] < dis[*it] )
                {
                    dis[*it]=dis[current]+cost[current][*it];

                    //cout<<dis[*it]<<endl;

                    parent[*it]=current;
                }
            }

        }
    }

}


void PrintPath(int n)
{
    if(parent[n]==n)
    {
        cout<<n<<" ";
        return;
    }

    PrintPath(parent[n]);
    cout<<n<<" ";
}



int main()
{
    int n,e,a,b,c;

    cin>>e;

    for(int i=0; i<e; i++)
    {
        cin>>a>>b>>c;
        Map[a].push_back(b);  /*  Karon amra sudhu a thika b te jete pari... mane direction "a to b"   */
        //Map[b].push_back(a);
        cost[a][b]=c;
        nodes[a]=0;
        nodes[b]=0;
    }

    cin>>n;  /*  Here "n" is for Printing the specific nodes Path... mane jai source node theke jai node aer path print korte chai... */

    Dijkstra();

    cout<<"Distance: "<<dis[n]<<endl;

    cout<<"Path: ";
    PrintPath(n);

    return 0;
}

/*
4
1 2 2
1 3 1
2 3 6
3 4 3
4

ans: 4
path: 1 3 4



6
1 3 3
3 2 2
3 5 1
2 5 3
5 6 6
2 4 1
6

ans:10
path:  1 3 5 6

*/
