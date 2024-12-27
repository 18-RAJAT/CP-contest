#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,p;
    cin>>n>>p;
    vector<pair<int,int>>vp(n);
    for(int i=0;i<n;++i) cin>>vp[i].second;
    for(int i=0;i<n;++i) cin>>vp[i].first;
    sort(vp.begin(),vp.end());
    int last=n-1,ans=p;
    for(int i=0;i<vp.size();++i)
    {
        if(p<vp[i].first) break;
        int minimum_cost=min(last,vp[i].second);
        last-=minimum_cost;
        ans+=minimum_cost*vp[i].first;
    }
    cout<<p*last+ans<<endl;
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