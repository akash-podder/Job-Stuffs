#include<stdio.h>
#include<math.h>
#define PI 3.14159

 int main()
 {
     double R,V;
     scanf("%lf",&R);

     V=((4/3.0)*PI*R*R*R);     //Tip: Use (4/3.0) or (4.0/3) in your formula, because some languages (including C++) assume that the division's result between two integers is another integer. :)

     printf("A=%0.3lf\n",V);




     return 0;
 }
