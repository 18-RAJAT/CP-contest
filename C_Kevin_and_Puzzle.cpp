#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mod=998244353;
void sol()
{
    int n;
    cin>>n;
    vector<int>dp(n+5,0),ndp(n+5,0),dp1(n+5,0),ndp1(n+5,0);
    for(int i=1;i<=n;++i)cin>>dp[i];
    if(n==1)
    {
        cout<<(dp[1]==0?2:1)<<endl;
        return;
    }
    if(dp[1]==0)
    {
        if(dp[2]==0)dp1[2]=ndp1[2]=1;
        (dp[2]==1)?dp1[2]=ndp[2]=1:dp1[2]=1;
    }
    else
    {
        if(dp[2]==1)ndp[2]=1;
    }
    for(int i=3;i<=n;++i)
    {
        if(dp[i]==dp[i-2]+1)ndp[i]=dp1[i-1];
        dp1[i]=(ndp1[i-1]+ndp[i-1])%Mod;
        if(dp[i]==dp[i-1])ndp1[i]=(ndp1[i-1]+ndp[i-1])%Mod;
    }
    cout<<(ndp[n]+ndp1[n]+dp1[n])%Mod<<endl;
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