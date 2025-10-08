#include<stdio.h>
#include<string.h>
int main()
{
    char str[255];
    int a=0,b=0,c=0,i=0;
    scanf("%s",str);
    while(i<strlen(str))
    {
        if(str[i]=='a')
        {
            if(str[i+3]=='a')
            {
                a=a;
            }
            else if(str[i+3]=='b')
            {
                a=b;
            }
            else if(str[i+3]=='c')
            {
                a=c;
            }
            else
            {
                a=str[i+3]-'0';
            }
        }
        if(str[i]=='b')
        {
            if(str[i+3]=='a')
            {
                b=a;
            }
            else if(str[i+3]=='b')
            {
                b=b;
            }
            else if(str[i+3]=='c')
            {
                b=c;
            }
            else
            {
                b=str[i+3]-'0';
            }
        }
        if(str[i]=='c')
        {
            if(str[i+3]=='a')
            {
                c=a;
            }
            else if(str[i+3]=='b')
            {
                c=b;
            }
            else if(str[i+3]=='c')
            {
                c=c;
            }
            else
            {
                c=str[i+3]-'0';
            }
        }
        i=i+5;
    }
    printf("%d %d %d",a,b,c);

}