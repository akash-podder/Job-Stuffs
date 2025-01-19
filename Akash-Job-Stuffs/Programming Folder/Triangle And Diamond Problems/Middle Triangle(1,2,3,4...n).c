#include<stdio.h>

int main()
{
    int n,row,ColSpace,ColStar;

    printf("Enter Number of Rows in Diamond(For Upper Half):");

    scanf("%d",&n);

    for(row=1; row<=n; row++)                      /*Here "Row" variable is used as "i" */
    {
        //for(ColSpace=1; ColSpace<=(n-row); ColSpace++)
        for(ColSpace=(n-row); ColSpace>=1; ColSpace--)
        {
            printf(" ");
        }

        for(ColStar=1; ColStar<=row; ColStar++)   /*   Eikane amra joto tomo current row te toto gula star print kortasi.... tai ColStar<=row sorto diyechi   */
        {
            printf("* ");           /*    Eikane amra star aer por ae space diyechi...jaita odik joruri....nahole figure ta asbe nah    */
        }

        printf("\n");
    }


    return 0;
}
