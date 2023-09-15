#include<bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,int>dp[1005][1005],cache[1005][1005];
int recur(int n,int m,int k)
{
    if(k<0)
    {
        return 0;
    }
    int &ans=dp[n][m][k];
    int &c=cache[n][m][k];
    if(c)
    {
        return ans;
    }
    c=1;
    if(n<=1 && m<=1)
    {
        ans=(k==0);
        return ans;
    }
    if(n>=2)
    {
        if(recur(n-1,m,k-m))
        {
            return ans=1;
        }
    }
    if(m>=2)
    {
        if(recur(n,m-1,k-n))
        {
            return ans=1;
        }
    }
    // return ans=recur(n-1,m,k-1)+recur(n,m-1,k-1);
    return ans;
    assert(dp[n][m][k]<=1e18 && dp[n][m][k]>=0);
}
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    cout<<(recur(n,m,k)?"YES":"NO")<<endl;
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