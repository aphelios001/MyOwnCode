#include<stdio.h>
int gcd(int a,int b)
{
    if(a<b)
    {
        int temp=b;
        b=a;
        a=temp;
    }
    return(a%b==0)?b:gcd(b,a%b);
//相当于
    if (b == 0) 
    {
        return a;
    }
    else if(a%b==0)
    {
        return b;
    }
    else
    {
        return gcd(b,a%b);
    }
}