#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>h(n);
    for(int i=0;i<n;++i)
    {
        cin>>h[i];
    }
    int ans=0;
    for(int i=n-1;i>=0;--i)
    {
        if(h[i]==0)continue;
        h[i]-=ans;
        h[i]=max(1LL,h[i]),ans+=h[i];
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