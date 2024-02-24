#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        mp[abs(x)]+=a[i];
    }
    int ans=0;
    for(auto& it:mp)
    {
        ans+=it.second;
        if(k*it.first<ans)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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