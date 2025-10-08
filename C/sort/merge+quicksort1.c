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
void merge(int a[],int temp[],int left,int mid,int right)
{
    int lpos=left;
    int rpos=mid+1;
    int pos=left;
    while(lpos<=mid&&rpos<=right)
    {
        if(a[lpos]<a[rpos])
        {
            temp[pos++]=a[lpos++];
        }
        else
        {
            temp[pos++]=a[rpos++];
        }
    }
    while(lpos<=mid)
    {
        temp[pos++]=a[lpos++];
    }
    while(rpos<=right)
    {
        temp[pos++]=a[rpos++];
    }
    while(left<=right)
    {
        a[left]=temp[left];
        left++;
    }
}
void msort(int a[],int temp[],int left,int right)
{
    if(left<right)
    {
        int mid=left+(right-left)/2;
        msort(a,temp,left,mid);
        msort(a,temp,mid+1,right);
        merge(a,temp,left,mid,right);
    }
}
void mergesort(int a[],int n)
{
    int *temp=(int*)malloc(sizeof(int)*n);
    msort(a,temp,0,n-1);
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
    mergesort(a,n);
    printfarr(a,n);
    free(a);
}