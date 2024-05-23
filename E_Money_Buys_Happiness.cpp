#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x;
    cin>>n>>x;
    vector<int>dp(50010,-1);
    dp[0]=0;
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        int c,h;
        cin>>c>>h;
        for(int j=ans;~j;--j)
        {
            if(c<=dp[j])dp[j+h]=max(dp[j+h],dp[j]-c),ans=max(ans,j+h);
        }
        for(int j=0;j<=ans;++j)
        {
            if(~dp[j])dp[j]+=x;
        }
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