#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<pair<int,char>>pr(q);
    for(int i=0;i<q;++i)
    {
        cin>>pr[i].first>>pr[i].second;
    }
    vector<int>count(n+1,0);
    for(int i=0;i<q;++i)
    {
        if(pr[i].second=='+') count[pr[i].first]++;
    }
    vector<int>arr(n+1,q+1),cur(n+1,0);
    for(int i=0;i<q;++i)
    {
        int s=pr[i].first;
        if(pr[i].second=='+')
        {
            cur[s]++;
            if(cur[s]==count[s]) arr[s]=i+1;
        }
    }
    vector<pair<int,int>>vp;
    for(int i=1;i<=n;++i)
    {
        if(count[i]>0) vp.emplace_back(arr[i],count[i]);
    }
    sort(vp.begin(),vp.end());
    int ans=1;
    for(auto& it:vp) ans+=it.second;
    int z=0;
    for(int i=1;i<=n;++i)
    {
        if(count[i]==0)z++;
    }
    ans+=z;
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}