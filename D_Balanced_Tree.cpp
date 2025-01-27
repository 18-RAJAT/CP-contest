#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<vector<int>>g(n);
    vector<int>a(n),l(n),r(n);
    for(int i=0;i<n;++i)cin>>l[i]>>r[i];
    for(int i=0;i<n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0;i<n;++i)a[i]=l[i];
    int j=0,mini;
    while(j<1e2)
    {
        for(int i=0;i<n;++i)
        {
            mini=-1;
            for(auto& it:g[i])mini=max(mini,a[it]);
            if(mini<l[i])a[i]=l[i];
            else if(mini<=r[i])a[i]=mini;
            else a[i]=r[i];
        }
        j++;
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        ans+=a[i];
        for(auto& j:g[i])if(i<j)ans-=min(a[i],a[j]);
    }
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