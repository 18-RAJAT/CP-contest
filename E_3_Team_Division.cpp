#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<pair<int,int>>a(n);
    int sum=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first>>a[i].second;
        sum+=a[i].second;
    }
    if(sum%3!=0)
    {
        cout<<-1<<endl;
        return;
    }
    int div=sum/3;
    vector<vector<int>>dp(div+1,vector<int>(div+1,INT_MAX));
    dp[0][0]=0;
    for(int i=0;i<n;++i)
    {
        int x=a[i].first,y=a[i].second;
        vector<vector<int>>ndp(div+1,vector<int>(div+1,INT_MAX));
        for(int j=0;j<=div;++j)
        {
            for(int k=0;k<=div;++k)
            {
                if(dp[j][k]==INT_MAX)continue;
                if(j+y<=div)
                {
                    int sw=(x!=1)?1:0;
                    ndp[j+y][k]=min(ndp[j+y][k],dp[j][k]+sw);
                }
                if(k+y<=div)
                {
                    int sw=(x!=2)?1:0;
                    ndp[j][k+y]=min(ndp[j][k+y],dp[j][k]+sw);
                }
                int sw=(x!=3)?1:0;
                ndp[j][k]=min(ndp[j][k],dp[j][k]+sw);
            }
        }
        dp=move(ndp);
    }
    if(dp[div][div]==INT_MAX)cout<<-1<<endl;
    else cout<<dp[div][div]<<endl;
}
signed main()
{
    sol();
    return 0;
}