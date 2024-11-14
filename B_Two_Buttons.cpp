#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    int ans=0;
    while(n<m)
    {
        (m&1)?m++:m/=2;
        ans++;
    }
    ans+=(n-m);
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}