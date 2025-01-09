#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i)cin>>a[i];
    vector<int>f(n+1,-1),l(n+1,-1);
    for(int i=1;i<=n;++i)
    {
        if(f[a[i]]==-1)f[a[i]]=i;
        l[a[i]]=i;
    }
    vector<pair<int,int>>v;
    for(int i=1;i<=n;++i)
    {
        if(l[i]>f[i])v.push_back({f[i],l[i]});
    }
    sort(v.begin(),v.end());
    vector<pair<int,int>>m;
    for(int i=0;i<v.size();++i)
    {
        int x=v[i].first,y=v[i].second;
        if(m.empty() || x>m.back().second)m.push_back({x,y});
        else m.back().second=max(m.back().second,y);
    }
    vector<int>p(n+1,0),c(n+1,0);
    for(int i=1;i<=n;++i)if(f[a[i]]==i)c[i]=1;
    for(int i=1;i<=n;++i)p[i]=p[i-1]+c[i];
    int ans=0;
    for(int i=0;i<m.size();++i)ans+=(p[m[i].second]-p[m[i].first-1]);
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