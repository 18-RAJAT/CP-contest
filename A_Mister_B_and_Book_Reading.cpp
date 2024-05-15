#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int c,v0,v1,a,l;
    cin>>c>>v0>>v1>>a>>l;
    int count=0,speed=v0,ans=0;
    while(count<c)
    {
        ans++;
        if(count)count-=l;
        count+=speed;
        speed+=a;
        speed=min(speed,v1);
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}