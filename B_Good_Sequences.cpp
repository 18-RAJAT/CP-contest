#include<bits/stdc++.h>
using namespace std;
#define int long long

void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<int>dp(100001,0);
    int maximum=0;
    for(int i=0;i<n;++i)
    {
        int current=1LL;
        for(int j=1;j<=sqrt(a[i]);++j)
        {
            if(a[i]%j==0)
            {
                current=max<int>(current,dp[a[i]/j]+1);
                current=max<int>(current,dp[j]+1);
            }
        }
        dp[i]=current;
        maximum=max<int>(maximum,dp[i]);
    }
    cout<<maximum;
}
signed main()
{
    sol();
    return 0;
}