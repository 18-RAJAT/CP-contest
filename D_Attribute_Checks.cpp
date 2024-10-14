#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<int>dp(m+1,0);
    int CountZ=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]==0)
        {
            CountZ++;
            for(int j=min(CountZ,m);~j;--j)
            {
                if(j>0)
                {
                    dp[j]=max(dp[j],dp[j-1]);
                }
            }
        }
        else
        {
            int temp=abs(a[i]);
            if(a[i]>0)
            {
                for(int j=0;j<=min(CountZ,m);++j)
                {
                    int I=CountZ-j;
                    if(I>=temp)dp[j]++;
                }
            }
            else
            {
                for(int j=0;j<=min(CountZ,m);++j)
                {
                    int S=j;
                    if(S>=temp)dp[j]++;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=m;++i)ans=max(ans,dp[i]);
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}