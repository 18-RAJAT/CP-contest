#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1000000007;
int add(int x,int y,int mod)
{
    return (((x%mod)+(y%mod))%mod+mod)%mod;
}
int dp[100005];
int k;
int flowers(int len)
{
    if(len<0)
    {
        return 0;
    }
    if(len==0)
    {
        return 1;
    }
    if(dp[len]>-1)
    {
        return dp[len];
    }
    int &ans=dp[len];
    //pruning
    if(~ans)
    {
        return ans;
    }
    //fill with red flower
    int ans1=flowers(len-1);
    //fill with white flower
    int ans2=flowers(len-k);
    int res=0;

    if(len>=k)
    {
    	res=add(res,ans2,mod);
    }
    res=add(res,ans1,mod);
    // return ans=add(ans1,ans2,mod);
    return ans=res;
    assert(~dp[len] && dp[len]<=1e18 && dp[len]>=0);
}
signed main()
{
    int t;
    cin>>t>>k;
    int N=100005;
    for(int i=0;i<=N;++i)
    {
        dp[i]=-1;
    }
    dp[0]=1;

    flowers(N);
    // for(int i=N-1;i>=1;--i)
    // {
    //     dp[i]=flowers(i);
    // }
    for(int i=1;i<=N;++i)
    {
        dp[i]=add(dp[i],dp[i-1],mod);
        // dp[i]+=dp[i-1];
    }
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int res=0;
        // cout<<add(dp[b],-dp[a-1],mod)<<endl;
        // cout<<dp[b]-dp[a-1]<<endl;
        res=(dp[b]-dp[a-1]+mod)%mod;
        // for(int i=a;i<=b;++i)
        // {
            // res=add(res,flowers(i),mod);
        // }
        cout<<res%mod<<endl;
    }
    return 0;
}