#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<int>a(n),b(n+1,0);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        b[i+1]=b[i]^(a[i]+a[i]);
    }
    for(int i=0;i<q;++i)
    {
        int l,r;
        cin>>l>>r;
        cout<<(b[l-1]^b[r])<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}