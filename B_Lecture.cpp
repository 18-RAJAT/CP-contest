#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    string s;
    map<string,string>mp;
    for(int i=0;i<m;++i)
    {
        string a,b;
        cin>>a>>b;
        mp[a]=b;
    }
    for(int i=0;i<n;++i)
    {
        cin>>s;
        (mp[s].size()<s.size())?cout<<mp[s]<<" ":cout<<s<<" ";
    }
}
signed main()
{
    sol();
    return 0;
}