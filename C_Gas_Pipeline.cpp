#include<bits/stdc++.h>
using namespace std;
#define int long long
int recur(int i,string s,int pipe,int pillar,int last,vector<vector<int>>&dp)
{
    int calc1=10e10;
    int calc2=10e10;
    //memoization
    int &ans=dp[i][last];
    if(~ans)
    {
        return ans;
    }
    //base case
    if(s.length()==0)
    {
        return dp[i][last]=0;
    }
    if(s.length()==1)
    {
        if(last==1)
        {
            calc1=pillar+2*pipe;
        }
        else
        {
            calc1=pillar+pipe;
        }
        return dp[i][last]=calc1;
    }
    if(s.length()>=2 && s[0]=='0' && s[1]=='0')
    {
        //the last one was a pillar
        if(last==1)
        {
            //use pipe
            calc1=2*pillar+pipe+recur(i+1,s.substr(1),pipe,pillar,1,dp);
            calc2=2*pipe+pillar+recur(i+1,s.substr(1),pipe,pillar,0,dp);
        }
        else
        {
            //the last one was a pipe
            calc1=pillar+pipe+recur(i+1,s.substr(1),pipe,pillar,0,dp);
            calc2=2*pipe+2*pillar+recur(i+1,s.substr(1),pipe,pillar,1,dp);
        }
        return dp[i][last]=min(calc2,calc1);
    }
    else if(s.length()>=2 && s[0]=='0' && s[1]=='1')
    {
        if(last==1)
        {
            //use pipe
            calc1=2*pillar+pipe+recur(i+1,s.substr(1),pipe,pillar,1,dp);
        }
        else
        {
            //use pillar
            calc2=2*pillar+2*pipe+recur(i+1,s.substr(1),pipe,pillar,1,dp);
        }
        return dp[i][last]=min(calc2,calc1);
    }
    else if(s.length()>=2 && s[0]=='1' && s[1]=='0')
    {
        if(last==1)
        {
            calc1=2*pillar+pipe+recur(i+1,s.substr(1),pipe,pillar,1,dp);
        }
        return dp[i][last]=min(calc2,calc1);
        // cout<<dp[i][last]<<endl;
    }
    else if(s.length()>2 && s[0]=='1' && s[1]=='1')
    {
        if(last==1)
        {
            calc1=2*pillar+pipe+recur(i+1,s.substr(1),pipe,pillar,1,dp);
        }
        return dp[i][last]=min(calc2,calc1);//the state of the last one is not changing
    }
    else if(s.length()>=2 && s[0]=='1' && s[1]=='0')
    {
        if(last==1)
        {
            calc1=2*pillar+pipe+recur(i+1,s.substr(1),pipe,pillar,1,dp);
        }
        return dp[i][last]=min(calc2,calc1);
        // cout<<dp[i][last]<<endl;
    }
    else if(s.length()>2 && s[0]=='1' && s[1]=='1')
    {
        if(last==1)
        {
            calc1=2*pillar+pipe+recur(i+1,s.substr(1),pipe,pillar,1,dp);
        }
        return dp[i][last]=min(calc2,calc1);//the state of the last one is not changing
    }
    assert(dp[i][last]!=-1 && dp[i][last]!=1e15 && pillar!=1e15 && pipe!=1e15);//assertion
}
void sol()
{
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    int ans=b;
    vector<vector<int>>dp(n+1,vector<int>(2,-1));
    ans+=recur(0,s.substr(0),a,b,0,dp);
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