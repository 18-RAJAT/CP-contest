#include<bits/stdc++.h>
using namespace std;
#define int long long
//Rajat joshi template
int commonPrefix(int l,int r)
{
    int mask=0;
    for(int i=30;~i;--i)
    {
        bool L=(l&(1LL<<i))!=0,R=(r&(1LL<<i))!=0;
        if(L==R)
        {
            if(L)mask|=(1LL<<i);
        }
        else break;
    }
    return mask;
}
void sol()
{
    int l,r;
    cin>>l>>r;
    int calc=commonPrefix(l,r),diff=-1;
    for(int i=30;~i;--i)
    {
        bool L=(l&(1LL<<i))!=0,R=(r&(1LL<<i))!=0;
        if(L!=R)
        {
            diff=i;
            break;
        }
    }
    if(diff==-1)
    {
        cout<<l-2<<" "<<l-1<<" "<<l<<endl;
        return;
    }
    int ans=calc+(1LL<<diff);
    if(ans<r)cout<<ans-1<<" "<<ans<<" "<<ans+1<<endl;
    else cout<<ans-2<<" "<<ans-1<<" "<<ans<<endl;
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