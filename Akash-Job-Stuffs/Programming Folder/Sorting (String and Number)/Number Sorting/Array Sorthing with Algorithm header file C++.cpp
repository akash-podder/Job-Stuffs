#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
    int ara[100],i,length;

    printf("Enter The Length Of The Array:");

    scanf("%d",&length);

    for(i=0;i<length;i++)
    {
        scanf("%d",&ara[i]);
    }

    sort(ara,ara+length);   /*Eikane "a" huilo ekta array and "n" huile array aer length*/

    for(i=0;i<length;i++)
    {
        printf("%d\t",ara[i]);
    }

    return 0;
}
