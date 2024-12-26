#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    vector<pair<int,int>>vp(n);
    for(int i=0;i<n;++i)cin>>a[i],vp[i]={a[i],i};
    sort(vp.begin(),vp.end(),[&](pair<int,int>& x,pair<int,int>& y)
    {
        return y.first<x.first;
    });
    for(int i=0;i<n;++i)b[vp[i].second]=i+1;
    int ans=0;
    for(int i=0;i<n-1;++i)
    {
        if(abs(b[i]-b[i+1])==1)ans++;
    }
    // cout<<n<<" "<<ans%10;
    int tot=n-ans;
    cout<<tot<<endl;
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