#include<stdio.h>
#include<bits/stdc++.h>

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

    for(i=0; i<=lenA; i++)
    {
        mat[i][0]=0;
    }
    for(j=0; j<=lenB; j++)
    {
        mat[0][j]=0;
    }

    for(i=1; i<=lenA; i++)   /*  Prothom for loop kintu lenA aer jonno... karon ei for aer [i][j]  aer maan gula amra matrix ae store kortasi... tai matrix aer [i][j] aer moto koira for loop dite hobe  */
    {
        for(j=1; j<=lenB; j++)
        {
            if(seqA[i-1]==seqB[j-1])   /*  Jehetu string 0 tika start huise.... tai  seqA[i-1] arr seqB[j-1] hobe */
            {
                mat[i][j]=mat[i-1][j-1]+1;
                dir[i][j]=diag;
            }

            else
            {
                mat[i][j]=max( max(mat[i-1][j],mat[i][j-1]), mat[i-1][j-1] );

                if(mat[i][j]==mat[i-1][j])
                {
                    dir[i][j]=up;
                }

                else if(mat[i][j]==mat[i][j-1])
                {
                    dir[i][j]=left;
                }

                else
                {
                    dir[i][j]=diag;
                }
            }
        }
    }

    /*
    for(int i=0;i<=lenA;i++)
    {
        for(int j=0;j<=lenB;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    */

    cout<<"LCS Length: "<<mat[lenA][lenB]<<endl;

    i=lenA;
    j=lenB;

    seqC="";  /*  String ae "" (null) assign nah korle seqC+=seqA[i-1] likha jabe nah... tokon error dekai... mane C++ string ae char by char jog kore rakte gele string ke "" korte hobe 1st ae  */

    while(i>0 && j>0)
    {
        if(dir[i][j]==diag)
        {
            if(seqA[i-1]==seqB[j-1])   /* Sudu matro diagonally gele(diagonally mille oo diag sign disi amra abr "min" newar time ae oo diag sign disi... orthat amra 2 bar "diag" sign disi but ei ketre amra sudhu jodi "letter eki hui" sai ketro consider korbo...tai extra ekta if lagano huise) and amra saita subsequence include korbo  */
            {
                seqC+=seqA[i-1];  /*  jehetu  " seqA[i-1]==seqB[j-1] " tai jekono ekta add korle ei huitase ...  karon eida common sub-sequence tai only letter mille strC te jog korbo*/
            }
            i--;
            j--;
        }
        else if(dir[i][j]==left)
        {
            j--;
        }

        else
        {
            i--;
        }
    }

    reverse(seqC.begin(),seqC.end());

    cout<<seqC;

    return 0;
}
