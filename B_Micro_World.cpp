#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    int ans=n;
    vector<pair<int,int>>v;
    for(auto it=mp.begin();it!=mp.end();++it)
    {
        v.push_back({it->first,it->second});
    }
    for(int i=0;i<v.size()-1;++i)
    {
        if(v[i+1].first-v[i].first<=k)
        {
            ans-=v[i].second;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}