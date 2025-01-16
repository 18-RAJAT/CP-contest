#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,l,a;
    cin>>n>>l>>a;
    vector<pair<int,int>>vp;
    for(int i=0;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        vp.emplace_back(x,y);
    }
    sort(vp.begin(),vp.end());
    int ans=0,res=0;
    for(int i=0;i<n;++i)
    {
        ans+=(vp[i].first-res)/a,res=vp[i].first+vp[i].second;
        if(res>l)break;
    }
    ans+=(l-res)/a;
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}