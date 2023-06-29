#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long dp[501][501];
    string s;
    function<long long(long long,long long)>func=[&](long long l,long long r)->long long
    {
        if(dp[l][r]!=-1)
        {
            return dp[l][r];
        }
        if(r<l)
        {
            return 0;
        }
        if(l==r)
        {
            return 1;
        }
        long long ans=func(l+1,r)+1;
        for(long long i=l+1;i<=r;++i)
        {
            if(s[l]==s[i])
            {
                ans=min<long long>(ans,func(l+1,i-1)+func(i,r));
            }
        }
        return dp[l][r]=ans;
    };
    function<void()>sol=[&]()
    {
        long long n;
        cin>>n>>s;
        memset(dp,-1,sizeof(dp));
        cout<<func(0,n-1);
    };
    while(true)
    {
        sol();
        return 0;
    }
}