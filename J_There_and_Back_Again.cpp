#include<bits/stdc++.h>
using namespace std;
#define int long long
bitset<100001>vis;
vector<vector<pair<int,int>>>g;
int n,m;
int bfs(int src,int dest)
{
    queue<pair<int,int>>q;
    q.push({src,0});
    vis.reset();
    vis[src]=1;
    while(!q.empty())
    {
        int u=q.front().first;
        int d=q.front().second;
        q.pop();
        if(u==dest)
        {
            return d;
        }
        for(int i=0;i<g[u].size();++i)
        {
            int v=g[u][i].first;
            int w=g[u][i].second;
            if(!vis[v])
            {
                vis[v]=1;
                q.push({v,d+w});
            }
        }
    }
    return -1;
}
void sol()
{
    cin>>n>>m;
    if(n%2==0 && m%2!=0)
    {
        cout<<-1<<endl;
        return;
    }
    g.clear();
    g.resize(n+1);
    for(int i=0;i<m;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int ans=1e18;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<g[i].size();++j)
        {
            int v=g[i][j].first;
            int w=g[i][j].second;
            int d1=bfs(i,v);
            int d2=bfs(v,i);
            if(d1!=-1 && d2!=-1)
            {
                ans=min(ans,d1+d2+w);
            }
        }
    }
    cout<<2*ans<<endl;
}
signed main()
{
    sol();
    return 0;
}