#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    map<int,vector<int>>mp;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        mp[x].push_back(i);
    }
    auto arithmetic_sequence=[&](vector<int>&a)->bool
    {
        for(int i=0;i<a.size()-1;++i)
        {
            if(a[i+1]-a[i]!=a[1]-a[0])return false;
        }
        return true;
    };
    vector<pair<int,int>>ans;
    for(auto it=mp.begin();it!=mp.end();++it)
    {
        int F=it->first;
        vector<int>& S=it->second;
        if(S.size()==1)
        {
            ans.push_back(pair<int,int>(F,0));
        }
        else if(arithmetic_sequence(S))
        {
            ans.push_back(pair<int,int>(F,S[1]-S[0]));
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();++i)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}