#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

/*

(a≡b) mod n  means:  a mod n ≡ b mod n  ---> then a & b are called Congruent numbers

let,
a=n*d1 + remainder .....(1)
b=n*d2 + remainder .....(2)

(a-b)=n*(d1-d2);

so, if  (a≡b) mod n  then   (a-b) will be a multiple of n...  mane   (a-b)  hobe n aer gunitok

*/



/*  This is the code for finding Largest "n"  for  three numbers  "a"  and  "b" and "c"

means,

a mod n ≡ b mod n ≡ c mod n

or,(a≡b≡c) mod n

*/
int main()
{
    int a,b,c,diff,n;

    cin>>a>>b>>c;
    //diff=abs(a-b);

    //n=__gcd(diff,abs(b-c));
    n=__gcd( abs(a-b),abs(b-c) );

    cout<<n<<endl;


    return 0;
}


/*

701 1059 1417

ans:358

*/
