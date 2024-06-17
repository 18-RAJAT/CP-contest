#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;++i) 
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a.begin(),a.end());
    int sum=0;
    vector<int>ans;
    for(int i=n-1;i>=n-k;--i)
    {
        ans.push_back(a[i].second),sum+=a[i].first;
    }
    sort(ans.begin(),ans.end());
    cout<<sum<<endl;
    if(k==1)cout<<n;
    else
    {
        cout<<1+ans[0]<<" ";
        for(int i=1;i<k-1;++i)
        {
            cout<<ans[i]-ans[i-1]<<" ";
        }
        cout<<n-ans[k-2]-1;
    }
    cout<<endl;
}
signed main()
{
    sol();
    return 0;
}