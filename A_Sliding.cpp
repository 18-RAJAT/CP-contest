#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,r,c;
    cin>>n>>m>>r>>c;
    cout<<(2*n-2*r+1)*m-n+r-c<<endl;
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