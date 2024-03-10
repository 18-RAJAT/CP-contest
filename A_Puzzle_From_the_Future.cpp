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
    int prev=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]-'0'+1!=prev)
        {
            ans+='1';
            prev=1+s[i]-'0';
        }
        else
        {
            ans+='0';
            prev=0+s[i]-'0';
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