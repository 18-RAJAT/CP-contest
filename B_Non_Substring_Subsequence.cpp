#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    char x;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a[i]=x-'0';
    }
    int dp[2];
    memset(dp,0,sizeof(dp));
    int dp1[2];
    for(int i=1;i<=n;i++)
    {
        // dp1[0]=dp[0];
        // dp1[1]=dp[1];
        // if(a[i]==0)
        // {
        //     dp[0]=dp1[0];
        //     dp[1]=dp1[1];
        // }
        // else
        // {
        //     dp[0]=dp1[0]+1;
        //     dp[1]=max(dp1[1],dp1[0])+1;
        // }
        if(dp[a[i]]==0) dp[a[i]]=i;
        dp1[a[i]]=i;
        // else
        // {
        //     // dp[a[i]]=max(dp[a[i]],i);
        //     dp1[a[i]]=i;
        // }
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        // if(dp[1]>=l && dp[1]<=r)
        if(dp[a[l]]<l || dp1[a[r]]>r)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}