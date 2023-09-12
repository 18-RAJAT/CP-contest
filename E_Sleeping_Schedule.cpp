#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,h,l,r;
int dp[2005][2005];
vector<int>a;
int sol(int idx,int time)//time is here currentTime.
{
    int &ans=dp[idx][time];
    //cache check
    if(~ans)
    {
        return ans;
    }
    //base case
    if(idx==a.size())
    {
        return ans=(time>=l && time<=r);//if time is in range then return 1 else 0.
    }
    // else if(idx==a.size()-1)
    // {
    //     return ans=1+((time>=l && time<=r)?1:0);
    // }
    return ans=(time>=l && time<=r)+max(sol(idx+1,(time+a[idx])%h),sol(idx+1,(time+a[idx]-1)%h));
    
    assert(~dp[idx][time]);//pruning optimization calc.
}
signed main()
{
    cin>>n>>h>>l>>r;
    a.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bool ok=false;
    if(l==0)
    {
        ok=true;
    }
    memset(dp,-1,sizeof(dp));
    cout<<sol(0,0)-ok<<endl;
    return 0;
}