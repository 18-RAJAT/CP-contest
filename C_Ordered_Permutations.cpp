#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int dp[41];
    dp[0]=1;
    for(int i=1;i<=40;++i)
    {
        dp[i]=2*dp[i-1];
        if(dp[i]>1e12)dp[i]=1e12+1;
    }
    int n,k;
    cin>>n>>k;
    int res=(n-1>=40)?1e12+1:(n-1>=0?dp[n-1]:1);
    if(k>res)
    {
        cout<<-1<<endl;
        return;
    }
    vector<int>L,R;
    int ans=1;
    for(int i=1;i<=n;++i)
    {
        int tmp=n-i,cnts=(tmp>=1?(tmp-1<=40 && tmp-1>=0?dp[tmp-1]:1e12+1):1);
        if(k<=cnts)L.push_back(ans);
        else
        {
            R.push_back(ans);
            k-=cnts;
        }
        ans++;
    }
    // sort(R.begin(),R.end());
    reverse(R.begin(),R.end());
    for(auto& it:L)cout<<it<<" ";
    for(auto& it:R)cout<<it<<" ";
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