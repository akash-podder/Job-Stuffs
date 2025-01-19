#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,length,word_started;

    char str[1000],word[1000];

    gets(str);

    length=strlen(str);

    word_started=0;

    for(i=0,j=0;i<=length;i++)         /*   Eikane for loop aer condition ae (i<length) dile last aer word ta baad jabe..... tai equal sign dewa lagbe ei..... (i<=length)   */
    {
        if(str[i]>='a' && str[i]<='z')
        {
            if(word_started==0)         /*  word_started=0 mane eitai oi word aer 1st letter..jaita kina small letter... tai eita ke Capital letter korbo...... and word_started=1 korbo jate bujte pari pore je word ta start huise..... */
            {
                word_started=1;
                word[j]='A'+str[i]-'a';    /* Ete kore small letter capita letter huia gelo  */
                j++;
            }

            else
            {
                word[j]=str[i];
                j++;
            }
        }


        else if(str[i]>='A' && str[i]<='Z')
        {
            if(word_started==0)
            {
                word_started=1;
                word[j]=str[i];
                j++;
            }

            else //if(word_started==1)
            {
                word[j]='a'+str[i]-'A';    /*   Eita huilo capital letter ke small letter ae kora... karon word aer middle ae capital letter small letter hobe    */
                j++;
            }

        }


        else if(str[i]>='0' && str[i]<='9')
        {
            if(word_started==0)
            {
                word_started=1;
            }
            word[j]=str[i];
            j++;
        }


        else
        {
            if(word_started==1)
            {
                word_started=0;

                word[j]='\0';            /*  Eikane jehetu word sesh huia gese tai NULL character diye space aer kaaj korbo jaat ae new word print hui  */

                printf("%s\t",word);

                j=0;                    /*  Jehetu word ta eikane ei sesh huia gese tai word[] variable ae abr '0' element tika start korbo   */
            }

        }

    }



    return 0;
}
