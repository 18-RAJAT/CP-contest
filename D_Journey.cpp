#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>Left_dp(n,1),right_dp(n,1);
    for(int i=1;i<n;++i)
    {
        if(s[i]!=s[i-1])
        {
            Left_dp[i]+=Left_dp[i-1];
        }
    }
    for(int i=n-2;i>=0;--i)
    {
        if(s[i]!=s[i+1])
        {
            right_dp[i]+=right_dp[i+1];
        }
    }
    vector<int>state(n+1,1);
    for(int i=0;i<=n;++i)
    {
        if(i>=1 && s[i-1]=='L')
        {
            state[i]+=Left_dp[i-1];
        }
        if(i<n && s[i]=='R')
        {
            state[i]+=right_dp[i];
        }
    }
    for(int i=0;i<state.size();++i)
    {
        cout<<state[i]<<" "[i+1==state.size()];
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