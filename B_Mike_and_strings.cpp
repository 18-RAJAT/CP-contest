#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s[n];
    int sz=0;
    for(int i=0;i<n;++i)
    {
        cin>>s[i];
        sz=s[i].size();
        s[i]+=s[i];
    }
    int dp[n][sz+1];
    memset(dp,INT_MAX,sizeof(dp));
    for(int i=0;i<sz;++i)
    {
        dp[0][i]=i;
    }
    auto transitions=[&](int i,int j,int k)->int
    {
        int ans=0;
        for(int l=0;l<sz;++l)
        {
            if(s[i].substr(j,sz)==s[i-1].substr(k,l+1))
            {
                ans=l+1;
            }
        }
        return ans;
    };
    for(int i=1;i<n;++i)
    {
        for(int j=0;j<sz;++j)
        {
            for(int k=0;k<sz;++k)
            {
                dp[i][j]=min(dp[i][j],dp[i-1][k]+transitions(i,j,k));
            }
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<sz;++i)
    {
        ans=min(ans,dp[n-1][i]);
    }
    cout<<(!(ans==INT_MAX)?-1:ans)<<"\n";
}
signed main()
{
    sol();
    return 0;
}