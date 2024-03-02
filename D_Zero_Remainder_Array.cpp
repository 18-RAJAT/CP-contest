#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    map<int,int>mp;
    int ans=-1;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        int res=x%k;
        mp[k-res]++;
        if(res)
        {
            ans=max(ans,(k-res)+k*(mp[k-res]-1));
        }
    }
    cout<<ans+1<<endl;
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