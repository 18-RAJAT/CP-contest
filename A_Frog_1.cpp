#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[100001];
vector<int>heights;
int recur(int level)
{
    if(level<=0)
    {
        return 0;
    }
    int &ert=dp[level];
    if(~ert)return ert;
    int ans=recur(level-1)+abs<int>(heights[level]-heights[level-1]);
    if(level>=2)
    {
        ans=min<int>(ans,recur(level-2)+abs<int>(heights[level]-heights[level-2]));
    }
    return ert=ans;
}
signed main()
{
    int n;
    cin>>n;
    heights.resize(n);
    for(int i=0;i<n;++i)cin>>heights[i];
    memset(dp,-1,sizeof(dp));
    cout<<recur(n-1);
    return 0;
}