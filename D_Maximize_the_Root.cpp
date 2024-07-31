#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>a;
vector<vector<int>>adj;
int dfs(int u)
{
    int check=(adj[u].empty()?a[u]:1e18);
    for(auto& it:adj[u])
    {
        check=min(check,dfs(it));
    }
    return (a[u]<check && u?(check+a[u])/2:check);
}
void sol()
{
    int n;
    cin>>n;
    a.resize(n),adj.clear(),adj.resize(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;++i)
    {
        int p;
        cin>>p;
        adj[--p].push_back(i);
    }
    cout<<a[0]+dfs(0)<<endl;
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