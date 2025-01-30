#include<stdio.h>

int main()
{
    int n,row,ColSpace,ColChar,value=1;

    printf("Enter Number of Rows in Diamond(For Upper Half):");

    scanf("%d",&n);

    for(row=1; row<=n; row++)    /* Sudu Matro Pascal aer ketre amra row 0 theke start korbo    */                      /*Here "Row" variable is used as "i" */
    {
        //for(ColSpace=1; ColSpace<=(n-row); ColSpace++)
        for(ColSpace=(n-row); ColSpace>=1; ColSpace--)
        {
            printf(" ");
        }


       // int printChar=1;    /*   Ei Variable tai amra print korbo   printChar   */

        for(ColChar=1; ColChar<=row; ColChar++)   /*   Eikane amra joto tomo current row te toto gula star print kortasi.... tai ColStar<=row sorto diyechi   */
        {
            printf("%d ",value);           /*    Eikane amra Number print aer por ae space diyechi...jaita odik joruri....nahole figure ta asbe nah    */

            value++;

        }

        printf("\n");
    }


    return 0;
}

