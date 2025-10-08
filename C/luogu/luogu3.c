#include<stdio.h>
int main()
{
    int a[8];
    int n,m;
    a[0]=0;
    for(int i=1;i<=7;i++)
    {
        scanf("%d %d",&n,&m);
        a[i]=m+n;
    }
    int index;
    int max=a[1];
    for(int i=1;i<=7;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
            index =i;
        }
    }
    if(max>8)
        printf("%d",index);
    else
    {
        printf("%d",0);
    }
}