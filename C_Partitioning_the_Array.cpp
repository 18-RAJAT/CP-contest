#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>ar(2e5+5);
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ans=0;
    for(auto& it:ar[n])
    {
        int G=0;
        for(int i=0;i<n-it;++i)
        {
            (G==0?G=abs(a[i]-a[i+it]):G=__gcd(G,abs(a[i]-a[i+it])));
        }
        if(G==0 || G>1)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    ar.clear();
    for(int i=1;i<=2e5;++i)
    {
        for(int j=i;j<=2e5;j+=i)
        {
            ar[j].push_back(i);
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}