#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x,k;
    cin>>n>>x>>k;
    string s;
    cin>>s;
    int cnt1=0,ok=0;
    for(auto& c:s)
    {
        if(c=='1')++cnt1;
        else ok+=cnt1;
    }
    if(ok<=x && ok%k==0)cout<<1<<endl;
    else cout<<2<<endl;
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