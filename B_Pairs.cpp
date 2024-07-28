#include<bits/stdc++.h>
using namespace std;
#define int long long
int recur(vector<pair<int,int>>& p,int i)
{
    int count=0;
    unordered_map<int,int>mp;
    for(auto& it:p)
    {
        if(it.first==i || it.second==i)continue;
        count++,mp[it.first]++,mp[it.second]++;
    }
    int maxi=0;
    for(auto& it:mp)maxi=max(maxi,it.second);
    return count<=maxi;
}
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>p(m);
    for(auto& it:p)cin>>it.first>>it.second;
    cout<<((recur(p,p[0].first) || recur(p,p[0].second))?"YES":"NO");
}
signed main()
{
    sol();
    return 0;
}