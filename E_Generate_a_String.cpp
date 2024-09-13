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
        dp[i]=min(dp[i-1]+x,(i&1?x:0)+dp[(i+1)/2]+y);
    }
    cout<<dp[n];
}
signed main()
{
    sol();
    return 0;
}