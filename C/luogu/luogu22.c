#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *a=(int*)malloc(sizeof(int)*2147483647);
    int temp;
    for(int i=0;;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==0)
        {
            temp=i;
            break;
        }
    }
    for(int j=temp-1;j>=0;j--)
    {
        printf("%d",a[j]);
        if(j!=0)
        {
            printf(" ");
        }
    }
}