#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(k);
    for(auto&it:a)cin>>it;
    sort(a.begin(),a.end());
    int ans=0;
    for(int i=0;i<k-1;++i)
    {
        ans+=2*a[i]-1;
    }
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