#include<stdio.h>
#include<stdlib.h>
void printfarr(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
        if(i<n-1)
        {
            printf(" ");
        }
    }
    printf("\n");
}
void merge(int a[],int temparr[],int left,int mid,int right)
{
    int l_pos=left;
    int r_pos=mid+1;
    int pos=left;
    while(l_pos<=mid&&r_pos<=right)
    {
        if(a[l_pos]<a[r_pos])
        {
            temparr[pos++]=a[l_pos++];
        }
        else
        {
            temparr[pos++]=a[r_pos++];
        }
    }
    while(l_pos<=mid)
    {
        temparr[pos++]=a[l_pos++];
    }
    while(r_pos<=right)
    {
        temparr[pos++]=a[r_pos++];
    }
    while(left<=right)
    {
        a[left]=temparr[left];
        left++;
    }
}
void msort(int a[],int temparr[],int left,int right)
{
    if(left<right)
    {
        int mid = left+(right-left)/2;
        msort(a,temparr,left,mid);
        msort(a,temparr,mid+1,right);
        merge(a,temparr,left,mid,right);
    }
}
void mergesort(int a[],int n)
{
    int* temparr=(int*)malloc(sizeof(int)*n);
    msort(a,temparr,0,n-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    int *a=(int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printfarr(a,n);
    mergesort(a,n);
    printfarr(a,n);
    free(a);
}