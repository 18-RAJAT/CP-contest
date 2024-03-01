#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[31];
vector<int>coins={1,3,6,10,15};
void sol()
{
    int n;
    cin>>n;
    if(n<31)
    {
        cout<<dp[n]<<endl;
    }
    else
    {
        int ans=1e18;
        for(int i=0;i<31;++i)
        {
            int side=n-i;
            ans=min(ans,dp[i]+side/15+dp[side%15]);
        }
        cout<<ans<<endl;
    }
}
void chk()
{
    fill(dp,dp+31,1e18);
    dp[0]=0;
    for(int i=1;i<31;++i)
    {
        for(int j=0;j<5;++j)
        {
            if(i>=coins[j])
            {
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }
}
signed main()
{
    chk();
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}