#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main()
{
    char a[51];  // Permutation ta only char array aer ketre kaaj korbe...string nah...

    while(gets(a))
    {
        if(a[0]=='#')
        {
            break;
        }

        else
        {
            if(next_permutation(a, a+strlen(a)))   //Use of next_permutation, which gives the lexicographical next permutation of the given array.
            {
                puts(a);
            }

            else
            {
                puts("No Successor");
            }
        }
    }

    return 0;
}
