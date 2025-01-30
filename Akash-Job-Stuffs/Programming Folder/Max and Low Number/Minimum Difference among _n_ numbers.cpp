#include<stdio.h>
#include<algorithm>   /* Sorting aer jonno ei header file lagbe... algorthom    */
#include<bits/stdc++.h>

using namespace std;


int main()
{
    int i,j,n,counter=0;

    printf("Enter The Size of The Array:");

    scanf("%d",&n);

    int ara[n],diff[10000];   /*  Eikane amra diff aer size n dite parbo nah because diff aer size array aer element tika besi huitase... karon prottek ta element aer sathe prottek tar difference bahir kora hochhe    */

    printf("Enter the Numbers:");

    for(i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=0; j<n && j!=i; j++)
        {
            diff[counter++]=abs(ara[i]-ara[j]);
        }
    }

    sort(diff,diff+counter);    /*Eikane diff array aer moddhe element ase  counter aer sonkha aer soman.... tai difff array aer size counter aer soman     */

    printf("The Minimum Difference is: %d",diff[0]);

    return 0;
}
