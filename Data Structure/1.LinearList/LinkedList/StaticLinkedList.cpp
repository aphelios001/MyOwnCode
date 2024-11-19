#include<iostream>
#define MaxSize 10	//静态链表的最大长度 
struct Node
{		//静态链表结构类型的定义 
	int data;	//存储数据元素  
	int next;		//下一个元素的数组下标 
};
typedef struct Node SLinkList [MaxSize];
SLinkList a;//这是个数组,大小是MaxSize

