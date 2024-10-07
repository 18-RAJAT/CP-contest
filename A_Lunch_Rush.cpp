#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Inf=1e18;
void sol()
{
    int n,d;
    cin>>n>>d;
    vector<int>k(n),l(n);
    for(int i=0;i<n;++i)
    {
        cin>>k[i]>>l[i];
    }
    int ans=-Inf;
    for(int i=0;i<n;++i)ans=max(ans,k[i]-max(l[i]-d,0ll));
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}