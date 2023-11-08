#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    vector<int>prefix(n,0);
    vector<int>suffix(n,0);
    for(int i=1;i<n;++i)
    {
        if(s[i]=='v' && s[i-1]=='v')
        {
            prefix[i]=1;
        }
        prefix[i]+=prefix[i-1];
    }
    for(int i=n-2;i>=0;--i)
    {
        if(s[i]=='v' && s[i+1]=='v')
        {
            suffix[i]=1;
        }
        suffix[i]+=suffix[i+1];
    }
    int ans=0;
    for(int i=1;i<n-1;++i)
    {
        if(s[i]=='o')
        {
            ans+=prefix[i-1]*suffix[i+1];
        }
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}