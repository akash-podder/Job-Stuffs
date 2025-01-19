#include<stdio.h>

int main()
{
    int ara[]={10,20,30,40,50,60,70,80,90,100};
    int i,j,temp;
    for(i=0,j=9;i<(10/2);i++,j--) /*eikane i<10 dile abr ara te swap huito. and output asto 10,20,30...100. Tai eikane i<5 or i<(10/2) nite hobe. Shariar Suveen Book Page-93,94 */
    {
        temp=ara[j];
        ara[j]=ara[i];
        ara[i]=temp;
    }
    for(i=0;i<10;i++)
    {
        printf("%d\t",ara[i]); /* printf ae \t use kora huise. \t mane 1 tb dhure ae jabe*/
    }


    return 0;
}
