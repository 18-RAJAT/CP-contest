#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>vp(n);
    for(int i=0;i<n;++i)
    {
        cin>>vp[i].first>>vp[i].second;
    }
    sort(vp.begin(),vp.end());
    vector<int>dp(n),ndp(n);
    for(int i=0;i<n;++i)
    {
        dp[i]=vp[i].first,ndp[i]=vp[i].second;
    }
    //Template Rajat
    vector<int>pref(n,0);
    for(int i=0;i<n;++i)
    {
        int L=dp[i]-ndp[i];
        int Bs=lower_bound(dp.begin(),dp.begin()+i,L)-dp.begin();
        (Bs<i)?pref[i]=pref[Bs]:pref[i]=i;
    }
    vector<int>suf(n,0);
    for(int i=n-1;~i;--i)
    {
        int R=dp[i]+ndp[i];
        int Bs=upper_bound(dp.begin(),dp.end(),R)-dp.begin()-1;
        (Bs>i)?suf[i]=suf[Bs]:suf[i]=i;
    }
    int l=-1,r=-1;
    
    int p=upper_bound(dp.begin(),dp.end(),k-1)-dp.begin()-1;
    if(p>=0 && dp[p]<k)l=p;
    p=lower_bound(dp.begin(),dp.end(),k+1)-dp.begin();
    if(p<n && dp[p]>k)r=p;
    
    int L=0,R=0,cnt=0;
    int ls,le,rs,re;
    
    if(~l)ls=pref[l],le=l,L=le-ls+1;
    if(~r)rs=r,re=suf[r],R=re-rs+1;
    
    if(~l && ~r)
    {
        int mx=max(ls,rs),mn=min(le,re);
        if(mx<=mn)cnt=mn-mx+1;
    }
    cout<<L+R-cnt;
}
signed main()
{
    sol();
    return 0;
}