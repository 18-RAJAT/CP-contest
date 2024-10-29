#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(i>=1)a[i]+=a[i-1];
    }
    int ans=0,nums=0;
    for(int i=0;i<=n-2;++i)
    {
        if(2*a[n-1]==3*a[i])ans+=nums;
        if(a[n-1]==3*a[i])nums++;
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}