#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,p,k;
    cin>>n>>p>>k;
    string s;
    cin>>s;
    int x,y;
    cin>>x>>y;
    int dp[n]={};
    for(int i=n-1;i>=0;--i)
    {
        if(s[i]=='0')
        {
            dp[i]+=1;
        }
        if(i+k<n)
        {
            dp[i]+=dp[i+k];
        }
    }
    int ans=INT_MAX;
    // for(int i=p-1;i<n;i+=k)
    // {
    //     ans=min(ans,dp[i]*(i-p+1));
    // }
    for(int i=0;i<=n-p;++i)
    {
        ans=min(ans,i*y+dp[i+p-1]*x);
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