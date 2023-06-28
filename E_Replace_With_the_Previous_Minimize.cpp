#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;
        string s;cin>>s;
        int dp[100001];

        if(k>27)
        {
            for(int i=0;i<n;++i)
            {
                cout<<"a";
            }
            cout<<"\n";
            continue;
        }
        for(int i='a';i<='z';++i)
        {
            dp[i]=0;
        }
        for(int i=0;i<n;++i)
        {
            while(s[i]>'a' && !dp[s[i]] && k)
            {
                dp[s[i]]=1;--k;--s[i];
            }
        }
        for(int i=0;i<n;++i)
        {
            while(s[i]>'a' && dp[s[i]])
            {
                --s[i];
            }
        }
        cout<<s<<"\n";
    }
    return (0-0);
}