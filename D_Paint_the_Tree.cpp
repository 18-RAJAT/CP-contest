#include<bits/stdc++.h>
using namespace std;
#define int long long

pair<int,int>init;
int further;
void dfs1(int i,int parent,int dist,vector<int>&visited,vector<vector<int>>& adj)
{
    visited[i]=dist;
    for(auto& it:adj[i])
    {
        if(it!=parent)dfs1(it,i,dist+1,visited,adj);
    }
}
void dfs2(int i,int parent,int dist,vector<vector<int>>& adj,vector<int>&visited)
{
    if(dist>=visited[i])
    {
        if(dist<init.first)init=make_pair(dist,i);
    }
    for(auto& it:adj[i])
    {
        if(it!=parent)dfs2(it,i,dist+1,adj,visited);
    }
}
void dfs3(int i,int parent,int dist,vector<vector<int>>& adj)
{
    further=max(dist,further);
    for(auto& it:adj[i])
    {
        if(it!=parent)dfs3(it,i,dist+1,adj);
    }
}
void sol()
{
    int n;
    cin>>n;
    vector<vector<int>>adj(n);
    int x,y;
    cin>>x>>y;
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    x--,y--;
    vector<int>visited(n,-1);
    dfs1(x,-1,0,visited,adj);
    init=make_pair(INT_MAX,INT_MAX);
    dfs2(y,-1,0,adj,visited);
    further=0;
    dfs3(init.second,-1,0,adj);
    cout<<(init.first+(n+1)*2-further)-4<<endl;
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