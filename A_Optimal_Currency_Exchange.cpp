#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,d,e;
    cin>>n>>d>>e;
    int ans=n;
    e*=5;
    for(int i=0;i<=n;i+=e)
    {
        ans=min(ans,(n-i)%d);
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}