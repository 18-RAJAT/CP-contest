#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int j=0;j<m;++j)cin>>b[j];
    int temp=a[0];
    sort(a.begin(),a.end());
    vector<int>arr;
    for(int i=0;i<m;++i)
    {
        if(b[i]>temp)
        {
            auto UB=upper_bound(a.begin(),a.end(),b[i]-1)-a.begin();
            arr.push_back(n-UB+1);
        }
        else
        {
            arr.push_back(1);
        }
    }
    sort(arr.begin(),arr.end());
    for(int k=1;k<=m;++k)
    {
        int ans=0;
        for(int j=k-1;j<m;j+=k)
        {
            ans+=arr[j];
        }
        cout<<ans<<" ";
    }
    cout<<endl;
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