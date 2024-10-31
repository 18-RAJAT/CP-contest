#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int tmp=a[0],ans=0;
    for(int i=0;i<n;++i)tmp&=a[i];
    // if(n==1)
    // {
    //     cout<<a[0]<<endl;
    //     return;
    // }
    int bit_set=(1LL<<30);
    int i=1;
    while(i<=bit_set)
    {
        if(tmp&i)ans+=i;
        i*=2;
    }
    cout<<ans<<endl;
    // else
    // {
    //     int tmp=a[0];
    //     for(int i=1;i<n;++i)tmp&=a[i];
    //     int cnt=__builtin_popcountll(tmp);
    //     if(cnt==0)cout<<0<<endl;
    //     else cout<<(1LL<<cnt)-1<<endl;
    // }
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