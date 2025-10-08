#include<stdio.h>
int main()
{
    int n;
    int k;
    scanf("%d %d",&n,&k);
    int count=0;
    int xi=0;
    while(n>0)
    {
        n=n-1;
        xi=xi+1;
        if(xi>=k)
        {
            xi=xi-k;
            n=n+1;
        }
        count++;    
    }
    printf("%d",count);
}
