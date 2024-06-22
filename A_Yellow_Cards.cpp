#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,x,y,n;
    cin>>a>>b>>x>>y>>n;
    if(x>y)swap(a,b),swap(x,y);
    int ans=min(n/x,a)+(n-min(n/x,a)*x)/y;
    n-=a*(x-1)+b*(y-1);
    cout<<max(0LL,n)<<" "<<ans;
}
signed main()
{
    sol();
    return 0;
}