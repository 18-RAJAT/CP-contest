#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)cin>>a[i];
    if(n==2)
    {
        cout<<max(a[0],a[1])<<endl;
        return;
    }
    sort(a,a+n);
    cout<<a[n/2]<<endl;
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