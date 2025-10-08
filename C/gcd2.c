#include<stdio.h>
int gcd(int a,int b)
{
    if(a<b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    return(a%b==0)?b:gcd(b,a%b);
}
int main()
{
    printf("%d",gcd(8,16));
}