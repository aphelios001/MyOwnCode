#include<bits/stdc++.h>
using namespace std;
int n, m;
int x, y, z;
int p[5005];
int ans = 0;
int cnt = 0;//统计已添加的边数
struct Edge 
{
	int begin;
	int end;
	int weight;
}e[200005];
bool cmp(Edge a, Edge b)
{
	return a.weight < b.weight;
}
int find(int x)//查找祖先
{
	if (p[x] == x)
	{
		return x;
	}
	else
	{
		p[x] = find(p[x]);
	}
	return p[x];
}
void kruskal()
{
	for (int i = 1; i <= n; i++)//初始化每一个顶点的祖先
	{
		p[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		int a = find(e[i].begin);//查找祖先
		int b = find(e[i].end);
		if (a != b)
		{
			cnt++;//统计边数
			p[a] = b;//合并
			ans += e[i].weight;
		}
	}

}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y >> z;
		e[i].begin = x;
		e[i].end = y;
		e[i].weight = z;
	}
	sort(e + 1, e + 1 + m,cmp);
	kruskal();
	if(cnt == n-1)//n个顶点的最小生成树必须要有n-1条边
	{
		cout << ans<<endl;
	}
	else//否则无法生成
	{
		cout << "orz" << endl;
	}
	return 0;
}
//problem url:https://www.luogu.com.cn/problem/P3366