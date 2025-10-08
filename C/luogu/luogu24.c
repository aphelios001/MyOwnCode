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
}
int main()
{
    int a,b,c,d;
    scanf("%d/%d",&a,&b);
    scanf("%d/%d",&c,&d);
    int e,f;
    int Gcd;
    e=a*c;
    f=b*d;
    Gcd = gcd(e,f);
    e=e/Gcd;
    f=f/Gcd;
    printf("%d %d\n",f,e);

}