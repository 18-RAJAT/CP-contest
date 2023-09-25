#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    vector<int>pref(n);
    pref.resize(n+1);
    for(int i=0;i<n;++i)
    {
        pref[i+1]=pref[i]^a[i];
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        int suf=pref[i];
        for(int j=i;j<n;++j)
        {
            int calc=pref[j+1]^suf;
            // cout<<"print: "<<calc;
            int func=j-i+1;
            ans=(ans+calc*(func))%998244353;
        }
    }
    cout<<ans%998244353<<"\n";
}
signed main()
{
	sol();
    return 0;
}