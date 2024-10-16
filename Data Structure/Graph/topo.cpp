#include<bits/stdc++.h>
using namespace std;
int n;
bool e[10005][10005];//邻接矩阵存图，也可以用邻接表
int ind[10005],t[10005],ans[10005],res=0;//ind为入度，t为点i的初始值，ans为点i更新后的值，res为结果
queue<int>q;
void topo()//拓扑排序
{
    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0)
        {
            q.push(i);
            ans[i]=t[i];
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=1;v<=n;v++)
        {
            if(e[u][v]==true)
            {
                ind[v]--;
                if(ind[v]==0)
                {
                    q.push(v);
                }
                ans[v]=max(ans[v],ans[u]+t[v]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        res=max(res,ans[i]);
    }
}   
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        t[a]=b;
        while(c!=0)
        {
            ind[a]++;
            e[c][a]=true;
            cin>>c;
        }    
    }
    topo();
    cout<<res<<endl;
    return 0;   
}
//problem url:https://www.luogu.com.cn/problem/P1113 //topo排序模板