#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[200005];
    for(int i=0;i<2*n;++i)
    {
        cin>>a[i];
    }
    sort(a,a+2*n);
    cout<<a[n]-a[n-1]<<endl;
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