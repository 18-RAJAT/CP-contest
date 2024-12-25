#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int>fz(26,0);
    for(int i=1;i<=n;++i) fz[s[i-1]-'A']++;
    sort(fz.begin(),fz.end(),greater<int>());
    int i=0,ans=0;
    for(;i<n && k>=1;)
    {
        int mn=min(fz[i],k);
        ans+=mn*mn,k-=mn,i++;
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}