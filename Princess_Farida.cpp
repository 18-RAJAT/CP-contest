#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol(int t)
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    if(n==0)
    {
        cout<<"Case "<<t<<": 0"<<endl;
        return;
    }
    vector<int>dp(n+1,0);
    dp[1]=a[0];
    for(int i=2;i<=n;++i)
    {
        dp[i]=max(dp[i-1],dp[i-2]+a[i-1]);
    }
    cout<<"Case "<<t<<": "<<dp[n]<<endl;
}
signed main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;++i)sol(i);
    return 0;
}