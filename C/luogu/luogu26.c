#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int*a=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int count=0;
    int max=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i-1])
        {
            count++;
            if(count>max)
            {
                max=count;
            }
        }
        else
        {
            count=0;
        }
    }
    printf("%d",max+1);
}   