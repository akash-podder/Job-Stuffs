#include<stdio.h>
#include<string.h>

int main()
{
    int i,j;
    char a[1000],b[1000],str[1000000];
    int length_a,length_b;

    gets(a);            /*Eiakne scanf and Printf use korle oo somoshha chilo nah. Karon eikane space fact kore nah*/
    gets(b);

    length_a=strlen(a);
    length_b=strlen(b);

    for(i=0,j=0; i<length_a; i++,j++)
    {
        str[j]=a[i];
    }

    for(i=0; i<length_b; i++,j++)
    {
        str[j]=b[i];
    }

    str[j]='\0';

    puts(str);

    return 0;
}
