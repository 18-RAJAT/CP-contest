#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    unordered_map<int,int>mp;
    for(int i=0;i<n;++i)mp[a[i]]++;
    int ans=0;
    for(auto& it:mp)ans+=it.second/2;
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