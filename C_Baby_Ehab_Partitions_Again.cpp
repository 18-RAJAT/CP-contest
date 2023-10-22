#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    int sum=0;
    a.resize(n+1);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    //Checks whether there is a subset whose sum is sum/2 or not
    auto check_state=[&]()
    {
        if(sum&1)
        {
            return false;
        }
        vector<bool>dp(sum+1,false);
        dp[0]=true;
        for(int i=1;i<=n;++i)
        {
            // for(int j=a[i];j<=sum;++j)
            for(int j=sum;j>=a[i];--j)
            {
                dp[j]=dp[j]|dp[j-a[i]];//for each element we have two choices either to take it or not
            }
        }
        return dp[sum/2]?true:false;
    };
    if(sum&1)
    {
        cout<<"0\n";
        return;
    }
    if(check_state())
    {
        int G=0;
        for(int i=1;i<=n;++i)
        {
            G=__gcd(G,a[i]);
        }
        assert(G>=1);
        for(int i=1;i<=n;++i)
        {
            a[i]/=G;
        }
        int id=-1;
        // assert(!check_state());
        for(int i=1;i<=n;++i)
        {
            if(a[i]&1)
            {
                id=i;
            }
        }
        assert(~id);
        cout<<"1\n";
        cout<<id<<"\n";
    }
    else
    {
        cout<<"0\n";
    }
}
signed main()
{
    sol();
    return 0;
}