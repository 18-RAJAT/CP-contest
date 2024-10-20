#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    int mn=INT_MAX,mx=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        mn=min<int>(mn,a[i]);
        mx=max<int>(mx,a[i]);
    }
    cout<<(mx-mn)*(n-1)<<endl;
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