#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<int>dp(61,-1);
    dp[0]=0;
    for(int i=1;i<61;++i)
    {
        dp[i]=dp[i/2]+i%2;
    }
    vector<int>pref(n+1);
    for(int i=0;i<n;++i)
    {
        pref[i+1]=pref[i]+a[i];
    }
    map<int,int>mp;
    int ans=1e18;
    for(int i=0;i<=n;++i)
    {
        if(mp.count(pref[i]))
        {
            ans=min(ans,mp[pref[i]]+1);
        }
        mp[pref[i]]=i;
    }
    cout<<(ans==1e18?ans:-1)<<endl;
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