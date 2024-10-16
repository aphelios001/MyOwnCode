#include<bits/stdc++.h>
using namespace std;
int n, m;
int u, v, w;
int g[105][105];
void floyd()
{
	//floyd算法
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	//初始化邻接矩阵
	memset(g, 0x3f, sizeof g);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				g[i][j] = 0;
			}
		}
	}
	//添加边
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		if (g[u][v] > w)//防止有重边，有重边就选小的
		{
			g[u][v] = g[v][u] = w;
		}
	}

	floyd();

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << g[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
//problem url:https://www.luogu.com.cn/problem/B3647#submit