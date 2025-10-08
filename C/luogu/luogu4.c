#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
    int a[13];
    int money = 0;
    a[0] = 0;
    for (int i = 1; i <= 12; i++)
    {
        scanf("%d", &a[i]);
    }
    int remain = 0;
    int save = 0;
    int temp = 0;
    for (int i = 1; i <= 12; i++)
    {
        money = remain + 300;//i月初拥有的钱
        remain = money - a[i];//i月末剩下的钱
        if (remain < 0)
        {
            printf("-%d", i);
            break;
        }
        if (remain >= 100)
        {
            save = save + (remain / 100) * 100;
            remain = remain - (remain / 100) * 100;
        }
        if (i == 12)
        {
            printf("%g", (float)remain + ((float)save * 1.2));
            break;
        }
    }
    return 0;




}