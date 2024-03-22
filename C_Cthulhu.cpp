#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> adj[200005];
void sol()
{
    int n,m;
    cin>>n>>m;
    function<void(vector<int>[],int root,bool vis[])> dfs=[&](vector<int> adj[],int root,bool vis[])
    {
        vis[root]=true;
        for(int i=0;i<adj[root].size();++i)
        {
            if(!vis[adj[root][i]])
            {
                dfs(adj,adj[root][i],vis);
            }
        }
    };
    for(int i=0;i<m;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n!=m)
    {
        cout<<"NO";
        return;
    }
    int root=1;
    bool vis[n+1]={false};
    dfs(adj,root,vis);
    for(int i=1;i<=n;++i)
    {
        if(!vis[i])
        {
            cout<<"NO";
            return;
        }
    }
    cout<<"FHTAGN!";
}
signed main()
{
    sol();
    return 0;
}