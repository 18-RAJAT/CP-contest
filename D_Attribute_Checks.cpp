#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b;
    int mx=m*2+1;
    vector<vector<int>>dp(mx);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]==0)b.push_back(i);
        else dp[a[i]+m].push_back(i);
    }
    auto check=[&](int i,int j)->int
    {
        auto& compute=dp[j+m];
        return compute.size()-(lower_bound(compute.begin(),compute.end(),i)-compute.begin());
    };
    vector<vector<int>>ndp(m,vector<int>(m+1));
    ndp[0][0]=check(b[0],-1);
    ndp[0][1]=check(b[0],1);
    for(int i=1;i<m;++i)
    {
        ndp[i][0]=ndp[i-1][0]+check(b[i],-i-1);
        for(int j=1;j<=i+1;++j)
        {
            ndp[i][j]=max(ndp[i-1][j-1]+check(b[i],j),ndp[i-1][j]+check(b[i],j-i-1));
        }
    }
    int ans=0;
    for(auto &it:ndp.back())
    {
        ans=max(ans,it);
    }
    cout<<ans;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    sol();
    return 0;
}