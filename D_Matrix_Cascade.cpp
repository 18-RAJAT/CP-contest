#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<string>vs(n);
    for(int i=0;i<n;++i)
    {
        cin>>vs[i];
    }
    vector<vector<int>>dp(n,vector<int>(n)),ndp(n,vector<int>(n)),mid(n,vector<int>(n));
    int ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            int val=vs[i][j]-'0'+dp[i][j]+ndp[i][j]+mid[i][j];
            if(val&1)
            {
                ans++;
                mid[i][j]++;
            }
        }
        for(int j=0;j<n;++j)
        {
            if(i+1<n)
            {
                if(j-1>=0)
                {
                    ndp[i+1][j-1]+=mid[i][j]+ndp[i][j];
                }
                if(j+1<n)
                {
                    dp[i+1][j+1]+=mid[i][j]+dp[i][j];
                }
                mid[i+1][j]+=mid[i][j];
            }
            // cout<<dp[i][j]<<" "<<ndp[i][j]<<" "<<mid[i][j]<<" ";
        }
    }
    cout<<ans%1000000007<<endl;
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