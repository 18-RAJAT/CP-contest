#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>dp(m+2,0);
    for(int i=0;i<n;++i)
    {
        int l,r;
        cin>>l>>r;
        dp[r]=max(dp[r],l);
    }
    for(int i=1;i<=m;++i)dp[i]=max(dp[i],dp[i-1]);
    int ans=0;
    for(int i=1;i<=m;++i)
    {
        if(i>=dp[i])ans+=i-dp[i];
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}