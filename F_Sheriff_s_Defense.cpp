#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,c;
    cin>>n>>c;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<vector<int>>adj(n);
    for(int i=0;i<n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        assert(u>=0 && u<n && v>=0 && v<n);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<array<int,2>>MaxGold(n,{0,0});
    function<void(int,int)>Dfs=[&](int Camp,int NbgCamp)->void
    {
        MaxGold[Camp][1]=a[Camp];
        for(auto& it:adj[Camp])
        {
            if(it==NbgCamp)continue;
            Dfs(it,Camp);
            MaxGold[Camp][0]+=max(MaxGold[it][0],MaxGold[it][1]);
            MaxGold[Camp][1]+=max(MaxGold[it][0],MaxGold[it][1]-2*c);
        }
    };
    Dfs(0,-1);
    int ans=max(MaxGold[0][0],MaxGold[0][1]);
    cout<<ans<<endl;
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