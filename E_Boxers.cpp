#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a.begin(),a.end());
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        if(mp[a[i]-1]==0 && a[i]!=1)mp[a[i]-1]++;
        else if(mp[a[i]]==0)mp[a[i]]++;
        else if(mp[a[i]+1]==0 && a[i]!=150001)mp[a[i]+1]++;
    }
    int ans=0;
    for(auto it=mp.begin();it!=mp.end();++it)if(it->second>0)ans++;
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}