#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a;
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        mp[x]++;
        a.push_back(x);
    }
    map<int,vector<int>>dp;
    sort(a.begin(),a.end());
    // reverse(a.begin(),a.end());
    for(auto& it:mp)dp[it.second].push_back(it.first);
    int ans=0;
    for(auto& it:dp)
    {
        if(it.first==1)
        {
            auto ok=it.second.size();
            int div=ok/2,md=ok%2;;
            ans+=((md+div)*2);
        }
        else ans+=it.second.size();
    }
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