
#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,n;
    cin>>a>>b>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=b;
    for(auto&it:arr)
    {
        ans+=min(it,a-1);
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