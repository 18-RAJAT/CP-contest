#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+1;
int n;
string s;
int LC[N],RC[N];
int dp[N];
void sol()
{
    cin>>n;
    cin>>s;
    function<int(int)>dfs=[&](int val)->int
    {
        if(LC[val]==0 && RC[val]==0)
        {
            dp[val]=0;
        }
        // if(dp[val]!=-1)
        // {
        //     return dp[val];
        // }
        int &get=dp[val];
        if(LC[val])
        {
            dp[val]=min<int>(get,dfs(LC[val])+(s[val]!='L'));
        }
        if(RC[val])
        {
            dp[val]=min<int>(get,dfs(RC[val])+(s[val]!='R'));
        }
        return get;
    };
    s="#"+s;
    for(int i=1;i<=n;++i)
    {
        dp[i]=1e9;
    }
    for(int i=1;i<=n;++i)
    {
        cin>>LC[i]>>RC[i];
    }
    cout<<dfs(1)<<endl;
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