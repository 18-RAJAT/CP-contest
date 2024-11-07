#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    s=' '+s;
    vector<int>dp(n+1,0),ndp(n+1,0),a(n+1,0);
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='(')ndp[++ans]=i;
        else
        {
            if(ans)
            {
                if(ans>=1)dp[a[i]=1+i-ndp[ans]+a[ndp[ans]-1]]++,ans--;
            }
        }
    }
    dp[0]=1;
    for(int i=n;~i;--i)
    {
        if(dp[i])
        {
            cout<<i<<' '<<dp[i];
            return;
        }
    }
}
signed main()
{
    sol();
    return 0;
}