#include<stdio.h>

int main()

{
    int a,b;
    char sign;

    printf("Enter Plus or Minus or Multiply or Division or Remainder Sign:");
    scanf("%c",&sign);

    printf("Enter 1st Number:");
    scanf("%d",&a);

    printf("Enter 2nd Number:");
    scanf("%d",&b);

    if (sign=='+')
        printf("%d+%d=%d",a,b,a+b);
    else if (sign=='-')
        printf("%d-%d=%d",a,b,a-b);
    else if (sign=='*')
        printf("%d*%d=%d",a,b,a*b);
    else if (sign=='/')
        printf("%d/%d=%d",a,b,a/b);
    else if (sign=='%')
        printf("Remainder of %d and %d=%d",a,b,a%b);
    else
        printf("You have not entered Plus or Minus or Multiply or Division or Remainder Sign.");

    return 0;
}
