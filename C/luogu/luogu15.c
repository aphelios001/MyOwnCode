#include<stdio.h>
#include<string.h>
int main()
{
    char digit[200],diagram[40000];
    scanf("%s",digit);
    int count=strlen(digit);
    strcpy(diagram,digit);
    for(int i=1;i<count;i++)
    {
        scanf("%s",digit);
        strcat(diagram,digit);
    }
    printf("%d ",count);
    char num='0';
    int sum=0;
    for(int i=0;i<=strlen(diagram);i++)
    {
        if(diagram[i]==num)
        {
            sum++;
        }
        else
        {
            num=diagram[i];
            printf("%d ",sum);
            sum=1;
        }
    }
}