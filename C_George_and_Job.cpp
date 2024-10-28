#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[5005][5005];
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    int prefix[n+1];
    prefix[0]=0;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        prefix[i+1]=prefix[i]+a[i];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=k;++j)
        {
            dp[i][j]=dp[i-1][j];
            if(i-m>=0)dp[i][j]=max(dp[i][j],dp[i-m][j-1]+prefix[i]-prefix[i-m]);
        }
    }
    cout<<dp[n][k]<<endl;
}
signed main()
{
    sol();
    return 0;
}