#include<stdio.h>
#include<string.h>
int main()
{
    char star[7];
    char group[7];
    int starnum=1;
    int groupnum=1;
    scanf("%s",&star);
    scanf("%s",&group);
    for(int i=0;star[i]!='\0';i++)
    {
        starnum = starnum * (star[i]+1-'A');
    }
    for(int i=0;group[i]!='\0';i++)
    {   
        groupnum = groupnum * (group[i]+1-'A');
    }
    if(starnum%47==groupnum%47)
    {
        printf("GO");
    }
    else
    {
        printf("STAY");
    }
}