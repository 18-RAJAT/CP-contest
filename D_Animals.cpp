#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<int>dp(n+1);
    for(int i=0;i<n;++i)
    {
        dp[i+1]=dp[i]+a[i];
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(dp[n]-dp[i]<=x)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    sol();
    return 0;
}