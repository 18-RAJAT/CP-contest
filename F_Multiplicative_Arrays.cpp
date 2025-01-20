#include<bits/stdc++.h>
using namespace std;
#define int long long

//Rajat joshi template
const int MOD=998244353,N=18;
int Power(int a,int b,int mod)
{
    int res=1;a%=mod;
    while(b>=1)
    {
        if(b&1)res=res*a%mod;
        a=a*a%mod;b>>=1;
    }
    return res;
}
void sol()
{
    int k,n;
    cin>>k>>n;
    int Ft[N+1],Inv[N+1];
    Ft[0]=1;
    for(int i=1;i<=N;++i)Ft[i]=Ft[i-1]*i%MOD;
    for(int i=0;i<=N;++i)Inv[i]=Power(Ft[i],MOD-2,MOD);
    vector<vector<int>>g(k+1,vector<int>(N+1,0));
    for(int i=2;i<=k;++i)g[i][1]=1;
    vector<int>dp(k+1,0),ndp(k+1,0);
    for(int i=1;i<=k;++i)dp[i]=g[i][1];
    for(int i=2;i<=N;++i)
    {
        fill(ndp.begin(),ndp.end(),0);
        for(int j=2;j<=k;++j)
        {
            for(int l=j;l<=k;l+=j)
            {
                ndp[l]=(ndp[l]+dp[l/j])%MOD;
            }
        }
        for(int j=1;j<=k;++j)g[j][i]=ndp[j];
        dp=ndp;
    }
    int NFt[N+2],NInv[N+2];
    NFt[0]=1;
    for(int i=1;i<=N+1;++i)NFt[i]=NFt[i-1]*i%MOD;
    for(int i=0;i<=N+1;++i)NInv[i]=Power(NFt[i],MOD-2,MOD);
    vector<int> res(k+1,0);
    for(int l=1;l<=k;++l)
    {
        if(l==1)
        {
            res[l]=n%MOD;
            continue;
        }
        int tot=0;
        for(int j=1;j<=N;++j)
        {
            if(!g[l][j] || j+1>n+1)continue;
            int c=1;
            for(int i=0;i<=j;++i)c=c*((n+1)-i)%MOD;
            c=c*NInv[j+1]%MOD;
            tot=(tot+g[l][j]*c)%MOD;
        }
        res[l]=tot;
    }
    for(int i=1;i<=k;++i)cout<<res[i]<<(i==k?"\n":" ");
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