#include<bits/stdc++.h>
using namespace std;
#define int long long
int vis=0;
void dfs(int i,vector<vector<pair<int,int>>>&adj,int &ans)
{
    for(auto& it:adj[i])
    {
        if(vis+it.second>vis)
        {
            vis+=it.second;
            // ans+=vis;
        }
        else
        {
            // vis=it.second;
            ans+=vis;
        }
        dfs(it.first,adj,ans);
    }
    // vis=0;
}
signed main()
{
    int n;
    cin>>n;
    vector<vector<pair<int,int>>>par(n);
    par.resize(n+1);

    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        // par[x].push_back({i,1});
        while(x--)
        {
            int u,v;
            cin>>u>>v;
            par[i].push_back({u,v});//{node,weight}
        }
    }
    int ans=0;
    // for(int i=1;i<=n;++i)
    // {
    //     vis=0;
    //     dfs(i,par[i],ans);
    // }
    dfs(1,par,ans);
    cout<<ans<<endl;
    return 0;

    assert(vis==0 && ans<=1e18);
}