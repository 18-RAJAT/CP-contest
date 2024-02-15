#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
vector<vector<int>>cache;
int dp[10005][10005];
vector<int>take,leave;
int func(int index,int taken)
{
    if(index==n || taken==k)
    {
        return 0;
    }
    int& ans=dp[index][taken];
    if(~ans)return ans;
    int res=0;
    res=max(res,func(index+1,taken));
    int leave_index=lower_bound(leave.begin(),leave.end(),take[index])-leave.begin();
    if(leave_index<leave.size())
    {
        res=max(res,1+func(index+1,taken+1));
    }
    return ans=res;
}
void sol()
{
    cin>>n>>k;
    cache.assign(k,vector<int>(n));
    for(auto& it:cache)
    {
        for(auto& itr:it)
        {
            cin>>itr;
        }
    }
    int ans=n;
    for(int i=0;i<k;++i)
    {
        for(int j=i+1;j<k;++j)
        {
            take=cache[i];
            leave=cache[j];
            memset(dp,-1,sizeof dp);
            ans=min(ans,func(0,0));
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}