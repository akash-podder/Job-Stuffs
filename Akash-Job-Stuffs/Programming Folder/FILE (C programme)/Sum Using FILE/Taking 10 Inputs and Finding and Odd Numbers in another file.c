#include<stdio.h>
//#include<bits/stdc++.h>

//using namespace std;

int main()
{
    FILE *finput,*foutput;

    int i,a;

    finput=fopen("10 Inputs of Number.txt","r");
    foutput=fopen("10 Outputs of Number.txt","w");

    for(i=1;i<=10;i++)
    {
        fscanf(finput, "%d",&a);
        if(a%2!=0)
        {
            fprintf(foutput, "%d\n",a);
        }
    }

    fclose(finput);
    fclose(foutput);


    return 0;
}
