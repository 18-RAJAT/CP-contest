#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<vector<int>>adj(n);
    for(int i=0;i<n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int res=1;
    vector<int>vis(n);
    function<void(int,int)>dfs=[&](int node,int parent)
    {
        if(parent==-1)vis[node]=res++;
        else
        {
            int tmp=res-vis[parent];
            if(tmp==2)res+=2;
            else if(tmp&1 && tmp>=2)res++;
            vis[node]=res++;
        }
        for(int i=0;i<adj[node].size();++i)
        {
            if(adj[node][i]==parent)continue;
            dfs(adj[node][i],node);
        }
    };
    for(int i=0;i<n;++i)
    {
        if(adj[i].size()==1)
        {
            dfs(i,-1);
            break;
        }
    }
    if(n*2<res)
    {
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i<vis.size();++i)
    {
        cout<<vis[i]<<" ";
    }
    cout<<endl;
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