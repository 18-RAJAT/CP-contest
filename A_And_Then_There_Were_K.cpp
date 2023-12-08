#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int ans=1;
    n=n>>1;
    while(n)
    {
        ans*=2;
        n=n>>1;
    }
    ans-=1;
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