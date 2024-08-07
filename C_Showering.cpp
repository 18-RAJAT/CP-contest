#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,s,m;
    cin>>n>>s>>m;
    vector<pair<int,int>>vp(n);
    for(int i=0;i<n;++i)
    {
        cin>>vp[i].first>>vp[i].second;
    }
    int ok=0;
    if(s<=vp[0].first-0)ok=1;
    for(int i=1;i<n && !ok;++i)
    {
        if(vp[i].first-vp[i-1].second>=s)
        {
            ok=1;
        }
    }
    if(m-vp[n-1].second>=s)ok=1;
    cout<<(ok?"YES":"NO")<<endl;
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