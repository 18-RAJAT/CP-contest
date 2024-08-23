#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x1,y1,x2,y2;
    cin>>n;
    int ans=0;
    while(n--)
    {
        cin>>x1>>y1>>x2>>y2;
        ans+=(1+abs(x1-x2))*(1+abs(y1-y2));
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}