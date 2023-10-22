#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int x=1,ans=0;
    int n=s.size();
    for(int i=0;i<n;++i)
    {
        if(s[i]=='0')
        {
            // x++;
            s[i]=10+'0';
        }
        // else
        // {
        //     ans=max(ans,x);
        //     x=1;
        // }
    }
    for(int i=0;i<n;++i)
    {
       ans+=abs((s[i]-'0')-x);
       ans++;
       x=s[i]-'0';
    }
    cout<<ans<<"\n";
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