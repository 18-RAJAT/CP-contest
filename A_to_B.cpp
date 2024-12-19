#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x1,y1,z1,x2,y2,z2,k;
    cin>>x1>>y1>>z1>>x2>>y2>>z2>>k;
    int dx=abs(x2-x1),dy=abs(y2-y1),dz=abs(z2-z1);
    int mxi=max({dx,dy,dz}),tot=dx+dy+dz-mxi,tmp=(mxi+k-1)/k,ans;
    if(tot>=tmp-1)ans=dx+dy+dz;
    else
    {
        int rem=tmp-1-tot;
        //cout<<tot<<" "<<tmp<<endl;
        if(rem&1)ans=dx+dy+dz+rem+1;
        else ans=dx+dy+dz+rem;
    }
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