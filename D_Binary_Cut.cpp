#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    s.erase(unique(s.begin(),s.end()),s.end());
    int n=s.size();
    int ans=n;
    for(int i=0;i+1<n;++i)
    {
        if(s[i]=='0' && s[i+1]=='1'){ans--;break;}
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