#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mod=998244353,N=1000005;
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    vector<int>spf(N,0);
    for(int i=2;i<N;++i)
    {
        if(spf[i]==0)
        {
            spf[i]=i;
            for(int j=2*i;j<N;j+=i)
            {
                if(spf[j]==0)spf[j]=i;
            }
        }
    }
    vector<int>dp(n+1,0),ndp(N,0);
    auto factor=[&](int x)
    {
        vector<int>res;
        while(x>=2)
        {
            int p=spf[x];
            res.push_back(p);
            while(x%p==0)x/=p;
        }
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    };
    dp[1]=1;
    vector<int>fact=factor(a[0]);
    int sz=fact.size();
    for(int mask=1;mask<(1<<sz);++mask)
    {
        int x=1;
        for(int i=0;i<sz;++i)
        {
            if(mask&(1<<i))x*=fact[i];
        }
        ndp[x]=(ndp[x]+dp[1])%Mod;
    }
    for(int i=2;i<=n;++i)
    {
        vector<int>nFact=factor(a[i-1]);
        int zs=nFact.size();
        int sum=0;
        for(int mask=1;mask<(1<<zs);++mask)
        {
            int x=1,bits=0;
            for(int j=0;j<zs;++j)
            {
                if(mask&(1<<j))
                {
                    x*=nFact[j];
                    bits++;
                }
            }
            (bits&1)?(sum=(sum+ndp[x])%Mod):(sum=(sum-ndp[x]+Mod)%Mod);
        }
        dp[i]=sum;
        for(int mask=1;mask<(1<<zs);++mask)
        {
            int x=1;
            for(int j=0;j<zs;++j)
            {
                if(mask&(1<<j))x*=nFact[j];
            }
            ndp[x]=(ndp[x]+dp[i])%Mod;
        }
    }
    cout<<dp[n]<<endl;
}
signed main()
{
    sol();
    return 0;
}