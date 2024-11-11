#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,v;
    cin>>n>>m>>v;
    vector<int>a(n);
    for(auto& it:a)cin>>it;
    vector<int>pref(n+1,0);
    for(int i=1;i<=n;++i)pref[i]=pref[i-1]+a[i-1];
    vector<int>dp(n+1,0);
    int curr=0,cnt=0;
    for(int i=1;i<=n;++i)
    {
        curr+=a[i-1];
        if(v<=curr)
        {
            cnt++,curr=0;
        }
        dp[i]=cnt;
    }
    vector<int>ndp(n+2,0);
    curr=0,cnt=0;
    for(int i=n;i>=1;--i)
    {
        curr+=a[i-1];
        if(v<=curr)
        {
            cnt++,curr=0;
        }
        ndp[i]=cnt;
    }
    int tmp=pref[n];
    if(tmp<m*v)
    {
        cout<<-1<<endl;
        return;
    }
    int ans=0,sum=0;
    for(auto& it:a)
    {
        sum+=it;
        if(sum>=v)
        {
            ans++,sum=0;
        }
    }
    int maxi=(m<=ans)?0:-1;
    int l=1,r=tmp;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        bool ok=false;
        int i=1;
        for(int j=1;j<=n;++j)
        {
            while(i<=j && pref[j]-pref[i-1]>=mid)
            {
                if(dp[i-1]+ndp[j+1]>=m)
                {
                    ok=true;
                    break;
                }
                i++;
            }
            if(ok)break;
        }
        (ok)?maxi=mid,l=mid+1:r=mid-1;
    }
    cout<<maxi<<endl;
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