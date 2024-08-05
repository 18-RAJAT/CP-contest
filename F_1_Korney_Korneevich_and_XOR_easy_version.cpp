#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=550;
int dp[N];
void sol()
{
    int n;
    cin>>n;
    for(int i=0;i<N;++i)dp[i]=1010;
    dp[0]=0;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        for(int j=0;j<N;++j)
        {
            if(dp[j]<x)dp[x^j]=min(dp[x^j],x);
        }
    }
    int ans=0;
    for(int i=0;i<N;++i)
    {
        if(dp[i]!=1010)ans++;
    }
    cout<<ans<<endl;
    for(int i=0;i<N;++i)
    {
        if(dp[i]!=1010) cout<<i<<" ";
    }
}
signed main()
{
    sol();
    return 0;
}