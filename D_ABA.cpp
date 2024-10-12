#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    vector<vector<int>>Pref(n+1,vector<int>(26,0)),Suf(n+1,vector<int>(26,0));
    for(int i=0;i<n;++i)
    {
        Pref[i+1]=Pref[i];
        Pref[i+1][s[i]-'A']++;
    }
    for(int i=n-1;~i;--i)
    {
        Suf[i]=Suf[i+1];
        Suf[i][s[i]-'A']++;
    }
    int ans=0;
    for(int j=1;j<n-1;++j)
    {
        for(int c=0;c<26;++c)ans+=Pref[j][c]*Suf[j+1][c];
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}