#include<stdio.h>

int main()
{
    int *pointer;

    int a=10,b=5;

    printf("a=%d\n",a);

    pointer=&a;  /* &a dewa mane holo a aer location ta ekon pointer nirdesh korbe*/

    *pointer=13;   /*  *pointer mane holo value raka    */

    printf("a=%d(Variable a)\n",a);

    printf("a=%d (Variable Pointer) and Location of a=%d\n",*pointer,pointer);     /* Pointer aer value change korle eti jai variable nirdesh kore taar oo value change huia jawa   */



    return 0;
}
