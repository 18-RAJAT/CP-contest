#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAX=1000005,MOD=1000000007;
//Rajat joshi template
int power(int x,int y,int m)
{
    int res=1;
    x%=m;
    while(y>=1)
    {
        if(y&1)res=res*x%m;
        x=x*x%m;
        y>>=1;
    }
    return res;
}
void sol()
{
    vector<int>Spf(MAX,0),P;
    //Rajat joshi template (Sieve)
    for(int i=2;i<MAX;++i)
    {
        if(Spf[i]==0)
        {
            Spf[i]=i;
            P.push_back(i);
            if(i*i<MAX) for(int j=i*i;j<MAX;j+=i) if(Spf[j]==0)Spf[j]=i;
        }
    }
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int& it:a)cin>>it;
    vector<int>arr(MAX,0);
    for(auto& it:P)
    {
        if(m<it)break;
        int tmp=it;
        while(tmp<=m)
        {
            arr[it]+=m/tmp;
            if(tmp>m/it)break;
            tmp*=it;
        }
    }
    int tot=1;
    for(auto& it:P)
    {
        if(it>m)break;
        tot=tot*(arr[it]+1)%MOD;
    }
    vector<int>Inv(205,1);
    for(int i=1;i<=200;++i)Inv[i]=power(i,MOD-2,MOD);
    //Rajat joshi template (factorize)
    auto Fact=[&](int x)->vector<pair<int,int>>
    {
        vector<pair<int,int>>F;
        while(x>=2)
        {
            int p=Spf[x],cnt=0;
            while(x%p==0)cnt++,x/=p;
            if(F.empty() || F.back().first!=p)F.emplace_back(p,cnt);
            else F.back().second+=cnt;
        }
        return F;
    };

    vector<int>res;
    res.reserve(n);
    for(int i=0;i<n;++i)
    {
        int tmp=a[i];
        vector<pair<int,int>>F=Fact(tmp);
        int ans=tot;
        for(auto& it:F)
        {
            int f=it.first,s=it.second;
            if(f<=m && arr[f]>=1)
            {
                ans=ans*(arr[f]+s+1)%MOD;
                ans=ans*Inv[arr[f]+1]%MOD;
            }
            else
            {
                ans=ans*(s+1)%MOD;
            }
        }
        res.push_back(ans);
    }
    for(int i=0;i<n;++i)cout<<res[i]<<(i<n-1?" ":"\n");
}
signed main()
{
    sol();
    return 0;
}