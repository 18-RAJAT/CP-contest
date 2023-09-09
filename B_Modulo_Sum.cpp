#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[1005][1005][2];//idx,sum,call

int add(int x,int y,int m)
{
    return (((x%m)+(y%m))%m+m)%m;
}
// int sub(int x,int y,int m)
// {
//     return (((x%m)-(y%m))%m-m)%m;
// }

int sol(int idx,vector<int>&v,int m,int sum,int call)
{
    //base case
    if(idx==v.size())
    {
        int ans=(sum%m==0 && call>0);
        return ans;
    }
    //pruning
    if(~dp[idx][sum][call])
    {
        return dp[idx][sum][call];
    }
    //recursive case
    //take
    int take=sol(idx+1,v,m,add(sum,v[idx],m),1);//call=1 means we have taken atleast one element
    //not take
    int not_take=sol(idx+1,v,m,sum,call);//call=0 means we have not taken any element
    
    int &ans=dp[idx][sum][call];
    int chk=take || not_take;
    //return
    return ans=chk;

    assert(dp[idx][sum][call]!=-1 && ~dp[1][1][0] && ~dp[1][1][1] && ~dp[1][0][0] && ~dp[1][0][1] && ~dp[0][1][0] && ~dp[0][1][1] && ~dp[0][0][0] && ~dp[0][0][1]);//chk if all values are filled or not
}
signed main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
    }
    if(n>m || sol(0,v,m,0,0) || m==0)//if n>m then we can always make sum%m=0
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}