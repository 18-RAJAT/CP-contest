#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mod=998244353,N=2e5+5;
int dp[N][2];
struct st
{
    int F,S;
};
int ModInverse(int x)
{
    int ans=1,e=Mod-2;
    while(e)
    {
        if(e&1)ans=(ans*x)%Mod;
        x=(x*x)%Mod;
        e>>=1;
    }
    return ans;
}
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)cin>>b[i];
    vector<st>v[2];
    for(int i=0;i<n;++i)
    {
        v[0].push_back({a[i],i});
        v[1].push_back({b[i],i});
    }
    sort(v[0].begin(),v[0].end(),[&](st x,st y)
    {
        if(x.F!=y.F)return x.F<y.F;
        return x.S<y.S;
    });
    sort(v[1].begin(),v[1].end(),[&](st x,st y)
    {
        if(x.F!=y.F)return x.F<y.F;
        return x.S<y.S;
    });
    int ans=1;
    for(int i=0;i<n;++i)
    {
        int mini=min(v[0][i].F,v[1][i].F);
        ans=(ans*mini)%Mod;
        dp[v[0][i].S][0]=i;
        dp[v[1][i].S][1]=i;
    }
    cout<<ans<<" ";
    while(q--)
    {
        int o,x;
        cin>>o>>x;
        o--,x--;
        int ert=dp[x][o],mini=min(v[0][ert].F,v[1][ert].F);
        ans=(ans*ModInverse(mini))%Mod;
        v[o][ert].F++;
        int take=v[o][ert].F>v[o][ert+1].F && ert+1<n;
        if(take)
        {
            int l=ert+1,r=n-1,tmp=ert;
            while(l<=r)
            {
                int mid=(l+r)/2;
                (v[o][mid].F<v[o][ert].F)?tmp=mid,l=mid+1:r=mid-1;
            }
            mini=min(v[0][tmp].F,v[1][tmp].F),ans=(ans*ModInverse(mini))%Mod;
            swap<st>(v[o][ert],v[o][tmp]);
            // for(int i=0;i<n;++i)
            // {
            //     if(v[o][i].S==ert)dp[i][o]=tmp;
            //     else if(v[o][i].S==tmp)dp[i][o]=ert;
            // }
            dp[v[o][ert].S][o]=ert,dp[v[o][tmp].S][o]=tmp;
            mini=min(v[0][tmp].F,v[1][tmp].F);
            // for(auto it=v[o].begin()+ert+1;it!=v[o].begin()+tmp;++it) mini=min(mini,it->F);
            ans=(ans*mini)%Mod;
        }
        mini=min(v[0][ert].F,v[1][ert].F);
        ans=(ans*mini)%Mod;
        cout<<ans<<" ";
    }
    cout<<endl;
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