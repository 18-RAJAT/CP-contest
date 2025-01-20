#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int res=max(*max_element(a.begin(),a.end()),k);
    vector<int>ar(res+5,0);
    for(int i=0;i<n;++i)ar[a[i]]++;
    int ans=0;
    for(int i=1;i<=k/2;++i)
    {
        int j=k-i;
        if(j<1 || res<j)continue;
        if(i==j)ans+=ar[i]/2;
        else if(i<j)ans+=min(ar[i],ar[j]);
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