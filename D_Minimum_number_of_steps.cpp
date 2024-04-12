#include<bits/stdc++.h>
using namespace std;
#define int long long
array<pair<int,int>,1000005>dp;
void sol()
{
    string s;
    cin>>s;
    dp[0].first=0;
    dp[0].second=0;
    dp[1].first=1;
    dp[1].second=1;
    for(int i=2;i<=1000005;++i)
    {
        dp[i].first=1+dp[i-1].first+dp[dp[i-1].second].first;
        dp[i].first%=1000000007;
        dp[i].second=dp[dp[i-1].second].second+1;
        dp[i].second%=1000000007;
    }
    int ans=0;
    int count_a=0;
    for(int i=0;i<s.size();++i)
    {
        ((s[i]=='a')?count_a++:(ans+=dp[count_a].first,ans%=1000000007,count_a=dp[count_a].second));
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}