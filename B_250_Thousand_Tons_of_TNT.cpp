#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<int> pref(n+1);
    for(int i=0;i<n;++i)
    {
        pref[i+1]=pref[i]+a[i];
    }
    int ans=0;
    vector<int> fact;
    for(int k=1;k<=n;++k)
    {
        if(n%k) continue;
        int mx=-1e18,mn=1e18;
        for(int i=k;i<=n;i+=k)
        {
            mx=max(mx,pref[i]-pref[i-k]);
            mn=min(mn,pref[i]-pref[i-k]);
        }
        ans=max(ans,abs(mx-mn));
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