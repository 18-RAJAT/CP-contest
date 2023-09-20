#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    string a,b;
    cin>>a>>b;
    int dp[26][2];//Y/N
    memset(dp,0,sizeof(dp));
    for(auto&it:a)
    {
        dp[it-'a'][0]++;
    }
    for(auto&it:b)
    {
        dp[it-'a'][1]++;
    }
    int tmp[26];
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<26;++i)
    {
        tmp[i]=dp[i][0]-dp[i][1];
    }
    int cnt=0;
    for(int i=0;i<26;++i)
    {
        if((tmp[i])%k!=0)
        {
            cout<<"No\n";
            cnt++;
            return;
        }
    }
    if(cnt) return;
    int sum=0;
    for(int i=0;i<26;++i)
    {
        sum+=tmp[i];
        if(sum<0)
        {
            cout<<"No\n";
            cnt++;
            return;
        }
    }
    if(cnt) return;
    cout<<"Yes\n";
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