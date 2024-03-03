#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<pair<int,int>>pairs;
    int one=0,zero=0;
    for(int i=0;i<n;++i)
    {
        string s;
        cin>>s;
        int one_count=0;
        for(auto& it:s)
        {
            one_count+=(it=='1');
        }
        pairs.push_back({s.size()-one_count,one_count});
        zero+=pairs.back().first;
        one+=pairs.back().second;
    }
    if(zero==0 || one==0)
    {
        cout<<0<<endl;
        return;
    }
    int ans=1e18;
    //for 0 table
    int a=pairs[0].second;
    for(int i=1;i<n;++i)
    {
        a+=min(pairs[i].first,pairs[i].second);
    }
    for(int i=1;i<n;++i)
    {
        ans=min(ans,a+pairs[i].first-min(pairs[i].first,pairs[i].second));
    }
    //for 1 table
    a=pairs[0].first;
    for(int i=1;i<n;++i)
    {
        a+=min(pairs[i].first,pairs[i].second);
    }
    for(int i=1;i<n;++i)
    {
        ans=min(ans,a+pairs[i].second-min(pairs[i].first,pairs[i].second));
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}