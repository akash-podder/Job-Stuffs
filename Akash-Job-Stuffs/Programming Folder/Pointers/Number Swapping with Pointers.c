#include<stdio.h>

void swap_function(int *a, int *b)
{
    int swap;
    swap=*a;     /*   pointer a (*a) holo value nirdesh kore. Arr "a=&x" mane hochhe x aer location ta a pointer a jabe*/
    *a=*b;
    *b=swap;
    //printf("a=%d b=%d",*a,*b);
}


int main()
{
    int x,y;

    printf("Enter Two Numbers You Want To Swap:");

    scanf("%d%d",&x,&y);

    printf("x=%d and y=%d\n",x,y);

    swap_function(&x,&y);  /*Eikane "&x" diye "x" variable aer location ta swap_function aer *a(pointer a) te location patachhe*/

    printf("New x=%d and New y=%d\n",x,y);

    return 0;
}
