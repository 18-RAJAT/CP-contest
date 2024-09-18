#include<bits/stdc++.h>
using namespace std;
#define int long long

void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<bool>>dp(n,vector<bool>(n,0));
    int maxLength=1,start=0;
    for(int i=0;i<n;++i)
    {
        dp[i][i]=1;
    }
    for(int i=0;i<n-1;++i)
    {
        if(s[i]==s[i+1])
        {
            dp[i][i+1]=1;
            maxLength=2;
            start=i;
        }
    }

    for(int len=3;len<=n;++len)
    {
        for(int i=0;i<n-len+1;++i)
        {
            int j=i+len-1;
            if(s[i]==s[j] && dp[i+1][j-1])
            {
                dp[i][j]=1;
                if(maxLength<len)
                {
                    maxLength=len;
                    start=i;
                }
            }
        }
    }
    cout<<maxLength<<endl;
    cout<<s.substr(start,maxLength)<<endl;
}

signed main() {
    sol();
    return 0;
}