#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,l;
    cin>>n>>l;
    vector<array<int,2>>arr(n);
    vector<int>dp(n+1),ndp(n+1);
    fill(dp.begin(),dp.end(),1e18);
    dp[0]=0;
    for(int i=0;i<n;++i)
    {
        cin>>arr[i][1]>>arr[i][0];
    }
    sort(arr.begin(),arr.end());
    int current=-1,ans=0;
    for(auto[f,s]:arr)
    {
        ndp[1]=min(f+dp[1]-current,s);
        for(int i=1;i<n;++i)
        {
            ndp[i+1]=min(f+dp[i+1]-current,f+dp[i]-current+s);
        }
        ndp[0]=0;
        for(int i=0;i<=n;++i)
        {
            if(ndp[i]<=l)
            {
                ans=max(ans,i);
            }
            dp[i]=ndp[i];
        }
        current=f;
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