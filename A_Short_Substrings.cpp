#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    string ans="";
    for(int i=0;i<n;i+=2)
    {
        ans+=s[i];
    }
    if(n<3)
    {
        cout<<s<<'\n';
    }
    else
    {
        cout<<ans+s[n-1]<<'\n';
    }
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