#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int dp[500010][105];
int a,b,k,t;
int recur(int x,int y)
{
    if(y==0)
    {
        return(x-N>=1)?1:0;
    }
    int& ret=dp[x][y];
    if(~ret)return ret;
    ret=0;
    for(int i=-k;i<=k;++i)//limit 1
    {
        for(int j=-k;j<=k;++j)//limit 2
        {
            ret+=recur(x+i-j,y-1)%1000000007;
        }
    }
    return ret%1000000007;
}
void sol()
{
    cin>>a>>b>>k>>t;
    memset(dp,-1,sizeof(dp));
    cout<<recur(a-b+N,t);
}
signed main()
{
    sol();
    return 0;
}