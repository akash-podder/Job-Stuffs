#include<stdio.h>

int main()
{
    int a,b,c;
    char sign;
    printf("Enter 1st number:");
    scanf("%d",&a);
    printf("Enter 2nd number:");
    scanf("%d",&b);

    c=a+b;
    sign='+';
    printf("%d%c%d=%d\n",a,sign,b,c);

    c=a-b;
    sign='-';
    printf("%d%c%d=%d\n",a,sign,b,c);

    c=a*b;
    sign='*';
    printf("%d%c%d=%d\n",a,sign,b,c);

    c=a/b;
    sign='-';
    printf("%d%c%d=%d\n",a,sign,b,c);

    return 0;
}
