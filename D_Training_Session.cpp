#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    map<int,int>mp1,mp2;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        mp1[a[i]]++,mp2[b[i]]++;
    }
    for(int i=n-1;~i;--i)
    {
        ans+=(n-1-i)*(n-2-i)/2;
        ans-=(mp1[a[i]]-1)*(mp2[b[i]]-1);
    }
    assert(ans>=0 && ans<=n*(n-1)*(n-2)/6);
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