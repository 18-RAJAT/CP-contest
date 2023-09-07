#include<bits/stdc++.h>
using namespace std;
#define int long long
const long long inf=1e18;

int dp[5005][5005];
int recur(int idx,int k,vector<int>&v,int end)
{
    //base case.
    if(idx==v.size())
    {
        //pruning.
        return(k<0)?-inf:0;
    }
    //reference.
    int &ans=dp[end][k];
    if(~ans)//!=-1 case
    {
        return ans;
    }
    //recursive assumption.
    int res1=recur(idx+1,k,v,end),res2=-inf;
    //transitions
    if(end!=5001 && v[idx]-v[end]<=5 && idx!=0)
    {
        //func1 call
        res2=recur(idx+1,k,v,end)+1;//till of idx+1.
    }
    else
    {
        //func2 call
        res2=recur(idx+1,k-1,v,idx)+1;//vice versa.
    }
    //update the ans.
    return ans=max(res1,res2);//save and return.

    assert(dp[0][0]!=0);
}
signed main()
{
    int n,k;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    vector<int>v(n);
    for(auto &it:v)cin>>it;
    sort(v.begin(),v.end());
    // for(int i=0;i<n;++i)
    // {
    //     if(i==0||v[i]-v[i-1]>5)
    //     {
    //         chk.push_back(i);
    //     }
    // }
    cout<<recur(0,k,v,5001)<<endl;
    return 0;
}