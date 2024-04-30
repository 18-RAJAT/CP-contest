#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    array<int,2>dp[n+1][k+1];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<=k;++i)
    {
        dp[n][i]={0,0};
    }
    unordered_map<int,int>mp;
    for(int i=n-1;~i;--i)
    {
        for(int j=0;j<=k;++j)
        {
            mp.clear();
            dp[i][j]={LLONG_MAX,0};//ok
            dp[i][j]={a[i]+dp[i+1][j][0],dp[i+1][j][1]};
            int temp=a[i],end=n-1;
            int count=0;
            for(int l=i;l<=i+j;++l)
            {
                if(l<=end)
                {
                    if(a[l]<temp)
                    {
                        temp=a[l];
                        count=1;
                    }
                    else if(a[l]==temp)
                    {
                        count++;
                    }
                    int minimize=l-i+1;
                    for(int m=0;m<=j-(minimize-count);++m)
                    {
                        if(dp[i][j][0]>temp*minimize+dp[l+1][m][0])
                        {
                            dp[i][j]={temp*minimize+dp[l+1][m][0],dp[i][j][1]+dp[l+1][m][1]};
                        }
                        else if(dp[i][j][0]==temp*minimize+dp[l+1][m][0])
                        {
                            dp[i][j]={dp[i][j][0],dp[i][j][1]+dp[l+1][m][1]};
                        }
                    }
                    if(l+1<=end)
                    {
                        if(dp[i][j][0]>temp*minimize+dp[l+1][j-(minimize-count)][0])
                        {
                            dp[i][j]={temp*minimize+dp[l+1][j-(minimize-count)][0],dp[i][j][1]+dp[l+1][j-(minimize-count)][1]};
                        }
                        else if(dp[i][j][0]==temp*minimize+dp[l+1][j-(minimize-count)][0])
                        {
                            dp[i][j]={dp[i][j][0],dp[i][j][1]+dp[l+1][j-(minimize-count)][1]};
                        }
                    }
                    else
                    {
                        dp[i][j]={min(dp[i][j][0],temp*minimize),dp[i][j][1]+1};
                    }
                }
            }
        }
    }
    // for(int i=0;i<n;++i)
    // {
    //     for(int j=0;j<=k;++j)
    //     {
    //         cout<<dp[i][j][0]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[0][k][0]<<endl;
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