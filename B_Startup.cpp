#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(k+5);
    for(int i=0;i<k;++i)
    {
        int b,c;
        cin>>b>>c;
        a[b]+=c;
    }
    sort(a.begin(),a.end(),greater<int>());
    int ans=0;
    for(int i=0;i<min(n,k+5);++i)ans+=a[i];
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