#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x1,x2,x3;
    cin>>x1>>x2>>x3;
    cout<<max({x1,x2,x3})-min({x1,x2,x3})<<endl;
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