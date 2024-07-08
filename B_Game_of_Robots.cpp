#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ans=1;
    while(k>0)
    {
        k-=ans,ans++;
    }
    k+=ans-1;
    cout<<a[k-1];
}
signed main()
{
    sol();
    return 0;
}