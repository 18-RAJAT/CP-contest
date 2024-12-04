#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD=1000000007,N=200005;

//Rajat Joshi Template
int power(int x,int y,int mod)
{
    int r=1;
    x%=mod;
    if(x<0)x+=mod;
    while(y>=1)
    {
        if(y&1)r=r*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return r;
}
vector<int>f(N,1),Inv(N,1);
void precompute()
{
    for(int i=1;i<N;++i)f[i]=f[i-1]*i%MOD;
    Inv[N-1]=power(f[N-1],MOD-2,MOD);
    for(int i=N-2;~i;--i)Inv[i]=Inv[i+1]*(i+1)%MOD;
}
void sol()
{
    int n,k;
    cin>>n>>k;
    int h=(k-1)/2,l=max<int>(1LL,k-n),m=(l<=h?h-l+1:0),s=0;
    if(m==0)s=f[n]%MOD;
    else
    {
        int c=1,res=1;
        for(int i=0;i<=m;++i)
        {
            if(i>=1)
            {
                c=c*(m-i+1)%MOD;
                c=c*power(i,MOD-2,MOD)%MOD;
                res=res*(MOD-2)%MOD;
            }
            int t=c*res%MOD;
            t=t*f[n-i]%MOD;
            s=(s+t)%MOD;
        }
    }
    int ans=(f[n]-s+MOD)%MOD;
    cout<<ans<<endl;
}
signed main()
{
    int t;
    cin>>t;
    precompute();
    while(t--)
    {
        sol();
    }
    return 0;
}