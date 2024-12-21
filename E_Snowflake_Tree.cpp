#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>deg(n+1,0);
    for(int i=1;i<=n;++i)deg[i]=adj[i].size();
    int Deg=0;
    for(int i=1;i<=n;++i)Deg=max(Deg,deg[i]);
    vector<int>f(Deg+2,0);
    for(int i=1;i<=n;++i)
    {
        int k=adj[i].size();
        if(k==0)continue;
        vector<int>nbg;
        nbg.reserve(k);
        for(auto&v:adj[i])
        {
            nbg.push_back(deg[v]);
        }
        sort(nbg.begin(),nbg.end(),[&](int a,int b){return a>b;});
        int sz=nbg.size();
        for(int j=0;j<sz;++j)
        {
            int d=nbg[j];
            int mxi=d-1;
            if(mxi>=1)f[mxi]=max(f[mxi],j+1);
        }
    }
    for(int y=Deg;y>=1;--y)
    {
        f[y]=max(f[y],f[y+1]);
    }
    int ans=0;
    for(int y=1;y<=Deg;++y)
    {
        int x=f[y];
        if(x>=1)
        {
            int sub=1+x+(x*y);
            ans=max(ans,sub);
        }
    }
    cout<<n-ans<<endl;
}
signed main()
{
    sol();
    return 0;
}