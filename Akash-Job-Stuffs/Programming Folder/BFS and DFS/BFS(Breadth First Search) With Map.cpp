#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

map<int,vector<int>> Map;
queue<int>q;
int color[10001];
int parent[10001];

int bfs(int Start,int End)
{
    memset(color,-1,sizeof(color));

    int current;

    color[Start]=0;

    q.push(Start);

    while(!q.empty())
    {
        current=q.front();

        q.pop();

        for( __typeof(Map[current].begin()) it=Map[current].begin(); it!=Map[current].end(); it++)
        {
            if(color[*it]==-1)
            {
                parent[*it]=current;

                color[*it]=color[current]+1;

                if(*it==End)
                {
                    return color[*it];
                }

                q.push(*it);
            }

        }
    }


    return 0;

}


void printpath(int Start,int End)
{
    if(Start==End)
    {
        return;
        //cout<<current<<" ";
    }

    printpath(Start,parent[End]);

    cout<<parent[End]<<" ";

}


int main()
{

    int e,Start,End,distance;
    int a,b;

    cin>>e;

    for(int i=1; i<=e; i++)
    {
        cin>>a>>b;
        Map[a].push_back(b);
        Map[b].push_back(a);
    }

    cin>>Start>>End;

    distance=bfs(Start,End);

    cout<<distance<<endl;

    return 0;
}














/*#include<bits/stdc++.h>
using namespace std;

map<int,vector<int>> m;
queue<int>q;

int color[100009];  //color will count the distance as well check the node is visited or not

int distance(int start, int End)
{
    q.push(start);

    color[start]=1;

    while(!q.empty())
    {
        start=q.front();

        q.pop();

        for(__typeof(m[start].begin())it=m[start].begin(); it!=m[start].end(); it++)
        {
            if(color[*it]==0)
            {
                color[*it]=color[start]+1;

                if(*it==End)
                {
                    return color[*it];
                }

                q.push(*it);
            }
        }
    }

    return 0;
}

int main()
{
    int i,e,j,n;
    cin>>e;//x is the number of edges
    while(e--)
    {
        cin>>i>>j;
        m[i].push_back(j);
        m[j].push_back(i);
    }

    cin>>n;//number of test case;

    while(n--)
    {
        memset(color,0,sizeof(color));
        cin>>i>>j;
        printf("%d\n",distance(i,j)-1);
        q=queue<int>();

    }

    return 0;
}
*/
