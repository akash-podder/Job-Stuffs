//calculates value of  (a ^ p) % m
//process used : Divide and Conquer

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;


/*
Formula:

(a*b)%m=((a%m)*(b%m))%m
*/

//BIG MODE CODE...
long long int  big_mod ( long long int a,long long int p,long long int m )
{
    if ( p == 0 )
    {
        return 1; // If power is 0, then a ^ 0 = 1 for any value of a, And 1 Mod m=1 for any value of m, So return 1
    }

    if ( p%2==1 ) // If power is odd, Split it : a ^ 5 =( a )* (a ^ 4) --> left and right child respectively.
    {
        return ((a%m)*(big_mod(a,p-1,m)))%m;
    }

    else if(p%2==0) //If power is even then split it equally and return the result...
    {
        //long long c = bigmod ( a, p / 2, m );
        //return ( (c%m) * (c%m) ) % m;
        return ( big_mod(a,p/2,m )* big_mod(a,p/2,m) )%m;   /*  Big Mod call kora mane ei (%m) kora... tai direct gun diya gunfol reh mod kora  */
    }
}





int main(){
    printf("input format...\n (a^p) MOD m\n");
    long long int a,p,m;

    printf("enter a : ");
    scanf("%lld",&a);
    printf("\n");
    printf("enter p : ");
    scanf("%lld",&p);
    printf("\n");
    printf("enter m : ");
    scanf("%lld",&m);
    printf("\n");



    //Calling...
    printf("result is %lld\n",big_mod(a,p,m));


   return 0;
}
