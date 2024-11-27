#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e5+5;
vector<int>g[N];
int n,col[N],arr[2];
void dfs(int v,int c)
{
    col[v]=c,arr[c]++;
    for(auto& u:g[v])
    {
        if(col[u]==-1)dfs(u,1-c);
    }
}
void sol()
{
    cin>>n;
    for(int i=0;i<n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    fill(col,col+n,-1);
    for(int i=0;i<n;++i)
    {
        if(col[i]==-1)
        {
            dfs(i,0);
        }
    }
    cout<<1ll*arr[0]*arr[1]-(n-1);
}
signed main()
{
    sol();
    return 0;
}