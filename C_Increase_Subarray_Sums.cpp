#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        vector<int>a(n);
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        vector<int>ans(n+1,0),dp(n+1,0);
        for(int i=0;i<n;++i)
        {
            vector<int>ndp(n+1,-INF);
            for(int j=0;j<n+1;++j)
            {
                ndp[j]=max<int>(0,dp[j]+a[i]);
                if(j)
                {
                    ndp[j]=max<int>(ndp[j],dp[j-1]+a[i]+x);
                }
                ans[j]=max<int>(ans[j],ndp[j]);
            }
            dp.swap(ndp);
        }
        for(int i=0;i<n+1;++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}