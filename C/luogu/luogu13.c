#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int count=0;
    for(int i=1;i<n-1;i++)
    {   
        if(a[i] < a[i-1] && a[i] < a[i+1])
        {
            count++;
        }
        if(a[i-1] > a[i] && a[i+1] == a[i])
		{
			while(a[i] <= a[i+1])
			{
				i++;
			}
			if(a[i-1] < a[i])
			{
				count++;
			}
		}
    }    
    printf("%d",count);
}