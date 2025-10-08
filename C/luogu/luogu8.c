#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int *arr = (int*)malloc(2000001 * sizeof(int));
    double a;
    int t;
    int temp;
    int max=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lf %d",&a,&t);
        for(int j=1;j<=t;j++)
        {
            temp = (int)(j * a);
            if(temp >max)
            {
                max=temp;
            }
            if(arr[temp]==0)
            {
                arr[temp]=1;
            }
            else
            {
                arr[temp]=0;
            }
        }
    }
    for(int i=1;i<=max;i++)
    {
        if(arr[i]==1)
        {
            printf("%d",i);
        }
    } 
    free(arr);
    return 0;
}