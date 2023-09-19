#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k,x;
    cin>>n>>k>>x;
    if(n<k || x<k-1)
    {
        cout<<"-1\n";
    }
    else if(x<=k)
    {
        cout<<k*(k-1)/2+(k-1)*(n-k)<<"\n";
    }
    else
    {
        cout<<k*(k-1)/2+x*(n-k)<<"\n";
    }
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