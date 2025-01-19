#include<stdio.h>
#include<conio.h>

int main()

{
   int a,b,c,D;
   double X1,X2;
   printf("Enter The Value of a,b,c:");
   scanf("%d%d%d",&a,&b,&c);

   D=((b*b)-4*a*c);

   if(D>=0)
   {
       X1=(-b+sqrt((b*b)-4*a*c))/2*a;
       X2=(-b-sqrt((b*b)-4*a*c))/2*a;
       printf("The Value of X1=%lf\nThe Value of X2=%lf",X1,X2);

   }

    else
        printf("The solution can not be Done or Undefined\n");



}

