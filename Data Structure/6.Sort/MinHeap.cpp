#include<iostream>
#include<limits.h>
#define MAX 10000
using namespace std;
struct Heap
{
	int* element;
	int size;
	int capacity;

	Heap() :element(new int[MAX]), size(0), capacity(MAX) 
	{
		element[0] = INT_MIN;
	}
	
	void MinHeapAllInsert(int a[],int n)
	{
		for (int i = 1; i <= n; i++)
		{
			element[++size] = a[i-1];
		}
		adjust();
	}
	void down(int i)
	{
		int parent, child;
		int temp = element[i];
		for (parent = i; 2 * parent <= size; parent = child)
		{
			child = 2 * parent;
			if ((child != size) && (element[child + 1] < element[child]))
			{
				child++;
			}
			if (element[child] >= temp)
			{
				break;
			}
			else
			{
				element[parent] = element[child];
			}
		}
		element[parent] = temp;
	}
	void adjust()
	{
		int i = size / 2;
		for (; i > 0; i--)
		{
			down(i);
		}
	}
	void Print()
	{
		for (int i = 1; i <= size; i++)
		{
			cout << element[i] << ' ';
		}
		cout << endl;
	}
};

int main()
{
	Heap* MinHeap = new Heap;
	int a[] = {3,4,6,1,2};
	MinHeap->MinHeapAllInsert(a, 5);
	MinHeap->Print();
	return 0;
}