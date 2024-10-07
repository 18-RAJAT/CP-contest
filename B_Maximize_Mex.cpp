#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,int>mp;
void sol()
{
    int n,x;
    cin>>n>>x;
    mp.clear();
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    int ans=0;
    for(int i=0;i<2*n;++i)
    {
        if(mp[i] || (i-x>=0 && mp[i-x]>=2))
        {
            ans++;
            if(i-x>=0 && mp[i-x]>=2)mp[i]+=(mp[i-x]-1);
        }
        else
        {
            break;
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