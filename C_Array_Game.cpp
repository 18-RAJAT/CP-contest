#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    if(k>=3)
    {
        cout<<0<<endl;
        return;
    }
    sort(a.begin(),a.end());
    int ans=a[0];
    for(int i=1;i<n;++i) ans=min(ans,a[i]-a[i-1]);
    if(k==1)
    {
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            int tmp=a[j]-a[i];
            auto UB=upper_bound(a.begin(),a.end(),tmp);
            if(UB!=a.begin()) ans=min(ans,tmp-*prev(UB));
            UB=lower_bound(a.begin(),a.end(),tmp);
            if(UB!=a.end()) ans=min(ans,*UB-tmp);
        }
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