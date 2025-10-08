#include<stdio.h>
#include<math.h>
int isprime(int n)
{
    int j;
    if(n<=1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }
    for(j=2;j<=sqrt(n);j++)
        {
            if(n%j==0)
            {
                return 0;//不是质数
            }
        }
        return 1;//是质数
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=4;i<=n;i+=2)
    {
        for(int j=2;;j++)
        {
            if(isprime(j)==1&&isprime(i-j)==1)
            {
                printf("%d=%d+%d\n",i,j,i-j);
                break;
            }
        }   
    }   
}