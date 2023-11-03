#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    char ch[n];
    for(int i=0;i<n;++i)
    {
        cin>>ch[i];
    }
    int dp[2];
    dp[0]=dp[1]=0;
    int extra_char='1';
    for(int i=0;i<n;i+=2)
    {
        auto check=[&]()->bool
        {
            return ch[i]!=ch[i+1]?true:false;
        };
        if(check())
        {
            dp[0]++;
            ch[i]=extra_char;
            ch[i+1]=extra_char;
        }
        extra_char=ch[i];
    }
    for(int i=0;i<n-1;++i)
    {
        auto check=[&]()->bool
        {
            return ch[i]!=ch[i+1]?true:false;
        };
        if(check())
        {
            dp[1]++;
        }
    }
    // int mx=max(1LL,1+dp[1]);
    cout<<dp[0]<<" "<<1+dp[1]<<"\n";
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