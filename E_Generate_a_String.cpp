#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x,y;
    cin>>n>>x>>y;
    int dp[n+1]={};
    for(int i=1;i<=n;++i)
    {
        dp[i]=x+dp[i-1];
        int precompute=dp[0]+x*abs(i)+y;
        for(int j=1;j<i;++j)
        {
            int state=dp[j]+x*abs(j*2-i)+y;
            precompute=min(precompute,state);
        }
        dp[i]=min(dp[i],precompute);
    }
    cout<<dp[n];
}
signed main()
{
    sol();
    return 0;
}