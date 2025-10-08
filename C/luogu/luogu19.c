#include<stdio.h>
int main()
{
    int x,n;
    scanf("%d %d",&x,&n);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(x!=6&&x!=7)
        {    
            sum=sum+250;
        }
        if(x==8)
        {
            x=1;
        }
        x++; 
    }
    printf("%d",sum);
}