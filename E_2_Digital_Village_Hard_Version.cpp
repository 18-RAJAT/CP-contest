#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=1e9+5;
const int INF_N=1e18+5;

class DSU
{
public:
    vector<int>parent,size,special;
    int count;
    vector<vector<int>>dp;

    DSU(int n)
    {
        parent.resize(n);
        size.resize(n,1);
        special.resize(n);
        dp.resize(n,vector<int>(2));
        iota(parent.begin(),parent.end(),0);
        count=n;
    }
    int GetParent(int i)
    {
        return (parent[i]==i)?i:(parent[i]=GetParent(parent[i]));
    }
    void Join(int u,int v,int w)
    {
        u=GetParent(u),v=GetParent(v);
        if(u==v) return;
        count--;
        if(size[u]<size[v]) swap(u,v);
        parent[v]=u;
        // size[u]+=size[v];
        // special[u]+=special[v];
        int ert=size[u]+size[v];
        vector<int>ndp(ert+1);
        for(int i=1;i<=ert;++i)
        {
            ndp[i]=INF_N;
            for(int j=max(0LL,i-size[v]);j<=min(i,size[u]);++j)
            {
                int ToDestination=i-j;
                ndp[i]=min(ndp[i],dp[u][j]+dp[v][ToDestination]+(j?0:w*special[u])+(ToDestination?0:w*special[v]));
            }
        }
        dp[u]=ndp;
        size[u]+=size[v];
        special[u]+=special[v];
    }
};
void sol()
{
    int n,m,w;
    cin>>n>>m>>w;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    vector<vector<pair<int,int>>>adj(n);
    vector<array<int,3>>edges(m);
    for(int i=0;i<m;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        --u,--v;
        edges[i]={w,u,v};
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    sort(edges.begin(),edges.end());
    DSU dsu(n);
    for(int i=0;i<n;++i) dsu.special[i]=a[i];
    for(vector<array<int,3>>::iterator it=edges.begin();it!=edges.end();++it)
    {
        dsu.Join((*it)[1],(*it)[2],(*it)[0]);
    }
    int p=dsu.GetParent(0);
    for(int i=1;i<=n;++i) cout<<dsu.dp[p][i]<<" ";
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