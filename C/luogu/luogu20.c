#include<stdio.h>
int main()
{
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int min1,min2;
    min1=a*60+b;
    min2=c*60+d;
    int min3;
    min3=min2-min1;
    int e,f;
    e=min3/60;
    f=min3%60;
    printf("%d %d",e,f);    
    
}