#include<stdio.h>
#include<string.h>
int main()
{
    char str[255];
    int boy=0,girl=0;
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='b'&&str[i+1]=='o'&&str[i+2]=='y')
        {
            i=i+2;
            boy++;
            continue;
        }
        if(str[i]=='o'&&str[i+1]=='y')
        {
            i=i+1;
            boy++;
            continue;
        }
        if(str[i]=='b'&&str[i+1]=='o'&&str[i+2]!='y')
        {
            i=i+1;
            boy++;
            continue;
        }
        if(str[i]=='b'&&str[i+1]!='o'&&str[i+2]!='y')
        {
            boy++;
            continue;
        }
        if(str[i-1]!='b'&&str[i]=='o'&&str[i+1]!='y')
        {
            boy++;
            continue;
        }
        if(str[i-2]!='b'&&str[i-1]!='o'&&str[i]=='y')
        {
            boy++;
            continue;
        }   

    }
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='g')
        {
            girl++;
        }
        if(str[i]=='i'&&str[i-1]!='g')
        {
            girl++;
        }
        if(str[i]=='r'&&str[i-1]!='i'&&str[i-2]!='g')
        {
            girl++;
        }
        if(str[i]=='l'&&str[i-1]!='r'&&str[i-2]!='i'&&str[i-3]!='g')
        {
            girl++;
        }
    }

    printf("%d\n",boy);
    printf("%d",girl);
}