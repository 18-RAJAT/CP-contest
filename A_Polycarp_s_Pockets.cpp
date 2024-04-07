#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    int ans=0;
    for(auto it=mp.begin();it!=mp.end();++it)
    {
        ans=max(ans,it->second);
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}