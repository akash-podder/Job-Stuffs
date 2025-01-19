#include<stdio.h>
#include<math.h>
/* "SPACE" print korar main sorto (n-current row) and "STAR" print korar main sorto hochhe (2*current-1).....eita diamond aer ketre... diamond with space aer ketre amra star aer jigai khali space arr star interchange korbo.... then 2 ta main for loop aer jai 1st star print huise sai 2 tai copy kore abr sesh ae dibo */
/* Eikane "row" variable current row hisvabe treat hochhe */



int main()
{
    int n,row,ColSpace,ColStar,i;

    printf("Enter Number of Rows in Diamond(For Upper Half):");

    scanf("%d",&n);


    for(row=1; row<=n; row++)                      /*Here "Row" variable is used as "i" */
    {
        //for(ColSpace=1; ColSpace<=(n-row); ColSpace++)
        for(ColStar=n; ColStar>=row; ColStar--)
        {
            printf("*");
        }

        for(ColSpace=2; ColSpace<((2*row)-1); ColSpace++)
        {
            printf(" ");
        }

        if(row==1)
        {
            printf("\b");
        }

        //for(ColSpace=1; ColSpace<=(n-row); ColSpace++)
        for(ColStar=n; ColStar>=row; ColStar--)
        {
            printf("*");
        }

        printf("\n");
    }


    /*Eiakne 2 ta main for loop. Ekta Upper Triangle aer jonno.Onno ta Lower Triangle aer jonno*/


    for(row=(n-1); row>=1; row--)           /* Jehetu eikane row ekon kombe tai "row" aer sonkha (n-1) tika "1" porjonto hobe hobe*/
    {
         //for(ColSpace=1; ColSpace<=(n-row); ColSpace++)
        for(ColStar=n; ColStar>=row; ColStar--)
        {
            printf("*");
        }

        for(ColSpace=2; ColSpace<((2*row)-1); ColSpace++)
        {
            printf(" ");
        }

        if(row==1)
        {
            printf("\b");
        }

        //for(ColSpace=1; ColSpace<=(n-row); ColSpace++)
        for(ColStar=n; ColStar>=row; ColStar--)
        {
            printf("*");
        }

        printf("\n");
    }


    return 0;
}

