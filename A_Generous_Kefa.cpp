#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int>cnt(26);
    auto convert=[&](char ch)->int
    {
        return ch-'a';
    };
    for(auto& ch:s)
    {
        cnt[convert(ch)]++;
    }
    for(int i=0;i<26;++i)
    {
        if(cnt[i]>k)
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
signed main()
{
    sol();
    return 0;
}