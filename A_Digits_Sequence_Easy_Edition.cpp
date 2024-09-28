#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string ans="";
    for(int i=1;i<=n;++i)
    {
        ans+=to_string(i);
    }
    cout<<ans[n-1];
}
signed main()
{
    sol();
    return 0;
}