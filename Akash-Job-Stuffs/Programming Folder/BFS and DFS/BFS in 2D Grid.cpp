#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int bomb[1010][1010];
int color[1010][1010];
int row,colomn;

int bfs(int Start_x,int Start_y,int End_x,int End_y)
{
    int x,y,x1,y1;

    queue<int>q;

    int dx[4]= {+1,-1,0,0};
    int dy[4]= {0,0,+1,-1};

    q.push(Start_x);
    q.push(Start_y);

    color[Start_x][Start_y]=0;

    while(!q.empty())
    {
        x=q.front();
        q.pop();

        y=q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            x1=x+dx[i];
            y1=y+dy[i];

            if((x1>=0 && y1>=0) && (x1<=row && y1<=colomn))
            {
                if(color[x1][y1]==-1 && bomb[x1][y1]!=1)    /*  Eita mane oi (x1,y1) agge tika visit kora nah... and (x1,y1) co-ordinate aer moddhe bomb nai...  */
                {
                    color[x1][y1]=color[x][y]+1;
                    q.push(x1);
                    q.push(y1);
                }

                if(x1==End_x && y1==End_y)
                {
                    return color[x1][y1];
                }

            }
        }
    }

}


int main()
{
    int ans;

    while(cin>>row>>colomn)
    {
        int Start_x,Start_y,End_x,End_y;

        if(row==0 && colomn==0)
        {
            return 0;
        }

        int number_row_bomb;

        memset(bomb,0,sizeof(bomb));
        memset(color,-1,sizeof(color));

        cin>>number_row_bomb;

        for(int i=0; i<number_row_bomb; i++)
        {
            int n,number_of_bomb_in_a_row;

            cin>>n;

            cin>>number_of_bomb_in_a_row;

            for(int j=0; j<number_of_bomb_in_a_row; j++)
            {
                int a;
                cin>>a;
                bomb[n][a]=1;
            }

        }

        cin>>Start_x>>Start_y;
        cin>>End_x>>End_y;

        ans=bfs(Start_x,Start_y,End_x,End_y);

        cout<<ans<<endl;

    }


    return 0;
}
