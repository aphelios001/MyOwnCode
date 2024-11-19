//堆优化版Dijkstra （稀疏图）
#include<bits/stdc++.h>
#define maxn 100005
#define maxm 500005
#define PII pair<int,int>
using namespace std;
int n,m,s,cnt;
bool vis[maxn];
int dis[maxn];
int head[maxn];
int inf=0x3f3f3f3f;
struct edge
{
    int v;
    int w;
    int next;
}e[maxm];
void add(int u,int v,int w)
{
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt++;

}
void dijkstra(int S)
{
    dis[S]=0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,S});
    while(!heap.empty())
    {
        auto t=heap.top();
        heap.pop();
        int u=t.second;
        if(vis[u])
        {
            continue;
        }
        vis[u]=true;
        for(int i=head[u];i!=-1;i=e[i].next)
        {
            int v=e[i].v;   
            if(dis[v]>dis[u]+e[i].w)
            {
                dis[v]=dis[u]+e[i].w;
                heap.push({dis[v],v});
            }
        }
    }
}
int main()
{
    cin>>n>>m>>s;
    memset(head,-1,sizeof head);
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
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
//problem url:https://www.luogu.com.cn/problem/P4779