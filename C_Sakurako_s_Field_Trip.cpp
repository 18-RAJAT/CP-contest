#include <bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=1;i<n/2;++i)
    {
        if(a[i]==a[i-1] || a[n-i-1]==a[n-i])swap(a[i],a[n-i-1]);
    }
    int ans=0;
    for(int i=0;i<n-1;++i)
    {
        if(a[i]==a[i+1])ans++;
    }
    cout<<ans<<endl;
}
signed main()
{
    int t;
    cin >> t;
    while(t--)
    {
        sol();
    }
    return 0;
}