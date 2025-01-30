#include<stdio.h>

int main()
{
    int n,row,ColSpace,ColChar;

    printf("Enter Number of Rows in Diamond(For Upper Half):");

    scanf("%d",&n);

    for(row=0; row<=n; row++)    /* Sudu Matro Pascal aer ketre amra row 0 theke start korbo    */                      /*Here "Row" variable is used as "i" */
    {
        for(ColSpace=1; ColSpace<=(n-row); ColSpace++)
        //for(ColSpace=(n-row); ColSpace>=1; ColSpace--)
        {
            printf(" ");
        }


        int printChar=1;    /*   Ei Variable tai amra print korbo   printChar   */
        int numerator=row;
        int denominator=1;

        for(ColChar=0; ColChar<=row; ColChar++)        /*  Eikane zero'th row te amra 1 print korchi....abr 1st row te 2 ta.... tai (ColChar=1 tika row+1)   or (CholChar= tika row) porjonto hobe   */
        //for(ColChar=1; ColChar<=(row+1); ColChar++)   /*   Eikane amra joto tomo current row te toto gula star print kortasi.... tai ColStar<=row sorto diyechi  */
        {
            printf("%d ",printChar);           /*    Eikane amra Number print aer por ae space diyechi...jaita odik joruri....nahole figure ta asbe nah    */

            printChar=printChar*numerator;
            printChar=printChar/denominator;

            numerator--;
            denominator++;

        }

        printf("\n");
    }


    return 0;
}
