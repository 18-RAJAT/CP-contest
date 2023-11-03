#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    memset(a,0,sizeof(a));
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ans=1;
    for(int i=1;i<n;++i)
    {
        if(a[i]<a[i-1])
        {
            ans++;
        }
    }
    cout<<ans<<"\n";
}
signed main()
{
    sol();
    return 0;
}