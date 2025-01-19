#include<stdio.h>

int main()
{
    FILE *input,*output;

    int a,b,sum;

    input=fopen("input file.txt", "r");
    output=fopen("output file.txt", "w");

    fscanf(input, "%d%d",&a,&b);

    sum=a+b;

    fprintf(output, "The Sum of %d and %d is: %d",a,b,sum);

    fclose(input);
    fclose(output);



    return 0;
}
