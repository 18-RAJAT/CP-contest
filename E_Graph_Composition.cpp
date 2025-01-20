#include<bits/stdc++.h>
using namespace std;
#define int long long

//Rajat joshi template
struct DSU
{
    vector<int>par,rank;
    DSU(int n)
    {
        par.resize(n+1);
        rank.resize(n+1,1);
        for(int i=0;i<=n;++i)par[i]=i;
    }
    int find(int x)
    {
        if(par[x]!=x)par[x]=find(par[x]);
        return par[x];
    }
    void unite(int x,int y)
    {
        int px=find(x),py=find(y);
        if(px==py)return;
        if(rank[px]<rank[py])par[px]=py;
        else
        {
            par[py]=px;
            if(rank[px]==rank[py])++rank[px];
        }
    }
};
void sol()
{
    int n,m1,m2;
    cin>>n>>m1>>m2;
    vector<pair<int,int>>vp(m1);
    for(auto& it:vp)cin>>it.first>>it.second;
    DSU g(n);
    for(int i=0;i<m2;++i)
    {
        int u,v;
        cin>>u>>v;
        g.unite(u,v);
    }
    vector<int>ar(n+1);
    for(int i=1;i<=n;++i)ar[i]=g.find(i);
    DSU ds(n);
    int cnt=0;
    for(auto& it:vp)
    {
        int u=it.first,v=it.second;
        if(ar[u]==ar[v])ds.unite(u,v);
        else cnt++;
    }
    vector<pair<int,int>>p;
    for(int i=1;i<=n;++i)p.push_back({ar[i],ds.find(i)});
    sort(p.begin(),p.end());
    int tot=0,cur=-1,pr=-1,res=0;
    for(auto& it:p)
    {
        int c=it.first,p=it.second;
        if(c!=cur)
        {
            if(~cur)tot+=res-1;
            cur=c,pr=p,res=1;
        }
        else
        {
            if(p!=pr)res++,pr=p;
        }
    }
    if(~cur)tot+=res-1;

    cout<<cnt+tot<<endl;
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