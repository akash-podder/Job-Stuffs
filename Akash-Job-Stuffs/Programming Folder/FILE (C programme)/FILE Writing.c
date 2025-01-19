#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fPointer;

    fPointer=fopen("Food.txt","w");

    fprintf(fPointer,"I love Cakes\n");      /*Eikane 2 ta parameter. 1st aer ta File pointer and 2nd ta text likhar jonno*/

    fclose(fPointer);



    return 0;
}
