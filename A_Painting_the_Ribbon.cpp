#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    int div=n/m,rem=n%m;
    ((n-(div+(rem!=0))<=k)?cout<<"NO"<<endl:cout<<"YES"<<endl);
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