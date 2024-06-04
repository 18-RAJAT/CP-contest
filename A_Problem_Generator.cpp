#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    unordered_map<char,int>mp;
    for(auto& it:s)mp[it]++;
    int ans=0;
    string ss="ABCDEFG";
    for(auto& it:ss)
    {
        if(mp[it]<m)ans+=(m-mp[it]);
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