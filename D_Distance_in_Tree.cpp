#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[50005][505];
int n,k,ans;
vector<int>adj[50005];

void dfs(int node,int parent)
{
    dp[node][0]=1;
    for(vector<int>::iterator it=adj[node].begin();it!=adj[node].end();++it)
    {
        if(*it==parent)continue;
        dfs(*it,node);
        for(int i=1;i<=k;++i)
        {
            ans+=dp[*it][i-1]*dp[node][k-i];
        }
        for(int i=1;i<=k;++i)
        {
            dp[node][i]+=dp[*it][i-1];
        }
    }
}
void sol()
{
    cin>>n>>k;
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}