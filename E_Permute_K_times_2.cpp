#include<bits/stdc++.h>
using namespace std;
#define int long long
int PowerMod(int base,int exp,int mod)
{
    if(mod==1)return 0;
    int res=1;
    base%=mod;
    while(exp)
    {
        if(exp&1)res=(res*base)%mod;
        base=(base*base)%mod;
        exp>>=1;
    }
    return res;
}
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i],a[i]--;
    }
    vector<int>vis(n,0),ans(n,0);
    for(int i=0;i<n;++i)
    {
        if(!vis[i])
        {
            vector<int>dp;
            int tmp=i;
            while(!vis[tmp])
            {
                vis[tmp]=1;
                dp.push_back(tmp);
                tmp=a[tmp];
            }
            int inv=PowerMod(2,k,dp.size());
            for(int j=0;j<dp.size();++j)
            {
                ans[dp[j]]=dp[(j+inv)%dp.size()];
            }
            // for(auto x:dp)vis[x]=0;
            // for(auto x:dp)cout<<x<<' ';
            // cout<<endl;
        }
    }
    for(int i=0;i<n;++i)cout<<ans[i]+1<<(i==n-1?'\n':' ');
}
signed main()
{
    sol();
    return 0;
}