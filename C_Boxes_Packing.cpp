#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int ans=0;
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        mp[x]++;
        ans=max(ans,mp[x]);
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}