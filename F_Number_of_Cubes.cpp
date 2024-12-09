#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353,MAXN=3000005;
vector<int> spf,check,fact,inv_fact;

//Rajat joshi template
int pow_mod(int b,int e,int m)
{
    int res=1;
    b%=m;
    while(e>=1)
    {
        if(e&1)res=res*b%m;
        b=b*b%m;
        e>>=1;
    }
    return res;
}
int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y);
}
void Pre(int n)
{
    spf.assign(n+1,0);
    check.assign(n+1,0);
    for(int i=0;i<=n;++i)check[i]=i;
    for(int p=2;p<=n;++p)
    {
        if(spf[p]==0)
        {
            spf[p]=p;
            check[p]=p-1;
            for(int i=2*p;i<=n;i+=p)
            {
                if(spf[i]==0)spf[i]=p;
                check[i]=check[i]/p*(p-1);
            }
        }
    }
}
vector<int>divisors(int n)
{
    vector<int>divs;
    if(n==0)return divs;
    vector<pair<int,int>>factors;
    while(n>1)
    {
        int p=spf[n],cnt=0;
        while(n%p==0)cnt++,n/=p;
        factors.emplace_back(p,cnt);
    }
    divs.push_back(1);
    for(auto& f:factors)
    {
        int p=f.first,c=f.second;
        int sz=divs.size(),p_pow=1;
        for(int i=0;i<c;++i)
        {
            p_pow*=p;
            for(int j=0;j<sz;++j)
            {
                if((int)divs[j]*p_pow>3000000)continue;
                divs.push_back(divs[j]*p_pow);
            }
        }
    }
    sort(divs.begin(),divs.end());
    return divs;
}
void sol()
{
    int a,b,c,k;
    cin>>a>>b>>c>>k;
    vector<int>d(k);
    for(auto& x:d)cin>>x;
    int g=d[0];

    for(int i=1;i<k;++i)g=gcd(g,d[i]);
    vector<int>DA,DB,DC;
    for(auto dx:divisors(a))
    {
        int u=a/dx;
        if(g%u==0)DA.push_back(dx);
    }
    for(auto dy:divisors(b))
    {
        int v=b/dy;
        if(g%v==0)DB.push_back(dy);
    }
    for(auto dz:divisors(c))
    {
        int w=c/dz;
        if(g%w==0)DC.push_back(dz);
    }
    int n=a*b*c,Ans=0;
    for(auto dx:DA)
    {
        int u=a/dx,Tmp=check[u];
        for(auto dy:DB)
        {
            int v=b/dy,Temp=check[v];
            for(auto dz:DC)
            {
                int w=c/dz,Res=check[w];
                int lcm_uv=(u/gcd(u,v))*v;
                int lcm_uvw=(lcm_uv/gcd(lcm_uv,w))*w;
                if((int)lcm_uvw>n || g%lcm_uvw!=0)continue;
                int m=n/lcm_uvw,res=fact[m];
                for(int i=0;i<k;++i)
                {
                    int ci=d[i]/lcm_uvw;
                    res=res*inv_fact[ci]%MOD;
                }
                int cnt=Tmp*Temp%MOD*Res%MOD;
                Ans=(Ans+res*cnt)%MOD;
            }
        }
    }
    int inv_n=pow_mod(n,MOD-2,MOD)%MOD;
    cout<<(Ans*inv_n%MOD)%MOD<<endl;
}
signed main()
{
    spf.clear();
    check.clear();
    fact.clear();
    inv_fact.clear();
    Pre(MAXN);
    fact.assign(MAXN+1,1);
    for(int i=1;i<=MAXN;++i)fact[i]=fact[i-1]*i%MOD;
    inv_fact.assign(MAXN+1,1);
    inv_fact[MAXN]=pow_mod(fact[MAXN],MOD-2,MOD);
    for(int i=MAXN-1;~i;--i)inv_fact[i]=inv_fact[i+1]*(i+1)%MOD;
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}