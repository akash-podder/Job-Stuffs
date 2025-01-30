#include<stdio.h>

int main()
{
    int n,num,row,ColSpace,ColChar;

    printf("Enter Number of Rows in Diamond(For Upper Half):");

    scanf("%d",&num);

    n=num;

    for(row=1; row<=num; row++)               /*Here "Row" variable is used as "i" */
    {
        for(ColSpace=1; ColSpace<=(n-1); ColSpace++)
        //for(ColSpace=(n-row); ColSpace>=1; ColSpace--)
        {
            printf(" ");
        }

        n--;

       // int printChar=1;    /*   Ei Variable tai amra print korbo   printChar   */
        int value=1;

        for(ColChar=1; ColChar<=row; ColChar++)   /*   Eikane amra joto tomo current row te toto gula star print kortasi.... tai ColStar<=row sorto diyechi   */
        {
            printf("%d ",value);

            value++;
        }


        printf("\n");
    }


    return 0;
}
