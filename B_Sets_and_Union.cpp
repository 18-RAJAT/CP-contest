#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<vector<int>>a(n),dp(55);
    // a.resize(n+1);
    vector<int>ndp(55);
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        a[i].resize(x);
        for(int j=0;j<x;++j)
        {
            cin>>a[i][j];
            ndp[a[i][j]]++;
            dp[a[i][j]].push_back(i);
        }
    }
    int ans=0,cnt=0;
    for(auto& it:ndp)
    {
        if(it>0)
        {
            cnt++;
        }
    }
    for(int i=1;i<=50;++i)
    {
        if(!ndp[i])
        {
            continue;
        }
        int curr=cnt;
        for(auto& it:dp[i])
        {
            for(auto& itr:a[it])
            {
                // if(ndp[itr]==1)
                // {
                //     curr--;
                // }
                ndp[itr]--;
                if(!ndp[itr])
                {
                    curr--;
                }
            }
        }
        if(curr!=cnt)
        {
            ans=max<int>(ans,curr);
            for(auto&it:dp[i])
            {
                for(auto& itr:a[it])
                {
                    ndp[itr]++;
                }
                // cout<<"A: "<<a[it].size()<<endl;
            }
        }
    }
    cout<<ans<<endl;
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