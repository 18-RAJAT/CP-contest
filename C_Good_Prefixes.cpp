#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto& it:a)cin>>it;
    int pref=0,maxi=0,count=0;
    for(int i=0;i<n;++i)
    {
        pref+=a[i],maxi=max(maxi,a[i]),count+=(pref-maxi)==maxi;
    }
    cout<<count<<endl;
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