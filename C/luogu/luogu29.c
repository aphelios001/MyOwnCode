#include<stdio.h>
int main()
{
    int h1,h2,m1,m2,s1,s2;
    int S1,S2;
    int time;
    int a;
    scanf("%d:%d:%d",&h1,&m1,&s1);
    scanf("%d:%d:%d",&h2,&m2,&s2);
    scanf("%d",&a);
    S1=h1*60*60+m1*60+s1;
    S2=h2*60*60+m2*60+s2;
    time =S2-S1;
    printf("%ld",time*a);
}