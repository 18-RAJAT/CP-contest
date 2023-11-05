#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int p,a,b,c;
    cin>>p>>a>>b>>c;
 
    int x=((p-1)/a+1)*a;
    int y=((p-1)/b+1)*b;
    int z=((p-1)/c+1)*c;
 
    int ans=min(x-p,y-p);
    ans=min(ans,z-p);
    cout<<ans<<endl;
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