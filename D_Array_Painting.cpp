#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=2e18+5;
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<int>b={a[0]};
    for(int i=1;i<n;++i)
    {
        if(a[i]==0)
        {
            b.push_back(0);
        }
        else if(b.back()==0)
        {
            b.push_back(a[i]);
        }
        else
        {
            //simplify
            auto maxi=[&](int a,int b)->void
            {
                if(a<b)
                {
                    a=b;
                }
            };
            maxi(b[b.size()-1],a[i]);
        }
    }
    int ans=0;
    int sza_b=b.size();
    vector<int>remain(sza_b+5,0);
    for(int i=0;i<sza_b;++i)
    {
        if(b[i]==2)
        {
            ans++;
            remain[i]=1;
            if(i>=1)
            {
                remain[i-1]=1;
            }
            // (i<sza_b-1?remain[i+1]=1:remain[0]=1);
            if(i<sza_b-1)
            {
                remain[i+1]=1;
            }
        }
    }
    vector<int>check={0};
    // check.assign(b.begin(),b.end());
    for(int i=0;i<b.size();++i)
    {
        if(!remain[i])
        {
            check.push_back(b[i]);
        }
        else
        {
            if(check.back()==-1)
            {
                continue;
            }
            else
            {
                check.push_back(-1);
            }
        }
    }
    int sza_check=check.size();
    vector<int>dp(sza_check+5,INF);
    dp[0]=0;
    dp[1]=(~check[1]);
    for(int i=2;i<sza_check;++i)
    {
        if(check[i]==-1)
        {
            dp[i]=dp[i-1];
            continue;
        }
        if(check[i]==0)
        {
            if(check[i-1]==1)
            {
                dp[i]=min<int>(dp[i-1],dp[i-2])+1;
            }
            else if(check[i-1]==0)
            {
                dp[i]=dp[i-1]+1;
            }
            else
            {
                dp[i]=dp[i-1]+1;
            }
        }
        else
        {
            if(check[i-1]==-1)
            {
                dp[i]=dp[i-1]+1;
            }
            else
            {
                dp[i]=min<int>(dp[i-1],dp[i-2])+1;
            }
        }
    }
    cout<<dp[sza_check-1]+ans<<endl;
}
signed main()
{
    sol();
    return 0;
}