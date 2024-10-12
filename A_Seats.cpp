#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    string s;
    cin>>n>>s;
    int ans=0;
    for(int i=0;i<=n-3;++i)
    {
        if(s[i]=='#' && s[i+1]=='.'&&s[i+2]=='#')ans++;
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}