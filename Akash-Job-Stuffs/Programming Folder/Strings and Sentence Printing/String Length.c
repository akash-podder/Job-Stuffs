#include<stdio.h>

int string_length(char str[])
{
    int i;

    for(i=0; str[i] != '\0'; i++);
    {
        return i;
    }

}

int main()
{
    char country[1000];

    int length;

    printf("Enter a String :");

    while(1==scanf("%s",country))
    {
        length=string_length(country);

        printf("Length:%d\n",length);
    }

    return 0;
}
