#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    vector<int>pref(n+1,0);
    for(int i=0;i<n;++i)
    {
        pref[i+1]=pref[i]+(s[i]=='('?1:-1);
    }
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;++i)
    {
        a[i]={pref[i],i};
    }
    sort(a.begin(),a.end());
    string ans;
    for(int i=0;i<n;++i)
    {
        ans+=s[a[i].second];
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}