#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n),b(n);
    int G=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        G=__gcd(a[i],G);
    }
    if(G==0)
    {
        cout<<k<<endl;
        return;
    }
    if(n==1)
    {
        cout<<(a[0]>=k?k-1:k)<<endl;
        return;
    }
    for(int i=0;i<n;++i)b[i]=1LL*i*G;k--;
    for(int i=0;i<n;++i)if(b[i]<=k)k++;
    cout<<k<<endl;
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