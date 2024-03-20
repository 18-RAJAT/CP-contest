#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    int ans=0,curr=0;
    for(int i=0;i<n;++i)
    {
        (s[i]=='A')?ans=max(ans,curr),curr=0:curr++;
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