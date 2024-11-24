#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int PowM(int a,int b,int mod)
{
    int res=1;
    a%=mod;
    while(b>=1)
    {
        if(b&1)res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
int combination(int n,int r)
{
    int res=1;
    for(int i=1;i<=r;++i)res=(res*(n-i+1)/i)%mod;
    return res;
}
void sol()
{
    int m;
    cin>>m;
    int ans=m;
    if(m>=2)ans=(ans+m*(m-1))%mod;
    if(m>=3)
    {
        int tot=m*(m-1)%mod;
        tot=(tot*(m-2))%mod;
        int res=combination(m,3);
        if(m==5)res=4;
        ans=(ans+res)%mod;
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