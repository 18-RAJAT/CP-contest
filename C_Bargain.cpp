#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    array<int,100005>dp;
    dp.fill(0);
    int n=s.size();
    for(int i=0;i<n;++i)
    {
        dp[i]=s[i]-'0';
    }
    int ans=0,sum=0,computation=1;
    for(int i=n-1;~i;--i)
    {
        int next_computation=(i*(i+1)/2%1000000007*computation%1000000007+sum);
        sum=(sum+computation*(n-i)%1000000007);
        //10^i R->L
        computation=computation*10%1000000007;
        //each digit contributes to the answer
        ans=(ans+dp[i]*next_computation%1000000007);
    }
    cout<<ans%1000000007;
}
signed main()
{
    sol();
    return 0;
}