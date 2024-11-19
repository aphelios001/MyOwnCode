//朴素版Dijkstra （稠密图）
#include<bits/stdc++.h>
using namespace std;
int n,m,s;
int g[10005][10005];
bool vis[10005];
int dis[10005];
int inf=0x3f3f3f3f;
void dijkstra(int S)
{
    dis[S]=0;
    for(int i=1;i<=n;i++)
    {
        int temp=inf;
        int index=-1;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&(index==-1||temp>dis[j]))
            {
                temp=dis[j];
                index=j;
            }
        }
        if(index==-1)
        {
            return;
        }
        vis[index]=true;
        for(int j=1;j<=n;j++)
        {
            dis[j]=min(dis[j],dis[index]+g[index][j]);
        }
    }
}
int main()
{
    cin>>n>>m>>s;
    memset(g,0x3f,sizeof g);
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        if(g[u][v]>w)
        {
            g[u][v]=w;
        }
    }
    dijkstra(s);
    for(int i=1;i<=n;i++)
    {
        if(dis[i]!=inf)
        {
            cout<<dis[i]<<' ';
        }
        else if(dis[i]==inf)
        {
            cout<<INT_MAX<<' ';
        }
    }
    return 0;
}
//problem url:https://www.luogu.com.cn/problem/P3371 会出现MLE
