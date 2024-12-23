#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<int>l(n),r(n);
    vector<vector<int>>adj(n,vector<int>(n)),dp(n,vector<int>(1<<n,1e9));
    for(int i=1;i<=q;++i)
    {
        int x;
        cin>>x;
        char s;
        cin>>s;
        x--;
        (s=='+')?r[x]++:l[x]++;
        for(int j=0;j<n;++j)
        {
            if(j!=x)
            {
                adj[j][x]=max(adj[j][x],r[j]-l[x]);
                adj[x][j]=max(adj[x][j],r[x]-l[j]);
            }
        }
    }
    for(int i=0;i<n;++i)dp[i][1LL<<i]=1;
    for(int i=0;i<1LL<<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(!(i&(1LL<<j)))continue;
            else
            {
                for(int k=0;k<n;++k)
                {
                    dp[j][i]=min(dp[j][i],dp[k][i-(1LL<<j)]+adj[k][j]+1);
                }
            }
        }
    }
    int ans=1e9;
    for(int i=0;i<n;++i)ans=min(ans,r[i]+dp[i][(1LL<<n)-1]);
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}