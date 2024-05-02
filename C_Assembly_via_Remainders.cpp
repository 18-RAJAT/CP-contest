#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n,100005);
    for(int i=1;i<n;++i)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<" \n"[i+1==n];
    }
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