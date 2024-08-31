#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int l,r;
    cin>>l>>r;
    int ans=0;
    for(int i=l;i<=r;++i)
    {
        if(i&1)ans++;
    }
    cout<<ans/2<<endl;
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