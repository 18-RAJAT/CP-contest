#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n,k;
    cin>>n>>k;
    int ans=0;
    map<int,int>mp;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        x%=k;
        int y=(k-x)%k;
        if(mp[y])
        {
            mp[y]--;
            ans++;
        }
        else
        {
            mp[x]++;
        }
    }
    cout<<ans*2<<endl;
    return 0;
}