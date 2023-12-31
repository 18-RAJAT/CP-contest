#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    int ans=0;
    if(m<n/2)
    {
        ans=m;
    }
    else if(n<m/2)
    {
        ans=n;
    }
    else if(ans==0)
    {
        ans=(n+m)/3;
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}