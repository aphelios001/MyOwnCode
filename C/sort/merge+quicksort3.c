#include<stdio.h>
#include<stdlib.h>
int partition(int a[],int low,int high)
{
    int pivot=a[low];
    while(low<high)
    {
        while(low<high&&a[high]>=pivot)
        {
            --high;
        }
        a[low]=a[high];
        while(low<high&&a[low]<=pivot)
        {
            ++low;
        }
        a[high]=a[low];
    }
    a[low]=pivot;
    return low;
}
void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int ploc=partition(a,low,high);
        quicksort(a,low,ploc-1);
        quicksort(a,ploc+1,high);
    }
}
void print(int a[])
{
    for(int i=0;i<5;i++)
    {
        printf(" %d",a[i]);
    }
    printf("\n");
}
int merge(int a[],int t[],int left,int mid,int right)
{
    int lpos=left;
    int rpos=mid+1;
    int pos=left;
    while(lpos<=mid&&rpos<=right)
    {
        if(a[lpos]<a[rpos])
        {
            t[pos++]=a[lpos++];
        }
        else
        {
            t[pos++]=a[rpos++];
        }
    }
    while(lpos<=mid)
    {
        t[pos++]=a[lpos++];
    }
    while(rpos<=right)
    {
        t[pos++]=a[rpos++];
    }
    while(left<=right)
    {
        a[left]=t[left];
        left++;
    }

}
void msort(int a[],int t[],int left,int right)
{
    if(left<right)
    {
        int mid=left+(right-left)/2;
        msort(a,t,left,mid);
        msort(a,t,mid+1,right);
        merge(a,t,left,mid,right);
    }
}
void mergesort(int a[],int n)
{
    int*t=(int*)malloc(sizeof(int)*n);
    msort(a,t,0,n-1);
}
int main()
{
    int a[5]={1,4,7,2,5};
    print(a);
    //quicksort(a,0,4);
    mergesort(a,5);
    print(a);
}