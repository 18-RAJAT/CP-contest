#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x,y;
    cin>>n>>x>>y;
    int ans=0;
    y/=3;
    (y<x)?(ans+=y,x=x-y,ans+=x/2):(ans=x);
    cout<<(n<=ans?"YES":"NO")<<endl;
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