#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int dp[n+1],ndp[n+1],ans[n+1];
    fill(dp,dp+n+1,0),fill(ndp,ndp+n+1,0),fill(ans,ans+n+1,0);
    int sum=0,i=k;
    dp[0]=1;
    while((sum+=i++)<=n)
    {
        for(int j=sum;j<=n;++j)ndp[j]=(dp[j-(i-1)]+ndp[j-(i-1)])%998244353;
        for(int j=0;j<=n;++j)ans[j]=(ndp[j]+ans[j])%998244353;
        copy(ndp,ndp+n+1,dp),fill(ndp,ndp+n+1,0);
    }
    for(int i=1;i<=n;++i)cout<<ans[i]<<" ";cout<<endl;
}
signed main()
{
    sol();
    return 0;
}