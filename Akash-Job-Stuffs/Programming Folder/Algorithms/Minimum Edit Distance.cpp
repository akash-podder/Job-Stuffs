#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

#define sz 100
#define diag 1
#define up 2
#define left 3

int main()
{
    string seqA,seqB,seqC;
    int lenA,lenB,i,j,mat[sz][sz],dir[sz][sz];

    cin>>seqA>>seqB;
    lenA=seqA.size();
    lenB=seqB.size();

    for(i=0; i<=lenA; i++) mat[i][0]=i;
    for(j=0; j<=lenB; j++) mat[0][j]=j;

    for(i=1; i<=lenA; i++)
    {
        for(j=1; j<=lenB; j++)
        {
            if(seqA[i-1]==seqB[j-1])
            {
                mat[i][j]=mat[i-1][j-1];
                dir[i][j]=diag;
            }
            else
            {
                mat[i][j]=min(min(mat[i-1][j],mat[i][j-1]),mat[i-1][j-1])+1;

                if(mat[i][j]==mat[i][j-1]) dir[i][j]=left;

                else if(mat[i][j]==mat[i-1][j]) dir[i][j]=up;

                else dir[i][j]=diag;
            }
        }
    }

    cout<<"Minimum Edit Distance: "<<mat[lenA][lenB]<<endl;

    return 0;
}
