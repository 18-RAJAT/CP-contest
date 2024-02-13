#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int x,y,l;
    vector<pair<int,int>>v[n+1];
    for(int i=0;i<n-1;++i)
    {
        cin>>x>>y>>l;
        v[x].push_back({y,l});
        v[y].push_back({x,l});
    }
    vector<int>dist(n+1,0);
    vector<int>subtree(n+1,0);
    function<void(int,int)>dfs=[&](int u,int p)
    {
        subtree[u]=1;
        for(auto& x:v[u])
        {
            if(x.first==p)
            {
                continue;
            }
            dist[x.first]=dist[u]+x.second;
            dfs(x.first,u);
            subtree[u]+=subtree[x.first];
        }
    };
    dfs(1,0);
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        ans+=dist[i];
    }
    int minimum=LLONG_MAX;
    for(int i=1;i<=n;++i)
    {
        minimum=min(minimum,min(ans-dist[i]+subtree[i]*dist[i],1LL*ans));
    }
    cout<<minimum<<endl;
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