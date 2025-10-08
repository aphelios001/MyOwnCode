#include<stdio.h>
int main()
{
    long long int s,x;
    scanf("%lld %lld",&s,&x);
    double d=0;
    double i=7;
    double temp=0;
    while(1)
    {
        if(d>=s-x&&d<=s+x)
        {
            break;
        }   
        d=d+i;
        i=i*0.98;
        temp=i;
    }
    if(d+temp*0.98>=s+x) 
    {
        printf("n");
    }
    else
    {
        printf("y");
    }
}