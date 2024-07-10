#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<=m;++i)
    {
        cin>>b[i];
    }
    int check=a[0]*b[0];
    if(n>m)
    {
        if(check<0)
        {
            cout<<"-Infinity";
        }
        else
        {
            cout<<"Infinity";
        }
    }
    else if(n<m)
    {
        cout<<"0/1";
    }
    else
    {
        int val=__gcd(a[0],b[0]);
        if(check>0)cout<<abs(a[0]/val)<<'/'<<abs(b[0]/val)<<endl;
        else cout<<'-'<<abs(a[0]/val)<<'/'<<abs(b[0]/val)<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}