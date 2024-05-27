#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int r,d,n,R,x,y,p,count=0;
    cin>>r>>d>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x>>y>>R;
        p=x*x+y*y;
        double q=sqrt(p);
        if((r-d)<=q-R && q+R<=r && 2*R<=d)count++;
    }
    cout<<count;
}
signed main()
{
    sol();
    return 0;
}