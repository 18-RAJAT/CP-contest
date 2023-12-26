#include<bits/stdc++.h>
using namespace std;
#define int long long
int memo(int i,int n,int ndp[],vector<vector<int>>&dp,int check)
{
    //base case
    if(i==n || i==n+1)
    {
        return 0;
    }
    int& ret=dp[i][check];
    // pruning step
    if(~ret)
    {
        return ret;
    }
    int take=INT_MAX,not_take=INT_MAX;
    //rec step
    if(check==0)
    {
        if(ndp[i]==1)
        {
            take=1+memo(i+1,n,ndp,dp,1);
        }
        else
        {
            take=memo(i+1,n,ndp,dp,1);
        }
        //check for i+1 and i+2 if they are in range or not
        if(i<n)//1
        {
            int calc=0;
            calc+=(ndp[i]==1?1:0);
            calc+=(ndp[i+1]==1?1:0);
            if(calc==2)
            {
                not_take=memo(i+2,n,ndp,dp,0);
            }
            else
            {
                not_take=memo(i+1,n,ndp,dp,0);
            }
            not_take=calc+memo(i+2,n,ndp,dp,1);
        }
    }
    else
    {
        //take the current element and check for i+1 and i+2 if they are in range or not similarly for not_take case also
        take=memo(i+1,n,ndp,dp,0);
        not_take=memo(i+2,n,ndp,dp,0);
    }
    return ret=min<int>(take,not_take);
}
void sol()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<vector<int>>dp(n,vector<int>(2,-1));
    assert(~memo(0,n,a,dp,0));
    cout<<memo(0,n,a,dp,0)<<endl;
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