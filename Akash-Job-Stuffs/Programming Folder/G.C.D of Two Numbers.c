#include<stdio.h>
#include<math.h>

int main()
{
    int small,big,remainder;
    printf("Enter 1st Number:");
    scanf("%d",&small);
    printf("Enter 2nd Number:");
    scanf("%d",&big);

    while(small>0)
    {
        remainder=big%small;
        big=small;
        small=remainder;

    }
            printf("%d\n",big);

    return 0;

}
