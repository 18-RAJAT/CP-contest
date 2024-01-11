#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    if(k==1)
    {
        cout<<s<<endl;
        return;
    }
    if(s[0]!=s[k-1])
    {
        cout<<s[k-1]<<endl;
        return;
    }
    string ans="";
    if(s[n-1]!=s[k])
    {
        ans+=s[0];
        for(int i=k;i<n;++i)
        {
            ans+=s[i];
        }
    }
    else
    {
        ans+=s[0];
        for(int i=k;i<n;i+=k)
        {
            ans+=s[i];
        }
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