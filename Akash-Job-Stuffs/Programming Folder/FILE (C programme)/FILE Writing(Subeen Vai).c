#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fPointer;

    char sentence[1000];

    fPointer=fopen("File Writing.txt","w");

   // fprintf(fPointer,"I love Cakes\n");      /*Eikane 2 ta parameter. 1st aer ta File pointer and 2nd ta text likhar jonno*/

    gets(sentence);

    fputs(sentence,fPointer);

    fclose(fPointer);



    return 0;
}
