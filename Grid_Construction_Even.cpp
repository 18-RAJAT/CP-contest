#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        if(i&1)
        {
            for(int j=1;j<=n;++j)cout<<j<<" ";
        }
        else
        {
            for(int j=n;j>=1;--j)cout<<j<<" ";
        }
        cout<<endl;
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