#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fPointer;

    char singleLine[200];

    fPointer=fopen("Food.txt","r");

    //while(!feof(fPointer))
    //{
        fgets(singleLine,200,fPointer);
        puts(singleLine);

    //}

    fclose(fPointer);



    return 0;
}

