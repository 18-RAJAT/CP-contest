#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    map<int,int>mp;
    mp[1],mp[m];
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first>>v[i].second;
        mp[v[i].first];
        mp[v[i].second];
        if(v[i].second+1<=m)
        {
            mp[v[i].second+1];
        }
        // cout<<mp[v[i].first]<<" "<<mp[v[i].second]<<endl;
    }
    function<int(int,int,int)>ans=[&](int X,int count,int m)->int
    {
        vector<int>prefix(count+1);
        for(auto& it:v)
        {
            if(it.first<=X && X<=it.second)
            {
                continue;
            }
            prefix[mp[it.first]]++;
            if(it.second+1<=m)
            {
                prefix[mp[it.second+1]]--;
            }
        }
        for(int i=1;i<=count;++i)
        {
            prefix[i]+=prefix[i-1];
        }
        return *max_element(prefix.begin(),prefix.end())-*min_element(prefix.begin(),prefix.end());
    };
    int count=1;
    for(auto& it:mp)
    {
        it.second=count++;
    }
    cout<<max(ans(1,count,m),ans(m,count,m))<<endl;
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