#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[505][505];
int solve(int idx,int k,int l,int speed,vector<int>&distance,vector<int>&limit)
{
    if(k<0)
    {
        return 1e9;
    }
    if(idx==distance.size()-1)
    {
        return min((distance[idx]-l)*speed,limit[idx]*(distance[idx]-l));
    }
    int &ans=dp[idx][k];
    if(~ans)
    {
        return ans;
    }
    ans=1e9;
    ans=min<int>(ans,solve(idx+1,k,limit[idx],distance[idx+1]-distance[idx],distance,limit)+limit[idx]*(distance[idx+1]-distance[idx]));
    ans=min<int>(ans,solve(idx+1,k-1,speed,distance[idx+1]-distance[idx],distance,limit)+speed*(distance[idx+1]-distance[idx]));
    return ans;
}
void sol()
{
    int n,l,k;
    cin>>n>>l>>k;
    memset(dp,-1,sizeof dp);
    vector<int>distance(n);
    for(auto &it:distance)
    {
        cin>>it;
    }
    vector<int>limit(n);
    for(auto &it:limit)
    {
        cin>>it;
    }
    cout<<solve(0,k,l,limit[0],distance,limit)<<endl;
}
signed main()
{
    sol();
    return 0;
}