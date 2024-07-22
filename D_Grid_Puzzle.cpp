#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<int>dp(n);
    array<int,2>ndp={-1,-1};
    for(int i=0;i<n;++i)
    {
        dp[i]=(i>=1?dp[i-1]:0)+(a[i]!=0);
        if(a[i]<=2)
        {
            int bit=i&1;
            int check=ndp[bit^1];
            if(~check)
            {
                dp[i]=min(dp[i],(check>=1?dp[check-1]:0)+i-check);
            }
            ndp[bit]=i;
        }
        if(a[i]>4)
        {
            ndp={-1,-1};
        }
    }
    cout<<dp[n-1]<<endl;
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