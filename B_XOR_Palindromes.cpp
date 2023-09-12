#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string ans="";
    for(int i=0;i<=n;++i)
    {
        ans+='0';
    }
    int cnt1=0,cnt2=0;
    for(int i=0;i<n/2;++i)
    {
        if(s[i]==s[n-1-i])
        {
            cnt2++;
        }
        else
        {
            cnt1++;
        }
    }
    if(n&1)
    {
        ans[cnt1]='1';
        for(int i=1;i<=2*cnt2+1;++i)
        {
            ans[i+cnt1]='1';
        }
        // cout<<cnt1<<" "<<cnt2<<endl;
    }
    else
    {
        ans[cnt1]='1';
        for(int i=1;i<=cnt2;++i)
        {
            ans[2*i+cnt1]='1';
        }
        // cout<<ans[cnt1]<<endl;
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