#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int*a=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int count=1;
    int temp=0;
    for(int i=0;i<n;i++)
    {
        if(count>temp)
            temp=count;
        if(a[i+1]!=a[i]+1)
        {
            count=1;
        }
        if(a[i+1]==a[i]+1)
        {
            count++;
        }
    }
    printf("%d",temp);
}