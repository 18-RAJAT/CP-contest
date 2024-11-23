#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>a(n);
    map<int,int>mp;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        a[i]=(s[i]-'0')-1;
        if(i>=1) a[i]+=a[i-1];
        mp[a[i]]++;
        if(a[i]==0)ans++;
    }
    for(auto it=mp.begin();it!=mp.end();++it)
    {
        if(it->second>=2)
        {
            ans+=it->second*(it->second-1)/2;
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