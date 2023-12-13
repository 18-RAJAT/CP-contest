#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    if(is_sorted(a.begin(),a.end()))
    {
        cout<<1<<endl;
        return;
    }
    vector<vector<int>>dp(n,vector<int>(2));
    dp[0][0]=1;
    dp[0][1]=1;
    for(int i=1;i<n;++i)
    {
        if(a[i]%2==0)
        {
            dp[i][0]=dp[i-1][0]+dp[i-1][1];
            dp[i][1]=dp[i-1][0]+dp[i-1][1];
        }
        else
        {
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];
        }
    }
    int ans=dp[n-1][0];
    if(ans==1)
    {
        cout<<0<<endl;
        return;
    }
    cout<<ans%998244353<<endl;
}
signed main()
{
    sol();
    return 0;
}