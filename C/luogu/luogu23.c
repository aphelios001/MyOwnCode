#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[100];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int count=0;
    int b[100]={0};
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
            {
                count++;
            }
        }
        b[i]=count;
        count=0;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",b[i]);
    }
}