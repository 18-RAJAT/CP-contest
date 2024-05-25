#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int r;
    cin>>r;
    int ans=0,lw=0,hi=0;
    for(int i=r;i>0;--i)
    {
        while(i*i+hi*hi<(r+1)*(r+1))hi++;
        while(i*i+lw*lw<(r*r))lw++;
        ans+=hi-lw;
    }
    cout<<4*ans<<endl;
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