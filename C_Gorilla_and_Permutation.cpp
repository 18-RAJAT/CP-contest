#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n-m;++i)
    {
        cout<<n-i<<" ";
    }
    for(int i=1;i<m+1;++i)
    {
        cout<<i<<" ";
    }
    cout<<endl;
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