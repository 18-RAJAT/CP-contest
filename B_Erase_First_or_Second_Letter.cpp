#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int dp[N][26];
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int sum=0;
    for(int i=0;i<n;++i)
    {
        dp[i][s[i]-'a']++;
        if(i!=0)
        {
            for(int j=0;j<26;++j)
            {
                dp[i][j]+=dp[i-1][j];
            }
        }
    }
    for(int i=n-1;~i;--i)
    {
        for(int j=0;j<26;++j)
        {
            // if(dp[i][j]>0)
            // {
            //     sum+=dp[i][j];
            //     break;
            // }
            sum+=(dp[i][j]>=1);
        }
    }
    // for(int i=0;i<26;++i)
    // {
    //     if(dp[n-1][i]>0)
    //     {
    //         sum-=dp[n-1][i];
    //         break;
    //     }
    // }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<26;++j)
        {
            dp[i][j]=0;
        }
    }
    cout<<sum<<"\n";
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