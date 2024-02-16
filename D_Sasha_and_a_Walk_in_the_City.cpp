#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans=0;
void sol()
{
    int n;
    cin>>n;
    vector<vector<int>>adj;
    function<int(int,int)>dfs=[&](int u,int p)->int
    {
        int sum=1;
        for(auto& v:adj[u])
        {
            if(v==p)
            {
                continue;
            }
            int call=dfs(v,u);
            ans=(ans+call+998244352)%998244353;
            sum=(sum*call)%998244353;
        }
        sum=(sum+1)%998244353;
        return sum%998244353;
    };
    ans=0;
    adj.assign(n,vector<int>());
    for(int i=0;i<n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int tmp=dfs(0,-1)%998244353;
    cout<<(ans+tmp)%998244353<<endl;
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