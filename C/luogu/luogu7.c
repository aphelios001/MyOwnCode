#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    int *b=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(j+1>n-1)
        {
            break;
        }
        b[i]=abs(a[j]-a[j+1]);
        j++;
    }
    int count=0;
    for(j=0;j<=n-2;j++)
    {
    for(int i=1;i<=n-1;i++)
    {
        if(b[j]==i)
        {
            count++;
        }
    }
    }
    if(count==n-1)
    {
        printf("Jolly");
    }
    else
    {
        printf("Not jolly");
    }
}