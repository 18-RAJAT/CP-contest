#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int sum=0;
    for(int i=0;i<n/2;++i)
    {
        sum+=(a[i]+a[n-i-1])*(a[i]+a[n-i-1]);
    }
    cout<<sum<<"\n";
    return 0;
}