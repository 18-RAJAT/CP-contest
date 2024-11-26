#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k,d;
    cin>>n>>k>>d;
    int dp[255][2];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<n;++i)
    {
        for(int j=1;j<=k;++j)
        {
            if(d<=j)dp[i+j][1]=(dp[i+j][1]+dp[i][0])%1000000007;
            else dp[i+j][0]=(dp[i+j][0]+dp[i][0])%1000000007;
            dp[i+j][1]=(dp[i+j][1]+dp[i][1])%1000000007;
        }
    }
    cout<<dp[n][1];
}
signed main()
{
    sol();
    return 0;
}