#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x,y;
    cin>>x>>y;
    cout<<max((y+1)/2,(4*y+x+14)/15)<<endl;
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