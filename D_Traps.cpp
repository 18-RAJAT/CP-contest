#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(auto& it:a)cin>>it;
    vector<pair<int,int>>vp,trap;
    for(int i=0;i<n;++i)
    {
        vp.push_back({n-i-1-a[i],i});
    }
    int ans=0;
    sort(vp.begin(),vp.end());
    for(auto& it:a)ans+=it;
    for(int i=0;i<k;++i)
    {
        trap.push_back({vp[i].second,vp[i].first});
    }
    sort(trap.begin(),trap.end(),greater<pair<int,int>>());
    int i=0,j=0;
    do
    {
        if(ans<ans+trap[i].second-j)
        {
            i++;
            continue;
        }
        else
        {
            ans+=trap[i].second-j,j++;
        }
        i++;
    }while(i<trap.size() && j<k);
    cout<<ans<<endl;
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