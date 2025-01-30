#include<stdio.h>

int main()
{
    char ch;
    printf("Enter any Alphabet:");
    scanf("%c",&ch);

    if(ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U')
    {
        printf("The Alphabet %c is an Vowel\n",ch);
    }

    else
    {
        printf("The Alphabet %c is a Consonant\n",ch);
    }

    return 0;

}
