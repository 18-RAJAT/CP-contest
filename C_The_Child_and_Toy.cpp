#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    vector<pair<int,int>>vp;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        vp.push_back({a[i],i});
    }
    int ans=0;
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        ans+=min(a[x-1],a[y-1]);
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}