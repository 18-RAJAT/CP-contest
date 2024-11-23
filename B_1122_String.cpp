#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.length();
    if(n&1)
    {
        cout<<"No";
        return;
    }
    for(int i=0;i<n;i+=2)
    {
        if(s[i]!=s[i+1])
        {
            cout<<"No";
            return;
        }
    }
    unordered_map<char,int>mp;
    for(int i=0;i<n;++i)mp[s[i]]++;
    for(auto it=mp.begin();it!=mp.end();++it)
    {
        if(it->second!=2)
        {
            cout<<"No";
            return;
        }
    }
    cout<<"Yes";
}
signed main()
{
    sol();
    return 0;
}