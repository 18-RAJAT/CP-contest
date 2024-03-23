#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    int ans=-1;
    array<bool,3>dp;
    auto state=[&]()
    {
        return dp[0]||dp[1]||dp[2];
    };
    for(auto& it:s)
    {
        int val=(it-'0')%3;
        if(val==0)
        {
            dp[0]=true;
            dp[1]=dp[2]=false;
            ans++;
        }
        else if(val==1)
        {
            (dp[2]?dp[2]=false,dp[0]=true,ans++:dp[2]=true);
        }
        else
        {
            (dp[1]?dp[1]=false,dp[0]=true,ans++:dp[1]=true);
        }
    }
    if(state())
    {
        ans++;
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}