#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1000000007;
int add(int a,int b,int mod)
{
    return ((a%mod)+(b%mod))%mod;
}
int mul(int a,int b,int mod)
{
    return ((a%mod)*(b%mod))%mod;
}
void sol()
{
    vector<int>dp(55,1LL);
    int n;
    cin>>n;
    dp[1]=n;
    int ans=0;
    int present=2LL;
    for(int i=2;i<55;i++)
    {
        int pre=present*i;
        int gcd=__gcd(present,i);
        present=pre/gcd;
        dp[i]=n/present;

        int state=abs(dp[i-1]-dp[i]);
        ans=add(ans,mul(i,state,mod),mod);
    }
    cout<<ans<<"\n";
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