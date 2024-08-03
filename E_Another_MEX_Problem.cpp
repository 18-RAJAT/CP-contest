#include<bits/stdc++.h>
using namespace std;
#define int long long
int mex;
vector<int>fz(5001);
int ok(int a)
{
    return fz[a]==1 && a<mex;
}
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(5001,0));
    dp[0][0]=1;
    for(int i=0;i<n;++i)
    {
        dp[i+1]=dp[i];
        for(int j=i;j>=0;--j)
        {
            fz[a[j]]++;
            while(fz[mex])mex++;
            if(ok(a[i]) && ok(a[j]))
            {
                vector<int>ndp(dp[i+1]);
                for(int k=0;k<5001;++k)
                {
                    if(dp[j][k])ndp[k^mex]=1;
                }
                dp[i+1]=move(ndp);
            }
        }
        for(int j=0;j<=i;++j)fz[a[j]]--;
        mex=0;
    }
    auto it=find_if(dp[n].rbegin(),dp[n].rend(),[&](int x){return x==1;});
    cout<<distance(it,dp[n].rend())-1<<endl;
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