#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<array<int,2>>dp(n);
    dp.resize(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>dp[i][0];
        dp[i][1]=i;
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        cin>>dp[i][1];
        if(dp[i][0]<dp[i][1])
        {
            swap(dp[i][1],dp[i][0]);
        }
        ans+=abs(dp[i][1]-dp[i][0]);
    }
    int mn=dp[1][0];
    int mx=dp[1][1];
    for(int i=2;i<=n;++i)
    {
        mn=min(mn,dp[i][0]);
        mx=max(mx,dp[i][1]);
    }
    cout<<ans+max(2LL*(mx-mn),0LL)<<endl;
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