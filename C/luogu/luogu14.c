#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int r=n*n;
    int t,flag=0,count=0;
    while(r)
    {
        scanf("%d",&t);
        r = r-t;
        for(int i=0;i<t;i++)
        {
            printf("%d",flag);
            count++;
            if (count==n)
            {
                count=0;
                printf("\n");
            }
              
        }
        flag=!flag;
        
    }
}