#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    if((n&1) && n<27)
    {
        cout<<-1<<endl;
        return;
    }
    int count=1;
    vector<int>dp(n+1,0);
    if(n&1)
    {
        dp[1]=dp[10]=dp[26]=1;
        dp[23]=dp[27]=2;
        count=3;
        for(int i=3;i<=9;i+=2)
        {
            dp[i]=dp[i-1]=count;
            count++;
        }
        for(int i=12;i<=22;i+=2)
        {
            dp[i]=dp[i-1]=count;
            count++;
        }
        dp[24]=count;
        dp[25]=count;
        count++;
        for(int i=29;i<=n;i+=2)
        {
            dp[i]=dp[i-1]=count;
            count++;
        }
    }
    else
    {
        for(int i=2;i<=n;i+=2)
        {
            dp[i]=dp[i-1]=count;
            count++;
        }
    }
    for(int i=1;i<=n;++i)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
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