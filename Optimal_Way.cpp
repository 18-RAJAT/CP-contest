#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int dp[n+1][2];
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    dp[0][0]=0;
    dp[0][1]=0;
    for(int i=1;i<=n;++i)
    {
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        dp[i][1]=a[i-1];
        for(int j=i-2;~j;--j)
        {
            dp[i][1]=max(dp[i][1],a[i-1]&a[j]+dp[j][0]);
        }
    }
    cout<<max(dp[n][0],dp[n][1])<<endl;
}
signed main()
{
    sol();
    return 0;
}