#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int len,temp,dist[N];
vector<int>g[N];
void dfs(int f,int u)
{
    for(auto v:g[u])
    {
        if(v==f) continue;
        dist[v]=dist[u]+1;
        if(dist[v]>len) len=dist[v],temp=v;
        dfs(u,v);
    }
}
int find(int x)
{
    len=0;
    temp=0;
    dist[x]=0;
    dfs(0,x);
    return temp;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int q=find(1);
    int w=find(q);
    vector<int>dis_q(n+1,0);
    vector<int>dis_w(n+1,0);
    function<void(int,int,vector<int>&)>dfs=[&](int fa,int u,vector<int>&dis)
    {
        for(auto v:g[u])
        {
            if(v==fa) continue;
            dis[v]=dis[u]+1;
            dfs(u,v,dis);
        }
    };
    dfs(q,q,dis_q);
    dfs(w,w,dis_w);
    vector<int>mn(n+1,0);
    for(int i=1;i<=n;++i) mn[i]=max(dis_q[i],dis_w[i]);
    sort(mn.begin()+1,mn.end());
    int cur=1;
    for(int i=1;i<=n;++i)
    {
        int val=0;
        while(cur<=n && mn[cur]<i) cur+=1;
        cout<<min(cur,n)<<" \n"[i==n];
    }
    return 0;
}