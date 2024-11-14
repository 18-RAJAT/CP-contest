#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int Power(int b,int e,int mod)
{
    int res=1;
    b%=mod;
    while(e>=1)
    {
        if(e&1LL)res=res*b%mod;
        b=b*b%mod;
        e>>=1LL;
    }
    return res;
}
void sol()
{
    int n,m;
    cin>>n>>m;
    int lim=(n+1)/2;
    int pali=Power(m,lim,MOD);
    int sum=0;
    for(int i=1;i<=m;++i)
    {
        int q=m/i,rem=m%i;
        int sq=((i*q%MOD)*q)%MOD;
        sq=(sq+(rem*(2LL*q+1))%MOD)%MOD;
        int cnt;
        if(n%2==0)
        {
            int k=n/2;
            cnt=Power(sq,k,MOD);
        }
        else
        {
            int k=n/2;
            int sm=(q*i%MOD+rem)%MOD;
            int tmp=Power(sq,k,MOD);
            cnt=(tmp*sm)%MOD;
        }
        sum=(sum+cnt)%MOD;
    }
    int term=((m+1)*pali%MOD)%MOD;
    int ans=(sum-term+MOD)%MOD;
    if(ans<0)ans+=MOD;
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