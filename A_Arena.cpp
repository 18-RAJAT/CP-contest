#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int ans=0,minimum=1e9;
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        int a;
        cin>>a;
        mp[a]++,minimum=min(minimum,a);
    }
    ans=n,ans-=mp[minimum];
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