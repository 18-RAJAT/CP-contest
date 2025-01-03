#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    array<array<int,2>,100005>mp;
    for(int i=0;i<n;++i)cin>>mp[i][0]>>mp[i][1];
    sort(mp.begin(),mp.begin()+n,[&](array<int,2>& a,array<int,2>& b)
    {
        return a[0]<b[0] || (a[0]==b[0] && a[1]<b[1]);
    });
    int ans=0;
    for(int i=0;i<n;++i)
    {
        ans=(mp[i][1]>=ans)?mp[i][1]:mp[i][0];
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}