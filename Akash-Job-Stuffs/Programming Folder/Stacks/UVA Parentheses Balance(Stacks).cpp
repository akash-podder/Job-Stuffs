#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#include<cstdio>
#include<stack>
#include<cstring>


using namespace std;
int main()
{
    int n,i,j,length;

    scanf("%d\n",&n);

    getc(stdin);

    while(n--)
    {
        stack<char> checker;

        char str[130];

        gets(str);

        length=strlen(str);

        for(i=0; i<length; i++)
        {
            if(str[i]=='(' || str[i]=='[')
            {
                checker.push(str[i]);
            }

            else if(str[i]==')')
            {
                if(checker.empty() || checker.top()!='(')
                {
                    checker.push('a');
					break;
                }

                checker.pop();

            }


            else if(str[i]==']')
            {

                if(checker.empty() || checker.top()!='[')
                {
                    checker.push('a');
					break;
                }

                checker.pop();

            }

        }

        if(checker.empty())
        {
            printf("Yes\n");
        }

        else
        {
            printf("No\n");
        }


    }



    return 0;
}
