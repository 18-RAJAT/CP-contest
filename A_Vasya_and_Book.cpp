#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x,y,d;
    cin>>n>>x>>y>>d;
    int ans=1e9;
    if(abs(x-y)%d==0) ans=min(ans,abs(x-y)/d);
    else
    {
        if((y-1)%d==0) ans=min(ans,(x-1)/d+1+(y-1)/d);
        if((n-y)%d==0) ans=min(ans,(n-x)/d+1+(n-y)/d);
    }
    cout<<((ans==1e9)?-1:ans)<<endl;
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