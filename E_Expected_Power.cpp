#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int N=2e5+9;
int pow(int a,int b,int p=mod)
{
    a%=p;
    if(a==0)return 0;
    int ans=1;
    while(b>0)
    {
        if(b&1)ans=(ans*a)%p,b--;
        a*=a;a%=p;
        b>>=1;
    }
    return ans;
}
int CountINV(int a,int x=mod)
{
    return pow(a,x-2,x);
}
int Inverse[N],a[N],p[N];
int n;
int Dp[2][1024];
void sol()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>p[i];
    for(int j=0;j<1024;++j)Dp[0][j]=Dp[1][j]=0;
    Dp[0][0]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<1024;++j)
        {
            Dp[i&1][j]=(Dp[i&1^1][j]*(10000-p[i])%mod*Inverse[10000]%mod);
            Dp[i&1][j]+=(Dp[i&1^1][j^a[i]]*p[i]%mod*Inverse[10000]%mod);
        }
    }
    int ans=0;
    for(int j=0;j<1024;++j)
    {
        ans+=j*j%mod*Dp[n&1][j]%mod;
        ans%=mod;
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=1;i<N;++i)Inverse[i]=CountINV(i);
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}