#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    int ans=0;
    vector<int>pref(n+1),suf(2*n+2);//r side
    for(int i=0;i<n;++i)
    {
        if(s[i]-'0')
        {
            pref[i+1]=pref[i]+1;
        }
        else
        {
            pref[i+1]=pref[i]-1;
        }
    }
    for(int i=1;i<=n;++i)
    {
        int prev=n+pref[i-1];
        suf[prev]+=i;
        int next=n+pref[i];
        int combinator=(n-i+1)*suf[next];
        ans=(ans+combinator)%1000000007;
    }
    cout<<ans<<endl;
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