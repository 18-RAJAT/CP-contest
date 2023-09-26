#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<int>ans,dp;
    ans.push_back(0);
    int start=a[0];
    int tmp=0;
    dp.push_back(a[0]);
    for(int i=1;i<n;++i)
    {
        start+=a[i];
        tmp=0;
        int x=0;
        // int lst=i-1;
        int rem=start;
        while(rem>m)
        {
            sort(dp.rbegin(),dp.rend());
            // start-=a[lst];
            rem-=dp[x];
            // lst--;
            x++;
            tmp++;
            // y++;
        }
        dp.push_back(a[i]);
        ans.push_back(tmp);
    }
    for(auto& it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}