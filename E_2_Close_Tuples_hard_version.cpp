#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int Fact[200005];
void Compute()
{
    Fact[0]=1;
    for(int i=1;i<=200000;++i)
    {
        Fact[i]=i*Fact[i-1]%mod;
    }
}
int Power(int x,int y,int mod=mod)
{
    int res=1;
    x%=mod;
    while(y>=1)
    {
        if(y&1)
        {
            res=res*x%mod;
        }
        y>>=1;
        x=x*x%mod;
    }
    return res;
}
int ModInverse(int x,int mod=mod)
{
    return Power(x,mod-2,mod);
}
int Factorial(int p,int q,int mod=mod)
{
    if(p<q)return 0;
    if(p==q || q==0)return 1;
    return Fact[p]*ModInverse(Fact[q],mod)%mod*ModInverse(Fact[p-q],mod)%mod;
}
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(n),count(n+1,0),cmp(n+1,0);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        count[a[i]]++;
    }
    for(int i=1;i<=n;++i)
    {
        cmp[i]=cmp[i-1]+count[i];
    }
    int ans=0;
    for(int i=0;i<=n;++i)
    {
        int l=count[i];
        int r=cmp[min(n,i+k)]-cmp[i];
        for(int j=1;j<=m;++j)
        {
            if(j>l || m-j>r) continue;
            ans=(ans+Factorial(l,j)*Factorial(r,m-j)%mod)%mod;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    Compute();
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}