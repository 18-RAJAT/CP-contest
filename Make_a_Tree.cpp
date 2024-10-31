#include<bits/stdc++.h>
using namespace std;
#define int long long
void assign(int n,vector<vector<pair<int,int>>>&adj,vector<int>&edgeColors,int &deg)
{
    deg=0;
    for(int i=1;i<=n;++i)
    {
        deg=max(deg,(int)adj[i].size());
    }
    queue<int>q;
    vector<int>parent(n+1,-1);
    vector<int>col(n+1,1);
    q.push(1);
    parent[1]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        int color=1;
        for(auto& it:adj[u])
        {
            int v=it.first;
            int s=it.second;
            if(v==parent[u]) continue;
            while(color==col[u]) color++;
            if(color>deg) color=1;
            edgeColors[s]=color;
            col[v]=color;
            parent[v]=u;
            q.push(v);
            color++;
            if(color>deg)color=1;
        }
    }
}
void sol()
{
    int n;
    cin>>n;
    vector<pair<int,int>>edges(n-1);
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        edges[i]={u,v};
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
    vector<int>cols(n-1,0);
    int deg;
    assign(n,adj,cols,deg);
    vector<vector<int>>col(deg+1,vector<int>());
    for(int i=0;i<n-1;i++)
    {
        int x=cols[i];
        col[x].push_back(i);
    }
    cout<<deg<<endl;
    for(int i=1;i<=deg;++i)
    {
        vector<int>c(n+1,0);
        for(auto& it:col[i])
        {
            int u=edges[it].first;
            int v=edges[it].second;
            c[u]=c[v]=i;
        }
        for(int j=1;j<=n;++j)
        {
            if(j>=2) cout<<" ";
            cout<<c[j];
        }
        cout<<endl;
    }
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}