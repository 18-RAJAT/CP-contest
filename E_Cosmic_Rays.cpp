#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    vector<array<int,2>>dp;
    for(int i=0;i<n;++i)
    {
        cin>>a[i]>>b[i];
        int mx=0;
        while(1)
        {
            while(dp.size()>=1 && dp.back()[0]<=a[i] && dp.back()[1]!=b[i])
            {
                mx=dp.back()[0];
                dp.pop_back();
            }
            if(dp.empty() || dp.back()[1]!=b[i])
            {
                dp.push_back({a[i],b[i]});
                break;
            }
            else
            {
                a[i]+=dp.back()[0]-mx;
                dp.pop_back();
                mx=0;
            }
        }
        assert(!dp.empty());
        cout<<dp[0][0]<<" ";
    }
    cout<<endl;
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