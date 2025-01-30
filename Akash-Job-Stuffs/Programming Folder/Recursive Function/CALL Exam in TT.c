#include<stdio.h>

int CALL(int x,int y)
{
    if(x<0 || y>5)
    {
        return;
    }

    y=CALL(--x,y++);    /* Eikane x=CALL(x-1,y+1)  dile tor sob x aer man zero huia jaito   */
    printf("%d %d\n",x,y);

    return x;


}

int main()
{
    int x;

    x=CALL(2,3);
    printf("%d",x);


    return 0;
}
