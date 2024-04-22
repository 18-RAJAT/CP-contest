#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    string x,s;
    cin>>x>>s;
    auto check=[&](string &x,string &s)
    {
        return x.find(s)!=-1;
    };
    int ans=-1;
    for(int i=0;i<7;++i)
    {
        if(check(x,s))
        {
            ans=i;
            break;
        }
        x+=x;
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