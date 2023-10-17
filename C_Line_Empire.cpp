#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int pref[N],suf[N];
int n,a,b;
int dp[N];

void sol()
{
    cin>>n>>a>>b;
    memset(dp,-1,sizeof(dp));
    function<int(int)>space=[&](int pos)->int
    {
        int &res=dp[pos];
        if(~res)
        {
            return res;
        }
        if(pos==n-1)
        {
            return res=(pref[n]-pref[pos])*b;
        }
        res=suf[n]-suf[pos]-abs(pref[pos]*(n-pos));
        res*=b;
        for(int i=pos+1;i<pos+2;i++)
        {
            int z=suf[i]-suf[pos]-abs(pref[pos])*(i-pos);
            z*=b;
            res=min(res,z+(pref[i]-pref[pos])*a+space(i));
            // cout<<z<<" "<<b;
        }
        return res;
    };
    for(int i=1;i<=n;++i)
    {
        cin>>pref[i];
        suf[i]=pref[i]+suf[i-1];
    }
    for(int i=n-1;i>=0;--i)
    {
        space(i);
    }
    cout<<space(0)<<endl;
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