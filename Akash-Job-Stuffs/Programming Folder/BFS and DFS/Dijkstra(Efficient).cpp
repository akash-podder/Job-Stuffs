#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

map<int,vector<int> >Map;
int color[110];
int dis[110];
int cost[110][110];


struct comp
{
    bool operator() (const int&a,const int&b)
    {
        return dis[a]>dis[b];  /* Jehetu distance of "a" update hole dis[a] auto update hochhe so "priority queue" aer moddhe oo "dis[a]" updated akare takbe */
    }
};


//UVA 1112 Mice and Maze
int Dijkstra(int start,int exit,int time)
{
    color[start]=1;
    dis[start]=0;

    priority_queue<int,vector<int>,comp>pq;
    pq.push(start);

    int current;

    while(!pq.empty())
    {
        current=pq.top();
        pq.pop();

        color[current]=1;

        for(__typeof(Map[current].begin())it=Map[current].begin(); it!=Map[current].end(); it++)
        {
            if(color[*it]==0)
            {
                if(dis[*it]==-1)
                {
                    dis[*it]=dis[current]+cost[current][*it];  /* Jehetu distance of "a" update hole dis[a] auto update hochhe so "priority queue" aer moddhe oo "dis[a]" updated akare takbe */
                    pq.push(*it);  /*  Khali jokon dis[*t]=-1 takbe mane "-1" hochhe infinity sudhu tokon ei push korbo */
                }

                if(dis[*it]> dis[current]+cost[current][*it])
                {
                    dis[*it]=dis[current]+cost[current][*it];
                    pq.push(*it);
                }
            }
        }
    }

    //return dis[exit];


    if(dis[exit]<=time && dis[exit]!=-1)   /*  dis[]=-1 huile oo pore saita time thika choto hui arr "1" return kore... but asole korar kotha nah... tai dis[exit]!=-1 */
    {
        return 1;
    }

    else
    {
        return 0;
    }



}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int test,n,e,time,m;

    cin>>test;

    for(int j=1;j<=test;j++)
    {
        cin>>n>>e>>time>>m;

        int a,b,c;
        int ans=0;

        for(int i=1; i<=m; i++)
        {
            cin>>a>>b>>c;
            Map[a].push_back(b);
            cost[a][b]=c;
        }

        for(int i=1; i<=n; i++)
        {
            memset(color,0,sizeof(color));
            memset(dis,-1,sizeof(dis));

            //cout<<i<<" "<<Dijkstra(i,e,time)<<endl;


            if(Dijkstra(i,e,time)==1)
            {
                ans++;
            }


        }

        cout<<ans<<endl;

        if(j<test)
        {
            cout<<endl;
        }

        Map.clear();
        memset(cost,0,sizeof(cost));
        //cout<<cost[1][4];

    }

    return 0;
}




/*
#include<bits/stdc++.h>
using namespace std;
#define me boss
#define ll long long int
int vis[555],dis[555],cost[555][555];
map<int,vector<int> >graph;

struct comp
{
    bool operator () (const int&a, const int&b)
    {
        return dis[a] > dis[b];
    }

};

void Dijkstra(int start)
{
    vis[start]=1;
    dis[start]=0;

    priority_queue<int,vector<int>,comp>pq;
    pq.push(start);

    while(!pq.empty())
    {
        int current=pq.top();
        pq.pop();

        //for( __typeof(Map[current].begin()) it=Map[current].begin(); it!=Map[current].end(); it++)
        //for(int i=0; i<graph[u].size(); i++)
        for(__typeof(graph[current].begin())it=graph[current].begin(); it!=graph[current].end(); it++)
        {
            if(vis[*it]==0)
            {
                vis[*it]=1;
                dis[*it]=max(dis[current],cost[current][*it]);
                pq.push(*it);
            }

            else if(dis[*it]>max(dis[current],cost[current][*it]))
            {
                dis[*it]=max(dis[current],cost[current][*it]);
                pq.push(*it);
            }
        }
    }
}


int main()
{
    int t;
    scanf("%d",&t);
    for(int j=0; j<t; j++)
    {
        int n,m,a,b,c,s;
        scanf("%d %d",&n,&m);
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            graph[a].push_back(b);
            graph[b].push_back(a);
            if(cost[a][b]==0)
            {
                cost[a][b]=c;
                cost[b][a]=c;
            }
            else
            {
                cost[a][b]=min(cost[a][b],c);
                cost[b][a]=min(cost[a][b],c);
            }
        }
        cin>>s;
        memset(dis,-1,sizeof(dis));
        printf("Case %d:\n",j+1);

        Dijkstra(s);

        for(int i=0; i<n; i++)
        {
            if(dis[i]==-1)
                printf("Impossible\n");
            else
                printf("%d\n",dis[i]);
            graph[i].clear();
        }

        memset(vis,0,sizeof(vis));
        memset(cost,0,sizeof(cost));

    }

    return 0;
}
*/
