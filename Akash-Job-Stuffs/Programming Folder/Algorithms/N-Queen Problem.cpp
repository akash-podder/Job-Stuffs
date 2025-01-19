#include<stdio.h>
#include<bits/stdc++.h>

/* Problem:
    Have to place N queens in a (N*N) chess board so that no queen can kaita na fele
*/

/*
1. Start in the leftmost column
2. If all queens are placed
    return true;
3. Try all rows in the current column. Do following for every tried row:
    a) If the queen can be safely placed in this row then mark this[row,column]
    as a part of the solution and recursively check if placing queen here leads to a solution
    b) If placing queen in [row,column] leads to a solution then return true
    c) If placing  queen doesn't lead to a solution then unmark this [row,column]
    and go to step (a) to try other rows.

*/

#define sz 100

bool isSafe(int mat[sz][sz],int n,int row,int col)
{
    int i,j;

    for(i=0;i<col;i++)
    {
        if(mat[row][i]==1)
        {
            return false;
        }
    }

    for(i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
    {
        if(mat[i][j]==1)
        {
            return false;
        }
    }

    for(i=row+1,j=col-1; i<n && j>=0;i++,j--)
    {
        if(mat[i][j]==1)
        {
            return false;
        }
    }


    return true;
}



bool findSolution(int mat[sz][sz],int col,int n)
{
    int i;
    if(col>=n)   /*   Recursion aer base condition  */
    {                   /*   mane jokon amra jai column pass korsi saita size "n" thika boro huia jabe tokon ei condition true hobe... eitar mane amra queen bosaite bosaite last queen ta bosaite sookom huisi... tai true return kortase */
        return true;
    }

    for(i=0; i<n; i++)  /*  Eita hochhe amra bortoman jai row te asi sai column pura ta ekbar scan kora   */
    {
        if(isSafe(mat,n,i,col))
        {
            mat[i][col]=1;
            if(findSolution(mat,col+1,n)==true)
            {
                return true;
            }

            mat[i][col]=0;
        }
    }

    return false;
}


using namespace std;
int main()
{
    int n,i,j,col;
    cin>>n;
    int mat[sz][sz];

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            mat[i][j]=0;
        }
    }

    col=0; // starting column

    if(findSolution(mat,col,n))
    {
        cout<<"Solution found"<<endl;

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cout<<mat[i][j]<<" ";
            }

            cout<<endl;
        }

    }

    else
    {
        cout<<"There is no solution"<<endl;
    }

    //cout<<"Solution found"<<endl;

    return 0;
}
