#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
#define maxm 500005
struct edge
{
    int v;
    int w;
    int next;
}edge[maxm];
int head[maxn],cnt=1;
void add(int u,int v,int w)
{
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt++;    
}
int main()
{
    memset(head,-1,sizeof head);
}