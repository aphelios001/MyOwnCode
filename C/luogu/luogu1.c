#include<stdio.h>
#include<stdlib.h>
int main()
{
    int l;
    int m;  
    scanf("%d",&l);
    scanf("%d",&m);
    int *a=(int *)malloc(sizeof(int) * (l+1));
    a[0]=0;
    for(int i=1;i<=l;i++)
    {
        a[i]=1;
    }
    int left,right;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&left,&right);
        for(int j=left;j<=right;j++)
        {
            a[j]=-1;
        }
    }
    int count=0;
    for(int i=1;i<=l;i++)
    {
        if(a[i]>0)
        {
            count++;
        }
    }
    printf("%d",count+1);


}