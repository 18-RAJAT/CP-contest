#include<bits/stdc++.h>
using namespace std;
#define int long long
void dfs(int u,vector<vector<int>>&adj,vector<int>&vis)
{
    vis[u]=1;
    for(auto v:adj[u])
    {
        if(!vis[v])
        {
            dfs(v,adj,vis);
        }
    }
}
void sol()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;++i)
    {
        cin>>ar[i];
        ar[i]--;
    }
    vector<vector<int>>adj(n);
    for(int i=0;i<n;++i)
    {
        adj[i].push_back(ar[i]);
        adj[ar[i]].push_back(i);
    }
    vector<int>vis(n,0);
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(!vis[i])
        {
            dfs(i,adj,vis);
            ans++;
        }
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}