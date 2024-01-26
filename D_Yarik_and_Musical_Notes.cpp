#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    map<int,int>hash;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        hash[x]++;
    }
    int ans=0;
    for(auto mp:hash)
    {
        ans+=(mp.second*(mp.second-1))/2;
    }
    ans+=hash[1]*hash[2];
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