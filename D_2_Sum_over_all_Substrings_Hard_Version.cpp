#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<pair<int,int>>dp(3);//f0,f1,f2
    int count=0;
    int ans=0;
    for(int i=0;i<s.size();++i)
    {
        dp.clear();
        vector<pair<int,int>>cache_dp(3);
        cache_dp.clear();
        if(s[i]=='0')
        {
            // for 1
            cache_dp[1].first+=dp[0].first;
            // for 0
            cache_dp[1].second+=dp[0].second;
            // for 0
            cache_dp[2].first+=dp[1].first;
            // for 1
            cache_dp[2].second+=dp[1].second;
            //for 0
            cache_dp[2].first+=dp[2].first;
            //for 0
            cache_dp[2].second+=dp[2].second;
        }
        else
        {
            // for 1
            cache_dp[1].first+=dp[0].first;
            // for 0
            cache_dp[1].second+=dp[0].second;
            // for 0
            cache_dp[2].first+=dp[1].first;
            // for 1
            cache_dp[2].second+=dp[1].second;
            //for 0
            cache_dp[0].first+=dp[2].first;
            //for 1
            cache_dp[0].second+=dp[2].second+dp[2].first;
            // cache_dp[0].first+=dp[0].first;
        }
        swap<vector<pair<int,int>>>(dp,cache_dp);
        if(s[i]=='0')
        {
            //count of 0
            // dp[0].first++;
            dp[2].first++;
            // dp[0].second+=ans;
        }
        else if(s[i]=='1')
        {
            dp[0].first++;
            // dp[1].first++;
            dp[0].second++;
            // dp[1].second+=dp[0].first;
            // dp[2].second+=dp[0].second;
            // ans+=dp[0].first;
        }
        for(int j=0;j<3;++j)
        {
            count+=dp[j].first;
            ans+=dp[j].second;
        }
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