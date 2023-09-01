#include<bits/stdc++.h>
using namespace std;
#define int long long
int sol()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    if(a[0]==a[1])
    {
        cout<<a[0]+a[n-1]<<endl;
        return 0;
    }
    if(is_sorted(a.begin(),a.end()))
    {
        cout<<0<<"\n";
        return 0;
    }
    //is reverse sorted then 1;
    vector<int>dp;
    dp.push_back(0);
    dp.push_back(1);
    //pruning
    if(n==2)
    {
        cout<<1<<"\n";
        return 0;
    }
    //base case
    // if(a[0]>a[1])
    // {
    //     dp.push_back(1);
    // }
    // else
    // {
    //     dp.push_back(0);
    // }

    //cache check 1
    if(dp[n-1]==dp[n-2])
    {
        return dp[n-1];
    }
    //cache check 2
    // if(dp[n-1]!=-1)
    // {
    //     return dp[n-1];
    // }

    for(int i=2;i<=n;++i)
    {
        //transition
        dp.push_back(dp[i-1]+i);
        dp.erase(unique(dp.begin(),dp.end()),dp.end());
    }
    for(int i=0;i<=n;++i)
    {
        // cout<<dp[i]<<" ";
        if(dp[i]>=n)
        {
            cout<<i-1<<"\n";
            return 0;
        }
    }
    assert(dp[n]>=n);
    /*
        5 4 3 2 5 1
        
        compute
        1 2 3 4 5 5
        1 2 3 4 5 5
        1 2 3 4 5 5
    */
    return 0;
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