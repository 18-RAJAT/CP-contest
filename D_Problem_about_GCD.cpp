#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int l,r,G;
    cin>>l>>r>>G;
    if(G==0)
    {
        cout<<"-1 -1"<<endl;
        return;
    }
    int mn=l/G;
    if(l%G!=0)mn++;
    int mx=r/G;
    if(mn>mx)
    {
        cout<<"-1 -1"<<endl;
        return;
    }
    int ans=-1,L=-1,R=-1,cnt=0;
    for(int y=mx;y>=mn && cnt<100;--y)
    {
        cnt++;
        for(int x=mn;x<=y && x<=mn+100;++x)
        {
            if(__gcd(x,y)==1)
            {
                int tot=y-x;
                if(tot>ans || (tot==ans && x<(~L?L/G:LLONG_MAX)))
                {
                    ans=tot,L=x*G,R=y*G;
                }
                break;
            }
        }
    }
    // cout<<ans<<" "<<L<<" "<<R<<__gcd(L,R)<<endl;
    if(~ans) cout<<L<<" "<<R<<endl;
    else
    {
        if(mn==mx && __gcd(mn,mx)==1) cout<<G*mn<<" "<<G*mx<<endl;
        else cout<<"-1 -1"<<endl;
    }
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