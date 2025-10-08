#include<stdio.h>
#include<string.h>
int main()
{
    char s[255];
    scanf("%s",s);
    int i=0;
    int t=0;
    while(s[i]!='@')
    {
        if(s[i]=='(')
        {
            t++;
        }
        if(s[i]==')')
        {
            t--;
        }
        if(t<0)
        {
            printf("NO");
            return 0;
        }
        i++;
    }
    if(t==0)
        printf("YES");
    else
        printf("NO");
    return 0;
}