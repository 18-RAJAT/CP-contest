#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,p;
    cin>>n>>p;
    int dp[n+1];
    fill(dp,dp+n+1,0);
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    int count=0;
    for(int i=4;i<=n;++i)
    {
        if((i&(i-1))==0)
        {
            dp[i]=((i*dp[i-1])+i)%p;
            count=0;
        }
        else
        {
            dp[i]=(((count*dp[i-count])%p)+(((i-count)*(count+1)*(dp[i-count-1]))%p))%p;
            count++;
        }
    }
    cout<<dp[n]%p<<endl;
}
signed main()
{
    sol();
    return 0;
}