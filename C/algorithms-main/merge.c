#include <stdio.h>
#include <stdlib.h>

// 合并
void merge(int arr[], int tempArr[], int left, int mid, int right)
{
    // 标记左半区第一个未排序的元素

    // 标记右半区第一个未排序的元素

    // 临时数组元素的下标

    // 合并
   
    
          // 左半区第一个剩余元素更小
            
          // 右半区第一个剩余元素更小
            

    // 合并左半区剩余的元素
   

    // 合并右半区剩余的元素
    

    // 把临时数组中合并后的元素复制回原来的数组
    
}

// 归并排序
void msort(int arr[], int tempArr[], int left, int right)
{
    // 如果只有一个元素，那么不需要继续划分
    // 只有一个元素的区域，本生就是有序的，只需要被归并即可
    
    
        // 找中间点
        
        // 递归划分左半区
        
        // 递归划分右半区
        
        // 合并已经排序的部分
        
    
}

// 归并排序入口
void merge_sort(int arr[], int n)
{
    // 分配一个辅助数组

    // 调用实际的归并排序
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
