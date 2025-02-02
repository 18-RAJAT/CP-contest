#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int l=s.size();
    vector<int>dp(l),dp1(l);
    for(int i=0;i<l;++i)((s[i]=='0')?(dp[i]=0,dp1[i]=1):(dp[i]=1,dp1[i]=0));
    while(l>1)
    {
        int r=l/3;
        vector<int>ndp(r),ndp1(r);
        for(int i=0;i<r;++i)
        {
            int x=3*i;
            //x->x+1->x+2,x+1->x+2,x+2
            ndp[i]=min({dp[x]+dp[x+1],dp[x]+dp[x+2],dp[x+1]+dp[x+2]});
            // cout<<ndp[i]<<" ";last
            ndp1[i]=min({dp1[x]+dp1[x+1],dp1[x]+dp1[x+2],dp1[x+1]+dp1[x+2]});
            // cout<<ndp1[i]<<" ";
        }
        dp.swap(ndp),dp1.swap(ndp1);
        l=r;
    }
    cout<<(dp[0]?dp[0]:dp1[0])<<endl;
}
signed main()
{
    sol();
    return 0;
}