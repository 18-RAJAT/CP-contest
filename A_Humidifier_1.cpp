#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;++i)cin>>a[i].first>>a[i].second;
    int ans=0,t=0;
    for(int i=0;i<n;++i)
    {
        int F=a[i].first,S=a[i].second;
        ans=max(0LL,ans-(F-t));
        ans+=S,t=F;
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}