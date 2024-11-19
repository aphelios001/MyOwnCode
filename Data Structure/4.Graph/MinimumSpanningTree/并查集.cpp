#include<bits/stdc++.h>
using namespace std;
int n, m;
int p[10005];
void init()
{
	for (int i = 1; i <= n; i++)//初始化，一开始自己的爸爸等于自己
	{
		p[i] = i;
	}
}
int find(int x)//含路径压缩
{
	if (x == p[x])//如果一个元素的爸爸就是它自己
	{
		return x;//就直接返回它自身
	}
	else
	{
		p[x] = find(p[x]);//否则就接下去寻找，直到找到他的爸爸为止
	}
	return p[x];//返回它的爸爸的值
}
void merge(int x,int y)//合并的本质就是使x和y的爸爸变成同一个爸爸
{
	int a = find(x);//找x的爸爸
	int b = find(y);//找y的爸爸
	p[a] = b;//x的爸爸的爸爸=y的爸爸
}
int main()
{
	cin >> n >> m;
	init();
	for (int i = 1; i <= m; i++)
	{
		int z,x,y;
		cin >> z >> x >> y;
		
		if (z == 1)
		{
			merge(x, y);
		}
		else if(z == 2)
		{
			int a = find(x);//找x的爸爸
			int b = find(y);//找y的爸爸
			if (a == b)//爸爸相同代表在同一个集合里
			{
				cout << "Y"<<endl;
			}
			else
			{
				cout << "N" << endl;
			}
		}
	}
	return 0;
}
//problem url:https://www.luogu.com.cn/problem/P3367