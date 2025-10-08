#include<stdio.h>
int main()
{
    long long int x,n;
    scanf("%lld %lld",&x,&n);
    long long int ganran=1;
    for(int i=0;i<n;i++)
    {
        ganran=ganran+ganran*x;

    }
    printf("%d",ganran);
}