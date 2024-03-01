#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int ans=1;
    while(1)
    {
        if(k&1)
        {
            cout<<ans;
            return;
        }
        ans++,k/=2;
    }
}
signed main()
{
    sol();
    return 0;
}