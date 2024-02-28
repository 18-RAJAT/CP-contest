#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    int sum=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        sum+=abs(a[i]);
    }
    cout<<sum<<endl;
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