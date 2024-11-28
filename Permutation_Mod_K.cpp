#include<bits/stdc++.h>
using namespace std;
#define int long long

bool dfs(int u,vector<vector<int>>& adj,vector<bool>& vis,vector<int>& ok)
{
    for(auto& v:adj[u])
    {
        if(!vis[v])
        {
            vis[v]=true;
            if(ok[v]==-1 || dfs(ok[v],adj,vis,ok))
            {
                ok[v]=u;
                return true;
            }
        }
    }
    return false;
}
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>>adj(n+1,vector<int>());
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if((j%k)!=(i%k))
            {
                adj[i].push_back(j);
            }
        }
    }
    vector<int>ok(n+1,-1);
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        vector<bool>vis(n+1,false);
        if(dfs(i,adj,vis,ok))ans++;
    }
    if(ans==n)
    {
        vector<int>P(n+1,-1);
        for(int j=1;j<=n;++j)
        {
            if(~ok[j])
            {
                P[ok[j]]=j;
            }
        }
        string str="";
        for(int i=1;i<=n;++i)
        {
            str+=to_string(P[i])+" ";
        }
        if(n>=1)str.pop_back();
        cout<<str<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
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
}