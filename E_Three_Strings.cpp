#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string a,b,c;
    cin>>a>>b>>c;
    int n=a.size(),m=b.size();
    vector<int> dp(m+1,0),ndp(m+1,0);
    for(int j=1;j<=m;++j)dp[j]=dp[j-1]+(b[j-1]!=c[j-1]);
    for(int i=1;i<=n;++i)
    {
        ndp[0]=dp[0]+(a[i-1]!=c[i-1]);
        for(int j=1;j<=m;++j)
        {
            ndp[j]=min(dp[j]+(a[i-1]!=c[i+j-1]),ndp[j-1]+(b[j-1]!=c[i+j-1]));
        }
        swap(dp,ndp);
    }
    cout<<dp[m]<<endl;
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