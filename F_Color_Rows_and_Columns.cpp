#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>dp(k+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=n;++i)
    {
        int a,b;
        cin>>a>>b;
        vector<int>ndp(k+1,INT_MAX);
        int cnt=0,cur=0;
        while(cnt<k && (a||b))
        {
            if(a>b)
            {
                swap(a,b);
            }
            cnt++,cur+=a,b--,ndp[cnt]=cur;
        }
        for(int rev=k;rev>=1;--rev)
        {
            for(int j=1;j<=rev;++j)
            {
                dp[rev]=min(dp[rev],dp[rev-j]+ndp[j]);
            }
        }
    }
    cout<<((dp[k]==INT_MAX)?-1:dp[k])<<endl;
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