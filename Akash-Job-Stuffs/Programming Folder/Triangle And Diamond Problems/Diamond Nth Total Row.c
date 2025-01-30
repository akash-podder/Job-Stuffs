#include<stdio.h>

/* "SPACE" print korar main sorto (n-current row) and "STAR" print korar main sorto hochhe (2*current-1) */
                    /* Eikane "row" variable current row hisvabe treat hochhe */



int main()
{
    int x,n,row,ColSpace,ColStar;

    printf("Enter Number of Rows in Diamond(For Upper Half):");

    scanf("%d",&x);

    n=(x/2)+1;

    for(row=1; row<=n; row++)                      /*Here "Row" variable is used as "i" */
    {
        for(ColSpace=1; ColSpace<=(n-row); ColSpace++)
        //for(ColSpace=(n-row); ColSpace>=1; ColSpace--)
        {
            printf(" ");
        }

        for(ColStar=1; ColStar<=((2*row)-1); ColStar++)
        {
            printf("*");
        }

        printf("\n");
    }


        /*Eiakne 2 ta main for loop. Ekta Upper Triangle aer jonno.Onno ta Lower Triangle aer jonno*/


    for(row=(n-1); row>=1; row--)           /* Jehetu eikane row ekon kombe tai "row" aer sonkha (n-1) tika "1" porjonto hobe hobe*/
    {
        for(ColSpace=1; ColSpace<=(n-row); ColSpace++)
        {
            printf(" ");
        }

        for(ColStar=1; ColStar<=((2*row)-1); ColStar++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}

