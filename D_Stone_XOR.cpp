#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int ans=1<<n;
    vector<int>ar(ans,0);
    for(int j=1;j<ans;++j)
    {
        //lsb->>then it will be 0
        int i=__builtin_ctzl(j),X=j^(1<<i);
        ar[j]=ar[X]+a[i];
    }
    vector<vector<int>>dp(ans);
    dp[0].push_back(0);
    vector<vector<int>>cnt(n+1);
    for(int i=0;i<ans;++i)cnt[__builtin_popcountl(i)].push_back(i);
    for(int c=1;c<=n;++c)
    {
        for(auto& it:cnt[c])
        {
            int i=__builtin_ctzl(it),msk=1LL<<i;
            vector<int>ok;
            int t=it;
            while(true)
            {
                if(t!=0 && (t&msk))
                {
                    int r=it^t,tmp=ar[t];
                    for(auto& x:dp[r])ok.push_back(x^tmp);
                }
                if(t==0)break;
                t=(t-1)&it;
            }
            sort(ok.begin(),ok.end());
            ok.erase(unique(ok.begin(),ok.end()),ok.end());
            dp[it]=move(ok);
        }
    }
    cout<<dp[ans-1].size()<<endl;
}
signed main()
{
    sol();
    return 0;
}