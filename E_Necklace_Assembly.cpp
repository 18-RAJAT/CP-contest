#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>dp(26);
    function<int(int,int)>gcd=[&](int a,int b)->int
    {
        return(a%b)?gcd(b,a%b):b;
    };
    auto convert=[&](char c)->int
    {
        return c-'a';
    };
    for(int i=0;i<n;++i)
    {
        char c;
        cin>>c;
        dp[convert(c)]++;  
    }
    int ans=1;
    for(int i=2;i<=n;++i)
    {
        int G=gcd(i,k);
        int x=0;
        for(auto& it:dp)
        {
            x+=it/(i/G);
            if(x>=G)
            {
                ans=i;
            }
        }
    }
    cout<<ans<<'\n';
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