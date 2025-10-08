#include<stdio.h>
#include<string.h>
int main()
{
    char s[200];
    gets(s);
    int count=0;
    int i=0;
    while(i<strlen(s))
    {
        if(s[i]=='a'||s[i]=='d'||s[i]=='g'||s[i]=='j'||s[i]=='m'||s[i]=='p'||s[i]=='t'||s[i]=='w')
        {
            count+=1;
        }
        else if(s[i]=='b'||s[i]=='e'||s[i]=='h'||s[i]=='k'||s[i]=='n'||s[i]=='q'||s[i]=='u'||s[i]=='x')
        {
            count+=2;
        }
        else if(s[i]=='c'||s[i]=='f'||s[i]=='i'||s[i]=='l'||s[i]=='o'||s[i]=='r'||s[i]=='v'||s[i]=='y')
        {
            count+=3;
        }
        else if(s[i]=='s'||s[i]=='z')
        {
            count+=4;
        }
        else if(s[i]==' ')
        {
            count+=1;
        }
        i++;
    }
    printf("%d",count);

}