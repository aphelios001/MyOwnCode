#include<iostream>
#include<limits.h>
#define MAX 10000
using namespace std;
struct Heap
{
	int* Element;
	int size;
	int capacity;

	Heap() :Element(new int[MAX]), size(0), capacity(MAX) 
	{
		Element[0] = INT_MAX;
	}
	
	bool insertElement(int x)
	{
		//插入的时候 上滤（向上调整）先找到位置，才插入元素
		int i;
		for (i = ++size; x > Element[i/2]; i /= 2)
		{
			Element[i] = Element[i/2];//如果比x小，就换下来
		}
		Element[i] = x;//找到位置i了，插入
		return true;
	}
	void deleteMax()
	{
		int parent, child;
		int Max, temp;
		Max = Element[1];
		temp = Element[size--];
		//删除的时候 下滤（向下调整）不是真正意义上删除，下面的循环是给最后一个元素找位置
		for (parent = 1; parent * 2 <= size; parent = child)
		{
			child = 2 * parent;//左孩子
			if ((child != size) && (Element[child] < Element[child + 1]))
			{
				child++;
			}
			if (Element[child] <= temp)
			{
				break;
			}
			else
			{
				Element[parent] = Element[child];
			}
		}
		Element[parent] = temp;
	}
	void Print()
	{
		for (int i = 1; i <= size; i++)
		{
			cout << Element[i] << ' ';
		}
		cout << endl;
	}
};

int main()
{
	Heap* MaxHeap = new Heap;
	MaxHeap->insertElement(3);
	MaxHeap->insertElement(4);
	MaxHeap->insertElement(6);
	MaxHeap->insertElement(1);
	MaxHeap->insertElement(2);

	MaxHeap->Print();
	return 0;
}