#include<stdio.h>

/* "STAR" print korar main sorto (n-current row) and "SPACE" print korar main sorto hochhe (2*current-1) */
            /* Eikane "row" variable current row hisvabe treat hochhe */



int main()
{
    int row,ColSpace,ColStar,n;

    printf("Enter Number of Rows in Triangle:");  /*Mane "n" huilo koita row print korbo.Mane highest "i" aer maan hocche "n"*/

    scanf("%d",&n);

    for(row=n;row>=1;row--)                             /* "i" huilo row sonkha*/
    {
        for(ColSpace=1;ColSpace<=(n-row);ColSpace++)     /* Space aer shorto sobsomoy agge dibo, the Star aer ta */
        {
            printf(" ");
        }

        for(ColStar=1;ColStar<=((2*row)-1);ColStar++)    /* Because column=(2*current row-1) where i=current row and n=highest row */
        {
             printf("*");
        }

        printf("\n");
    }

    return 0;
}
