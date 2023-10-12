#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    char dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>dp[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n/2;i++)
    {
        for(int j=i;j<n-i-1;j++)
        {
            char c=max({dp[i][j],dp[n-1-j][i],dp[n-1-i][n-1-j],dp[j][n-1-i]});
            ans+=(abs(c-dp[i][j])+abs(c-dp[n-1-j][i])+abs(c-dp[n-1-i][n-1-j])+abs(c-dp[j][n-1-i]));
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