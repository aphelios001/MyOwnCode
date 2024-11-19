#include<bits/stdc++.h>
using namespace std;
int n, m;
int g[5005][5005];
int dist[5005];
int INF = 0x3f3f3f3f; 
int ans = 0;
bool st[5005];
void prim()
{
	st[1] = true;
	dist[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		dist[i] = min(dist[i], g[1][i]);
	}
	for (int i = 2; i <= n; i++)
	{
		int temp = INF;
		int index = -1;
		for (int j = 2; j <= n; j++)
		{
			if (!st[j] && dist[j]<temp)
			{
				temp=dist[j];
				index = j;
			}
		}
		if (index == -1)
		{
			ans = INF;
			return;
		}
		st[index] = true;
		ans += dist[index];
		for (int j = 2; j <= n; j++)
		{
			dist[j] = min(dist[j], g[index][j]);
		}
	}
}
int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		for (int j = 1; j <= n; j++)
		{
			g[i][j] = INF;
		}
		dist[i] = INF;
	}
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		if (g[x][y] > z)
		{
			g[x][y] = g[y][x] = z;
		}
	}
	prim();
	if (ans == INF)
	{
		cout << "orz" << endl;
	}
	else
	{
		cout << ans << endl;
	}
	return 0;

}
//problem url:https://www.luogu.com.cn/problem/P3366