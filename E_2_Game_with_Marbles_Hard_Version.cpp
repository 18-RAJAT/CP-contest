#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    vector<pair<int,int>>vp(n);
    for(int i=0;i<n;++i)
    {
        vp[i]=make_pair(a[i]+b[i],i);
    }
    sort(vp.begin(),vp.end());
    // reverse(vp.begin(),vp.end());
    int ans=0,cnt=0;
    for(int i=n-1;i>=0;--i)
    {
        // i%2==0?a[vp[i].second]=1:b[vp[i].second]=1;
        cnt%2==0?ans+=a[vp[i].second]-1:ans-=b[vp[i].second]-1;
        // cnt&1?a[vp[i].second]=1:b[vp[i].second]=1;
        cnt++;
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