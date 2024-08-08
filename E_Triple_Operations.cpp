#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[200005];
void sol()
{
    int l,r;
    cin>>l>>r;
    cout<<2*(dp[l]-(l>=1?dp[l-1]:0))+(dp[r]-dp[l])<<endl;
}
signed main()
{
    for(int i=1;i<200005;++i)
    {
        int x=i;
        while(x>=1)x/=3,dp[i]++;
        if(i>=1)dp[i]+=dp[i-1];
    }
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}