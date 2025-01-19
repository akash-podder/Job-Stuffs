#include<iostream>

using namespace std;

int main()
{
    int length;
    string a,b;  /* C++ ae string variable size likha lagge nah....arr third bracket oo lagge nah*/

    cin>>a;

    length=a.length();  /*Eita mane "a" namok string aer size ber kora*/

    b=a.substr(0,length/2); /*Eita maen huilo "a" string aer 0 tika length/2 porjonto copy huia "b" string ae copy kobre*/

    cout<<b;

    return 0;
}
